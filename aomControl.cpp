/*	Name: aomControl.cpp
	Description: AOM Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#include "aomControl.h"
#include "string.h"
#include "QtGui"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NIDAQmx.h"
#include "nivision.h"

//static members, constants
const double		AomControl::Aom_Max_Voltage					= 2.6;
const double		AomControl::Aom_Min_Voltage					= -2.6;
const float			AomControl::Aom_Sample_Rate					= 1e6;
const char			AomControl::AOM_RETRIG_SMPL_CLK_TERMINAL[]	= "/Dev1/Ctr0InternalOutput";	//Ctr1InternalOutput
const char			AomControl::AOM_RETRIG_TRIG_TERMINAL[]		= "/Dev3/Ctr0InternalOutput";	//May need to find a suitable counter or clock or trig source
const char			AomControl::AOM_RETRIG_SMPL_CLK_SOURCE[]	= "/Dev1/ctr0";
const char			AomControl::AOM_RETRIG_TRIG_SOURCE[]		= "/Dev3/ctr0";

//default constructor
AomControl::AomControl()
{

	//include this to prevent startup error messages that aom intensity scaling values are out of bounds
	AomMaxVoltage = Aom_Max_Voltage;
	AomMinVoltage = Aom_Min_Voltage;
	
	//Dangling pointers
	AOMSigs = NULL;

	AOMPulseRepRate = 1000;
}

//Destructor
AomControl::~AomControl()
{
	//definition
}

//AomControl::init
int AomControl::initAomCtrl()
{
	sampRate = Aom_Sample_Rate;
	AomMaxVoltage = Aom_Max_Voltage;
	AomMinVoltage = Aom_Min_Voltage;
//	xVolts = 0.0;
//	yVolts = 0.0;
	AOMSigs = 0x0;
//	AOMRefSig = 0x0;
	AOMTaskHandle = 0;
	AOMReTrigTaskHandle = 0;
	AOMSmplClkTaskHandle = 0;
	strcpy(AOMReTrigSampClkChan, AOM_RETRIG_SMPL_CLK_SOURCE);
	strcpy(AOMReTrigTrigChan, AOM_RETRIG_TRIG_SOURCE);

	bIntScaling = false;
	intensityScalingTopV = 1;
	intensityScalingBottomV = 0;

	bAOMOn = false;


	sizeArray = (int)(Aom_Sample_Rate / AOMPulseRepRate) - 1;	// xxx worth of signal w/ samprate of 1MHz
	

	//Call routine which fills in signal arrays.
	this->makeWaveform();

	return 1;
}

//AomControl::startDAQmxTask
int AomControl::startDAQmxTask()
{
	// DAQmx Start Code
	if( AOMTaskHandle !=0 ) DAQmxStartTask(AOMTaskHandle);
	if( AOMSmplClkTaskHandle !=0 )DAQmxStartTask(AOMSmplClkTaskHandle);
	if( AOMReTrigTaskHandle !=0 ) DAQmxStartTask(AOMReTrigTaskHandle);

	return 1;
}

//AomControl::stopDAQmxTask
int AomControl::stopDAQmxTask()
{

	if( AOMTaskHandle !=0 ) 
	{
		DAQmxStopTask(AOMTaskHandle);
		
	}
	if( AOMReTrigTaskHandle!=0 ) 
	{
		DAQmxStopTask(AOMReTrigTaskHandle);
	}

	if( AOMSmplClkTaskHandle!=0 ) 
	{
		DAQmxStopTask(AOMSmplClkTaskHandle); 
	}


	return 1;
}

//AomControl::clearDAQmxTask
int AomControl::clearDAQmxTask()
{
	int error;

	if( AOMTaskHandle !=0 )
	{
		DAQmxErrChk (DAQmxClearTask(AOMTaskHandle));
		AOMTaskHandle = 0;
	}

	if( AOMReTrigTaskHandle !=0 )
	{
		DAQmxErrChk (DAQmxClearTask(AOMReTrigTaskHandle));
		AOMReTrigTaskHandle = 0;
	}

	if( AOMSmplClkTaskHandle !=0 )
	{
		DAQmxErrChk (DAQmxClearTask(AOMSmplClkTaskHandle));
		AOMSmplClkTaskHandle = 0;
	}
	
	this->releaseMemory();
	return 1;

Error:
	return 0;
}

//AomControl::configNiDAQ
int AomControl::configNiDAQ()
{
	int32       error=0;
	char        errBuff[2048]={'\0'};
	double		trigHighTime = 20e-6;
	double		trigLowTime = (1/AOMPulseRepRate) - trigHighTime; 
	
	if (AOMTaskHandle != 0)
	{
		stopDAQmxTask();
		clearDAQmxTask();
	}


	AOMTaskHandle = 0;
	AOMReTrigTaskHandle = 0;
	AOMSmplClkTaskHandle = 0;

	// DAQmx Configure Code
	DAQmxErrChk(DAQmxCreateTask("AOMCntrlTask",&AOMTaskHandle));
	DAQmxErrChk(DAQmxCreateAOVoltageChan(AOMTaskHandle, AOMChan,"",AomMinVoltage,AomMaxVoltage,DAQmx_Val_Volts,NULL));
	DAQmxErrChk(DAQmxCreateAOVoltageChan(AOMTaskHandle, AOMRefOutChan,"",-5,5,DAQmx_Val_Volts,NULL));
	
	if (bAOMPulsed)
	{

		//Configure timing for AOM waveform task so that it may be retriggerable.  This means setup a counter to be retriggerable and
		// make that counter the sample clock for the analog output generation.--Note this step will take 3 counters--
		DAQmxErrChk(DAQmxCfgSampClkTiming(AOMTaskHandle,AOM_RETRIG_SMPL_CLK_TERMINAL,sampRate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,sizeArray));

		DAQmxErrChk(DAQmxCreateTask("AOMCntrlSmplClkTask",&AOMSmplClkTaskHandle));
		DAQmxErrChk(DAQmxCreateCOPulseChanFreq(AOMSmplClkTaskHandle,AOMReTrigSampClkChan,"",DAQmx_Val_Hz,DAQmx_Val_Low,0.0,sampRate,0.5));
		DAQmxErrChk(DAQmxCfgImplicitTiming (AOMSmplClkTaskHandle , DAQmx_Val_FiniteSamps , sizeArray));
		DAQmxErrChk(DAQmxCfgDigEdgeStartTrig(AOMSmplClkTaskHandle,AOM_RETRIG_TRIG_TERMINAL,DAQmx_Val_Rising));
		DAQmxErrChk(DAQmxSetTrigAttribute (AOMSmplClkTaskHandle, DAQmx_StartTrig_Retriggerable, TRUE));
		

		//Setup a counter to be the trigger source for the AOM waveform sample clock. --Note:this must come from other board since we used both counters already.--
		DAQmxErrChk(DAQmxCreateTask("AOMCntrlReTrigTask",&AOMReTrigTaskHandle));
		DAQmxErrChk(DAQmxCreateCOPulseChanTime(AOMReTrigTaskHandle, AOMReTrigTrigChan, "", DAQmx_Val_Seconds , DAQmx_Val_Low , 0.0, trigLowTime, trigHighTime));
	
		if (bAOMContinuous)
		{
			long NumTrigsFinite	= (long)(AOMPulseRepRate * AOMOnDuration);
			DAQmxErrChk(DAQmxCfgImplicitTiming(AOMReTrigTaskHandle,DAQmx_Val_ContSamps  ,NumTrigsFinite));
		}
		else
		{
			long NumTrigsFinite	= (long)(AOMPulseRepRate * AOMOnDuration);
			DAQmxErrChk(DAQmxCfgImplicitTiming (AOMReTrigTaskHandle , DAQmx_Val_FiniteSamps , NumTrigsFinite));
		}
	}
	else //Non-pulsed AOM operation mode.  This does not use up any counters.
	{
		//	DAQmxErrChk(DAQmxCfgSampClkTiming(AOMTaskHandle,NULL,sampRate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,sizeArray));
	}

	//Create new wave form.
	makeWaveform();
	//AOM_cntrl_UpdateWaveform(AOMStruct);

	return 1;

Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);
	if( AOMTaskHandle!=0 ) {
		// DAQmx Stop Code
		DAQmxStopTask(AOMTaskHandle);
		DAQmxClearTask(AOMTaskHandle);
	}
	if( AOMReTrigTaskHandle!=0 ) {
		// DAQmx Stop Code
		DAQmxStopTask(AOMReTrigTaskHandle);
		DAQmxClearTask(AOMReTrigTaskHandle);
	}
	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);
	return 0;
}

//AomControl::makeWaveform
//Build signal to be output, save in AOMSigs
int AomControl::makeWaveform()
{
	long i;

	if (AOMSigs)
		this->releaseMemory();

	sizeArray = (int)(Aom_Sample_Rate / AOMPulseRepRate) - 1;	// xxx worth of signal w/ samprate of 1MHz
	
	if (bAOMPulsed)
	{
		AOMSigs = new double[sizeArray*2];
		for (i=0; i < sizeArray; i++)
		{
			if(i <= PulseOnTime)
			{
				AOMSigs[i] = AOMVoltage;
				AOMSigs[i + sizeArray] = AOMRefOutVoltage;

			}
			else
			{		
				AOMSigs[i] = (double)0.0;
				AOMSigs[i + sizeArray] = (double)0.0;
			}
		}
	}
	else
	{
		AOMSigs = new double[2];
		AOMSigs[0] = AOMVoltage;
		AOMSigs[1] = 0.0;
	}
	

	return 1;
}

//AomControl::updateWaveform
//Load AOMSigs into Task
int AomControl::updateWaveform()
{
	int error;
	char errBuff[2048]={'\0'};

	if (bAOMPulsed)
	{
		DAQmxErrChk (DAQmxWriteAnalogF64(AOMTaskHandle,(int)sizeArray,0,10.0,DAQmx_Val_GroupByChannel,AOMSigs,NULL,NULL));	
	}
	else
	{
		DAQmxErrChk (DAQmxWriteAnalogF64(AOMTaskHandle,(int)1,1,10.0,DAQmx_Val_GroupByChannel,AOMSigs,NULL,NULL));	
	}
		return 1;

Error:
	if( DAQmxFailed(error) )
	{
		DAQmxGetExtendedErrorInfo(errBuff,2048);
		QMessageBox::about(0,"DAQmx Error",errBuff);
	}
	return 0;
}

//AomControl::releaseMemory
int AomControl::releaseMemory()
{
	if (AOMSigs)
	{
		delete [] AOMSigs;
		AOMSigs = 0x0;
	}
	return 1;
}


