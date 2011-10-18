/*	Name: TwoPhotonControl.h
	Description: Master container class for two photon
	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/11/2009		Begun moving software to C++ and QT gui
	Updated:
*/ 
#include <QObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "string.h"

//include 2p files for functionality
#include "2pData.h"
#include "acqengine.h"
#include "aomControl.h"
#include "scanengine.h"
#include "lifetimeacq.h"
#include "AcqThread.h"
#include "stepperDriver.h"
#include "zStepDriver.h"
#include "Server.h"


#ifndef TWOPHOTONCONTROL_H
#define TWOPHOTONCONTROL_H

class TwoPhotonControl : public QObject
{
	Q_OBJECT

public:
	// constructors
	TwoPhotonControl(QObject * parent = 0);

	// destructor
	~TwoPhotonControl();
	
	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	int init();
	int ParseConfig();
	int CalcXYVoltsFromPxlVal(int x, int y, double& xVolts, double& yVolts);
	int InitLog();
	int AddLogItem(char* buff);
	void AcqDriveThread(bool linescan);
	void RunAcq(bool continuous, bool linescan);	//consolidated
	int testXVoltageRange(bool linescan, unsigned long overScan);
	int AomZeroStart();
	int AomStop();
	int AcqLifeTime1Point(float xVolt, float yVolt, double aomVoltage, char FILE_NAME[]);
	int CalcNumZSteps();
	int Update2PDataStruct();
	void evaluateAomIntensityScaling();
	int startScanBar();
	int stopScanBar();
	

	//----------------------------------------------------------------------------------------
	// Slots ---------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	public slots:
		//GUI Interfacing slots
		//void Acquire();
		void ScanDrive();
		void AcqCallback(const QString & buttonName);	//consolidated
		void StopAcqCallback();
		//void LineScanAcq();
		void changeDir();
		void AcqLifetimeData();
		void StopScanDrive();
		void AomControlOn(double voltage);
		void AomControlUpdate(double voltage);
		void AomControlOff();
		void updateScalingField();
		double updateLineRateField();
		double UpdateLineScanSpeed();
		double UpdateMemoryNeeded();
		//void ContAcqCallback();
		void StopContAcqCallback();
		void parkBeam();
		void updateIntensityScaling(short ch1Min,short ch1Max,short ch2Min, short ch2Max);
		void updateAomTimer();
		void updateNumZSteps(double zStopPos, double zStartPos, double zStepSize);
		void saveImageLoc(double x, double y, double z);
		void savePointLoc(double x, double y, double z);
		void goToLoc(QTreeWidgetItem entry, double coarse, double zMoveTo);
		void zSetOrigin(double zPos, QTreeWidget* tree);
		void stopAcq();
		void connectZCom(int port);
		void connectXYCom(int port);
		void viewVisionTools();
		void viewImageOne();
		void viewImageTwo();
		void setXYOrigin(double xPos,double yPos, QTreeWidget* tree);
		void coarseUp(double coarsefield,double yPos);
		void coarseDown(double coarsefield,double yPos);
		void coarseLeft(double coarsefield,double xPos);
		void coarseRight(double coarsefield,double xPos);
		void fineUp(double finefield, double yPos);
		void fineDown(double finefield, double yPos);
		void fineLeft(double finefield, double xPos);
		void fineRight(double finefield, double xPos);
		void zStepUp(double stepSize);
		void zStepDown(double stepSize);
		void zMoveTo(double moveToPos);
		void updateAomControl(AomControl* aomClass);
		void updateAcqControl(AcqEngine acqClass);
		void updateScanControl(ScanEngine* scanClass);
		void updateDataControl(DataFile2P dataClass);
		void updateZStepControl(zStepperDriver zStepClass);
		void rotateGalvos();
		void slotSendPort(int port);
                void slotUpdateLTAcqNum(int num);

		//Acquisition Thread interfacing slots
		void acqFinished();
		void progressUpdate(double percent);
		void updateScanBar();
		void zPosUpdate(double);

	//----------------------------------------------------------------------------------------
	// Signals -------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
signals:
	void sendLineRateInfo(double rate, double frameTime);
	void sendLinescanSpeed(double lineSpeed);
	void sendMemNeeded(double memNeeded);
	void sendMessageForPopup(QString title,QString message);
	void sigLockControlWidgets();
	void sigUnlockControlWidgets();
	void sigUnlockContScanWidgets();
	void sigFinishContAcq();
	void setScanButton(bool on);
	void setStopButton(bool on);
	void setStopAcqButton(bool on);
	void setChkAomPulsed(bool checked);
	void setChkAomCont(bool checked);
        void sigChkSave(bool checked);
	void setAomOnButton(bool on);
	void setAomOffButton(bool on);
	void sendAomIntScalingVals(double bottom, double top);
	void sigUpdateAomControl();
	void sigUpdateDataFile();
	void sigUpdateAcqEng();
	void sigUpdateScanEng();
	void sigUpdateZStepEng();
	void sigUpdateScalingFields(int xFov,int yFov,double xRes,double yRes);
	void sigUpdateScalingInt(short ch1Min,short ch1Max,short ch2Min,short ch2Max);
	void sigUpdateZStepField(int numZSteps);
	void sigAddSavedLoc(QTreeWidgetItem* entry, int type);
	void sigSendCoarseFieldVal(double size);
	void sigSendFineFieldVal(double size);
	void sigSendZMoveToPos(double z);
	void sigSendZPos(double z);
	void sigSendLocTree(QTreeWidget* tree);
	void sigSendXPos(double x);
	void sigSendYPos(double y);
	void sigAddMagEntry(int numObj, char* string, int data);
	void sigSendXYCom(int port);
	void sigSendZCom(int port);
	void sigUpdateScaling();
	void sigClearLog();
	void sigSendLogText(QString text);
	void sigSendPercentComplete(double percent);
	void sigUpdateScanBar(double percent);
	void sigToggleAomWidgets(bool aomOn);
	void sigSendPort(int port);
        void sigUpdateLifetimeAcqNum(int acqNumber);

private:

	//private class instances -------------------------------------------------
	DataFile2P *data2P;
	AcqEngine *acqEng;
	AomControl *aomCtrl;
	LifetimeAcq *ltAcq;
	ScanEngine *scanEng;
	AcqThread *acqThread;
	stepperDriver *stepEng;
	zStepperDriver *zStepEng;
	QTimer *aomTimer;
	QTimer *scanTimer;
	Server *tcspcServer;

	//Member variables --------------------------------------------------------
	short			scaleMin1;					//Min val for signed short
	short			scaleMax1;					//Max val for signed short
	short			scaleMin2;					//Min val for signed short
	short			scaleMax2;					//Max val for signed short
	double			zStartPos;
	double			zStepSize;
	double			numZSteps;
	double			zPos;
	bool			bAdjustLaserIntensityOn3DAcq;
	double			scanPercent;				//used to update scan progress bar
	int				lifeTimeAcqNumber;			//Counter used to keep reference TCSPC board lifetime data

	//Initialization Variables-------------------------------------------------
	//These variables are used to initialize other classes
	//These used to be global vars
	static const long		Min_Count = -32768;;
	static const long		Max_Count = 32767;
	static const double		SCANENGINE_PERCENT_OVERSCAN;
	static const double		SCANENGINE_PERCENT_OVERSCAN_V;
	static const int		Num_Lines_Flyback	= 4;
	static const int		Header_Size = 512;			//bytes
	static const int		numBytesPerDatum = 2;		//short 
	static const int		ADC_Num_Bits = 16;
	static const float		Version_Number;
	static const int		Max_LineRate = 1000;		//Hz
	static const char		TCSPC_Trig_Channel[];		//To start TCSPC board measurement 
	static const char		Trig_Channel[];
	static const double		Num_XYSteps_Per_Micron;			//x-y stage.  Make this more accurate

};

#endif
