#include <iostream>
#include <QDebug>
#include "nivisionclass.h"
#include <QCoreApplication>


void  IMAQ_CALLBACK NIVisionCallbackFunction(WindowEventType , int ,
                                       Tool , Rect );
void (* callbackFunctPtr)(WindowEventType , int ,
                         Tool , Rect );

extern NIVisionClass* niVisionVarPtr;
/*WindowEventType* type_a = NULL;
    int*        windowNumber_a = NULL;
    Tool*       tool_a = NULL;
    Rect*       rect_a = NULL;
*/

//Function: Class constructor
//Description:
NIVisionClass::NIVisionClass()
{
    int temp;
    image1 = NULL;
    image2 = NULL;
    imageData1 = NULL;
    imageData2 = NULL;
    numContours = 0;

    for (int i=0; i<200; i++)
    {
        contourInfoArray[i]=NULL;
    }

/*
    type_a = NULL;
    windowNumber_a = NULL;
    tool_a = NULL;
    rect_a = NULL;
*/
    //callbackFunctPtr = &NIVisionClass::NIVisionCallbackFunction;
    callbackFunctPtr = &NIVisionCallbackFunction;

    setupNIVisionWindows();

    //Specify the callback function for NIVision events
   // temp =  imaqSetEventCallback(NIVisionCallbackFunction(type,windowNumber,tool,rect), TRUE);
    temp =  imaqSetEventCallback((EventCallback)callbackFunctPtr, TRUE);
}


//Function: Class destructor
//Description:
NIVisionClass::~NIVisionClass()
{
    if(image1) delete image1;
    if(image2) delete image2;
    if(imageData1) delete imageData1;
    if(imageData2) delete imageData2;

}

//Function: Copy constructor
//Description:
NIVisionClass::NIVisionClass(const NIVisionClass& copyFromMe)
{
    displayWinNum1 = copyFromMe.displayWinNum1;
    displayWinNum2 = copyFromMe.displayWinNum2;
    image1 = copyFromMe.image1;
    image2 = copyFromMe.image2;
    imageData1 = copyFromMe.imageData1;
    imageData2 = copyFromMe.imageData2;
    posWindow1 = copyFromMe.posWindow1;
    posWindow2 = copyFromMe.posWindow2;
    posToolBar = copyFromMe.posToolBar;
    curr_roi = copyFromMe.curr_roi;
    *contourInfoArray = *(copyFromMe.contourInfoArray);
}

//Function: Copy constructor
//Description:  --This is tricky to implement.  I'm not really going to
// because I should never need it.  Included it because compiler wanted it
/*NIVisionClass::operator=(const NIVisionClass& assignFromMe)
{


}
*/
//Function: setupNIVisionWindows
//Description: Creates and displays two NIVision image windows and
//              the toolbar
void NIVisionClass::setupNIVisionWindows()
{
    //Point	toolPos;
    posToolBar.x=850;
    posToolBar.y=20;


    //Setup display and display tools using NIVision calls
    image1 = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
    displayWinNum1 = 1;
    imaqDisplayImage(image1, displayWinNum1, 1);
    imaqSetWindowTitle(1, "PMT Images");
    imaqSetWindowSize(1, 256, 256);
    posWindow1.x = 850;
    posWindow1.y = 300;
    imaqMoveWindow(1, posWindow1);

    imaqShowToolWindow (TRUE);
    imaqMoveToolWindow(posToolBar);
    imaqSetToolColor(&IMAQ_RGB_BLUE);
    imaqSetCurrentTool (IMAQ_POLYLINE_TOOL);

    image2 = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
    displayWinNum2 = 2;
    imaqDisplayImage(image2, displayWinNum2, 1);
    imaqSetWindowTitle(2, "ROI Images");
    imaqSetWindowSize(2, 256, 256);
    posWindow2.x = 850;
    posWindow2.y = 590;
    imaqMoveWindow(2, posWindow2);

    imageData1 = NULL;
    imageData2 = NULL;


}

//Function: UpdateContourInfo
//Description: Reads info for all the defined contours and stores in member vars.
void NIVisionClass::updateContourInfoArray()
{

    ContourInfo2*   tempContourInfo = NULL;
    int             tempCounter = 0;

    curr_roi = imaqGetWindowROI(displayWinNum1);

    for (int i=0; i < 200; i++)
    {
        tempContourInfo = imaqGetContourInfo2(curr_roi, i+1);
        if (tempContourInfo != NULL)
        {
            contourInfoArray[i] = tempContourInfo;
            tempCounter++;
        }
        else
        {
            //break;
            contourInfoArray[i] = NULL;
        }
    }
    numContours = tempCounter;

}


//Function: Toggle Tools
//Description: Toggles the tool bar visibility
void NIVisionClass::slotToggleTools()
{
        int visible;

        //Determine if tool window is visible
        imaqIsToolWindowVisible(&visible);

        //if window is visible, set to invisible; if not set to visible
        if(visible)
                imaqShowToolWindow(0);
        else
                imaqShowToolWindow(1);

}


//Function: toggleImage1
//Description: Toggles Image 1 visibility
void NIVisionClass::slotToggleImage1()
{
        int visible;

        //Determine if window is visible
        imaqIsWindowVisible(displayWinNum1,&visible);

        //if window is visible, set to invisible; if not set to visible
        if(visible)
                imaqShowWindow(displayWinNum1,0);
        else
                imaqShowWindow(displayWinNum1,1);
}


//Function: toggleImage2
//Description: Toggles Image 2 visibility
void NIVisionClass::slotToggleImage2()
{

        int visible;

        //Determine if window is visible
        imaqIsWindowVisible(displayWinNum2,&visible);

        //if window is visible, set to invisible; if not set to visible
        if(visible)
                imaqShowWindow(displayWinNum2,0);
        else
                imaqShowWindow(displayWinNum2,1);
}

void NIVisionClass::slotUpdateVisionWindows(int displayWinNum,int numX, int numY)
{

    //Acqthread updated imagedata, emitted signal which called this slot
    if (displayWinNum == this->displayWinNum1)  //Regular image (not linescan)
    {
        imaqArrayToImage(image1, imageData1, numX,numY);
        imaqDisplayImage(image1, displayWinNum, 1);
    }
    else    //linescan
    {
        imaqArrayToImage(image2, imageData2, numX,numY);
        imaqDisplayImage(image2, displayWinNum, 1);
    }
    QCoreApplication::processEvents();
}


//Function: NIVisionCallbackFunction
//Description: This is the callback function specified to NIVision.  All
//              NIVision events trigger this function.
//void NIVisionClass::NIVisionCallbackFunction(WindowEventType* type, int* windowNumber,
//                                                     Tool* tool, Rect* rect)


void  IMAQ_CALLBACK NIVisionCallbackFunction(WindowEventType type, int windowNumber,
                                                     Tool tool, Rect rect)
{
//EventCallback

bool bCallClassCallback = false;

   if (tool == IMAQ_POINT_TOOL)
   {

        if (type == IMAQ_CLICK_EVENT)
        {
            bCallClassCallback = true;
        }



    }
    else if (tool == IMAQ_POLYLINE_TOOL)
    {
       if (type == IMAQ_DRAW_EVENT)
       {
           bCallClassCallback = true;
       }

    }
    else if (tool == IMAQ_LINE_TOOL)
    {
        if (type == IMAQ_DRAW_EVENT)
        {
            bCallClassCallback = true;
        }
    }

   if (bCallClassCallback)
       niVisionVarPtr->NIVisionClassCallBack(type, windowNumber, tool, rect);



}

//The NIVision callback function cant be part of the class.  So it cant
// directly emit signals (since they are inherently protected).  Therefore,
// I need to have a public class method to emit the signal for the callback
// function
void NIVisionClass::NIVisionClassCallBack(WindowEventType type, int windowNumber,Tool tool, Rect rect)
{
  //QString messageStr;
    qDebug() << "In NIVisionClassCallBack()";


    if (tool == IMAQ_POINT_TOOL)
    {

         if (type == IMAQ_CLICK_EVENT)
         {

            qDebug() << "Point_Tool CLICK_EVENT";
            updateContourInfoArray();
            emit NIVisionPointToolClickEvent(rect);

            //Announce changes to NIVisionClass in case other classes need to update themselves
            emit NIVisionVarsChanged(this);  //Not hooked to anything.  Using pointer to ContourInfoArray.  So no need to update twophotoncontrol class.

         }
     }
    else if (tool == IMAQ_POLYLINE_TOOL)
    {
       if (type == IMAQ_DRAW_EVENT)
       {
           qDebug() << "PolyLine DRAW_EVENT";

           //Update all relevant variable values since some may have changed.
           updateContourInfoArray();

           //Announce changes to NIVisionClass in case other classes need to update themselves
           emit NIVisionVarsChanged(this);  //Not hooked to anything.  Using pointer to ContourInfoArray.  So no need to update twophotoncontrol class.
       }

    }
    else if (tool == IMAQ_LINE_TOOL)
    {
        if (type == IMAQ_DRAW_EVENT)
        {
            qDebug() << "Line DRAW_EVENT";
            updateContourInfoArray();
            //Announce changes to NIVisionClass in case other classes need to update themselves
            emit NIVisionVarsChanged(this);  //Not hooked to anything.  Using pointer to ContourInfoArray.  So no need to update twophotoncontrol class.

        }
    }


}

