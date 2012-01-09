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
        char *getFileName() { return data2P->getFileName(); }

	//modifiers
	void setLinescan(bool lscan) { bLinescan = lscan; }
	void setContinuous(bool cont) { bContinuous = cont; }
        void setLifetimeFov(bool lifetime) { bLifetimeFov = lifetime; }
        void setNIVisionContourInfo(ContourInfo2* contourInfo) {NIVisionCurrContourInfo = contourInfo;}
        void setPtrToImage1(Image** ptrToimage){ptrToimage1 =  ptrToimage;}
        void setPtrToImage2(Image** ptrToimage){ptrToimage2 =  ptrToimage;}
        void setPtrToImage1Data(RGBValue** ptrToimageData){ptrToimageData1 = ptrToimageData;}
        void setPtrToImage2Data(RGBValue** ptrToimageData){ptrToimageData2 = ptrToimageData;}
        void SetScaleMin1(short val) {scaleMin1 = val;}
        void SetScaleMin2(short val) {scaleMin2 = val;}
        void SetScaleMax1(short val) {scaleMax1 = val;}
        void SetScaleMax2(short val) {scaleMax2 = val;}


	//Thread code
	void init(ScanEngine *scanEngi, AcqEngine *acqEngi,  DataFile2P *data2Pi, zStepperDriver *zStepper, AomControl *aCtrl);
	void run();
	void setIntensityScaling(short sMax1, short sMin1, short sMax2, short sMin2);
	void stopExec();
	int CalcXYVoltsFromPxlVal(int x, int y, double& xVolts, double& yVolts);  //Copied from TwoPhotonGui.  Need better way of doing this

    public slots:

	
signals:
	void acqFinished();
	void sendProgress(double progress);
	void sigZPosChange(double zPos);
        void imageData1Change(RGBValue* imageData1);
        void imageData2Change(RGBValue* imageData2);
        void image1Change(Image* image1);
        void image2Change(Image* image2);
        void sendMessageForPopup(QString title,QString message);
        void sigUdateVisionWindows(int win, int numx, int numy);

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
        int			ADC_Num_Bits, tempp;
	long			Min_Count;
	long			Max_Count;

	char			errBuff[2048];
	int 			displayWinNum1;
	int 			displayWinNum2;
        short			scaleMin1;			//Min val for signed short
        short			scaleMax1;			//Max val for signed short
        short			scaleMin2;			//Min val for signed short
        short			scaleMax2;			//Max val for signed short
        double			zStartPos;
	double			zStepSize;
	double			numZSteps;
	double			zPos;
	double			arrayMin, arrayMax;
        unsigned int*           histArray1;			// Hist values array chan 1
        unsigned int*           histArray2;			// Hist values array chan 2
	short*			binsArray;			// Hist axis array
	unsigned long	mag;

        Image**			ptrToimage1;			//Ptr to Pointer to Image object for display
        Image**			ptrToimage2;			//Ptr to Pointer to Image object for display
        RGBValue**		ptrToimageData1;		//Ptr to Data Ptr to use to make the image1
        RGBValue**		ptrToimageData2;		//Ptr to Data Ptr to use to make the image2
        ContourInfo2*           NIVisionCurrContourInfo;

	double			intScalingCoeff;
	bool			bScaleCoeffCalc;
	bool			terminate;


	//private functions
	int  ProcessDataForDisplay(int linescan);
        void updateDataPtr();
	int CalcNumZSteps();
	int Update2PDataStruct();
	double CalcIntensityScalingCoeff();
	double CalcAomIntVoltage(double depth);
	void AomUpdate(double voltage);
};

#endif
