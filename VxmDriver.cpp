// #include "stdafx.h" must appear in the top of each
// of these files or the fatal error C1010: unexpected 
// end of file while looking for precompiled header 
// directive will keep popping up

#include "stdafx.h"	
#include "windows.h"	// needed or code below will not work

//*** Move declarations to a header file when done ***
//long ShowForm(long ParentHwnd);

//-------------------------------------------------------------------------------------------------
//--------------------- Set up a struct to be used as the handle for the driver -------------------
//-------------------------------------------------------------------------------------------------
HINSTANCE HwndDriver;
HWND HwndDesktop;			//Desktop Hwnd

//-------------------------------------------------------------------------------------------------
//------------------ Define types as longs to be handles for each function called -----------------
//-------------------------------------------------------------------------------------------------
typedef long (CALLBACK* SHOWTERMINAL)(long ParentHwnd);					// Show Terminal
typedef long (CALLBACK* HIDETERMINAL)(void);					// Show Terminal
typedef long (CALLBACK* OPENPORT)(long PortNumber, long BaudRate);		//Open Port
typedef long (CALLBACK* ISPORTOPEN)(void);		//Is Port Open
typedef long (CALLBACK* CLOSEPORT)(void);		//Close Port
typedef long (CALLBACK* DRIVERSENDTOPORT)(char* CommandOut);		//Send commands to VXM
typedef char* (CALLBACK* READFROMPORT)(void);		//Read From Port
typedef long (CALLBACK* COUNTCHARSATPORT)(void);		//Count number of chars at the port
typedef long (CALLBACK* SEARCHFORCHARS)(char* CharsToFind);		//Search for matching chars
typedef long (CALLBACK* CLEARPORT)(void);		//Clear the port
typedef long (CALLBACK* REMOVEFROMPORT)(char* StringToRemove);		//Remove Chars From Port
typedef char* (CALLBACK* GETMOTORPOSITION)(long MotorNumber);		//Get Motor Position
typedef long (CALLBACK* WAITFORCHAR)(char* CharToWaitFor, long TimeOutTime);		//Wait for character
typedef long (CALLBACK* WAITFORCHARWITHMOTORPOSITION)(char* CharToWaitFor, long MotorNumber, long ReportToWindowHwnd, long TimeOutTime);		//Wait for character and get motor position while waiting
typedef void (CALLBACK* RESETDRIVER)(void);

//-------------------------------------------------------------------------------------------------
//----------------------- Set the type to be a pointer to the driver function ---------------------
//-------------------------------------------------------------------------------------------------
SHOWTERMINAL ShowTerminalSimple;
HIDETERMINAL HideTerminalSimple;
OPENPORT OpenPort;
ISPORTOPEN IsPortOpen;
CLOSEPORT ClosePort;
DRIVERSENDTOPORT DriverSendToPort;
READFROMPORT ReadFromPort;
COUNTCHARSATPORT CountCharsAtPort;
SEARCHFORCHARS SearchForChars;
CLEARPORT ClearPort;
REMOVEFROMPORT RemoveFromPort;
GETMOTORPOSITION GetMotorPosition;
WAITFORCHAR WaitForChar;
WAITFORCHARWITHMOTORPOSITION WaitForCharWithMotorPosition;
RESETDRIVER ResetDriver;

//-------------------------------------------------------------------------------------------------
//--------------------------------- Set up the driver functions -----------------------------------
//-------------------------------------------------------------------------------------------------

//--------------------------------- Load Driver Function Pointers ---------------------------------

long LoadDriver(LPCWSTR DriverPath)
{
	
	HwndDriver=LoadLibrary(DriverPath);									// Handle to the driver
	ShowTerminalSimple=(SHOWTERMINAL)GetProcAddress(HwndDriver,"ShowTerminalSimple");			// Show Terminal
	HideTerminalSimple=(HIDETERMINAL)GetProcAddress(HwndDriver,"HideTerminalSimple");			// Show Terminal
	OpenPort=(OPENPORT)GetProcAddress(HwndDriver, "OpenPort");		//Open Port
	IsPortOpen=(ISPORTOPEN)GetProcAddress(HwndDriver, "IsPortOpen");	//Is Port Open
	ClosePort=(CLOSEPORT)GetProcAddress(HwndDriver, "ClosePort");		//Close Port
//	ClosePort=(CLOSEPORT)GetProcAddress(HwndDriver, "CloseSerialPort");		//Close Port
	DriverSendToPort=(DRIVERSENDTOPORT)GetProcAddress(HwndDriver, "DriverSendToPort");		//Send Commands to port
	ReadFromPort=(READFROMPORT)GetProcAddress(HwndDriver, "ReadFromPort");		//Read From Port
	CountCharsAtPort=(COUNTCHARSATPORT)GetProcAddress(HwndDriver, "CountCharsAtPort");	//Count chars at port
	SearchForChars=(SEARCHFORCHARS)GetProcAddress(HwndDriver, "SearchForChars");		//Search for chars at port
	ClearPort=(CLEARPORT)GetProcAddress(HwndDriver, "ClearPort");						//Clear Port
	RemoveFromPort=(REMOVEFROMPORT)GetProcAddress(HwndDriver, "RemoveFromPort");		//Remove from port
	GetMotorPosition=(GETMOTORPOSITION)GetProcAddress(HwndDriver, "GetMotorPosition");		//Get motor position
	WaitForChar=(WAITFORCHAR)GetProcAddress(HwndDriver, "WaitForChar");		//Wait for char
	WaitForCharWithMotorPosition=(WAITFORCHARWITHMOTORPOSITION)GetProcAddress(HwndDriver, "WaitForCharWithMotorPosition");	//Wait for char with motor position
	ResetDriver=(RESETDRIVER)GetProcAddress(HwndDriver, "ResetDriver");		//Reset driver functions

//	char MyText;
//	long LenMyText;
//	LenMyText = 10;
//	ultoa(HideTerminalSimple, MyText, LenMyText);
//	AfxMessageBox(MyText);
	
	//HwndDesktop = GetDesktopWindow(); // Get desktop handle
//	ShowTerminalSimple(0);
return 1;
}

//--------------------------------- Release Driver Function Pointers -----------------------------
long ReleaseDriver()
{
	FreeLibrary(HwndDriver);
	return 1;
}

//--------------------------------- Show or Hide Driver Terminal ----------------------------------
long DriverTerminalShowState(long StateToShow, long ParentHwnd)
{
	if (StateToShow == 0)	//If told to hide terminal
	{
		if (HideTerminalSimple != 0)		//If function exists
		{
			return HideTerminalSimple();	//Call function
		}
		else		//Return failed call
		{
			return 0;
		}
	}
	else if (StateToShow == 1)	//If told to show terminal
	{
		if (ShowTerminalSimple != 0)	//If function exists
		{
			return ShowTerminalSimple(ParentHwnd);	//Call function
		}
		else	//Return failed call
		{
			return 0;
		}
	}
	else	//Return failed call
	{
		return 0;
	}
}

//--------------------------------- Open Port for Communications ----------------------------------
long PortOpen(long PortNumber, long BaudRate)
{
	if (PortNumber < 1)		//If invalid port
	{
		return 0;		//Return failed call
	}
	else if (PortNumber > 255)	//If invalid port
	{
		return 0;		//Return failed call
	}
	else	//If valid port
	{
		if (OpenPort != 0)	//If function exists
		{
			if (BaudRate == 9600)	//If valid baudrate
			{
				return OpenPort(PortNumber, BaudRate);	//Call function
			}
			else if (BaudRate == 19200)		//If valid baudrate
			{
				return OpenPort(PortNumber, BaudRate);	//Call function
			}
			else if (BaudRate == 38400)		//If valid baudrate
			{
				return OpenPort(PortNumber, BaudRate);	//Call function
			}
			else	//If invalid baudrate
			{
				return 0;	//Return failed call
			}
		}
		else	//If function doesnt exist
		{
			return 0;	//Return failed call
		}
	}
}

//------------------------------------- Check if Port is Open --------------------------------------------
long PortIsOpen(void)
{
	if (IsPortOpen != 0)	//If function exists
	{
		return IsPortOpen();	//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//----------------------------------------- Close Port ---------------------------------------------------
long PortClose(void)
{
	if (ClosePort != 0)		//If function exists
	{
		ClosePort();		//Call function
		return 1;
	}
	else
	{
		return 0;		//Return failed call
	}
}

//--------------------------------------- Send Commands to VXM -------------------------------------------
long PortSendCommands(char* CommandToSend)
{
	if (DriverSendToPort != 0)		//If function exists
	{
		if (CommandToSend != "")	//If there is a command to send
		{
			return DriverSendToPort(CommandToSend);	//Send the command
		}
		else
		{
			return 0;	//Return failed call
		}
	}
	else
	{
		return 0;	//Return failed call
	}
}

//--------------------------------------- Read Reply from VXM ---------------------------------------------
char* PortReadReply(void)
{
	if (ReadFromPort != 0)		//If function exists
	{
		return ReadFromPort();	//Call function
	}
	else
	{
		return 0;	//Return failed call
	}
}

//--------------------------------------- Count Chars At Port --------------------------------------------
long PortCountChars(void)
{
	if (CountCharsAtPort != 0)		//If function exists
	{
		return CountCharsAtPort();	//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//------------------------------------- Search for Chars at Port -----------------------------------------
long PortSearchForChars(char* CharsToFind)
{
	if (SearchForChars != 0)		//If function exists
	{
		return SearchForChars(CharsToFind);		//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//------------------------------------------- Clear Port ------------------------------------------------
long PortClear(void)
{
	if (ClearPort != 0)		//If function exists
	{
		return ClearPort();		//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//------------------------------------- Remove Chars from Port -------------------------------------------
long PortRemoveChars(char* StringToRemove)
{
	if (RemoveFromPort !=0)		//If function exists
	{
		return RemoveFromPort(StringToRemove);		//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//---------------------------------------- Get Motor Position --------------------------------------------
char* MotorPosition(long MotorNumber)
{
	if (GetMotorPosition !=0)		//If function exists
	{
		return GetMotorPosition(MotorNumber);	//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//--------------------------------------- Wait for Char --------------------------------------------------
long PortWaitForChar(char* CharToWaitFor, long TimeOutTime)
{
	if (WaitForChar !=0)		//If function exists
	{
		return WaitForChar(CharToWaitFor, TimeOutTime);	//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//---------------------------------- Wait for Char with Motor Position -----------------------------------
long PortWaitForCharWithMotorPosition(char* CharToWaitFor, long MotorNumber, long ReportToWindowHwnd, long TimeOutTime)
{
	if (WaitForCharWithMotorPosition !=0)		//If function exists
	{
		return WaitForCharWithMotorPosition(CharToWaitFor, MotorNumber, ReportToWindowHwnd, TimeOutTime);	//Call function
	}
	else
	{
		return 0;		//Return failed call
	}
}

//--------------------------------------- Reset Driver Functions -----------------------------------------
void DriverResetFunctions(void)
{
	if (ResetDriver !=0)		//If function exists
	{
		ResetDriver();	//Call function
	}
	else
	{
	}
}

