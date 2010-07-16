/*	Name: lifetimeacq.cpp
	Description: Lifetime Acquisition Controls for Two Photon
	Written by: Arnold Estrada, Alex Greis
	
	Functional Optical Imaging Laboratory
	Department of Biomedical Engineering
	University of Texas at Austin
	Austin, TX 78712

	Created:	9/18/2008		Begun moving software to C++ and QT gui
	Updated:
*/ 

#include "lifetimeacq.h"
#include "scanengine.h"
#include "NIDAQmx.h"
#include "stdio.h"

// static members, constants
const bool LifetimeAcq::VERBOSE = false;
const double LifetimeAcq::ACQMIN = -5;
const double LifetimeAcq::ACQMAX = 5;
const double LifetimeAcq::SAMP_RATE = 1e6;
const double LifetimeAcq::DURATION = 1.5e-3;
const int LifetimeAcq::NUM_TRIGS = 2000;
const char LifetimeAcq::ACQ_CHANNEL[] = "Dev1/ai0";
const char LifetimeAcq::SAMPCLK_CHANNEL[] = "/Dev1/Ctr0InternalOutput";
const char LifetimeAcq::COUNTER_CHANNEL[] = "/Dev1/ctr0";
const char LifetimeAcq::TRIG_CHANNEL[] = "/Dev1/PFIO";
//const char LifetimeAcq::FILE_NAME[] = "C:/TestData.dat";
const unsigned char LifetimeAcq::padding = 0x0;
const int LifetimeAcq::Header_Size = 512;
const int LifetimeAcq::numBytesPerDatumLT = 8;
	
// global variables
TaskHandle LifetimeAcq::acqTaskHandle = 0;
TaskHandle LifetimeAcq::ctrTaskHandle = 0;
TaskHandle LifetimeAcq::aoTaskHandle = 0;
int32* LifetimeAcq::numSampsWritten;
long LifetimeAcq::numSamps = long(SAMP_RATE * DURATION);
unsigned int LifetimeAcq::totSamps = unsigned int(numSamps * NUM_TRIGS);

// default constructor
LifetimeAcq::LifetimeAcq()
{
	// definition
}

// copy constructor
LifetimeAcq::LifetimeAcq(const LifetimeAcq& life)
{
	// definition
}

// destructor
LifetimeAcq::~LifetimeAcq()
{
	// definition
}

// from ConfigDAQmxTasks(float xVolts, float yVolts, ScanStructure scanStructure);
int LifetimeAcq::configDAQmxTasks(float xVolts, float yVolts, ScanEngine* scanStruct)
{
	int				error;
	int				retVal;
	char			errBuff[2048];
	double			voltagePair[2];
	//extern Trig_Channel;
	
	voltagePair[0] = (double)xVolts;
	voltagePair[1] = (double)yVolts;
	//_____DAQmx Configure Code________________________________________________________________
	
	
	
	//_____Setup analog output task_____
	DAQmxErrChk (DAQmxCreateTask("AnalogOuput",&aoTaskHandle));
	DAQmxErrChk (DAQmxCreateAOVoltageChan (aoTaskHandle, scanStruct->getXChan(), "xChan", 
						-2.0, 2.0, DAQmx_Val_Volts, NULL));
	DAQmxErrChk (DAQmxCreateAOVoltageChan (aoTaskHandle, scanStruct->getYChan(), "yChan", 
						-2.0, 2.0, DAQmx_Val_Volts, NULL));
	DAQmxErrChk (DAQmxWriteAnalogF64 (aoTaskHandle, 1, 1, 10, DAQmx_Val_GroupByChannel, 
						voltagePair, DAQmx_Val_GroupByChannel, NULL));
	
	
	//_____Setup Analog input task_____
	DAQmxErrChk (DAQmxCreateTask("TrigAcq",&acqTaskHandle));
	
	/*Add analog input channel to acqtask*/
	DAQmxErrChk (DAQmxCreateAIVoltageChan(acqTaskHandle, ACQ_CHANNEL, "PMT", 
						DAQmx_Val_RSE,ACQMIN, ACQMAX, DAQmx_Val_Volts,NULL));

	/*config analog input to use counter output as sample clock and continuous samps*/
	DAQmxErrChk (DAQmxCfgSampClkTiming (acqTaskHandle, SAMPCLK_CHANNEL, SAMP_RATE, 
		DAQmx_Val_Rising, DAQmx_Val_ContSamps, totSamps));

	/*Make buffer size slightly larger than default*/
	DAQmxErrChk (DAQmxSetBufferAttribute (acqTaskHandle, DAQmx_Buf_Input_BufSize, totSamps+1000));
	
	//_____Setup counter task_____
	DAQmxErrChk (DAQmxCreateTask ("couterOutTask", &ctrTaskHandle));
	/*Add counter clock to counter task*/
	DAQmxErrChk (DAQmxCreateCOPulseChanFreq (ctrTaskHandle, COUNTER_CHANNEL, "coChannel", 
					DAQmx_Val_Hz,DAQmx_Val_Low, 0, SAMP_RATE, 0.5));
	
	/*config clock for counter output task to generate correct numSamps*/					
	DAQmxErrChk (DAQmxCfgImplicitTiming (ctrTaskHandle, DAQmx_Val_FiniteSamps, numSamps));

	/*Config triggering of counter task*/
	DAQmxErrChk (DAQmxCfgDigEdgeStartTrig (ctrTaskHandle, TRIG_CHANNEL, DAQmx_Val_Rising));
	DAQmxErrChk (DAQmxSetTrigAttribute (ctrTaskHandle, DAQmx_StartTrig_Retriggerable, TRUE));
	
	

	return 1;

Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);

	retVal = this->stopTasks();

	//if( DAQmxFailed(error) )
	//	MessagePopup("DAQmx Error",errBuff);

	return 0;
}

// from StopTasks();
int LifetimeAcq::stopTasks()
{
	
	//Stop Task;
	if( aoTaskHandle!=0 ) 
	{
		DAQmxStopTask(aoTaskHandle);
		DAQmxClearTask(aoTaskHandle);
		aoTaskHandle = 0; 
	}

	if( acqTaskHandle!=0 ) 
	{
		DAQmxStopTask(acqTaskHandle);
		DAQmxClearTask(acqTaskHandle);
		acqTaskHandle = 0; 
	}

	if( ctrTaskHandle!=0 ) 
	{
		DAQmxStopTask(ctrTaskHandle);
		DAQmxClearTask(ctrTaskHandle);
		ctrTaskHandle = 0; 
	}
	return 1;
}

// from WriteTheLTData(uInt32* data, char FILE_NAME[]);
int LifetimeAcq::writeTheLTAcqData(uInt32* data, char FILE_NAME[])
{
	FILE* 		fpFile=0;
	int			numBytesWritten = 0;
	int			headerCounter;
	size_t		numWritten;


	if ((fpFile = fopen(FILE_NAME,"wb")) == NULL) return 0;


	// Write in some header info
	fwrite(&Header_Size,sizeof(Header_Size),1,fpFile);
	numBytesWritten += sizeof(Header_Size);

	
	fwrite(&numBytesPerDatumLT,sizeof(numBytesPerDatumLT),1,fpFile);
	numBytesWritten += sizeof(numBytesPerDatumLT);
	
	fwrite(&(SAMP_RATE),sizeof(SAMP_RATE),1,fpFile);
	numBytesWritten += sizeof(SAMP_RATE);
	
	fwrite(&(totSamps),sizeof(totSamps),1,fpFile); 
	numBytesWritten += sizeof(totSamps);

	fwrite(&(numSamps),sizeof(numSamps),1,fpFile); 
	numBytesWritten += sizeof(numSamps);


	fwrite(&(NUM_TRIGS),sizeof(NUM_TRIGS),1,fpFile); 
	numBytesWritten += sizeof(NUM_TRIGS);

	// Fill the rest of the header with padding character
	for(headerCounter = numBytesWritten+1; headerCounter <= Header_Size; headerCounter++)
		fwrite(&padding,sizeof(padding),1,fpFile);

	// Write the actual data.
	numWritten = fwrite(data,sizeof(data[0]),totSamps,fpFile);
	
	fclose(fpFile);

	return 1;
}

// from LifetimeAcq(float xVolts, float yVolts, ScanStruct scanStructure, char FILE_NAME[]);
int LifetimeAcq::lifetimeAcq(float xVolts, float yVolts,ScanEngine* scanStruct, char FILE_NAME[])
{
	int				status = 0;
	int				error;
	long			sampsRead = 0;
	unsigned long	totRead = 0;
	char			errBuff[2048];
	double*			acqData;

	if (VERBOSE)
	{
		/*	
		cout << "Hit Enter to acquire " << NUM_TRIGS << " triggers of " << numSamps		//NEED IMPLEMENTATION
											<< " samples each. \n";
		cout << "Data will be written to " <<FILE_NAME << " (Hit enter to begin)";
		c = cin.get();
		cout << "\nAcquiring...";
		*/
	}
	acqData = new double[totSamps];


	status = this->configDAQmxTasks(xVolts, yVolts, scanStruct);
	
	
	//_____Start the tasks_____
	DAQmxStartTask(aoTaskHandle);
	DAQmxStartTask(acqTaskHandle);
	DAQmxStartTask(ctrTaskHandle);

	

	//_____Perform read_____
	while( totRead < totSamps )
	{
		DAQmxErrChk (DAQmxReadAnalogF64(acqTaskHandle,totSamps,-1,DAQmx_Val_GroupByScanNumber,
						acqData,totSamps,&sampsRead,NULL));

		if( sampsRead > 0 )
		{
			totRead += sampsRead;
			//cout << "Acquired "<< totRead << " samples.\n";
		}
	}


	

//status = WriteTheLTAcqData( acqData, FILE_NAME);
	status =this->stopTasks();
	delete [] acqData;
	acqData = NULL;
	if (VERBOSE)
	{
		/*																			NEED IMPLEMENTATION
		cout << "\nAcquired " << totSamps << " samples. (Hit enter to end)";
		c = cin.get();
		*/
	}
		return 1;

Error:
	if (acqData)
	{
		delete [] acqData;
		acqData = NULL;
	}
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);


	status = this->stopTasks();


	if( DAQmxFailed(error) )
	{
		/*
		cout << "DAQmx Error: "<<errBuff << "\n";				NEED IMPLEMENTATION
		c = cin.get();
		*/
	}
		return 0;

}
