/*	Name: zStepDriver.c
	Description: Z Stepper Motor Controls for Two Photon
	Written by: Alex Greis, Graham Miller, Arnold Estrada
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	2/18/2009		
	Updated:
*/ 

#include "zStepDriver.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "rs232.h"
#include <iostream>

//NOTE: This class uses National Instruments CVI RS232 drivers



//_____Global Constants____________________________________________________________________________
const int		Default_Step_Mode = 1;				//0=half step, 1=full step, 2=wave step
const int		Num_Full_Steps_Per_Rev = 381;
const int		Num_Half_Steps_Per_Rev = 757;
const double	Num_Microns_Per_Rev = 100;			//On fine focus knob
const double	Num_Microns_Per_Full_Step = Num_Microns_Per_Rev / Num_Full_Steps_Per_Rev;
const double	Num_Microns_Per_Half_Step = Num_Microns_Per_Rev / Num_Half_Steps_Per_Rev;
//_________________________________________________________________________________________________

//Constructor
//Initializes hardware and software variables. Redundant for ZStepperInit
zStepperDriver::zStepperDriver()
{
	int			dummy=0;
//	double		prevPos;

	port = 1;
	prevPort = 1;
	

	fullStepConvFactor = Num_Microns_Per_Full_Step;		// microns/step
	halfStepConvFactor = Num_Microns_Per_Half_Step;
	stepMode = Default_Step_Mode;
	bTorqueOn = 1;

	//Try to init motor.
	if (!initialized)
		dummy =  OpenPort();
	
	if (dummy)
	{	
		//MessageBox();

		return;
	}

	dummy = SetTorque(1);
	if (dummy)
		bTorqueOn = true;

	SetStepMode(stepMode);

	switch (stepMode)
	{
		case 0:
			currentStepConvFactor = Num_Microns_Per_Half_Step;
			break;
		case 1:
			currentStepConvFactor = Num_Microns_Per_Full_Step;
			break;
		default:;
	}

	ReadPos(currentStepConvFactor);
	
}

//Destructor
zStepperDriver::~zStepperDriver()
{
}
//Init-------------------------------
//Initialize instance variables - redundant from constructor
//Input: None
//Ouput: success or error code
int zStepperDriver::Init()
{
	int			dummy=0;
//	double		prevPos;
	

	fullStepConvFactor = Num_Microns_Per_Full_Step;		// microns/step
	halfStepConvFactor = Num_Microns_Per_Half_Step;
	stepMode = Default_Step_Mode;
	bTorqueOn = 1;

	//Try to init motor.
	if (!initialized)
		dummy =  OpenPort();
	
	if (dummy!=0)
	{	
		//error opening port
		return 0;
	}

	dummy = SetTorque(1);
	if (dummy)
		bTorqueOn = true;

	SetStepMode(stepMode);

	switch (stepMode)
	{
		case 0:
			currentStepConvFactor = Num_Microns_Per_Half_Step;
			break;
		case 1:
			currentStepConvFactor = Num_Microns_Per_Full_Step;
			break;
		default:;
	}

	ReadPos(currentStepConvFactor);
	
	return 1;
}
//OpenPort-------------------------------
//Initialize COM port, make stepper motor's current position home (0)
//Input: None
//Ouput: RS232 error code
int zStepperDriver::OpenPort()
{
	int RS232Error;
	char out[5];
	char ptName[4];

	//Initialize comm port
	CloseCom(prevPort);
	
	sprintf(ptName,"COM%i ",port);
	
	RS232Error = OpenComConfig (port, ptName, 9600, 0, 8, 1, 512, 512);
	SetXMode (port, 0);
	SetCTSMode (port, 1); 
	SetComTime (port, 10);
	
	sprintf(out, "HM0\r");
	ComWrt(port, out, strlen(out));

	//set previous port as newly opened port
	prevPort = port;
	
	return RS232Error;
}
//MoveTo-------------------------------
//Move to absolute position
//Input: desired z position in um, relative to origin, converstion factor
//Ouput: none
void zStepperDriver::MoveTo(double zPos, double convFactor)
{
	
	char Str [15];
	char out [15];
	char in [15];
	int retVal = 0;
	int termCharVal = 13;
	int numSteps;

	//Calculate wait time
	//double stepWait = 0.010 * (zPos - ReadPos(convFactor)) ;  //In seconds

	//if(stepWait < 0)
	//	stepWait = -stepWait;

	//double waitTime = stepWait + .1;
	
	if(zPos > 0)
	{
		numSteps = (int) (zPos / convFactor + 0.5);
		numSteps += 0;		//Fudge factor
	}
	else
	{	
		numSteps = (int) (zPos / convFactor - 0.5);
		numSteps -= 0;		//Fudge factor
	}
	//Output command to RS232
	sprintf(Str, "MI%i\r", numSteps);
	ComWrt(port, Str, strlen(Str));
	Sleep(0.1*1000);		//*1000 because original value was for Delay function in CVI
//	retVal = FlushInQ (port);
//	Sleep(.5*1000);		//*1000 because original value was for Delay function in CVI
	//Sleep(waitTime*1000);		//*1000 because original value was for Delay function in CVI

	//Wait here until z has reached position
	int delta;
	int test;
	int count = 0;
	sprintf(out, "RT\r");
	do
	{
		
		retVal=ComWrt(port, out, strlen(out));
		Sleep(0.1*1000);		//*1000 because original value was for Delay function in CVI
		//ComRd (port, in, 5);
		retVal=ComRdTerm (port, in, 7, termCharVal);
		if (retVal > 0)
			in[retVal]='\0';
		Sleep(0.1*1000);		//*1000 because original value was for Delay function in CVI
		//printf("%s \n",in);
		//retVal = FlushOutQ (port);
		//Sleep(.5*1000);		//*1000 because original value was for Delay function in CVI
		//retVal=ComRdTerm (port, in, 7, termCharVal);
		//Sleep(.5*1000);		//*1000 because original value was for Delay function in CVI
		delta = atoi(in);
		test = abs(delta);
		sprintf(in,"");
		count++;
	} while(test > 4);


	ReadPos(convFactor);


}

//Offset-------------------------------
//Move by value specified by stepSize field.
//Input: zStep = distance, in um, to move (relative to current position)
//Ouput: none
void zStepperDriver::Offset(double zStep, double convFactor)
{
	char Str[15];
	int numSteps;
	
	//Calculate wait time
	double waitTime = .015 * zStep;
	
	if(waitTime < 0)
		waitTime = -waitTime;
	
	if(zStep > 0)
		numSteps = (int) (zStep / convFactor + 0.5);
	else
		numSteps = (int) (zStep / convFactor - 0.5);
	
	//Output command to RS232
	sprintf(Str, "II%i\r", numSteps);
	ComWrt(port, Str, strlen(Str));
	Sleep(waitTime*1000);		//*1000 because original value was for Delay function in CVI 

	ReadPos(currentStepConvFactor);
}
//ReadPos-------------------------------
//Report Position, save to member variables
//Input: none
//Ouput: motor position relative to origin in um
double zStepperDriver::ReadPos(double convFactor)
{

	char out [5];
	char in [15];
	int termCharVal = 13;
	int numBytesRead=0;
	double pos;

	//Output command to RS232

	sprintf(out, "RC\r");
	ComWrt(port, out, strlen(out));
	Sleep(.05*1000);		//*1000 because original value was for Delay function in CVI
	//ComRd (port, in, 11);
	numBytesRead = ComRdTerm (port, in, 11, termCharVal);
	if (numBytesRead > 0)
		in[numBytesRead]='\0';  //Add null terminator because sometimes there is random stuff in char array.
	pos = atoi(in);
	
	//if (getStepMode() ==0)
	//	pos = pos*2;

	pos = pos * convFactor;
	

	currentZPos = pos;
	return pos;

}
//ToggleTorque-------------------------------
//Set holding torque on/off
//Input: mode = 0 (off) or 1 (on)
//Ouput: 1 if successful, 0 if not
int zStepperDriver::ToggleTorque()
{
	int retVal;

	if (bTorqueOn)
	{
		retVal = SetTorque(1);
		//zStepDriver.bTorqueOn = false;

	}
	else
	{
		retVal = SetTorque(0);
		//zStepDriver.bTorqueOn = true;
	}
	return 1;
}
//SetTorque-------------------------------
//helper function for toggleZTorqueStruct
//Input: mode = 0 (off) or 1 (on)
//Ouput: 1 if successful, 0 if not
int zStepperDriver::SetTorque(int mode)
{

	char out[5];
	switch(mode)
	{
		case 0:
			sprintf(out, "SO\r");
			break;
		case 1:
			sprintf(out, "SP\r");
			break;
		default:
			//MessagePopup("Holding Torque Error", "Invalid torque mode specified.");
			return 0;
	}

	ComWrt(port, out, 3);
	return 1;
}
//SetStepMode-------------------------------
//Helper function for SetZStepperModeStruct
//Input: 0 (half-step), 1 (full step), or 2 (wave step)
//Ouput: 1 if successful, 0 if not
int zStepperDriver::SetStepMode(int stepperMode)
{

	char out[5];
	switch(stepperMode)
	{
		case 0:
			sprintf(out, "SH\r");
			break;
		case 1:
			sprintf(out, "SF\r");
			break;
		case 2:
			sprintf(out, "SW\r");
			break;
		default:
			//MessagePopup("Step Mode Error", "Invalid step mode specified.");
			return 0;		// Falls through to here if invalid input
	}

	ComWrt(port, out, 3);

	stepMode = stepperMode;

	return 1;

}
