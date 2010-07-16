/*	Name: zStepDriver.h
	Description: Z Stepper Motor Controls for Two Photon
	Written by: Alex Greis, Graham Miller, Arnold Estrada
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	2/18/2009		
	Updated:
*/ 


/*
#include <userint.h>
#include <utility.h>
#include <ansi_c.h>
#include <rs232.h>
#include <cvirte.h>	

*/
#ifndef __ZSTEPPERDRIVER_H
#define __ZSTEPPERDRIVER_H

class zStepperDriver
{
public:

	//constructor
	zStepperDriver();

	//destructor
	~zStepperDriver();

	//Accessors
	bool getInitialized() {	return initialized;	}
	bool getBTorqueOn()	{ return bTorqueOn;	}
	int getStepMode() { return stepMode; }
	double getCurrentZPos() { return currentZPos; }
	double getDesiredZPos()	{ return desiredZPos; }
	double getStepSize() { return stepSize; }
	double getHalfStepConvFactor() { return halfStepConvFactor; }
	double getFullStepConvFactor() { return fullStepConvFactor; }
	double getCurrentStepConvFactor() { return currentStepConvFactor; }

	//Modifiers
	void setInitialized(bool init) { initialized = init; }
	void setBTorqueOn(bool torqueOn)	{  bTorqueOn = torqueOn; }
	void setStepMode(int mode) { stepMode = mode; }
	void setCurrentZPos(double pos) { currentZPos = pos; }
	void setDesiredZPos(double pos)	{ desiredZPos = pos; }
	void setStepSize(double size) { stepSize = size; }
	void setHalfStepConvFactor(double factor) { halfStepConvFactor = factor; }
	void setFullStepConvFactor(double factor) { fullStepConvFactor = factor; }
	void setCurrentStepConvFactor(double factor) { currentStepConvFactor = factor; }
	void setPort(int pt) { port = pt; }
	void setPrevPort(int pt) { prevPort = pt; }


	//Member functions
	int Init();
	int OpenPort();
	void MoveTo(double zPos, double convFactor);
	void Offset(double zStep, double convFactor);
	double ReadPos(double convFactor);
	int ToggleTorque();
	int SetTorque(int mode);
	int SetStepMode(int stepMode);

private:
	
	int				port;
	int				prevPort;
	bool			initialized;
	bool			bTorqueOn;
	int				stepMode;			//0=half step, 1 = full step, 2=wave mode
	double			currentZPos;
	double			desiredZPos;
	double			stepSize;
	double			halfStepConvFactor;			//um / step
	double			fullStepConvFactor;
	double			currentStepConvFactor;

};
#endif
