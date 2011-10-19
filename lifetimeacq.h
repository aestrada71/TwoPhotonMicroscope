/*	Name: lifetimeacq.h
	Description: Lifetime Acquisition Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#ifndef LIFETIMEACQ_H
#define LIFETIMEACQ_H

#include "scanengine.h"

//#define DAQmxErrChk(functionCall) { if( DAQmxFailed(error=(functionCall)) ) { goto Error; } }

class LifetimeAcq
{
public:
	// constructors
	LifetimeAcq();
	LifetimeAcq(const LifetimeAcq& life);
	
	// deconstructor
	~LifetimeAcq();

	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	int getX() { return x; }
	int getY() { return y; }
	float getXVolts() { return xVolts; }
	float getYVolts() { return yVolts; }
        int getMeasRefNum() {return measRefNum;}
	
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
	void setXVolts(float v) { xVolts = v; }
	void setYVolts(float v) { yVolts = v; }
        void setMeasRefNum(int num) {measRefNum = num;}
	
	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	int configDAQmxTasks(float xVolts, float yVolts, ScanEngine* scanStruct);
	int stopTasks();
	int writeTheLTAcqData(uInt32* data, char FILE_NAME[]);
	int lifetimeAcq(float xVolts, float yVolts,ScanEngine* scanStruct, char FILE_NAME[]);

private:
	int x;
	int y;
        int measRefNum;         //Added this to synchronize tcspc lifetime acq to 2p sw.
	float xVolts;
	float yVolts;
	//float* trigAcqDataFloat;

	// static members, constants
	static const bool VERBOSE;
	static const double ACQMIN;
	static const double ACQMAX;
	static const double SAMP_RATE;
	static const double DURATION;
	static const int NUM_TRIGS;
	static const char ACQ_CHANNEL[];
	static const char SAMPCLK_CHANNEL[];
	static const char COUNTER_CHANNEL[];
	static const char TRIG_CHANNEL[];
	//static const char FILE_NAME[] ;
	static const unsigned char padding;
	static const int Header_Size;
	static const int numBytesPerDatumLT;
	
	// global variables
	static TaskHandle acqTaskHandle;
	static TaskHandle ctrTaskHandle;
	static TaskHandle aoTaskHandle;
	static int32* numSampsWritten;
	static long numSamps;
	static unsigned int totSamps;
};

#endif
