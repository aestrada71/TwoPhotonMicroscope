/*	Name: scanengine.h
	Description: Scanning Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#include "NIDAQmx.h"
#include "string.h"


#ifndef SCANENGINE_H
#define SCANENGINE_H

#define DAQmxErrChk(functionCall) { if( DAQmxFailed(error=(functionCall)) ) { goto Error; } }

class ScanEngine
{
public:
	// constructors
	ScanEngine(int numLinesFlyback, double percentOverscan, double overScanV);

	// destructor
	~ScanEngine();
	
	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	int	getWidth() { return width;	}
	int getRepeats() {	return repeats;	}
	int getPark_X()	{ return park_x; }
	int getPark_Y() { return park_y; }
	bool getBInitialized() { return bInitialized; }
	bool getMemIsAllocated() { return memIsAllocated; }
	char* getXChan() { return xChan; }
	char* getYChan() { return yChan; }
	char* getTrigChan() {return trigChan; }
	char* getErrBuff() { return errBuff; }
	unsigned long getnumValidXSamps() { return numValidXSamps; }
	unsigned long getnumValidYSamps() { return numValidYSamps; }
	unsigned long getNumLinesFlybackPerFrame() { return numLinesFlybackPerFrame; }
	unsigned long getTotSampsPerLine() { return totSampsPerLine; }
	unsigned long getTotSampsPerLine_LS() { return totSampsPerLine_LS; }
	unsigned long getTotLinesPerFrame() { return totLinesPerFrame; }
	unsigned long getTotLinesPerFrame_LS() { return totLinesPerFrame_LS; }
	unsigned long getNumSampsPerFrame() { return numSampsPerFrame; }
	unsigned long getNumSampsPerFrame_LS() { return numSampsPerFrame_LS; }
	//unsigned long getBufferSize() { return bufferSize; }
	unsigned int getNumFrames() { return numFrames; }
	unsigned long getNumSampsTotal() { return numSampsTotal; }
	long getSampsWritten() { return sampsWritten; }
	double getLine_Rate() { return Line_Rate; }
	double getSamp_Rate() { return Samp_Rate; }
	float getFrameTime() { return FrameTime; }
	double getXMinVolts() { return xMinVolts; }
	double getXMaxVolts() { return xMaxVolts; }
	double getYMinVolts() { return yMinVolts; }
	double getYMaxVolts() { return yMaxVolts; }
	double getROIPt1XVolts() {return roiPt1XVolts; }
	double getROIPt1YVolts() {return roiPt1YVolts; }
	double getROIPt2XVolts() {return roiPt2XVolts; }
	double getROIPt2YVolts() {return roiPt2YVolts; }
	double getXRange() { return xRange; }
	double getYRange() { return yRange; }
	double *getDacData() { return dacData; } 
 	TaskHandle getScanTaskHandle() { return scanTaskHandle; }
	double getLineRate() { return lineRate; }
	double getLineLength() { return lineLength; }
	double getScaling() { return scaling; }
	char* getMag() { return mag; }
	unsigned long getOverscan() { return overscan; }
	unsigned long getOverscan_LS() { return overscan_LS; }
	unsigned long getPercentOverscan() { return percentOverscan; }
	bool getOverscanCalculated() { return overscanCalculated; }
	bool getTriggered() { return bTrigger; }
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	void setPark_X(int x) { park_x = x; }
	void setPark_Y(int y) { park_y = y; }
	void setWidth(int w) { width = w;	}
	void setRepeats(int r) { repeats = r;	}
	void setBInitialized(bool b) { bInitialized = b; }
	void setMemIsAllocated(bool b) { memIsAllocated = b; }
	void setXChan(char chan[]) { memcpy(xChan,chan,256*sizeof(char)); }
	void setYChan(char chan[]) { memcpy(yChan,chan,256*sizeof(char)); }
	void setTrigChan(char chan[]) { memcpy(trigChan,chan,256*sizeof(char)); }
	void setErrBuff(char buff[]) {  memcpy(errBuff,buff,4096*sizeof(char)); }
	void setnumValidXSamps(unsigned long num) { numValidXSamps = num; }
	void setnumValidYSamps(unsigned long num) { numValidYSamps = num; }
	void setNumLinesFlybackPerFrame(unsigned long num) { numLinesFlybackPerFrame = num; }
	void setTotSampsPerLine(unsigned long samps) { totSampsPerLine = samps; }
	void setTotLinesPerFrame(unsigned long tot) { totLinesPerFrame = tot; }
	void setNumSampsPerFrame(unsigned long samps) { numSampsPerFrame = samps; }
	//void setBufferSize(unsigned long size) { bufferSize = size; }
	void setNumFrames(unsigned int num) { numFrames = num; }
	void setNumSampsTotal(unsigned long num) { numSampsTotal = num; }
	void setSampsWritten(long samps) { sampsWritten = samps; }
	void setLine_Rate(double rate) { Line_Rate = rate; }
	void setSamp_Rate(double rate) { Samp_Rate = rate; }
	void setFrameTime(float time) { FrameTime = time; }
	void setXMinVolts(double v) { xMinVolts = v; }
	void setXMaxVolts(double v) { xMaxVolts = v; }
	void setYMinVolts(double v) { yMinVolts = v; }
	void setYMaxVolts(double v) { yMaxVolts = v; }
	void setROIPt1XVolts(double v) { roiPt1XVolts = v; }
	void setROIPt1YVolts(double v) { roiPt1YVolts = v; }
	void setROIPt2XVolts(double v) { roiPt2XVolts = v; }
	void setROIPt2YVolts(double v) { roiPt2YVolts = v; }
	void setXRange(double range) { xRange = range; }
	void setYRange(double range) { yRange = range; }
 	void setDacData(double* data) { dacData = data; } 
	void setScanTaskHandle(TaskHandle handle) { scanTaskHandle = handle; }
	void setLineRate(double rate) { lineRate = rate; }
	void setLineLength(double len) { lineLength = len; }
	void setScaling(double scale) { scaling = scale; }
	void setMag(char magn[]) { memcpy(mag,magn,64*sizeof(char)); }
	void setXHoldVolts(double volts) { xHoldVolts = volts; }
	void setYHoldVolts(double volts) { yHoldVolts = volts; }
	void setOverscan(unsigned long oscan) { overscan = oscan; }
	void setOverscan_LS(unsigned long oscan) { overscan_LS = oscan; }
	void setPercentOverscan(double percentOScan) { percentOverscan = percentOScan; }
	void setOverscanCalculated(bool calced) { overscanCalculated = calced; }
	void setTriggered(bool bTrig) { bTrigger = bTrig; }
	
	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	int initScan(bool bGrabMemory, bool lineScan);
	//int initLine(bool bGrabMemory);
	int update();
	int grabMemory();
	int grabRotateMemory();
	int releaseMemory();
	int configDAQmxTask(bool bTriggered, bool bContinuous);
	int writeDAQmxTask();
	int startDAQmxTask();
	int parkBeam();
	int stopDAQmxTask();
	int clearDAQmxTask();
	unsigned long calcNumSampsPerFrame();
	int generateWaveForms();
	int generateLineScanWave(int x1, int y1, int x2, int y2);
	int generateLineScanWaveForms();
	int generateRotationWaveforms();
	int genSineWave     (int numElements,double amplitude,double frequency,double *phase,double sineWave[]);
	int gen1SawtoothWave (unsigned long numElements,unsigned long tailLength,double sawtoothWave[]);
	//int gen1TriangleWave (unsigned long numElements, double triangleWave []);
	int gen1TriangleWave ( long numOverscanSamps, unsigned long numLinearScanSamps, double triangleWave []);
	int GenDiagnosticSquareWave (unsigned long numElements, double squareWave []);
	int genSquareWave   (int numElements,double amplitude,double frequency,double *phase,double dutyCycle,double squareWave[]);
	int scaleAndShift   (const double inputArray[],int numElements,double upper,double lower,double outputArray[]);
	int scaleAndShiftTriangle   (const double inputArray[],unsigned long numElements,double upper,double lower,double outputArray[]);
	int gen1LineScan(int numElements, int tailLength, unsigned long numPixels, double maxVolt, double minVolt, double pos1, double pos2, double lineScan[]);
	int calcLineLengthStruct(int x1, int y1,int x2, int y2);
	int calcLineRate();

private:
	// static members, constants
	static const double PI;
	static const double MAXVOLT_X;
	static const double MINVOLT_X;
	static const double MAXVOLT_Y;
	static const double MINVOLT_Y;

	// private members
	bool bInitialized, memIsAllocated;
	bool bParkBeam;
	bool bTaskRunning;
	bool bLineScan;
	bool bTrigger;
	char xChan[256], yChan[256], trigChan[256], errBuff[4096];
	unsigned long numValidXSamps, numValidYSamps;
	unsigned long  numLinesFlybackPerFrame;
	unsigned long totSampsPerLine, totLinesPerFrame, numSampsPerFrame, numSampsTotal;
	unsigned long totSampsPerLine_LS, totLinesPerFrame_LS, numSampsPerFrame_LS, numSampsTotal_LS;		//For line scan mode
	//unsigned long bufferSize;		//Is this used anywhere
	unsigned int numFrames;
	int	Num_Lines_Flyback;

	long sampsWritten;
	double Line_Rate, Samp_Rate;	//non-linescan
	float FrameTime;
	double xMinVolts, xMaxVolts, yMinVolts, yMaxVolts, xMaxVOScan, xMinVOScan, yMaxVOScan, yMinVOScan;
	double roiPt1XVolts, roiPt1YVolts,roiPt2XVolts, roiPt2YVolts;
	double xRange, yRange;
	double xHoldVolts, yHoldVolts;
	double *dacData; // Will hold x and y waveforms
	TaskHandle scanTaskHandle;
	double lineRate, lineLength;	//linescan
	double scaling;
	char mag[64];
	unsigned long width, repeats;		//for line scan mode.
	int park_x,park_y;
	double	percentOverscan;
	unsigned long overscan;
	unsigned long overscan_LS;
	bool overscanCalculated;
	double	SCANENGINE_PERCENT_OVERSCAN;
	double	SCANENGINE_PERCENT_OVERSCAN_V;
};

#endif
