/*	Name: scanengine.cpp
	Description: Scanning Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:	7/17/09			Added triangle x-scanning waveform and acq on flyback (birectional acquisition)
*/ 
#include "QtGui"
#include "scanengine.h"
#include "string.h"
#include "TwoPhotonControl.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>		//Used for time and date stamp on file.
#include <string.h>		//Used for file name for saving data.
#include "NIDAQmx.h"

// static constants
const double ScanEngine::PI = 3.1415926535897932384626433832795028841971;
const double ScanEngine::MAXVOLT_X = 5.0;
const double ScanEngine::MINVOLT_X = -5.0;
const double ScanEngine::MAXVOLT_Y = 5.0;
const double ScanEngine::MINVOLT_Y = -5.0;

// constructor
ScanEngine::ScanEngine(int numLinesFlyback, double percentOverscan, double overScanV)
{
	Num_Lines_Flyback = numLinesFlyback;
	overscanCalculated = false;
	SCANENGINE_PERCENT_OVERSCAN = percentOverscan;
	SCANENGINE_PERCENT_OVERSCAN_V = overScanV;

}
// deconstructor
ScanEngine::~ScanEngine()
{
	// definition
}

// from InitScanEngineStruct(int panel, ScanStruct& scanEngine, bool bGrabMemory);
int ScanEngine::initScan(bool bGrabMemory, bool lineScan)
{
//	char        temp[256];

	memcpy(trigChan,"/Dev1/PFI7",256*sizeof(char));

	if(lineScan)
		bLineScan = true;
	else
		bLineScan = false;

	numLinesFlybackPerFrame = Num_Lines_Flyback;;
	scanTaskHandle = 0;
	
	if (dacData)
		this->releaseMemory();

	

	//Update number of samp fields for line scan mode( 1 samp per pixel).
	totSampsPerLine_LS = width  + (2*overscan_LS);
	totLinesPerFrame_LS = repeats;
	numSampsPerFrame_LS = totSampsPerLine_LS * totLinesPerFrame_LS;
	numSampsTotal_LS	= numFrames * numSampsPerFrame_LS;

	//Update number of samp fields for normal scan mode (1 samp per pixel).
	totSampsPerLine		= numValidXSamps +(2*overscan); 
	totLinesPerFrame	= numValidYSamps + numLinesFlybackPerFrame; //Must be even number for birectional acq.
	numSampsPerFrame	= totSampsPerLine * totLinesPerFrame;
	numSampsTotal		= numFrames * numSampsPerFrame;

	//Is this value ever used for anything ???????????????????????????????
	//bufferSize			= numSampsTotal * sizeof(double); 

	//initialize beam parking params to zero
	xHoldVolts = 0.0;
	yHoldVolts = 0.0;
	
	if (bGrabMemory)
		this->grabMemory();

	bParkBeam = false;
	bTaskRunning = false;
	bInitialized = true;

	return 1;

 /*Error:

	if( dacData )
	{
		delete [] dacData;
		memIsAllocated = false;
	}

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
*/
}

// from UpdateScanEngineStruct(int panel);
int ScanEngine::update()
{
	// definition
	//Update number of samp fields for line scan mode( 1 samp per pixel).
	totSampsPerLine_LS = width  + (2*overscan_LS);
	totLinesPerFrame_LS = repeats;
	numSampsPerFrame_LS = totSampsPerLine_LS * totLinesPerFrame_LS;
	numSampsTotal_LS	= numFrames * numSampsPerFrame_LS;

	//Update number of samp fields for normal scan mode (1 samp per pixel).
	totSampsPerLine		= numValidXSamps +(2*overscan); 
	totLinesPerFrame	= numValidYSamps + numLinesFlybackPerFrame; //Must be even number for birectional acq.
	numSampsPerFrame	= totSampsPerLine * totLinesPerFrame;
	numSampsTotal		= numFrames * numSampsPerFrame;

	return 1; 
}
//Function: grabRotateMemory
//Description: allocates memory for x rotation signal
//Output: 1 upon success,0 upon failure
int ScanEngine::grabRotateMemory()
{
	//clear memory
	int retVal;
	retVal = ScanEngine::releaseMemory();

	//allocate memory (500 points for x/y)
	if( (dacData = new double[1000]) == NULL )
	{
		QMessageBox::about(0,"error","Not enough memory.");
		memIsAllocated = false;
		return 0;
	}
	else
		memIsAllocated = true;

	return 1;


}
// from ScanEngineGrabMemory(ScanStruct& scanEngine);
int ScanEngine::grabMemory()
{
	int retVal;

	retVal = ScanEngine::releaseMemory();
	
	//Grab memory for x an y waveforms
	if (bLineScan)
	{
		if( (dacData = new double[2 * numSampsTotal_LS]) == NULL )
		{
			QMessageBox::about(0,"error","Not enough memory.");
			memIsAllocated = false;
			return 0;
		}
		else
			memIsAllocated = true;

	}
	else
	{
		if( (dacData = new double[2 * numSampsTotal]) == NULL )
		{
			QMessageBox::about(0,"error","Not enough memory.");
			memIsAllocated = false;
			return 0;
		}
		else
			memIsAllocated = true;
	
	}
	return 1;
}

// from ScanEngineReleaseMemory(ScanStruct& scanEngine);
int ScanEngine::releaseMemory()
{
	if( dacData )
	{
		delete [] dacData;
		dacData = NULL;
		memIsAllocated = false;
	}
	return 1;
}

// from ScanEngineConfigDAQmxTask(ScanStruct& scanEngine, bool bTriggered, bool bContinuous);
int ScanEngine::configDAQmxTask(bool bTriggered, bool bContinuous)
{
	
	int error;
	//extern Trig_Channel;
	
	//_____DAQmx Configure Code________________________________________________________________
	if (!scanTaskHandle)
		DAQmxErrChk (DAQmxCreateTask("Scan",&(scanTaskHandle)));

	DAQmxErrChk (DAQmxCreateAOVoltageChan(scanTaskHandle,xChan,"",xMinVOScan,xMaxVOScan,DAQmx_Val_Volts, NULL));
	DAQmxErrChk (DAQmxCreateAOVoltageChan(scanTaskHandle,yChan,"",yMinVOScan,yMaxVOScan, DAQmx_Val_Volts, NULL));

	if(!bParkBeam)
	{
		if (bContinuous)
		{
			if (bLineScan)
                                DAQmxErrChk (DAQmxCfgSampClkTiming(scanTaskHandle,"/Dev1/PFI13",Samp_Rate, DAQmx_Val_Rising,DAQmx_Val_ContSamps,numSampsPerFrame_LS))
			else
                                DAQmxErrChk (DAQmxCfgSampClkTiming(scanTaskHandle,"/Dev1/PFI13",Samp_Rate, DAQmx_Val_Rising,DAQmx_Val_ContSamps,numSampsPerFrame));
		}
		else
		{	
			if (bLineScan)
                                DAQmxErrChk (DAQmxCfgSampClkTiming(scanTaskHandle,"/Dev1/PFI13",Samp_Rate, DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,numSampsTotal_LS))
			else
                                DAQmxErrChk (DAQmxCfgSampClkTiming(scanTaskHandle,"/Dev1/PFI13",Samp_Rate, DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,numSampsTotal));
		}
		if (bTrigger)
		{
			//DAQmxErrChk (DAQmxCfgAnlgEdgeStartTrig (scanTaskHandle, trigChan, DAQmx_Val_RisingSlope , 2.0));
			DAQmxErrChk (DAQmxCfgDigEdgeStartTrig(scanTaskHandle, trigChan, DAQmx_Val_Rising));
		}
	}
	return 1;



Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,4096);

	if( scanTaskHandle!=0 ) 
	{
		DAQmxStopTask(scanTaskHandle);
		DAQmxClearTask(scanTaskHandle);
		scanTaskHandle = 0;
//		SetCtrlVal(scanEngine.panel,PANEL_ledRunning,0); 
	}
	if (memIsAllocated)
		this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;

}

// from ScanEngineWriteDAQmxTask(ScanStruct& scanEngine);
int ScanEngine::writeDAQmxTask()
{
	
	int error;
	
	//_____DAQmx Write Code____________________________________________________________________
	if(!bParkBeam)
	{
		if(bLineScan)
			DAQmxErrChk (DAQmxWriteAnalogF64(scanTaskHandle, numSampsTotal_LS, 0,0 ,DAQmx_Val_GroupByScanNumber , 
				dacData, &(sampsWritten), NULL))
		else
			DAQmxErrChk (DAQmxWriteAnalogF64(scanTaskHandle, numSampsTotal, 0,0 ,DAQmx_Val_GroupByScanNumber , 
				dacData, &(sampsWritten), NULL));
	}
	else
	{
		//Parked beam case. Only write 2 samps. No timing
		double	 writeSamples[2] = {xHoldVolts, yHoldVolts};
		DAQmxErrChk(DAQmxWriteAnalogF64(scanTaskHandle,1,1,10.0,DAQmx_Val_GroupByChannel,writeSamples,NULL,NULL));
	}

	return 1;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,4096);

	if( scanTaskHandle!=0 ) 
	{
		DAQmxStopTask(scanTaskHandle);
		DAQmxClearTask(scanTaskHandle);
		scanTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	//if( DAQmxFailed(error) )
		//QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
}

// from ScanEngineStartDAQmxTask(ScanStruct& scanEngine);
int ScanEngine::startDAQmxTask()
{
	int error;
	
	//_____DAQmx start task Code___________________________________________________________________
	if( scanTaskHandle!=0 )
	{
		DAQmxErrChk (DAQmxStartTask(scanTaskHandle));
		return 1;
	}
	
	return 0;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,4096);

	if( scanTaskHandle!=0 ) 
	{
		DAQmxStopTask(scanTaskHandle);
		DAQmxClearTask(scanTaskHandle);
		scanTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;

}

// from ScanEngineStopDAQmxTask(ScanStruct& scanEngine);
int ScanEngine::stopDAQmxTask()
{
	int error;
	
	//_____DAQmx start task Code___________________________________________________________________
	if( scanTaskHandle!=0 )
	{
		DAQmxErrChk (DAQmxStopTask(scanTaskHandle));
		return 1;
	}

	//Turn off beam parking in case it is on.
	bParkBeam = false;
	
	return 0;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,4096);

	if( scanTaskHandle!=0 ) 
	{
		DAQmxStopTask(scanTaskHandle);
		DAQmxClearTask(scanTaskHandle);
		scanTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);

	return 0;
}

// from ScanEngineClearDAQmxTask(ScanStruct& scanEngine);
int ScanEngine::clearDAQmxTask()
{

	int error;
	
	//_____DAQmx start task Code___________________________________________________________________
	if( scanTaskHandle!=0 )
	{
		DAQmxErrChk (DAQmxClearTask(scanTaskHandle));
		scanTaskHandle = 0;
		return 1;
	}

	//Turn off beam parking in case it is on.
	bParkBeam = false;
	
	return 0;


Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,4096);

	if( scanTaskHandle!=0 ) 
	{
		DAQmxStopTask(scanTaskHandle);
		DAQmxClearTask(scanTaskHandle);
		scanTaskHandle = 0;
//		SetCtrlVal(panel,PANEL_ledRunning,0); 
	}
	this->releaseMemory();

	if( DAQmxFailed(error) )
		QMessageBox::about(0,"DAQmx Error",errBuff);
	return 0;
}
//parkBeam
//Parks beam over one spot
int ScanEngine::parkBeam()
{
	int retVal;
  
     retVal = stopDAQmxTask();
     retVal = clearDAQmxTask();
     bParkBeam = true;
     retVal = configDAQmxTask(false, false);
     retVal = writeDAQmxTask();
     retVal = startDAQmxTask();

     return 1;
  
}

// from CalcNumSampsPerFrameScanStruct(ScanStruct& scanEngine);
unsigned long ScanEngine::calcNumSampsPerFrame()
{
	unsigned long retVal;
	
	retVal = 0;

	
	retVal = (totSampsPerLine) * (numValidYSamps + numLinesFlybackPerFrame);
	return retVal;
}

// from GenerateWaveForms(ScanStruct& scanEngine);
int ScanEngine::generateWaveForms()
{
	
	unsigned long	ii, xIndex, yIndex, dacDataIndex;
	double*			xWaveForm = 0;			//Will hold one cycle of x waveform (2 lines since bidirectional acq).  
	double*			yWaveForm = 0;			//Will hold on cycle of y waveform.
	int				retVal;
	int				maxVoltExceededFlag = 0; //check to make sure maximum voltage isn't exceeded with overscan


	if (!memIsAllocated)
		retVal = this->grabMemory();

	//This is small amount of memory.  I assume we can always get this much.
	xWaveForm = new double[2 * totSampsPerLine];  // 
	yWaveForm = new double[totLinesPerFrame];
		
	//If overscan has not yet been calculated (check to prevent errors during continuous acq)
	if(!overscanCalculated)
	{
		double xDeltaV = xMaxVolts - xMinVolts;
		xMaxVOScan = xMaxVolts + (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new max voltage with overscan
		xMinVOScan = xMinVolts - (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new min voltage with overscan
		yMaxVOScan = yMaxVolts;
		yMinVOScan = yMinVolts;
		overscanCalculated = true;
	}

	
	//set flag to see if 
	if((xMaxVOScan>MAXVOLT_X)||(xMinVOScan<MINVOLT_X))
		maxVoltExceededFlag = 1;



	//_____Create actual x waveform for one line.______________________________________________
	xRange = xMaxVolts - xMinVolts;
	this->gen1TriangleWave(overscan, numValidXSamps,xWaveForm); 
	//this->GenDiagnosticSquareWave(totSampsPerLine, xWaveForm);	//-temp change to test something
	this->scaleAndShift(xWaveForm,2 * totSampsPerLine,xMaxVolts,xMinVolts, xWaveForm);

	//_____Create actual y waveform for one frame._____________________________________________
	yRange = yMaxVolts - yMinVolts;
	this->gen1SawtoothWave(totLinesPerFrame, numLinesFlybackPerFrame, yWaveForm);
	this->scaleAndShift(yWaveForm, totLinesPerFrame, yMaxVolts,yMinVolts, yWaveForm);
	
	
	//_____Stuff the x and y data into a single frame. (interleaved)_______________________
	dacDataIndex = 0;
	for	(yIndex = 0; yIndex < numValidYSamps; yIndex++)
	{
		//Forward scan direction
		for	(xIndex = 0; xIndex < totSampsPerLine; xIndex++)
		{
			dacData[dacDataIndex] = xWaveForm[xIndex];
			dacDataIndex++;
			dacData[dacDataIndex] = yWaveForm[yIndex];
			dacDataIndex++;
		}

		//Reverse scan direction
		yIndex++;
		for	(xIndex = totSampsPerLine; xIndex < 2 * totSampsPerLine; xIndex++)
		{
			dacData[dacDataIndex] = xWaveForm[xIndex];
			dacDataIndex++;
			dacData[dacDataIndex] = yWaveForm[yIndex];
			dacDataIndex++;
		}
	}
	//Added this to have a more smooth y flyback.  -ADE 7/21/09
	unsigned long numSampsInYFlyback = totSampsPerLine * numLinesFlybackPerFrame;  //Num lines flyback per frame always even
	unsigned long tempCounter = 0;
	for	(ii = 0; ii < numLinesFlybackPerFrame/2; ii++) //Number of lines
	{
		//Forward scan direction
		for	(xIndex = 0; xIndex < totSampsPerLine; xIndex++)
		{
			dacData[dacDataIndex] = xWaveForm[xIndex];
			dacDataIndex++;
			dacData[dacDataIndex] = yMaxVolts - tempCounter * yRange / numSampsInYFlyback;
			dacDataIndex++;
			tempCounter++;
		}
		//Reverse scan direction
		for	(xIndex = totSampsPerLine; xIndex < 2 * totSampsPerLine; xIndex++)
		{
			dacData[dacDataIndex] = xWaveForm[xIndex];
			dacDataIndex++;
			dacData[dacDataIndex] = yMaxVolts - tempCounter * yRange / numSampsInYFlyback;
			dacDataIndex++;
			tempCounter++;
		}
	}

	//_____Repeat the waveforms for arbitrary number of frames_____
	for (unsigned int iFrameNum = 1; iFrameNum < numFrames; iFrameNum++)
	{
		for (ii = 0; ii < 2 * numSampsPerFrame; ii++)
		{
			dacData[(2 * numSampsPerFrame * iFrameNum) + ii] = dacData[ii];
		}
	}


	if( xWaveForm )
		delete [] xWaveForm;

	if( yWaveForm )
		delete [] yWaveForm;

	//check to see that maximum volts were not exceded with overscan
	if(maxVoltExceededFlag)
		return 0;
	else
		return 1;
}
//Function: generateRotationWaveforms
//Description: generates waveform for rotating the x-axis mirror to prevent wear on the galvo bearings
//Output: 1 for success, 0 for failure
int ScanEngine::generateRotationWaveforms()
{
	unsigned long	ii, dacDataIndex;
	double			a;						//coefficient for waveform equations
	double*			xWaveForm = 0;			//Will hold one cycle of x waveform .  
	double*			yWaveForm = 0;			//Will hold on cycle of y waveform.
	int				retVal;
	int				maxVoltExceededFlag = 0; //check to make sure maximum voltage isn't exceeded with overscan


	if (!memIsAllocated)
		retVal = this->grabRotateMemory();

	//This is small amount of memory.  I assume we can always get this much.
	xWaveForm = new double[500];  // 
	yWaveForm = new double[500];
		
	//If overscan has not yet been calculated (check to prevent errors during continuous acq)
	if(!overscanCalculated)
	{
		//double xDeltaV = xMaxVolts - xMinVolts;
		//xMaxVOScan = xMaxVolts + (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new max voltage with overscan
		//xMinVOScan = xMinVolts - (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new min voltage with overscan
		//yMaxVOScan = yMaxVolts;
		//yMinVOScan = yMinVolts;
		overscanCalculated = true;
	}

	
	//set flag to see if 
	//if((xMaxVOScan>MAXVOLT_X)||(xMinVOScan<MINVOLT_X))
	//	maxVoltExceededFlag = 1;



	//Create clearing waveform 
	//create first half of waveform

	a = pow((double)20,(int)-5);
	for(ii=0;ii<240;ii++)
		xWaveForm[ii] = xMaxVolts*(a*ii*ii - 0.0012*ii + 0.0009);												//from trendline estimate of desired waveform

	a = pow((double)-30,(int)-6);
	for (ii=240;ii<250;ii++)
		xWaveForm[ii] = xMaxVolts*(a*ii*ii*ii*ii + 0.0027*ii*ii*ii - 1.0001*ii*ii + 166.73*ii - 10424);		//from trendline estimate of desired waveform

	//copy second half
	for(ii = 0;ii<250;ii++)
		xWaveForm[ii+250] = xWaveForm[249-ii];

	//create flat signal for y-axis (need to do this to use existing DAQ function calls
	for(ii=0;ii<500;ii++)
		yWaveForm[ii] = 0;


	//_____Stuff the x and y data into a single frame. (interleaved)_______________________
	dacDataIndex = 0;

	for	(ii = 0; ii < 500; ii++)
	{
			dacData[dacDataIndex] = xWaveForm[ii];
			dacDataIndex++;

			dacData[dacDataIndex] = yWaveForm[ii];
			dacDataIndex++;
	}

	if( xWaveForm )
		delete [] xWaveForm;

	if( yWaveForm )
		delete [] yWaveForm;

	//check to see that maximum volts were not exceded with overscan
	if(maxVoltExceededFlag)
		return 0;
	else
		return 1;
}
// from GenerateLineScanWave(ScanStruct& scanEngine,int panel,int x1, int y1, int x2, int y2);
int ScanEngine::generateLineScanWaveForms()
{
	unsigned long	ii, Index, dacDataIndex;
	double*			xWaveForm = 0;			//Will hold one cycle of x waveform. 
	double*			yWaveForm = 0;			//Will hold one cycle of y waveform.
	//double			acqSlope,xMaxVOs,xMinVOs;
	int				maxVoltExceededFlag = 0; //check to make sure maximum voltage isn't exceeded with overscan

	//recalculate scanning parameters based on width and repeat fields (instead of x and y pixels)
	
	//This is small amount of memory.  I assume we can always get this much.
	xWaveForm = new double[2 * totSampsPerLine_LS];		//2x because code is for bidirectional now.
	yWaveForm = new double[2 * totSampsPerLine_LS];		//2x because code is for bidirectional now.

	//Calc max voltages and verify it does not exceed damage limit.
	double xDeltaV = abs(roiPt1XVolts - roiPt2XVolts);
	double xMinV,xMaxV;
	if (roiPt1XVolts < roiPt2XVolts) 
	{
		xMinV = roiPt1XVolts;
		xMaxV = roiPt2XVolts; 
	}
	else 
	{
		xMinV = roiPt2XVolts;
		xMaxV = roiPt1XVolts;
	}
	xMaxVOScan = xMaxV + (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new max voltage with overscan
	xMinVOScan = xMinV - (xDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new min voltage with overscan

	double yDeltaV = abs(roiPt1YVolts - roiPt2YVolts);
	double yMinV,yMaxV;
	if (roiPt1YVolts < roiPt2YVolts) 
	{
		yMinV = roiPt1YVolts;
		yMaxV = roiPt2YVolts; 
	}
	else 
	{
		yMinV = roiPt2YVolts;
		yMaxV = roiPt1YVolts;
	}
	yMaxVOScan = yMaxV + (yDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new max voltage with overscan
	yMinVOScan = yMinV - (yDeltaV * SCANENGINE_PERCENT_OVERSCAN_V);	//new max voltage with overscan

	//set flag to see if damage max or min is exceeded
	if((xMaxVOScan>MAXVOLT_X)||(xMinVOScan<MINVOLT_X)||(yMaxVOScan>MAXVOLT_Y)||(yMinVOScan<MINVOLT_Y))
		maxVoltExceededFlag = 1;

	//_____Create actual x waveform for one line.______________________________________________
	this->gen1TriangleWave(overscan_LS, width,xWaveForm); 
	this->scaleAndShift(xWaveForm,2 * totSampsPerLine_LS,roiPt2XVolts,roiPt1XVolts, xWaveForm);

	//_____Create actual y waveform for one frame._____________________________________________
	this->gen1TriangleWave(overscan_LS, width,yWaveForm);
	this->scaleAndShift(yWaveForm,2 * totSampsPerLine_LS,roiPt2YVolts,roiPt1YVolts, yWaveForm);


	//_____Stuff the x and y data into a single frame. (interleaved)_______________________
	dacDataIndex = 0;
	//fill in first 2 rows (2 lines)
	for	(Index = 0; Index < 2* totSampsPerLine_LS; Index++)
	{
		dacData[dacDataIndex] = xWaveForm[Index];
		dacDataIndex++;
		dacData[dacDataIndex] = yWaveForm[Index];
		dacDataIndex++;
	}
	//_____Repeat the waveform for the width (amount of repeats)
	for (Index=1; Index < totLinesPerFrame_LS/2; Index++)  //Loop throgh the number of line pairs
	{
		for (ii = 0; ii < 2 * 2 * totSampsPerLine_LS; ii++)  //2 waveforms, and 2 lines worth of samples
		{
			dacData[(2* 2 * totSampsPerLine_LS * Index) + ii] = dacData[ii];

		}
	}

	//_____Repeat the waveforms for arbitrary number of frames_____
	for (unsigned int iFrameNum = 1; iFrameNum < numFrames; iFrameNum++)
	{
		for (ii = 0; ii < 2 * numSampsPerFrame_LS; ii++)
		{
			dacData[(2 * numSampsPerFrame_LS * iFrameNum) + ii] = dacData[ii];
		}
	}

	if( xWaveForm )
		delete [] xWaveForm;

	if( yWaveForm )	
		delete [] yWaveForm;

	return 1;
}
int ScanEngine::generateLineScanWave(int x1, int y1, int x2, int y2)
{
	unsigned long	ii, Index, dacDataIndex;
	double*			xWaveForm = 0;			//Will hold one cycle of x waveform. 
	double*			yWaveForm = 0;			//Will hold one cycle of y waveform.
	int				numAcqPix;
	double			acqSlope,xMaxVOs,xMinVOs;

	//recalculate scanning parameters based on width and repeat fields (instead of x and y pixels)
	
	//This is small amount of memory.  I assume we can always get this much.

	xWaveForm = new double[totSampsPerLine];
	yWaveForm = new double[totSampsPerLine];

	//if overscan is present, changed max/min voltages -If overscan px = 0; no change occurs
	numAcqPix = totSampsPerLine-(2*overscan);
	acqSlope = (xMaxVolts-xMinVolts)/numAcqPix;	//slope for non-flyback region (V/px)
	
	xMaxVOs = xMaxVolts + overscan*acqSlope;	//new max voltage with overscan
	xMinVOs = xMinVolts -overscan*acqSlope;		//new min voltage with overscan

		//need to change xMaxVolts and xMinVolts to change maximum voltage range on task
	xMaxVolts = xMaxVOs;
	xMinVolts = xMinVOs;

	//_____Create actual x waveform for one line.______________________________________________
	xRange = xMaxVolts - xMinVolts;
	this->gen1LineScan(totSampsPerLine, 200, numValidXSamps, xMaxVolts,xMinVolts,x1,x2,xWaveForm);
	//this->gen1TriangleWave(totSampsPerLine, xWaveForm); 
	//_____Create actual y waveform for one frame._____________________________________________
	yRange = yMaxVolts - yMinVolts;
	//retVal = this->gen1LineScan(totSampsPerLine,, numValidYSamps, yMaxVolts,yMinVolts,y1,y2,yWaveForm);
	
	
	//_____Stuff the x and y data into a single frame. (interleaved)_______________________
	dacDataIndex = 0;
		for	(Index = 0; Index < totSampsPerLine; Index++)
		{
			dacData[dacDataIndex] = xWaveForm[Index];
			dacDataIndex++;
			dacData[dacDataIndex] = yWaveForm[Index];
			dacDataIndex++;
		}
	//_____Repeat the waveforms for the width (amount of repeats)
	for (Index=1; Index < totLinesPerFrame; Index++)
	{
		for (ii = 0; ii < 2 * totSampsPerLine; ii++)
		{
			dacData[(2 * totSampsPerLine * Index) + ii] = dacData[ii];
		}
	}

	//_____Repeat the waveforms for arbitrary number of frames_____
	for (unsigned int iFrameNum = 1; iFrameNum < numFrames; iFrameNum++)
	{
		for (ii = 0; ii < 2 * numSampsPerFrame; ii++)
		{
			dacData[(2 * numSampsPerFrame * iFrameNum) + ii] = dacData[ii];
		}
	}

	if( xWaveForm )
		delete [] xWaveForm;

	if( yWaveForm )	
		delete [] yWaveForm;

	return 1;
}
// from GenSineWave     (int numElements,double amplitude,double frequency,double *phase,double sineWave[]);
int ScanEngine::genSineWave     (int numElements,double amplitude,double frequency,double *phase,double sineWave[])
{
	int i;

	for(i=0;i<numElements;i++)
		sineWave[i] = amplitude*sin(PI/180.0*(*phase + 360.0*frequency*i));
	*phase = fmod((*phase + frequency*360.0*numElements), 360.0);
	return 0;
}

// from Gen1SawtoothWave (unsigned long numElements,unsigned long tailLength,double sawtoothWave[]);
//		Creates a single cycle of a sawtooth wave from 0 to 1 v.
int ScanEngine::gen1SawtoothWave (unsigned long numElements,unsigned long tailLength,double sawtoothWave[])
{
	unsigned long	i;
	unsigned long 	posLength;

	double posStepSize, negStepSize;
	
	posStepSize = 1/(double)(numElements-tailLength);
	negStepSize = 1/(double)tailLength;
	
	posLength = numElements - tailLength;
	for(i=0;i<posLength;i++)
	{
		
		sawtoothWave[i] = posStepSize * i;
	}

	
	for(i=0;i<tailLength;i++)
	{
		
		sawtoothWave[i+posLength] = (posLength * posStepSize) - (negStepSize * i);
	}
	return 0;
}

// from GenTriangleWave ( triangleWave []);
//		Generates a single cycle of a triangle wave from 0 to 1 volt
//		note: numLinearScanSamps is number of elements for forward scan only.
int ScanEngine::gen1TriangleWave (long numOverscanSamps, unsigned long numLinearScanSamps, double triangleWave [])
{
	long i;
	unsigned long shift;
	double stepSize = 1/(double)(numLinearScanSamps-1);  //for linear region
	double vPercent = SCANENGINE_PERCENT_OVERSCAN_V;


	//start of forward scan.  Cos portion (0 to pi/2).  Negation makes this upward curving
	for(i=0;i<numOverscanSamps ;i++)
	{
		triangleWave[i] = -vPercent * cos(i * PI / (2 * numOverscanSamps));
	}

	//linear part of forward scan
	shift = numOverscanSamps;
	for(i=0; i < numLinearScanSamps; i++)
	{
		triangleWave[i+shift] = i * stepSize;
	}

	//end of forward scan.  Pos slope portion of Cos (-pi/2 to 0)
	shift += numLinearScanSamps;
	for(i=0;i<numOverscanSamps ;i++)
	{
		triangleWave[i+shift]= 1.0 + vPercent * cos((i-numOverscanSamps) * PI / (2 * numOverscanSamps));
	}
	
	//start of reverse scan.  Neg slope portion of Cos (0 to pi/2)
	shift += numOverscanSamps;
	for(i=0;i<numOverscanSamps ;i++)
	{
		triangleWave[i+shift] = 1.0 + vPercent * cos(i * PI/(2*numOverscanSamps));
	}

	//linear part of reverse scan
	shift += numOverscanSamps;
	for(i=0;i<numLinearScanSamps ;i++)
	{
		triangleWave[i+shift] =1.0 - (i * stepSize);
	}

	//end of reverse scan. Pos slope prortion of Cos (-pi/2 to 0) Negation makes upward curve.
	shift += numLinearScanSamps;
	for(i=0;i<numOverscanSamps ;i++)
	{
		triangleWave[i+shift] = -vPercent * cos((i-numOverscanSamps) * PI / (2*numOverscanSamps));
	}
	return 0;
}

//		Generates a square wave train which cycles every other pixel from 0 to 1 volt.  This is
//		 to test if i am reversing the even rows correctly.
//		note: numElements is number of elements for forward scan only.
int ScanEngine::GenDiagnosticSquareWave (unsigned long numElements, double squareWave [])
{
	unsigned long i;
//	double stepSize = 1/(double)(numElements);

	for(i=0;i<numElements*2;i++)
	{
		squareWave[i] = (double)(i % 4)/3.0;

	}
	return 0;
}

// from GenSquareWave   (int numElements,double amplitude,double frequency,double *phase,double dutyCycle,double squareWave[]);
int ScanEngine::genSquareWave   (int numElements,double amplitude,double frequency,double *phase,double dutyCycle,double squareWave[])
{
	int i;

	for(i=0;i<numElements;i++)
	{
		double phase_i = fmod((*phase + 360.0*frequency*i), 360.0);
		squareWave[i] = (phase_i/360.0 <= dutyCycle/100.0) ? amplitude : -amplitude;
	}
	*phase = fmod((*phase + frequency*360.0*numElements), 360.0);
	return 0;
}

// from ScaleAndShift   (const double inputArray[],int numElements,double upper,double lower,double outputArray[]);
int ScanEngine::scaleAndShift   (const double inputArray[],int numElements,double upper,double lower,double outputArray[])
{
	int i;

	double scaleFactor = upper - lower;
	
	if (scaleFactor == 0.0)
	{
		for(i=0; i < numElements; i++)
			outputArray[i] = lower;
		return 0;
	}
	else
	{
		for(i=0; i < numElements; i++)
			outputArray[i] = (scaleFactor * inputArray[i]) + lower;
		return 0;
	}
}

// from ScaleAndShiftTriangle   (const double inputArray[],int numElements,double upper,double lower,double outputArray[]);
//		note: numElements is number of elements for forward scan only.
int ScanEngine::scaleAndShiftTriangle   (const double inputArray[],unsigned long numElements,double upper,double lower,double outputArray[])
{
	int i;

	double scaleFactor = upper - lower;
	
	if (scaleFactor == 0.0)
	{
		for(i=0; i < 2*numElements; i++)
			outputArray[i] = lower;
		return 0;
	}
	else
	{
		for(i=0; i < 2*numElements; i++)
			outputArray[i] = (scaleFactor * inputArray[i]) + lower;
		return 0;
	}
}
// from Gen1LineScan(int numElements, int tailLength, int pixels, double maxVolt, double minVolt, double pos1, double pos2, double lineScan[]);
int ScanEngine::gen1LineScan(int numElements, int tailLength, unsigned long numPixels, double maxVolt, double minVolt, double pos1, double pos2, double lineScan[])
{

	unsigned long i;
	unsigned long temp;
	double debug = 0.0;

	double voltRange = maxVolt-minVolt;

	//Sizes to increment for each point (in pxl values)
	double stepSize = (pos2-pos1)/(numElements-tailLength);
	//Sizes to decrease for each Tail step (in pxl values)
	double tailStepSize = (pos2-pos1)/tailLength;
	//starting coordinates for loop
	double pix = pos1;

	//Find voltage offset
	double offset = minVolt;

	//Fill in rising edge voltages in array
	temp = 0;
	for (i=0;i<numElements-tailLength;i++)
	{
		lineScan[temp] = ((voltRange/numPixels)*pix + offset);
		debug=lineScan[temp];
		temp++;

		/*if((lineScan[temp-1]<-.5)||(lineScan[temp-1]>.5))
			debug=debug;
			*/
		pix = pix+stepSize;
	}

	//Fill in tail voltages in array
	for (i=0;i<tailLength;i++)
	{
		lineScan[temp] = ((voltRange/numPixels)*pix + offset);
		debug=lineScan[temp];
		temp++;

		/*if((lineScan[temp-1]<-.5)||(lineScan[temp-1]>.5))
			debug=debug;
			*/
		pix = pix-tailStepSize;
	}

	return 0;
}


// from Gen1LineScan(int numElements, int tailLength, int pixels, double maxVolt, double minVolt, double pos1, double pos2, double lineScan[]);
//int ScanEngine::gen1LineScan_old(int numElements, int tailLength, unsigned long numPixels, double maxVolt, double minVolt, double pos1, double pos2, double lineScan[])
//{
//
//	unsigned long i;
//	unsigned long temp;
//	double debug = 0.0;
//
//	double voltRange = maxVolt-minVolt;
//
//	//Sizes to increment for each point (in pxl values)
//	double stepSize = (pos2-pos1)/(numElements-tailLength);
//	//Sizes to decrease for each Tail step (in pxl values)
//	double tailStepSize = (pos2-pos1)/tailLength;
//	//starting coordinates for loop
//	double pix = pos1;
//
//	//Find voltage offset
//	double offset = minVolt;
//
//	//Fill in rising edge voltages in array
//	temp = 0;
//	for (i=0;i<numElements-tailLength;i++)
//	{
//		lineScan[temp] = ((voltRange/numPixels)*pix + offset);
//		debug=lineScan[temp];
//		temp++;
//
//		/*if((lineScan[temp-1]<-.5)||(lineScan[temp-1]>.5))
//			debug=debug;
//			*/
//		pix = pix+stepSize;
//	}
//
//	//Fill in tail voltages in array
//	for (i=0;i<tailLength;i++)
//	{
//		lineScan[temp] = ((voltRange/numPixels)*pix + offset);
//		debug=lineScan[temp];
//		temp++;
//
//		/*if((lineScan[temp-1]<-.5)||(lineScan[temp-1]>.5))
//			debug=debug;
//			*/
//		pix = pix-tailStepSize;
//	}
//
//	return 0;
//}

//Function:	calcLineRate
//Description: calculates the rate of a linescan
int ScanEngine::calcLineRate()
{
	//calculate linerate
	lineRate	= Samp_Rate / (totSampsPerLine);									//rate (Hz) = sampRate (Hz) / (numValidXSamps  )

	return 1;
}
//Function: CalcLineLengthStruct
//Description: Calculates the length of a linescan, in microns. Must update scanEng before calling this function
int ScanEngine::calcLineLengthStruct(int x1, int y1,int x2, int y2)
{
	double conv; //microns per millivolt

	int xPxTot = width;
	int yPxTot = repeats;

	double xVolt;
	double yVolt;

	double xVoltRangeTot = xMaxVolts - xMinVolts;
	double yVoltRangeTot = yMaxVolts - yMinVolts;
	
	conv = scaling;
	conv = conv / 1000;


	//Get x and y voltage ranges of the linescan (in millivolts)
	xVolt = (xVoltRangeTot)/(xPxTot)*(x2-x1)*1000;
	if(xVolt<0)
		xVolt=xVolt*(-1);

	yVolt = (yVoltRangeTot)/(yPxTot)*(y2-y1)*1000;
	if(yVolt<0)
		yVolt=yVolt*(-1);

	//Calculate the lengths of the x an y of line, then find total length (hypotenuse)
	
	double xDist = conv * xVolt;
	double yDist = conv * yVolt;

	lineLength = sqrt(xDist*xDist + yDist*yDist);

	return 0;
}
