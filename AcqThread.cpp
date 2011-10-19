/*	Name: AcqThread.cpp
	Description: Provides multithreaded support for acquisition functions in parallel
				 with GUI functionality.

	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712
	
	Created:	1/22/2009
	Updated:	
*/ 
#include "AcqThread.h"


#include "acqengine.h"
#include "scanengine.h"
#include "2pData.h"
#include "zStepDriver.h"


//Global Vars---------------------

double			pDone;

//----------------------------------


//Function: Constructor
//Description: Creates pointers to data structures contained by TwoPhotonGui to set up acquisition
//			   Sets up Vision modules
AcqThread::AcqThread(int adcNumBits, long minCount,long maxCount,double vNum,
					ScanEngine *scanEngi, AcqEngine *acqEngi,  DataFile2P *data2Pi, zStepperDriver *zStepper, AomControl *aCtrl)
{

	ADC_Num_Bits = adcNumBits;
	Min_Count = minCount;
	Max_Count = maxCount;
	Version_Number = vNum;

	scanEng = scanEngi;
	acqEng = acqEngi;
	data2P = data2Pi;
	zStep = *zStepper;
	aomCtrl = aCtrl;

	Point	toolPos;
	toolPos.x=850;
	toolPos.y=20;
	
	//temporary scaling
	scaleMin1 = 0;
	scaleMax1 = 32767;
	scaleMin2 = 0;
	scaleMax2 = 32767;


	//Setup diplay and display tools using NIVision calls
	image1 = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	displayWinNum1 = 1;
	imaqDisplayImage(image1, displayWinNum1, 1);
	imaqSetWindowTitle(1, "PMT Images");
	imaqSetWindowSize(1, 256, 256);
	posWindow1.x = 850;
	posWindow1.y = 300;
	imaqMoveWindow(1, posWindow1);

	imaqShowToolWindow (TRUE);
	imaqMoveToolWindow(toolPos);
	imaqSetToolColor(&IMAQ_RGB_BLUE);
	imaqSetCurrentTool (IMAQ_POLYLINE_TOOL);

	image2 = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	displayWinNum2 = 2;
	imaqDisplayImage(image2, displayWinNum2, 1);
	imaqSetWindowTitle(2, "ROI Images");
	imaqSetWindowSize(2, 256, 256);
	posWindow2.x = 850;
	posWindow2.y = 590;
	imaqMoveWindow(2, posWindow2);

	intScalingCoeff = 1.0;
	bScaleCoeffCalc = false;


	//Allocate memory for display arrays.
	imageData1 = new RGBValue[acqEng->getnumValidXSamps() * acqEng->getnumValidYSamps()];
	imageData2 = new RGBValue[acqEng->getWidth() * acqEng->getRepeats()];

	bContinuous		=	false;
	bLifetimeFov	=	false;
	bLinescan		=	false;

}
//Function: init
//Description: Creates pointers to data structures contained by TwoPhotonGui to set up acquisition
void AcqThread::init(ScanEngine *scanEngi, AcqEngine *acqEngi,  DataFile2P *data2Pi, zStepperDriver *zStepper, AomControl *aCtrl)
{

	scanEng = scanEngi;
	acqEng = acqEngi;
	data2P = data2Pi;
	zStep = *zStepper;
	aomCtrl = aCtrl;

	terminate = false;

	return;
}
AcqThread::~AcqThread()
{

}
//Function: Run
//Description: Runs acquisition routine in a new thread
//			   This function cannot access gui widgets so all variables are frozen when thread class instance is created
void AcqThread::run()
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
	int				numValidXSamps;
	int				numValidYSamps;
	double			debug;

	//set to not be terminated (default)
	terminate = false;


	//scaling coeff has not been calculated for this acq yet
	bScaleCoeffCalc = false;		

	//overscan values have not yet been calculated into the fov
	scanEng->setOverscanCalculated(false);

	done = false;

	do{
		//if regular acq (not line scan), call generateWaveForms
		if(!bLinescan)
		{	
			scanEng->initScan(true,false);
			retVal = scanEng->generateWaveForms();
			retVal = acqEng->initAcq(true,false);
		}
		
		else  //Line scan mode
		{
			retVal = scanEng->initScan(true,true);

			//Grab ROI info from display window
			curr_roi = imaqGetWindowROI(displayWinNum1);
			contourInfo = imaqGetContourInfo2(curr_roi, 1);
			if(!contourInfo)
				{
					//QMessageBox::about(this,"Error","No data points defined\n");
					goto Error;
				}
			if (contourInfo->type != IMAQ_LINE)
				{
					//QMessageBox::about(this,"Error","Points must be defined with line tool\n");
					goto Error;
				}

			//grab endpoints from line contour
			x1=contourInfo->structure.line->start.x;
			y1=contourInfo->structure.line->start.y;	
			x2=contourInfo->structure.line->end.x;
			y2=contourInfo->structure.line->end.y;
		
			//Update data class
			data2P->Header.setLsX1(x1);
			data2P->Header.setLsX2(x2);
			data2P->Header.setLsY1(y1);
			data2P->Header.setLsY2(y2);

			//Calc the volatges that correspond to the x1,y1,x2,y2.  These will define the line scan waveforms.
			double x1V,y1V,x2V,y2V;
			CalcXYVoltsFromPxlVal(x1, y1, x1V, y1V);
			scanEng->setROIPt1XVolts(x1V);
			scanEng->setROIPt1YVolts(y1V);
			CalcXYVoltsFromPxlVal(x2, y2, x2V, y2V);
			scanEng->setROIPt2XVolts(x2V);
			scanEng->setROIPt2YVolts(y2V);

			retVal = scanEng->generateLineScanWaveForms();
			retVal = acqEng->initAcq(true,true);
			
		}
		
		//_____Setup for 3D Acq if needed_____
		if (acqEng->getB3DAcq())
		{
			numZSteps = this->CalcNumZSteps();
			CalcIntensityScalingCoeff();
		}
		else
			numZSteps = 1;

		//_____DAQmx DigOut Configure Code (Sample clock for Aout and Ain)____________________________________________
                DAQmxErrChk (DAQmxCreateTask("SampleClockTask",&digTaskHandle));
                DAQmxErrChk (DAQmxCreateCOPulseChanFreq (digTaskHandle, "/Dev1/ctr1", "SampleClock", DAQmx_Val_Hz, DAQmx_Val_Low,
                                0.1, scanEng->getSamp_Rate(), 0.5));
		if (bLinescan)
			DAQmxErrChk (DAQmxCfgImplicitTiming(digTaskHandle,DAQmx_Val_ContSamps ,scanEng->getNumSampsPerFrame_LS()))
		else
			DAQmxErrChk (DAQmxCfgImplicitTiming(digTaskHandle,DAQmx_Val_ContSamps ,scanEng->getNumSampsPerFrame()))


			//_____config AOut task for triggered, finite samps_____
		retVal = scanEng->configDAQmxTask(true, false);
		
		//_____Write samples to daq board_____
		retVal = scanEng->writeDAQmxTask();

			//_____Config AIn task for triggered, finite samps_____
		retVal = acqEng->configDAQmxTask(true, false);

		pDone = 0;
		
		for (iZCount = 0; iZCount < numZSteps; iZCount++)
		{
			//Only if there are Z steps to do
			if(numZSteps>1)
			{
				//update Z Pos
				zStep.setDesiredZPos(acqEng->getZStartPos() + (acqEng->getZStepSize() * iZCount));
				//if (zStep->getDesiredZPos() != acqEng->getZPos())
				if(numZSteps!=1)
					zStep.MoveTo(zStep.getDesiredZPos(),zStep.getCurrentStepConvFactor());

				//Manual zPos Calculations
				//acqEng->setZPos(acqEng->getZPos()+acqEng->getZStepSize());
				acqEng->setZPos(zStep.getCurrentZPos());

				emit sigZPosChange(zStep.getCurrentZPos());

				//Update pDone for updating gui progress bar
				pDone = ((double)iZCount)/((double)numZSteps);
				emit sendProgress(pDone);

				//update gui field
				//TwoPhotonGui::doubleSpinBox_zPos->setValue(zStepEng->getCurrentZPos()); NEED IMPLEMENTATION
				
				//update acqEng field
				//acqEng->setZPos(zStep->getCurrentZPos());		NOTE: this isn't working, using manual z-pos calculations
			}

			//if Aom Voltage scaling is selected, update Aom
			if(aomCtrl->getBIntScaling())
			{
				debug = CalcAomIntVoltage((acqEng->getZStartPos()-acqEng->getZPos()));
				AomUpdate(debug);		//turns AOM on
			}
			else
			{
				AomUpdate(aomCtrl->getAomOnVoltage());  //Turns on AOM (no updating for depth)
			}

			 
                        //_____Start DAQmx Read._____
                        retVal = acqEng->startDAQmxTask();
			//_____Start DAQmx write._____
			retVal = scanEng->startDAQmxTask(); 

			//_____Start DAQmx Trig._____
                        DAQmxErrChk (DAQmxStartTask(digTaskHandle));
			//_____Perform read.  Execution will pause until all samps acquired._____
			retVal = acqEng->readDAQmxTask(); 

			/*		Added for diagnostics.  I want to write out the acq buffer here before I flip even rows.
			

			*/

			/*
				NEED IMPLEMENTATION
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
			*/
			
			//_____Separate data into two images if needed, scale and convert to 8 bit for display._____
			if(bLinescan)
			{
				numValidXSamps = (int)acqEng->getWidth();
				numValidYSamps = (int)acqEng->getRepeats();
			}
			else
			{
				numValidXSamps = (int)acqEng->getnumValidXSamps();
				numValidYSamps = (int)acqEng->getnumValidYSamps();
			}
			retVal = ProcessDataForDisplay(bLinescan);
			if(!bLinescan)
			{
				imaqArrayToImage(image1, imageData1, (int)acqEng->getnumValidXSamps(),(int)acqEng->getnumValidYSamps());
			}
			else
			{
				imaqArrayToImage(image2, imageData2, (int)acqEng->getWidth(),(int)acqEng->getRepeats());
			}
		

			//--Update display--
			if(!bLifetimeFov) //does not update vision image if lifetime fov (BUG)
			{
				if (!bLinescan)
					imaqDisplayImage(image1, displayWinNum1, 1);
				else
					imaqDisplayImage(image2, displayWinNum2, 1);
			}

			//imaqHistogram(image1,65536,0,1,NULL);


			//Update Data2P class instance before writing it to file
			updateDataPt();

			//Save the data to file if requested
			if (acqEng->getSaveData())
			{
				if(!bLinescan)
				{
					Update2PDataStruct();

					if (acqEng->getBInput1()) 
						retVal = data2P->WriteTheData(1,acqEng);
					if (acqEng->getBInput2()) 
						retVal = data2P->WriteTheData(2,acqEng);
				}
				else	//If linescan, need to record correct lineLength/lineRate
				{
					retVal =scanEng->calcLineLengthStruct(x1,y1,x2,y2);
					retVal =scanEng->calcLineRate();

					Update2PDataStruct();
					
					data2P->Header.setLineRate(data2P->Header.getLinescanRate());	//ensure linerate recorded is that of linescan


					if (acqEng->getBInput1()) 
						retVal = data2P->WriteTheData(1,acqEng);
					if (acqEng->getBInput2()) 
						retVal = data2P->WriteTheData(2,acqEng);
				}
					
			}
		
                        DAQmxStopTask(digTaskHandle);
			retVal = acqEng->stopDAQmxTask();
			retVal = scanEng->stopDAQmxTask();
			//retVal = scanEng->clearDAQmxTask();
			//scanEng->setScanTaskHandle(0);
			
			if(terminate)
				goto Kill;
				
			//turn off Aom until ready to image again (set to 0 volts)
			AomUpdate(0.0);
			aomCtrl->setAomOn(false);
		}
Kill:
		retVal = scanEng->stopDAQmxTask();
		//Cleanup ...
		//	retVal = AcqEngineStopDAQmxTask(acqStruct);
		DAQmxClearTask(scanEng->getScanTaskHandle());
		scanEng->setScanTaskHandle(0);
		//	retVal = ScanEngineStopDAQmxTask(scanStruct);
		DAQmxClearTask(acqEng->getAcqTaskHandle());
		acqEng->setAcqTaskHandle(0);
		DAQmxClearTask(digTaskHandle);
		
		scanEng->releaseMemory();
		acqEng->releaseMemory();

		}while(bContinuous && (!terminate));

	/*
	SetCtrlVal(appState->panelHandle,PANEL_ledRunning,0);	NEED IMPLEMENTATION
	SetCtrlVal(appState->panelHandle,PANEL_ledAcquiring,0);
	SetCtrlVal(appState->panelHandle,PANEL_cbx3DAcq,0);
	SetCtrlVal(appState->panelHandle,PANEL_cbxSave,0);
	
	
	*/

	//Disable Aom (set to 0 volts)--------------------
	AomUpdate(0.0);
	aomCtrl->setAomOn(false);

	bScaleCoeffCalc = false;

	pDone = 0;

	emit acqFinished();

	quit();
	return;

Error:
	//return;

	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

		//DAQmxDisconnectTerms ("/Dev1/PFI12", "/Dev1/PFI1"); 

	if( digTaskHandle!=0 ) 
	{
		// _____DAQmx Stop Code
		DAQmxStopTask(digTaskHandle);
		DAQmxClearTask(digTaskHandle);
	}
	if( scanEng->getScanTaskHandle() != 0 ) 
	{
	  	DAQmxStopTask(scanEng->getScanTaskHandle());
		DAQmxClearTask(scanEng->getScanTaskHandle());
		scanEng->setScanTaskHandle(0);
		
		//SetCtrlVal(appState->panelHandle,PANEL_ledRunning,0);		NEED IMPLEMENTATION
		//SetCtrlVal(appState->panelHandle,PANEL_ledAcquiring,0);
	}
	if( acqEng->getAcqTaskHandle() != 0 ) 
	{
		DAQmxStopTask(acqEng->getAcqTaskHandle());
		DAQmxClearTask(acqEng->getAcqTaskHandle());
		acqEng->setAcqTaskHandle(0);
	}
	
	if (scanEng->getMemIsAllocated())
		scanEng->releaseMemory();
	
	if (acqEng->getMemIsAllocated())
		acqEng->releaseMemory();


//	if( DAQmxFailed(error) )
//		QMessageBox::about(this,"DAQmx Error",errBuff);

	emit acqFinished();
	return;

}

//Function: StopExec
//Description: stops thread / image acquisition
void AcqThread::stopExec()
{
	//set flag to kill thread
	terminate = true;	
}
//Function: ProcessDataForDisplay
//Description: Recreate image buffers and prepare for output to NI vision
int AcqThread::ProcessDataForDisplay(int linescan)
{
	unsigned long int pxlCount =0 ;
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
	int		numValidXSamps;
	int		numValidYSamps;
	unsigned long numSampsTotal;
	unsigned long overScan;
	unsigned long totSampsPerLine;
	unsigned long numSampsPerFrame;

	//set x/y dimensions based on whether or not acq is linescan
	if (!linescan)
	{
		numValidXSamps = acqEng->getnumValidXSamps();
		numValidYSamps = acqEng->getnumValidYSamps();
		numSampsTotal = acqEng->getNumSampsTotal();
		overScan = acqEng->getOverscan();
		totSampsPerLine = acqEng->getTotSampsPerLine();
		numSampsPerFrame = acqEng->getNumSampsPerFrame();
	}
	else
	{
		numValidXSamps = acqEng->getWidth();
		numValidYSamps = acqEng->getRepeats();
		numSampsTotal = acqEng->getNumSampsTotal_LS();
		overScan = acqEng->getOverscan_LS();
		totSampsPerLine = acqEng->getTotSampsPerLine_LS();
		numSampsPerFrame = acqEng->getNumSampsPerFrame_LS();
	}

	//delete and reinitialize display data arrays to size of acquisition
	if (!bLinescan)
	{
		delete [] imageData1;
		imageData1 = new RGBValue[numValidXSamps * numValidYSamps];
		for (int ii = 0; ii<numValidXSamps * numValidYSamps; ii++)
			imageData1[ii] = IMAQ_RGB_BLACK;
	}
	else
	{
		delete [] imageData2;
		imageData2 = new RGBValue[numValidXSamps * numValidYSamps];
		for (int ii = 0; ii<(numValidXSamps * numValidYSamps); ii++)
			imageData2[ii] = IMAQ_RGB_BLACK;
	}

	
	//~

	unsigned long shiftToNextChannel = 0;

	numFrames = acqEng->getNumFrames();
	if (acqEng->getBInput1() && acqEng->getBInput2())
		shiftToNextChannel = numSampsTotal;

	for (y = 0; y < numValidYSamps; y++)
	{
		for(x = acqEng->getXOffset() + overScan; x < numValidXSamps + acqEng->getXOffset() + overScan; x++)
		{
	
			//calc average pxl val accross all frames
			tempVal = 0;		//init pxl value chann1
			tempVal2 = 0;

			for(frameNum = 0; frameNum < numFrames; frameNum++)
			{
				index = x + (totSampsPerLine * y) + (numSampsPerFrame * frameNum);
				tempVal += ((double)(acqEng->getAcqData(index) / (double)(numFrames)));
	
				
				if (acqEng->getBInput1() && acqEng->getBInput2())
					tempVal2 += ((double) (acqEng->getAcqData(index + shiftToNextChannel)) / (double)(numFrames));

			}

			if (acqEng->getBInput1())
			{
				//Scale value into 8 bit range for display.
				if (tempVal < (double)min1) tempVal = (double)min1;
				if (tempVal > (double)max1) tempVal = (double)max1;
				if(!bLinescan)
				{
					imageData1[pxlCount].G = (unsigned char)(((tempVal - (double)min1)/((double)max1 - (double)min1)) * 255);
				}
				else
				{
					imageData2[pxlCount].G = (unsigned char)(((tempVal - (double)min1)/((double)max1 - (double)min1)) * 255);
				}


				if (acqEng->getBInput2())
				{
					if (tempVal2 < (double)min2) tempVal2 = (double)min2;
					if (tempVal2 > (double)max2) tempVal2 = (double)max2;
					if(!bLinescan)
					{
						imageData1[pxlCount].R = (unsigned char)(((tempVal2 - (double)min2)/((double)max2 - (double)min2)) * 255);
					}
					else
					{	
						imageData2[pxlCount].R = (unsigned char)(((tempVal2 - (double)min2)/((double)max2 - (double)min2)) * 255);
					}
				}
			}
			else		//This is the case where only channel 2 was acquired
			{
				if (tempVal < (double)min2) tempVal = (double)min2;
				if (tempVal > (double)max2) tempVal = (double)max2;
				if (!bLinescan)
					imageData1[pxlCount].R = (unsigned char)(((tempVal - (double)min2)/((double)max2 - (double)min2)) * 255);
				else
					imageData2[pxlCount].R = (unsigned char)(((tempVal - (double)min2)/((double)max2 - (double)min2)) * 255);
				
			}


			pxlCount++;
		}
	}
	return 1;
}
//Function: getContourVision
//Description: Returns contour i information from vision module to main GUI instance
ContourInfo2* AcqThread::getContourVision(int i)
{
	ROI*			curr_roi;

	curr_roi = imaqGetWindowROI(displayWinNum1);
	return(imaqGetContourInfo2(curr_roi, i));
}
//Function: UpdateDataFile
//Description: Updates data Pointer to newly acquired buffer
void AcqThread::updateDataPt()
{
	data2P->setPtrData(acqEng->getAcqData());
}
//Function: Toggle Tools
//Description: Toggles the tool bar visibility
void AcqThread::toggleTools()
{
	int visible;

	//Determine if tool window is visible
	imaqIsToolWindowVisible(&visible);
	
	//if window is visible, set to invisible; if not set to visible
	if(visible)
		imaqShowToolWindow(0);
	else
		imaqShowToolWindow(1);
		
}
//Function: toggleImage1
//Description: Toggles Image 1 visibility
void AcqThread::toggleImage1()
{
	int visible;

	//Determine if window is visible
	imaqIsWindowVisible(displayWinNum1,&visible);
	
	//if window is visible, set to invisible; if not set to visible
	if(visible)
		imaqShowWindow(displayWinNum1,0);
	else
		imaqShowWindow(displayWinNum1,1);
}
//Function: toggleImage2
//Description: Toggles Image 2 visibility
void AcqThread::toggleImage2()
{
	
	int visible;

	//Determine if window is visible
	imaqIsWindowVisible(displayWinNum2,&visible);
	
	//if window is visible, set to invisible; if not set to visible
	if(visible)
		imaqShowWindow(displayWinNum2,0);
	else
		imaqShowWindow(displayWinNum2,1);
}
//Function: setIntensityScaling
//Description: Sets the scaling values for image intensity
void AcqThread::setIntensityScaling(short sMax1, short sMin1, short sMax2, short sMin2)
{
	scaleMax1 = sMax1;
	scaleMin1 = sMin1;
	scaleMax2 = sMax2;
	scaleMin2 = sMin2;
}
//Function: CalcNumZSteps
//Description: Calculates the number of z steps in an acquisition
//Returns: number of Z steps in acquisition
int AcqThread::CalcNumZSteps()
{
	int numZSteps;

	numZSteps = 1 + (int)(((acqEng->getZStopPos() - acqEng->getZStartPos()) 
				/ acqEng->getZStepSize()) + 0.5);

	if (numZSteps < 1)
		numZSteps = 1;

	return numZSteps;
}
//Function: Update2PDataStruct
//Description: Updates 2p data structure: header info and data
int AcqThread::Update2PDataStruct()
{

	if (acqEng->getBLineScan())
	{
                data2P->Header.setValidX((int)acqEng->getWidth());
                data2P->Header.setValidY((int)acqEng->getRepeats());
                data2P->Header.setNumX((int)acqEng->getTotSampsPerLine_LS());
                data2P->Header.setNumY((int)acqEng->getTotLinesPerFrame_LS());
	}
	else
	{
                data2P->Header.setValidX((int)acqEng->getnumValidXSamps());
                data2P->Header.setValidY((int)acqEng->getnumValidYSamps());
                data2P->Header.setNumX((int)acqEng->getTotSampsPerLine());
                data2P->Header.setNumY((int)acqEng->getTotLinesPerFrame());
	}

	data2P->Header.setVersion((float)Version_Number);
	data2P->Header.setB3DAcq(acqEng->getB3DAcq());

	data2P->Header.setNumFrames((int)acqEng->getNumFrames());
	data2P->Header.setMag(scanEng->getMag());
	data2P->Header.setXMinV((float)scanEng->getXMinVolts());
	data2P->Header.setXMaxV((float)scanEng->getXMaxVolts());
	data2P->Header.setYMinV((float)scanEng->getYMinVolts());
	data2P->Header.setYMaxV((float)scanEng->getYMaxVolts());
	data2P->Header.setZPos((float)acqEng->getZPos());
	data2P->Header.setXPos((float)acqEng->getXPos());
	data2P->Header.setYPos((float)acqEng->getYPos());
	data2P->Header.setADC_Min_Voltage((float)acqEng->getAcqMin());
	data2P->Header.setADC_Max_Voltage((float)acqEng->getAcqMax());
	//dataFile.Header.ZStep = (float)acqEngine.zStepSize;
	data2P->Header.setNumChans((int)acqEng->getNumActiveChannels());
	data2P->Header.setNumBits((int)ADC_Num_Bits);
	data2P->Header.setADC_Min_Count((int)Min_Count);
	
	data2P->Header.setLineLength((float)scanEng->getLineLength());
	data2P->Header.setLineRate((float)scanEng->getLineRate());
	data2P->Header.setObjScaling((float)scanEng->getScaling());

	data2P->setPtrData(acqEng->getAcqData());

	data2P->Header.setAomCtrlVoltage((float)aomCtrl->getAomVoltage());

	return 1;
	
}

//Function: CalcIntensityScalingCoeff
//Description: Solves for the unknown coefficient in the intensity scaling formula for z-depth scaled laser intensity, set global coeff var
//
//		V(z) = Vtop*e^(-z/zo)		V(z) = Aom voltage at depth z, Vtop = Aom Voltage at top (provided in gui/aomStruct)
//									z = current z position, zo = coefficient
//Input: none
//Output: intensity coefficient
double AcqThread::CalcIntensityScalingCoeff()
{
	double soln;
	//use the bottom case, where V(z) = Aom voltage at bottom, z = maximum depth (z stop position from gui)

	soln = aomCtrl->getIntensityScalingBottomV()/aomCtrl->getIntensityScalingTopV();	//  V(z)/Vtop = soln = e^(-z/zo)
	soln = log(soln);					//  ln(soln) = -z/zo
	soln = - (soln / (acqEng->getZStartPos() - acqEng->getZStopPos()));	//  -( soln / z) = 1/zo  -need depth not zPos
	soln = 1/soln;						//zo

	//set coeff (class member)
	intScalingCoeff = soln;
	//set bool to indicate coeff has been calculated for this acq
	bScaleCoeffCalc = true;

	return soln;

}
//Function: CalcAomIntVoltage
//Description: Calculates the Aom Voltage for given depth, according to the equation with solved coeff in CalcIntensityScalingCoeff()
//
//		V(z) = Vtop*e^(-z/zo)		V(z) = Aom voltage at depth z, Vtop = Aom Voltage at top (provided in gui/aomStruct)
//									z = current z position, zo = coefficient
//Input: zDepth, in um
//Output: AomVoltage for depth
double AcqThread::CalcAomIntVoltage(double depth)
{
	//if coefficient has not been calculated, do not calculate voltage
	if (!bScaleCoeffCalc)
		return 0;
	else
		return aomCtrl->getIntensityScalingTopV()*exp(-(depth/intScalingCoeff));

}
//Function: AomUpdate
//Description: change aom output value
//Input: voltage value to change aom voltage to
void AcqThread::AomUpdate(double voltage)
{
	//set new voltage value
	aomCtrl->setAomVoltage(voltage);

	//Restart Aom task with new voltage---------------
	aomCtrl->setAomOn(true);
	aomCtrl->setAomPulsed(false);
	aomCtrl->setAomContinuous(true);
	aomCtrl->stopDAQmxTask();
	aomCtrl->clearDAQmxTask();
	aomCtrl->makeWaveform();
	aomCtrl->configNiDAQ();
	aomCtrl->updateWaveform();
	aomCtrl->startDAQmxTask();
}

int AcqThread::CalcXYVoltsFromPxlVal(int x, int y, double& xVolts, double& yVolts)
{
	double xVoltsPerSamp;
	double yVoltsPerSamp;
	//int galvoLagPxls;


	//galvoOffsetPxls = TwoPhotonGui::spinBox_xOffset->value();

	//Calc the volts per sample for x and y.
	xVoltsPerSamp = (scanEng->getXMaxVolts() - scanEng->getXMinVolts()) /
								(scanEng->getnumValidXSamps()-1);
	yVoltsPerSamp = (scanEng->getYMaxVolts() - scanEng->getYMinVolts()) /
								(scanEng->getnumValidYSamps()-1);

	//galvoLagPxls = acqEng->getXOffset();

	//Calc x an y galvo voltage levels which correspond to the selected points
	xVolts = x * xVoltsPerSamp + scanEng->getXMinVolts();
	yVolts = y * yVoltsPerSamp + scanEng->getYMinVolts();
	return 1;


}
