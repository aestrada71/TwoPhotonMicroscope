/*	Name: AcqThread.h
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
#include <QThread>

#include "aomControl.h"
#include "acqengine.h"
#include "scanengine.h"
#include "2pData.h"
#include "zStepDriver.h"
#include "math.h"

#ifndef ACQTHREAD_H
#define ACQTHREAD_H

class AcqThread :  public QThread
{
	Q_OBJECT

public:
	//constructors
	AcqThread(int adcNumBits, long minCount,long maxCount,double vNum,
			ScanEngine *scanEngi, AcqEngine *acqEngi, DataFile2P *data2Pi, zStepperDriver *zStepper, AomControl *aCtrl);

	//destructors
	~AcqThread();

	//accessors
	ContourInfo2* getContourVision(int i);
        char *getFileName() { return data2P->getFileName(); }

	//modifiers
	void setLinescan(bool lscan) { bLinescan = lscan; }
	void setContinuous(bool cont) { bContinuous = cont; }
	void setLifetimeFov(bool lifetime) { bLifetimeFov = lifetime; };
	void toggleTools();
	void toggleImage1();
	void toggleImage2();

	//Thread code
	void init(ScanEngine *scanEngi, AcqEngine *acqEngi,  DataFile2P *data2Pi, zStepperDriver *zStepper, AomControl *aCtrl);
	void run();
	void setIntensityScaling(short sMax1, short sMin1, short sMax2, short sMin2);
	void stopExec();
	int CalcXYVoltsFromPxlVal(int x, int y, double& xVolts, double& yVolts);  //Copied from TwoPhotonGui.  Need better way of doing this
	
signals:
	void acqFinished();
	void sendProgress(double progress);
	void sigZPosChange(double zPos);

private:

	//members
	AcqEngine *acqEng;
	ScanEngine *scanEng;
	DataFile2P *data2P;
	zStepperDriver zStep;
	AomControl *aomCtrl;

	bool bLinescan;								//-1 = continuous scan, 0 = image scan, 1 = linescan, 2 = lifetime fov image
	bool bContinuous;
	bool bLifetimeFov;

	double			Version_Number;
	int				ADC_Num_Bits;
	long			Min_Count;
	long			Max_Count;

	char			errBuff[2048];
	int 			displayWinNum1;
	int 			displayWinNum2;
	short			scaleMin1;					//Min val for signed short
	short			scaleMax1;					//Max val for signed short
	short			scaleMin2;					//Min val for signed short
	short			scaleMax2;					//Max val for signed short
	double			zStartPos;
	double			zStepSize;
	double			numZSteps;
	double			zPos;
	double			arrayMin, arrayMax;
	unsigned int*	histArray1;			// Hist values array chan 1
	unsigned int*	histArray2;			// Hist values array chan 2
	short*			binsArray;			// Hist axis array
	unsigned long	mag;
	Image*			image1;				//Pointer to Image object for display
	Image*			image2;				//Pointer to Image object for display
	RGBValue*		imageData1;			//Data to use to make the image1
	RGBValue*		imageData2;			//Data to use to make the image2
	Point			posWindow1;			//NI Vision data type. Position of window1
	Point			posWindow2;
	
	double			intScalingCoeff;
	bool			bScaleCoeffCalc;
	bool			terminate;


	//private functions
	int  ProcessDataForDisplay(int linescan);
	void updateDataPt();
	int CalcNumZSteps();
	int Update2PDataStruct();
	double CalcIntensityScalingCoeff();
	double CalcAomIntVoltage(double depth);
	void AomUpdate(double voltage);
};

#endif
