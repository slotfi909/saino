/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionabout_1;
    QAction *actionblack;
    QAction *actionwhite;
    QAction *actiondark;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *setting_pbn;
    QPushButton *start_btn;
    QPushButton *stop_btn;
    QPushButton *export_pbn;
    QPushButton *export_pbn_2;
    QGroupBox *selectBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *applyButton;
    QGroupBox *additionalOptionsGroupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *localEchoCheckBox;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_4;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *tab_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *oil_pressure_rdbtn;
    QRadioButton *oil_temprature_rdbtn;
    QRadioButton *fuel_flow_rdbtn;
    QRadioButton *fuel_rdbtn;
    QRadioButton *EGT_rdbtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *torque_rdbtn;
    QRadioButton *indicated_power_rdbtn;
    QRadioButton *frictional_power_rdbtn;
    QRadioButton *thermal_efficiency_rdbtn;
    QRadioButton *airfuel_ratio_rdbtn;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *motor_speed_rdbtn;
    QRadioButton *output_air_speed_rdbtn;
    QRadioButton *vibration_rdbtn;
    QRadioButton *body_temp_rdbtn;
    QRadioButton *air_temp_rdbtn;
    QWidget *tab_4;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuabout;
    QMenu *menutheme;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionabout_1 = new QAction(MainWindow);
        actionabout_1->setObjectName(QString::fromUtf8("actionabout_1"));
        actionblack = new QAction(MainWindow);
        actionblack->setObjectName(QString::fromUtf8("actionblack"));
        actionwhite = new QAction(MainWindow);
        actionwhite->setObjectName(QString::fromUtf8("actionwhite"));
        actiondark = new QAction(MainWindow);
        actiondark->setObjectName(QString::fromUtf8("actiondark"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 781, 561));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 271, 20));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 161, 136, 175));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        setting_pbn = new QPushButton(layoutWidget);
        setting_pbn->setObjectName(QString::fromUtf8("setting_pbn"));

        verticalLayout_2->addWidget(setting_pbn);

        start_btn = new QPushButton(layoutWidget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));

        verticalLayout_2->addWidget(start_btn);

        stop_btn = new QPushButton(layoutWidget);
        stop_btn->setObjectName(QString::fromUtf8("stop_btn"));

        verticalLayout_2->addWidget(stop_btn);

        export_pbn = new QPushButton(layoutWidget);
        export_pbn->setObjectName(QString::fromUtf8("export_pbn"));

        verticalLayout_2->addWidget(export_pbn);

        export_pbn_2 = new QPushButton(layoutWidget);
        export_pbn_2->setObjectName(QString::fromUtf8("export_pbn_2"));

        verticalLayout_2->addWidget(export_pbn_2);

        selectBox_2 = new QGroupBox(tab);
        selectBox_2->setObjectName(QString::fromUtf8("selectBox_2"));
        selectBox_2->setGeometry(QRect(222, 50, 201, 241));
        gridLayout_3 = new QGridLayout(selectBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        serialPortInfoListBox = new QComboBox(selectBox_2);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout_3->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox_2);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        gridLayout_3->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox_2);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        gridLayout_3->addWidget(manufacturerLabel, 2, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox_2);
        serialNumberLabel->setObjectName(QString::fromUtf8("serialNumberLabel"));

        gridLayout_3->addWidget(serialNumberLabel, 3, 0, 1, 1);

        locationLabel = new QLabel(selectBox_2);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout_3->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox_2);
        vidLabel->setObjectName(QString::fromUtf8("vidLabel"));

        gridLayout_3->addWidget(vidLabel, 5, 0, 1, 1);

        pidLabel = new QLabel(selectBox_2);
        pidLabel->setObjectName(QString::fromUtf8("pidLabel"));

        gridLayout_3->addWidget(pidLabel, 6, 0, 1, 1);

        layoutWidget_3 = new QWidget(tab);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(442, 388, 185, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        applyButton = new QPushButton(layoutWidget_3);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_3->addWidget(applyButton);

        additionalOptionsGroupBox = new QGroupBox(tab);
        additionalOptionsGroupBox->setObjectName(QString::fromUtf8("additionalOptionsGroupBox"));
        additionalOptionsGroupBox->setGeometry(QRect(282, 298, 350, 77));
        verticalLayout_3 = new QVBoxLayout(additionalOptionsGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        localEchoCheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchoCheckBox->setObjectName(QString::fromUtf8("localEchoCheckBox"));
        localEchoCheckBox->setChecked(true);

        verticalLayout_3->addWidget(localEchoCheckBox);

        parametersBox = new QGroupBox(tab);
        parametersBox->setObjectName(QString::fromUtf8("parametersBox"));
        parametersBox->setGeometry(QRect(430, 50, 301, 241));
        gridLayout_4 = new QGridLayout(parametersBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));

        gridLayout_4->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));

        gridLayout_4->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        gridLayout_4->addWidget(dataBitsLabel, 1, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout_4->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        gridLayout_4->addWidget(parityLabel, 2, 0, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout_4->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        gridLayout_4->addWidget(stopBitsLabel, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout_4->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        gridLayout_4->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout_4->addWidget(flowControlBox, 4, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayoutWidget_2 = new QWidget(tab_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 10, 731, 251));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 270, 731, 221));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 130, 644, 194));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oil_pressure_rdbtn = new QRadioButton(layoutWidget1);
        oil_pressure_rdbtn->setObjectName(QString::fromUtf8("oil_pressure_rdbtn"));
        oil_pressure_rdbtn->setAutoExclusive(false);

        horizontalLayout->addWidget(oil_pressure_rdbtn);

        oil_temprature_rdbtn = new QRadioButton(layoutWidget1);
        oil_temprature_rdbtn->setObjectName(QString::fromUtf8("oil_temprature_rdbtn"));
        oil_temprature_rdbtn->setAutoExclusive(false);

        horizontalLayout->addWidget(oil_temprature_rdbtn);

        fuel_flow_rdbtn = new QRadioButton(layoutWidget1);
        fuel_flow_rdbtn->setObjectName(QString::fromUtf8("fuel_flow_rdbtn"));
        fuel_flow_rdbtn->setAutoExclusive(false);

        horizontalLayout->addWidget(fuel_flow_rdbtn);

        fuel_rdbtn = new QRadioButton(layoutWidget1);
        fuel_rdbtn->setObjectName(QString::fromUtf8("fuel_rdbtn"));
        fuel_rdbtn->setAutoExclusive(false);

        horizontalLayout->addWidget(fuel_rdbtn);

        EGT_rdbtn = new QRadioButton(layoutWidget1);
        EGT_rdbtn->setObjectName(QString::fromUtf8("EGT_rdbtn"));
        EGT_rdbtn->setAutoExclusive(false);

        horizontalLayout->addWidget(EGT_rdbtn);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        torque_rdbtn = new QRadioButton(layoutWidget1);
        torque_rdbtn->setObjectName(QString::fromUtf8("torque_rdbtn"));
        torque_rdbtn->setAutoExclusive(false);

        horizontalLayout_5->addWidget(torque_rdbtn);

        indicated_power_rdbtn = new QRadioButton(layoutWidget1);
        indicated_power_rdbtn->setObjectName(QString::fromUtf8("indicated_power_rdbtn"));
        indicated_power_rdbtn->setAutoExclusive(false);

        horizontalLayout_5->addWidget(indicated_power_rdbtn);

        frictional_power_rdbtn = new QRadioButton(layoutWidget1);
        frictional_power_rdbtn->setObjectName(QString::fromUtf8("frictional_power_rdbtn"));
        frictional_power_rdbtn->setAutoExclusive(false);

        horizontalLayout_5->addWidget(frictional_power_rdbtn);

        thermal_efficiency_rdbtn = new QRadioButton(layoutWidget1);
        thermal_efficiency_rdbtn->setObjectName(QString::fromUtf8("thermal_efficiency_rdbtn"));
        thermal_efficiency_rdbtn->setAutoExclusive(false);

        horizontalLayout_5->addWidget(thermal_efficiency_rdbtn);

        airfuel_ratio_rdbtn = new QRadioButton(layoutWidget1);
        airfuel_ratio_rdbtn->setObjectName(QString::fromUtf8("airfuel_ratio_rdbtn"));
        airfuel_ratio_rdbtn->setAutoExclusive(false);

        horizontalLayout_5->addWidget(airfuel_ratio_rdbtn);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        motor_speed_rdbtn = new QRadioButton(layoutWidget1);
        motor_speed_rdbtn->setObjectName(QString::fromUtf8("motor_speed_rdbtn"));
        motor_speed_rdbtn->setAutoExclusive(false);

        horizontalLayout_6->addWidget(motor_speed_rdbtn);

        output_air_speed_rdbtn = new QRadioButton(layoutWidget1);
        output_air_speed_rdbtn->setObjectName(QString::fromUtf8("output_air_speed_rdbtn"));
        output_air_speed_rdbtn->setAutoExclusive(false);

        horizontalLayout_6->addWidget(output_air_speed_rdbtn);

        vibration_rdbtn = new QRadioButton(layoutWidget1);
        vibration_rdbtn->setObjectName(QString::fromUtf8("vibration_rdbtn"));
        vibration_rdbtn->setAutoExclusive(false);

        horizontalLayout_6->addWidget(vibration_rdbtn);

        body_temp_rdbtn = new QRadioButton(layoutWidget1);
        body_temp_rdbtn->setObjectName(QString::fromUtf8("body_temp_rdbtn"));
        body_temp_rdbtn->setAutoExclusive(false);

        horizontalLayout_6->addWidget(body_temp_rdbtn);

        air_temp_rdbtn = new QRadioButton(layoutWidget1);
        air_temp_rdbtn->setObjectName(QString::fromUtf8("air_temp_rdbtn"));
        air_temp_rdbtn->setAutoExclusive(false);

        horizontalLayout_6->addWidget(air_temp_rdbtn);


        verticalLayout->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableWidget = new QTableWidget(tab_4);
        if (tableWidget->columnCount() < 15)
            tableWidget->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 50, 691, 191));
        tableWidget_2 = new QTableWidget(tab_4);
        if (tableWidget_2->columnCount() < 13)
            tableWidget_2->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(9, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(10, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(11, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(12, __qtablewidgetitem27);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(30, 310, 691, 171));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 101, 20));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 270, 151, 20));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 260, 111, 31));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuabout = new QMenu(menubar);
        menuabout->setObjectName(QString::fromUtf8("menuabout"));
        menutheme = new QMenu(menuabout);
        menutheme->setObjectName(QString::fromUtf8("menutheme"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFont font;
        font.setFamily(QString::fromUtf8("B Masjed"));
        font.setPointSize(12);
        statusbar->setFont(font);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuabout->menuAction());
        menuabout->addSeparator();
        menuabout->addAction(menutheme->menuAction());
        menutheme->addSeparator();
        menutheme->addAction(actionblack);
        menutheme->addAction(actionwhite);
        menutheme->addAction(actiondark);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionabout_1->setText(QCoreApplication::translate("MainWindow", "about_1", nullptr));
        actionblack->setText(QCoreApplication::translate("MainWindow", "black", nullptr));
        actionwhite->setText(QCoreApplication::translate("MainWindow", "white", nullptr));
        actiondark->setText(QCoreApplication::translate("MainWindow", "dark", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "SETTING:", nullptr));
        setting_pbn->setText(QCoreApplication::translate("MainWindow", "RANDOM DATA", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stop_btn->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        export_pbn->setText(QCoreApplication::translate("MainWindow", "export sensor", nullptr));
        export_pbn_2->setText(QCoreApplication::translate("MainWindow", "export sensor error", nullptr));
        selectBox_2->setTitle(QCoreApplication::translate("MainWindow", "Select Serial Port", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        manufacturerLabel->setText(QCoreApplication::translate("MainWindow", "Manufacturer:", nullptr));
        serialNumberLabel->setText(QCoreApplication::translate("MainWindow", "Serial number:", nullptr));
        locationLabel->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        vidLabel->setText(QCoreApplication::translate("MainWindow", "Vendor ID:", nullptr));
        pidLabel->setText(QCoreApplication::translate("MainWindow", "Product ID:", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        additionalOptionsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Additional options", nullptr));
        localEchoCheckBox->setText(QCoreApplication::translate("MainWindow", "Local echo", nullptr));
        parametersBox->setTitle(QCoreApplication::translate("MainWindow", "Select Parameters", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("MainWindow", "BaudRate:", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("MainWindow", "Data bits:", nullptr));
        parityLabel->setText(QCoreApplication::translate("MainWindow", "Parity:", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("MainWindow", "Stop bits:", nullptr));
        flowControlLabel->setText(QCoreApplication::translate("MainWindow", "Flow control:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "setting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Gauge", nullptr));
        oil_pressure_rdbtn->setText(QCoreApplication::translate("MainWindow", "Oil Pressure", nullptr));
        oil_temprature_rdbtn->setText(QCoreApplication::translate("MainWindow", "Oil Temprature", nullptr));
        fuel_flow_rdbtn->setText(QCoreApplication::translate("MainWindow", "Fuel Flow", nullptr));
        fuel_rdbtn->setText(QCoreApplication::translate("MainWindow", "Fuel", nullptr));
        EGT_rdbtn->setText(QCoreApplication::translate("MainWindow", "EGT", nullptr));
        torque_rdbtn->setText(QCoreApplication::translate("MainWindow", "Torque", nullptr));
        indicated_power_rdbtn->setText(QCoreApplication::translate("MainWindow", "Indicated Power", nullptr));
        frictional_power_rdbtn->setText(QCoreApplication::translate("MainWindow", "Frictional Power", nullptr));
        thermal_efficiency_rdbtn->setText(QCoreApplication::translate("MainWindow", "Thermal efficiency", nullptr));
        airfuel_ratio_rdbtn->setText(QCoreApplication::translate("MainWindow", "Air-fuel Ratio", nullptr));
        motor_speed_rdbtn->setText(QCoreApplication::translate("MainWindow", "Motor Speed", nullptr));
        output_air_speed_rdbtn->setText(QCoreApplication::translate("MainWindow", "Output Air Speed", nullptr));
        vibration_rdbtn->setText(QCoreApplication::translate("MainWindow", "Vibration", nullptr));
        body_temp_rdbtn->setText(QCoreApplication::translate("MainWindow", "Body Temp", nullptr));
        air_temp_rdbtn->setText(QCoreApplication::translate("MainWindow", "Air Temp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "sensor error", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "OIL PRESSURE", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "OIL TEMPRATURE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "FUEL FLOW", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "FUEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "EGT", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "TORQUE", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "INDICATED POWER", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Frictional Power", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Thermal Efficiency", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Air-fuel Ratio", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "MOTOR SPEED", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "OUTPUT AIR SPEED", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "VIBRATION", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "BODY TEMP", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "FUEL FLOW", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "FUEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "EGT", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "TORQUE", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "INDECATED POWER", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Frictional Power", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Thermal Efficiency", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Air-fuel Ratio", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_2->horizontalHeaderItem(9);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "MOTOR SPEED", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_2->horizontalHeaderItem(10);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "OUTPUT AIR SPEED", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_2->horizontalHeaderItem(11);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "VIBRATION", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_2->horizontalHeaderItem(12);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "AIR TEMP", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "sensor data:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "sensor error data:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "clear tables", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Table", nullptr));
        menuabout->setTitle(QCoreApplication::translate("MainWindow", "menu", nullptr));
        menutheme->setTitle(QCoreApplication::translate("MainWindow", "theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
