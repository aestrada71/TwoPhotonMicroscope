#ifndef VxmDriver_H			//If not defined
	#define VxmDriver_H		//Define
#endif						//End macro
#include "windows.h"

//-------------------------------------------------------------------------------------------------
//------------ Functions below are declarations in __stdcall format 
//------ (but in C++ when called they are prefixed by a _ so then we use loadlibrary instead) ------
//-------------------------------------------------------------------------------------------------
/*
#ifdef __cplusplus
extern "C"{
#endif
// Actual Driver Functions
//    FUNCTION ShowTerminalSimple ALIAS "ShowTerminalSimple"(BYVAL hParent&) EXPORT AS LONG
//    FUNCTION HideTerminalSimple ALIAS "HideTerminalSimple"() EXPORT AS LONG
//    FUNCTION OpenPort ALIAS "OpenPort"(BYVAL ComPortNumber AS LONG, BYVAL ComPortBaudRate AS LONG) EXPORT AS LONG  'Configure and open serial port
//    FUNCTION IsPortOpen ALIAS "IsPortOpen"() EXPORT AS LONG
//    FUNCTION ClosePort ALIAS "ClosePort"() EXPORT AS LONG  'Close serial port
//    FUNCTION DriverSendToPort ALIAS "DriverSendToPort" (CommandOut AS ASCIIZ * %MAX_PATH) EXPORT AS LONG 'Send Command to device via Cptr or actual string
//    FUNCTION ReadFromPort ALIAS "ReadFromPort"() EXPORT AS STRING  'Get reply from device
//    FUNCTION CountCharsAtPort ALIAS "CountCharsAtPort"() EXPORT AS LONG 'Count Number of Chars at port
//    FUNCTION SearchForChars ALIAS "SearchForChars"(CharsToFind AS ASCIIZ) EXPORT AS LONG
//    FUNCTION ClearPort ALIAS "ClearPort"() EXPORT AS LONG  'Clear buffer
//    FUNCTION RemoveFromPort ALIAS "RemoveFromPort"(StringToRemove AS ASCIIZ) EXPORT AS LONG  'Clear buffer chars
//    FUNCTION GetMotorPosition ALIAS "GetMotorPosition"(BYVAL MotorNumber AS LONG) AS STRING
//    FUNCTION WaitForChar ALIAS "WaitForChar"(CharToWaitFor AS ASCIIZ * %MAX_PATH, OPTIONAL BYVAL TimeOutTime AS LONG) AS LONG
//    FUNCTION WaitForCharWithMotorPosition ALIAS "WaitForCharWithMotorPosition"(CharToWaitFor AS ASCIIZ * %MAX_PATH, BYVAL MotorNumber AS LONG, OPTIONAL BYVAL ReportToWindowHwnd AS LONG, OPTIONAL BYVAL TimeOutTime AS LONG) AS LONG
//    SUB ResetDriverFunctions ALIAS "ResetDriverFunctions"()


// Functions as called from C++ 
//long ShowTerminalSimple(long HwndParent);               //Used to show the Debug Terminal
//long HideTerminalSimple(void);                          //Used to hide the Debug Terminal
//long OpenPort(long PortNumber, long BaudRate);          //Used to open the serial port (typically Com1 at 9600 baud
//long IsPortOpen(void);                                  //Used to check if the serial port is open
//long ClosePort(void);                                   //Used to close the serial port
//long DriverSendToPort(char* CommandToSend);             //Used to send commands to the VXM
//char* ReadFromPort(void);                               //Used to read replies from the VXM
//long CountCharsAtPort(void);                            //Used to count how many character are at the port waiting to be read
//long SearchForChars(char* CharsToFind);                 //Used to search for a particular character or string (typically the "^" indicating a VXM program has completed)
//long ClearPort(void);                                   //Used to clear the serial port buffer of any characters
//long RemoveFromPort(char* CharsToRemove);               //Used to remove certain characters but leave any other characters in the serial port buffer
//char* GetMotorPosition(long MotorNumber);               //Used to Get a motor position

//long WaitForChar(char* CharToWaitFor, long TimeOutTime);    //Used to make your computer program halt until a particular character is sent from the VXM (typically the "^" indicating a VXM program has completed)

//long WaitForCharWithMotorPosition(char* CharToWaitFor, long MotorNumber, long ReportToWindowHwnd, long TimeOutTime);        //A combination of waiting for a character but also continuously read motor position back while waiting

//void ResetDriverFunctions(void);                        //Used to reset the driver in cases where your code is waiting but for some reason the correct response never comes back


//#ifdef __cplusplus
//}
//#endif


*/

//--- Declare the wrapper functions ---//
long LoadDriver(LPCWSTR DriverPath);
long ReleaseDriver();
long DriverTerminalShowState(long StateToShow, long ParentHwnd);
long PortOpen(long PortNumber, long BaudRate);
long PortIsOpen(void);
long PortClose(void);
long PortSendCommands(char* CommandToSend);
char* PortReadReply(void);
long PortCountChars(void);
long PortSearchForChars(char* CharsToFind);
long PortClear(void);
long PortRemoveChars(char* StringToRemove);
char* MotorPosition(long MotorNumber);
long PortWaitForChar(char* CharToWaitFor, long TimeOutTime);
long PortWaitForCharWithMotorPosition(char* CharToWaitFor, long MotorNumber, long ReportToWindowHwnd, long TimeOutTime);
void DriverResetFunctions(void);
 