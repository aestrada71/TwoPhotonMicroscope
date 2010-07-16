/*	Name: stepperDriver.h
	Description: Stepper Motor Controls for Two Photon
	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	2/16/2009		
	Updated:
*/ 



#include "VxmDriver.h"

#ifndef STEPPERDRIVER_H
#define STEPPERDRIVER_H

class stepperDriver
{

public:
	//constructor
	stepperDriver();
	//destructor
	~stepperDriver();
	
	//modifiers
	void setPort(int pt) { Port = pt; }

	//stepper motor operational functions
	int LoadVXMDriver();
	int MoveUp();
	int MoveDown();
	int MoveLeft();
	int MoveRight();
	int CloseVXM();
	int GetXPos();
	int GetYPos();
	int resetDriver();
	int showTerminal();
	int hideTerminal();
	int GotoPos(int x, int y);
	int MoveX(int steps);
	int MoveY(int steps);
	int resetCoords();
	int openSerialPort();
	int closeSerialPort();
	int WaitForVXM();
	double getXyStepsPerMicron();
private:
	int Port;								//Serial Port #
	int BaudRate;							//Serial Port Baud Rate
	int xCo;								//x and y coordinates
	int yCo;
	static const int BACKLASH_COMPENSATION_X=11;	//Number of steps to compensate when changing directions
	static const int BACKLASH_COMPENSATION_Y=11;	//Number of steps to compensate when changing directions
	int		iLastMoveX;						//Used to test if changing direction
	int		iLastMoveY;						//Used to test if changing direction
	double	Num_XYSteps_Per_Micron;			//On fine focus knob

};

#endif
