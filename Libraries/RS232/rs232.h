/*============================================================================*/
/*                        L a b W i n d o w s / C V I                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 1987-1999.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       rs232.h                                                       */
/* Purpose:     Include file for RS-232 library support.                      */
/*                                                                            */
/*============================================================================*/

#ifndef RS232_HEADER
#define RS232_HEADER

#include "cvidef.h"
#include "cvirte.h"

#ifdef __cplusplus
    extern "C" {
#endif

/* Escape Codes */
#define SETXOFF             1       /* Simulate XOFF received      */
#define SETXON              2       /* Simulate XON received       */
#define SETRTS              3       /* Set RTS high                */
#define CLRRTS              4       /* Set RTS low                 */
#define SETDTR              5       /* Set DTR high                */
#define CLRDTR              6       /* Set DTR low                 */
#define RESETDEV            7       /* Reset device if possible    */
#define GETMAXCOM           9       /* return highest com number   */
/* RS485 only */
#define WIRE_4              128     /* Set 4-wire wiring mode (0 to Scratchpad) */
#define WIRE_2_ECHO         129     /* Set 2-wire, DTR echo mode (1 to Scratchpad) */
#define WIRE_2_CTRL         130     /* Set 2-wire, DTR controlled mode (2 to Scratchpad) */
#define WIRE_2_AUTO         131     /* Set 2-wire, TxRdy auto control (3 to scratchpad) */

/* Modem Status Flags for GetComLineStatus */
#define kRS_CTS_ON                      0x00000010
#define kRS_DSR_ON                      0x00000020
#define kRS_RING_ON                     0x00000040
#define kRS_RLSD_ON                     0x00000080

/* variables */
#ifdef _CVI_USE_FUNCS_FOR_VARS_
    extern int *CVIFUNC_C _GetRs232Err(void);
    #define rs232err (*_GetRs232Err())
#else
    extern int rs232err;
#endif

/* exported functions */
int CVIFUNC CloseCom(int portNo);
int CVIFUNC ComBreak(int portNo, int milliSec);
int CVIFUNC ComFromFile(int portNo, int handle, int maxCnt, int termCh);
int CVIFUNC ComRd(int portNo, char buf[], int maxCnt);
int CVIFUNC ComRdByte(int portNo);
int CVIFUNC ComRdTerm(int portNo, char buf[], int   maxCnt, int termCh);
int CVIFUNC ComToFile(int portNo, int handle, int   maxCnt, int termCh);
int CVIFUNC ComWrt(int portNo, const char *buf, int maxCnt);
int CVIFUNC ComWrtByte(int portNo, int byte);
int CVIFUNC FlushInQ(int portNo);
int CVIFUNC FlushOutQ(int portNo);
int CVIFUNC GetComStat(int portNo);
int CVIFUNC GetInQLen(int portNo);
int CVIFUNC GetOutQLen(int portNo);
int CVIFUNC OpenCom(int portNo, const char deviceName[]);
int CVIFUNC OpenComConfig(int portNo, const char deviceName[], int baudRate, int parity,
                  int dataBits, int stopBits, int iqSize,
                  int oqSize);
int CVIFUNC SetComTime(int portNo, double seconds);
int CVIFUNC SetCTSMode(int portNo, int mode);
int CVIFUNC SetXMode(int portNo, int mode);
int CVIFUNC XModemConfig(int portNo, double startDelay, int maxTries,
                 double waitPeriod, int packetSize);
int CVIFUNC XModemReceive(int portNo, const char pathName[]);
int CVIFUNC XModemSend(int portNo, const char pathName[]);
int CVIFUNC ReturnRS232Err(void);
int CVIFUNC GetSystemComHandle(int portNo, int *handle);
unsigned CVIFUNC GetComLineStatus(int portNo);
int CVIFUNC GetComConnectionState(int portNo);

#if defined(_NI_mswin16_) || defined(_NI_mswin32_) || defined(_NI_mswin_)
typedef void (CVICALLBACK *ComCallbackPtr) (int portNo, int eventMask, void *callbackData);
int CVIFUNC InstallComCallback(int  portNo, int eventMask, int notifyCount,
      int eventCharacter, ComCallbackPtr callbackPtr, void *CallbackData);

#endif

int CVIFUNC ComSetEscape(int portNo, int escapeCode);
char * CVIFUNC GetRS232ErrorString(int errorNum);



/* error codes returned by RS-232 functions */
typedef enum {
    kRS_UnknownSysError          =  -1,
    kRS_InvalidPortNum           =  -2,
    kRS_PortNotOpen              =  -3,
    kRS_UnknownIOError           =  -4,
    kRS_InternalError            =  -5,
    kRS_NoPortFound              =  -6,
    kRS_CanNotOpenPort           =  -7,
    kRS_OutOfMemory              =  -11,
    kRS_InvalidParameter         =  -13,
    kRS_InvalidBaudRate          =  -14,
    kRS_InvalidParity            =  -24,
    kRS_InvalidDataBits          =  -34,
    kRS_InvalidStopBits          =  -44,
    kRS_BadFileHandle            =  -90,
    kRS_FileIOError              =  -91,
    kRS_InvalidCount             =  -94,
    kRS_InvalidIntLevel          =  -97,
    kRS_IOTimeOut                =  -99,
    kRS_InvalidBreakTime         =  -104,
    kRS_InvalidInQSize           =  -114,
    kRS_InvalidOutQSize          =  -124,
    kRS_GeneralIOFailure         =  -151,
    kRS_InvalidBufferPointer     =  -152,
    kRS_NoAckReceived            =  -257,
    kRS_MaxRetriesBeforeSend     =  -258,
    kRS_MaxRetriesBeforeReceived =  -259,
    kRS_UnexpectedEOT            =  -260,
    kRS_CanNotReadPackNum        =  -261,
    kRS_InconsistentPackNum      =  -262,
    kRS_CanNotReadPackData       =  -263,
    kRS_CanNotReadCheckSum       =  -264,
    kRS_CheckSumError            =  -265,
    kRS_PackSizeGTInQ            =  -269,
    kRS_OpenFileError            =  -300,
    kRS_ReadFileError            =  -301,
    kRS_NoInitNegAck             =  -302,
    kRS_NoAckAfterEOT            =  -303,
    kRS_WriteFileError           =  -304,
    kRS_NoSOHorEOT               =  -305,
    kRS_TransferCancelled        =  -402,
    kRS_InvalidStartDelay        =  -503,
    kRS_InvalidMaxTries          =  -504,
    kRS_InvalidWaitPeriod        =  -505,
    kRS_InvalidPacketSize        =  -506,
    kRS_CanNotReadCRC            =  -507,
    kRS_CRCError                 =  -508
} RS232ErrorType;

/* event Mask defines for InstallComCallback (only for Windows) */
#if defined(_NI_mswin16_) || defined(_NI_mswin32_) || defined(_NI_mswin_)
#define LWRS_RECEIVE    0x8000  /* notifyCount bytes in inqueue   */
#define LWRS_RXCHAR     0x0001  /* Any Character received         */
#define LWRS_RXFLAG     0x0002  /* Received certain character     */
#define LWRS_TXEMPTY    0x0004  /* Transmit Queue Empty           */
#define LWRS_CTS        0x0008  /* CTS changed state              */
#define LWRS_DSR        0x0010  /* DSR changed state              */
#define LWRS_RLSD       0x0020  /* RLSD changed state             */
#define LWRS_BREAK      0x0040  /* BREAK received                 */
#define LWRS_ERR        0x0080  /* Line status error occurred     */
#define LWRS_RING       0x0100  /* Ring signal detected           */
#endif

/* modes for SetCTSMode() */
#define LWRS_HWHANDSHAKE_OFF                   0
#define LWRS_HWHANDSHAKE_CTS_RTS_DTR           1
#define LWRS_HWHANDSHAKE_CTS_RTS               2

/* status codes return through GetComStat */
#define kRS_InputLost                   0x00000001
#define kRS_AsynError                   0x00000002
#define kRS_ParityError                 0x00000010
#define kRS_OverrunError                0x00000020
#define kRS_FramingError                0x00000040
#define kRS_BreakSignal                 0x00000080
#define kRS_RemoteXoff                  0x00001000
#define kRS_RemoteXon                   0x00002000
#define kRS_LocalXoff                   0x00004000
#define kRS_LocalXon                    0x00008000

/* Modem Status Flags for GetComLineStatus */
#define kRS_CTS_ON                      0x00000010
#define kRS_DSR_ON                      0x00000020
#define kRS_RING_ON                     0x00000040
#define kRS_RLSD_ON                     0x00000080

#ifdef __cplusplus
    }
#endif

#endif /* RS232_HEADER */
