
#some type of include dir or path is included in this file that makes debug mode work - need to find out what and then delete this line
include(C:\Qt\src\3rdparty\qwt-5.1.1\qwtconfig.pri)

# Input

HEADERS += TwoPhotonGui.h \
                   NIDAQmx.h \
                   nivision.h \
                   TwoPhoton.h \
		   scanengine.h \
		   acqengine.h \
		   2pData.h \
		   aomControl.h \
		   lifetimeacq.h \
		   TwoPhoton.h \
		   AcqThread.h \
		   VxmDriver.h \
		   stepperDriver.h \
		   zStepDriver.h \
		   TwoPhotonControl.h \
		   Server.h \
                    nivisionclass.h \
                    spc_data_file_structure.h
		   
FORMS += TwoPhoton.ui

SOURCES += TwoPhoton.cpp \
		   TwoPhotonGui.cpp \
		   scanengine.cpp \
		   acqengine.cpp \
		   2pData.cpp \
		   aomControl.cpp \
		   lifetimeacq.cpp \
		   AcqThread.cpp \
		   VxmDriver.cpp \
		   stepperDriver.cpp \
		   zStepDriver.cpp \
		   TwoPhotonControl.cpp \
		   Server.cpp \
    nivisionclass.cpp

		   
DEPENDPATH += .
INCLUDEPATH += "C:\Program Files\National Instruments\NI-DAQ\DAQmx ANSI C Dev\include\" \
                           "C:\Program Files\National Instruments\Vision\Include\" \
                           "C:\Qt\src\3rdparty\qwt-5.1.1\src" \
                           "C:\wsc4c\APPS\wsc.h"\
                            ".\Libraries\RS232"
			   
LIBS += "C:\Program Files\National Instruments\NI-DAQ\DAQmx ANSI C Dev\lib\msvc\NIDAQmx.lib"	\
		"C:\Program Files\National Instruments\Vision\Lib\MSVC\nivision.lib" \
		"C:\Qt\lib\QtNetwork4.lib" \
                "C:\Qt\lib\qwt5.lib" \
                "C:\Qt\lib\qwtd5.lib" \
                "C:\Arnold\ADE_Code_Dir\TwoPhotonGitRepo\Libraries\RS232\cvirt.lib" \
                "C:\Arnold\ADE_Code_Dir\TwoPhotonGitRepo\Libraries\RS232\cvisupp.lib"

RESOURCES =".\Resources\Art\2P_Resources.qrc"

QT += network
