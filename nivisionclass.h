#ifndef NIVISIONCLASS_H
#define NIVISIONCLASS_H

#include <QObject>
#include <QString>
#include "NIDAQmx.h"
#include "nivision.h"


class NIVisionClass : public QObject
{
    Q_OBJECT
public:

    // Public class functions

    NIVisionClass();                //Constructor
    ~NIVisionClass();               //Destructor
    NIVisionClass(const NIVisionClass & copyFromMe); //Copy Constructor
  //  NIVisionClass operator=(const NIVisionClass& assignFromMe); //assignment operator

     void NIVisionClassCallBack(WindowEventType type, int windowNumber,Tool tool, Rect rect);

    //Accessor Functions
    // Using refs to pointers because control class will perform dynamic memory
    //  allocation on Image and RGBValue vars.  Therefore must pass by reff.
    Image**         GetPtrToImage1Ptr() {return &image1;}
    Image**         GetPtrToImage2Ptr() {return &image2;}
    RGBValue**      GetPtrToImageData1Ptr() {return &imageData1;}
    RGBValue**      GetPtrToImageData2Ptr() {return &imageData2;}
    int             GetDisplayWinNum1() {return displayWinNum1;}
    int             GetDisplayWinNum2() {return displayWinNum2;}


    // Public class vars

    int 	displayWinNum1;
    int 	displayWinNum2;
    int         numContours;
    Image*	image1;				//Pointer to Image object for display
    Image*	image2;				//Pointer to Image object for display
    RGBValue*	imageData1;			//Data to use to make the image1
    RGBValue*	imageData2;			//Data to use to make the image2
    Point	posWindow1;			//NI Vision data type. Position of window1
    Point	posWindow2;
    Point       posToolBar;
    ROI*        curr_roi;
    ContourInfo2*   contourInfoArray[200];       //Set max num of contours so I dont need to deal with dynamic mem allocation
/*    WindowEventType* type;
    int*        windowNumber;
    Tool*       tool;
    Rect*       rect;

    void (*callbackFunctPtr)(WindowEventType* type, int* windowNumber,
                             Tool* tool, Rect* rect);
*/

public slots:
    void slotToggleTools();
    void slotToggleImage1();
    void slotToggleImage2();
    void slotUpdateVisionWindows(int displayWinNum,int numX, int numY);
    //void slotUpdateImage1Ptr();       //Not needed since passing by reference now
    //void slotUpdateImage2Ptr();
    //void slotUpdateImage1DataPtr();
    //void slotUpdateImage2DataPtr();
    //ContourInfo2*   slotGetContourVision(int i);

signals:
    void NIVisionVarsChanged( NIVisionClass* niVisionVar);
    void NIVisionPointToolClickEvent(Rect rect);

private:

    //Callback function for NIVision.  Appears to have its own event handler.  Note
    //  this is actually a function pointer (as is typical for callback functions).
   // void IMAQ_CALLBACK NIVisionCallbackFunction(WindowEventType type, int windowNumber,
    //                                       Tool tool, Rect rect);
    void updateContourInfoArray();
    void setupNIVisionWindows();
};

#endif // NIVISIONCLASS_H
