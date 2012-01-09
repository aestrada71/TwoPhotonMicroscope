/*	Name: stepperDriver.cpp
	Description: Stepper Motor Controls for Two Photon
	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	2/16/2009		
	Updated:
*/ 



//Stage Panning routine
//Written by: Alex Greis 8/27/2007
//Last Updated 11/26/2007
//Last update 06/30/2010 -ADE

#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "VxmDriver.h"
#include "stepperDriver.h"
#include <tchar.h>

//Constructor
stepperDriver::stepperDriver()
{
	Port = 2;											//Serial Port #
	BaudRate = 9600;									//Serial Port Baud Rate
	xCo=0;												//x and y coordinates
	yCo=0;
	iLastMoveX = 0;										
	iLastMoveY = 0;										
	Num_XYSteps_Per_Micron = 0.6333;					
}

//Destructor
stepperDriver::~stepperDriver()
{

}

//Load VXM Driver - Load VXM driver into memory
//Input: None
int stepperDriver::LoadVXMDriver()
{

	int temp = LoadDriver(L"..\\Libraries\\VXM_Stepper\\VxmDriver.dll"); //Location of driver relative to exe.

//	int temp = LoadDriver(L".\\VxmDriver.dll"); //Location of driver needed in project ex.  ".\\VxmDriver.dll"
	return temp;
}
//Serial Port Open - Open Serial Port Connection to the VXM
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::openSerialPort()	
{
	 int temp = PortOpen(Port, BaudRate);
	 return temp;
}
//Serial Port Close - Closes Serial Port Connection with VXM
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::closeSerialPort()
{
	 int temp = PortClose();
	 return temp;
}
//Wait for VXM - Waits for the VXM to finish executing program before code continues to execute
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::WaitForVXM()
{
	int temp =  PortWaitForChar("^",0); 
	//"^" is the completion character returned from VXM, 0 is the timeout time in milliseconds (0 indicates timeout disabled)
	return temp;
}
//Close VXM Drivers
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::CloseVXM()
{
DriverTerminalShowState(0,0);
ReleaseDriver();
return 0;
}
//Get Y position
//Input: none
//Output: motor 2 Position (y coordinate)
int stepperDriver::GetYPos()
{
	/*int y;
	y = MotorPosition(1);	//NOTE: The motor position is relative to the starting position at power-on
	return y;
	*/
	return yCo;
}
//Get X position
//Input: none
//Output: motor 2 Position (x coordinate)
int stepperDriver::GetXPos()
{
	/*int position;
	char* x;
	x = MotorPosition(2);	//NOTE: The motor position is relative to the starting position at power-on
	printf("%s\n",x);
	//position = atoi(x);
	//return position;
	return 0;
	*/
	return xCo;
}
//Reset Coords - Marks current location as origin
//Input: None
//Output: None
int stepperDriver::resetCoords()
{
	xCo=0;
	yCo=0;
	return 0;
}
//Reset Driver Functions - In case of lock up
//Input: None
//Output: None
int stepperDriver::resetDriver()
{
	DriverResetFunctions();
	return 0;
}
//Show Driver Terminal 
//Input: None
//Output: None
int stepperDriver::showTerminal()
{
	DriverTerminalShowState(1,0);
	return 0;
}
//Hide Driver Terminal 
//Input: None
//Output: None
int stepperDriver::hideTerminal()
{
	DriverTerminalShowState(0,0);
	return 0;
}
//Hide getXyStepsPerMicron 
//Input: None
//Output: numXY Steps per micron
double stepperDriver::getXyStepsPerMicron()
{
	return Num_XYSteps_Per_Micron;
}

//-----------------------------------------------------------------------------------------------------------------
//--------------Movement Functions---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

//Goto Coordinates - Goes to coordinates specified by input
//Input: coordinates in x,y format (int)
//Output: None
int stepperDriver::GotoPos(int x, int y)
{	
	int temp = 0;

	//Calculate X difference and travel X coordinates
	int current = GetXPos();
	x = x - current;
	temp = MoveX(x);

	//Calculate Y difference and travel Y coordinates
	current = GetYPos();
	y = y - current;
	temp = MoveY(y);
	
	return 0;
}

//Move Y - Move Y axis motor variable steps
//Input: Number of Steps
//Output: 0 for failure, 1 for success
//	2010/06/30:	Added backlash compensation when stepper turns around -ADE
int stepperDriver::MoveY(int steps)
{
	int temp;		//Added to handle backlash compensation when stepper changes direciton
	temp = steps;

	//Check if stepper is changing directions.  If so compensate for backlash in motors.
	if ((iLastMoveY * steps)<0)
	{
		
		if (steps < 0)
			temp = steps - BACKLASH_COMPENSATION_Y;
		else
			temp = steps + BACKLASH_COMPENSATION_Y;
	}
	iLastMoveY = steps;
	
	//Build command string
	char command[25] = "F,C,I2M";

	char buf[10];
        itoa(temp,buf,10);	//convert steps to buffer string
	strcat(command,buf);	//append amount of steps to string
	strcat(command,",R");	//append run component of command

	//Output to Port
	
	openSerialPort();
	PortSendCommands(command);
	WaitForVXM();
	closeSerialPort();

	xCo-=steps;
	return 0;
}
//Move X - Move X axis motor variable steps
//Input: Number of Steps
//Output: 0 for failure, 1 for success
//	2010/06/30:	Added backlash compensation when stepper turns around -ADE
int stepperDriver::MoveX(int steps)
{
	int temp;		//Added to handle backlash compensation when stepper changes direciton
	steps = -steps; //Axis is inverted with hardware setup
	temp = steps;

	//Check if stepper is changing directions.  If so compensate for backlash in motors.
	if ((iLastMoveX * steps)<0)
	{
		
		if (steps < 0)
			temp = steps - BACKLASH_COMPENSATION_X;
		else
			temp = steps + BACKLASH_COMPENSATION_X;
	}
	iLastMoveX = steps;
		
	//Build command string
	char command[25] = "F,C,I1M";
	
	char buf[10];
	itoa(temp,buf,10);		//convert steps to buffer string
	strcat(command,buf);	//append amount of steps to string
	strcat(command,",R");	//append run component of command
	
	//Output to Port
	
	openSerialPort();
	PortSendCommands(command);
	WaitForVXM();
	closeSerialPort();

	yCo+=steps;
	return 0;
}
//Move Left - Move Motor 1 +1000 steps (goes in the -x direction due to hardware setup)
//Input: None
//Output: 0 for failure, 1 for success
//Note: This command sent is a program for the VXM contoller, F enables online mode w/o echo, C clears previous programs
// I1M50 follows the syntax ImMx where m is the motor# and x is the number of steps, R runs the program
int stepperDriver::MoveLeft()
{
	int temp = openSerialPort();		//add error code if needed
	temp = PortSendCommands("F,C,I1M1000,R"); //Move Motor 1 +5 steps
	temp = WaitForVXM();					//Wait for VMX program to finish
	temp = closeSerialPort();

	xCo-=1000;
	return temp;
}
//Move Right - Move Motor 1 -1000 steps (goes in +x direction due to hardware setup)
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::MoveRight()
{
	int temp = openSerialPort();		//add error code if needed
	temp = PortSendCommands("F,C,I1M-1000,R"); //Move Motor 1 -5 steps
	temp = WaitForVXM();					//Wait for VMX program to finish
	temp = closeSerialPort();

	xCo+=1000;
	return temp;
}
//Move Down - Move Motor 2 -1000 steps
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::MoveDown()
{
	int temp = openSerialPort();		//add error code if needed
	temp = PortSendCommands("F,C,I2M-1000,R"); //Move Motor 2 -5 steps
	temp = WaitForVXM();					//Wait for VMX program to finish
	temp = closeSerialPort();

	yCo-=1000;
	return temp;
}
//Move Up - Move Motor 2 +1000 steps
//Input: None
//Output: 0 for failure, 1 for success
int stepperDriver::MoveUp() 
{
	int temp = openSerialPort();		//add error code if needed
	temp = PortSendCommands("F,C,I2M1000,R"); //Move Motor 2 +5 steps
	temp = WaitForVXM();					//Wait for VMX program to finish
	temp = closeSerialPort();

	yCo+=1000;
	return temp;
}



