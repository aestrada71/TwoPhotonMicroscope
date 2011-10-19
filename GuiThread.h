/*	Name: GuiThread.h
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

#ifndef GUITHREAD_H
#define GUITHREAD_H

class GuiThread : public QThread
{
	Q_OBJECT

public:
	//constructors
	GuiThread(TwoPhotonGui *tPGui);

	//destructors
	~GuiThread();

	//member functions
	void run();
	void updateVars();

signals:
	void incAcqBar();			//to increment the acq bar during acquisition
	void incScanBar();			//to increment the scan bar during scans
	void clearScanBar();		//to clear the scan bar when scanning is done
	void clearAcqBar();			//to clear the acq bar when acquisition is done
	void unlockGuiWidgets();	//to unlock gui widgets at the end of an acquisition routine

private:

	//members
	TwoPhotonGui *gui;

	bool	runLastCycle;	//indicates that the system was running last cycle (dependant on bRunning)

	bool 	bRunning;		//indicates that system is running
	bool	sRunning;		//indicates that scan is running
	bool	aRunning;		//indicates that acquisition is running

};
#endif