/*	Name: TwoPhotonGui.cpp
	Description: Provides functionality for Qt-based GUI
	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712
	
	Created:	9/4/2008
	Updated:	4/20/2009

	Description:

	All gui slots are implemented in this file. All object instances of other classes are contained in this. All Gui signals are connected to slots
	in this file.

	This is the only class that has access to the gui widgets.
*/ 
   
#include <QtGui>

#include "TwoPhotonGui.h"	
#include "time.h"

//include 2p files for functionality
#include "2pData.h"
#include "acqengine.h"
#include "aomControl.h"
#include "scanengine.h"
#include "lifetimeacq.h"
#include "AcqThread.h"
#include "stepperDriver.h"
#include "zStepDriver.h"


#include <QSignalMapper>
#include "fstream"

//Constructor for TwoPhotonGui
//Connects all GUI signals and slots, initializes all encapsulated class instances, opens NI VISION module
TwoPhotonGui::TwoPhotonGui(QWidget * parent)
{
	Point	toolPos;
	toolPos.x=850;
	toolPos.y=20;

	
	//Set up QT Gui
	
	setupUi(this);


	//-----------------------------------------------------------------------------------
	//signal/slot connections------------------------------------------------------------
	//-----------------------------------------------------------------------------------
	
	//Create signalMapper so that I can tell which object sent signal when I have multiple
	// objects connected to one slot.
	signalMapper = new QSignalMapper(this);
	signalMapper->setMapping(pushButton_Acquire,pushButton_Acquire->objectName());
	signalMapper->setMapping(pushButton_linescanAcq,pushButton_linescanAcq->objectName());
	connect(pushButton_Acquire, SIGNAL( clicked()),signalMapper, SLOT(map()));
	connect(pushButton_linescanAcq, SIGNAL( clicked()),signalMapper, SLOT(map()));
	connect(signalMapper, SIGNAL(mapped(const QString &)),this,SIGNAL(startAcq(const QString &)));	//SLOT(AcqCallback(const QString &)));
	
	//Gui Initiated routines
	connect(pushButton_ResetOrigin, SIGNAL( clicked()),this, SLOT(setXYOrigin()));
	connect(actionAbout_TwoPhotonSoftware,SIGNAL(triggered()),this,SLOT(aboutTwoPhoton()));
	connect(actionDefault_Hardware_Connections,SIGNAL(triggered()),this,SLOT(defaultHwConnections()));
	connect(actionView_visionTools,SIGNAL(triggered()),this,SLOT(viewVisionTools()));
	connect(actionView_viewChan1,SIGNAL(triggered()),this,SLOT(viewImageOne()));
	connect(actionView_viewChan2,SIGNAL(triggered()),this,SLOT(viewImageTwo()));
	connect(pushButton_Scan,SIGNAL(pressed()),this,SLOT(ScanDrive()));
	connect(pushButton_changeDir,SIGNAL(pressed()),this,SLOT(changeDir()));
	connect(pushButton_lifetimeAcq,SIGNAL(pressed()),this,SLOT(AcqLifetimeData()));
	connect(pushButton_Stop,SIGNAL(pressed()),this,SLOT(StopScanDrive()));
	//connect(pushButton_Stop,SIGNAL(pressed()),this,SLOT(StopAcqCallback()));
	connect(pushButton_AomOn,SIGNAL(pressed()),this,SLOT(AomControlOn()));
	connect(doubleSpinBox_AomVoltAmp,SIGNAL(editingFinished()),this,SLOT(AomControlUpdate()));
	connect(checkBox_AomPulse,SIGNAL(clicked()),this,SLOT(AomControlUpdate()));
	connect(spinBox_OnTime,SIGNAL(editingFinished()),this,SLOT(AomControlUpdate()));
	connect(spinBox_RepRate,SIGNAL(editingFinished()),this,SLOT(AomControlUpdate()));
	connect(pushButton_AomOff,SIGNAL(pressed()),this,SLOT(AomControlOff()));
	connect(pushButton_coarseUp,SIGNAL(pressed()),this,SLOT(coarseUp()));
	connect(pushButton_coarseDown,SIGNAL(pressed()),this,SLOT(coarseDown()));
	connect(pushButton_coarseLeft,SIGNAL(pressed()),this,SLOT(coarseLeft()));
	connect(pushButton_coarseRight,SIGNAL(pressed()),this,SLOT(coarseRight()));
	connect(toolButton_fineUp,SIGNAL(pressed()),this,SLOT(fineUp()));
	connect(toolButton_fineDown,SIGNAL(pressed()),this,SLOT(fineDown()));
	connect(toolButton_fineLeft,SIGNAL(pressed()),this,SLOT(fineLeft()));
	connect(toolButton_fineRight,SIGNAL(pressed()),this,SLOT(fineRight()));
	connect(pushButton_zStepUp,SIGNAL(pressed()),this,SLOT(zStepUp()));
	connect(pushButton_zStepDown,SIGNAL(pressed()),this,SLOT(zStepDown()));
	connect(pushButton_zMoveTo,SIGNAL(pressed()),this,SLOT(zMoveTo()));
	connect(pushButton_zStepResetOrigin,SIGNAL(pressed()),this,SLOT(zSetOrigin()));
	connect(pushButton_parkBeam,SIGNAL(pressed()),this,SLOT(parkBeam()));
	connect(pushButton_saveImageLoc,SIGNAL(pressed()),this,SLOT(saveImageLoc()));
	connect(pushButton_savePtLoc,SIGNAL(pressed()),this,SLOT(savePointLoc()));
	connect(pushButton_goToLoc,SIGNAL(pressed()),this,SLOT(goToLoc()));
	connect(pushButton_zStepResetOrigin,SIGNAL(pressed()),this,SLOT(zSetOrigin()));
	connect(pushButton_stopAcq,SIGNAL(pressed()),this,SLOT(stopAcq()));
	connect(pushButton_connectXYCom,SIGNAL(pressed()),this,SLOT(connectXYCom()));
	connect(pushButton_connectZCom,SIGNAL(pressed()),this,SLOT(connectZCom()));
	connect(pushButton_RotateGalvos,SIGNAL(pressed()),this,SLOT(rotateGalvos()));
        connect(pushButton_UpdateLTAcqNum,SIGNAL(pressed()),this,SLOT(resetLTAcqNum()));

	
	 
	//Gui Updates
	//connect(comboBox_Magnification,SIGNAL(currentIndexChanged(int)),this,SLOT(updateScalingField()));
	connect(spinBox_numXPx,SIGNAL(editingFinished()),this,SLOT(updateLineRateField()));
	connect(spinBox_numYPx,SIGNAL(editingFinished()),this,SLOT(updateLineRateField()));
	connect(doubleSpinBox_SampleRate,SIGNAL(editingFinished()),this,SLOT(updateLineRateField()));
	connect(spinBox_numXPx,SIGNAL(editingFinished()),this,SLOT(UpdateMemoryNeeded()));
	connect(spinBox_numYPx,SIGNAL(editingFinished()),this,SLOT(UpdateMemoryNeeded()));
	connect(spinBox_numFrames,SIGNAL(editingFinished()),this,SLOT(UpdateMemoryNeeded()));
	connect(checkBox_Input1,SIGNAL(clicked()),this,SLOT(UpdateMemoryNeeded()));
	connect(checkBox_Input2,SIGNAL(clicked()),this,SLOT(UpdateMemoryNeeded()));
	connect(horizontalSlider_Ch1MinScale,SIGNAL(sliderReleased()),this,SLOT(updateIntensityScaling()));
	connect(horizontalSlider_Ch1MaxScale,SIGNAL(sliderReleased()),this,SLOT(updateIntensityScaling()));
	connect(horizontalSlider_Ch2MinScale,SIGNAL(sliderReleased()),this,SLOT(updateIntensityScaling()));
	connect(horizontalSlider_Ch2MaxScale,SIGNAL(sliderReleased()),this,SLOT(updateIntensityScaling()));
	connect(spinBox_Ch1MinScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScalingFields()));
	connect(spinBox_Ch1MaxScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScalingFields()));
	connect(spinBox_Ch2MinScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScalingFields()));
	connect(spinBox_Ch2MaxScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScalingFields()));
	connect(spinBox_Ch1MinScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScaling()));
	connect(spinBox_Ch1MaxScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScaling()));
	connect(spinBox_Ch2MinScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScaling()));
	connect(spinBox_Ch2MaxScale,SIGNAL(editingFinished()),this,SLOT(updateIntensityScaling()));
	connect(doubleSpinBox_zStartPos,SIGNAL(editingFinished()),this,SLOT(updateNumZSteps()));
	connect(doubleSpinBox_zStepSize,SIGNAL(editingFinished()),this,SLOT(updateNumZSteps()));
        connect(doubleSpinBox_zStopPos,SIGNAL(editingFinished()),this,SLOT(updateNumZSteps()));


	//Whenever Linescan gui widgets are changed, update scan speed
	connect(spinBox_Width,SIGNAL(editingFinished()),this,SLOT(UpdateLineScanSpeed()));
	connect(spinBox_Repeat,SIGNAL(editingFinished()),this,SLOT(UpdateLineScanSpeed()));
	connect(doubleSpinBox_SampleRate,SIGNAL(editingFinished()),this,SLOT(UpdateLineScanSpeed()));



	//Whenever DataFile gui widgets are changed, update class Instance
	connect(lineEdit_OutputDir,SIGNAL(editingFinished()),this,SLOT(updateDataFile()));
	connect(checkBox_3dAcq,SIGNAL(clicked()),this,SLOT(updateDataFile()));
	connect(spinBox_numXPx,SIGNAL(editingFinished()),this,SLOT(updateDataFile()));
	connect(spinBox_numYPx,SIGNAL(editingFinished()),this,SLOT(updateDataFile()));
	connect(spinBox_numFrames,SIGNAL(editingFinished()),this,SLOT(updateDataFile()));
	
	//Whenever AcqEngine gui widgets are changed, update class Instance
	connect(spinBox_Width,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(spinBox_Repeat,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_SampleRate,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(comboBox_AIRange,SIGNAL(currentIndexChanged(int)),this,SLOT(updateAcqEng()));
	connect(comboBox_InChan1,SIGNAL(currentIndexChanged(int)),this,SLOT(updateAcqEng()));
	connect(comboBox_InChan2,SIGNAL(currentIndexChanged(int)),this,SLOT(updateAcqEng()));
	connect(spinBox_numXPx,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(spinBox_numYPx,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(spinBox_numFrames,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_xPos,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_yPos,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(spinBox_xOffset,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(checkBox_Input1,SIGNAL(clicked()),this,SLOT(updateAcqEng()));
	connect(checkBox_Input2,SIGNAL(clicked()),this,SLOT(updateAcqEng()));
	connect(checkBox_Save,SIGNAL(clicked()),this,SLOT(updateAcqEng()));
	connect(checkBox_3dAcq,SIGNAL(clicked()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_zStartPos,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_zStepSize,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(doubleSpinBox_zStopPos,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));
	connect(checkBox_ContinAcq,SIGNAL(clicked()),this,SLOT(updateAcqEng()));
	//connect(spinBox_OverscanSize,SIGNAL(editingFinished()),this,SLOT(updateAcqEng()));

	//Whenever zStepper gui widgets are changed, update class instance
	connect(checkBox_holdTorque,SIGNAL(clicked()),this,SLOT(updateZStepEng()));
	connect(doubleSpinBox_moveToPos,SIGNAL(editingFinished()),this,SLOT(updateZStepEng()));

	//Whenever AomControl gui widgets are changed, update class Instance
	connect(spinBox_RepRate,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(doubleSpinBox_duration,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(spinBox_OnTime,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(doubleSpinBox_AomRefOutVoltage,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(doubleSpinBox_AomVoltAmp,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(comboBox_AomChan,SIGNAL(currentIndexChanged(int)),this,SLOT(updateAomControl()));
	connect(comboBox_AomRefOutChan,SIGNAL(currentIndexChanged(int)),this,SLOT(updateAomControl()));
	connect(checkBox_AomCont,SIGNAL(clicked()),this,SLOT(updateAomControl()));
	connect(checkBox_AomPulse,SIGNAL(clicked()),this,SLOT(updateAomControl()));
	connect(doubleSpinBox_TopVoltage,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(doubleSpinBox_BottomVoltage,SIGNAL(editingFinished()),this,SLOT(updateAomControl()));
	connect(checkBox_laserIntAdjust,SIGNAL(clicked()),this,SLOT(updateAomControl()));
	
	//Whenever ScanEngine gui widgets are changed, update class Instance
	connect(spinBox_Width,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(spinBox_Repeat,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(doubleSpinBox_SampleRate,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(comboBox_xChannel,SIGNAL(currentIndexChanged(int)),this,SLOT(updateScanEng()));
	connect(comboBox_yChannel,SIGNAL(currentIndexChanged(int)),this,SLOT(updateScanEng()));
	connect(spinBox_numXPx,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(spinBox_numYPx,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(spinBox_numFrames,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(doubleSpinBox_xMinVolts,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(doubleSpinBox_xMaxVolts,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(doubleSpinBox_yMinVolts,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(doubleSpinBox_yMaxVolts,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(comboBox_Magnification,SIGNAL(currentIndexChanged(int)),this,SLOT(updateScanEng()));
	//connect(spinBox_LineRate,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	//connect(spinBox_OverscanSize,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(spinBox_xPosBeamPark,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));
	connect(spinBox_yPosBeamPark,SIGNAL(editingFinished()),this,SLOT(updateScanEng()));


	//-----------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------

	

	//Init GUI fields
	updateLineRateField();
	UpdateLineScanSpeed();
	UpdateMemoryNeeded();

	//Init dangling pointers
	image1 = NULL;
	image2 = NULL;
	imageData1 = NULL;
	imageData2 = NULL;
	

	//resize columns for saved locations
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(0);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(1);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(2);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(3);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(4);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(5);

	TwoPhotonGui::comboBox_InChan2->setCurrentIndex(3);



}
//Destructor for TwoPhotonGui
//Turns off AOM
TwoPhotonGui::~TwoPhotonGui()
{

}
//Function: updateAomControl
//Type: Slot
//Description: Triggered when AOM class-related fields are edited
void TwoPhotonGui::updateAomControl()
{
	AomControl *aomClass = new AomControl();
	
	char temp[1024];
	QString tempString;
	int dummy;

	//Get Values from gui
	aomClass->setAomPulseRepRate(TwoPhotonGui::spinBox_RepRate->value());
	aomClass->setAomOnDuration(TwoPhotonGui::doubleSpinBox_duration->value());
	aomClass->setPulseOnTime(TwoPhotonGui::spinBox_OnTime->value());
	aomClass->setAOMRefOutVoltage(TwoPhotonGui::doubleSpinBox_AomRefOutVoltage->value());
	aomClass->setAomOnVoltage(TwoPhotonGui::doubleSpinBox_AomVoltAmp->value());
	
	tempString = TwoPhotonGui::comboBox_AomChan->currentText();
	strcpy(temp,tempString.toAscii().data());
	aomClass->setAomChan(temp);

	tempString = TwoPhotonGui::comboBox_AomRefOutChan->currentText();
	strcpy(temp,tempString.toAscii().data());
	aomClass->setAomRefOutChan(temp);

	aomClass->setAomVoltage(TwoPhotonGui::doubleSpinBox_AomVoltAmp->value());
	aomClass->setIntScalingTopV(TwoPhotonGui::doubleSpinBox_TopVoltage->value());
	aomClass->setIntScalingBottomV(TwoPhotonGui::doubleSpinBox_BottomVoltage->value());

	//GUI Booleans

	dummy = TwoPhotonGui::checkBox_AomCont->isChecked();
	if (dummy)
		aomClass->setAomContinuous(true);
	else
		aomClass->setAomContinuous(false);

	dummy = TwoPhotonGui::checkBox_AomPulse->isChecked();
	if (!dummy)
		aomClass->setAomPulsed(false);
	else
		aomClass->setAomPulsed(true);
	
	dummy = TwoPhotonGui::checkBox_laserIntAdjust->isChecked();
	if (!dummy)
		aomClass->setbIntScaling(false);
	else
		aomClass->setbIntScaling(true);

	//Emit signal to send data
	emit sendAomClassData(aomClass);
	emit sigAomControlUpdate(TwoPhotonGui::doubleSpinBox_AomVoltAmp->value());
}
//Function: updateAcqEng
//Type: Slot
//Description: Triggered when Acq class-related fields are edited
void TwoPhotonGui::updateAcqEng()
{
	AcqEngine *acqEng = new AcqEngine(5); //Note: the numlines flyback are irrelevant, this class
											//is created only to hold gui values
	char temp[1024];
	char second;	//this will hold the second character from AI Range strings (2,5,or 1)
	QString tempString;
	int dummy;

	//Get values from GUI
	acqEng->setDToARate(TwoPhotonGui::doubleSpinBox_SampleRate->value());
	
	tempString	= TwoPhotonGui::comboBox_AIRange->currentText();	
	strcpy(temp,tempString.toAscii().data());
	second = temp[1];
	switch(second)					//The second value (unique) from the string contained in the combobox is used to compare
	{				
		case '2':	//"-2V to 2V"
			acqEng->setAcqMax(2);
			acqEng->setAcqMin(-2);
			break;
		case '5':	//"-5V to 5V"
			acqEng->setAcqMax(5);
			acqEng->setAcqMin(-5);
			break;
		case '1':	//"-10V to 10V"
			acqEng->setAcqMax(10);
			acqEng->setAcqMin(-10);
			break;
	}

	tempString = TwoPhotonGui::comboBox_InChan1->currentText();		//chan1
	strcpy(temp,tempString.toAscii().data());
	acqEng->setAcqChan1(temp);								

	tempString = TwoPhotonGui::comboBox_InChan2->currentText();		//chan2
	strcpy(temp,tempString.toAscii().data());
	acqEng->setAcqChan2(temp);

	acqEng->setnumValidXSamps(TwoPhotonGui::spinBox_numXPx->value());
	acqEng->setnumValidYSamps(TwoPhotonGui::spinBox_numYPx->value());
	acqEng->setNumFrames(TwoPhotonGui::spinBox_numFrames->value());
	acqEng->setXPos(TwoPhotonGui::doubleSpinBox_xPos->value());
	acqEng->setYPos(TwoPhotonGui::doubleSpinBox_yPos->value());
	acqEng->setXOffset(TwoPhotonGui::spinBox_xOffset->value());

	//GUI booleans
	dummy = TwoPhotonGui::checkBox_ContinAcq->isChecked();
	if (dummy)
		acqEng->setContAcq(true);
	else
		acqEng->setContAcq(false);

	dummy = TwoPhotonGui::checkBox_Input1->isChecked();
	if (dummy)
		acqEng->setBInput1(true);
	else
		acqEng->setBInput1(false);

	dummy = TwoPhotonGui::checkBox_Input2->isChecked();
	if (dummy)
		acqEng->setBInput2(true);
	else
		acqEng->setBInput2(false);

	dummy = TwoPhotonGui::checkBox_Save->isChecked();
	if (dummy) 
		acqEng->setSaveData(true);
	else
		acqEng->setSaveData(false);

	//3d acquisition sets up more dependant variables
	dummy = TwoPhotonGui::checkBox_3dAcq->isChecked();
	if (dummy)
	{
		acqEng->setB3DAcq(true);

		acqEng->setZStartPos(TwoPhotonGui::doubleSpinBox_zStartPos->value());
		acqEng->setZStopPos(TwoPhotonGui::doubleSpinBox_zStopPos->value());
		acqEng->setZStepSize(TwoPhotonGui::doubleSpinBox_zStepSize->value());
		acqEng->setZPos(TwoPhotonGui::doubleSpinBox_zPos->value());
	}
	else
	{
		acqEng->setB3DAcq(false);

		acqEng->setZStartPos(TwoPhotonGui::doubleSpinBox_zPos->value());
		acqEng->setZStopPos(TwoPhotonGui::doubleSpinBox_zPos->value());
		acqEng->setZPos(TwoPhotonGui::doubleSpinBox_zPos->value());
		acqEng->setZStepSize(0.0);
	}

	//Linescan width & repeats
	acqEng->setWidth(TwoPhotonGui::spinBox_Width->value());
	acqEng->setRepeats(TwoPhotonGui::spinBox_Repeat->value());

	emit sendAcqClassData(*acqEng);

}


//Function: updateZStepEng
//Type: Slot
//Description: Triggered when z-step class-related fields are edited
void TwoPhotonGui::updateZStepEng()
{
	zStepperDriver *zStepClass = new zStepperDriver();
	int dummy;

	//check to see if holding torque is enabled
	dummy = TwoPhotonGui::checkBox_holdTorque->isChecked();
	if(dummy)
		zStepClass->setBTorqueOn(true);
	else
		zStepClass->setBTorqueOn(true);

	//update desired zPos
	zStepClass->setDesiredZPos(TwoPhotonGui::doubleSpinBox_moveToPos->value());

	emit sendZStepClassData(*zStepClass);
}
//Function: updateScanEng
//Type: Slot
//Description: Triggered when scan class-related fields are edited
void TwoPhotonGui::updateScanEng()
{
	ScanEngine *scanEng = new ScanEngine(5,5,5);	//Note: params are not significant, object is just a
												// container for gui values
	char		temp[1024];
	QString		tempString;		//needed to read from comboBoxes, then convert to std::string
	QByteArray	bArr;
	bool		bTrig;
	int			i;

	//Grab Gui Values
	scanEng->setSamp_Rate(TwoPhotonGui::doubleSpinBox_SampleRate->value());
	scanEng->setLineRate(TwoPhotonGui::spinBox_LineRate->value());		//lineRate in Hz
	scanEng->setLineLength(0);
	scanEng->setWidth(TwoPhotonGui::spinBox_Width->value());
	scanEng->setRepeats(TwoPhotonGui::spinBox_Repeat->value());

	tempString	= TwoPhotonGui::comboBox_xChannel->currentText();	//xChan
	strcpy(temp,tempString.toAscii().data());
	scanEng->setXChan(temp);								

	tempString	= TwoPhotonGui::comboBox_yChannel->currentText();	//yChan
	strcpy(temp,tempString.toAscii().data());		
	scanEng->setYChan(temp);

	//tempString	= TwoPhotonGui::comboBox_trigChannel->currentText();	//trigChan
	strcpy(temp,tempString.toAscii().data());		
	scanEng->setTrigChan(temp);

	bTrig = TwoPhotonGui::checkBox_TrigAcq->isChecked();
	scanEng->setTriggered(bTrig);

	scanEng->setnumValidXSamps(TwoPhotonGui::spinBox_numXPx->value());
	scanEng->setnumValidYSamps(TwoPhotonGui::spinBox_numYPx->value());
	scanEng->setNumFrames(TwoPhotonGui::spinBox_numFrames->value());
	scanEng->setXMinVolts(TwoPhotonGui::doubleSpinBox_xMinVolts->value());
	scanEng->setXMaxVolts(TwoPhotonGui::doubleSpinBox_xMaxVolts->value());
	scanEng->setYMinVolts(TwoPhotonGui::doubleSpinBox_yMinVolts->value());
	scanEng->setYMaxVolts(TwoPhotonGui::doubleSpinBox_yMaxVolts->value());

	//Update scaling and magnification - values provided in config file
	tempString	= TwoPhotonGui::comboBox_Magnification->currentText();	
	//pad string with spaces until it is 64 elements long
	for(i=tempString.size();i<64;i++)
		tempString.append(' ');

	bArr = tempString.toAscii();
	scanEng->setMag(bArr.data());		

	//Make sure scaling is same index as mag
	QVariant QV = TwoPhotonGui::comboBox_Magnification->itemData(TwoPhotonGui::comboBox_Magnification->currentIndex(),1);
	TwoPhotonGui::spinBox_Scaling->setValue(QV.toInt());
	scanEng->setScaling(QV.toInt());

	scanEng->setPark_X(TwoPhotonGui::spinBox_xPosBeamPark->value());
	scanEng->setPark_Y(TwoPhotonGui::spinBox_yPosBeamPark->value());

	emit sendScanClassData(scanEng);
}
//Function: updateDataFile
//Type: Slot
//Description: Triggered when scan class-related fields are edited
void TwoPhotonGui::updateDataFile()
{
	DataFile2P *dataClass = new DataFile2P(5,5,5,5);	//params are insignificant, this object is used to only hold gui values

	char temp[1024];
	QString tempString;
	
	//Update output directory
	tempString = TwoPhotonGui::lineEdit_OutputDir->text();
	strcpy(temp,tempString.toAscii().data());
	
	dataClass->setOutputDir(temp);

	//Update Header data used for saving
	dataClass->Header.setB3DAcq(TwoPhotonGui::checkBox_3dAcq->isChecked());

	emit sendDataClassData(*dataClass);
}
//Function: updateScalingField
//Type: Slot
//Description: Loads GUI with updated scaling and resolution values
void TwoPhotonGui::updateScalingField(int xFov,int yFov,double xRes, double yRes)
{
	TwoPhotonGui::spinBox_xFov->setValue(xFov);
	TwoPhotonGui::spinBox_yFov->setValue(yFov);

	TwoPhotonGui::doubleSpinBox_xRes->setValue(xRes);	//um/px
	TwoPhotonGui::doubleSpinBox_yRes->setValue(yRes);	//um/px
}
//Function: setAomIntScalingVals
//Type: Slot
//Description: Sets the top and bottom aom intensity scaling fields. This is used if fields are
//	out of bounds and need to be restored to default from within TwoPhotonControl.
void TwoPhotonGui::setAomIntScalingVals(double bottom, double top)
{
	TwoPhotonGui::doubleSpinBox_BottomVoltage->setValue(bottom);
	TwoPhotonGui::doubleSpinBox_TopVoltage->setValue(top);
}
//Function: connectZCom
//Type: Slot
//Description: Reopen serial communication with z-stepper motor
void TwoPhotonGui::connectZCom()
{
	int port = TwoPhotonGui::spinBox_ComPortZStep->value();
	emit sigConnectZCom(port);
}
//Function: connectXYCom
//Description: Reopen serial communication with xy-stepper motor
void TwoPhotonGui::connectXYCom()
{
	int port = TwoPhotonGui::spinBox_ComPortXYStep->value();
	emit sigConnectXYCom(port);
}
//Function: ChangeDir
//Description: Opens a dialog box for user to set new save directory
void TwoPhotonGui::changeDir()
{
	QString directory = QFileDialog::getExistingDirectory(this,tr("Choose Save Directory"),tr("C:/Data/"));
	directory.replace("/","\\");
	 //If directory is not empty
	 if (!directory.isEmpty())
	 {
		 directory.append('\\');
		 //update gui
		 TwoPhotonGui::lineEdit_OutputDir->setText(directory);
		 //update save file var
		 updateDataFile();
     }
	 else
	 {
		QMessageBox::about(this,"Error","Not a valid directory\nPlease choose another directory");
	 }

}
//Function: updateNumZStepsField
//Type: Slot
//Description: Updates the number of zSteps field
void TwoPhotonGui::updateNumZStepsField(int numZSteps)
{
	TwoPhotonGui::spinBox_numSteps->setValue(numZSteps);
}
//Function: setXYOrigin
//Description: Resets the XY stepping coordinates to current position as origin, updates all saved locations
void TwoPhotonGui::setXYOrigin()
{
	QTreeWidget* tree = TwoPhotonGui::treeWidget_savedLocs;
	double x = TwoPhotonGui::doubleSpinBox_xPos->value();
	double y = TwoPhotonGui::doubleSpinBox_yPos->value();
	emit sigSetXYOrigin(x,y,tree);
}
//Function: setFineStepField
//Type: Slot
//Description: Sets the fine step field size
//Input: Step size in um
void TwoPhotonGui::setFineStepField(double size)
{
	TwoPhotonGui::doubleSpinBox_fineField->setValue(size);
}
//Function: setCoarseStepField
//Type: Slot
//Description: Sets the coarse step field size
//Input: Step size in um
void TwoPhotonGui::setCoarseStepField(double size)
{
	TwoPhotonGui::doubleSpinBox_coarseField->setValue(size);
}
//Function: setZMoveToField
//Type: Slot
//Description: Sets the z move to field
//Input: z coordinate to set as the move to field
void TwoPhotonGui::setZMoveToField(double z)
{
	TwoPhotonGui::doubleSpinBox_moveToPos->setValue(z);
}
//Function: setZPos
//Type: Slot
//Description: Sets the z pos field
//Input: z coordinate to set as the current position
void TwoPhotonGui::setZPos(double z)
{
	TwoPhotonGui::doubleSpinBox_zPos->setValue(z);
}
//Function: setXPos
//Type: Slot
//Description: Sets the x pos field
//Input: x coordinate to set as the current position
void TwoPhotonGui::setXPos(double x)
{
	TwoPhotonGui::doubleSpinBox_xPos->setValue(x);
}
//Function: setYPos
//Type: Slot
//Description: Sets the y pos field
//Input: y coordinate to set as the current position
void TwoPhotonGui::setYPos(double y)
{
	TwoPhotonGui::doubleSpinBox_yPos->setValue(y);
}
//Function: aboutTwoPhoton
//Description: Opens dialogue pop-up with software information
void TwoPhotonGui::aboutTwoPhoton()
{
	QMessageBox::about(this,"About TwoPhoton",
                "Two Photon Data Acquisition Software\n"
				"Version 2.0, 9/22/2008\n\n"
                "Alex Greis, Arnold Estrada\n"
				"Functional Optical Imaging Laboratory\n"
				"Biomedical Engineering, University of Texas\n");
}
//Function: defaultHwConnections
//Description: Opens dialogue pop-up with default hardware information
void TwoPhotonGui::defaultHwConnections()
{
	
/*
	NI DAQ Board Configurations (Default)

	X-galvo scan:		/dev1/ao0
	Y-galvo scan:		/dev1/ao1
	CH1 PMT:			/dev1/ai0
	CH2 PMT:			/dev1/ai1
	AOM Ctrl:			/dev1/ao2
	AOM Ref Out:		/dev1/ao3
	TCSPC Trigger:		some pfi line


*/
	QMessageBox::about(this,"Default Hardware Connections",
				"RS232 Ports:\n"
				"COM 1: Z-Stepper Motor Controller\n"
				"COM 2: X/Y VXM Stepper Motor Controller\n\n"
                "NI-DAQ Dev1\n"
				"/dev1/ao0: X-galvanometer\n"
				"/dev1/ao1: Y-galvanometer\n"
				"/dev1/ao2: AOM Control\n"
				"/dev1/ao3: AOM Reference Out\n"
				"/dev1/ai0: Channel 1 PMT\n"
				"/dev1/ai1: Channel 2 PMT\n\n"
				"NI-DAQ Dev3\n"
				"???: TCSPC Trigger\n"
				"\n");
}
//Function: LineScanAcq
//Description: Called whenever "Linescan Acquire" is pressed. Calls functions in order to acquire 2P data and linescan
void TwoPhotonGui::LineScanAcq()
{
	emit sigLineScanAcq();
}
//Function: Acquire
//Description: Called whenever "Acquire" is pressed. Calls functions in order to acquire 2P data and scan
void TwoPhotonGui::Acquire()
{
	emit sigAcquire();
}
//Function: RotateGalvos
//Description: Called whenever "Rotate" is pressed. Calls functions in order to rotate galvos
void TwoPhotonGui::rotateGalvos()
{
	emit sigRotateGalvos();
}
//Function: resetLTAcqNum
//Description: Called whenever "Reset LT Acq #" is pressed. Calls function to update lifetime acq number.  This
//  number is used to synchronize the 2P software with B&H acquisition.
void TwoPhotonGui::resetLTAcqNum()
{
    int response;
    bool ok = false;

    response = QInputDialog::getInteger(0,tr("Enter Lifetime Acq #"),tr("Lifetime Acq #"), 1, 1, 999, 1, &ok);

    if (ok)
        spinBox_LifetimeAcqNum->setValue(response);

    emit sigResetLTAcqNum(spinBox_LifetimeAcqNum->value());
}
//Fucntion: StopAcq
//Description: Stops acquisition in progress
void TwoPhotonGui::stopAcq()
{
	emit sigStopAcq();
}

//Function: ScanDrive
//Description: Called whenever "Scan" is pressed.No acquisition, only scanning. Starts scan, user must press stop to stop scan.
void TwoPhotonGui::ScanDrive()
{
	emit sigScanDrive();
}
//Function: StopScanDrive
//Description: Called whenever "Stop" is pressed.Stops Scanning initiated by ScanDrive
void TwoPhotonGui::StopScanDrive()
{
	emit sigStopScanDrive();
}
//Function: setScanButton
//Type: Slot
//Description: Enables/Disables Scan button
//Input: Boolean, to turn button on or off
void TwoPhotonGui::setScanButton(bool on)
{
	TwoPhotonGui::pushButton_Scan->setEnabled(on);
}
//Function: setStopButton
//Type: Slot
//Description: Enables/Disables Stop button
//Input: Boolean, to turn button on or off
void TwoPhotonGui::setStopButton(bool on)
{
	TwoPhotonGui::pushButton_Stop->setEnabled(on);
}
//Function: setAomOnButton
//Type: Slot
//Description: Enables/Disables AOM on button
//Input: Boolean, to turn button on or off
void TwoPhotonGui::setAomOnButton(bool on)
{
	TwoPhotonGui::pushButton_AomOn->setEnabled(on);
}
//Function: setAomOffButton
//Type: Slot
//Description: Enables/Disables AOM off button
//Input: Boolean, to turn button on or off
void TwoPhotonGui::setAomOffButton(bool on)
{
	TwoPhotonGui::pushButton_AomOff->setEnabled(on);
}
//Function: setStopAcqButton
//Type: Slot
//Description: Enables/Disables Stop Acq button
//Input: Boolean, to turn button on or off
void TwoPhotonGui::setStopAcqButton(bool on)
{
	TwoPhotonGui::pushButton_stopAcq->setEnabled(on);
}
//Function: setChkAomPulsed
//Type: Slot
//Description: checks/unchecks pulsed AOM checkbox
//Input: Boolean, to check/uncheck
void TwoPhotonGui::setChkAomPulsed(bool checked)
{
	TwoPhotonGui::checkBox_AomPulse->setChecked(checked);
}
//Function: setChkAomCont
//Type: Slot
//Description: checks/unchecks continuous AOM checkbox
//Input: Boolean, to check/uncheck
void TwoPhotonGui::setChkAomCont(bool checked)
{
	TwoPhotonGui::checkBox_AomCont->setChecked(checked);
}
//Function: setChkSave
//Type: Slot
//Description: checks/unchecks save checkbox
//Input: Boolean, to check/uncheck
void TwoPhotonGui::setChkSave(bool checked)
{
	TwoPhotonGui::checkBox_Save->setChecked(checked);
}
//Function: updateIntensityScaling
//Description: Changes image intensity scaling if a horizontal slider is moved -eventually replace with histogram
void TwoPhotonGui::updateIntensityScaling()
{
	short ch1Min,ch1Max,ch2Min,ch2Max;

	ch1Min = TwoPhotonGui::horizontalSlider_Ch1MinScale->value();
	ch1Max = TwoPhotonGui::horizontalSlider_Ch1MaxScale->value();
	ch2Min = TwoPhotonGui::horizontalSlider_Ch2MinScale->value();
	ch2Max = TwoPhotonGui::horizontalSlider_Ch2MaxScale->value();

	emit sigUpdateIntensityScaling(ch1Min,ch1Max,ch2Min,ch2Max);
}

//Function: updateIntensityScalingFields
//Description: Changes image intensity scaling if a scaling field is changed
void TwoPhotonGui::updateIntensityScalingFields()
{
	short ch1Min,ch1Max,ch2Min,ch2Max;
	
	ch1Min = TwoPhotonGui::spinBox_Ch1MinScale->value();
	ch1Max = TwoPhotonGui::spinBox_Ch1MaxScale->value();
	ch2Min = TwoPhotonGui::spinBox_Ch2MinScale->value();
	ch2Max = TwoPhotonGui::spinBox_Ch2MaxScale->value();

	emit sigUpdateIntensityScaling(ch1Min,ch1Max,ch2Min,ch2Max);

}
//Function: updateScalingInt
//Type: Slot
//Description: Updates GUI fields for intensity scaling on each channel
void TwoPhotonGui::updateScalingInt(short ch1Min,short ch1Max,short ch2Min,short ch2Max)
{
	TwoPhotonGui::spinBox_Ch1MinScale->setValue(ch1Min);
	TwoPhotonGui::spinBox_Ch1MaxScale->setValue(ch1Max);
	TwoPhotonGui::horizontalSlider_Ch1MinScale->setValue(ch1Min);
	TwoPhotonGui::horizontalSlider_Ch1MaxScale->setValue(ch1Max);
	TwoPhotonGui::spinBox_Ch2MinScale->setValue(ch2Min);
	TwoPhotonGui::spinBox_Ch2MaxScale->setValue(ch2Max);
	TwoPhotonGui::horizontalSlider_Ch2MinScale->setValue(ch2Min);
	TwoPhotonGui::horizontalSlider_Ch2MaxScale->setValue(ch2Max);
}
//Function: updateNumZSteps
//Description: Updates the number of z steps field if z step params are changed
//Returns: none
void TwoPhotonGui::updateNumZSteps()
{
	emit sigUpdateNumZSteps(TwoPhotonGui::doubleSpinBox_zStopPos->value(), TwoPhotonGui::doubleSpinBox_zStartPos->value(), TwoPhotonGui::doubleSpinBox_zStepSize->value());
}
//Function: UpdateLineRateField
//Description: Updates the linerate field and frametime if the acquisition parameters are changed
//Returns: linerate (hz)
void TwoPhotonGui::updateLineRateField()
{
	emit sigUpdateLineRateField();
}
//Function: updateGuiLineRateField
//Type: Slot
//Description: Updates the linerate field and frametime
//Input: lineRate (Hz), frameTime (s)
void TwoPhotonGui::updateGuiLineRateField(double lineRate, double frameTime)
{
	TwoPhotonGui::spinBox_LineRate->setValue(lineRate);
	TwoPhotonGui::doubleSpinBox_frametime->setValue(frameTime);
}
//Function: AcqLifetimeData
//Description: Acquires lifetime data defined on previous image by NI open contour tools
void TwoPhotonGui::AcqLifetimeData()
{
	emit sigAcqLifetimeData();
}
//Function: AomControlOn
//Description: If user enables Aom Control
void TwoPhotonGui::AomControlOn()
{	
	double voltage = TwoPhotonGui::doubleSpinBox_AomVoltAmp->value();
	emit sigAomControlOn(voltage);
}
//Function: AomControlUpdate
//Description: If user changed AOM voltage amp value, and aom control is on, change output value
void TwoPhotonGui::AomControlUpdate()
{
	double voltage = TwoPhotonGui::doubleSpinBox_AomVoltAmp->value();
	emit sigAomControlUpdate(voltage);
}
//Function: AomControlOff
//Description: If user turns Aom control off (sets it to zero voltage)
void TwoPhotonGui::AomControlOff()
{
	emit sigAomControlOff();
}
//Function: updateAomTimer
//Description: Slot that is triggered when AomTimer is expired
void TwoPhotonGui::updateAomTimer()
{
	emit sigUpdateAomTimer();
}
//Function: UpdateLineScanSpeed
//Description: Updates the linescan rate field based on the scan parameters
void TwoPhotonGui::UpdateLineScanSpeed()
{
	emit sigUpdateLineScanSpeed();
}
//Function: toggleAomWidgets
//Description: Sets gui widgets according to if Aom is on or off
//Input: Current state of aom
void TwoPhotonGui::toggleAomWidgets(bool aomOn)
{
	//If aom is on
	if(aomOn)
	{
		TwoPhotonGui::pushButton_AomOn->setEnabled(false);
		TwoPhotonGui::pushButton_AomOff->setEnabled(true);
	}
	else
	{
		TwoPhotonGui::pushButton_AomOn->setEnabled(true);
		TwoPhotonGui::pushButton_AomOff->setEnabled(false);
	}
}
//Function: UpdateGuiLineScanSpeed
//Type: Slot
//Description: Updates the linescan rate field based on the scan parameters
//Input: Linespeed in Hz
void TwoPhotonGui::UpdateGuiLineScanSpeed(double lineSpeed)
{
	TwoPhotonGui::spinBox_linescanRate->setValue(lineSpeed);
}
//Function: UpdateMemoryNeeded
//Description: Updates the field indicating the amount of disk space needed for save file
void TwoPhotonGui::UpdateMemoryNeeded()
{
	emit sigUpdateMemoryNeeded();
}
//Function: UpdateGuiMemoryNeeded
//Type: Slot
//Description: Updates the field indicating the amount of disk space needed for save file
//Input: Memory needed, in MB
void TwoPhotonGui::UpdateGuiMemoryNeeded(double memNeeded)
{
	TwoPhotonGui::doubleSpinBox_diskSpace->setValue(memNeeded);
}
//Function: parkBeam
//Description: Initiates beam parking scan routine
//Returns: nothing
void TwoPhotonGui::parkBeam()
{
	emit sigParkBeam();
}
//Function: ContAcqCallback
//Description: Starts a continuous acquisition, enables stop button
void TwoPhotonGui::ContAcqCallback()
{ 
	emit sigContAcqCallback();	
}
//Function: StopContAcqCallback
//Description: Stops a continuous acquisition, enables start button
void TwoPhotonGui::StopContAcqCallback()
{	
	emit sigStopContAcqCallback();
}
//Function: saveImageLoc
//Description: Slot, saves current x,y,z coordinates into image location table
void TwoPhotonGui::saveImageLoc()
{
	double 	x = TwoPhotonGui::doubleSpinBox_xPos->value();
	double 	y = TwoPhotonGui::doubleSpinBox_yPos->value();
	double 	z = TwoPhotonGui::doubleSpinBox_zPos->value();

	emit sigSaveImageLoc(x,y,z);
}
//Function: savePointLoc
//Description: Slot, saves current x,y,z coordinates and <x,y> pixel into image location table
void TwoPhotonGui::savePointLoc()
{
	double 	x = TwoPhotonGui::doubleSpinBox_xPos->value();
	double 	y = TwoPhotonGui::doubleSpinBox_yPos->value();
	double 	z = TwoPhotonGui::doubleSpinBox_zPos->value();

	emit sigSavePointLoc(x,y,z);
}
//Function: addSavedLoc
//Type: Slot
//Description: Adds a new entry to the saved locations chart
//Input: entry containing details (x-step,y-step,z-step,x,y) of the ROI to be added
//		 int to determine which type of ROI
//			0 = point (pixel and stepper coordinates)
//			1 = fov   (stepper coordinates only)
void TwoPhotonGui::addSavedLoc(QTreeWidgetItem* entry, int type)
{	
	TwoPhotonGui::treeWidget_savedLocs->addTopLevelItem(entry);

	//resize columns
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(0);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(1);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(2);
	TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(3);
	if(type == 0)
	{
		TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(4);
		TwoPhotonGui::treeWidget_savedLocs->resizeColumnToContents(5);
	}

}
//Function: goToLoc
//Description: Slot, goes to selected coordinates
void TwoPhotonGui::goToLoc()
{
	QTreeWidgetItem *entry;
	double coarse,zMoveTo;

	//Get currently selected location
	entry = TwoPhotonGui::treeWidget_savedLocs->currentItem();
	coarse = TwoPhotonGui::doubleSpinBox_coarseField->value();
	zMoveTo = TwoPhotonGui::doubleSpinBox_moveToPos->value();

	emit sigGoToLoc(*entry,coarse,zMoveTo);
}
//Function: receivePercentComplete
//Type: Slot
//Description: Updates acq progress bar with percentage
void TwoPhotonGui::receivePercentComplete(double percent)
{
	TwoPhotonGui::progressBar_acq->setValue(percent*100);
}
//Function: updateScanProgressBar
//Type: Slot
//Description: Updates scan progress bar
//Input: percent to update with
void TwoPhotonGui::updateScanProgressBar(double percent)
{
	TwoPhotonGui::progressBar_scan->setValue(percent*100);
}
//Function: updateLifeTimeAcqNumber
//Type: Slot
//Description: Updates Lifetime Acq Number text box
//Input: percent to update with
void TwoPhotonGui::updateLifeTimeAcqNumber(int number)
{
	TwoPhotonGui::spinBox_LifetimeAcqNum->setValue(number);
}
//Function: lockControlWidgets
//Type: Slot
//Description: deactivates all GUI elements that cannot be used during a standard, linescan, cont scan, or lifetime acquisition
void TwoPhotonGui::lockControlWidgets()
{
	TwoPhotonGui::checkBox_Input1->setEnabled(false);
	TwoPhotonGui::checkBox_Input2->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_zStartPos->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_zStepSize->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_zStopPos->setEnabled(false);
	TwoPhotonGui::checkBox_3dAcq->setEnabled(false);
	TwoPhotonGui::checkBox_laserIntAdjust->setEnabled(false);
	TwoPhotonGui::pushButton_changeDir->setEnabled(false);
	TwoPhotonGui::pushButton_Scan->setEnabled(false);
	TwoPhotonGui::pushButton_Acquire->setEnabled(false);
	TwoPhotonGui::pushButton_lifetimeAcq->setEnabled(false);
	//TwoPhotonGui::pushButton_contAcq->setEnabled(false);
	TwoPhotonGui::pushButton_linescanAcq->setEnabled(false);
	TwoPhotonGui::checkBox_AomPulse->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_AomVoltAmp->setEnabled(false);
	TwoPhotonGui::pushButton_AomOn->setEnabled(false);
	TwoPhotonGui::pushButton_AomOff->setEnabled(false);
	TwoPhotonGui::checkBox_AomCont->setEnabled(false);
	TwoPhotonGui::comboBox_AomChan->setEnabled(false);
	TwoPhotonGui::spinBox_RepRate->setEnabled(false);
	TwoPhotonGui::spinBox_OnTime->setEnabled(false);
	TwoPhotonGui::comboBox_AomRefOutChan->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_AomRefOutVoltage->setEnabled(false);
	TwoPhotonGui::doubleSpinBox_duration->setEnabled(false);
	//TwoPhotonGui::pushButton_ResetOrigin->setEnabled(false);
	//TwoPhotonGui::pushButton_zStepResetOrigin->setEnabled(false);
	////TwoPhotonGui::pushButton_zStepUp->setEnabled(false);
	//TwoPhotonGui::pushButton_zStepDown->setEnabled(false);
	//TwoPhotonGui::pushButton_zMoveTo->setEnabled(false);
	TwoPhotonGui::pushButton_parkBeam->setEnabled(false);
	TwoPhotonGui::pushButton_stopAcq->setEnabled(true);
	
}
//Function: UnlockContScanControlWidgets
//Type: Slot
//Description: Reactivates some of the GUI elements allowed during continuous scan
void TwoPhotonGui::UnlockContScanControlWidgets()
{
	TwoPhotonGui::pushButton_stopAcq->setEnabled(false);
	TwoPhotonGui::checkBox_AomPulse->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_AomVoltAmp->setEnabled(true);
	TwoPhotonGui::pushButton_AomOn->setEnabled(true);
	TwoPhotonGui::pushButton_AomOff->setEnabled(true);
	TwoPhotonGui::checkBox_AomCont->setEnabled(true);
	TwoPhotonGui::comboBox_AomChan->setEnabled(true);
	TwoPhotonGui::spinBox_RepRate->setEnabled(true);
	TwoPhotonGui::spinBox_OnTime->setEnabled(true);
	TwoPhotonGui::comboBox_AomRefOutChan->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_AomRefOutVoltage->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_duration->setEnabled(true);
	//TwoPhotonGui::pushButton_ResetOrigin->setEnabled(true);
	//TwoPhotonGui::pushButton_zStepResetOrigin->setEnabled(true);
	//TwoPhotonGui::pushButton_zStepUp->setEnabled(true);
	//TwoPhotonGui::pushButton_zStepDown->setEnabled(true);
	//TwoPhotonGui::pushButton_zMoveTo->setEnabled(true);

	//Set Scan/Stop buttons
	//TwoPhotonGui::pushButton_contAcq->setEnabled(false);
	//TwoPhotonGui::pushButton_stopContAcq->setEnabled(true);
}
//Function: finishContAcq
//Type: Slot
//Description: Adjusts GUI widgets after continuous acquisition is stopped
void TwoPhotonGui::finishContAcq()
{
	//TwoPhotonGui::pushButton_contAcq->setEnabled(true);
	//TwoPhotonGui::pushButton_stopContAcq->setEnabled(false);

	//unlock control widgets that would interfere with acquisition
	//unlockControlWidgets();
}
//Function: unlockControlWidgets
//Type: Slot
//Description: reactivates all GUI elements that were disabled during a standard, linescan, cont scan, or lifetime acquisition
void TwoPhotonGui::unlockControlWidgets()
{
	TwoPhotonGui::checkBox_Input1->setEnabled(true);
	TwoPhotonGui::checkBox_Input2->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_zStartPos->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_zStepSize->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_zStopPos->setEnabled(true);
	TwoPhotonGui::checkBox_3dAcq->setEnabled(true);
	TwoPhotonGui::checkBox_laserIntAdjust->setEnabled(true);
	TwoPhotonGui::pushButton_changeDir->setEnabled(true);
	TwoPhotonGui::pushButton_Scan->setEnabled(true);
	TwoPhotonGui::pushButton_Acquire->setEnabled(true);
	TwoPhotonGui::pushButton_lifetimeAcq->setEnabled(true);
	//TwoPhotonGui::pushButton_contAcq->setEnabled(true);
	TwoPhotonGui::pushButton_linescanAcq->setEnabled(true);
	TwoPhotonGui::checkBox_AomPulse->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_AomVoltAmp->setEnabled(true);
	TwoPhotonGui::pushButton_AomOn->setEnabled(true);
	TwoPhotonGui::pushButton_AomOff->setEnabled(true);
	TwoPhotonGui::checkBox_AomCont->setEnabled(true);
	TwoPhotonGui::comboBox_AomChan->setEnabled(true);
	TwoPhotonGui::spinBox_RepRate->setEnabled(true);
	TwoPhotonGui::spinBox_OnTime->setEnabled(true);
	TwoPhotonGui::comboBox_AomRefOutChan->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_AomRefOutVoltage->setEnabled(true);
	TwoPhotonGui::doubleSpinBox_duration->setEnabled(true);
	TwoPhotonGui::pushButton_ResetOrigin->setEnabled(true);
	TwoPhotonGui::pushButton_zStepResetOrigin->setEnabled(true);
	TwoPhotonGui::pushButton_zStepUp->setEnabled(true);
	TwoPhotonGui::pushButton_zStepDown->setEnabled(true);
	TwoPhotonGui::pushButton_zMoveTo->setEnabled(true);
	TwoPhotonGui::pushButton_parkBeam->setEnabled(true);
	TwoPhotonGui::pushButton_stopAcq->setEnabled(false);
}
//Function: viewVisionTools
//Description: slot to hide or show vision tools
void TwoPhotonGui::viewVisionTools()
{	
	emit sigViewVisionTools();
}
//Function: viewImageOne
//Description: slot to hide or show image one
void TwoPhotonGui::viewImageOne()
{
	emit sigViewImageOne();
}
//Function: viewImageTwo
//Description: slot to hide or show image two
void TwoPhotonGui::viewImageTwo()
{
	emit sigViewImageTwo();
}

//Function: coarseUp
//Description: move XY stage coarse increment in +Y direction
void TwoPhotonGui::coarseUp()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_coarseField->value(); 
	double yPos = TwoPhotonGui::doubleSpinBox_yPos->value();
	emit sigCoarseUp(stepSize,yPos);
}
//Function: coarseDown
//Description: move XY stage coarse increment in -Y direction
void TwoPhotonGui::coarseDown()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_coarseField->value(); 
	double yPos = TwoPhotonGui::doubleSpinBox_yPos->value();
	emit sigCoarseDown(stepSize,yPos);
}
//Function: coarseLeft
//Description: move XY stage coarse increment in -X direction
void TwoPhotonGui::coarseLeft()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_coarseField->value(); 
	double xPos = TwoPhotonGui::doubleSpinBox_xPos->value();
	emit sigCoarseLeft(stepSize,xPos);
}
//Function: coarseRight
//Description: move XY stage coarse increment in +X direction
void TwoPhotonGui::coarseRight()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_coarseField->value(); 
	double xPos = TwoPhotonGui::doubleSpinBox_xPos->value();
	emit sigCoarseRight(stepSize,xPos);
}
//Function: fineUp
//Description: move XY stage coarse increment in +Y direction
void TwoPhotonGui::fineUp()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_fineField->value(); 
	double yPos = TwoPhotonGui::doubleSpinBox_yPos->value();
	emit sigFineUp(stepSize,yPos);
}
//Function: fineDown
//Description: move XY stage coarse increment in -Y direction
void TwoPhotonGui::fineDown()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_fineField->value(); 
	double yPos = TwoPhotonGui::doubleSpinBox_yPos->value();
	emit sigFineDown(stepSize,yPos);
}
//Function: fineLeft
//Description: move XY stage coarse increment in -X direction
void TwoPhotonGui::fineLeft()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_fineField->value(); 
	double xPos = TwoPhotonGui::doubleSpinBox_xPos->value();
	emit sigFineLeft(stepSize,xPos);
}
//Function: fineRight
//Description: move XY stage coarse increment in +X direction
void TwoPhotonGui::fineRight()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_fineField->value(); 
	double xPos = TwoPhotonGui::doubleSpinBox_xPos->value();
	emit sigFineRight(stepSize,xPos);
}
//Function: zStepUp
//Description: move stage in positive z direction
void TwoPhotonGui::zStepUp()
{
	double stepSize = TwoPhotonGui::doubleSpinBox_zManualStepSize->value();
	emit sigZStepUp(stepSize);
}
//Function: zStepDown
//Description:  move stage in negative z direction
void TwoPhotonGui::zStepDown()
{	
	double stepSize = TwoPhotonGui::doubleSpinBox_zManualStepSize->value();
	emit sigZStepDown(stepSize);
}
//Function: zMoveTo
//Description:  move stage in z direction to specified position (indicated by field on gui)
void TwoPhotonGui::zMoveTo()
{
	double moveToPos = TwoPhotonGui::doubleSpinBox_moveToPos->value();
	emit sigZMoveTo(moveToPos);
}
//Function: zSetOrigin
//Description: reset z stepper coordinates
void TwoPhotonGui::zSetOrigin()
{
	double z = TwoPhotonGui::doubleSpinBox_zPos->value();
	QTreeWidget *tree = TwoPhotonGui::treeWidget_savedLocs;

	emit sigZSetOrigin(z,tree);	
}
//Function: setLocTree
//Type: Slot
//Description: copy tree into locations list over old one
//Input: QTreeWidget containing all entries of saved locations
void TwoPhotonGui::setLocTree(QTreeWidget* tree)
{
	QTreeWidgetItem *entry;
	int i,numItems;


	numItems = TwoPhotonGui::treeWidget_savedLocs->topLevelItemCount();
	
	//Only works without loop

	//copy all values of tree into new list
	//for(i=0;i<numItems;i++)
	//{
		TwoPhotonGui::treeWidget_savedLocs->takeTopLevelItem(i);
		entry = tree->takeTopLevelItem(0);
		TwoPhotonGui::treeWidget_savedLocs->addTopLevelItem(entry);
		//tree->insertTopLevelItem(i,entry);	//re-enter so that index is unchanged
	//}

}
//Function: popupMessage
//Type: Slot
//Input: Popup Title and Message
//Description: Creates a notification popup
void TwoPhotonGui::popupMessage(QString title,QString message)
{
	QMessageBox::about(this,title,message);
}
//Function: addMagEntry
//Type: Slot
//Description: Adds an entry into the objective field
//Input: index, objective name, data value associated with objective
void TwoPhotonGui::addMagEntry(int numObj,char* string, int data)
{
	TwoPhotonGui::comboBox_Magnification->insertItem(numObj,string,data);
	TwoPhotonGui::comboBox_Magnification->setItemData(numObj,data,1);
}
//Function: setXYCom
//Type: Slot
//Description: sets the xy com port field
//Input: com port value
void TwoPhotonGui::setXYCom(int port)
{
	TwoPhotonGui::spinBox_ComPortXYStep->setValue(port);
}
//Function: setZCom
//Type: Slot
//Description: sets the z com port field
//Input: com port value
void TwoPhotonGui::setZCom(int port)
{
	TwoPhotonGui::spinBox_ComPortZStep->setValue(port);
}
//Function: updateScaling
//Type: Slot
//Description: updates scaling field to most recent obj if updated
void TwoPhotonGui::updateScaling()
{
	QVariant QV = TwoPhotonGui::comboBox_Magnification->itemData(TwoPhotonGui::comboBox_Magnification->currentIndex(),1);
	TwoPhotonGui::spinBox_Scaling->setValue(QV.toInt());
}
//Function: clearLog
//Type: Slot
//Description: clears the log, sets font size
void TwoPhotonGui::clearLog()
{
	TwoPhotonGui::textEdit_log->clear();
	TwoPhotonGui::textEdit_log->setFontPointSize(7);
}
//Function: processLogText
//Type: Slot
//Description: updates log with text entry
//Input: text, describing entry
void TwoPhotonGui::processLogText(QString text)
{
	TwoPhotonGui::textEdit_log->insertPlainText(text);
}
//Function: receivePort
//Type: Slot
//Description: updates GUI with server port number
//Input: port number
void TwoPhotonGui::receivePort(int port)
{
	char buff[12];

	itoa(port,buff,10);

	TwoPhotonGui::lineEdit_ServerPort->setText(buff);
}


//Function: updZPos
//Description: Slot used to update z position during z-stack acq
void TwoPhotonGui::updZPos(float zPos)
{
	TwoPhotonGui::doubleSpinBox_zPos->setValue(zPos);
 }
