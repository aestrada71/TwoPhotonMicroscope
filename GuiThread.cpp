/*	Name: GuiThread.cpp
	Description: Provides multithreaded support GUI updates dependant on TwoPhotonThread.
		Necessary because TwoPhotonThread does not have access to the GUI widgets

	Written by: Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712
	
	Created:	1/28/2009
	Updated:	
*/ 

#include <QThread>
#include <QObject>
#include "TwoPhotonGui.h"
#include "GuiThread.h"

//Function: Constructor
//Description: initiates pointer to GUI object
GuiThread::GuiThread(TwoPhotonGui *tPGui)
{
	gui = tPGui;
	runLastCycle = false;
}

//Function: Destructor
//Description: 
GuiThread::~GuiThread()
{}
//Function: run
//Description: checks for global vars bRunning, sRunning, aRunning and updates gui as needed
void GuiThread::run()
{
	int temp;

	while(true)
	{
		updateVars();

		if(sRunning == true)
			emit incScanBar();
		else
			emit clearScanBar();

		if(aRunning == true)
			emit incAcqBar();
		else
			emit clearAcqBar();

		//if scan routine just ended
		if((bRunning == false) && (runLastCycle == true))
		{
			emit unlockGuiWidgets();
		}
		runLastCycle = bRunning;

		msleep(80);
	}
}
//Function: updateVars
//Description: synchronize gui indicator vars
void GuiThread::updateVars()
{
	bRunning = gui->getBRunning();
	sRunning = gui->getSRunning();
	aRunning = gui->getARunning();
}

