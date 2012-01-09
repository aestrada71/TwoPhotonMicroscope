/********************************************************************************
** Form generated from reading ui file 'TwoPhoton.ui'
**
** Created: Tue Jan 3 15:24:59 2012
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TWOPHOTON_H
#define UI_TWOPHOTON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwoPhotonMainWindow
{
public:
    QAction *actionAbout_TwoPhotonSoftware;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionEdit_item_1;
    QAction *actionEdit_item_2;
    QAction *actionEdit_item_3;
    QAction *actionEdit_item_4;
    QAction *actionEdit_item_5;
    QAction *actionEdit_item_6;
    QAction *actionView_visionTools;
    QAction *actionView_viewChan1;
    QAction *actionSubmenu_1;
    QAction *actionSubmenu_2;
    QAction *actionScan_Setup;
    QAction *actionImage_Setup;
    QAction *actionAcquisition_Setup;
    QAction *actionShutter_Setup;
    QAction *actionAOM_Setup;
    QAction *actionView_viewChan2;
    QAction *actionDefault_Hardware_Connections;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *scanSetupTab;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_15;
    QVBoxLayout *vboxLayout;
    QLabel *label_9;
    QComboBox *comboBox_xChannel;
    QVBoxLayout *vboxLayout1;
    QLabel *label_13;
    QComboBox *comboBox_yChannel;
    QVBoxLayout *vboxLayout2;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox_SampleRate;
    QSpacerItem *verticalSpacer_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_xMinVolts;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_yMinVolts;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *vboxLayout3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_xMaxVolts;
    QVBoxLayout *vboxLayout4;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_yMaxVolts;
    QVBoxLayout *vboxLayout5;
    QLabel *label_28;
    QSpinBox *spinBox_LineRate;
    QSpacerItem *verticalSpacer_10;
    QVBoxLayout *vboxLayout6;
    QLabel *label_12;
    QSpinBox *spinBox_numXPx;
    QVBoxLayout *vboxLayout7;
    QLabel *label_16;
    QSpinBox *spinBox_numYPx;
    QVBoxLayout *vboxLayout8;
    QLabel *label_27;
    QDoubleSpinBox *doubleSpinBox_frametime;
    QSpacerItem *verticalSpacer_11;
    QGridLayout *gridLayout_12;
    QLabel *label_19;
    QSpinBox *spinBox_ZoomFactor;
    QLabel *label_70;
    QDoubleSpinBox *doubleSpinBox_FOV;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_RotateGalvos;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QFrame *line_2;
    QWidget *acqSetupTab;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_47;
    QSpinBox *spinBox_xOffset;
    QLabel *label_50;
    QComboBox *comboBox_InChan2;
    QComboBox *comboBox_InChan1;
    QComboBox *comboBox_AIRange;
    QLabel *label_33;
    QDoubleSpinBox *doubleSpinBox_9;
    QSpacerItem *spacerItem;
    QSpacerItem *spacerItem1;
    QWidget *imageSetupTab;
    QGridLayout *gridLayout2;
    QGridLayout *gridLayout3;
    QGridLayout *gridLayout4;
    QLabel *label_38;
    QLabel *label_34;
    QLabel *label_32;
    QSpinBox *spinBox_yFov;
    QSpinBox *spinBox_xFov;
    QVBoxLayout *vboxLayout9;
    QLabel *label_45;
    QSpinBox *spinBox_Scaling;
    QVBoxLayout *vboxLayout10;
    QLabel *label_31;
    QComboBox *comboBox_Magnification;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QGridLayout *gridLayout5;
    QLabel *label_39;
    QLabel *label_44;
    QLabel *label_43;
    QDoubleSpinBox *doubleSpinBox_xRes;
    QDoubleSpinBox *doubleSpinBox_yRes;
    QSpacerItem *spacerItem5;
    QWidget *shutterSetupTab;
    QGridLayout *gridLayout6;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;
    QVBoxLayout *vboxLayout11;
    QLabel *label_52;
    QComboBox *comboBox_9;
    QWidget *aOMSetupTab;
    QGridLayout *gridLayout7;
    QVBoxLayout *vboxLayout12;
    QLabel *label_56;
    QComboBox *comboBox_AomRefOutChan;
    QVBoxLayout *vboxLayout13;
    QLabel *label_53;
    QDoubleSpinBox *doubleSpinBox_duration;
    QCheckBox *checkBox_AomCont;
    QVBoxLayout *vboxLayout14;
    QLabel *label_64;
    QSpinBox *spinBox_OnTime;
    QVBoxLayout *vboxLayout15;
    QLabel *label_55;
    QComboBox *comboBox_AomChan;
    QVBoxLayout *vboxLayout16;
    QLabel *label_58;
    QSpinBox *spinBox_RepRate;
    QVBoxLayout *vboxLayout17;
    QLabel *label_57;
    QDoubleSpinBox *doubleSpinBox_AomRefOutVoltage;
    QSpacerItem *spacerItem8;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_7;
    QLabel *label_63;
    QSpinBox *spinBox_ComPortXYStep;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_65;
    QLabel *label_69;
    QSpinBox *spinBox_ComPortZStep;
    QPushButton *pushButton_connectXYCom;
    QPushButton *pushButton_connectZCom;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_10;
    QLabel *label_72;
    QLineEdit *lineEdit_ServerPort;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout9;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout18;
    QVBoxLayout *vboxLayout19;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_zStartPos;
    QVBoxLayout *vboxLayout20;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_zStepSize;
    QVBoxLayout *vboxLayout21;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_zStopPos;
    QSpacerItem *spacerItem9;
    QVBoxLayout *vboxLayout22;
    QVBoxLayout *vboxLayout23;
    QLabel *label_18;
    QSpinBox *spinBox_numSteps;
    QCheckBox *checkBox_3dAcq;
    QSpacerItem *spacerItem10;
    QSpacerItem *spacerItem11;
    QVBoxLayout *vboxLayout24;
    QLabel *label_46;
    QCheckBox *checkBox_laserIntAdjust;
    QLabel *label_51;
    QDoubleSpinBox *doubleSpinBox_TopVoltage;
    QLabel *label_54;
    QDoubleSpinBox *doubleSpinBox_BottomVoltage;
    QSpacerItem *spacerItem12;
    QVBoxLayout *vboxLayout25;
    QPushButton *pushButton_changeDir;
    QFrame *line_3;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Stop;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_ContinAcq;
    QCheckBox *checkBox_TrigAcq;
    QPushButton *pushButton_Acquire;
    QPushButton *pushButton_linescanAcq;
    QPushButton *pushButton_lifetimeAcq;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_stopAcq;
    QHBoxLayout *hboxLayout1;
    QLabel *label_17;
    QLineEdit *lineEdit_OutputDir;
    QVBoxLayout *vboxLayout26;
    QVBoxLayout *vboxLayout27;
    QCheckBox *checkBox_Input1;
    QCheckBox *checkBox_Input2;
    QCheckBox *checkBox_Save;
    QVBoxLayout *vboxLayout28;
    QLabel *label_23;
    QSpinBox *spinBox_numFrames;
    QSpacerItem *spacerItem13;
    QVBoxLayout *vboxLayout29;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_diskSpace;
    QFrame *frame;
    QGridLayout *gridLayout10;
    QSpacerItem *spacerItem14;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QProgressBar *progressBar_acq;
    QProgressBar *progressBar_scan;
    QLabel *label_6;
    QFrame *line_6;
    QFrame *line_5;
    QSpinBox *spinBox_LifetimeAcqNum;
    QLabel *label_71;
    QLabel *label;
    QProgressBar *progressBar_LaserOn;
    QPushButton *pushButton_UpdateLTAcqNum;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout11;
    QSpacerItem *spacerItem15;
    QSpacerItem *spacerItem16;
    QVBoxLayout *vboxLayout30;
    QPushButton *pushButton_ResetOrigin;
    QGridLayout *gridLayout12;
    QLabel *label_66;
    QLabel *label_67;
    QDoubleSpinBox *doubleSpinBox_xPos;
    QDoubleSpinBox *doubleSpinBox_yPos;
    QLabel *label_68;
    QGridLayout *gridLayout13;
    QLabel *label_77;
    QLabel *label_78;
    QLabel *label_81;
    QDoubleSpinBox *doubleSpinBox_coarseField;
    QDoubleSpinBox *doubleSpinBox_fineField;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_25;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_coarseUp;
    QGridLayout *gridLayout14;
    QToolButton *toolButton_fineDown;
    QToolButton *toolButton_fineRight;
    QToolButton *toolButton_fineLeft;
    QToolButton *toolButton_fineUp;
    QPushButton *pushButton_coarseLeft;
    QPushButton *pushButton_coarseDown;
    QPushButton *pushButton_coarseRight;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout15;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_holdTorque;
    QPushButton *pushButton_zStepResetOrigin;
    QLabel *label_96;
    QPushButton *pushButton_zStepUp;
    QPushButton *pushButton_zStepDown;
    QDoubleSpinBox *doubleSpinBox_zPos;
    QLabel *label_103;
    QDoubleSpinBox *doubleSpinBox_moveToPos;
    QPushButton *pushButton_zMoveTo;
    QDoubleSpinBox *doubleSpinBox_zManualStepSize;
    QLabel *label_104;
    QSpacerItem *verticalSpacer_51;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout16;
    QVBoxLayout *verticalLayout;
    QLabel *label_83;
    QSpinBox *spinBox_Width;
    QLabel *label_84;
    QSpinBox *spinBox_Repeat;
    QLabel *label_85;
    QSpinBox *spinBox_linescanRate;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout17;
    QLabel *label_80;
    QLabel *label_82;
    QLabel *label_79;
    QDoubleSpinBox *doubleSpinBox_AomVoltAmp;
    QPushButton *pushButton_AomOff;
    QPushButton *pushButton_AomOn;
    QCheckBox *checkBox_AomPulse;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout18;
    QLabel *label_7;
    QGridLayout *gridLayout_4;
    QSlider *horizontalSlider_Ch1MinScale;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_41;
    QSpinBox *spinBox_Ch1MaxScale;
    QSpinBox *spinBox_Ch1MinScale;
    QLabel *label_59;
    QSlider *horizontalSlider_Ch1MaxScale;
    QGridLayout *gridLayout_6;
    QSlider *horizontalSlider_Ch2MinScale;
    QSlider *horizontalSlider_Ch2MaxScale;
    QSpinBox *spinBox_Ch2MinScale;
    QSpinBox *spinBox_Ch2MaxScale;
    QLabel *label_37;
    QLabel *label_40;
    QLabel *label_42;
    QLabel *label_60;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout19;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_saveImageLoc;
    QPushButton *pushButton_savePtLoc;
    QTreeWidget *treeWidget_savedLocs;
    QPushButton *pushButton_goToLoc;
    QPushButton *pushButton;
    QLabel *label_8;
    QGroupBox *groupBox_9;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_log;
    QGroupBox *groupBox_10;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_5;
    QSpinBox *spinBox_yPosBeamPark;
    QLabel *label_29;
    QLabel *label_30;
    QSpinBox *spinBox_xPosBeamPark;
    QPushButton *pushButton_parkBeam;
    QGridLayout *gridLayout_9;
    QSpinBox *spinBox;
    QLabel *label_61;
    QLabel *label_62;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuView;
    QMenu *menuFile;

    void setupUi(QMainWindow *TwoPhotonMainWindow)
    {
    if (TwoPhotonMainWindow->objectName().isEmpty())
        TwoPhotonMainWindow->setObjectName(QString::fromUtf8("TwoPhotonMainWindow"));
    TwoPhotonMainWindow->setWindowModality(Qt::WindowModal);
    TwoPhotonMainWindow->resize(992, 920);
    QFont font;
    font.setFamily(QString::fromUtf8("Calibri"));
    font.setPointSize(10);
    TwoPhotonMainWindow->setFont(font);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/backup/Resources/Art/2PIcon.bmp")), QIcon::Normal, QIcon::Off);
    TwoPhotonMainWindow->setWindowIcon(icon);
    actionAbout_TwoPhotonSoftware = new QAction(TwoPhotonMainWindow);
    actionAbout_TwoPhotonSoftware->setObjectName(QString::fromUtf8("actionAbout_TwoPhotonSoftware"));
    actionAbout_TwoPhotonSoftware->setFont(font);
    actionNew = new QAction(TwoPhotonMainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    actionNew->setFont(font);
    actionOpen = new QAction(TwoPhotonMainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionOpen->setFont(font);
    actionSave = new QAction(TwoPhotonMainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    actionSave->setFont(font);
    actionQuit = new QAction(TwoPhotonMainWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionQuit->setFont(font);
    actionEdit_item_1 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_1->setObjectName(QString::fromUtf8("actionEdit_item_1"));
    actionEdit_item_1->setFont(font);
    actionEdit_item_2 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_2->setObjectName(QString::fromUtf8("actionEdit_item_2"));
    actionEdit_item_2->setFont(font);
    actionEdit_item_3 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_3->setObjectName(QString::fromUtf8("actionEdit_item_3"));
    actionEdit_item_3->setFont(font);
    actionEdit_item_4 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_4->setObjectName(QString::fromUtf8("actionEdit_item_4"));
    actionEdit_item_4->setFont(font);
    actionEdit_item_5 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_5->setObjectName(QString::fromUtf8("actionEdit_item_5"));
    actionEdit_item_5->setFont(font);
    actionEdit_item_6 = new QAction(TwoPhotonMainWindow);
    actionEdit_item_6->setObjectName(QString::fromUtf8("actionEdit_item_6"));
    actionEdit_item_6->setFont(font);
    actionView_visionTools = new QAction(TwoPhotonMainWindow);
    actionView_visionTools->setObjectName(QString::fromUtf8("actionView_visionTools"));
    actionView_visionTools->setCheckable(true);
    actionView_visionTools->setChecked(true);
    actionView_visionTools->setEnabled(true);
    actionView_visionTools->setFont(font);
    actionView_viewChan1 = new QAction(TwoPhotonMainWindow);
    actionView_viewChan1->setObjectName(QString::fromUtf8("actionView_viewChan1"));
    actionView_viewChan1->setCheckable(true);
    actionView_viewChan1->setChecked(true);
    actionView_viewChan1->setFont(font);
    actionSubmenu_1 = new QAction(TwoPhotonMainWindow);
    actionSubmenu_1->setObjectName(QString::fromUtf8("actionSubmenu_1"));
    actionSubmenu_2 = new QAction(TwoPhotonMainWindow);
    actionSubmenu_2->setObjectName(QString::fromUtf8("actionSubmenu_2"));
    actionScan_Setup = new QAction(TwoPhotonMainWindow);
    actionScan_Setup->setObjectName(QString::fromUtf8("actionScan_Setup"));
    actionScan_Setup->setFont(font);
    actionImage_Setup = new QAction(TwoPhotonMainWindow);
    actionImage_Setup->setObjectName(QString::fromUtf8("actionImage_Setup"));
    actionImage_Setup->setFont(font);
    actionAcquisition_Setup = new QAction(TwoPhotonMainWindow);
    actionAcquisition_Setup->setObjectName(QString::fromUtf8("actionAcquisition_Setup"));
    actionAcquisition_Setup->setFont(font);
    actionShutter_Setup = new QAction(TwoPhotonMainWindow);
    actionShutter_Setup->setObjectName(QString::fromUtf8("actionShutter_Setup"));
    actionShutter_Setup->setFont(font);
    actionAOM_Setup = new QAction(TwoPhotonMainWindow);
    actionAOM_Setup->setObjectName(QString::fromUtf8("actionAOM_Setup"));
    actionAOM_Setup->setFont(font);
    actionView_viewChan2 = new QAction(TwoPhotonMainWindow);
    actionView_viewChan2->setObjectName(QString::fromUtf8("actionView_viewChan2"));
    actionView_viewChan2->setCheckable(true);
    actionView_viewChan2->setChecked(true);
    actionView_viewChan2->setFont(font);
    actionDefault_Hardware_Connections = new QAction(TwoPhotonMainWindow);
    actionDefault_Hardware_Connections->setObjectName(QString::fromUtf8("actionDefault_Hardware_Connections"));
    actionDefault_Hardware_Connections->setFont(font);
    centralwidget = new QWidget(TwoPhotonMainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 340, 591, 211));
    tabWidget->setFont(font);
    scanSetupTab = new QWidget();
    scanSetupTab->setObjectName(QString::fromUtf8("scanSetupTab"));
    gridLayoutWidget_4 = new QWidget(scanSetupTab);
    gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
    gridLayoutWidget_4->setGeometry(QRect(10, 10, 570, 171));
    gridLayout_15 = new QGridLayout(gridLayoutWidget_4);
    gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
    gridLayout_15->setContentsMargins(0, 0, 0, 0);
    vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout->setMargin(0);
#endif
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label_9 = new QLabel(gridLayoutWidget_4);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout->addWidget(label_9);

    comboBox_xChannel = new QComboBox(gridLayoutWidget_4);
    comboBox_xChannel->setObjectName(QString::fromUtf8("comboBox_xChannel"));

    vboxLayout->addWidget(comboBox_xChannel);

    vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout1->setSpacing(6);
#endif
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    label_13 = new QLabel(gridLayoutWidget_4);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout1->addWidget(label_13);

    comboBox_yChannel = new QComboBox(gridLayoutWidget_4);
    comboBox_yChannel->setObjectName(QString::fromUtf8("comboBox_yChannel"));

    vboxLayout1->addWidget(comboBox_yChannel);

    vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout2->setSpacing(6);
#endif
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    vboxLayout2->setSizeConstraint(QLayout::SetNoConstraint);
    label_26 = new QLabel(gridLayoutWidget_4);
    label_26->setObjectName(QString::fromUtf8("label_26"));
    label_26->setAlignment(Qt::AlignCenter);

    vboxLayout2->addWidget(label_26);

    doubleSpinBox_SampleRate = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_SampleRate->setObjectName(QString::fromUtf8("doubleSpinBox_SampleRate"));
    doubleSpinBox_SampleRate->setEnabled(true);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(doubleSpinBox_SampleRate->sizePolicy().hasHeightForWidth());
    doubleSpinBox_SampleRate->setSizePolicy(sizePolicy);
    doubleSpinBox_SampleRate->setMaximum(500000);
    doubleSpinBox_SampleRate->setSingleStep(1000);
    doubleSpinBox_SampleRate->setValue(450000);

    vboxLayout2->addWidget(doubleSpinBox_SampleRate);

    verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout2->addItem(verticalSpacer_9);


    vboxLayout1->addLayout(vboxLayout2);


    vboxLayout->addLayout(vboxLayout1);


    gridLayout_15->addLayout(vboxLayout, 0, 0, 1, 1);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_10 = new QLabel(gridLayoutWidget_4);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    verticalLayout_3->addWidget(label_10);

    doubleSpinBox_xMinVolts = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_xMinVolts->setObjectName(QString::fromUtf8("doubleSpinBox_xMinVolts"));
    doubleSpinBox_xMinVolts->setMinimumSize(QSize(77, 0));
    doubleSpinBox_xMinVolts->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_xMinVolts->setMinimum(-5);
    doubleSpinBox_xMinVolts->setMaximum(5);
    doubleSpinBox_xMinVolts->setValue(-3);

    verticalLayout_3->addWidget(doubleSpinBox_xMinVolts);

    label_14 = new QLabel(gridLayoutWidget_4);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    verticalLayout_3->addWidget(label_14);

    doubleSpinBox_yMinVolts = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_yMinVolts->setObjectName(QString::fromUtf8("doubleSpinBox_yMinVolts"));
    doubleSpinBox_yMinVolts->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_yMinVolts->setMinimum(-5);
    doubleSpinBox_yMinVolts->setMaximum(5);
    doubleSpinBox_yMinVolts->setValue(-3);

    verticalLayout_3->addWidget(doubleSpinBox_yMinVolts);

    verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_3->addItem(verticalSpacer_8);


    gridLayout_15->addLayout(verticalLayout_3, 0, 1, 1, 1);

    vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout3->setSpacing(6);
#endif
    vboxLayout3->setMargin(0);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    label_11 = new QLabel(gridLayoutWidget_4);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout3->addWidget(label_11);

    doubleSpinBox_xMaxVolts = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_xMaxVolts->setObjectName(QString::fromUtf8("doubleSpinBox_xMaxVolts"));
    doubleSpinBox_xMaxVolts->setMinimumSize(QSize(77, 0));
    doubleSpinBox_xMaxVolts->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_xMaxVolts->setMinimum(-5);
    doubleSpinBox_xMaxVolts->setMaximum(5);
    doubleSpinBox_xMaxVolts->setValue(3);

    vboxLayout3->addWidget(doubleSpinBox_xMaxVolts);

    vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout4->setSpacing(6);
#endif
    vboxLayout4->setMargin(0);
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    label_15 = new QLabel(gridLayoutWidget_4);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout4->addWidget(label_15);

    doubleSpinBox_yMaxVolts = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_yMaxVolts->setObjectName(QString::fromUtf8("doubleSpinBox_yMaxVolts"));
    doubleSpinBox_yMaxVolts->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_yMaxVolts->setMinimum(-5);
    doubleSpinBox_yMaxVolts->setMaximum(5);
    doubleSpinBox_yMaxVolts->setValue(3);

    vboxLayout4->addWidget(doubleSpinBox_yMaxVolts);

    vboxLayout5 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout5->setSpacing(6);
#endif
    vboxLayout5->setMargin(0);
    vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
    label_28 = new QLabel(gridLayoutWidget_4);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setAlignment(Qt::AlignCenter);

    vboxLayout5->addWidget(label_28);

    spinBox_LineRate = new QSpinBox(gridLayoutWidget_4);
    spinBox_LineRate->setObjectName(QString::fromUtf8("spinBox_LineRate"));
    spinBox_LineRate->setEnabled(false);
    spinBox_LineRate->setAlignment(Qt::AlignCenter);
    spinBox_LineRate->setReadOnly(true);
    spinBox_LineRate->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_LineRate->setMaximum(100000000);
    spinBox_LineRate->setValue(200);

    vboxLayout5->addWidget(spinBox_LineRate);

    verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout5->addItem(verticalSpacer_10);


    vboxLayout4->addLayout(vboxLayout5);


    vboxLayout3->addLayout(vboxLayout4);


    gridLayout_15->addLayout(vboxLayout3, 0, 2, 1, 1);

    vboxLayout6 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout6->setSpacing(6);
#endif
    vboxLayout6->setMargin(0);
    vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
    label_12 = new QLabel(gridLayoutWidget_4);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout6->addWidget(label_12);

    spinBox_numXPx = new QSpinBox(gridLayoutWidget_4);
    spinBox_numXPx->setObjectName(QString::fromUtf8("spinBox_numXPx"));
    spinBox_numXPx->setMinimumSize(QSize(77, 0));
    spinBox_numXPx->setAlignment(Qt::AlignHCenter);
    spinBox_numXPx->setMinimum(1);
    spinBox_numXPx->setMaximum(2048);
    spinBox_numXPx->setValue(512);

    vboxLayout6->addWidget(spinBox_numXPx);

    vboxLayout7 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout7->setSpacing(6);
#endif
    vboxLayout7->setMargin(0);
    vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
    label_16 = new QLabel(gridLayoutWidget_4);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout7->addWidget(label_16);

    spinBox_numYPx = new QSpinBox(gridLayoutWidget_4);
    spinBox_numYPx->setObjectName(QString::fromUtf8("spinBox_numYPx"));
    spinBox_numYPx->setAlignment(Qt::AlignHCenter);
    spinBox_numYPx->setMinimum(1);
    spinBox_numYPx->setMaximum(2048);
    spinBox_numYPx->setValue(512);

    vboxLayout7->addWidget(spinBox_numYPx);

    vboxLayout8 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout8->setSpacing(6);
#endif
    vboxLayout8->setMargin(0);
    vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
    label_27 = new QLabel(gridLayoutWidget_4);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setAlignment(Qt::AlignCenter);

    vboxLayout8->addWidget(label_27);

    doubleSpinBox_frametime = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_frametime->setObjectName(QString::fromUtf8("doubleSpinBox_frametime"));
    doubleSpinBox_frametime->setEnabled(false);
    doubleSpinBox_frametime->setAlignment(Qt::AlignCenter);
    doubleSpinBox_frametime->setReadOnly(true);
    doubleSpinBox_frametime->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_frametime->setDecimals(4);
    doubleSpinBox_frametime->setMaximum(100);
    doubleSpinBox_frametime->setSingleStep(0.01);

    vboxLayout8->addWidget(doubleSpinBox_frametime);

    verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout8->addItem(verticalSpacer_11);


    vboxLayout7->addLayout(vboxLayout8);


    vboxLayout6->addLayout(vboxLayout7);


    gridLayout_15->addLayout(vboxLayout6, 0, 3, 1, 1);

    gridLayout_12 = new QGridLayout();
    gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
    label_19 = new QLabel(gridLayoutWidget_4);
    label_19->setObjectName(QString::fromUtf8("label_19"));

    gridLayout_12->addWidget(label_19, 0, 0, 1, 1);

    spinBox_ZoomFactor = new QSpinBox(gridLayoutWidget_4);
    spinBox_ZoomFactor->setObjectName(QString::fromUtf8("spinBox_ZoomFactor"));
    spinBox_ZoomFactor->setEnabled(false);
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(spinBox_ZoomFactor->sizePolicy().hasHeightForWidth());
    spinBox_ZoomFactor->setSizePolicy(sizePolicy1);
    spinBox_ZoomFactor->setMinimum(1);
    spinBox_ZoomFactor->setMaximum(20);

    gridLayout_12->addWidget(spinBox_ZoomFactor, 1, 0, 1, 1);

    label_70 = new QLabel(gridLayoutWidget_4);
    label_70->setObjectName(QString::fromUtf8("label_70"));

    gridLayout_12->addWidget(label_70, 3, 0, 1, 1);

    doubleSpinBox_FOV = new QDoubleSpinBox(gridLayoutWidget_4);
    doubleSpinBox_FOV->setObjectName(QString::fromUtf8("doubleSpinBox_FOV"));
    doubleSpinBox_FOV->setEnabled(false);
    sizePolicy1.setHeightForWidth(doubleSpinBox_FOV->sizePolicy().hasHeightForWidth());
    doubleSpinBox_FOV->setSizePolicy(sizePolicy1);
    doubleSpinBox_FOV->setFrame(true);
    doubleSpinBox_FOV->setReadOnly(true);
    doubleSpinBox_FOV->setButtonSymbols(QAbstractSpinBox::NoButtons);

    gridLayout_12->addWidget(doubleSpinBox_FOV, 5, 0, 1, 1);

    verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_12->addItem(verticalSpacer_13, 2, 0, 1, 1);

    verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_12->addItem(verticalSpacer_14, 6, 0, 1, 1);


    gridLayout_15->addLayout(gridLayout_12, 0, 6, 1, 1);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_15->addItem(horizontalSpacer_2, 0, 4, 1, 1);

    verticalLayout_4 = new QVBoxLayout();
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    pushButton_RotateGalvos = new QPushButton(gridLayoutWidget_4);
    pushButton_RotateGalvos->setObjectName(QString::fromUtf8("pushButton_RotateGalvos"));
    QFont font1;
    font1.setPointSize(9);
    font1.setStrikeOut(false);
    font1.setKerning(true);
    pushButton_RotateGalvos->setFont(font1);
    pushButton_RotateGalvos->setIconSize(QSize(15, 15));

    verticalLayout_4->addWidget(pushButton_RotateGalvos);

    verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_4->addItem(verticalSpacer_12);


    gridLayout_15->addLayout(verticalLayout_4, 0, 9, 1, 1);

    horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_15->addItem(horizontalSpacer_4, 0, 7, 1, 1);

    line = new QFrame(gridLayoutWidget_4);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);

    gridLayout_15->addWidget(line, 0, 5, 1, 1);

    line_2 = new QFrame(gridLayoutWidget_4);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setFrameShape(QFrame::VLine);
    line_2->setFrameShadow(QFrame::Sunken);

    gridLayout_15->addWidget(line_2, 0, 8, 1, 1);

    tabWidget->addTab(scanSetupTab, QString());
    acqSetupTab = new QWidget();
    acqSetupTab->setObjectName(QString::fromUtf8("acqSetupTab"));
    gridLayout = new QGridLayout(acqSetupTab);
#ifndef Q_OS_MAC
    gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout1->setMargin(0);
#endif
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout1->setSizeConstraint(QLayout::SetMaximumSize);
    label_48 = new QLabel(acqSetupTab);
    label_48->setObjectName(QString::fromUtf8("label_48"));
    label_48->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(label_48, 0, 2, 1, 1);

    label_49 = new QLabel(acqSetupTab);
    label_49->setObjectName(QString::fromUtf8("label_49"));
    label_49->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(label_49, 2, 1, 1, 1);

    label_47 = new QLabel(acqSetupTab);
    label_47->setObjectName(QString::fromUtf8("label_47"));
    label_47->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout1->addWidget(label_47, 2, 0, 1, 1);

    spinBox_xOffset = new QSpinBox(acqSetupTab);
    spinBox_xOffset->setObjectName(QString::fromUtf8("spinBox_xOffset"));
    spinBox_xOffset->setAlignment(Qt::AlignCenter);
    spinBox_xOffset->setSingleStep(1);
    spinBox_xOffset->setValue(39);

    gridLayout1->addWidget(spinBox_xOffset, 1, 2, 1, 1);

    label_50 = new QLabel(acqSetupTab);
    label_50->setObjectName(QString::fromUtf8("label_50"));
    label_50->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(label_50, 0, 1, 1, 1);

    comboBox_InChan2 = new QComboBox(acqSetupTab);
    comboBox_InChan2->setObjectName(QString::fromUtf8("comboBox_InChan2"));

    gridLayout1->addWidget(comboBox_InChan2, 4, 0, 1, 1);

    comboBox_InChan1 = new QComboBox(acqSetupTab);
    comboBox_InChan1->setObjectName(QString::fromUtf8("comboBox_InChan1"));

    gridLayout1->addWidget(comboBox_InChan1, 1, 0, 1, 1);

    comboBox_AIRange = new QComboBox(acqSetupTab);
    comboBox_AIRange->setObjectName(QString::fromUtf8("comboBox_AIRange"));
    QFont font2;
    font2.setKerning(true);
    font2.setStyleStrategy(QFont::PreferDefault);
    comboBox_AIRange->setFont(font2);
    comboBox_AIRange->setLayoutDirection(Qt::LeftToRight);
    comboBox_AIRange->setEditable(false);
    comboBox_AIRange->setModelColumn(0);

    gridLayout1->addWidget(comboBox_AIRange, 1, 1, 1, 1);

    label_33 = new QLabel(acqSetupTab);
    label_33->setObjectName(QString::fromUtf8("label_33"));
    label_33->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout1->addWidget(label_33, 0, 0, 1, 1);

    doubleSpinBox_9 = new QDoubleSpinBox(acqSetupTab);
    doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
    doubleSpinBox_9->setAlignment(Qt::AlignCenter);
    doubleSpinBox_9->setReadOnly(true);
    doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_9->setMaximum(500);
    doubleSpinBox_9->setValue(61.03);

    gridLayout1->addWidget(doubleSpinBox_9, 4, 1, 1, 1);


    gridLayout->addLayout(gridLayout1, 0, 0, 1, 1);

    spacerItem = new QSpacerItem(101, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem, 0, 1, 1, 1);

    spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem1, 1, 0, 1, 1);

    tabWidget->addTab(acqSetupTab, QString());
    imageSetupTab = new QWidget();
    imageSetupTab->setObjectName(QString::fromUtf8("imageSetupTab"));
    gridLayout2 = new QGridLayout(imageSetupTab);
#ifndef Q_OS_MAC
    gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout2->setMargin(9);
#endif
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    gridLayout3 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout3->setMargin(0);
#endif
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    gridLayout4 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout4->setMargin(0);
#endif
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    label_38 = new QLabel(imageSetupTab);
    label_38->setObjectName(QString::fromUtf8("label_38"));
    sizePolicy1.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
    label_38->setSizePolicy(sizePolicy1);
    label_38->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout4->addWidget(label_38, 1, 0, 1, 1);

    label_34 = new QLabel(imageSetupTab);
    label_34->setObjectName(QString::fromUtf8("label_34"));
    label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout4->addWidget(label_34, 2, 0, 1, 1);

    label_32 = new QLabel(imageSetupTab);
    label_32->setObjectName(QString::fromUtf8("label_32"));
    label_32->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    gridLayout4->addWidget(label_32, 0, 0, 1, 2);

    spinBox_yFov = new QSpinBox(imageSetupTab);
    spinBox_yFov->setObjectName(QString::fromUtf8("spinBox_yFov"));
    spinBox_yFov->setAlignment(Qt::AlignCenter);
    spinBox_yFov->setReadOnly(true);
    spinBox_yFov->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_yFov->setMaximum(10000000);
    spinBox_yFov->setValue(200);

    gridLayout4->addWidget(spinBox_yFov, 2, 1, 1, 1);

    spinBox_xFov = new QSpinBox(imageSetupTab);
    spinBox_xFov->setObjectName(QString::fromUtf8("spinBox_xFov"));
    spinBox_xFov->setAlignment(Qt::AlignCenter);
    spinBox_xFov->setReadOnly(true);
    spinBox_xFov->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_xFov->setMaximum(1000000);
    spinBox_xFov->setValue(200);

    gridLayout4->addWidget(spinBox_xFov, 1, 1, 1, 1);


    gridLayout3->addLayout(gridLayout4, 0, 2, 2, 1);

    vboxLayout9 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout9->setSpacing(6);
#endif
    vboxLayout9->setMargin(0);
    vboxLayout9->setObjectName(QString::fromUtf8("vboxLayout9"));
    label_45 = new QLabel(imageSetupTab);
    label_45->setObjectName(QString::fromUtf8("label_45"));
    label_45->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout9->addWidget(label_45);

    spinBox_Scaling = new QSpinBox(imageSetupTab);
    spinBox_Scaling->setObjectName(QString::fromUtf8("spinBox_Scaling"));
    spinBox_Scaling->setWrapping(false);
    spinBox_Scaling->setAlignment(Qt::AlignCenter);
    spinBox_Scaling->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_Scaling->setMaximum(1000000);
    spinBox_Scaling->setValue(5000);

    vboxLayout9->addWidget(spinBox_Scaling);


    gridLayout3->addLayout(vboxLayout9, 2, 0, 1, 1);

    vboxLayout10 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout10->setSpacing(6);
#endif
    vboxLayout10->setMargin(0);
    vboxLayout10->setObjectName(QString::fromUtf8("vboxLayout10"));
    label_31 = new QLabel(imageSetupTab);
    label_31->setObjectName(QString::fromUtf8("label_31"));
    label_31->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout10->addWidget(label_31);

    comboBox_Magnification = new QComboBox(imageSetupTab);
    comboBox_Magnification->setObjectName(QString::fromUtf8("comboBox_Magnification"));

    vboxLayout10->addWidget(comboBox_Magnification);


    gridLayout3->addLayout(vboxLayout10, 0, 0, 1, 1);

    spacerItem2 = new QSpacerItem(21, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout3->addItem(spacerItem2, 2, 1, 1, 1);

    spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout3->addItem(spacerItem3, 1, 0, 1, 1);

    spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout3->addItem(spacerItem4, 3, 0, 1, 1);

    gridLayout5 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout5->setSpacing(6);
#endif
    gridLayout5->setMargin(0);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    label_39 = new QLabel(imageSetupTab);
    label_39->setObjectName(QString::fromUtf8("label_39"));
    label_39->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout5->addWidget(label_39, 4, 0, 1, 1);

    label_44 = new QLabel(imageSetupTab);
    label_44->setObjectName(QString::fromUtf8("label_44"));
    label_44->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    gridLayout5->addWidget(label_44, 0, 0, 1, 2);

    label_43 = new QLabel(imageSetupTab);
    label_43->setObjectName(QString::fromUtf8("label_43"));
    label_43->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout5->addWidget(label_43, 6, 0, 1, 1);

    doubleSpinBox_xRes = new QDoubleSpinBox(imageSetupTab);
    doubleSpinBox_xRes->setObjectName(QString::fromUtf8("doubleSpinBox_xRes"));
    doubleSpinBox_xRes->setAlignment(Qt::AlignCenter);
    doubleSpinBox_xRes->setReadOnly(true);
    doubleSpinBox_xRes->setButtonSymbols(QAbstractSpinBox::NoButtons);

    gridLayout5->addWidget(doubleSpinBox_xRes, 4, 1, 1, 1);

    doubleSpinBox_yRes = new QDoubleSpinBox(imageSetupTab);
    doubleSpinBox_yRes->setObjectName(QString::fromUtf8("doubleSpinBox_yRes"));
    doubleSpinBox_yRes->setAlignment(Qt::AlignCenter);
    doubleSpinBox_yRes->setReadOnly(true);
    doubleSpinBox_yRes->setButtonSymbols(QAbstractSpinBox::NoButtons);

    gridLayout5->addWidget(doubleSpinBox_yRes, 6, 1, 1, 1);


    gridLayout3->addLayout(gridLayout5, 2, 2, 2, 1);


    gridLayout2->addLayout(gridLayout3, 0, 0, 1, 1);

    spacerItem5 = new QSpacerItem(51, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    gridLayout2->addItem(spacerItem5, 0, 1, 1, 1);

    tabWidget->addTab(imageSetupTab, QString());
    shutterSetupTab = new QWidget();
    shutterSetupTab->setObjectName(QString::fromUtf8("shutterSetupTab"));
    gridLayout6 = new QGridLayout(shutterSetupTab);
#ifndef Q_OS_MAC
    gridLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout6->setMargin(9);
#endif
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout6->addItem(spacerItem6, 0, 1, 1, 1);

    spacerItem7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout6->addItem(spacerItem7, 1, 0, 1, 1);

    vboxLayout11 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout11->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout11->setMargin(0);
#endif
    vboxLayout11->setObjectName(QString::fromUtf8("vboxLayout11"));
    label_52 = new QLabel(shutterSetupTab);
    label_52->setObjectName(QString::fromUtf8("label_52"));

    vboxLayout11->addWidget(label_52);

    comboBox_9 = new QComboBox(shutterSetupTab);
    comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));

    vboxLayout11->addWidget(comboBox_9);


    gridLayout6->addLayout(vboxLayout11, 0, 0, 1, 1);

    tabWidget->addTab(shutterSetupTab, QString());
    aOMSetupTab = new QWidget();
    aOMSetupTab->setObjectName(QString::fromUtf8("aOMSetupTab"));
    gridLayout7 = new QGridLayout(aOMSetupTab);
#ifndef Q_OS_MAC
    gridLayout7->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout7->setMargin(9);
#endif
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    vboxLayout12 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout12->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout12->setMargin(0);
#endif
    vboxLayout12->setObjectName(QString::fromUtf8("vboxLayout12"));
    label_56 = new QLabel(aOMSetupTab);
    label_56->setObjectName(QString::fromUtf8("label_56"));
    label_56->setAlignment(Qt::AlignCenter);

    vboxLayout12->addWidget(label_56);

    comboBox_AomRefOutChan = new QComboBox(aOMSetupTab);
    comboBox_AomRefOutChan->setObjectName(QString::fromUtf8("comboBox_AomRefOutChan"));

    vboxLayout12->addWidget(comboBox_AomRefOutChan);


    gridLayout7->addLayout(vboxLayout12, 1, 1, 1, 1);

    vboxLayout13 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout13->setSpacing(6);
#endif
    vboxLayout13->setMargin(0);
    vboxLayout13->setObjectName(QString::fromUtf8("vboxLayout13"));
    label_53 = new QLabel(aOMSetupTab);
    label_53->setObjectName(QString::fromUtf8("label_53"));
    label_53->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    vboxLayout13->addWidget(label_53);

    doubleSpinBox_duration = new QDoubleSpinBox(aOMSetupTab);
    doubleSpinBox_duration->setObjectName(QString::fromUtf8("doubleSpinBox_duration"));
    doubleSpinBox_duration->setAlignment(Qt::AlignCenter);
    doubleSpinBox_duration->setReadOnly(false);
    doubleSpinBox_duration->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    doubleSpinBox_duration->setDecimals(0);
    doubleSpinBox_duration->setMaximum(500);
    doubleSpinBox_duration->setValue(10);

    vboxLayout13->addWidget(doubleSpinBox_duration);


    gridLayout7->addLayout(vboxLayout13, 1, 0, 1, 1);

    checkBox_AomCont = new QCheckBox(aOMSetupTab);
    checkBox_AomCont->setObjectName(QString::fromUtf8("checkBox_AomCont"));
    checkBox_AomCont->setChecked(true);

    gridLayout7->addWidget(checkBox_AomCont, 0, 0, 1, 1);

    vboxLayout14 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout14->setSpacing(6);
#endif
    vboxLayout14->setMargin(0);
    vboxLayout14->setObjectName(QString::fromUtf8("vboxLayout14"));
    label_64 = new QLabel(aOMSetupTab);
    label_64->setObjectName(QString::fromUtf8("label_64"));
    label_64->setAlignment(Qt::AlignCenter);

    vboxLayout14->addWidget(label_64);

    spinBox_OnTime = new QSpinBox(aOMSetupTab);
    spinBox_OnTime->setObjectName(QString::fromUtf8("spinBox_OnTime"));
    spinBox_OnTime->setAlignment(Qt::AlignHCenter);
    spinBox_OnTime->setMaximum(5000);
    spinBox_OnTime->setValue(20);

    vboxLayout14->addWidget(spinBox_OnTime);


    gridLayout7->addLayout(vboxLayout14, 1, 2, 1, 1);

    vboxLayout15 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout15->setSpacing(6);
#endif
    vboxLayout15->setMargin(0);
    vboxLayout15->setObjectName(QString::fromUtf8("vboxLayout15"));
    label_55 = new QLabel(aOMSetupTab);
    label_55->setObjectName(QString::fromUtf8("label_55"));
    label_55->setAlignment(Qt::AlignCenter);

    vboxLayout15->addWidget(label_55);

    comboBox_AomChan = new QComboBox(aOMSetupTab);
    comboBox_AomChan->setObjectName(QString::fromUtf8("comboBox_AomChan"));

    vboxLayout15->addWidget(comboBox_AomChan);


    gridLayout7->addLayout(vboxLayout15, 0, 1, 1, 1);

    vboxLayout16 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout16->setSpacing(6);
#endif
    vboxLayout16->setMargin(0);
    vboxLayout16->setObjectName(QString::fromUtf8("vboxLayout16"));
    label_58 = new QLabel(aOMSetupTab);
    label_58->setObjectName(QString::fromUtf8("label_58"));
    label_58->setAlignment(Qt::AlignCenter);

    vboxLayout16->addWidget(label_58);

    spinBox_RepRate = new QSpinBox(aOMSetupTab);
    spinBox_RepRate->setObjectName(QString::fromUtf8("spinBox_RepRate"));
    spinBox_RepRate->setAlignment(Qt::AlignHCenter);
    spinBox_RepRate->setMaximum(999999999);
    spinBox_RepRate->setValue(5000);

    vboxLayout16->addWidget(spinBox_RepRate);


    gridLayout7->addLayout(vboxLayout16, 0, 2, 1, 1);

    vboxLayout17 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout17->setSpacing(6);
#endif
    vboxLayout17->setMargin(0);
    vboxLayout17->setObjectName(QString::fromUtf8("vboxLayout17"));
    label_57 = new QLabel(aOMSetupTab);
    label_57->setObjectName(QString::fromUtf8("label_57"));
    label_57->setAlignment(Qt::AlignCenter);

    vboxLayout17->addWidget(label_57);

    doubleSpinBox_AomRefOutVoltage = new QDoubleSpinBox(aOMSetupTab);
    doubleSpinBox_AomRefOutVoltage->setObjectName(QString::fromUtf8("doubleSpinBox_AomRefOutVoltage"));
    doubleSpinBox_AomRefOutVoltage->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_AomRefOutVoltage->setMinimum(-10);
    doubleSpinBox_AomRefOutVoltage->setMaximum(10);
    doubleSpinBox_AomRefOutVoltage->setValue(2);

    vboxLayout17->addWidget(doubleSpinBox_AomRefOutVoltage);


    gridLayout7->addLayout(vboxLayout17, 2, 1, 1, 1);

    spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout7->addItem(spacerItem8, 0, 3, 1, 1);

    tabWidget->addTab(aOMSetupTab, QString());
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayoutWidget = new QWidget(tab);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(9, 9, 561, 151));
    gridLayout_7 = new QGridLayout(gridLayoutWidget);
    gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
    gridLayout_7->setContentsMargins(0, 0, 0, 0);
    label_63 = new QLabel(gridLayoutWidget);
    label_63->setObjectName(QString::fromUtf8("label_63"));
    QFont font3;
    font3.setPointSize(12);
    font3.setBold(true);
    font3.setWeight(75);
    label_63->setFont(font3);

    gridLayout_7->addWidget(label_63, 0, 0, 1, 1);

    spinBox_ComPortXYStep = new QSpinBox(gridLayoutWidget);
    spinBox_ComPortXYStep->setObjectName(QString::fromUtf8("spinBox_ComPortXYStep"));
    spinBox_ComPortXYStep->setAlignment(Qt::AlignCenter);
    spinBox_ComPortXYStep->setMaximum(10);
    spinBox_ComPortXYStep->setValue(2);

    gridLayout_7->addWidget(spinBox_ComPortXYStep, 2, 0, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_7->addItem(horizontalSpacer, 0, 2, 1, 1);

    verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_7->addItem(verticalSpacer_6, 5, 0, 1, 1);

    label_65 = new QLabel(gridLayoutWidget);
    label_65->setObjectName(QString::fromUtf8("label_65"));

    gridLayout_7->addWidget(label_65, 1, 0, 1, 1);

    label_69 = new QLabel(gridLayoutWidget);
    label_69->setObjectName(QString::fromUtf8("label_69"));

    gridLayout_7->addWidget(label_69, 3, 0, 1, 1);

    spinBox_ComPortZStep = new QSpinBox(gridLayoutWidget);
    spinBox_ComPortZStep->setObjectName(QString::fromUtf8("spinBox_ComPortZStep"));
    spinBox_ComPortZStep->setAlignment(Qt::AlignCenter);
    spinBox_ComPortZStep->setMaximum(10);
    spinBox_ComPortZStep->setValue(1);

    gridLayout_7->addWidget(spinBox_ComPortZStep, 4, 0, 1, 1);

    pushButton_connectXYCom = new QPushButton(gridLayoutWidget);
    pushButton_connectXYCom->setObjectName(QString::fromUtf8("pushButton_connectXYCom"));

    gridLayout_7->addWidget(pushButton_connectXYCom, 2, 1, 1, 1);

    pushButton_connectZCom = new QPushButton(gridLayoutWidget);
    pushButton_connectZCom->setObjectName(QString::fromUtf8("pushButton_connectZCom"));

    gridLayout_7->addWidget(pushButton_connectZCom, 4, 1, 1, 1);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayoutWidget_2 = new QWidget(tab_2);
    gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
    gridLayoutWidget_2->setGeometry(QRect(10, 10, 561, 151));
    gridLayout_10 = new QGridLayout(gridLayoutWidget_2);
    gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
    gridLayout_10->setContentsMargins(0, 0, 0, 0);
    label_72 = new QLabel(gridLayoutWidget_2);
    label_72->setObjectName(QString::fromUtf8("label_72"));

    gridLayout_10->addWidget(label_72, 0, 0, 1, 1);

    lineEdit_ServerPort = new QLineEdit(gridLayoutWidget_2);
    lineEdit_ServerPort->setObjectName(QString::fromUtf8("lineEdit_ServerPort"));

    gridLayout_10->addWidget(lineEdit_ServerPort, 0, 1, 1, 1);

    verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_10->addItem(verticalSpacer_5, 1, 0, 1, 1);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_10->addItem(horizontalSpacer_3, 0, 2, 1, 1);

    tabWidget->addTab(tab_2, QString());
    groupBox_3 = new QGroupBox(centralwidget);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 70, 591, 269));
    QFont font4;
    font4.setFamily(QString::fromUtf8("Calibri"));
    font4.setPointSize(14);
    font4.setBold(false);
    font4.setItalic(false);
    font4.setUnderline(false);
    font4.setWeight(50);
    font4.setStrikeOut(false);
    groupBox_3->setFont(font4);
    gridLayout8 = new QGridLayout(groupBox_3);
#ifndef Q_OS_MAC
    gridLayout8->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout8->setMargin(9);
#endif
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    groupBox_4 = new QGroupBox(groupBox_3);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    QFont font5;
    font5.setFamily(QString::fromUtf8("Calibri"));
    font5.setPointSize(10);
    font5.setBold(false);
    font5.setItalic(false);
    font5.setUnderline(false);
    font5.setWeight(50);
    font5.setStrikeOut(false);
    groupBox_4->setFont(font5);
    gridLayout9 = new QGridLayout(groupBox_4);
#ifndef Q_OS_MAC
    gridLayout9->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout9->setMargin(9);
#endif
    gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    hboxLayout->setMargin(0);
#endif
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    vboxLayout18 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout18->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout18->setMargin(0);
#endif
    vboxLayout18->setObjectName(QString::fromUtf8("vboxLayout18"));
    vboxLayout19 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout19->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout19->setMargin(0);
#endif
    vboxLayout19->setObjectName(QString::fromUtf8("vboxLayout19"));
    label_20 = new QLabel(groupBox_4);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setFont(font);
    label_20->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout19->addWidget(label_20);

    doubleSpinBox_zStartPos = new QDoubleSpinBox(groupBox_4);
    doubleSpinBox_zStartPos->setObjectName(QString::fromUtf8("doubleSpinBox_zStartPos"));
    doubleSpinBox_zStartPos->setFont(font);
    doubleSpinBox_zStartPos->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_zStartPos->setMinimum(-10000);
    doubleSpinBox_zStartPos->setMaximum(10000);

    vboxLayout19->addWidget(doubleSpinBox_zStartPos);


    vboxLayout18->addLayout(vboxLayout19);

    vboxLayout20 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout20->setSpacing(6);
#endif
    vboxLayout20->setMargin(0);
    vboxLayout20->setObjectName(QString::fromUtf8("vboxLayout20"));
    label_21 = new QLabel(groupBox_4);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setFont(font);
    label_21->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout20->addWidget(label_21);

    doubleSpinBox_zStepSize = new QDoubleSpinBox(groupBox_4);
    doubleSpinBox_zStepSize->setObjectName(QString::fromUtf8("doubleSpinBox_zStepSize"));
    doubleSpinBox_zStepSize->setFont(font);
    doubleSpinBox_zStepSize->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_zStepSize->setMinimum(-500);
    doubleSpinBox_zStepSize->setMaximum(1000);
    doubleSpinBox_zStepSize->setValue(-5);

    vboxLayout20->addWidget(doubleSpinBox_zStepSize);


    vboxLayout18->addLayout(vboxLayout20);

    vboxLayout21 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout21->setSpacing(6);
#endif
    vboxLayout21->setMargin(0);
    vboxLayout21->setObjectName(QString::fromUtf8("vboxLayout21"));
    label_22 = new QLabel(groupBox_4);
    label_22->setObjectName(QString::fromUtf8("label_22"));
    label_22->setFont(font);
    label_22->setAlignment(Qt::AlignCenter);

    vboxLayout21->addWidget(label_22);

    doubleSpinBox_zStopPos = new QDoubleSpinBox(groupBox_4);
    doubleSpinBox_zStopPos->setObjectName(QString::fromUtf8("doubleSpinBox_zStopPos"));
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(doubleSpinBox_zStopPos->sizePolicy().hasHeightForWidth());
    doubleSpinBox_zStopPos->setSizePolicy(sizePolicy2);
    doubleSpinBox_zStopPos->setMinimumSize(QSize(50, 0));
    doubleSpinBox_zStopPos->setBaseSize(QSize(0, 0));
    doubleSpinBox_zStopPos->setFont(font);
    doubleSpinBox_zStopPos->setAlignment(Qt::AlignHCenter);
    doubleSpinBox_zStopPos->setMinimum(-2000);
    doubleSpinBox_zStopPos->setMaximum(1000);
    doubleSpinBox_zStopPos->setValue(-50);

    vboxLayout21->addWidget(doubleSpinBox_zStopPos);


    vboxLayout18->addLayout(vboxLayout21);


    hboxLayout->addLayout(vboxLayout18);

    spacerItem9 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem9);

    vboxLayout22 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout22->setSpacing(6);
#endif
    vboxLayout22->setMargin(0);
    vboxLayout22->setObjectName(QString::fromUtf8("vboxLayout22"));
    vboxLayout23 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout23->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout23->setMargin(0);
#endif
    vboxLayout23->setObjectName(QString::fromUtf8("vboxLayout23"));
    label_18 = new QLabel(groupBox_4);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setFont(font);
    label_18->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout23->addWidget(label_18);

    spinBox_numSteps = new QSpinBox(groupBox_4);
    spinBox_numSteps->setObjectName(QString::fromUtf8("spinBox_numSteps"));
    spinBox_numSteps->setAlignment(Qt::AlignCenter);
    spinBox_numSteps->setReadOnly(true);
    spinBox_numSteps->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_numSteps->setMaximum(1000);
    spinBox_numSteps->setValue(10);

    vboxLayout23->addWidget(spinBox_numSteps);


    vboxLayout22->addLayout(vboxLayout23);

    checkBox_3dAcq = new QCheckBox(groupBox_4);
    checkBox_3dAcq->setObjectName(QString::fromUtf8("checkBox_3dAcq"));
    checkBox_3dAcq->setFont(font);

    vboxLayout22->addWidget(checkBox_3dAcq);

    spacerItem10 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout22->addItem(spacerItem10);


    hboxLayout->addLayout(vboxLayout22);

    spacerItem11 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem11);

    vboxLayout24 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout24->setSpacing(6);
#endif
    vboxLayout24->setMargin(0);
    vboxLayout24->setObjectName(QString::fromUtf8("vboxLayout24"));
    label_46 = new QLabel(groupBox_4);
    label_46->setObjectName(QString::fromUtf8("label_46"));
    QFont font6;
    font6.setBold(false);
    font6.setUnderline(true);
    font6.setWeight(50);
    label_46->setFont(font6);

    vboxLayout24->addWidget(label_46);

    checkBox_laserIntAdjust = new QCheckBox(groupBox_4);
    checkBox_laserIntAdjust->setObjectName(QString::fromUtf8("checkBox_laserIntAdjust"));
    checkBox_laserIntAdjust->setFont(font);

    vboxLayout24->addWidget(checkBox_laserIntAdjust);

    label_51 = new QLabel(groupBox_4);
    label_51->setObjectName(QString::fromUtf8("label_51"));

    vboxLayout24->addWidget(label_51);

    doubleSpinBox_TopVoltage = new QDoubleSpinBox(groupBox_4);
    doubleSpinBox_TopVoltage->setObjectName(QString::fromUtf8("doubleSpinBox_TopVoltage"));
    doubleSpinBox_TopVoltage->setAlignment(Qt::AlignCenter);
    doubleSpinBox_TopVoltage->setDecimals(3);
    doubleSpinBox_TopVoltage->setMinimum(-10);
    doubleSpinBox_TopVoltage->setMaximum(10);
    doubleSpinBox_TopVoltage->setValue(0.2);

    vboxLayout24->addWidget(doubleSpinBox_TopVoltage);

    label_54 = new QLabel(groupBox_4);
    label_54->setObjectName(QString::fromUtf8("label_54"));

    vboxLayout24->addWidget(label_54);

    doubleSpinBox_BottomVoltage = new QDoubleSpinBox(groupBox_4);
    doubleSpinBox_BottomVoltage->setObjectName(QString::fromUtf8("doubleSpinBox_BottomVoltage"));
    doubleSpinBox_BottomVoltage->setAlignment(Qt::AlignCenter);
    doubleSpinBox_BottomVoltage->setDecimals(3);
    doubleSpinBox_BottomVoltage->setMinimum(-10);
    doubleSpinBox_BottomVoltage->setMaximum(10);
    doubleSpinBox_BottomVoltage->setValue(0.7);

    vboxLayout24->addWidget(doubleSpinBox_BottomVoltage);

    spacerItem12 = new QSpacerItem(130, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout24->addItem(spacerItem12);


    hboxLayout->addLayout(vboxLayout24);


    gridLayout9->addLayout(hboxLayout, 1, 0, 1, 1);


    gridLayout8->addWidget(groupBox_4, 4, 1, 1, 1);

    vboxLayout25 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout25->setSpacing(6);
#endif
    vboxLayout25->setMargin(0);
    vboxLayout25->setObjectName(QString::fromUtf8("vboxLayout25"));
    pushButton_changeDir = new QPushButton(groupBox_3);
    pushButton_changeDir->setObjectName(QString::fromUtf8("pushButton_changeDir"));
    pushButton_changeDir->setFont(font5);

    vboxLayout25->addWidget(pushButton_changeDir);

    line_3 = new QFrame(groupBox_3);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setFrameShape(QFrame::HLine);
    line_3->setFrameShadow(QFrame::Sunken);

    vboxLayout25->addWidget(line_3);

    pushButton_Scan = new QPushButton(groupBox_3);
    pushButton_Scan->setObjectName(QString::fromUtf8("pushButton_Scan"));
    pushButton_Scan->setFont(font5);

    vboxLayout25->addWidget(pushButton_Scan);

    pushButton_Stop = new QPushButton(groupBox_3);
    pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
    pushButton_Stop->setEnabled(false);
    pushButton_Stop->setFont(font5);

    vboxLayout25->addWidget(pushButton_Stop);

    line_4 = new QFrame(groupBox_3);
    line_4->setObjectName(QString::fromUtf8("line_4"));
    line_4->setFrameShape(QFrame::HLine);
    line_4->setFrameShadow(QFrame::Sunken);

    vboxLayout25->addWidget(line_4);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    checkBox_ContinAcq = new QCheckBox(groupBox_3);
    checkBox_ContinAcq->setObjectName(QString::fromUtf8("checkBox_ContinAcq"));
    checkBox_ContinAcq->setEnabled(true);
    QFont font7;
    font7.setPointSize(8);
    checkBox_ContinAcq->setFont(font7);
    checkBox_ContinAcq->setChecked(false);

    horizontalLayout_2->addWidget(checkBox_ContinAcq);

    checkBox_TrigAcq = new QCheckBox(groupBox_3);
    checkBox_TrigAcq->setObjectName(QString::fromUtf8("checkBox_TrigAcq"));
    checkBox_TrigAcq->setFont(font7);
    checkBox_TrigAcq->setChecked(false);

    horizontalLayout_2->addWidget(checkBox_TrigAcq);


    vboxLayout25->addLayout(horizontalLayout_2);

    pushButton_Acquire = new QPushButton(groupBox_3);
    pushButton_Acquire->setObjectName(QString::fromUtf8("pushButton_Acquire"));
    pushButton_Acquire->setFont(font5);

    vboxLayout25->addWidget(pushButton_Acquire);

    pushButton_linescanAcq = new QPushButton(groupBox_3);
    pushButton_linescanAcq->setObjectName(QString::fromUtf8("pushButton_linescanAcq"));
    QFont font8;
    font8.setFamily(QString::fromUtf8("Calibri"));
    font8.setPointSize(9);
    font8.setBold(false);
    font8.setItalic(false);
    font8.setUnderline(false);
    font8.setWeight(50);
    font8.setStrikeOut(false);
    pushButton_linescanAcq->setFont(font8);

    vboxLayout25->addWidget(pushButton_linescanAcq);

    pushButton_lifetimeAcq = new QPushButton(groupBox_3);
    pushButton_lifetimeAcq->setObjectName(QString::fromUtf8("pushButton_lifetimeAcq"));
    pushButton_lifetimeAcq->setEnabled(true);
    pushButton_lifetimeAcq->setFont(font5);

    vboxLayout25->addWidget(pushButton_lifetimeAcq);

    verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout25->addItem(verticalSpacer_7);

    pushButton_stopAcq = new QPushButton(groupBox_3);
    pushButton_stopAcq->setObjectName(QString::fromUtf8("pushButton_stopAcq"));
    pushButton_stopAcq->setEnabled(false);
    QFont font9;
    font9.setPointSize(10);
    pushButton_stopAcq->setFont(font9);

    vboxLayout25->addWidget(pushButton_stopAcq);


    gridLayout8->addLayout(vboxLayout25, 3, 2, 2, 1);

    hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout1->setSpacing(6);
#endif
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    label_17 = new QLabel(groupBox_3);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setFont(font5);
    label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    hboxLayout1->addWidget(label_17);

    lineEdit_OutputDir = new QLineEdit(groupBox_3);
    lineEdit_OutputDir->setObjectName(QString::fromUtf8("lineEdit_OutputDir"));
    lineEdit_OutputDir->setFont(font5);
    lineEdit_OutputDir->setMaxLength(1024);

    hboxLayout1->addWidget(lineEdit_OutputDir);


    gridLayout8->addLayout(hboxLayout1, 3, 0, 1, 2);

    vboxLayout26 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout26->setSpacing(6);
#endif
    vboxLayout26->setMargin(0);
    vboxLayout26->setObjectName(QString::fromUtf8("vboxLayout26"));
    vboxLayout27 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout27->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout27->setMargin(0);
#endif
    vboxLayout27->setObjectName(QString::fromUtf8("vboxLayout27"));
    checkBox_Input1 = new QCheckBox(groupBox_3);
    checkBox_Input1->setObjectName(QString::fromUtf8("checkBox_Input1"));
    checkBox_Input1->setFont(font5);
    checkBox_Input1->setChecked(true);

    vboxLayout27->addWidget(checkBox_Input1);

    checkBox_Input2 = new QCheckBox(groupBox_3);
    checkBox_Input2->setObjectName(QString::fromUtf8("checkBox_Input2"));
    checkBox_Input2->setFont(font5);

    vboxLayout27->addWidget(checkBox_Input2);


    vboxLayout26->addLayout(vboxLayout27);

    checkBox_Save = new QCheckBox(groupBox_3);
    checkBox_Save->setObjectName(QString::fromUtf8("checkBox_Save"));
    checkBox_Save->setFont(font5);

    vboxLayout26->addWidget(checkBox_Save);

    vboxLayout28 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout28->setSpacing(6);
#endif
    vboxLayout28->setMargin(0);
    vboxLayout28->setObjectName(QString::fromUtf8("vboxLayout28"));
    label_23 = new QLabel(groupBox_3);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setFont(font5);
    label_23->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout28->addWidget(label_23);

    spinBox_numFrames = new QSpinBox(groupBox_3);
    spinBox_numFrames->setObjectName(QString::fromUtf8("spinBox_numFrames"));
    spinBox_numFrames->setFont(font5);
    spinBox_numFrames->setAlignment(Qt::AlignCenter);
    spinBox_numFrames->setValue(1);

    vboxLayout28->addWidget(spinBox_numFrames);


    vboxLayout26->addLayout(vboxLayout28);

    spacerItem13 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout26->addItem(spacerItem13);

    vboxLayout29 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout29->setSpacing(6);
#endif
    vboxLayout29->setMargin(0);
    vboxLayout29->setObjectName(QString::fromUtf8("vboxLayout29"));
    label_24 = new QLabel(groupBox_3);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setFont(font5);
    label_24->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

    vboxLayout29->addWidget(label_24);

    doubleSpinBox_diskSpace = new QDoubleSpinBox(groupBox_3);
    doubleSpinBox_diskSpace->setObjectName(QString::fromUtf8("doubleSpinBox_diskSpace"));
    QFont font10;
    font10.setFamily(QString::fromUtf8("Calibri"));
    font10.setPointSize(10);
    font10.setBold(false);
    font10.setWeight(50);
    doubleSpinBox_diskSpace->setFont(font10);
    doubleSpinBox_diskSpace->setAlignment(Qt::AlignCenter);
    doubleSpinBox_diskSpace->setReadOnly(true);
    doubleSpinBox_diskSpace->setButtonSymbols(QAbstractSpinBox::NoButtons);

    vboxLayout29->addWidget(doubleSpinBox_diskSpace);


    vboxLayout26->addLayout(vboxLayout29);


    gridLayout8->addLayout(vboxLayout26, 4, 0, 1, 1);

    frame = new QFrame(centralwidget);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(9, 9, 591, 62));
    frame->setFont(font);
    frame->setFrameShape(QFrame::WinPanel);
    frame->setFrameShadow(QFrame::Raised);
    frame->setLineWidth(10);
    gridLayout10 = new QGridLayout(frame);
#ifndef Q_OS_MAC
    gridLayout10->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout10->setMargin(9);
#endif
    gridLayout10->setObjectName(QString::fromUtf8("gridLayout10"));
    spacerItem14 = new QSpacerItem(166, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout10->addItem(spacerItem14, 0, 5, 1, 1);

    label_5 = new QLabel(frame);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    QFont font11;
    font11.setFamily(QString::fromUtf8("Calibri"));
    font11.setPointSize(11);
    font11.setBold(true);
    font11.setItalic(false);
    font11.setUnderline(false);
    font11.setWeight(75);
    font11.setStrikeOut(false);
    label_5->setFont(font11);
    label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout10->addWidget(label_5, 0, 8, 1, 1);

    label_2 = new QLabel(frame);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/g_ind2.bmp")));

    gridLayout10->addWidget(label_2, 0, 11, 1, 1);

    label_3 = new QLabel(frame);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/g_ind2.bmp")));

    gridLayout10->addWidget(label_3, 1, 11, 1, 1);

    label_4 = new QLabel(frame);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/g_ind2.bmp")));

    gridLayout10->addWidget(label_4, 0, 4, 1, 1);

    progressBar_acq = new QProgressBar(frame);
    progressBar_acq->setObjectName(QString::fromUtf8("progressBar_acq"));
    progressBar_acq->setValue(0);
    progressBar_acq->setTextVisible(false);

    gridLayout10->addWidget(progressBar_acq, 1, 9, 1, 1);

    progressBar_scan = new QProgressBar(frame);
    progressBar_scan->setObjectName(QString::fromUtf8("progressBar_scan"));
    progressBar_scan->setMaximum(100);
    progressBar_scan->setValue(0);
    progressBar_scan->setTextVisible(false);
    progressBar_scan->setInvertedAppearance(false);

    gridLayout10->addWidget(progressBar_scan, 0, 9, 1, 1);

    label_6 = new QLabel(frame);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setFont(font11);
    label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout10->addWidget(label_6, 1, 8, 1, 1);

    line_6 = new QFrame(frame);
    line_6->setObjectName(QString::fromUtf8("line_6"));
    line_6->setFrameShape(QFrame::VLine);
    line_6->setFrameShadow(QFrame::Sunken);

    gridLayout10->addWidget(line_6, 0, 6, 1, 1);

    line_5 = new QFrame(frame);
    line_5->setObjectName(QString::fromUtf8("line_5"));
    line_5->setFrameShape(QFrame::VLine);
    line_5->setFrameShadow(QFrame::Sunken);

    gridLayout10->addWidget(line_5, 1, 6, 1, 1);

    spinBox_LifetimeAcqNum = new QSpinBox(frame);
    spinBox_LifetimeAcqNum->setObjectName(QString::fromUtf8("spinBox_LifetimeAcqNum"));
    spinBox_LifetimeAcqNum->setEnabled(true);
    spinBox_LifetimeAcqNum->setAlignment(Qt::AlignCenter);
    spinBox_LifetimeAcqNum->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_LifetimeAcqNum->setMinimum(1);
    spinBox_LifetimeAcqNum->setMaximum(1000);

    gridLayout10->addWidget(spinBox_LifetimeAcqNum, 1, 2, 1, 1);

    label_71 = new QLabel(frame);
    label_71->setObjectName(QString::fromUtf8("label_71"));

    gridLayout10->addWidget(label_71, 1, 0, 1, 1);

    label = new QLabel(frame);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font12;
    font12.setFamily(QString::fromUtf8("Calibri"));
    font12.setPointSize(10);
    font12.setBold(false);
    font12.setItalic(false);
    font12.setUnderline(false);
    font12.setWeight(50);
    font12.setStrikeOut(false);
    font12.setKerning(false);
    font12.setStyleStrategy(QFont::PreferDefault);
    label->setFont(font12);
    label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout10->addWidget(label, 0, 0, 1, 1);

    progressBar_LaserOn = new QProgressBar(frame);
    progressBar_LaserOn->setObjectName(QString::fromUtf8("progressBar_LaserOn"));
    progressBar_LaserOn->setValue(0);
    progressBar_LaserOn->setTextVisible(false);

    gridLayout10->addWidget(progressBar_LaserOn, 0, 2, 1, 1);

    pushButton_UpdateLTAcqNum = new QPushButton(frame);
    pushButton_UpdateLTAcqNum->setObjectName(QString::fromUtf8("pushButton_UpdateLTAcqNum"));
    pushButton_UpdateLTAcqNum->setEnabled(true);
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(pushButton_UpdateLTAcqNum->sizePolicy().hasHeightForWidth());
    pushButton_UpdateLTAcqNum->setSizePolicy(sizePolicy3);
    QFont font13;
    font13.setFamily(QString::fromUtf8("Arial"));
    font13.setPointSize(8);
    font13.setKerning(true);
    pushButton_UpdateLTAcqNum->setFont(font13);

    gridLayout10->addWidget(pushButton_UpdateLTAcqNum, 1, 5, 1, 1);

    groupBox_5 = new QGroupBox(centralwidget);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(800, 300, 177, 360));
    QFont font14;
    font14.setFamily(QString::fromUtf8("Calibri"));
    font14.setPointSize(14);
    font14.setBold(false);
    font14.setItalic(false);
    font14.setUnderline(false);
    font14.setWeight(50);
    font14.setStrikeOut(false);
    font14.setKerning(false);
    groupBox_5->setFont(font14);
    groupBox_5->setAlignment(Qt::AlignLeading);
    gridLayout11 = new QGridLayout(groupBox_5);
#ifndef Q_OS_MAC
    gridLayout11->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout11->setMargin(9);
#endif
    gridLayout11->setObjectName(QString::fromUtf8("gridLayout11"));
    spacerItem15 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout11->addItem(spacerItem15, 0, 1, 1, 1);

    spacerItem16 = new QSpacerItem(2, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout11->addItem(spacerItem16, 0, 3, 1, 1);

    vboxLayout30 = new QVBoxLayout();
#ifndef Q_OS_MAC
    vboxLayout30->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    vboxLayout30->setMargin(0);
#endif
    vboxLayout30->setObjectName(QString::fromUtf8("vboxLayout30"));
    pushButton_ResetOrigin = new QPushButton(groupBox_5);
    pushButton_ResetOrigin->setObjectName(QString::fromUtf8("pushButton_ResetOrigin"));
    pushButton_ResetOrigin->setFont(font5);

    vboxLayout30->addWidget(pushButton_ResetOrigin);

    gridLayout12 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout12->setSpacing(6);
#endif
    gridLayout12->setMargin(0);
    gridLayout12->setObjectName(QString::fromUtf8("gridLayout12"));
    label_66 = new QLabel(groupBox_5);
    label_66->setObjectName(QString::fromUtf8("label_66"));
    label_66->setFont(font5);
    label_66->setAlignment(Qt::AlignCenter);

    gridLayout12->addWidget(label_66, 0, 0, 1, 2);

    label_67 = new QLabel(groupBox_5);
    label_67->setObjectName(QString::fromUtf8("label_67"));
    label_67->setFont(font5);
    label_67->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout12->addWidget(label_67, 1, 0, 1, 1);

    doubleSpinBox_xPos = new QDoubleSpinBox(groupBox_5);
    doubleSpinBox_xPos->setObjectName(QString::fromUtf8("doubleSpinBox_xPos"));
    QFont font15;
    font15.setPointSize(10);
    font15.setBold(false);
    font15.setWeight(50);
    doubleSpinBox_xPos->setFont(font15);
    doubleSpinBox_xPos->setAlignment(Qt::AlignCenter);
    doubleSpinBox_xPos->setReadOnly(true);
    doubleSpinBox_xPos->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_xPos->setMinimum(-9999);
    doubleSpinBox_xPos->setMaximum(9999);
    doubleSpinBox_xPos->setValue(0);

    gridLayout12->addWidget(doubleSpinBox_xPos, 1, 1, 1, 1);

    doubleSpinBox_yPos = new QDoubleSpinBox(groupBox_5);
    doubleSpinBox_yPos->setObjectName(QString::fromUtf8("doubleSpinBox_yPos"));
    doubleSpinBox_yPos->setFont(font15);
    doubleSpinBox_yPos->setAlignment(Qt::AlignCenter);
    doubleSpinBox_yPos->setReadOnly(true);
    doubleSpinBox_yPos->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_yPos->setMinimum(-9999);
    doubleSpinBox_yPos->setMaximum(9999);
    doubleSpinBox_yPos->setValue(0);

    gridLayout12->addWidget(doubleSpinBox_yPos, 3, 1, 1, 1);

    label_68 = new QLabel(groupBox_5);
    label_68->setObjectName(QString::fromUtf8("label_68"));
    label_68->setFont(font5);
    label_68->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout12->addWidget(label_68, 3, 0, 1, 1);


    vboxLayout30->addLayout(gridLayout12);

    gridLayout13 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout13->setSpacing(6);
#endif
    gridLayout13->setMargin(0);
    gridLayout13->setObjectName(QString::fromUtf8("gridLayout13"));
    label_77 = new QLabel(groupBox_5);
    label_77->setObjectName(QString::fromUtf8("label_77"));
    label_77->setFont(font5);
    label_77->setAlignment(Qt::AlignCenter);

    gridLayout13->addWidget(label_77, 0, 0, 1, 2);

    label_78 = new QLabel(groupBox_5);
    label_78->setObjectName(QString::fromUtf8("label_78"));
    label_78->setFont(font5);
    label_78->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout13->addWidget(label_78, 1, 0, 1, 1);

    label_81 = new QLabel(groupBox_5);
    label_81->setObjectName(QString::fromUtf8("label_81"));
    label_81->setFont(font5);
    label_81->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout13->addWidget(label_81, 2, 0, 1, 1);

    doubleSpinBox_coarseField = new QDoubleSpinBox(groupBox_5);
    doubleSpinBox_coarseField->setObjectName(QString::fromUtf8("doubleSpinBox_coarseField"));
    doubleSpinBox_coarseField->setFont(font15);
    doubleSpinBox_coarseField->setAlignment(Qt::AlignCenter);
    doubleSpinBox_coarseField->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_coarseField->setMaximum(5000);
    doubleSpinBox_coarseField->setValue(200);

    gridLayout13->addWidget(doubleSpinBox_coarseField, 1, 1, 1, 1);

    doubleSpinBox_fineField = new QDoubleSpinBox(groupBox_5);
    doubleSpinBox_fineField->setObjectName(QString::fromUtf8("doubleSpinBox_fineField"));
    doubleSpinBox_fineField->setFont(font15);
    doubleSpinBox_fineField->setAlignment(Qt::AlignCenter);
    doubleSpinBox_fineField->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_fineField->setMaximum(100.99);
    doubleSpinBox_fineField->setValue(50);

    gridLayout13->addWidget(doubleSpinBox_fineField, 2, 1, 1, 1);


    vboxLayout30->addLayout(gridLayout13);


    gridLayout11->addLayout(vboxLayout30, 0, 2, 1, 1);

    verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout11->addItem(verticalSpacer_3, 8, 2, 1, 1);

    label_25 = new QLabel(groupBox_5);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    QFont font16;
    font16.setFamily(QString::fromUtf8("Calibri"));
    font16.setPointSize(9);
    font16.setBold(false);
    font16.setWeight(50);
    label_25->setFont(font16);
    label_25->setAlignment(Qt::AlignCenter);

    gridLayout11->addWidget(label_25, 2, 2, 1, 1);

    gridLayout_3 = new QGridLayout();
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    pushButton_coarseUp = new QPushButton(groupBox_5);
    pushButton_coarseUp->setObjectName(QString::fromUtf8("pushButton_coarseUp"));
    pushButton_coarseUp->setEnabled(true);
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/Buttons/ArrowUp.bmp")), QIcon::Normal, QIcon::Off);
    pushButton_coarseUp->setIcon(icon1);

    gridLayout_3->addWidget(pushButton_coarseUp, 0, 2, 1, 1);

    gridLayout14 = new QGridLayout();
    gridLayout14->setObjectName(QString::fromUtf8("gridLayout14"));
    toolButton_fineDown = new QToolButton(groupBox_5);
    toolButton_fineDown->setObjectName(QString::fromUtf8("toolButton_fineDown"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/Buttons/ArrowDown.bmp")), QIcon::Normal, QIcon::Off);
    toolButton_fineDown->setIcon(icon2);

    gridLayout14->addWidget(toolButton_fineDown, 5, 2, 1, 1);

    toolButton_fineRight = new QToolButton(groupBox_5);
    toolButton_fineRight->setObjectName(QString::fromUtf8("toolButton_fineRight"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/Buttons/ArrowRight.bmp")), QIcon::Normal, QIcon::Off);
    toolButton_fineRight->setIcon(icon3);

    gridLayout14->addWidget(toolButton_fineRight, 4, 3, 1, 1);

    toolButton_fineLeft = new QToolButton(groupBox_5);
    toolButton_fineLeft->setObjectName(QString::fromUtf8("toolButton_fineLeft"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/Buttons/ArrowLeft.bmp")), QIcon::Normal, QIcon::Off);
    toolButton_fineLeft->setIcon(icon4);

    gridLayout14->addWidget(toolButton_fineLeft, 4, 1, 1, 1);

    toolButton_fineUp = new QToolButton(groupBox_5);
    toolButton_fineUp->setObjectName(QString::fromUtf8("toolButton_fineUp"));
    toolButton_fineUp->setIcon(icon1);

    gridLayout14->addWidget(toolButton_fineUp, 2, 2, 1, 1);


    gridLayout_3->addLayout(gridLayout14, 1, 2, 1, 1);

    pushButton_coarseLeft = new QPushButton(groupBox_5);
    pushButton_coarseLeft->setObjectName(QString::fromUtf8("pushButton_coarseLeft"));
    sizePolicy1.setHeightForWidth(pushButton_coarseLeft->sizePolicy().hasHeightForWidth());
    pushButton_coarseLeft->setSizePolicy(sizePolicy1);
    pushButton_coarseLeft->setIcon(icon4);

    gridLayout_3->addWidget(pushButton_coarseLeft, 1, 0, 1, 1);

    pushButton_coarseDown = new QPushButton(groupBox_5);
    pushButton_coarseDown->setObjectName(QString::fromUtf8("pushButton_coarseDown"));
    sizePolicy1.setHeightForWidth(pushButton_coarseDown->sizePolicy().hasHeightForWidth());
    pushButton_coarseDown->setSizePolicy(sizePolicy1);
    pushButton_coarseDown->setIcon(icon2);

    gridLayout_3->addWidget(pushButton_coarseDown, 2, 2, 1, 1);

    pushButton_coarseRight = new QPushButton(groupBox_5);
    pushButton_coarseRight->setObjectName(QString::fromUtf8("pushButton_coarseRight"));
    sizePolicy1.setHeightForWidth(pushButton_coarseRight->sizePolicy().hasHeightForWidth());
    pushButton_coarseRight->setSizePolicy(sizePolicy1);
    pushButton_coarseRight->setIcon(icon3);

    gridLayout_3->addWidget(pushButton_coarseRight, 1, 3, 1, 1);


    gridLayout11->addLayout(gridLayout_3, 5, 2, 1, 1);

    groupBox_8 = new QGroupBox(centralwidget);
    groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
    groupBox_8->setGeometry(QRect(800, 0, 177, 301));
    groupBox_8->setFont(font4);
    gridLayout15 = new QGridLayout(groupBox_8);
#ifndef Q_OS_MAC
    gridLayout15->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout15->setMargin(9);
#endif
    gridLayout15->setObjectName(QString::fromUtf8("gridLayout15"));
    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
    checkBox_holdTorque = new QCheckBox(groupBox_8);
    checkBox_holdTorque->setObjectName(QString::fromUtf8("checkBox_holdTorque"));
    checkBox_holdTorque->setFont(font5);
    checkBox_holdTorque->setChecked(true);
    checkBox_holdTorque->setTristate(false);

    gridLayout_2->addWidget(checkBox_holdTorque, 0, 0, 1, 2);

    pushButton_zStepResetOrigin = new QPushButton(groupBox_8);
    pushButton_zStepResetOrigin->setObjectName(QString::fromUtf8("pushButton_zStepResetOrigin"));
    pushButton_zStepResetOrigin->setFont(font5);

    gridLayout_2->addWidget(pushButton_zStepResetOrigin, 1, 0, 1, 2);

    label_96 = new QLabel(groupBox_8);
    label_96->setObjectName(QString::fromUtf8("label_96"));
    label_96->setFont(font5);
    label_96->setAlignment(Qt::AlignCenter);

    gridLayout_2->addWidget(label_96, 2, 0, 1, 2);

    pushButton_zStepUp = new QPushButton(groupBox_8);
    pushButton_zStepUp->setObjectName(QString::fromUtf8("pushButton_zStepUp"));
    pushButton_zStepUp->setFont(font5);

    gridLayout_2->addWidget(pushButton_zStepUp, 4, 0, 1, 1);

    pushButton_zStepDown = new QPushButton(groupBox_8);
    pushButton_zStepDown->setObjectName(QString::fromUtf8("pushButton_zStepDown"));
    pushButton_zStepDown->setFont(font5);

    gridLayout_2->addWidget(pushButton_zStepDown, 4, 1, 1, 1);

    doubleSpinBox_zPos = new QDoubleSpinBox(groupBox_8);
    doubleSpinBox_zPos->setObjectName(QString::fromUtf8("doubleSpinBox_zPos"));
    doubleSpinBox_zPos->setFont(font15);
    doubleSpinBox_zPos->setAlignment(Qt::AlignCenter);
    doubleSpinBox_zPos->setReadOnly(true);
    doubleSpinBox_zPos->setButtonSymbols(QAbstractSpinBox::NoButtons);
    doubleSpinBox_zPos->setMinimum(-10000);
    doubleSpinBox_zPos->setMaximum(10000);

    gridLayout_2->addWidget(doubleSpinBox_zPos, 3, 0, 1, 2);

    label_103 = new QLabel(groupBox_8);
    label_103->setObjectName(QString::fromUtf8("label_103"));
    label_103->setFont(font5);
    label_103->setAlignment(Qt::AlignCenter);

    gridLayout_2->addWidget(label_103, 5, 0, 1, 2);

    doubleSpinBox_moveToPos = new QDoubleSpinBox(groupBox_8);
    doubleSpinBox_moveToPos->setObjectName(QString::fromUtf8("doubleSpinBox_moveToPos"));
    doubleSpinBox_moveToPos->setFont(font5);
    doubleSpinBox_moveToPos->setMinimum(-5000);
    doubleSpinBox_moveToPos->setMaximum(5000);

    gridLayout_2->addWidget(doubleSpinBox_moveToPos, 10, 1, 1, 1);

    pushButton_zMoveTo = new QPushButton(groupBox_8);
    pushButton_zMoveTo->setObjectName(QString::fromUtf8("pushButton_zMoveTo"));
    pushButton_zMoveTo->setFont(font5);

    gridLayout_2->addWidget(pushButton_zMoveTo, 10, 0, 1, 1);

    doubleSpinBox_zManualStepSize = new QDoubleSpinBox(groupBox_8);
    doubleSpinBox_zManualStepSize->setObjectName(QString::fromUtf8("doubleSpinBox_zManualStepSize"));
    doubleSpinBox_zManualStepSize->setFont(font5);
    doubleSpinBox_zManualStepSize->setAlignment(Qt::AlignCenter);
    doubleSpinBox_zManualStepSize->setMinimum(-500);
    doubleSpinBox_zManualStepSize->setMaximum(500);
    doubleSpinBox_zManualStepSize->setValue(10);

    gridLayout_2->addWidget(doubleSpinBox_zManualStepSize, 7, 0, 1, 2);

    label_104 = new QLabel(groupBox_8);
    label_104->setObjectName(QString::fromUtf8("label_104"));
    label_104->setFont(font5);
    label_104->setAlignment(Qt::AlignCenter);

    gridLayout_2->addWidget(label_104, 9, 1, 1, 1);

    verticalSpacer_51 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_51, 11, 0, 1, 1);


    gridLayout15->addLayout(gridLayout_2, 0, 0, 1, 2);

    groupBox_7 = new QGroupBox(centralwidget);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    groupBox_7->setGeometry(QRect(610, 420, 177, 241));
    groupBox_7->setFont(font4);
    gridLayout16 = new QGridLayout(groupBox_7);
#ifndef Q_OS_MAC
    gridLayout16->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout16->setMargin(9);
#endif
    gridLayout16->setObjectName(QString::fromUtf8("gridLayout16"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    label_83 = new QLabel(groupBox_7);
    label_83->setObjectName(QString::fromUtf8("label_83"));
    label_83->setFont(font5);
    label_83->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_83);

    spinBox_Width = new QSpinBox(groupBox_7);
    spinBox_Width->setObjectName(QString::fromUtf8("spinBox_Width"));
    spinBox_Width->setFont(font5);
    spinBox_Width->setAlignment(Qt::AlignHCenter);
    spinBox_Width->setMaximum(2047);
    spinBox_Width->setValue(200);

    verticalLayout->addWidget(spinBox_Width);

    label_84 = new QLabel(groupBox_7);
    label_84->setObjectName(QString::fromUtf8("label_84"));
    label_84->setFont(font5);
    label_84->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_84);

    spinBox_Repeat = new QSpinBox(groupBox_7);
    spinBox_Repeat->setObjectName(QString::fromUtf8("spinBox_Repeat"));
    spinBox_Repeat->setFont(font5);
    spinBox_Repeat->setAlignment(Qt::AlignHCenter);
    spinBox_Repeat->setMaximum(200000);
    spinBox_Repeat->setValue(4096);

    verticalLayout->addWidget(spinBox_Repeat);

    label_85 = new QLabel(groupBox_7);
    label_85->setObjectName(QString::fromUtf8("label_85"));
    label_85->setFont(font5);
    label_85->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label_85);

    spinBox_linescanRate = new QSpinBox(groupBox_7);
    spinBox_linescanRate->setObjectName(QString::fromUtf8("spinBox_linescanRate"));
    spinBox_linescanRate->setEnabled(false);
    spinBox_linescanRate->setFont(font10);
    spinBox_linescanRate->setAlignment(Qt::AlignCenter);
    spinBox_linescanRate->setReadOnly(true);
    spinBox_linescanRate->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_linescanRate->setMaximum(999999);

    verticalLayout->addWidget(spinBox_linescanRate);


    gridLayout16->addLayout(verticalLayout, 0, 0, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout16->addItem(verticalSpacer_2, 3, 0, 1, 1);

    groupBox_6 = new QGroupBox(centralwidget);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(610, 0, 177, 175));
    groupBox_6->setFont(font4);
    gridLayout17 = new QGridLayout(groupBox_6);
#ifndef Q_OS_MAC
    gridLayout17->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout17->setMargin(9);
#endif
    gridLayout17->setObjectName(QString::fromUtf8("gridLayout17"));
    label_80 = new QLabel(groupBox_6);
    label_80->setObjectName(QString::fromUtf8("label_80"));
    label_80->setFont(font5);
    label_80->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    gridLayout17->addWidget(label_80, 5, 1, 1, 2);

    label_82 = new QLabel(groupBox_6);
    label_82->setObjectName(QString::fromUtf8("label_82"));
    QFont font17;
    font17.setFamily(QString::fromUtf8("MS Shell Dlg"));
    font17.setPointSize(8);
    font17.setBold(false);
    font17.setItalic(false);
    font17.setUnderline(false);
    font17.setWeight(50);
    font17.setStrikeOut(false);
    label_82->setFont(font17);
    label_82->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/circle_ind.bmp")));
    label_82->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout17->addWidget(label_82, 5, 0, 1, 1);

    label_79 = new QLabel(groupBox_6);
    label_79->setObjectName(QString::fromUtf8("label_79"));
    label_79->setFont(font5);
    label_79->setAlignment(Qt::AlignCenter);

    gridLayout17->addWidget(label_79, 2, 0, 1, 3);

    doubleSpinBox_AomVoltAmp = new QDoubleSpinBox(groupBox_6);
    doubleSpinBox_AomVoltAmp->setObjectName(QString::fromUtf8("doubleSpinBox_AomVoltAmp"));
    doubleSpinBox_AomVoltAmp->setFont(font5);
    doubleSpinBox_AomVoltAmp->setAlignment(Qt::AlignCenter);
    doubleSpinBox_AomVoltAmp->setDecimals(3);
    doubleSpinBox_AomVoltAmp->setMinimum(0);
    doubleSpinBox_AomVoltAmp->setMaximum(2.4);
    doubleSpinBox_AomVoltAmp->setSingleStep(0.005);
    doubleSpinBox_AomVoltAmp->setValue(0.4);

    gridLayout17->addWidget(doubleSpinBox_AomVoltAmp, 3, 0, 1, 3);

    pushButton_AomOff = new QPushButton(groupBox_6);
    pushButton_AomOff->setObjectName(QString::fromUtf8("pushButton_AomOff"));
    pushButton_AomOff->setEnabled(false);
    QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(pushButton_AomOff->sizePolicy().hasHeightForWidth());
    pushButton_AomOff->setSizePolicy(sizePolicy4);
    pushButton_AomOff->setMinimumSize(QSize(50, 23));
    pushButton_AomOff->setFont(font5);

    gridLayout17->addWidget(pushButton_AomOff, 4, 2, 1, 1);

    pushButton_AomOn = new QPushButton(groupBox_6);
    pushButton_AomOn->setObjectName(QString::fromUtf8("pushButton_AomOn"));
    sizePolicy4.setHeightForWidth(pushButton_AomOn->sizePolicy().hasHeightForWidth());
    pushButton_AomOn->setSizePolicy(sizePolicy4);
    pushButton_AomOn->setMinimumSize(QSize(50, 23));
    pushButton_AomOn->setFont(font5);

    gridLayout17->addWidget(pushButton_AomOn, 4, 0, 1, 2);

    checkBox_AomPulse = new QCheckBox(groupBox_6);
    checkBox_AomPulse->setObjectName(QString::fromUtf8("checkBox_AomPulse"));
    checkBox_AomPulse->setFont(font5);

    gridLayout17->addWidget(checkBox_AomPulse, 0, 0, 1, 2);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout17->addItem(verticalSpacer, 6, 1, 1, 1);

    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 550, 591, 121));
    groupBox->setFont(font4);
    gridLayout18 = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
    gridLayout18->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout18->setMargin(9);
#endif
    gridLayout18->setObjectName(QString::fromUtf8("gridLayout18"));
    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/hist.bmp")));

    gridLayout18->addWidget(label_7, 4, 0, 1, 1);

    gridLayout_4 = new QGridLayout();
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    gridLayout_4->setSizeConstraint(QLayout::SetFixedSize);
    horizontalSlider_Ch1MinScale = new QSlider(groupBox);
    horizontalSlider_Ch1MinScale->setObjectName(QString::fromUtf8("horizontalSlider_Ch1MinScale"));
    horizontalSlider_Ch1MinScale->setMinimum(0);
    horizontalSlider_Ch1MinScale->setMaximum(32767);
    horizontalSlider_Ch1MinScale->setValue(0);
    horizontalSlider_Ch1MinScale->setOrientation(Qt::Horizontal);

    gridLayout_4->addWidget(horizontalSlider_Ch1MinScale, 1, 1, 1, 1);

    label_35 = new QLabel(groupBox);
    label_35->setObjectName(QString::fromUtf8("label_35"));
    label_35->setFont(font9);

    gridLayout_4->addWidget(label_35, 1, 0, 1, 1);

    label_36 = new QLabel(groupBox);
    label_36->setObjectName(QString::fromUtf8("label_36"));
    label_36->setFont(font9);

    gridLayout_4->addWidget(label_36, 2, 0, 1, 1);

    label_41 = new QLabel(groupBox);
    label_41->setObjectName(QString::fromUtf8("label_41"));
    label_41->setFont(font9);

    gridLayout_4->addWidget(label_41, 0, 1, 1, 1);

    spinBox_Ch1MaxScale = new QSpinBox(groupBox);
    spinBox_Ch1MaxScale->setObjectName(QString::fromUtf8("spinBox_Ch1MaxScale"));
    QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy5.setHorizontalStretch(1);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(spinBox_Ch1MaxScale->sizePolicy().hasHeightForWidth());
    spinBox_Ch1MaxScale->setSizePolicy(sizePolicy5);
    spinBox_Ch1MaxScale->setFont(font9);
    spinBox_Ch1MaxScale->setAlignment(Qt::AlignCenter);
    spinBox_Ch1MaxScale->setReadOnly(false);
    spinBox_Ch1MaxScale->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_Ch1MaxScale->setMinimum(0);
    spinBox_Ch1MaxScale->setMaximum(32767);
    spinBox_Ch1MaxScale->setValue(32767);

    gridLayout_4->addWidget(spinBox_Ch1MaxScale, 2, 2, 1, 1);

    spinBox_Ch1MinScale = new QSpinBox(groupBox);
    spinBox_Ch1MinScale->setObjectName(QString::fromUtf8("spinBox_Ch1MinScale"));
    sizePolicy5.setHeightForWidth(spinBox_Ch1MinScale->sizePolicy().hasHeightForWidth());
    spinBox_Ch1MinScale->setSizePolicy(sizePolicy5);
    spinBox_Ch1MinScale->setFont(font9);
    spinBox_Ch1MinScale->setAlignment(Qt::AlignCenter);
    spinBox_Ch1MinScale->setReadOnly(false);
    spinBox_Ch1MinScale->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_Ch1MinScale->setMinimum(0);
    spinBox_Ch1MinScale->setMaximum(32767);
    spinBox_Ch1MinScale->setValue(0);

    gridLayout_4->addWidget(spinBox_Ch1MinScale, 1, 2, 1, 1);

    label_59 = new QLabel(groupBox);
    label_59->setObjectName(QString::fromUtf8("label_59"));
    label_59->setFont(font3);

    gridLayout_4->addWidget(label_59, 0, 0, 1, 1);

    horizontalSlider_Ch1MaxScale = new QSlider(groupBox);
    horizontalSlider_Ch1MaxScale->setObjectName(QString::fromUtf8("horizontalSlider_Ch1MaxScale"));
    horizontalSlider_Ch1MaxScale->setMinimum(0);
    horizontalSlider_Ch1MaxScale->setMaximum(32767);
    horizontalSlider_Ch1MaxScale->setValue(32767);
    horizontalSlider_Ch1MaxScale->setOrientation(Qt::Horizontal);

    gridLayout_4->addWidget(horizontalSlider_Ch1MaxScale, 2, 1, 1, 1);


    gridLayout18->addLayout(gridLayout_4, 2, 2, 3, 1);

    gridLayout_6 = new QGridLayout();
    gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
    horizontalSlider_Ch2MinScale = new QSlider(groupBox);
    horizontalSlider_Ch2MinScale->setObjectName(QString::fromUtf8("horizontalSlider_Ch2MinScale"));
    horizontalSlider_Ch2MinScale->setMinimum(0);
    horizontalSlider_Ch2MinScale->setMaximum(32767);
    horizontalSlider_Ch2MinScale->setValue(0);
    horizontalSlider_Ch2MinScale->setOrientation(Qt::Horizontal);
    horizontalSlider_Ch2MinScale->setTickPosition(QSlider::NoTicks);
    horizontalSlider_Ch2MinScale->setTickInterval(0);

    gridLayout_6->addWidget(horizontalSlider_Ch2MinScale, 1, 1, 1, 1);

    horizontalSlider_Ch2MaxScale = new QSlider(groupBox);
    horizontalSlider_Ch2MaxScale->setObjectName(QString::fromUtf8("horizontalSlider_Ch2MaxScale"));
    horizontalSlider_Ch2MaxScale->setMinimum(0);
    horizontalSlider_Ch2MaxScale->setMaximum(32767);
    horizontalSlider_Ch2MaxScale->setValue(32767);
    horizontalSlider_Ch2MaxScale->setOrientation(Qt::Horizontal);

    gridLayout_6->addWidget(horizontalSlider_Ch2MaxScale, 2, 1, 1, 1);

    spinBox_Ch2MinScale = new QSpinBox(groupBox);
    spinBox_Ch2MinScale->setObjectName(QString::fromUtf8("spinBox_Ch2MinScale"));
    sizePolicy5.setHeightForWidth(spinBox_Ch2MinScale->sizePolicy().hasHeightForWidth());
    spinBox_Ch2MinScale->setSizePolicy(sizePolicy5);
    spinBox_Ch2MinScale->setFont(font9);
    spinBox_Ch2MinScale->setAlignment(Qt::AlignCenter);
    spinBox_Ch2MinScale->setReadOnly(false);
    spinBox_Ch2MinScale->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_Ch2MinScale->setMinimum(0);
    spinBox_Ch2MinScale->setMaximum(32767);
    spinBox_Ch2MinScale->setValue(0);

    gridLayout_6->addWidget(spinBox_Ch2MinScale, 1, 2, 1, 1);

    spinBox_Ch2MaxScale = new QSpinBox(groupBox);
    spinBox_Ch2MaxScale->setObjectName(QString::fromUtf8("spinBox_Ch2MaxScale"));
    sizePolicy5.setHeightForWidth(spinBox_Ch2MaxScale->sizePolicy().hasHeightForWidth());
    spinBox_Ch2MaxScale->setSizePolicy(sizePolicy5);
    spinBox_Ch2MaxScale->setFont(font9);
    spinBox_Ch2MaxScale->setAlignment(Qt::AlignCenter);
    spinBox_Ch2MaxScale->setReadOnly(false);
    spinBox_Ch2MaxScale->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_Ch2MaxScale->setMinimum(0);
    spinBox_Ch2MaxScale->setMaximum(32767);
    spinBox_Ch2MaxScale->setValue(32767);

    gridLayout_6->addWidget(spinBox_Ch2MaxScale, 2, 2, 1, 1);

    label_37 = new QLabel(groupBox);
    label_37->setObjectName(QString::fromUtf8("label_37"));
    label_37->setFont(font9);

    gridLayout_6->addWidget(label_37, 1, 0, 1, 1);

    label_40 = new QLabel(groupBox);
    label_40->setObjectName(QString::fromUtf8("label_40"));
    label_40->setFont(font9);

    gridLayout_6->addWidget(label_40, 2, 0, 1, 1);

    label_42 = new QLabel(groupBox);
    label_42->setObjectName(QString::fromUtf8("label_42"));
    label_42->setFont(font9);

    gridLayout_6->addWidget(label_42, 0, 1, 1, 1);

    label_60 = new QLabel(groupBox);
    label_60->setObjectName(QString::fromUtf8("label_60"));
    label_60->setFont(font3);

    gridLayout_6->addWidget(label_60, 0, 0, 1, 1);


    gridLayout18->addLayout(gridLayout_6, 2, 3, 3, 1);

    label_7->raise();
    groupBox_2 = new QGroupBox(centralwidget);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 670, 491, 211));
    groupBox_2->setFont(font4);
    gridLayout19 = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
    gridLayout19->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout19->setMargin(9);
#endif
    gridLayout19->setObjectName(QString::fromUtf8("gridLayout19"));
    gridLayout_8 = new QGridLayout();
    gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
    gridLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
    pushButton_saveImageLoc = new QPushButton(groupBox_2);
    pushButton_saveImageLoc->setObjectName(QString::fromUtf8("pushButton_saveImageLoc"));
    pushButton_saveImageLoc->setFont(font9);

    gridLayout_8->addWidget(pushButton_saveImageLoc, 1, 0, 1, 1);

    pushButton_savePtLoc = new QPushButton(groupBox_2);
    pushButton_savePtLoc->setObjectName(QString::fromUtf8("pushButton_savePtLoc"));
    pushButton_savePtLoc->setFont(font9);

    gridLayout_8->addWidget(pushButton_savePtLoc, 1, 1, 1, 1);

    treeWidget_savedLocs = new QTreeWidget(groupBox_2);
    treeWidget_savedLocs->setObjectName(QString::fromUtf8("treeWidget_savedLocs"));
    QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Maximum);
    sizePolicy6.setHorizontalStretch(0);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(treeWidget_savedLocs->sizePolicy().hasHeightForWidth());
    treeWidget_savedLocs->setSizePolicy(sizePolicy6);
    QFont font18;
    font18.setFamily(QString::fromUtf8("Calibri"));
    font18.setPointSize(10);
    font18.setKerning(true);
    treeWidget_savedLocs->setFont(font18);
    treeWidget_savedLocs->setFrameShape(QFrame::StyledPanel);
    treeWidget_savedLocs->setLineWidth(1);
    treeWidget_savedLocs->setAutoScrollMargin(10);
    treeWidget_savedLocs->setIndentation(18);
    treeWidget_savedLocs->setRootIsDecorated(true);
    treeWidget_savedLocs->setUniformRowHeights(true);
    treeWidget_savedLocs->setAnimated(true);
    treeWidget_savedLocs->setAllColumnsShowFocus(false);
    treeWidget_savedLocs->setHeaderHidden(false);
    treeWidget_savedLocs->setColumnCount(6);

    gridLayout_8->addWidget(treeWidget_savedLocs, 2, 0, 1, 5);

    pushButton_goToLoc = new QPushButton(groupBox_2);
    pushButton_goToLoc->setObjectName(QString::fromUtf8("pushButton_goToLoc"));
    pushButton_goToLoc->setEnabled(true);
    pushButton_goToLoc->setFont(font9);

    gridLayout_8->addWidget(pushButton_goToLoc, 1, 2, 1, 1);

    pushButton = new QPushButton(groupBox_2);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setEnabled(false);
    pushButton->setFont(font9);

    gridLayout_8->addWidget(pushButton, 1, 4, 1, 1);


    gridLayout19->addLayout(gridLayout_8, 0, 0, 1, 1);

    label_8 = new QLabel(groupBox_2);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setPixmap(QPixmap(QString::fromUtf8("../../../Documents and Settings/FOIL/.designer/QTcode/QTGui source code/hist.bmp")));

    gridLayout19->addWidget(label_8, 1, 0, 1, 1);

    groupBox_9 = new QGroupBox(centralwidget);
    groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
    groupBox_9->setGeometry(QRect(520, 670, 461, 201));
    QFont font19;
    font19.setFamily(QString::fromUtf8("Calibri"));
    font19.setPointSize(14);
    font19.setBold(false);
    font19.setWeight(50);
    groupBox_9->setFont(font19);
    horizontalLayoutWidget = new QWidget(groupBox_9);
    horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
    horizontalLayoutWidget->setGeometry(QRect(10, 30, 441, 194));
    horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    textEdit_log = new QTextEdit(horizontalLayoutWidget);
    textEdit_log->setObjectName(QString::fromUtf8("textEdit_log"));
    QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy7.setHorizontalStretch(0);
    sizePolicy7.setVerticalStretch(0);
    sizePolicy7.setHeightForWidth(textEdit_log->sizePolicy().hasHeightForWidth());
    textEdit_log->setSizePolicy(sizePolicy7);
    textEdit_log->setMaximumSize(QSize(500, 16777215));
    QFont font20;
    font20.setPointSize(13);
    textEdit_log->setFont(font20);

    horizontalLayout->addWidget(textEdit_log);

    groupBox_10 = new QGroupBox(centralwidget);
    groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
    groupBox_10->setGeometry(QRect(610, 185, 177, 241));
    QFont font21;
    font21.setPointSize(14);
    groupBox_10->setFont(font21);
    verticalLayoutWidget = new QWidget(groupBox_10);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(10, 30, 161, 189));
    verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    verticalLayout_7->setContentsMargins(0, 0, 0, 0);
    gridLayout_5 = new QGridLayout();
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    spinBox_yPosBeamPark = new QSpinBox(verticalLayoutWidget);
    spinBox_yPosBeamPark->setObjectName(QString::fromUtf8("spinBox_yPosBeamPark"));
    spinBox_yPosBeamPark->setFont(font9);
    spinBox_yPosBeamPark->setAlignment(Qt::AlignCenter);
    spinBox_yPosBeamPark->setMaximum(2048);
    spinBox_yPosBeamPark->setValue(256);

    gridLayout_5->addWidget(spinBox_yPosBeamPark, 1, 1, 1, 1);

    label_29 = new QLabel(verticalLayoutWidget);
    label_29->setObjectName(QString::fromUtf8("label_29"));
    label_29->setFont(font9);

    gridLayout_5->addWidget(label_29, 0, 0, 1, 1);

    label_30 = new QLabel(verticalLayoutWidget);
    label_30->setObjectName(QString::fromUtf8("label_30"));
    label_30->setFont(font9);

    gridLayout_5->addWidget(label_30, 1, 0, 1, 1);

    spinBox_xPosBeamPark = new QSpinBox(verticalLayoutWidget);
    spinBox_xPosBeamPark->setObjectName(QString::fromUtf8("spinBox_xPosBeamPark"));
    spinBox_xPosBeamPark->setFont(font9);
    spinBox_xPosBeamPark->setAlignment(Qt::AlignCenter);
    spinBox_xPosBeamPark->setMaximum(2048);
    spinBox_xPosBeamPark->setValue(256);

    gridLayout_5->addWidget(spinBox_xPosBeamPark, 0, 1, 1, 1);


    verticalLayout_7->addLayout(gridLayout_5);

    pushButton_parkBeam = new QPushButton(verticalLayoutWidget);
    pushButton_parkBeam->setObjectName(QString::fromUtf8("pushButton_parkBeam"));
    sizePolicy1.setHeightForWidth(pushButton_parkBeam->sizePolicy().hasHeightForWidth());
    pushButton_parkBeam->setSizePolicy(sizePolicy1);
    pushButton_parkBeam->setFont(font9);

    verticalLayout_7->addWidget(pushButton_parkBeam);

    gridLayout_9 = new QGridLayout();
    gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
    spinBox = new QSpinBox(verticalLayoutWidget);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setFont(font9);
    spinBox->setAlignment(Qt::AlignCenter);
    spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox->setMaximum(2048);

    gridLayout_9->addWidget(spinBox, 1, 1, 1, 1);

    label_61 = new QLabel(verticalLayoutWidget);
    label_61->setObjectName(QString::fromUtf8("label_61"));
    label_61->setFont(font9);

    gridLayout_9->addWidget(label_61, 0, 0, 1, 1);

    label_62 = new QLabel(verticalLayoutWidget);
    label_62->setObjectName(QString::fromUtf8("label_62"));
    label_62->setFont(font9);

    gridLayout_9->addWidget(label_62, 1, 0, 1, 1);

    spinBox_2 = new QSpinBox(verticalLayoutWidget);
    spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
    spinBox_2->setFont(font9);
    spinBox_2->setAlignment(Qt::AlignCenter);
    spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBox_2->setMaximum(2048);

    gridLayout_9->addWidget(spinBox_2, 0, 1, 1, 1);


    verticalLayout_7->addLayout(gridLayout_9);

    verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_4);

    TwoPhotonMainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(TwoPhotonMainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    TwoPhotonMainWindow->setStatusBar(statusbar);
    menubar = new QMenuBar(TwoPhotonMainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 992, 22));
    menubar->setFont(font);
    menuAbout = new QMenu(menubar);
    menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    TwoPhotonMainWindow->setMenuBar(menubar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuView->menuAction());
    menubar->addAction(menuAbout->menuAction());
    menuAbout->addAction(actionDefault_Hardware_Connections);
    menuAbout->addAction(actionAbout_TwoPhotonSoftware);
    menuView->addAction(actionView_visionTools);
    menuView->addAction(actionView_viewChan1);
    menuView->addAction(actionView_viewChan2);
    menuFile->addAction(actionQuit);

    retranslateUi(TwoPhotonMainWindow);
    QObject::connect(doubleSpinBox_zPos, SIGNAL(valueChanged(double)), doubleSpinBox_zStartPos, SLOT(setValue(double)));

    tabWidget->setCurrentIndex(4);
    comboBox_xChannel->setCurrentIndex(2);
    comboBox_yChannel->setCurrentIndex(3);
    comboBox_InChan2->setCurrentIndex(3);
    comboBox_InChan1->setCurrentIndex(2);
    comboBox_Magnification->setCurrentIndex(0);
    comboBox_9->setCurrentIndex(6);
    comboBox_AomRefOutChan->setCurrentIndex(5);
    comboBox_AomChan->setCurrentIndex(4);


    QMetaObject::connectSlotsByName(TwoPhotonMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TwoPhotonMainWindow)
    {
    TwoPhotonMainWindow->setWindowTitle(QApplication::translate("TwoPhotonMainWindow", "FOIL::Two Photon Microscope Acquisition", 0, QApplication::UnicodeUTF8));
    actionAbout_TwoPhotonSoftware->setText(QApplication::translate("TwoPhotonMainWindow", "About TwoPhotonSoftware", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("TwoPhotonMainWindow", "New...", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("TwoPhotonMainWindow", "Open...", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("TwoPhotonMainWindow", "Save...", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("TwoPhotonMainWindow", "Quit", 0, QApplication::UnicodeUTF8));
    actionEdit_item_1->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 1", 0, QApplication::UnicodeUTF8));
    actionEdit_item_2->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 2", 0, QApplication::UnicodeUTF8));
    actionEdit_item_3->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 3", 0, QApplication::UnicodeUTF8));
    actionEdit_item_4->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 4", 0, QApplication::UnicodeUTF8));
    actionEdit_item_5->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 5", 0, QApplication::UnicodeUTF8));
    actionEdit_item_6->setText(QApplication::translate("TwoPhotonMainWindow", "Edit item 6", 0, QApplication::UnicodeUTF8));
    actionView_visionTools->setText(QApplication::translate("TwoPhotonMainWindow", "NI Vision Tools", 0, QApplication::UnicodeUTF8));
    actionView_viewChan1->setText(QApplication::translate("TwoPhotonMainWindow", "Channel 1", 0, QApplication::UnicodeUTF8));
    actionSubmenu_1->setText(QApplication::translate("TwoPhotonMainWindow", "submenu 1", 0, QApplication::UnicodeUTF8));
    actionSubmenu_2->setText(QApplication::translate("TwoPhotonMainWindow", "submenu 2", 0, QApplication::UnicodeUTF8));
    actionScan_Setup->setText(QApplication::translate("TwoPhotonMainWindow", "Scan Setup", 0, QApplication::UnicodeUTF8));
    actionImage_Setup->setText(QApplication::translate("TwoPhotonMainWindow", "Image Setup", 0, QApplication::UnicodeUTF8));
    actionAcquisition_Setup->setText(QApplication::translate("TwoPhotonMainWindow", "Acquisition Setup", 0, QApplication::UnicodeUTF8));
    actionShutter_Setup->setText(QApplication::translate("TwoPhotonMainWindow", "Shutter Setup", 0, QApplication::UnicodeUTF8));
    actionAOM_Setup->setText(QApplication::translate("TwoPhotonMainWindow", "AOM Setup", 0, QApplication::UnicodeUTF8));
    actionView_viewChan2->setText(QApplication::translate("TwoPhotonMainWindow", "Channel 2", 0, QApplication::UnicodeUTF8));
    actionDefault_Hardware_Connections->setText(QApplication::translate("TwoPhotonMainWindow", "Default Hardware Connections", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("TwoPhotonMainWindow", "X-Channel", 0, QApplication::UnicodeUTF8));
    comboBox_xChannel->clear();
    comboBox_xChannel->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao3", 0, QApplication::UnicodeUTF8)
    );
    label_13->setText(QApplication::translate("TwoPhotonMainWindow", "Y-Channel", 0, QApplication::UnicodeUTF8));
    comboBox_yChannel->clear();
    comboBox_yChannel->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao3", 0, QApplication::UnicodeUTF8)
    );
    label_26->setText(QApplication::translate("TwoPhotonMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Sample Rate</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_SampleRate->setSuffix(QApplication::translate("TwoPhotonMainWindow", " Hz", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("TwoPhotonMainWindow", "X Min", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_xMinVolts->setPrefix(QString());
    doubleSpinBox_xMinVolts->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("TwoPhotonMainWindow", "Y Min", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_yMinVolts->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("TwoPhotonMainWindow", "X Max", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_xMaxVolts->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("TwoPhotonMainWindow", "Y Max", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_yMaxVolts->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    label_28->setText(QApplication::translate("TwoPhotonMainWindow", "Line Rate", 0, QApplication::UnicodeUTF8));
    spinBox_LineRate->setSuffix(QApplication::translate("TwoPhotonMainWindow", " Hz", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("TwoPhotonMainWindow", "# X Pixels", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("TwoPhotonMainWindow", "# Y Pixels", 0, QApplication::UnicodeUTF8));
    label_27->setText(QApplication::translate("TwoPhotonMainWindow", "Frame Time", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_frametime->setSuffix(QApplication::translate("TwoPhotonMainWindow", " s", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("TwoPhotonMainWindow", "Zoom Factor", 0, QApplication::UnicodeUTF8));
    spinBox_ZoomFactor->setSuffix(QApplication::translate("TwoPhotonMainWindow", "x", 0, QApplication::UnicodeUTF8));
    label_70->setText(QApplication::translate("TwoPhotonMainWindow", "F.O.V.", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_FOV->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    pushButton_RotateGalvos->setText(QApplication::translate("TwoPhotonMainWindow", "Galvo Clear", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(scanSetupTab), QApplication::translate("TwoPhotonMainWindow", "Scan Setup", 0, QApplication::UnicodeUTF8));
    label_48->setText(QApplication::translate("TwoPhotonMainWindow", "X-Offset", 0, QApplication::UnicodeUTF8));
    label_49->setText(QApplication::translate("TwoPhotonMainWindow", "ADC Resolution (\302\265V)", 0, QApplication::UnicodeUTF8));
    label_47->setText(QApplication::translate("TwoPhotonMainWindow", "Input #2", 0, QApplication::UnicodeUTF8));
    spinBox_xOffset->setSuffix(QApplication::translate("TwoPhotonMainWindow", " px", 0, QApplication::UnicodeUTF8));
    label_50->setText(QApplication::translate("TwoPhotonMainWindow", "Analog Input Range", 0, QApplication::UnicodeUTF8));
    comboBox_InChan2->clear();
    comboBox_InChan2->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai6", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai7", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai8", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai9", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai10", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai11", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai12", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai13", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai14", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai15", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai16", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai17", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai18", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai19", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai20", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai21", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai22", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai23", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai24", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai25", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai26", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai27", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai28", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai29", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai30", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai31", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai6", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai7", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai8", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai9", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai10", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai11", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai12", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai13", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai14", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai15", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai16", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai17", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai18", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai19", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai20", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai21", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai22", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai23", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai24", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai25", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai26", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai27", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai28", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai29", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai30", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai31", 0, QApplication::UnicodeUTF8)
    );
    comboBox_InChan1->clear();
    comboBox_InChan1->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai6", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai7", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai8", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai9", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai10", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai11", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai12", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai13", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai14", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai15", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai16", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai17", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai18", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai19", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai20", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai21", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai22", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai23", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai24", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai25", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai26", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai27", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai28", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai29", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai30", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ai31", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai4", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai5", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai6", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai7", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai8", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai9", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai10", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai11", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai12", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai13", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai14", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai15", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai16", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai17", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai18", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai19", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai20", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai21", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai22", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai23", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai24", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai25", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai26", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai27", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai28", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai29", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai30", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ai31", 0, QApplication::UnicodeUTF8)
    );
    comboBox_AIRange->clear();
    comboBox_AIRange->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "-2V to 2V", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "-5V to 5V", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "-10V to 10V", 0, QApplication::UnicodeUTF8)
    );
    label_33->setText(QApplication::translate("TwoPhotonMainWindow", "Input #1", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_9->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265V", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(acqSetupTab), QApplication::translate("TwoPhotonMainWindow", "Acquisition Setup", 0, QApplication::UnicodeUTF8));
    label_38->setText(QApplication::translate("TwoPhotonMainWindow", "X:", 0, QApplication::UnicodeUTF8));
    label_34->setText(QApplication::translate("TwoPhotonMainWindow", "Y:", 0, QApplication::UnicodeUTF8));
    label_32->setText(QApplication::translate("TwoPhotonMainWindow", "Field of View", 0, QApplication::UnicodeUTF8));
    spinBox_yFov->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    spinBox_xFov->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_45->setText(QApplication::translate("TwoPhotonMainWindow", "Scaling", 0, QApplication::UnicodeUTF8));
    spinBox_Scaling->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m/V", 0, QApplication::UnicodeUTF8));
    label_31->setText(QApplication::translate("TwoPhotonMainWindow", "Objective Magnification", 0, QApplication::UnicodeUTF8));
    comboBox_Magnification->clear();
    comboBox_Magnification->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "10x", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "20x", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "40x", 0, QApplication::UnicodeUTF8)
    );
    label_39->setText(QApplication::translate("TwoPhotonMainWindow", "X:", 0, QApplication::UnicodeUTF8));
    label_44->setText(QApplication::translate("TwoPhotonMainWindow", "Resolution", 0, QApplication::UnicodeUTF8));
    label_43->setText(QApplication::translate("TwoPhotonMainWindow", "Y:", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_xRes->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m/px", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_yRes->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m/px", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(imageSetupTab), QApplication::translate("TwoPhotonMainWindow", "Image Setup", 0, QApplication::UnicodeUTF8));
    label_52->setText(QApplication::translate("TwoPhotonMainWindow", "Laser Shutter Channel", 0, QApplication::UnicodeUTF8));
    comboBox_9->clear();
    comboBox_9->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao3", 0, QApplication::UnicodeUTF8)
    );
    tabWidget->setTabText(tabWidget->indexOf(shutterSetupTab), QApplication::translate("TwoPhotonMainWindow", "Shutter Setup", 0, QApplication::UnicodeUTF8));
    label_56->setText(QApplication::translate("TwoPhotonMainWindow", "AOM Ref Out Channel", 0, QApplication::UnicodeUTF8));
    comboBox_AomRefOutChan->clear();
    comboBox_AomRefOutChan->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao3", 0, QApplication::UnicodeUTF8)
    );
    label_53->setText(QApplication::translate("TwoPhotonMainWindow", "Experiment Duration", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_duration->setSuffix(QApplication::translate("TwoPhotonMainWindow", " s", 0, QApplication::UnicodeUTF8));
    checkBox_AomCont->setText(QApplication::translate("TwoPhotonMainWindow", "Continuous?", 0, QApplication::UnicodeUTF8));
    label_64->setText(QApplication::translate("TwoPhotonMainWindow", "On Time", 0, QApplication::UnicodeUTF8));
    spinBox_OnTime->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265s", 0, QApplication::UnicodeUTF8));
    label_55->setText(QApplication::translate("TwoPhotonMainWindow", "AOM Channel", 0, QApplication::UnicodeUTF8));
    comboBox_AomChan->clear();
    comboBox_AomChan->insertItems(0, QStringList()
     << QApplication::translate("TwoPhotonMainWindow", "Browse...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Filter...", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev1/ao3", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao0", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao1", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao2", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("TwoPhotonMainWindow", "Dev2/ao3", 0, QApplication::UnicodeUTF8)
    );
    label_58->setText(QApplication::translate("TwoPhotonMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Repetition Rate</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    spinBox_RepRate->setSuffix(QApplication::translate("TwoPhotonMainWindow", " Hz", 0, QApplication::UnicodeUTF8));
    label_57->setText(QApplication::translate("TwoPhotonMainWindow", "Ref Out Voltage (V)", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(aOMSetupTab), QApplication::translate("TwoPhotonMainWindow", "EOM Setup", 0, QApplication::UnicodeUTF8));
    label_63->setText(QApplication::translate("TwoPhotonMainWindow", "Serial Ports", 0, QApplication::UnicodeUTF8));
    label_65->setText(QApplication::translate("TwoPhotonMainWindow", "XY Stepper Controller", 0, QApplication::UnicodeUTF8));
    label_69->setText(QApplication::translate("TwoPhotonMainWindow", "Z Stepper Controller", 0, QApplication::UnicodeUTF8));
    pushButton_connectXYCom->setText(QApplication::translate("TwoPhotonMainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    pushButton_connectZCom->setText(QApplication::translate("TwoPhotonMainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TwoPhotonMainWindow", "Hardware Config", 0, QApplication::UnicodeUTF8));
    label_72->setText(QApplication::translate("TwoPhotonMainWindow", "TCP/IP Server Port", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TwoPhotonMainWindow", "TCSPC Setup", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("TwoPhotonMainWindow", "Acquisition", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("TwoPhotonMainWindow", "3D Acquisition Parameters", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("TwoPhotonMainWindow", "Z Start Pos", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_zStartPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("TwoPhotonMainWindow", "Z Step Size", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_zStepSize->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("TwoPhotonMainWindow", "Z Stop Pos", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_zStopPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("TwoPhotonMainWindow", "# of Steps", 0, QApplication::UnicodeUTF8));
    checkBox_3dAcq->setText(QApplication::translate("TwoPhotonMainWindow", "3D", 0, QApplication::UnicodeUTF8));
    label_46->setText(QApplication::translate("TwoPhotonMainWindow", "Intensity Scaling", 0, QApplication::UnicodeUTF8));
    checkBox_laserIntAdjust->setText(QApplication::translate("TwoPhotonMainWindow", "Enabled", 0, QApplication::UnicodeUTF8));
    label_51->setText(QApplication::translate("TwoPhotonMainWindow", "EOM Top", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_TopVoltage->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    label_54->setText(QApplication::translate("TwoPhotonMainWindow", "EOM Bottom", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_BottomVoltage->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    pushButton_changeDir->setText(QApplication::translate("TwoPhotonMainWindow", " Change Directory", 0, QApplication::UnicodeUTF8));
    pushButton_Scan->setText(QApplication::translate("TwoPhotonMainWindow", "Scan", 0, QApplication::UnicodeUTF8));
    pushButton_Stop->setText(QApplication::translate("TwoPhotonMainWindow", "Stop", 0, QApplication::UnicodeUTF8));
    checkBox_ContinAcq->setText(QApplication::translate("TwoPhotonMainWindow", "Contin?", 0, QApplication::UnicodeUTF8));
    checkBox_TrigAcq->setText(QApplication::translate("TwoPhotonMainWindow", "Trigg?", 0, QApplication::UnicodeUTF8));
    pushButton_Acquire->setText(QApplication::translate("TwoPhotonMainWindow", "Acquire", 0, QApplication::UnicodeUTF8));
    pushButton_linescanAcq->setText(QApplication::translate("TwoPhotonMainWindow", "Linescan Acquire", 0, QApplication::UnicodeUTF8));
    pushButton_lifetimeAcq->setText(QApplication::translate("TwoPhotonMainWindow", "Acquire Lifetime Data", 0, QApplication::UnicodeUTF8));
    pushButton_stopAcq->setText(QApplication::translate("TwoPhotonMainWindow", "Stop", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("TwoPhotonMainWindow", "Output Directory:", 0, QApplication::UnicodeUTF8));
    lineEdit_OutputDir->setText(QApplication::translate("TwoPhotonMainWindow", "C:\\Data\\", 0, QApplication::UnicodeUTF8));
    checkBox_Input1->setText(QApplication::translate("TwoPhotonMainWindow", "Channel #1", 0, QApplication::UnicodeUTF8));
    checkBox_Input2->setText(QApplication::translate("TwoPhotonMainWindow", "Channel #2", 0, QApplication::UnicodeUTF8));
    checkBox_Save->setText(QApplication::translate("TwoPhotonMainWindow", "Save?", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("TwoPhotonMainWindow", "<u># of Frames", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("TwoPhotonMainWindow", "Disk Space Needed", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_diskSpace->setSuffix(QApplication::translate("TwoPhotonMainWindow", " MB", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("TwoPhotonMainWindow", "Scanning:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QString());
    label_3->setText(QString());
    label_4->setText(QString());
    label_6->setText(QApplication::translate("TwoPhotonMainWindow", "Acquiring:", 0, QApplication::UnicodeUTF8));
    label_71->setText(QApplication::translate("TwoPhotonMainWindow", "Lifetime Acq #:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("TwoPhotonMainWindow", "Laser On:", 0, QApplication::UnicodeUTF8));
    pushButton_UpdateLTAcqNum->setText(QApplication::translate("TwoPhotonMainWindow", "Reset #", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("TwoPhotonMainWindow", "XY-Stepping", 0, QApplication::UnicodeUTF8));
    pushButton_ResetOrigin->setText(QApplication::translate("TwoPhotonMainWindow", "Reset Origin", 0, QApplication::UnicodeUTF8));
    label_66->setText(QApplication::translate("TwoPhotonMainWindow", "Position", 0, QApplication::UnicodeUTF8));
    label_67->setText(QApplication::translate("TwoPhotonMainWindow", "X:", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_xPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_yPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_68->setText(QApplication::translate("TwoPhotonMainWindow", "Y:", 0, QApplication::UnicodeUTF8));
    label_77->setText(QApplication::translate("TwoPhotonMainWindow", "Step Magnitude", 0, QApplication::UnicodeUTF8));
    label_78->setText(QApplication::translate("TwoPhotonMainWindow", "Coarse:", 0, QApplication::UnicodeUTF8));
    label_81->setText(QApplication::translate("TwoPhotonMainWindow", "Fine:", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_coarseField->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_fineField->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_25->setText(QApplication::translate("TwoPhotonMainWindow", "Stepping Controls", 0, QApplication::UnicodeUTF8));
    pushButton_coarseUp->setText(QString());
    toolButton_fineDown->setText(QApplication::translate("TwoPhotonMainWindow", "...", 0, QApplication::UnicodeUTF8));
    toolButton_fineRight->setText(QApplication::translate("TwoPhotonMainWindow", "...", 0, QApplication::UnicodeUTF8));
    toolButton_fineLeft->setText(QApplication::translate("TwoPhotonMainWindow", "...", 0, QApplication::UnicodeUTF8));
    toolButton_fineUp->setText(QApplication::translate("TwoPhotonMainWindow", "...", 0, QApplication::UnicodeUTF8));
    pushButton_coarseLeft->setText(QString());
    pushButton_coarseDown->setText(QString());
    pushButton_coarseRight->setText(QString());
    groupBox_8->setTitle(QApplication::translate("TwoPhotonMainWindow", "Z-Stepping", 0, QApplication::UnicodeUTF8));
    checkBox_holdTorque->setText(QApplication::translate("TwoPhotonMainWindow", "Holding Torque", 0, QApplication::UnicodeUTF8));
    pushButton_zStepResetOrigin->setText(QApplication::translate("TwoPhotonMainWindow", "Reset Origin", 0, QApplication::UnicodeUTF8));
    label_96->setText(QApplication::translate("TwoPhotonMainWindow", "<u>Z Position", 0, QApplication::UnicodeUTF8));
    pushButton_zStepUp->setText(QApplication::translate("TwoPhotonMainWindow", "Step Up", 0, QApplication::UnicodeUTF8));
    pushButton_zStepDown->setText(QApplication::translate("TwoPhotonMainWindow", "Step Down", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_zPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_103->setText(QApplication::translate("TwoPhotonMainWindow", "Step Size", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_moveToPos->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    pushButton_zMoveTo->setText(QApplication::translate("TwoPhotonMainWindow", "Move To", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_zManualStepSize->setSuffix(QApplication::translate("TwoPhotonMainWindow", " \302\265m", 0, QApplication::UnicodeUTF8));
    label_104->setText(QApplication::translate("TwoPhotonMainWindow", "Position", 0, QApplication::UnicodeUTF8));
    groupBox_7->setTitle(QApplication::translate("TwoPhotonMainWindow", "Line Scan", 0, QApplication::UnicodeUTF8));
    label_83->setText(QApplication::translate("TwoPhotonMainWindow", "Width", 0, QApplication::UnicodeUTF8));
    label_84->setText(QApplication::translate("TwoPhotonMainWindow", "Repeats", 0, QApplication::UnicodeUTF8));
    label_85->setText(QApplication::translate("TwoPhotonMainWindow", "Line Rate", 0, QApplication::UnicodeUTF8));
    spinBox_linescanRate->setSuffix(QApplication::translate("TwoPhotonMainWindow", " Hz", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("TwoPhotonMainWindow", "Laser Intensity", 0, QApplication::UnicodeUTF8));
    label_80->setText(QApplication::translate("TwoPhotonMainWindow", "EOM Status", 0, QApplication::UnicodeUTF8));
    label_82->setText(QString());
    label_79->setText(QApplication::translate("TwoPhotonMainWindow", "EOM Vol. Amp", 0, QApplication::UnicodeUTF8));
    doubleSpinBox_AomVoltAmp->setSuffix(QApplication::translate("TwoPhotonMainWindow", " V", 0, QApplication::UnicodeUTF8));
    pushButton_AomOff->setText(QApplication::translate("TwoPhotonMainWindow", "OFF", 0, QApplication::UnicodeUTF8));
    pushButton_AomOn->setText(QApplication::translate("TwoPhotonMainWindow", "ON", 0, QApplication::UnicodeUTF8));
    checkBox_AomPulse->setText(QApplication::translate("TwoPhotonMainWindow", "Pulsed?", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("TwoPhotonMainWindow", "Input Channel Intensity", 0, QApplication::UnicodeUTF8));
    label_7->setText(QString());
    label_35->setText(QApplication::translate("TwoPhotonMainWindow", "Minimum", 0, QApplication::UnicodeUTF8));
    label_36->setText(QApplication::translate("TwoPhotonMainWindow", "Maximum", 0, QApplication::UnicodeUTF8));
    label_41->setText(QApplication::translate("TwoPhotonMainWindow", "Scaling", 0, QApplication::UnicodeUTF8));
    label_59->setText(QApplication::translate("TwoPhotonMainWindow", "CH 1", 0, QApplication::UnicodeUTF8));
    label_37->setText(QApplication::translate("TwoPhotonMainWindow", "Minimum", 0, QApplication::UnicodeUTF8));
    label_40->setText(QApplication::translate("TwoPhotonMainWindow", "Maximum", 0, QApplication::UnicodeUTF8));
    label_42->setText(QApplication::translate("TwoPhotonMainWindow", "Scaling", 0, QApplication::UnicodeUTF8));
    label_60->setText(QApplication::translate("TwoPhotonMainWindow", "CH 2", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("TwoPhotonMainWindow", "Saved Coordinates", 0, QApplication::UnicodeUTF8));
    pushButton_saveImageLoc->setText(QApplication::translate("TwoPhotonMainWindow", "Save Loc", 0, QApplication::UnicodeUTF8));
    pushButton_savePtLoc->setText(QApplication::translate("TwoPhotonMainWindow", "Save Pt", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(0, QApplication::translate("TwoPhotonMainWindow", "Description", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(1, QApplication::translate("TwoPhotonMainWindow", "X (\302\265m)", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(2, QApplication::translate("TwoPhotonMainWindow", "Y (\302\265m)", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(3, QApplication::translate("TwoPhotonMainWindow", "Z (\302\265m)", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(4, QApplication::translate("TwoPhotonMainWindow", "x (px)", 0, QApplication::UnicodeUTF8));
    treeWidget_savedLocs->headerItem()->setText(5, QApplication::translate("TwoPhotonMainWindow", "y (px)", 0, QApplication::UnicodeUTF8));
    pushButton_goToLoc->setText(QApplication::translate("TwoPhotonMainWindow", "Go", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("TwoPhotonMainWindow", "Delete", 0, QApplication::UnicodeUTF8));
    label_8->setText(QString());
    groupBox_9->setTitle(QApplication::translate("TwoPhotonMainWindow", "Log", 0, QApplication::UnicodeUTF8));
    textEdit_log->setHtml(QApplication::translate("TwoPhotonMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:6pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    groupBox_10->setTitle(QApplication::translate("TwoPhotonMainWindow", "ROI", 0, QApplication::UnicodeUTF8));
    spinBox_yPosBeamPark->setSuffix(QApplication::translate("TwoPhotonMainWindow", " px", 0, QApplication::UnicodeUTF8));
    label_29->setText(QApplication::translate("TwoPhotonMainWindow", "X Position", 0, QApplication::UnicodeUTF8));
    label_30->setText(QApplication::translate("TwoPhotonMainWindow", "Y Position", 0, QApplication::UnicodeUTF8));
    spinBox_xPosBeamPark->setSuffix(QApplication::translate("TwoPhotonMainWindow", " px", 0, QApplication::UnicodeUTF8));
    pushButton_parkBeam->setText(QApplication::translate("TwoPhotonMainWindow", "Park Beam", 0, QApplication::UnicodeUTF8));
    spinBox->setSuffix(QApplication::translate("TwoPhotonMainWindow", " px", 0, QApplication::UnicodeUTF8));
    label_61->setText(QApplication::translate("TwoPhotonMainWindow", "X", 0, QApplication::UnicodeUTF8));
    label_62->setText(QApplication::translate("TwoPhotonMainWindow", "Y", 0, QApplication::UnicodeUTF8));
    spinBox_2->setSuffix(QApplication::translate("TwoPhotonMainWindow", " px", 0, QApplication::UnicodeUTF8));
    menuAbout->setTitle(QApplication::translate("TwoPhotonMainWindow", "Help", 0, QApplication::UnicodeUTF8));
    menuView->setTitle(QApplication::translate("TwoPhotonMainWindow", "View", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("TwoPhotonMainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TwoPhotonMainWindow: public Ui_TwoPhotonMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOPHOTON_H
