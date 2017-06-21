/********************************************************************************
** Form generated from reading UI file 'streetgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREETGENERATOR_H
#define UI_STREETGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glimagepreview.h"
#include "qstreetrenderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_StreetGenerator
{
public:
    QAction *actionBuilding_Generator;
    QAction *actionTexture_Generator;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QPushButton *buttonBuildingType;
    QLabel *labelPMap;
    QPushButton *buttonHMap;
    QLabel *labelGMap;
    QPushButton *cmdClearBuildingType;
    QLabel *labelSMap;
    QPushButton *cmdClearGeog;
    QLabel *labelBMap;
    QPushButton *cmdClearStreetMap;
    QPushButton *cmdClearHeight;
    GLImagePreview *hMapRender;
    QPushButton *buttonGMap;
    QPushButton *buttonPMap;
    QLabel *labelHMap;
    GLImagePreview *patternMapRender;
    GLImagePreview *geogMapRender;
    GLImagePreview *popMapRender;
    GLImagePreview *buildingTypeRender;
    QPushButton *buttonSMap;
    QPushButton *cmdClearPop;
    QTabWidget *tabParameters;
    QWidget *tabStreetParams;
    QFormLayout *formLayout_3;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout;
    QDoubleSpinBox *highwayGrowthFactor;
    QDoubleSpinBox *streetGrowthFactor;
    QLabel *label_25;
    QSlider *sliderPopSearchRadius;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *sliderSearchAngleIncrease;
    QSlider *sliderRoadSampleInterval;
    QLabel *label_7;
    QSlider *slideRoadSearchAngle;
    QLabel *label_24;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QSpinBox *spnStreetDelay;
    QLabel *label_48;
    QLabel *label_33;
    QDoubleSpinBox *spinStreetWidth;
    QLabel *label_9;
    QLabel *label_34;
    QSpinBox *spinMaxBridgeLength;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QSpinBox *spinMaxRoadAngleChange;
    QLabel *label_14;
    QSlider *slideManhattanBlockHeight;
    QSpinBox *spinHighwayLength;
    QSlider *slideManhattanBlocKWidth;
    QDoubleSpinBox *spinHighwayWidth;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_22;
    QSpinBox *spinStreetLength;
    QDoubleSpinBox *spinRoadBranchProb;
    QDoubleSpinBox *spnLengthVariation;
    QLabel *label_39;
    QLabel *label_49;
    QSpinBox *spnMainroadFollowLength;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QSpinBox *spinRoadExtendLength;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *spinMinRoadLength;
    QLabel *label_12;
    QSpinBox *spinRoadSnapRadius;
    QLabel *label_18;
    QDoubleSpinBox *spinRoadPruneFactor;
    QGroupBox *groupBox_11;
    QFormLayout *formLayout_4;
    QFormLayout *formLayout_2;
    QLabel *label_40;
    QLabel *label_42;
    QSpinBox *spnStartX;
    QSpinBox *spnStartY;
    QLabel *label_41;
    QSpinBox *spnEndX;
    QSpinBox *spnEndY;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_12;
    QRadioButton *radUseWeightedStreet;
    QRadioButton *radUseMajorityStreet;
    QWidget *tabBuildingParams;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_31;
    QCheckBox *chkAllowLotMerge;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_6;
    QDoubleSpinBox *spinLotGenerationOffset;
    QSpinBox *spinMaxBuildingArea;
    QSpinBox *spinMinBuildingArea;
    QLabel *label_32;
    QSpinBox *spinMinLotDim;
    QSpinBox *spinMaxLotDim;
    QGroupBox *groupBox_9;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *spnHighriseMinPopDensity;
    QLabel *label_38;
    QLabel *label_28;
    QCheckBox *chkAllowSkyscrapers;
    QDoubleSpinBox *spnMinSkyscraperPopDensity;
    QDoubleSpinBox *spnSkyscraperPlacementChance;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_43;
    QDoubleSpinBox *spnCommercialHeight;
    QLabel *label_44;
    QLabel *label_45;
    QDoubleSpinBox *spnHighriseHeight;
    QDoubleSpinBox *spnHouseHeight;
    QDoubleSpinBox *spnIndustrialHeight;
    QDoubleSpinBox *spnSkyscraperHeight;
    QLabel *label_46;
    QLabel *label_47;
    QGroupBox *groupBox_10;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_7;
    QLabel *label_35;
    QDoubleSpinBox *spnBaseHeight;
    QLabel *label_36;
    QLabel *label_37;
    QDoubleSpinBox *spnHeightScale;
    QGroupBox *groupBox_3;
    QPushButton *cmdSaveOutput;
    QPushButton *cmdSaveOutputImage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radShowPopulation;
    QRadioButton *radShowGeography;
    QRadioButton *radShowHeightmap;
    QRadioButton *radShowPatternmap;
    QRadioButton *radShowNone;
    QCheckBox *chkShowVerts;
    QCheckBox *chkShowRegions;
    QCheckBox *chkShowLots;
    QWidget *layoutWidget2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *intSeedValue;
    QCheckBox *chkTimeSeed;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QPushButton *cmdReset;
    QPushButton *cmdStep;
    QPushButton *cmdGenerateStreets;
    QPushButton *cmdFilterRoads;
    QPushButton *cmdGenerateRegions;
    QPushButton *cmdCreateBuildingLots;
    QPushButton *cmdCreateView;
    QPushButton *cmdLoadImageDirectory;
    QStreetRenderWidget *streetRender;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *StreetGenerator)
    {
        if (StreetGenerator->objectName().isEmpty())
            StreetGenerator->setObjectName(QStringLiteral("StreetGenerator"));
        StreetGenerator->resize(1821, 1034);
        actionBuilding_Generator = new QAction(StreetGenerator);
        actionBuilding_Generator->setObjectName(QStringLiteral("actionBuilding_Generator"));
        actionTexture_Generator = new QAction(StreetGenerator);
        actionTexture_Generator->setObjectName(QStringLiteral("actionTexture_Generator"));
        centralWidget = new QWidget(StreetGenerator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(350, 700, 1021, 301));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 20, 1021, 271));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1542, 252));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        buttonBuildingType = new QPushButton(scrollAreaWidgetContents);
        buttonBuildingType->setObjectName(QStringLiteral("buttonBuildingType"));

        gridLayout_8->addWidget(buttonBuildingType, 1, 14, 1, 1);

        labelPMap = new QLabel(scrollAreaWidgetContents);
        labelPMap->setObjectName(QStringLiteral("labelPMap"));

        gridLayout_8->addWidget(labelPMap, 1, 3, 1, 1);

        buttonHMap = new QPushButton(scrollAreaWidgetContents);
        buttonHMap->setObjectName(QStringLiteral("buttonHMap"));

        gridLayout_8->addWidget(buttonHMap, 1, 2, 1, 1);

        labelGMap = new QLabel(scrollAreaWidgetContents);
        labelGMap->setObjectName(QStringLiteral("labelGMap"));

        gridLayout_8->addWidget(labelGMap, 1, 6, 1, 1);

        cmdClearBuildingType = new QPushButton(scrollAreaWidgetContents);
        cmdClearBuildingType->setObjectName(QStringLiteral("cmdClearBuildingType"));

        gridLayout_8->addWidget(cmdClearBuildingType, 1, 13, 1, 1);

        labelSMap = new QLabel(scrollAreaWidgetContents);
        labelSMap->setObjectName(QStringLiteral("labelSMap"));

        gridLayout_8->addWidget(labelSMap, 1, 9, 1, 1);

        cmdClearGeog = new QPushButton(scrollAreaWidgetContents);
        cmdClearGeog->setObjectName(QStringLiteral("cmdClearGeog"));

        gridLayout_8->addWidget(cmdClearGeog, 1, 7, 1, 1);

        labelBMap = new QLabel(scrollAreaWidgetContents);
        labelBMap->setObjectName(QStringLiteral("labelBMap"));

        gridLayout_8->addWidget(labelBMap, 1, 12, 1, 1);

        cmdClearStreetMap = new QPushButton(scrollAreaWidgetContents);
        cmdClearStreetMap->setObjectName(QStringLiteral("cmdClearStreetMap"));

        gridLayout_8->addWidget(cmdClearStreetMap, 1, 10, 1, 1);

        cmdClearHeight = new QPushButton(scrollAreaWidgetContents);
        cmdClearHeight->setObjectName(QStringLiteral("cmdClearHeight"));

        gridLayout_8->addWidget(cmdClearHeight, 1, 1, 1, 1);

        hMapRender = new GLImagePreview(scrollAreaWidgetContents);
        hMapRender->setObjectName(QStringLiteral("hMapRender"));
        hMapRender->setMinimumSize(QSize(300, 200));

        gridLayout_8->addWidget(hMapRender, 0, 0, 1, 3);

        buttonGMap = new QPushButton(scrollAreaWidgetContents);
        buttonGMap->setObjectName(QStringLiteral("buttonGMap"));

        gridLayout_8->addWidget(buttonGMap, 1, 8, 1, 1);

        buttonPMap = new QPushButton(scrollAreaWidgetContents);
        buttonPMap->setObjectName(QStringLiteral("buttonPMap"));

        gridLayout_8->addWidget(buttonPMap, 1, 5, 1, 1);

        labelHMap = new QLabel(scrollAreaWidgetContents);
        labelHMap->setObjectName(QStringLiteral("labelHMap"));

        gridLayout_8->addWidget(labelHMap, 1, 0, 1, 1);

        patternMapRender = new GLImagePreview(scrollAreaWidgetContents);
        patternMapRender->setObjectName(QStringLiteral("patternMapRender"));
        patternMapRender->setMinimumSize(QSize(300, 200));

        gridLayout_8->addWidget(patternMapRender, 0, 9, 1, 3);

        geogMapRender = new GLImagePreview(scrollAreaWidgetContents);
        geogMapRender->setObjectName(QStringLiteral("geogMapRender"));
        geogMapRender->setMinimumSize(QSize(300, 200));

        gridLayout_8->addWidget(geogMapRender, 0, 6, 1, 3);

        popMapRender = new GLImagePreview(scrollAreaWidgetContents);
        popMapRender->setObjectName(QStringLiteral("popMapRender"));
        popMapRender->setMinimumSize(QSize(300, 200));

        gridLayout_8->addWidget(popMapRender, 0, 3, 1, 3);

        buildingTypeRender = new GLImagePreview(scrollAreaWidgetContents);
        buildingTypeRender->setObjectName(QStringLiteral("buildingTypeRender"));
        buildingTypeRender->setMinimumSize(QSize(300, 200));

        gridLayout_8->addWidget(buildingTypeRender, 0, 12, 1, 3);

        buttonSMap = new QPushButton(scrollAreaWidgetContents);
        buttonSMap->setObjectName(QStringLiteral("buttonSMap"));

        gridLayout_8->addWidget(buttonSMap, 1, 11, 1, 1);

        cmdClearPop = new QPushButton(scrollAreaWidgetContents);
        cmdClearPop->setObjectName(QStringLiteral("cmdClearPop"));

        gridLayout_8->addWidget(cmdClearPop, 1, 4, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        tabParameters = new QTabWidget(centralWidget);
        tabParameters->setObjectName(QStringLiteral("tabParameters"));
        tabParameters->setGeometry(QRect(10, 10, 331, 991));
        tabStreetParams = new QWidget();
        tabStreetParams->setObjectName(QStringLiteral("tabStreetParams"));
        formLayout_3 = new QFormLayout(tabStreetParams);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        groupBox_6 = new QGroupBox(tabStreetParams);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_11 = new QGridLayout(groupBox_6);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        highwayGrowthFactor = new QDoubleSpinBox(groupBox_6);
        highwayGrowthFactor->setObjectName(QStringLiteral("highwayGrowthFactor"));
        highwayGrowthFactor->setMaximum(1);
        highwayGrowthFactor->setSingleStep(0.05);
        highwayGrowthFactor->setValue(0);

        gridLayout->addWidget(highwayGrowthFactor, 4, 1, 1, 1);

        streetGrowthFactor = new QDoubleSpinBox(groupBox_6);
        streetGrowthFactor->setObjectName(QStringLiteral("streetGrowthFactor"));
        streetGrowthFactor->setMaximum(1);
        streetGrowthFactor->setSingleStep(0.05);
        streetGrowthFactor->setValue(0);

        gridLayout->addWidget(streetGrowthFactor, 5, 1, 1, 1);

        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout->addWidget(label_25, 5, 0, 1, 1);

        sliderPopSearchRadius = new QSlider(groupBox_6);
        sliderPopSearchRadius->setObjectName(QStringLiteral("sliderPopSearchRadius"));
        sliderPopSearchRadius->setMinimum(25);
        sliderPopSearchRadius->setMaximum(1000);
        sliderPopSearchRadius->setSingleStep(25);
        sliderPopSearchRadius->setValue(200);
        sliderPopSearchRadius->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderPopSearchRadius, 3, 1, 1, 1);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 3, 2, 1, 1);

        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        sliderSearchAngleIncrease = new QSlider(groupBox_6);
        sliderSearchAngleIncrease->setObjectName(QStringLiteral("sliderSearchAngleIncrease"));
        sliderSearchAngleIncrease->setMinimum(1);
        sliderSearchAngleIncrease->setMaximum(10);
        sliderSearchAngleIncrease->setOrientation(Qt::Horizontal);
        sliderSearchAngleIncrease->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(sliderSearchAngleIncrease, 1, 1, 1, 1);

        sliderRoadSampleInterval = new QSlider(groupBox_6);
        sliderRoadSampleInterval->setObjectName(QStringLiteral("sliderRoadSampleInterval"));
        sliderRoadSampleInterval->setMinimum(1);
        sliderRoadSampleInterval->setMaximum(10);
        sliderRoadSampleInterval->setValue(2);
        sliderRoadSampleInterval->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderRoadSampleInterval, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        slideRoadSearchAngle = new QSlider(groupBox_6);
        slideRoadSearchAngle->setObjectName(QStringLiteral("slideRoadSearchAngle"));
        slideRoadSearchAngle->setMaximum(90);
        slideRoadSearchAngle->setValue(70);
        slideRoadSearchAngle->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slideRoadSearchAngle, 0, 1, 1, 1);

        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 4, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout, 0, 0, 1, 1);


        formLayout_3->setWidget(0, QFormLayout::LabelRole, groupBox_6);

        groupBox_7 = new QGroupBox(tabStreetParams);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout = new QHBoxLayout(groupBox_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        spnStreetDelay = new QSpinBox(groupBox_7);
        spnStreetDelay->setObjectName(QStringLiteral("spnStreetDelay"));
        spnStreetDelay->setValue(3);

        gridLayout_2->addWidget(spnStreetDelay, 10, 1, 1, 1);

        label_48 = new QLabel(groupBox_7);
        label_48->setObjectName(QStringLiteral("label_48"));

        gridLayout_2->addWidget(label_48, 10, 0, 1, 1);

        label_33 = new QLabel(groupBox_7);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_2->addWidget(label_33, 7, 0, 1, 1);

        spinStreetWidth = new QDoubleSpinBox(groupBox_7);
        spinStreetWidth->setObjectName(QStringLiteral("spinStreetWidth"));
        spinStreetWidth->setMinimum(1);
        spinStreetWidth->setMaximum(15);
        spinStreetWidth->setValue(5);

        gridLayout_2->addWidget(spinStreetWidth, 7, 1, 1, 1);

        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        label_34 = new QLabel(groupBox_7);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_2->addWidget(label_34, 8, 0, 1, 1);

        spinMaxBridgeLength = new QSpinBox(groupBox_7);
        spinMaxBridgeLength->setObjectName(QStringLiteral("spinMaxBridgeLength"));
        spinMaxBridgeLength->setMaximum(1000);
        spinMaxBridgeLength->setValue(200);

        gridLayout_2->addWidget(spinMaxBridgeLength, 0, 1, 1, 2);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 2, 2, 1, 1);

        spinMaxRoadAngleChange = new QSpinBox(groupBox_7);
        spinMaxRoadAngleChange->setObjectName(QStringLiteral("spinMaxRoadAngleChange"));
        spinMaxRoadAngleChange->setMaximum(360);
        spinMaxRoadAngleChange->setValue(30);

        gridLayout_2->addWidget(spinMaxRoadAngleChange, 4, 1, 1, 1);

        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        slideManhattanBlockHeight = new QSlider(groupBox_7);
        slideManhattanBlockHeight->setObjectName(QStringLiteral("slideManhattanBlockHeight"));
        slideManhattanBlockHeight->setMinimum(10);
        slideManhattanBlockHeight->setMaximum(200);
        slideManhattanBlockHeight->setValue(50);
        slideManhattanBlockHeight->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slideManhattanBlockHeight, 2, 1, 1, 1);

        spinHighwayLength = new QSpinBox(groupBox_7);
        spinHighwayLength->setObjectName(QStringLiteral("spinHighwayLength"));
        spinHighwayLength->setMinimum(5);
        spinHighwayLength->setMaximum(1000);
        spinHighwayLength->setSingleStep(5);
        spinHighwayLength->setValue(150);

        gridLayout_2->addWidget(spinHighwayLength, 6, 1, 1, 1);

        slideManhattanBlocKWidth = new QSlider(groupBox_7);
        slideManhattanBlocKWidth->setObjectName(QStringLiteral("slideManhattanBlocKWidth"));
        slideManhattanBlocKWidth->setMinimum(10);
        slideManhattanBlocKWidth->setMaximum(200);
        slideManhattanBlocKWidth->setValue(30);
        slideManhattanBlocKWidth->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slideManhattanBlocKWidth, 1, 1, 1, 1);

        spinHighwayWidth = new QDoubleSpinBox(groupBox_7);
        spinHighwayWidth->setObjectName(QStringLiteral("spinHighwayWidth"));
        spinHighwayWidth->setMinimum(1);
        spinHighwayWidth->setMaximum(20);
        spinHighwayWidth->setValue(7);

        gridLayout_2->addWidget(spinHighwayWidth, 8, 1, 1, 1);

        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 4, 0, 1, 1);

        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 6, 0, 1, 1);

        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 5, 0, 1, 1);

        spinStreetLength = new QSpinBox(groupBox_7);
        spinStreetLength->setObjectName(QStringLiteral("spinStreetLength"));
        spinStreetLength->setMinimum(5);
        spinStreetLength->setMaximum(500);
        spinStreetLength->setSingleStep(5);
        spinStreetLength->setValue(25);

        gridLayout_2->addWidget(spinStreetLength, 5, 1, 1, 1);

        spinRoadBranchProb = new QDoubleSpinBox(groupBox_7);
        spinRoadBranchProb->setObjectName(QStringLiteral("spinRoadBranchProb"));
        spinRoadBranchProb->setMaximum(1);
        spinRoadBranchProb->setSingleStep(0.05);
        spinRoadBranchProb->setValue(0.75);

        gridLayout_2->addWidget(spinRoadBranchProb, 3, 1, 1, 1);

        spnLengthVariation = new QDoubleSpinBox(groupBox_7);
        spnLengthVariation->setObjectName(QStringLiteral("spnLengthVariation"));

        gridLayout_2->addWidget(spnLengthVariation, 9, 1, 1, 1);

        label_39 = new QLabel(groupBox_7);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_2->addWidget(label_39, 9, 0, 1, 1);

        label_49 = new QLabel(groupBox_7);
        label_49->setObjectName(QStringLiteral("label_49"));

        gridLayout_2->addWidget(label_49, 11, 0, 1, 1);

        spnMainroadFollowLength = new QSpinBox(groupBox_7);
        spnMainroadFollowLength->setObjectName(QStringLiteral("spnMainroadFollowLength"));
        spnMainroadFollowLength->setValue(3);

        gridLayout_2->addWidget(spnMainroadFollowLength, 11, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        formLayout_3->setWidget(1, QFormLayout::LabelRole, groupBox_7);

        groupBox_8 = new QGroupBox(tabStreetParams);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_8);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        spinRoadExtendLength = new QSpinBox(groupBox_8);
        spinRoadExtendLength->setObjectName(QStringLiteral("spinRoadExtendLength"));
        spinRoadExtendLength->setMaximum(500);
        spinRoadExtendLength->setValue(20);

        gridLayout_3->addWidget(spinRoadExtendLength, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        spinMinRoadLength = new QSpinBox(groupBox_8);
        spinMinRoadLength->setObjectName(QStringLiteral("spinMinRoadLength"));
        spinMinRoadLength->setMaximum(200);
        spinMinRoadLength->setValue(10);
        spinMinRoadLength->setDisplayIntegerBase(10);

        gridLayout_3->addWidget(spinMinRoadLength, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 2, 0, 1, 1);

        spinRoadSnapRadius = new QSpinBox(groupBox_8);
        spinRoadSnapRadius->setObjectName(QStringLiteral("spinRoadSnapRadius"));
        spinRoadSnapRadius->setMaximum(500);
        spinRoadSnapRadius->setValue(25);

        gridLayout_3->addWidget(spinRoadSnapRadius, 2, 1, 1, 1);

        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 1);

        spinRoadPruneFactor = new QDoubleSpinBox(groupBox_8);
        spinRoadPruneFactor->setObjectName(QStringLiteral("spinRoadPruneFactor"));
        spinRoadPruneFactor->setMaximum(1);
        spinRoadPruneFactor->setSingleStep(0.01);
        spinRoadPruneFactor->setValue(0.1);

        gridLayout_3->addWidget(spinRoadPruneFactor, 3, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);


        formLayout_3->setWidget(2, QFormLayout::LabelRole, groupBox_8);

        groupBox_11 = new QGroupBox(tabStreetParams);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        formLayout_4 = new QFormLayout(groupBox_11);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_40 = new QLabel(groupBox_11);
        label_40->setObjectName(QStringLiteral("label_40"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, label_40);

        label_42 = new QLabel(groupBox_11);
        label_42->setObjectName(QStringLiteral("label_42"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_42);

        spnStartX = new QSpinBox(groupBox_11);
        spnStartX->setObjectName(QStringLiteral("spnStartX"));
        spnStartX->setMaximum(2047);
        spnStartX->setValue(900);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spnStartX);

        spnStartY = new QSpinBox(groupBox_11);
        spnStartY->setObjectName(QStringLiteral("spnStartY"));
        spnStartY->setMaximum(2047);
        spnStartY->setValue(800);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spnStartY);

        label_41 = new QLabel(groupBox_11);
        label_41->setObjectName(QStringLiteral("label_41"));

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, label_41);

        spnEndX = new QSpinBox(groupBox_11);
        spnEndX->setObjectName(QStringLiteral("spnEndX"));
        spnEndX->setMaximum(2047);
        spnEndX->setValue(800);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, spnEndX);

        spnEndY = new QSpinBox(groupBox_11);
        spnEndY->setObjectName(QStringLiteral("spnEndY"));
        spnEndY->setMaximum(2047);
        spnEndY->setValue(800);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, spnEndY);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, formLayout_2);


        formLayout_3->setWidget(3, QFormLayout::LabelRole, groupBox_11);

        groupBox_5 = new QGroupBox(tabStreetParams);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(235, 187));
        gridLayout_12 = new QGridLayout(groupBox_5);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        radUseWeightedStreet = new QRadioButton(groupBox_5);
        radUseWeightedStreet->setObjectName(QStringLiteral("radUseWeightedStreet"));
        radUseWeightedStreet->setChecked(true);

        gridLayout_12->addWidget(radUseWeightedStreet, 1, 0, 1, 1);

        radUseMajorityStreet = new QRadioButton(groupBox_5);
        radUseMajorityStreet->setObjectName(QStringLiteral("radUseMajorityStreet"));

        gridLayout_12->addWidget(radUseMajorityStreet, 0, 0, 1, 1);


        formLayout_3->setWidget(4, QFormLayout::LabelRole, groupBox_5);

        tabParameters->addTab(tabStreetParams, QString());
        tabBuildingParams = new QWidget();
        tabBuildingParams->setObjectName(QStringLiteral("tabBuildingParams"));
        groupBox_2 = new QGroupBox(tabBuildingParams);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 301, 201));
        gridLayoutWidget_4 = new QWidget(groupBox_2);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 281, 171));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_31 = new QLabel(gridLayoutWidget_4);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_5->addWidget(label_31, 2, 0, 1, 1);

        chkAllowLotMerge = new QCheckBox(gridLayoutWidget_4);
        chkAllowLotMerge->setObjectName(QStringLiteral("chkAllowLotMerge"));

        gridLayout_5->addWidget(chkAllowLotMerge, 5, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_4);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_5->addWidget(label_27, 4, 0, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_4);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_5->addWidget(label_26, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        spinLotGenerationOffset = new QDoubleSpinBox(gridLayoutWidget_4);
        spinLotGenerationOffset->setObjectName(QStringLiteral("spinLotGenerationOffset"));
        spinLotGenerationOffset->setMaximum(1);

        gridLayout_5->addWidget(spinLotGenerationOffset, 4, 1, 1, 1);

        spinMaxBuildingArea = new QSpinBox(gridLayoutWidget_4);
        spinMaxBuildingArea->setObjectName(QStringLiteral("spinMaxBuildingArea"));
        spinMaxBuildingArea->setMinimum(50);
        spinMaxBuildingArea->setMaximum(1000000);
        spinMaxBuildingArea->setValue(1000);

        gridLayout_5->addWidget(spinMaxBuildingArea, 1, 1, 1, 1);

        spinMinBuildingArea = new QSpinBox(gridLayoutWidget_4);
        spinMinBuildingArea->setObjectName(QStringLiteral("spinMinBuildingArea"));
        spinMinBuildingArea->setMinimum(10);
        spinMinBuildingArea->setMaximum(1000000);
        spinMinBuildingArea->setValue(100);

        gridLayout_5->addWidget(spinMinBuildingArea, 0, 1, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_4);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_5->addWidget(label_32, 3, 0, 1, 1);

        spinMinLotDim = new QSpinBox(gridLayoutWidget_4);
        spinMinLotDim->setObjectName(QStringLiteral("spinMinLotDim"));
        spinMinLotDim->setMaximum(200);

        gridLayout_5->addWidget(spinMinLotDim, 2, 1, 1, 1);

        spinMaxLotDim = new QSpinBox(gridLayoutWidget_4);
        spinMaxLotDim->setObjectName(QStringLiteral("spinMaxLotDim"));
        spinMaxLotDim->setMinimum(20);
        spinMaxLotDim->setMaximum(200);
        spinMaxLotDim->setValue(100);

        gridLayout_5->addWidget(spinMaxLotDim, 3, 1, 1, 1);

        groupBox_9 = new QGroupBox(tabBuildingParams);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 230, 301, 271));
        gridLayoutWidget_5 = new QWidget(groupBox_9);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 20, 281, 246));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        spnHighriseMinPopDensity = new QDoubleSpinBox(gridLayoutWidget_5);
        spnHighriseMinPopDensity->setObjectName(QStringLiteral("spnHighriseMinPopDensity"));
        spnHighriseMinPopDensity->setMaximum(1);
        spnHighriseMinPopDensity->setSingleStep(0.05);

        gridLayout_6->addWidget(spnHighriseMinPopDensity, 7, 1, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_5);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_6->addWidget(label_38, 7, 0, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_5);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_6->addWidget(label_28, 0, 1, 1, 1);

        chkAllowSkyscrapers = new QCheckBox(gridLayoutWidget_5);
        chkAllowSkyscrapers->setObjectName(QStringLiteral("chkAllowSkyscrapers"));

        gridLayout_6->addWidget(chkAllowSkyscrapers, 0, 0, 1, 1);

        spnMinSkyscraperPopDensity = new QDoubleSpinBox(gridLayoutWidget_5);
        spnMinSkyscraperPopDensity->setObjectName(QStringLiteral("spnMinSkyscraperPopDensity"));
        spnMinSkyscraperPopDensity->setMaximum(1);
        spnMinSkyscraperPopDensity->setSingleStep(0.05);

        gridLayout_6->addWidget(spnMinSkyscraperPopDensity, 2, 1, 1, 1);

        spnSkyscraperPlacementChance = new QDoubleSpinBox(gridLayoutWidget_5);
        spnSkyscraperPlacementChance->setObjectName(QStringLiteral("spnSkyscraperPlacementChance"));
        spnSkyscraperPlacementChance->setMaximum(1);
        spnSkyscraperPlacementChance->setSingleStep(0.05);
        spnSkyscraperPlacementChance->setValue(0.4);

        gridLayout_6->addWidget(spnSkyscraperPlacementChance, 1, 1, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_5);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_6->addWidget(label_29, 1, 0, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_5);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_6->addWidget(label_30, 2, 0, 1, 1);

        label_43 = new QLabel(gridLayoutWidget_5);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_6->addWidget(label_43, 4, 0, 1, 1);

        spnCommercialHeight = new QDoubleSpinBox(gridLayoutWidget_5);
        spnCommercialHeight->setObjectName(QStringLiteral("spnCommercialHeight"));
        spnCommercialHeight->setMaximum(200);
        spnCommercialHeight->setSingleStep(1);
        spnCommercialHeight->setValue(40);

        gridLayout_6->addWidget(spnCommercialHeight, 4, 1, 1, 1);

        label_44 = new QLabel(gridLayoutWidget_5);
        label_44->setObjectName(QStringLiteral("label_44"));

        gridLayout_6->addWidget(label_44, 5, 0, 1, 1);

        label_45 = new QLabel(gridLayoutWidget_5);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout_6->addWidget(label_45, 6, 0, 1, 1);

        spnHighriseHeight = new QDoubleSpinBox(gridLayoutWidget_5);
        spnHighriseHeight->setObjectName(QStringLiteral("spnHighriseHeight"));
        spnHighriseHeight->setMaximum(200);
        spnHighriseHeight->setSingleStep(1);
        spnHighriseHeight->setValue(50);

        gridLayout_6->addWidget(spnHighriseHeight, 6, 1, 1, 1);

        spnHouseHeight = new QDoubleSpinBox(gridLayoutWidget_5);
        spnHouseHeight->setObjectName(QStringLiteral("spnHouseHeight"));
        spnHouseHeight->setMaximum(200);
        spnHouseHeight->setSingleStep(1);
        spnHouseHeight->setValue(5);

        gridLayout_6->addWidget(spnHouseHeight, 5, 1, 1, 1);

        spnIndustrialHeight = new QDoubleSpinBox(gridLayoutWidget_5);
        spnIndustrialHeight->setObjectName(QStringLiteral("spnIndustrialHeight"));
        spnIndustrialHeight->setMaximum(200);
        spnIndustrialHeight->setSingleStep(1);
        spnIndustrialHeight->setValue(20);

        gridLayout_6->addWidget(spnIndustrialHeight, 8, 1, 1, 1);

        spnSkyscraperHeight = new QDoubleSpinBox(gridLayoutWidget_5);
        spnSkyscraperHeight->setObjectName(QStringLiteral("spnSkyscraperHeight"));
        spnSkyscraperHeight->setMaximum(300);
        spnSkyscraperHeight->setSingleStep(5);
        spnSkyscraperHeight->setValue(70);

        gridLayout_6->addWidget(spnSkyscraperHeight, 3, 1, 1, 1);

        label_46 = new QLabel(gridLayoutWidget_5);
        label_46->setObjectName(QStringLiteral("label_46"));

        gridLayout_6->addWidget(label_46, 8, 0, 1, 1);

        label_47 = new QLabel(gridLayoutWidget_5);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_6->addWidget(label_47, 3, 0, 1, 1);

        groupBox_10 = new QGroupBox(tabBuildingParams);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 510, 301, 161));
        gridLayoutWidget_6 = new QWidget(groupBox_10);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 281, 80));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(gridLayoutWidget_6);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_7->addWidget(label_35, 1, 3, 1, 1);

        spnBaseHeight = new QDoubleSpinBox(gridLayoutWidget_6);
        spnBaseHeight->setObjectName(QStringLiteral("spnBaseHeight"));
        spnBaseHeight->setMinimum(-1000);
        spnBaseHeight->setMaximum(1000);
        spnBaseHeight->setValue(-5);

        gridLayout_7->addWidget(spnBaseHeight, 1, 4, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_6);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_7->addWidget(label_36, 0, 4, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_6);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_7->addWidget(label_37, 2, 3, 1, 1);

        spnHeightScale = new QDoubleSpinBox(gridLayoutWidget_6);
        spnHeightScale->setObjectName(QStringLiteral("spnHeightScale"));
        spnHeightScale->setMinimum(1);
        spnHeightScale->setMaximum(1000);
        spnHeightScale->setValue(20);

        gridLayout_7->addWidget(spnHeightScale, 2, 4, 1, 1);

        tabParameters->addTab(tabBuildingParams, QString());
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1390, 700, 411, 301));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        cmdSaveOutput = new QPushButton(groupBox_3);
        cmdSaveOutput->setObjectName(QStringLiteral("cmdSaveOutput"));
        cmdSaveOutput->setGeometry(QRect(180, 230, 71, 31));
        cmdSaveOutputImage = new QPushButton(groupBox_3);
        cmdSaveOutputImage->setObjectName(QStringLiteral("cmdSaveOutputImage"));
        cmdSaveOutputImage->setGeometry(QRect(180, 190, 71, 31));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 161, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 14, 141, 180));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radShowPopulation = new QRadioButton(layoutWidget1);
        buttonGroup = new QButtonGroup(StreetGenerator);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radShowPopulation);
        radShowPopulation->setObjectName(QStringLiteral("radShowPopulation"));

        verticalLayout_2->addWidget(radShowPopulation);

        radShowGeography = new QRadioButton(layoutWidget1);
        buttonGroup->addButton(radShowGeography);
        radShowGeography->setObjectName(QStringLiteral("radShowGeography"));

        verticalLayout_2->addWidget(radShowGeography);

        radShowHeightmap = new QRadioButton(layoutWidget1);
        buttonGroup->addButton(radShowHeightmap);
        radShowHeightmap->setObjectName(QStringLiteral("radShowHeightmap"));

        verticalLayout_2->addWidget(radShowHeightmap);

        radShowPatternmap = new QRadioButton(layoutWidget1);
        buttonGroup->addButton(radShowPatternmap);
        radShowPatternmap->setObjectName(QStringLiteral("radShowPatternmap"));

        verticalLayout_2->addWidget(radShowPatternmap);

        radShowNone = new QRadioButton(layoutWidget1);
        buttonGroup->addButton(radShowNone);
        radShowNone->setObjectName(QStringLiteral("radShowNone"));

        verticalLayout_2->addWidget(radShowNone);

        chkShowVerts = new QCheckBox(layoutWidget1);
        chkShowVerts->setObjectName(QStringLiteral("chkShowVerts"));
        chkShowVerts->setChecked(true);

        verticalLayout_2->addWidget(chkShowVerts);

        chkShowRegions = new QCheckBox(layoutWidget1);
        chkShowRegions->setObjectName(QStringLiteral("chkShowRegions"));
        chkShowRegions->setEnabled(false);
        chkShowRegions->setCheckable(true);
        chkShowRegions->setChecked(false);

        verticalLayout_2->addWidget(chkShowRegions);

        chkShowLots = new QCheckBox(layoutWidget1);
        chkShowLots->setObjectName(QStringLiteral("chkShowLots"));
        chkShowLots->setEnabled(false);
        chkShowLots->setCheckable(true);
        chkShowLots->setChecked(false);

        verticalLayout_2->addWidget(chkShowLots);


        verticalLayout->addWidget(groupBox_4);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(236, 20, 171, 51));
        formLayout = new QFormLayout(layoutWidget2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        intSeedValue = new QSpinBox(layoutWidget2);
        intSeedValue->setObjectName(QStringLiteral("intSeedValue"));
        intSeedValue->setMinimum(-1000000000);
        intSeedValue->setMaximum(1000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, intSeedValue);

        chkTimeSeed = new QCheckBox(layoutWidget2);
        chkTimeSeed->setObjectName(QStringLiteral("chkTimeSeed"));

        formLayout->setWidget(1, QFormLayout::FieldRole, chkTimeSeed);

        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(260, 80, 141, 199));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        cmdReset = new QPushButton(layoutWidget3);
        cmdReset->setObjectName(QStringLiteral("cmdReset"));

        gridLayout_4->addWidget(cmdReset, 0, 0, 1, 1);

        cmdStep = new QPushButton(layoutWidget3);
        cmdStep->setObjectName(QStringLiteral("cmdStep"));

        gridLayout_4->addWidget(cmdStep, 1, 0, 1, 1);

        cmdGenerateStreets = new QPushButton(layoutWidget3);
        cmdGenerateStreets->setObjectName(QStringLiteral("cmdGenerateStreets"));

        gridLayout_4->addWidget(cmdGenerateStreets, 2, 0, 1, 1);

        cmdFilterRoads = new QPushButton(layoutWidget3);
        cmdFilterRoads->setObjectName(QStringLiteral("cmdFilterRoads"));
        cmdFilterRoads->setEnabled(false);
        cmdFilterRoads->setCheckable(false);

        gridLayout_4->addWidget(cmdFilterRoads, 3, 0, 1, 1);

        cmdGenerateRegions = new QPushButton(layoutWidget3);
        cmdGenerateRegions->setObjectName(QStringLiteral("cmdGenerateRegions"));
        cmdGenerateRegions->setEnabled(false);
        cmdGenerateRegions->setDefault(false);
        cmdGenerateRegions->setFlat(false);

        gridLayout_4->addWidget(cmdGenerateRegions, 4, 0, 1, 1);

        cmdCreateBuildingLots = new QPushButton(layoutWidget3);
        cmdCreateBuildingLots->setObjectName(QStringLiteral("cmdCreateBuildingLots"));
        cmdCreateBuildingLots->setEnabled(false);

        gridLayout_4->addWidget(cmdCreateBuildingLots, 5, 0, 1, 1);

        cmdCreateView = new QPushButton(layoutWidget3);
        cmdCreateView->setObjectName(QStringLiteral("cmdCreateView"));
        cmdCreateView->setEnabled(false);

        gridLayout_4->addWidget(cmdCreateView, 6, 0, 1, 1);

        cmdLoadImageDirectory = new QPushButton(groupBox_3);
        cmdLoadImageDirectory->setObjectName(QStringLiteral("cmdLoadImageDirectory"));
        cmdLoadImageDirectory->setGeometry(QRect(20, 230, 141, 31));
        streetRender = new QStreetRenderWidget(centralWidget);
        streetRender->setObjectName(QStringLiteral("streetRender"));
        streetRender->setGeometry(QRect(350, 20, 1451, 681));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(streetRender->sizePolicy().hasHeightForWidth());
        streetRender->setSizePolicy(sizePolicy1);
        streetRender->setFrameShape(QFrame::Box);
        streetRender->setFrameShadow(QFrame::Sunken);
        StreetGenerator->setCentralWidget(centralWidget);
        tabParameters->raise();
        groupBox_3->raise();
        streetRender->raise();
        groupBox->raise();
        statusBar = new QStatusBar(StreetGenerator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StreetGenerator->setStatusBar(statusBar);

        retranslateUi(StreetGenerator);
        QObject::connect(cmdGenerateStreets, SIGNAL(clicked()), StreetGenerator, SLOT(onClickGenerate()));
        QObject::connect(radShowPopulation, SIGNAL(toggled(bool)), StreetGenerator, SLOT(on_radPopClicked()));
        QObject::connect(radShowGeography, SIGNAL(toggled(bool)), StreetGenerator, SLOT(on_radGeogClicked()));
        QObject::connect(radShowHeightmap, SIGNAL(toggled(bool)), StreetGenerator, SLOT(on_radHeightClicked()));
        QObject::connect(cmdReset, SIGNAL(clicked()), StreetGenerator, SLOT(onClickReset()));
        QObject::connect(cmdStep, SIGNAL(clicked()), StreetGenerator, SLOT(onClickStep()));
        QObject::connect(cmdSaveOutput, SIGNAL(clicked()), StreetGenerator, SLOT(onClickSave()));
        QObject::connect(radShowNone, SIGNAL(clicked()), StreetGenerator, SLOT(on_radNoneClicked()));
        QObject::connect(radShowPatternmap, SIGNAL(clicked()), StreetGenerator, SLOT(on_radPatternClicked()));
        QObject::connect(cmdCreateBuildingLots, SIGNAL(clicked()), StreetGenerator, SLOT(onClickCreateLots()));
        QObject::connect(cmdGenerateRegions, SIGNAL(clicked()), StreetGenerator, SLOT(onClickCreateRegions()));
        QObject::connect(chkShowRegions, SIGNAL(toggled(bool)), StreetGenerator, SLOT(onClickRenderRegions(bool)));
        QObject::connect(chkShowLots, SIGNAL(toggled(bool)), StreetGenerator, SLOT(onClickRenderLots(bool)));
        QObject::connect(chkShowVerts, SIGNAL(toggled(bool)), StreetGenerator, SLOT(onClickRenderVerts(bool)));
        QObject::connect(cmdFilterRoads, SIGNAL(clicked()), StreetGenerator, SLOT(onClickFilterRoads()));
        QObject::connect(cmdCreateView, SIGNAL(clicked()), StreetGenerator, SLOT(onClickShowRendered()));
        QObject::connect(cmdLoadImageDirectory, SIGNAL(clicked()), StreetGenerator, SLOT(cmdLoadDirectory()));
        QObject::connect(cmdClearBuildingType, SIGNAL(clicked()), StreetGenerator, SLOT(clearBuildingMap()));
        QObject::connect(buttonBuildingType, SIGNAL(clicked()), StreetGenerator, SLOT(on_buttonBMap_Clicked()));
        QObject::connect(buttonSMap, SIGNAL(clicked()), StreetGenerator, SLOT(on_button_SMap_Clicked()));
        QObject::connect(cmdClearStreetMap, SIGNAL(clicked()), StreetGenerator, SLOT(clearStreetmap()));
        QObject::connect(cmdClearPop, SIGNAL(clicked()), StreetGenerator, SLOT(clearPopmap()));
        QObject::connect(cmdClearHeight, SIGNAL(clicked()), StreetGenerator, SLOT(clearHeightmap()));
        QObject::connect(cmdClearGeog, SIGNAL(clicked()), StreetGenerator, SLOT(clearGeogmap()));
        QObject::connect(buttonGMap, SIGNAL(clicked()), StreetGenerator, SLOT(on_buttonGMap_clicked()));
        QObject::connect(buttonPMap, SIGNAL(clicked()), StreetGenerator, SLOT(on_buttonPMap_clicked()));
        QObject::connect(cmdSaveOutputImage, SIGNAL(clicked()), StreetGenerator, SLOT(onClickSaveImage()));
        QObject::connect(slideManhattanBlocKWidth, SIGNAL(valueChanged(int)), label_16, SLOT(setNum(int)));
        QObject::connect(slideManhattanBlockHeight, SIGNAL(valueChanged(int)), label_15, SLOT(setNum(int)));
        QObject::connect(sliderPopSearchRadius, SIGNAL(valueChanged(int)), label_21, SLOT(setNum(int)));
        QObject::connect(slideRoadSearchAngle, SIGNAL(valueChanged(int)), label_3, SLOT(setNum(int)));
        QObject::connect(sliderSearchAngleIncrease, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));
        QObject::connect(sliderRoadSampleInterval, SIGNAL(valueChanged(int)), label_8, SLOT(setNum(int)));

        tabParameters->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StreetGenerator);
    } // setupUi

    void retranslateUi(QMainWindow *StreetGenerator)
    {
        StreetGenerator->setWindowTitle(QApplication::translate("StreetGenerator", "StreetGenerator", 0));
        actionBuilding_Generator->setText(QApplication::translate("StreetGenerator", "Building Generator", 0));
        actionTexture_Generator->setText(QApplication::translate("StreetGenerator", "Texture Generator", 0));
        groupBox->setTitle(QApplication::translate("StreetGenerator", "Inputs", 0));
        buttonBuildingType->setText(QApplication::translate("StreetGenerator", "Browse", 0));
        labelPMap->setText(QApplication::translate("StreetGenerator", "Population Density...", 0));
        buttonHMap->setText(QApplication::translate("StreetGenerator", "Browse", 0));
        labelGMap->setText(QApplication::translate("StreetGenerator", "Geography: ...", 0));
        cmdClearBuildingType->setText(QApplication::translate("StreetGenerator", "Clear", 0));
        labelSMap->setText(QApplication::translate("StreetGenerator", "Street Pattern: ...", 0));
        cmdClearGeog->setText(QApplication::translate("StreetGenerator", "Clear", 0));
        labelBMap->setText(QApplication::translate("StreetGenerator", "Building Type: ...", 0));
        cmdClearStreetMap->setText(QApplication::translate("StreetGenerator", "Clear", 0));
        cmdClearHeight->setText(QApplication::translate("StreetGenerator", "Clear", 0));
        buttonGMap->setText(QApplication::translate("StreetGenerator", "Browse", 0));
        buttonPMap->setText(QApplication::translate("StreetGenerator", "Browse", 0));
        labelHMap->setText(QApplication::translate("StreetGenerator", "Height Map: ......", 0));
        buttonSMap->setText(QApplication::translate("StreetGenerator", "Browse", 0));
        cmdClearPop->setText(QApplication::translate("StreetGenerator", "Clear", 0));
        groupBox_6->setTitle(QApplication::translate("StreetGenerator", "Search Parameters", 0));
        label_25->setText(QApplication::translate("StreetGenerator", "Street Growth Score", 0));
        label_21->setText(QApplication::translate("StreetGenerator", "200", 0));
        label_20->setText(QApplication::translate("StreetGenerator", "Pop Search Radius", 0));
        label_8->setText(QApplication::translate("StreetGenerator", "2", 0));
        label_2->setText(QApplication::translate("StreetGenerator", "Road Search Angle", 0));
        label_3->setText(QApplication::translate("StreetGenerator", "70", 0));
        label_4->setText(QApplication::translate("StreetGenerator", "Angle Search Increment", 0));
        label_5->setText(QApplication::translate("StreetGenerator", "1", 0));
        label_7->setText(QApplication::translate("StreetGenerator", "Road Sample Interval", 0));
        label_24->setText(QApplication::translate("StreetGenerator", "Highway Growth Score", 0));
        groupBox_7->setTitle(QApplication::translate("StreetGenerator", "Road Properties", 0));
        label_48->setText(QApplication::translate("StreetGenerator", "Street Delay", 0));
        label_33->setText(QApplication::translate("StreetGenerator", "Street Width", 0));
        label_9->setText(QApplication::translate("StreetGenerator", "Max Bridge Length", 0));
        label_34->setText(QApplication::translate("StreetGenerator", "Highway Width", 0));
        label_17->setText(QApplication::translate("StreetGenerator", "Road Branch Probability", 0));
        label_16->setText(QApplication::translate("StreetGenerator", "30", 0));
        label_15->setText(QApplication::translate("StreetGenerator", "50", 0));
        label_14->setText(QApplication::translate("StreetGenerator", "Manhattan Block Height", 0));
        label_13->setText(QApplication::translate("StreetGenerator", "Manhattan Block Width", 0));
        label_19->setText(QApplication::translate("StreetGenerator", "Road Max Angle Change", 0));
        label_23->setText(QApplication::translate("StreetGenerator", "Highway Length", 0));
        label_22->setText(QApplication::translate("StreetGenerator", "Street Length", 0));
        label_39->setText(QApplication::translate("StreetGenerator", "Length Variation", 0));
        label_49->setText(QApplication::translate("StreetGenerator", "Follow Peak Iterations", 0));
        groupBox_8->setTitle(QApplication::translate("StreetGenerator", "Intersection Fitting", 0));
        label_10->setText(QApplication::translate("StreetGenerator", "Road Extend Length", 0));
        label_11->setText(QApplication::translate("StreetGenerator", "Min Road Length", 0));
        label_12->setText(QApplication::translate("StreetGenerator", "Road Snap Radius", 0));
        label_18->setText(QApplication::translate("StreetGenerator", "Road Prune Factor", 0));
        groupBox_11->setTitle(QApplication::translate("StreetGenerator", "Start Parameters", 0));
        label_40->setText(QApplication::translate("StreetGenerator", "Initial Road Start:", 0));
        label_42->setText(QApplication::translate("StreetGenerator", "(X, Y):", 0));
        label_41->setText(QApplication::translate("StreetGenerator", "Initial Road End:", 0));
        groupBox_5->setTitle(QApplication::translate("StreetGenerator", "Street Pattern Evaluation", 0));
        radUseWeightedStreet->setText(QApplication::translate("StreetGenerator", "Weighted Values", 0));
        radUseMajorityStreet->setText(QApplication::translate("StreetGenerator", "Majority ", 0));
        tabParameters->setTabText(tabParameters->indexOf(tabStreetParams), QApplication::translate("StreetGenerator", "Street Generation", 0));
        groupBox_2->setTitle(QApplication::translate("StreetGenerator", "Lot Creation", 0));
        label_31->setText(QApplication::translate("StreetGenerator", "Min Lot Dimension", 0));
        chkAllowLotMerge->setText(QApplication::translate("StreetGenerator", "Allow Lot Merge", 0));
        label_27->setText(QApplication::translate("StreetGenerator", "Random Offset", 0));
        label_26->setText(QApplication::translate("StreetGenerator", "Max Building Area", 0));
        label_6->setText(QApplication::translate("StreetGenerator", "Min Building Area", 0));
        label_32->setText(QApplication::translate("StreetGenerator", "Max Lot Dimension", 0));
        groupBox_9->setTitle(QApplication::translate("StreetGenerator", "Building Creation", 0));
        label_38->setText(QApplication::translate("StreetGenerator", "Min Highrise Pop Density", 0));
        label_28->setText(QString());
        chkAllowSkyscrapers->setText(QApplication::translate("StreetGenerator", "Allow Skyscrapers", 0));
        label_29->setText(QApplication::translate("StreetGenerator", "Skyscraper Placement Chance", 0));
        label_30->setText(QApplication::translate("StreetGenerator", "Min Skyscraper Pop Density", 0));
        label_43->setText(QApplication::translate("StreetGenerator", "Commercial Height", 0));
        label_44->setText(QApplication::translate("StreetGenerator", "House Height", 0));
        label_45->setText(QApplication::translate("StreetGenerator", "Highrise Height", 0));
        label_46->setText(QApplication::translate("StreetGenerator", "Industrial Building Height", 0));
        label_47->setText(QApplication::translate("StreetGenerator", "Skyscraper Height", 0));
        groupBox_10->setTitle(QApplication::translate("StreetGenerator", "Misc.", 0));
        label_35->setText(QApplication::translate("StreetGenerator", "Base Height", 0));
        label_36->setText(QString());
        label_37->setText(QApplication::translate("StreetGenerator", "Height Scale", 0));
        tabParameters->setTabText(tabParameters->indexOf(tabBuildingParams), QApplication::translate("StreetGenerator", "Building Generation", 0));
        groupBox_3->setTitle(QApplication::translate("StreetGenerator", "Controls", 0));
        cmdSaveOutput->setText(QApplication::translate("StreetGenerator", "Save...", 0));
        cmdSaveOutputImage->setText(QApplication::translate("StreetGenerator", "Save Image", 0));
        groupBox_4->setTitle(QApplication::translate("StreetGenerator", "Render Options", 0));
        radShowPopulation->setText(QApplication::translate("StreetGenerator", "Show Population", 0));
        radShowGeography->setText(QApplication::translate("StreetGenerator", "Show Geography", 0));
        radShowHeightmap->setText(QApplication::translate("StreetGenerator", "Show Heightmap", 0));
        radShowPatternmap->setText(QApplication::translate("StreetGenerator", "Show Street Patterns", 0));
        radShowNone->setText(QApplication::translate("StreetGenerator", "Show None", 0));
        chkShowVerts->setText(QApplication::translate("StreetGenerator", "Show Vertices", 0));
        chkShowRegions->setText(QApplication::translate("StreetGenerator", "Render Building Regions", 0));
        chkShowLots->setText(QApplication::translate("StreetGenerator", "Render Building Lots", 0));
        label->setText(QApplication::translate("StreetGenerator", "Seed:", 0));
        chkTimeSeed->setText(QApplication::translate("StreetGenerator", "Use system time", 0));
        cmdReset->setText(QApplication::translate("StreetGenerator", "Initialise / Reset", 0));
        cmdStep->setText(QApplication::translate("StreetGenerator", "Step...", 0));
        cmdGenerateStreets->setText(QApplication::translate("StreetGenerator", "Generate Street Network", 0));
        cmdFilterRoads->setText(QApplication::translate("StreetGenerator", "Filter Roads", 0));
        cmdGenerateRegions->setText(QApplication::translate("StreetGenerator", "Create Regions", 0));
        cmdCreateBuildingLots->setText(QApplication::translate("StreetGenerator", "Create Building Lots", 0));
        cmdCreateView->setText(QApplication::translate("StreetGenerator", "3D View", 0));
        cmdLoadImageDirectory->setText(QApplication::translate("StreetGenerator", "Load from Directory", 0));
    } // retranslateUi

};

namespace Ui {
    class StreetGenerator: public Ui_StreetGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREETGENERATOR_H