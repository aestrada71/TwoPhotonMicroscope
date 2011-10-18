/*	Name: 2pData.h
	Description: Two Photon Data Storage and Writing
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 
#ifndef __WRITE_2P_DATA_H
#define __WRITE_2P_DATA_H

#include "acqengine.h"

#define F_NAME_SIZE 1024


class Header2P
{
public:
	//constructors
	Header2P();
	
	//destructor
	~Header2P();
	
	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	float getVersion() { return version; }
	bool getB3DAcq() { return b3DAcq; }
	int getNumX() { return numX; }
	int getNumY() { return numY; }
	int getValidX() { return validX; }
	int getValidY() { return validY; }
	int getNumFrames() { return numFrames; }
	int getNumBits() { return numBits; }
	int getADC_Min_Count() { return aDC_Min_Count; }
	int getChanNum() { return chanNum; }
	int getNumChans() {return numChans; }
	char* getMag() { return mag; }
	float getXMinV() { return xMinV; }
	float getXMaxV() { return xMaxV; }
	float getYMinV() { return yMinV; }
	float getYMaxV() { return yMaxV; }
	float getZPos() { return zPos; }
	float getXPos() { return xPos; }
	float getYPos() { return yPos; }
	float getADC_Min_Voltage() { return aDC_Min_Voltage; }
	float getADC_Max_Voltage() { return aDC_Max_Voltage; }
	float getLineRate() { return lineRate; }
	float getLineLength() { return lineLength; }
	float getObjScaling() { return objScaling; }
	int getLsX1()	{	return lsX1; }
	int getLsX2()	{	return lsX2; }
	int getLsY1()	{	return lsY1; }
	int getLsY2()	{	return lsY2; }
	int getNumSampsTotal() { return numSampsTotal; }
	int getNumSampsTotal_LS() { return numSampsTotal_LS; }
	int getOverscan() { return overscan; }
	int getOverscanLS() { return overscan_LS; }
	int getLinescan() { return linescan; }
	float getLinescanRate() { return linescanRate; }
	float getAomCtrlVoltage() { return aomCtrlVolt; }
	
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	void setVersion(float ver) { version = ver; }
	void setB3DAcq(bool b) { b3DAcq = b; }
	void setNumX(int x) { numX = x; }
	void setNumY(int y) { numY = y; }
	void setValidX(int x) { validX = x; }
	void setValidY(int y) { validY = y; }
	void setNumFrames(int numf) { numFrames = numf; }
	void setNumBits(int numb) { numBits = numb; }
	void setADC_Min_Count(int minc) { aDC_Min_Count = minc; }
	void setChanNum(int n) { chanNum = n; }
	void setNumChans(int n) { numChans = n; }
	void setMag(char m[]) { memcpy(mag,m,64*sizeof(char));}
	void setXMinV(float minV) { xMinV = minV; }
	void setXMaxV(float maxV) { xMaxV = maxV; }
	void setYMinV(float minV) { yMinV = minV; }
	void setYMaxV(float maxV) { yMaxV = maxV; }
	void setZPos(float z) { zPos = z; }
	void setXPos(float x) { xPos = x; }
	void setYPos(float y) { yPos = y; }
	void setADC_Min_Voltage(float minV) { aDC_Min_Voltage = minV; }
	void setADC_Max_Voltage(float maxV) { aDC_Max_Voltage = maxV; }
	void setLineRate(float rate) { lineRate = rate; }
	void setLineLength(float len) { lineLength = len; }
	void setObjScaling(float scale) { objScaling = scale; }
	void setLsX1(int coord) { lsX1 = coord;	}
	void setLsX2(int coord) { lsX2 = coord;	}
	void setLsY1(int coord) { lsY1 = coord;	}
	void setLsY2(int coord) { lsY2 = coord;	}
	void setNumSampsTotal(int num) { numSampsTotal = num; }
	void setNumSampsTotal_LS(int num) { numSampsTotal_LS = num; }
	void setOverscan(int num) { overscan = num; }
	void setOverscanLS(int num) { overscan_LS = num; }
	void setLinescan(int lscan) { linescan = lscan; }
	void setLinescanRate(float rate) { linescanRate = rate; }
	void setAomCtrlVoltage(float volts) { aomCtrlVolt = volts; }

private:
	int linescan,numSampsTotal,numSampsTotal_LS;
	int overscan, overscan_LS;
	float version;
	bool b3DAcq;
	int numX, numY;
	int validX, validY;
	int numFrames, numBits;
	int chanNum, numChans;
	int aDC_Min_Count;
	float aDC_Min_Voltage, aDC_Max_Voltage;
	char mag[64];
	float xMinV, xMaxV, yMinV, yMaxV;
	float xPos, yPos, zPos;
	float lineRate, lineLength, objScaling;
	float linescanRate;
	int lsX1,lsX2,lsY1,lsY2;
	float aomCtrlVolt;

	// static members, constants
	static const int F_Name_Size = 1024;
	static const int Header_Size = 512;
	static const int numBytesPerDatum = 2;
	static const unsigned char padding = 0x0;
	//static const char formatSpec[]  = "&Y-%m-%d_%H_%M_%S";	//NEED IMPLEMENTATION
	//static const char suffix[] = ".dat";
};

class DataFile2P
{
public:

	//header member
	Header2P Header;

	//constructors
	DataFile2P(long minCount,long maxCount, int adcNumBits,float versionNumber);
	
	//destructor
	~DataFile2P();
	
	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	int ConvertF64ToFloat(double inData[], float outData[], int numPxls);
	int WriteTheData(int chanNum,AcqEngine* acqStruct);
	int GenFileName(int chanNum);
	int CreateChanDir(int chanNum);
	
	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	char *getFileName() { return FileName; } 
	char *getOutputDir() { return outputDir; }
	
	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	//void setFileName(char* name) { FileName = name; }
	void setOutputDir(char dir[]) { memcpy(outputDir,dir,1024*sizeof(char)); }		
	void setPtrData(short* data) { PtrData = data; }

	
private:

	//static const char formatSpec[] = "&Y-%m-%d_%H_%M_%S";		//NEED IMPLEMENTATION
	//static const char suffix[] = ".dat";

	char FileName[F_NAME_SIZE];
	char outputDir[F_NAME_SIZE];
	short* PtrData;

	long Min_Count;
	long Max_Count;
	int ADC_Num_Bits;
	float Version_Number;

};

#endif
