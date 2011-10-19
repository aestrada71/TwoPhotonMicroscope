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

#include <time.h>
#include <Windows.h>
#include <string.h>
#include "NIDAQmx.h"
#include <direct.h>

#include "acqengine.h"
#include "2pdata.h"
#include "stdlib.h"
#include "stdio.h"
#include "QtGui"


//_____Global Constants____________________________________________________________________________	
const int			Header_Size = 512;			//bytes
const int			numBytesPerDatum = 2;		//short 
const unsigned char padding = 0x0;
const char			suffix[] = ".dat";
//const char		outputDir[] = "c:\\Data\\";

//_________________________________________________________________________________________________


//constructor
Header2P::Header2P()
{
}	

Header2P::~Header2P()
{
	//destructor
}

//default constructor
DataFile2P::DataFile2P(long minCount,long maxCount, int adcNumBits,float versionNumber)
{
	int i;
	char tempStr[64];

	Min_Count = minCount;
	Max_Count = maxCount;
	ADC_Num_Bits = adcNumBits;
	Version_Number = versionNumber;
	strcpy(outputDir,"c:\\Data\\");

	//initialize mag string
	for (i=0;i<64;i++)
		tempStr[i] = ' ';
	Header.setMag(tempStr);

}
//deconstructor
DataFile2P::~DataFile2P()
{
	//definition
}
//Create directories for specified channel
//Returns 1 for success, 0 for failure
int DataFile2P::CreateChanDir(int chanNum)
{
	char		dir[100];
	char		chanBuff[5];
	
	
	//Format channel buffer to separate files into different channel folders
	sprintf(chanBuff,"Ch%d",chanNum);
	strcat(chanBuff,"\\");

	//Create directory string
	strcpy(dir, outputDir);
	strcat(dir,chanBuff);


	//CreateDirectory
	if(mkdir(dir))
		return 1;
	else
		return 0;

}
// -Sep 1 2010: Added ms resolution to file name.  Simplified code to create name.  -ADE
int DataFile2P::GenFileName(int chanNum)
{
        char		temp[120];
	char		temp2[50];
	char		temp3[10];
	char		chanBuff[5];
        SYSTEMTIME      st;                                   //Added for millisecond time in filenames
	int			tempZPos;
	
	//Erase previous file name.
	FileName[0] = '\0';

	// Create name based off default dir and time and date.
        GetLocalTime(&st);
        sprintf(temp,"%04i-%02i-%02i_%02i_%02i_%02i_%03ims",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond,(int)(st.wMilliseconds));

        sprintf(temp3, "_Chan_%d" ,chanNum);
        strcat(temp, temp3);

	//Add zpos to filename if 3D Acq.
	if (Header.getB3DAcq())
	{
		tempZPos = (int)(Header.getZPos() + 0.5);		//Round to nearest int value
		sprintf(temp2, "_Z_%d_um", tempZPos);
		strcat(temp,temp2);
	}
	
	//Format channel buffer to separate files into different channel folders
	sprintf(chanBuff,"Ch%d",chanNum);
	strcat(chanBuff,"\\");

	//Create name string
	strcpy(FileName, outputDir);
	strcat(FileName,chanBuff);
	strcat(temp, suffix);
	strcat(FileName, temp);

	return 1;
}

int DataFile2P::ConvertF64ToFloat(double inData[], float outData[], int numPxls)
{
	int ii; 

	for (ii=0;ii<numPxls;ii++)
	{
		outData[ii] = (float)(inData[ii]);
	}


	return 0;
}

// Caller passes in data array, and this func creates file and writes contents.
// This function assumes data is of type float.
//
// -Sept 29 06.  ADE.  Now storing values related to magnification in header.  Also making header always be 512 bytes.
// -Feb 18 2008.  ADE.  Updated to handle data from two PMTs.
// -Feb 21 2008.  APG.  Updated to handle linescan parameters.
int DataFile2P::WriteTheData(int chanNum,AcqEngine* acqStruct)
{
	
	FILE			*fpFile;
	
	char			tempStr[15];
	int				numBytesWritten = 0;
	int				headerCounter;
	unsigned long	shiftToNextChannel;
	unsigned long	index;
	float tempFloat;
	int	  tempInt;

	if ((Header.getNumChans() == 2)&&(chanNum == 2))
		shiftToNextChannel = Header.getNumX() * Header.getNumY() * Header.getNumFrames();
	else
		shiftToNextChannel = 0;

	Header.setChanNum(chanNum);

	// update file name field of struct based on default dir and time and date and zpos.
	this->GenFileName(chanNum);
	//create directory for channel (stdio cannot create directories, depends on os)
	this->CreateChanDir(chanNum);
	
	//open file for writing
	fpFile = fopen(FileName,"wb");
	if (!fpFile) 
	{
		QMessageBox::about(0,"File IO Error","Could not create output file.");
		return 0;
	}
	// Write in some header info
	
	//sprintf(outBuff,"%f",Header.getVersion());
	//fwrite(outBuff,sizeof(outBuff),1,fpFile);

	tempFloat = Header.getVersion();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	fwrite(&Header_Size,sizeof(Header_Size),1,fpFile);
	numBytesWritten += sizeof(Header_Size);

	fwrite(&numBytesPerDatum,sizeof(numBytesPerDatum),1,fpFile);
	numBytesWritten += sizeof(numBytesPerDatum);
	
	tempInt = Header.getNumX();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);
	
	tempInt = Header.getNumY();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempInt = Header.getNumFrames();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempInt = Header.getValidX();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);
	
	tempInt = Header.getValidY();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);
	
	//always write 64 bytes
	fwrite(Header.getMag(),sizeof(char),64,fpFile);
	numBytesWritten += 64*sizeof(char);
	
	tempFloat = Header.getXMinV();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);
	
	tempFloat = Header.getXMaxV();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);
	
	tempFloat = Header.getYMinV();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);
	
	tempFloat = Header.getYMaxV();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getZPos();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getXPos();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getYPos();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getADC_Min_Voltage();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getADC_Max_Voltage();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempInt = Header.getNumBits();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);
	
	tempInt = Header.getADC_Min_Count();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	//fwrite(&(hdr.ZStep),sizeof(hdr.ZStep),1,fpFile);
	//numBytesWritten += sizeof(hdr.ZStep);

	tempFloat = Header.getLineRate();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempFloat = Header.getLineLength();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);
	
	tempFloat = Header.getObjScaling();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	tempInt = Header.getLsX1();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempInt = Header.getLsY1();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempInt = Header.getLsX2();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempInt = Header.getLsY2();
	fwrite(&(tempInt),sizeof(tempInt),1,fpFile);
	numBytesWritten += sizeof(tempInt);

	tempFloat = Header.getAomCtrlVoltage();
	fwrite(&(tempFloat),sizeof(tempFloat),1,fpFile);
	numBytesWritten += sizeof(tempFloat);

	
	for(headerCounter = numBytesWritten+1; headerCounter <= Header_Size; headerCounter++)
		fwrite(&padding,sizeof(padding),1,fpFile);
	
	
	// Now write the data.
//	fwrite(dataFile.PtrData + shiftToNextChannel ,numBytesPerDatum,
//												(hdr.NumFrames * hdr.NumX * hdr.NumY),fpFile);
	unsigned long overScan, numSampsTot;

	if (acqStruct->getBLineScan())
	{
		overScan = acqStruct->getOverscan_LS();
		numSampsTot = acqStruct->getNumSampsTotal_LS();
	}
	else
	{	
		overScan = acqStruct->getOverscan();
		numSampsTot = acqStruct->getNumSampsTotal();
	}

	for(long frameNum = 0; frameNum < Header.getNumFrames(); frameNum++)
	{
		for (long y = 0; y < Header.getValidY(); y++)
		{
                        for(long x = acqStruct->getXOffset()+ overScan; x < Header.getValidX() + acqStruct->getXOffset() + overScan; x++)		//CHANGE
			{
				index = x + (Header.getNumX() * y) + (Header.getNumX() * Header.getNumY() * frameNum);
				index += shiftToNextChannel;
				if (index >= (numSampsTot * Header.getNumChans()))		
					index = (numSampsTot * Header.getNumChans())-1;

				fwrite(PtrData + index ,numBytesPerDatum,1,fpFile);  //Write data one samp at a time
			}
		}
	}
	
	fclose(fpFile); 

	
	return 1;
}


