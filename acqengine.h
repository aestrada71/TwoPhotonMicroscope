/*	Name: acqengine.h
	Description: Two Photon Acquisition
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:	7/17/2006		Added birectional acq capabilities.
*/ 

#include "NIDAQmx.h"
#include "nivision.h"

#ifndef ACQENGINE_H
#define ACQENGINE_H

#define DAQmxErrChk(functionCall) { if( DAQmxFailed(error=(functionCall)) ) { goto Error; } }   

class AcqEngine
{
public:
	// constructors
	AcqEngine(int numLinesFlyback);
	
	// destructor
	~AcqEngine();
	
	
	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	bool getBInitialized() { return bInitialized; }
	bool getBInput1() { return bInput1; }
	bool getBInput2() { return bInput2; }
	bool getSaveData() { return saveData; }
	bool getB3DAcq() { return b3DAcq; }
	bool getMemIsAllocated() { return memIsAllocated; }
	char *getAcqChan1() { return acqChan1; }
	char *getAcqChan2() { return acqChan2; }
	char *getErrBuff() { return errBuff; }
	int getHeaderVersionNum() { return headerVersionNum; }
	long getNumSampsRead() { return numSampsRead; }
	long getNumActiveChannels() { return numActiveChannels; }
	unsigned int getNumBitsADC() { return numBitsADC; }
	//unsigned long getNumSampsFlybackPerFrame() { return numSampsFlybackPerFrame; }
	unsigned long getNumFrames() { return numFrames; }
	unsigned long getnumValidXSamps() { return numValidXSamps; }
	unsigned long getnumValidYSamps() { return numValidYSamps; }
	//unsigned long getBufferSize() { return bufferSize; }
	unsigned long getNumSampsPerFrame() { return numSampsPerFrame; }
	unsigned long getNumSampsTotal() { return numSampsTotal; }
	unsigned long getTotSampsPerLine() { return totSampsPerLine; }
	unsigned long getTotLinesPerFrame() { return totLinesPerFrame; }
	unsigned long getNumSampsPerFrame_LS() { return numSampsPerFrame_LS; }
	unsigned long getNumSampsTotal_LS() { return numSampsTotal_LS; }
	unsigned long getTotSampsPerLine_LS() { return totSampsPerLine_LS; }
	unsigned long getTotLinesPerFrame_LS() { return totLinesPerFrame_LS; }
	double getZStartPos() { return zStartPos; }
	double getZStopPos() { return zStopPos; }
	double getZStepSize() { return zStepSize; }
	double getNumZSteps() { return numZSteps; }
	double getAcqMin() { return acqMin; }
	double getAcqMax() { return acqMax; }
	double getDToARate() { return dToARate; }
	double getFrameRate() { return frameRate; }
	double getAcqTrigRate() { return acqTrigRate; }
	short *getAcqData() { return acqData; }
	short getAcqData(unsigned long int index) { return acqData[index]; }
	TaskHandle getAcqTaskHandle() { return acqTaskHandle; }
	double getXPos() { return xPos; }
	double getYPos() { return yPos; }
	double getZPos() { return zPos; }
	int getXOffset() { return xOffset; }
	int getWidth()	{ return width;	}
	int getRepeats() { return repeats; }
	int getBLineScan() { return bLineScan; }
	unsigned long getOverscan() { return overscan; }
	unsigned long getOverscan_LS() { return overscan_LS; }
	bool getContAcq() { return contAcq; }
	
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	void setBInitialized(bool b) { bInitialized = b; }
	void setBInput1(bool b) { bInput1 = b; }
	void setBInput2(bool b) { bInput2 = b; }
	void setSaveData(bool b) { saveData = b; }
	void setB3DAcq(bool b) { b3DAcq = b; }
	void setMemIsAllocated(bool b) { memIsAllocated = b; }
	void setAcqChan1(char chan1[]) { memcpy(acqChan1,chan1,256*sizeof(char)); }
	void setAcqChan2(char chan2[]) { memcpy(acqChan2,chan2,256*sizeof(char)); }
	void setErrBuff(char buff[]) { memcpy(errBuff,buff,2048*sizeof(char)); }
	void setHeaderVersionNum(int num) { headerVersionNum = num; }
	void setNumSampsRead(long num) { numSampsRead = num; }
	void setNumActiveChannels(long num) { numActiveChannels = num; }
	void setNumBitsADC(unsigned int num) { numBitsADC = num; }
	//void setNumSampsFlybackPerFrame(unsigned long num) { numSampsFlybackPerFrame = num; }
	void setNumFrames(unsigned long num) { numFrames = num; }
	void setnumValidXSamps(unsigned long num) { numValidXSamps = num; }
	void setnumValidYSamps(unsigned long num) { numValidYSamps = num; }
	//void setBufferSize(unsigned long size) { bufferSize = size; }
	void setNumSampsPerFrame(unsigned long num) { numSampsPerFrame = num; }
	void setNumSampsTotal(unsigned long num) { numSampsTotal = num; }
	void setTotSampsPerLine(unsigned long samps) { totSampsPerLine = samps; }
	void setTotLinesPerFrame(unsigned long lines) { totLinesPerFrame = lines; }
	void setZStartPos(double pos) { zStartPos = pos; }
	void setZStopPos(double pos) { zStopPos = pos; }
	void setZStepSize(double size) { zStepSize = size; }
	void setNumZSteps(double steps) { numZSteps = steps; }
	void setAcqMin(double min) { acqMin = min; }
	void setAcqMax(double max) { acqMax = max; }
	void setDToARate(double rate) { dToARate = rate; }
	void setFrameRate(double rate) { frameRate = rate; }
	void setAcqTrigRate(double rate) { acqTrigRate = rate; }
	void setAcqData(short* data) { acqData = data; } //wrong use of pointers
	void setAcqTaskHandle(TaskHandle handle) { acqTaskHandle = handle; }
	void setXPos(double pos) { xPos = pos; }
	void setYPos(double pos) { yPos = pos; }
	void setZPos(double pos) { zPos = pos; }
	void setXOffset(int offset) { xOffset = offset; }
	void setWidth(int w) { width = w; }
	void setRepeats(int r) { repeats = r; }
	void setBLineScan(bool scan) { bLineScan = scan; }
	void setOverscan(unsigned long oscan) { overscan = oscan; }
	void setOverscan_LS(unsigned long oscan) { overscan_LS = oscan; }
	void setPercentOverscan(double percentOScan) { percentOverscan = percentOScan; }
	void setContAcq(bool con) { contAcq = con; }
	//void setOverscanCalculated(bool calced) { overscanCalculated = calced; }
	
	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	int initAcq(bool bGrabMemory, bool lineScan);
	int update();
	int grabMemory();
	int releaseMemory();
	int configDAQmxTask(bool bTriggered, bool bContinuous);
	int readDAQmxTask();
	int startDAQmxTask();
	int stopDAQmxTask();
	int ReverseEvenRowData();		//Needed for bi-drectional acq.
	unsigned long calcNumSampsPerFrame();
	//double updateLineScanSpeed(TwoPhotonGui* TwoPGui);	NEED IMPLEMENTATION
	
private:
	// static constants
	static const double PI; //= 3.1415926535897932384626433832795028841971;
	
	// private members
	int Num_Lines_Flyback;
	bool bInitialized, bInput1, bInput2;
	bool saveData, b3DAcq, memIsAllocated;
	bool bLineScan;
	char acqChan1[256];
	char acqChan2[256];
	char errBuff[2048];
	int headerVersionNum;
	long numSampsRead, numActiveChannels;
	unsigned int numBitsADC, numFrames,numLinesFlybackPerFrame;
	unsigned long numValidXSamps, numValidYSamps;
	unsigned long totSampsPerLine, totLinesPerFrame, numSampsPerFrame, numSampsTotal;
	unsigned long totSampsPerLine_LS, totLinesPerFrame_LS, numSampsPerFrame_LS, numSampsTotal_LS;		//For line scan mode
	double zStartPos, zStopPos, zStepSize, numZSteps;
	double acqMin, acqMax, dToARate, frameRate, acqTrigRate;
	short* acqData;
	TaskHandle acqTaskHandle;
	double xPos, yPos, zPos;
	int xOffset;
	int width, repeats;		//For line scan mode.
	double	percentOverscan;
	unsigned long overscan;
	unsigned long overscan_LS;

	bool contAcq;
};

#endif