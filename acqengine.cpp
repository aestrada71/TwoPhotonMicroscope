/*	Name: acqengine.cpp
	Description: Two Photon Acquisition
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:	7/17/2006		Added birectional acq capabilities.
*/ 

#include <QtGui>
#include "acqengine.h"
#include "scanengine.h"

#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NIDAQmx.h"
#include "nivision.h"
#include "TwoPhotonControl.h"

// static constants
const double AcqEngine::PI = 3.1415926535897932384626433832795028841971;

// default constructor
AcqEngine::AcqEngine(int numLinesFlyback)
{
	Num_Lines_Flyback = numLinesFlyback;
	overscan = 0;
	overscan_LS = 0;
	numValidXSamps = 0;
	numValidYSamps = 0;
	width = 0;
	repeats = 0;
	contAcq = false;
	
}

// destructor
AcqEngine::~AcqEngine()
{
	//definition
}

// from InitAcqEngineStruct(int panel, AcqStruct& acqEngine, bool bGrabMemory);
int AcqEngine::initAcq(bool bGrabMemory, bool lineScan)
{
	
	int			dummy;
//	int			temp;
	long		numChans = 0;
	
	if (lineScan)  
		bLineScan = true;	 
    else  
        bLineScan = false;


	numLinesFlybackPerFrame = Num_Lines_Flyback;
	
	if (acqData != NULL)
		this->releaseMemory();

	if (bInput1)
		numChans++;

	if (bInput2)
		numChans++;


	//Calc the num samps per line.
	totSampsPerLine_LS = width +(2*overscan_LS);
	totLinesPerFrame_LS = repeats;
	numSampsPerFrame_LS = totSampsPerLine_LS * totLinesPerFrame_LS;
	numSampsTotal_LS = numFrames * numSampsPerFrame_LS;

	totSampsPerLine = numValidXSamps +(2*overscan);  
	totLinesPerFrame = numValidYSamps + numLinesFlybackPerFrame;
	numSampsPerFrame = totSampsPerLine * totLinesPerFrame;
	numSampsTotal = numFrames * numSampsPerFrame;

	if(bLineScan)
	{
		frameRate = dToARate/numSampsPerFrame_LS;
		acqTrigRate = dToARate/numSampsTotal_LS;
	}
	else
	{ 
		frameRate = dToARate/numSampsPerFrame;
		acqTrigRate = dToARate/numSampsTotal;
	}

	numActiveChannels = numChans;

	
	if (bGrabMemory)
		dummy = this->grabMemory();
	
	acqTaskHandle = 0;
	bInitialized = true;
	return 1;

/*Error:
	if( acqData )
	{
		this->releaseMemory();
	}

//	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;	
	*/
}

int AcqEngine::update()
{
	//Calc the num samps per line.
	overscan_LS = width*percentOverscan;
	overscan = numValidXSamps*percentOverscan;
	totSampsPerLine_LS = width +(2*overscan_LS);
	totLinesPerFrame_LS = repeats;
	numSampsPerFrame_LS = totSampsPerLine_LS * totLinesPerFrame_LS;
	numSampsTotal_LS = numFrames * numSampsPerFrame_LS;

	totSampsPerLine = numValidXSamps +(2*overscan);  
	totLinesPerFrame = numValidYSamps + numLinesFlybackPerFrame;
	numSampsPerFrame = totSampsPerLine * totLinesPerFrame;
	numSampsTotal = numFrames * numSampsPerFrame;

	if(bLineScan)
	{
		frameRate = dToARate/numSampsPerFrame_LS;
		acqTrigRate = dToARate/numSampsTotal_LS;
	}
	else
	{ 
		frameRate = dToARate/numSampsPerFrame;
		acqTrigRate = dToARate/numSampsTotal;
	}

	return 1;
}

// from AcqEngineGrabMemory(AcqStruct& acqEngine);
int AcqEngine::grabMemory()
{
	//Allocate RAM for Acquisition
	long	multiplier;
	int		retVal;

	retVal = this->releaseMemory();

	if (numActiveChannels == 0)
	{
		QMessageBox::about(0,"Error","No input channels enabled");
		memIsAllocated = false;
		return 0;
	}
	
	multiplier = numActiveChannels;
	if(bLineScan)
	{
		if( (acqData = new short[(numSampsTotal_LS * multiplier)])==NULL)
		{
			QMessageBox::about(0,"Error","Not enough memory");
			memIsAllocated = false;
			return 0;
		}
		else
			memIsAllocated = true;
	}
	else
	{
		if( (acqData = new short[(numSampsTotal * multiplier)])==NULL)
		{
			QMessageBox::about(0,"Error","Not enough memory");
			memIsAllocated = false;
			return 0;
		}
		else
			memIsAllocated = true;
	}
	
	return 1;
}

// from AcqEngineReleaseMemory(AcqStruct& acqEngine);
int AcqEngine::releaseMemory()
{
	if( acqData )
	{
		delete [] acqData;
		acqData = NULL;
		memIsAllocated = false;
	}



	return 1;
}

// from AcqEngineConfigDAQmxTask(AcqStruct& acqEngine, bool bTriggered, bool bContinuous);
int AcqEngine::configDAQmxTask(bool bTriggered, bool bContinuous)
{
	int error;
	//extern Trig_Channel;
	
	//_____DAQmx Configure Code________________________________________________________________
	if (!acqTaskHandle)
		DAQmxErrChk ( DAQmxCreateTask("Acq",&(acqTaskHandle)) );
		
		//Add channel 1 if needed
		if (bInput1)
			DAQmxErrChk(DAQmxCreateAIVoltageChan(acqTaskHandle,acqChan1,"PMT1",DAQmx_Val_RSE ,acqMin,acqMax,DAQmx_Val_Volts,NULL));

		//Add channel 2 if needed
		if (bInput2)
			DAQmxErrChk(DAQmxCreateAIVoltageChan(acqTaskHandle, acqChan2, "PMT2", DAQmx_Val_RSE  ,acqMin, acqMax, DAQmx_Val_Volts,NULL));

	if (bContinuous)
	{
		if (bLineScan)
			DAQmxErrChk(DAQmxCfgSampClkTiming(acqTaskHandle,"/Dev1/ao/SampleClock",dToARate, DAQmx_Val_Falling ,DAQmx_Val_ContSamps, numSampsPerFrame_LS))
		else
			DAQmxErrChk(DAQmxCfgSampClkTiming(acqTaskHandle,"/Dev1/ao/SampleClock",dToARate, DAQmx_Val_Falling ,DAQmx_Val_ContSamps, numSampsPerFrame));	
	}
	else
	{	
		if (bLineScan)
			DAQmxErrChk(DAQmxCfgSampClkTiming(acqTaskHandle,"/Dev1/ao/SampleClock",dToARate, DAQmx_Val_Falling ,DAQmx_Val_FiniteSamps, numSampsTotal_LS))
		else
			DAQmxErrChk(DAQmxCfgSampClkTiming(acqTaskHandle,"/Dev1/ao/SampleClock",dToARate, DAQmx_Val_Falling ,DAQmx_Val_FiniteSamps, numSampsTotal));
	}
	//if (bTriggered)
		//DAQmxErrChk(DAQmxCfgDigEdgeStartTrig(acqTaskHandle, "/Dev1/PFI13", DAQmx_Val_Rising));
	
	return 1;



Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

	if( acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(acqTaskHandle);
		DAQmxClearTask(acqTaskHandle);
		acqTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;

}

// from AcqEngineReadDAQmxTask(AcqStruct& acqEngine);
int AcqEngine::readDAQmxTask()
{
	int temp;
	int error;
	int multiplier;
	
	//_____DAQmx Read Code.  Task set to pause execution until all samps are read____
/*	DAQmxErrChk (DAQmxReadAnalogF64(acqTaskHandle, -1, -1, 0, acqData,numSampsTotal, &(numSampsRead),NULL));
*/	
	if (bInput1 && bInput2) 
		multiplier = 2;
	else
		multiplier = 1;
	
	DAQmxErrChk (DAQmxReadBinaryI16(acqTaskHandle, -1, -1, DAQmx_Val_GroupByChannel ,acqData,(numSampsTotal * multiplier), &(numSampsRead),NULL));

	temp = ReverseEvenRowData();
	return 1;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

	if( acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(acqTaskHandle);
		DAQmxClearTask(acqTaskHandle);
		acqTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
}

// from AcqEngioneStartDAQmxTask(AcqStruct& acqEngine);
int AcqEngine::startDAQmxTask()
{
	int error;
	
	//_____DAQmx start task Code___________________________________________________________________
	if( acqTaskHandle!=0 )
	{
		DAQmxErrChk (DAQmxStartTask(acqTaskHandle));
		return 1;
	}
	
	return 0;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

	if( acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(acqTaskHandle);
		DAQmxClearTask(acqTaskHandle);
		acqTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
}

// from AcqEngioneStopDAQmxTask(AcqStruct& acqEngine);
int AcqEngine::stopDAQmxTask()
{
	int error;
	
	//_____DAQmx stop task Code___________________________________________________________________
	if( acqTaskHandle!=0 )
	{
		DAQmxErrChk (DAQmxStopTask(acqTaskHandle));
		return 1;
	}

//	SetCtrlVal(acqEngine.PanelHandle,PANEL_cbxSave, 0);
//	SetCtrlVal(acqEngine.PanelHandle,PANEL_cbx3DAcq, 0);
	
	return 0;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

	if( acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(acqTaskHandle);
		DAQmxClearTask(acqTaskHandle);
		acqTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
}

// from CalcNumSampsPerFrameAcqStruct(AcqStruct& acqEngine);
unsigned long AcqEngine::calcNumSampsPerFrame()
{
	unsigned long retVal;
	
	retVal = 0;

	
	retVal = (totSampsPerLine) * (numValidYSamps + numLinesFlybackPerFrame);
	return retVal;
}

int AcqEngine::ReverseEvenRowData()
{
	
	unsigned long int firstPxlOfRow;	
	unsigned long int x;
	unsigned long int y;
	unsigned long int numPairsToSwap;

	short temp;

	if (!bLineScan)
	{
		numPairsToSwap = totSampsPerLine / 2;  //(integer division)This should round down if totSampsPerLine is odd

		for (y = 1; y < (totLinesPerFrame *  numFrames * numActiveChannels - numLinesFlybackPerFrame); y = y + 2)
		{
			firstPxlOfRow = (y * totSampsPerLine)+xOffset;

			for (x = 0; x < (numPairsToSwap); x++)
			{
				temp = acqData[firstPxlOfRow + (totSampsPerLine -1) - x];		//Store from end of row
				acqData[firstPxlOfRow + (totSampsPerLine -1) - x] = acqData[firstPxlOfRow + x];  //swap beginning of row to end of row
				acqData[firstPxlOfRow + x] = temp;								//Put temp val from end into beginning.
			}

		}
	}
	else
	{
		numPairsToSwap = totSampsPerLine_LS / 2;  //(integer division)This should round down if totSampsPerLine is odd

		for (y = 1; y < (totLinesPerFrame_LS *  numFrames * numActiveChannels-2); y = y + 2)
		{
			firstPxlOfRow = (y * totSampsPerLine_LS)+xOffset;

			for (x = 0; x < (numPairsToSwap); x++)
			{
				temp = acqData[firstPxlOfRow + (totSampsPerLine_LS -1) - x];		//Store from end of row
				acqData[firstPxlOfRow + (totSampsPerLine_LS -1) - x] = acqData[firstPxlOfRow + x];  //swap beginning of row to end of row
				acqData[firstPxlOfRow + x] = temp;								//Put temp val from end into beginning.
			}

		}
	}



	return 1;
}

// from UpdateLineScanSpeed(int panel);
/*
double AcqEngine::updateLineScanSpeed(TwoPhotonGui* TwoPGui)
{
	
	int			numSamps;
	double		sampleRate;
	double		lineSpeed;

	//get values from GUI
	numSamps	= width;
	sampleRate	= TwoPGui->doubleSpinBox_SampleRate->value();

	lineSpeed = 1/((1/sampleRate)*numSamps);
	//Update field for Line Speed
	TwoPGui->spinBox_LineRate_2->setValue(lineSpeed);
	return lineSpeed;
}
*/
