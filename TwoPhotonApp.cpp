/*	Name: TwoPhoton.cpp
	Description: Two Photon Acquisition software, main class derived from all other functional classes
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 


#include "TwoPhotonGui.h"
#include "TwoPhotonApp.h"
#include <QtGui>

#include "nivision.h"
#include "scanengine.h"
#include "acqengine.h"
//#include "stepper_driver.h"
#include "2PData.h"
//#include "aombutton.h"
#include "aomControl.h"

#include "NIDAQmx.h"

//Constants
extern const char				TCSPC_Trig_Channel[] = "/Dev2/ao3";

//Global Variables
extern ScanEngine *SCAN_ENG;

 //constructor
TwoPhotonApp::TwoPhotonApp()
{
	//Initialize all derived components of class

}

 //destructor
 TwoPhotonApp::~TwoPhotonApp()
 {
	//definition
 }

//InitTwoPhotonApp
int TwoPhotonApp::InitTwoPhotonApp(int argc, char *argv[])
{
	int		error;
	int		retVal;
	int		dummy;
	float	zeroVal = 0.0;
	Point	toolPos;


	toolPos.x=850;
	toolPos.y=20;
	/*
	
	//Init dangling pointers.
	this->setAcqData(NULL);
	this->setDacData(NULL);
	image1 = NULL;
	image2 = NULL;
	imageData1 = NULL;
	imageData2 = NULL;
	this->setPtrData(NULL);
	
	//appState->zStepStruct.initialized = false;	NEED IMPLEMENTATION
	acqEng.setBInitialized(false);
	acqEng.setMemIsAllocated(0);
	scanEng.setBInitialized(false);
	scanEng.setMemIsAllocated(0);
	AomCtrl.setInitialized(false);


	//LoadVXMDriver();		NEED IMPLEMENTATION
	error = NIDAQmx_NewPhysChanAOCtrl(scanTabHandle,TABPANEL_txtbx_XChannel,0);
/*	NIDAQmx_NewPhysChanAOCtrl(scanTabHandle,TABPANEL_txtbx_YChannel,0);
	NIDAQmx_NewPhysChanAICtrl(acqTabHandle,TABPANEL_3_txtbx_InputChannel,0);  
	NIDAQmx_NewPhysChanAICtrl(acqTabHandle,TABPANEL_3_txtbx_InputChannel_2,0);
	NIDAQmx_NewPhysChanAOCtrl(aomTabHandle,TABPANEL_5_AOMChannel,0);  
	NIDAQmx_NewPhysChanAOCtrl(aomTabHandle,TABPANEL_5_AOMRefOutChannel,0);



	//Init Component structs.
	retVal = InitScanEngineStruct(appState->panelHandle, appState->scanStruct, false);
	retVal = InitAcqEngineStruct(appState->panelHandle, appState->acqStruct, false);
//	retVal = InitAOMButtonStruct(appState->panelHandle, appState->aomButtonStruct, false);
	retVal = InitZStepperStruct(appState->panelHandle, appState->zStepStruct);
	retVal = InitAOMCntrlStruct(appState->panelHandle, appState->aomCntrlStruct);
	retVal = NumFramesCallback (appState->panelHandle, PANEL_bxNumFrames, EVENT_VAL_CHANGED, &retVal, 0, 0);

	//Make sure AOM starts set at 0
	retVal = AomZeroStart(appState->aomCntrlStruct);
*/
	//Setup diplay and display tools using NIVision calls
	image1 = imaqCreateImage(IMAQ_IMAGE_U8, 0);
	displayWinNum1 = 1;
	imaqDisplayImage(image1, displayWinNum1, 1);
	imaqSetWindowTitle(1, "Channel #1");
	imaqSetWindowSize(1, 256, 256);
	posWindow1.x = 850;
	posWindow1.y = 300;
	imaqMoveWindow(1, posWindow1);

	imaqShowToolWindow (TRUE);
	imaqMoveToolWindow(toolPos);
	imaqSetCurrentTool (IMAQ_POLYLINE_TOOL);

	image2 = imaqCreateImage(IMAQ_IMAGE_U8, 0);
	displayWinNum2 = 2;
	imaqDisplayImage(image2, displayWinNum2, 1);
	imaqSetWindowTitle(2, "Channel #2");
	imaqSetWindowSize(2, 256, 256);
	posWindow2.x = 850;
	posWindow2.y = 590;
	imaqMoveWindow(2, posWindow2);
/*
	//Allocate memory for display arrays.
	appState->imageData1 = new unsigned char[appState->acqStruct.numXPxls * appState->acqStruct.numYPxls];
	appState->imageData2 = new unsigned char[appState->acqStruct.numXPxls * appState->acqStruct.numYPxls];


	//Init vars for histograms
	appState->scaleMin1 = -32768;					//Min val for signed short
	appState->scaleMax1 = 32767;					//Max val for signed short
	appState->scaleMin2 = -32768;					//Min val for signed short
	appState->scaleMax2 = 32767;					//Max val for signed short
	appState->histArray1 = new unsigned int[NUM_BINS];
	appState->histArray2 = new unsigned int[NUM_BINS];
	appState->binsArray = new short[NUM_BINS];

	for (int i = 0; i < NUM_BINS;i++)
	{
		appState->binsArray[i] = (short) (-32768 + i * (65536/NUM_BINS));
		appState->histArray1[i]=0;
		appState->histArray2[i]=0;

	}


	//Start off with all timer events supressed.
	dummy = SetCtrlAttribute (appState->panelHandle, PANEL_AOMTIMER, ATTR_ENABLED, 0);
	*/
	return 1;
}

//ArrayMin
short TwoPhotonApp::ArrayMin( short data[], long numElements)
{
	short min = data[0];
	int i;
	
	for (i = 0; i < numElements;i++)
	{
		if (data[i] < min) min = data[i];
	}
	
	return min;
}

//ArrayMax
short TwoPhotonApp::ArrayMax( short data[], long numElements)
{
	
	short max = data[0];
	long i;
	
	for (i = 0; i < numElements;i++)
	{
		if (data[i] > max) max = data[i];
	}
	
	return max;
}

//ProcessDataForDisplay
int  TwoPhotonApp::ProcessDataForDisplay()
{
	/*unsigned long int pxlCount =0 ;
	unsigned long int index;	
	unsigned long int x;
	unsigned long int y;
	unsigned long int frameNum;
	unsigned int numFrames;
	double	tempVal;
	double	tempVal2;
	short	min1 = scaleMin1;
	short	max1 = scaleMax1;
	short	min2 = scaleMin2;
	short	max2 = scaleMax2;

	//delete and reinitialize display data arrays to size of acquisition
	delete [] imageData1;
	delete [] imageData2;

	imageData1 = new unsigned char[this->getNumXPxls() * this->getNumYPxls()];
	imageData2 = new unsigned char[this->getNumXPxls() * this->getNumYPxls()];
	//~

	unsigned long shiftToNextChannel = 0;

	numFrames = this->getNumFrames();
	if (getBInput1() && getBInput2())
		shiftToNextChannel = getNumSampsTotal();

	for (y = 0; y < getNumYPxls(); y++)
	{
		for(x = getXOffset(); x < getNumXPxls() + getXOffset(); x++)
		{
	
			//calc average pxl val accross all frames
			tempVal = 0;		//init pxl value chann1
			tempVal2 = 0;

			for(frameNum = 0; frameNum < numFrames; frameNum++)
			{
				index = x + (getTotSampsPerLine() * y) + (getNumSampsPerFrame() * frameNum);
				tempVal += ((double)(getAcqData(index) / (double)(numFrames)));
	
				
				if (getBInput1() && getBInput2())
					tempVal2 += ((double) (getAcqData(index + shiftToNextChannel)) / (double)(numFrames));

			}

			if (acqEng.getBInput1())
			{
				//Scale value into 8 bit range for display.
				if (tempVal < (double)min1) tempVal = (double)min1;
				if (tempVal > (double)max1) tempVal = (double)max1;
				imageData1[pxlCount] = (unsigned char)(((tempVal - (double)min1)/((double)max1 - (double)min1)) * 255);

				if (acqEng.getBInput2())
				{
					if (tempVal2 < (double)min2) tempVal2 = (double)min2;
					if (tempVal2 > (double)max2) tempVal2 = (double)max2;
					(imageData2)[pxlCount] = (unsigned char)(((tempVal2 - (double)min2)/((double)max2 - (double)min2)) * 255);
				}
			}
			else		//This is the case where only channel 2 was acquired
			{
				if (tempVal < (double)min2) tempVal = (double)min2;
				if (tempVal > (double)max2) tempVal = (double)max2;
				(imageData2)[pxlCount] = (unsigned char)(((tempVal - (double)min2)/((double)max2 - (double)min2)) * 255);
			}


			pxlCount++;
		}
	}*/
	return 1;
}


//ProcessDataForHistogram
int TwoPhotonApp::ProcessDataForHistogram()
{
	/*unsigned long shiftToNextChannel = 0;					NEED IMPLEMENTATION
	short val;
	short val2;
	int binNum;
	float minADCVal = (float)Min_Count;
	float ADCRAnge = (float)(Max_Count - Min_Count);

	if (acqStruct1.bInput1 && acqStruct1.bInput2)
		shiftToNextChannel = acqStruct1.numSampsTotal;
	
	//Zero out previous histogram if necessary
	if(acqStruct1.bInput1)
		for (int i=0; i < NUM_BINS; i++)
			appState->histArray1[i]=0;
	if(acqStruct1.bInput2)
		for (int i=0; i < NUM_BINS; i++)
			appState->histArray2[i]=0;

	for (unsigned long sampNum = 0; sampNum <acqStruct1.numSampsTotal; sampNum++)
	{
		val = acqStruct1.acqData[sampNum];
		val2 = acqStruct1.acqData[sampNum + shiftToNextChannel];

		if (acqStruct1.bInput1)
		{
			binNum = (int) floor(((double)val - minADCVal) / (ADCRAnge /(double) NUM_BINS));
			appState->histArray1[binNum]++;
			
			if (acqStruct1.bInput2)
			{
				binNum = (int) floor(((double)val2 - minADCVal) / (ADCRAnge / (double)NUM_BINS));
				appState->histArray2[binNum]++;
			}
		}
		else if (acqStruct1.bInput2)
		{
			binNum = (int) floor(((double)val - minADCVal) / (ADCRAnge /(double) NUM_BINS));
			appState->histArray2[binNum]++;
		}

	}
	*/
	return 1;
	
}

//Update2PDataStruct
int TwoPhotonApp::Update2PDataStruct()			//Might not be needed, depending on how classes are set up
{
	return 1;
}

//ParseConfig
int TwoPhotonApp::ParseConfig()
{
	char line[50];
	char *temp;
	int retVal;
	FILE *cfg;

	//open config file
	cfg = fopen(".\\two_photon.cfg", "r");
	if(cfg==NULL)
	{
		QMessageBox::about(0,"File Error","Configuration File Not Found");
		//goto cfg_error;
	}
	else
	{
	//get one line of config - must be space delimited
	fgets(line,50,cfg);
	char *token;
	//use string tokenizer to retrieve first token on line (key name)
	token = strtok(line," ");
	//Test and see if key is a correct value
	
	temp = "numObjectives";
	//If key is numObjectives
	retVal = strcmp(temp,token);
	if(retVal == 0)
	{
		char *tempObj;
		int tempScaling;
		token = strtok(NULL," ");
		int numObjs = atoi(token);
		//iterate through objectives -add scaling to array and magnification to gui list 
		for(int i = 0; i<numObjs;i++)
		{
			fgets(line,50,cfg);
			tempObj = strtok(line," ");	//objective value

			token = strtok(NULL," ");
			tempScaling = atoi(token);	//scaling value (um/V)
			
			/*SetCtrlVal(appState->scanStruct.ImgTabPanelHandle,TABPANEL_2_bxMag,80);									NEED IMPLEMENTATION
			InsertListItem (appState->scanStruct.ImgTabPanelHandle, TABPANEL_2_bxMag, -1, tempObj,tempScaling); */
		}
	}
	
	fclose(cfg);
	}
	return 1;
}

//AomZeroStart
int TwoPhotonApp::AomZeroStart()
{
	return 1;
}

//AomStop
int TwoPhotonApp::AomStop()
{
	return 1;
}

//AcqLifeTime1Point
int TwoPhotonApp::AcqLifeTime1Point(float xVolt, float yVolt, float timePerPoint, char FILE_NAME[])
{
	/*int retval = 0;
	int error;
	TaskHandle	GalvoTaskHandle = 0;
	TaskHandle	TCSPCBoardTrigTaskHandle = 0;
	double		writeSamples[2] = {xVolt, yVolt};
	double		trigVal = 2.0;
	char        errBuff[2048]={'\0'};



	//Create and setup Galvo Task
	DAQmxErrChk (DAQmxCreateTask("GalvoTask",&GalvoTaskHandle));
	DAQmxErrChk (DAQmxCreateAOVoltageChan(GalvoTaskHandle, scanEng.getXChan(),"",scanEng.getXMinVolts(), scanEng.getXMaxVolts(),DAQmx_Val_Volts,NULL));
	DAQmxErrChk (DAQmxCreateAOVoltageChan(GalvoTaskHandle, scanEng.getYChan(),"",scanEng.getYMinVolts(), scanEng.getYMaxVolts(),DAQmx_Val_Volts,NULL));
	DAQmxErrChk (DAQmxCfgSampClkTiming(GalvoTaskHandle,"",1.0e6,DAQmx_Val_Rising,DAQmx_Val_ContSamps,2));
	DAQmxErrChk (DAQmxWriteAnalogF64(GalvoTaskHandle,1,0,10.0,DAQmx_Val_GroupByChannel,writeSamples,NULL,NULL));
	DAQmxStartTask(GalvoTaskHandle); //Moves galvos to correct position immediately.

	//Create and setup TCSPC trigger Task
	DAQmxErrChk (DAQmxCreateTask("TCSPCBoardTrigTask",&TCSPCBoardTrigTaskHandle));
	DAQmxErrChk (DAQmxCreateAOVoltageChan(TCSPCBoardTrigTaskHandle, TCSPC_Trig_Channel,"",0.0, trigVal,DAQmx_Val_Volts,NULL));
	DAQmxErrChk (DAQmxWriteAnalogF64(TCSPCBoardTrigTaskHandle,1,1,10.0,DAQmx_Val_GroupByChannel,&trigVal,NULL,NULL));
	

	//Configure galvo operation to be pulsed and finite samples
	//SetCtrlVal(AOMTabHandle,TABPANEL_5_AOMOnDuration,1);	NEED IMPLEMENTATION


	*/
	return 0;

/*Error:
	if( DAQmxFailed(error) )
	{
		if (!GalvoTaskHandle)
		{
			DAQmxStopTask(GalvoTaskHandle);
			DAQmxClearTask(GalvoTaskHandle);
		}

		if (!TCSPCBoardTrigTaskHandle)
		{
			DAQmxStopTask(TCSPCBoardTrigTaskHandle);
			DAQmxClearTask(TCSPCBoardTrigTaskHandle);
		}
		DAQmxGetExtendedErrorInfo(errBuff,2048);
		QMessageBox::about(0,"DAQmx Error", errBuff);
	}
	return 0;
*/


}

/*int AcqDrive(int linescan)
{
	
	
	int				error=0;
	
	TaskHandle		digTaskHandle=0;  	
	bool			done;
	int				retVal;
	int				numZSteps;
	int				iZCount;
	ROI*			curr_roi;				//for linescan endpoints
	ContourInfo2*	contourInfo;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	double			lineScanSpeed;


	
	done = false;
	
	//this->InitTwoPhotonApp(1,NULL);	NEED IMPLEMENTATION
	

	//if regular acq (not line scan), call generateWaveForms
	if(linescan==0)
	{	
		InitScanEngineStruct(panel, appState->scanStruct, true);
		retVal = GenerateWaveForms(appState->scanStruct);
		retVal = InitAcqEngineStruct(panel, appState->acqStruct, true);
	}
	
	else
	{
	/*	retVal = InitLineScanEngineStruct(panel, appState->scanStruct, true);		NEED IMPLEMENTATION
		//Grab ROI info from display window
		curr_roi = imaqGetWindowROI(appState->displayWinNum1);
		contourInfo = imaqGetContourInfo2(curr_roi, 1);
		if(!contourInfo)
			{
				MessagePopup("Error", "No Data Points Defined");
				goto Error;
			}
		if (contourInfo->type != IMAQ_LINE)
			{
				MessagePopup("Error", "Points must be defined with line tool");
				goto Error;
			}
		//grab endpoints from line contour
		x1=contourInfo->structure.line->start.x;
		y1=contourInfo->structure.line->start.y;	
		x2=contourInfo->structure.line->end.x;
		y2=contourInfo->structure.line->end.y;
	
		retVal = GenerateLineScanWave(appState->scanStruct,panel,x1,y1,x2,y2);
		retVal = InitLineAcqEngineStruct(panel, appState->acqStruct, true);
			lineScanSpeed = UpdateLineScanSpeed(panel);
		//2Khz
		if (lineScanSpeed >2000)
		{
			MessagePopup("Error", "Scan Rate cannot go above 2Khz");
				goto Error;
		}
		
	}
	

	//_____Setup for 3D Acq if needed_____
	if (appState->acqStruct.b3DAcq)
	{
		numZSteps = 1 + (int)(((appState->acqStruct.zStopPos - appState->acqStruct.zStartPos) 
			/ appState->acqStruct.zStepSize) + 0.5);
	}
	else
		numZSteps = 1;
		//_____DAQmx DigOut Configure Code (frame sync)____________________________________________
	DAQmxErrChk (DAQmxConnectTerms ("/Dev1/PFI13", "/Dev1/PFI1", DAQmx_Val_DoNotInvertPolarity ));
	DAQmxErrChk (DAQmxCreateTask("",&digTaskHandle));
	DAQmxCreateCOPulseChanFreq (digTaskHandle, "/Dev1/ctr1", "Trig", DAQmx_Val_Hz, DAQmx_Val_Low, 
															0.0, appState->acqStruct.acqTrigRate, 0.01);
		//_____config AOut task for triggered, finite samps_____
	retVal = ScanEngineConfigDAQmxTask(appState->scanStruct, true, false);
	
	//_____Write samples to daq board_____
	retVal = ScanEngineWriteDAQmxTask(appState->scanStruct);
		//_____Config AIn task for triggered, finite samps_____
	retVal = AcqEngineConfigDAQmxTask(appState->acqStruct, true, false);


	SetCtrlVal(panel,PANEL_ledAcquiring,1); 
	SetCtrlVal(panel,PANEL_ledRunning,1);
	ProcessDrawEvents();

	appState->bRunning = true; 
	
	for (iZCount = 0; iZCount < numZSteps; iZCount++)
	{
		//update Z Pos.
		appState->zStepStruct.desiredZPos = appState->acqStruct.zStartPos + (appState->acqStruct.zStepSize * iZCount);
		if (appState->zStepStruct.desiredZPos != appState->acqStruct.zPos)
			ZMoveToStruct(appState->zStepStruct);
		SetCtrlVal(appState->zStepStruct.panelHandle,PANEL_bxCurrentZPos,appState->zStepStruct.currentZPos);
		appState->acqStruct.zPos = appState->zStepStruct.currentZPos;
		
		//_____Start DAQmx write._____
		retVal = ScanEngineStartDAQmxTask(appState->scanStruct); 
		//_____Start DAQmx Read._____
		retVal = AcqEngineStartDAQmxTask(appState->acqStruct);
		//_____Start DAQmx Trig._____
		DAQmxErrChk (DAQmxStartTask(digTaskHandle)); 
			//_____Perform read.  Execution will pause until all samps acquired._____
		retVal = AcqEngineReadDAQmxTask(appState->acqStruct); 
		
		//_____Update Histogram._____
		retVal = ProcessDataForHistogram(appState->acqStruct);
		if (appState->acqStruct.bInput1)
			DeleteGraphPlot (appState->panelHandle, PANEL_HIST1, -1, VAL_IMMEDIATE_DRAW);
			PlotXY (appState->panelHandle, PANEL_HIST1, appState->binsArray, appState->histArray1, NUM_BINS, 
				VAL_SHORT_INTEGER, VAL_UNSIGNED_INTEGER, VAL_VERTICAL_BAR, VAL_SOLID_SQUARE, VAL_SOLID, 
				1, VAL_BLUE);
		if (appState->acqStruct.bInput2)
			DeleteGraphPlot (appState->panelHandle, PANEL_HIST2, -1, VAL_DELAYED_DRAW);
			PlotXY (appState->panelHandle, PANEL_HIST2, appState->binsArray, appState->histArray2, NUM_BINS, 
				VAL_SHORT_INTEGER, VAL_UNSIGNED_INTEGER, VAL_VERTICAL_BAR, VAL_SOLID_SQUARE, VAL_SOLID, 
				1, VAL_BLUE);
			//_____Separate data into two images if needed, scale and convert to 8 bit for display._____
		retVal = ProcessDataForDisplay(appState->acqStruct);
		imaqArrayToImage(appState->image1, appState->imageData1, (int)appState->acqStruct.numXPxls, 
						(int)(appState->acqStruct.numYPxls)); 
		imaqArrayToImage(appState->image2, appState->imageData2, (int)appState->acqStruct.numXPxls, 
						(int)(appState->acqStruct.numYPxls)); 	
		
		//--Update display--
		imaqDisplayImage(appState->image1, appState->displayWinNum1, 1);
		imaqDisplayImage(appState->image2, appState->displayWinNum2, 1);
		
		//Save the data to file if requested
		if (appState->acqStruct.saveData)
		{
			if(linescan==0)
			{
				retVal =Update2PDataStruct(appState);
				if (appState->acqStruct.bInput1) 
					retVal = WriteTheData (appState->data2P, 1, appState->acqStruct);
				if (appState->acqStruct.bInput2) 
					retVal = WriteTheData (appState->data2P, 2, appState->acqStruct);
			}
			else	//If linescan, need to record correct lineLength/lineRate
			{
				retVal =CalcLineLengthStruct(appState->scanStruct,x1,y1,x2,y2);
				retVal =Update2PDataStruct(appState);
				if (appState->acqStruct.bInput1) 
					retVal = WriteTheData (appState->data2P, 1, appState->acqStruct);
				if (appState->acqStruct.bInput2) 
					retVal = WriteTheData (appState->data2P, 2, appState->acqStruct);
			}
				
		}
	
		DAQmxStopTask(digTaskHandle);
		retVal = AcqEngineStopDAQmxTask(appState->acqStruct);
		retVal = ScanEngineStopDAQmxTask(appState->scanStruct);
	}
		
	retVal = ScanEngineStopDAQmxTask(appState->scanStruct);
		//Cleanup ...
	DAQmxErrChk (DAQmxDisconnectTerms ("/Dev1/PFI12", "/Dev1/PFI1"));
	//	retVal = AcqEngineStopDAQmxTask(acqStruct);
	DAQmxClearTask(appState->scanStruct.scanTaskHandle);
	appState->scanStruct.scanTaskHandle = 0;
	//	retVal = ScanEngineStopDAQmxTask(scanStruct);
	DAQmxClearTask(appState->acqStruct.acqTaskHandle);
	appState->acqStruct.acqTaskHandle = 0;
	DAQmxClearTask(digTaskHandle);
	
	ScanEngineReleaseMemory(appState->scanStruct);
	AcqEngineReleaseMemory(appState->acqStruct);

	SetCtrlVal(appState->panelHandle,PANEL_ledRunning,0); 
	SetCtrlVal(appState->panelHandle,PANEL_ledAcquiring,0);
	SetCtrlVal(appState->panelHandle,PANEL_cbx3DAcq,0);
	SetCtrlVal(appState->panelHandle,PANEL_cbxSave,0);
	return 0;

	

Error:
	DAQmxErrChk (DAQmxDisconnectTerms ("/Dev1/PFI12", "/Dev1/PFI1")); 

	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(appState->errBuff,2048);
	if( digTaskHandle!=0 ) 
	{
		// _____DAQmx Stop Code
//		DAQmxStopTask(digTaskHandle);
//		DAQmxClearTask(digTaskHandle);
	}
	if( appState->scanStruct.scanTaskHandle!=0 ) 
	{
	  	DAQmxStopTask(appState->scanStruct.scanTaskHandle);
		DAQmxClearTask(appState->scanStruct.scanTaskHandle);
		appState->scanStruct.scanTaskHandle = 0;
		SetCtrlVal(appState->panelHandle,PANEL_ledRunning,0); 
		SetCtrlVal(appState->panelHandle,PANEL_ledAcquiring,0);
	}
	if( appState->acqStruct.acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(appState->acqStruct.acqTaskHandle);
		DAQmxClearTask(appState->acqStruct.acqTaskHandle);
		appState->acqStruct.acqTaskHandle = 0;
	}
	
	if (appState->scanStruct.memIsAllocated)
		ScanEngineReleaseMemory(appState->scanStruct);
	
	if (appState->acqStruct.memIsAllocated)
		AcqEngineReleaseMemory(appState->acqStruct);


	if( DAQmxFailed(error) )
		MessagePopup("DAQmx Error",appState->	errBuff);
	return 0;
}*/

//--------------------------------------------------------------------------------------------------------

// Overidden GUI Functions (slots)  ----------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
