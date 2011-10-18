/*	Name: TwoPhoton.cpp
	Description: Two Photon Acquisition software
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#include <QObject>
#include <QTreeWidget>
#include <QApplication>

#include "TwoPhotonGui.h"
#include "TwoPhotonControl.h"



//----------------------------------

 int main(int argc, char *argv[])
 {

	int retVal;

	//Open QT Gui
    QApplication app(argc, argv);

	//declare class instances
	TwoPhotonGui gui;
	TwoPhotonControl tpControl;// = new TwoPhotonControl();

	//Connect signals from gui generated events to control class ;

	gui.connect(&gui, SIGNAL(startAcq(const QString &)),&tpControl, SLOT(AcqCallback(const QString &)));
	gui.connect(&gui, SIGNAL(sigScanDrive()),&tpControl, SLOT(ScanDrive()));
	gui.connect(&gui, SIGNAL(sigAcqLifetimeData()),&tpControl, SLOT(AcqLifetimeData()));
	gui.connect(&gui, SIGNAL(sigStopScanDrive()),&tpControl, SLOT(StopScanDrive()));
	gui.connect(&gui, SIGNAL(sigAomControlOn(double)),&tpControl, SLOT(AomControlOn(double)));
	gui.connect(&gui, SIGNAL(sigAomControlUpdate(double)),&tpControl, SLOT(AomControlUpdate(double)));
	gui.connect(&gui, SIGNAL(sigAomControlOff()),&tpControl, SLOT(AomControlOff()));
	gui.connect(&gui, SIGNAL(sigUpdateLineRateField()),&tpControl, SLOT(updateLineRateField()));
	gui.connect(&gui, SIGNAL(sigUpdateLineScanSpeed()),&tpControl, SLOT(UpdateLineScanSpeed()));
	gui.connect(&gui, SIGNAL(sigUpdateMemoryNeeded()),&tpControl, SLOT(UpdateMemoryNeeded()));
	//gui.connect(&gui, SIGNAL(sigContAcqCallback()),&tpControl, SLOT(ContAcqCallback()));
	gui.connect(&gui, SIGNAL(sigStopContAcqCallback()),&tpControl, SLOT(StopContAcqCallback()));
	gui.connect(&gui, SIGNAL(sigParkBeam()),&tpControl, SLOT(parkBeam()));
	gui.connect(&gui, SIGNAL(sigUpdateIntensityScaling(short,short,short,short)),&tpControl, SLOT(updateIntensityScaling(short,short,short,short)));
	gui.connect(&gui, SIGNAL(sigUpdateAomTimer()),&tpControl, SLOT(updateAomTimer()));
	gui.connect(&gui, SIGNAL(sigSaveImageLoc(double, double, double)),&tpControl, SLOT(saveImageLoc(double, double, double)));
	gui.connect(&gui, SIGNAL(sigSavePointLoc(double, double, double)),&tpControl, SLOT(savePointLoc(double, double, double)));
	gui.connect(&gui, SIGNAL(sigGoToLoc(QTreeWidgetItem,double,double)),&tpControl, SLOT(goToLoc(QTreeWidgetItem,double,double)));
	gui.connect(&gui, SIGNAL(sigZSetOrigin(double,QTreeWidget*)),&tpControl, SLOT(zSetOrigin(double,QTreeWidget*)));
	gui.connect(&gui, SIGNAL(sigStopAcq()),&tpControl, SLOT(stopAcq()));
	gui.connect(&gui, SIGNAL(sigConnectZCom(int)),&tpControl, SLOT(connectZCom(int)));
	gui.connect(&gui, SIGNAL(sigConnectXYCom(int)),&tpControl, SLOT(connectXYCom(int)));
	gui.connect(&gui, SIGNAL(sigSetXYOrigin(double,double,QTreeWidget*)),&tpControl, SLOT(setXYOrigin(double,double,QTreeWidget*)));
	gui.connect(&gui, SIGNAL(sigCoarseUp(double,double)),&tpControl, SLOT(coarseUp(double,double)));
	gui.connect(&gui, SIGNAL(sigCoarseDown(double,double)),&tpControl, SLOT(coarseDown(double,double)));
	gui.connect(&gui, SIGNAL(sigCoarseLeft(double,double)),&tpControl, SLOT(coarseLeft(double,double)));
	gui.connect(&gui, SIGNAL(sigCoarseRight(double,double)),&tpControl, SLOT(coarseRight(double,double)));
	gui.connect(&gui, SIGNAL(sigFineUp(double,double)),&tpControl, SLOT(fineUp(double,double)));
	gui.connect(&gui, SIGNAL(sigFineDown(double,double)),&tpControl, SLOT(fineDown(double,double)));
	gui.connect(&gui, SIGNAL(sigFineLeft(double,double)),&tpControl, SLOT(fineLeft(double,double)));
	gui.connect(&gui, SIGNAL(sigFineRight(double,double)),&tpControl, SLOT(fineRight(double,double)));
	gui.connect(&gui, SIGNAL(sigZStepUp(double)),&tpControl, SLOT(zStepUp(double)));
	gui.connect(&gui, SIGNAL(sigZStepDown(double)),&tpControl, SLOT(zStepDown(double)));
	gui.connect(&gui, SIGNAL(sigZMoveTo(double)),&tpControl, SLOT(zMoveTo(double)));
	gui.connect(&gui, SIGNAL(sigUpdateNumZSteps(double,double,double)),&tpControl, SLOT(updateNumZSteps(double,double,double)));
	gui.connect(&gui, SIGNAL(sigViewVisionTools()),&tpControl, SLOT(viewVisionTools()));
	gui.connect(&gui, SIGNAL(sigViewImageOne()),&tpControl, SLOT(viewImageOne()));
	gui.connect(&gui, SIGNAL(sigViewImageTwo()),&tpControl, SLOT(viewImageTwo()));
        gui.connect(&gui, SIGNAL(sigRotateGalvos()),&tpControl, SLOT(rotateGalvos()));
        gui.connect(&gui, SIGNAL(sigResetLTAcqNum(int)),&tpControl, SLOT(slotUpdateLTAcqNum(int)));

	//connect signals/slots from control class back to gui for updating
	gui.connect(&tpControl, SIGNAL(sendLineRateInfo(double,double)),&gui, SLOT(updateGuiLineRateField(double,double)));
	gui.connect(&tpControl, SIGNAL(sendLinescanSpeed(double)),&gui, SLOT(UpdateGuiLineScanSpeed(double)));
	gui.connect(&tpControl, SIGNAL(sendMemNeeded(double)),&gui, SLOT(UpdateGuiMemoryNeeded(double)));
	gui.connect(&tpControl, SIGNAL(sendMessageForPopup(QString,QString)),&gui, SLOT(popupMessage(QString,QString)));
	gui.connect(&tpControl, SIGNAL(sigLockControlWidgets()),&gui, SLOT(lockControlWidgets()));
	gui.connect(&tpControl, SIGNAL(sigUnlockControlWidgets()),&gui, SLOT(unlockControlWidgets()));
	gui.connect(&tpControl, SIGNAL(setStopButton(bool)),&gui, SLOT(setStopButton(bool)));
	gui.connect(&tpControl, SIGNAL(setScanButton(bool)),&gui, SLOT(setScanButton(bool)));
	gui.connect(&tpControl, SIGNAL(setStopAcqButton(bool)),&gui, SLOT(setStopAcqButton(bool)));
	gui.connect(&tpControl, SIGNAL(setChkAomPulsed(bool)),&gui, SLOT(setChkAomPulsed(bool)));
	gui.connect(&tpControl, SIGNAL(setChkAomCont(bool)),&gui, SLOT(setChkAomCont(bool)));
	gui.connect(&tpControl, SIGNAL(setAomOnButton(bool)),&gui, SLOT(setAomOnButton(bool)));
	gui.connect(&tpControl, SIGNAL(setAomOffButton(bool)),&gui, SLOT(setAomOffButton(bool)));
	gui.connect(&gui, SIGNAL(sendAomClassData(AomControl*)),&tpControl, SLOT(updateAomControl(AomControl*)));
	gui.connect(&gui, SIGNAL(sendAcqClassData(AcqEngine)),&tpControl, SLOT(updateAcqControl(AcqEngine)));
	gui.connect(&gui, SIGNAL(sendZStepClassData(zStepperDriver)),&tpControl, SLOT(updateZStepControl(zStepperDriver)));
	gui.connect(&tpControl, SIGNAL(sendAomIntScalingVals(double,double)),&gui, SLOT(setAomIntScalingVals(double,double)));
	gui.connect(&tpControl, SIGNAL(sigUpdateAomControl()),&gui, SLOT(updateAomControl()));
	gui.connect(&tpControl, SIGNAL(sigUpdateDataFile()),&gui, SLOT(updateDataFile()));
	gui.connect(&tpControl, SIGNAL(sigUpdateAcqEng()),&gui, SLOT(updateAcqEng()));
	gui.connect(&tpControl, SIGNAL(sigUpdateScanEng()),&gui, SLOT(updateScanEng()));
	gui.connect(&tpControl, SIGNAL(sigUpdateZStepEng()),&gui, SLOT(updateZStepEng()));
	gui.connect(&tpControl, SIGNAL(sigUpdateScalingFields(int,int,double,double)),&gui,SLOT(updateScalingField(int,int,double, double)));
	gui.connect(&tpControl, SIGNAL(sigUnlockContScanWidgets()),&gui,SLOT(UnlockContScanControlWidgets()));
	gui.connect(&tpControl, SIGNAL(sigFinishContAcq()),&gui,SLOT(finishContAcq()));
	gui.connect(&gui, SIGNAL(sendDataClassData(DataFile2P)),&tpControl,SLOT(updateDataControl(DataFile2P)));
	gui.connect(&tpControl, SIGNAL(sigUpdateScalingInt(short,short,short,short)),&gui,SLOT(updateScalingInt(short,short,short,short)));
	gui.connect(&tpControl, SIGNAL(sigUpdateZStepField(int)),&gui,SLOT(updateNumZStepsField(int)));
	gui.connect(&tpControl, SIGNAL(sigAddSavedLoc(QTreeWidgetItem*,int)),&gui,SLOT(addSavedLoc(QTreeWidgetItem*,int)));
	gui.connect(&tpControl, SIGNAL(sigSendCoarseFieldVal(double)),&gui,SLOT(setCoarseStepField(double)));
	gui.connect(&tpControl, SIGNAL(sigSendZMoveToPos(double)),&gui,SLOT(setZMoveToField(double)));
	gui.connect(&tpControl, SIGNAL(sigSendZPos(double)),&gui,SLOT(setZPos(double)));
	gui.connect(&tpControl, SIGNAL(sigSendLocTree(QTreeWidget*)),&gui,SLOT(setLocTree(QTreeWidget*)));
	gui.connect(&tpControl, SIGNAL(sigSendXPos(double)),&gui,SLOT(setXPos(double)));
	gui.connect(&tpControl, SIGNAL(sigSendYPos(double)),&gui,SLOT(setYPos(double)));
	gui.connect(&tpControl, SIGNAL(sigSendFineFieldVal(double)),&gui,SLOT(setFineStepField(double)));
	gui.connect(&tpControl, SIGNAL(sigAddMagEntry(int,char*,int)),&gui,SLOT(addMagEntry(int,char*,int)));
	gui.connect(&tpControl, SIGNAL(sigSendXYCom(int)),&gui,SLOT(setXYCom(int)));
	gui.connect(&tpControl, SIGNAL(sigSendZCom(int)),&gui,SLOT(setZCom(int)));
	gui.connect(&tpControl, SIGNAL(sigUpdateScaling()),&gui,SLOT(updateScaling()));
	gui.connect(&tpControl, SIGNAL(sigClearLog()),&gui,SLOT(clearLog()));
	gui.connect(&tpControl, SIGNAL(sigSendLogText(QString)),&gui,SLOT(processLogText(QString)));
	gui.connect(&gui, SIGNAL(sendScanClassData(ScanEngine*)),&tpControl, SLOT(updateScanControl(ScanEngine*)));
	gui.connect(&tpControl, SIGNAL(sigSendPercentComplete(double)),&gui, SLOT(receivePercentComplete(double)));
	gui.connect(&tpControl, SIGNAL(sigUpdateScanBar(double)),&gui,SLOT(updateScanProgressBar(double)));
	gui.connect(&tpControl, SIGNAL(sigToggleAomWidgets(bool)),&gui,SLOT(toggleAomWidgets(bool)));
	gui.connect(&tpControl, SIGNAL(sigSendPort(int)),&gui,SLOT(receivePort(int)));
        gui.connect(&tpControl, SIGNAL(sigUpdateLifetimeAcqNum(int)),&gui,SLOT(updateLifeTimeAcqNumber(int)));
        gui.connect(&tpControl, SIGNAL(sigChkSave(bool)),&gui,SLOT(setChkSave(bool)));
	
	//Init application class
	tpControl.init();
	//Display Gui
	gui.show();	
	
	

	//call destructor for GUI
    retVal = app.exec();

	return retVal;
	
 }
