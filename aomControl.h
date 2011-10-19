/*	Name: aomControl.h
	Description: AOM Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#include "NIDAQmx.h"
#include <fstream>
#include <cstdio>

#ifndef AOMCONTROL_H
#define AOMCONTROL_H

#define DAQmxErrChk(functionCall) { if( DAQmxFailed(error=(functionCall)) ) { goto Error; } }

class AomControl
{
public:
	//constructors
	AomControl();

	//destructor
	~AomControl();

	//----------------------------------------------------------------------------------------
	// Access Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	//TaskHandle getTaskHandle() { return AOMTaskHandle; }
	//TaskHandle getSmplClkTaskHandle(){ return AOMSmplClkTaskHandle; }	
	//TaskHandle getReTrigTaskHandle() { return AOMReTrigTaskHandle; }
	unsigned long getSizeArray() {  return sizeArray; }
	double	getSampRate() { return sampRate; }
	double	getAomMaxVoltage() { return AomMaxVoltage; }
	double	getAomMinVoltage() { return AomMinVoltage; }
	double  getAomVoltage() { return AOMVoltage; }
	double	getAomRefOutVoltage() {return AOMRefOutVoltage; }
//	float	getXVolts() { return xVolts; }
//	float   getYVolts() { return yVolts; }
//	char*	getGalvoXChan() { return GalvoXChan; }
//	char*	getGavloYChan() { return GalvoYChan; }
	char   *getAomChan() { return AOMChan; }
	char*	getAomRefOutChan() { return AOMRefOutChan; }
	char*	getAomReTrigSampClkChan() { return AOMReTrigSampClkChan; }
	char*	getAomReTrigTrigChan() { return AOMReTrigTrigChan; }
	int		getPulseOnTime() { return PulseOnTime; }
	bool	getAomContinuous() { return bAOMContinuous; }
	bool	getAomPulsed() { return bAOMPulsed; }
	bool	getAomOn() { return bAOMOn; }
	bool	getInitialized() { return bInitialized; }
	double	getAomOnDuration() { return AOMOnDuration; }
	double	getAomPulseRepRate() { return AOMPulseRepRate; }
	bool	getBIntScaling() { return bIntScaling; }
	double	getIntensityScalingTopV() { return intensityScalingTopV; }
	double	getIntensityScalingBottomV() { return intensityScalingBottomV; }
	double  getAomOnVoltage() { return AOMOnVoltage; }
	
	double* getAomSigs() { return AOMSigs; }

	//----------------------------------------------------------------------------------------
	// Modifier Functions --------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	
	//void setAomTaskHandle(TaskHandle task) { AOMTaskHandle = task; }
	//void setAomSmplClkTaskHandle(TaskHandle task) { AOMSmplClkTaskHandle = task; }	
	//void setAomReTrigTaskHandle(TaskHandle task) { AOMReTrigTaskHandle = task; }
	void setSizeArray(unsigned long sArr) { sizeArray = sArr; }
	void setSampRate(double	rate) { sampRate = rate; }
	void setAomMaxVoltage(double voltage) {	AomMaxVoltage = voltage; }
	void setAomMinVoltage(double voltage) {	AomMinVoltage = voltage; }
	void setAomVoltage(double voltage) { AOMVoltage = voltage; }
	void setAOMRefOutVoltage(double voltage) { AOMRefOutVoltage = voltage; }
//	void setXVolts(float volts) { xVolts = volts; }
//	void setYVolts(float volts) { yVolts = volts; }
//	void setGalvoXChan(char* chan) { GalvoXChan = chan; }
//	void setGalvoYChan(char* chan) { GalvoYChan = chan; }
	void setAomChan(char chan[]) { memcpy(AOMChan,chan,256*sizeof(char));	}
	void setAomRefOutChan(char chan[]) {	memcpy(AOMRefOutChan,chan,256*sizeof(char)); }
	void setAomReTrigSampClkChan(char chan[]) {	memcpy(AOMReTrigSampClkChan,chan,256*sizeof(char)); }
	void setAomReTrigTrigChan(char chan[]) { memcpy(AOMReTrigTrigChan,chan,256*sizeof(char)); }
	void setPulseOnTime(int time) { PulseOnTime = time; }
	void setAomContinuous(bool cont) {	bAOMContinuous = cont; }
	void setAomPulsed(bool pulsed) { bAOMPulsed = pulsed; }
	void setAomOn(bool on) { bAOMOn = on; }
	void setInitialized(bool initialized) { bInitialized = initialized; }
	void setAomOnDuration(double dur) {	AOMOnDuration = dur; }
	void setAomPulseRepRate(double rate) { AOMPulseRepRate = rate; }
	void setbIntScaling(bool b) { bIntScaling = b; }
	void setIntScalingTopV(double volts) { intensityScalingTopV = volts; }
	void setIntScalingBottomV(double volts) { intensityScalingBottomV = volts; }

	void setAomSigs(double* sigs) { AOMSigs = sigs; }
//	void setAomRefSig(double* sig) { AOMRefSig = sig; }
	void setAomOnVoltage(double volts) { AOMOnVoltage = volts; }
	
	

	//----------------------------------------------------------------------------------------
	// Member Functions ----------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	int initAomCtrl();
	int startDAQmxTask();
	int stopDAQmxTask();
	int clearDAQmxTask();
	int configNiDAQ();
	int makeWaveform();
	int updateWaveform();
	int releaseMemory();

private:
	//static members, constants
	static const double		Aom_Max_Voltage; 
	static const double		Aom_Min_Voltage; 
	static const float		Aom_Sample_Rate; 
	static const char		AOM_RETRIG_SMPL_CLK_TERMINAL[];
	static const char		AOM_RETRIG_TRIG_TERMINAL[]; 
	static const char		AOM_RETRIG_SMPL_CLK_SOURCE[];
	static const char		AOM_RETRIG_TRIG_SOURCE[];

	//private members
		
	TaskHandle		AOMTaskHandle;
	TaskHandle		AOMSmplClkTaskHandle;	
	TaskHandle		AOMReTrigTaskHandle;		//Task to handle retriggerable AO generation.
	unsigned long    sizeArray;
	double	sampRate;
	double	AomMaxVoltage;
	double	AomMinVoltage;
	double  AOMVoltage;
	double  AOMOnVoltage;  //used to store aom on voltage during z-stacks when aomvoltage is set to zero
	double	AOMRefOutVoltage;
//	float	xVolts;
//	float   yVolts;
//	char	GalvoXChan[256];
//	char	GalvoYChan[256];
	char	AOMChan[256];
	char	AOMRefOutChan[256];
	char	AOMReTrigSampClkChan[256];
	char	AOMReTrigTrigChan[256];
	int		PulseOnTime;
	bool	bAOMContinuous;
	bool	bAOMPulsed;
	bool	bAOMOn;
	bool	bInitialized;
	double	AOMOnDuration;
	double	AOMPulseRepRate;
	
	double* AOMSigs;
	//double* AOMRefSig;

	bool	bIntScaling;
	double	intensityScalingTopV;
	double	intensityScalingBottomV;

};
#endif