#include "mainwindow.h"
#include "qlineedit.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIntValidator>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_intValidator(new QIntValidator(0, 4000000, this))
{
    ui->setupUi(this);
    this->_saino_client.reset(new sainoprotocol());

    ui->baudRateBox->setInsertPolicy(QComboBox::NoInsert);

    QObject::connect(ui->applyButton, &QPushButton::clicked,
            this, &MainWindow::apply);
    connect(ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::showPortInfo);
    connect(ui->baudRateBox,  QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::checkCustomBaudRatePolicy);
    connect(ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::checkCustomDevicePathPolicy);
    connect(this->_saino_client.get(), &sainoprotocol::new_packet_arrived, this, &MainWindow::read_new_packet);
    connect(this->_saino_client.get(), &sainoprotocol::message_overflow, this, &MainWindow::show_message_overflow);
    fillPortsParameters();
    fillPortsInfo();
    updateSettings();

    // setting up the gauges
    for(int i = 0; i < this->_gauge_names.length(); i++){
        this->circularGauges.append(new QcGaugeWidget);
        this->gaugeColorBands.append(circularGauges[i]->addColorBand(50));
        this->gaugeLabels.append(circularGauges[i]->addLabel(40));
        this->gaugeNeedles.append(circularGauges[i]->addNeedle(60));
        this->returned_degrees_item.append(circularGauges[i]->addDegrees(65));
        this->returned_values_item.append(circularGauges[i]->addValues(80));

        circularGauges[i]->addArc(55);
        returned_degrees_item[i]->setValueRange(0,_gauge_limits.at(i));
        returned_degrees_item[i]->setStep(_gauge_limits.at(i) / 10);
        gaugeColorBands[i]->setValueRange(0,100);
        returned_values_item[i]->setValueRange(0,_gauge_limits.at(i));
        returned_values_item[i]->setStep(_gauge_limits.at(i) / 10);
        circularGauges[i]->addLabel(70)->setText(this->_gauge_names.at(i));
        this->gaugeLabels[i]->setText("0");
        this->gaugeNeedles[i]->setLabel(this->gaugeLabels[i]);
        this->gaugeNeedles[i]->setColor(Qt::blue);
        this->gaugeNeedles[i]->setValueRange(0,_gauge_limits.at(i));
        circularGauges[i]->addBackground(7);
    }
    // upper layout
        for(int i = 0; i < 3; i++)
            this->ui->horizontalLayout_2->addWidget(circularGauges[i]);
    // lower layout
        for(int i = 3; i < 5; i++)
            this->ui->horizontalLayout_4->addWidget(circularGauges[i]);

    // set white theme as default
        this->on_actionwhite_triggered();
    ui->retranslateUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setting_pbn_clicked()
{
    if(this->_is_creating_random_data == false){
        this->random_data_timer = new QTimer(this);
        connect(this->random_data_timer, &QTimer::timeout, this->_saino_client.get(), &sainoprotocol::fillWithRandomData);
        this->random_data_timer->start(500);
        this->ui->statusbar->showMessage("started generating random data successfully", 3000);
        this->_is_creating_random_data = true;
    }
    else{
        this->random_data_timer->stop();
        this->ui->statusbar->showMessage("stopped generating random data successfully", 3000);
        this->_is_creating_random_data = false;
    }
}


void MainWindow::on_start_btn_clicked()
{
    if(this->_applyClicked == false){
        this->ui->statusbar->showMessage("please set the port details using apply button first", 3000);
        return;
    }
    bool opening_result = this->_saino_client->openSerialPort();
    if(opening_result)
        this->ui->statusbar->showMessage("connected successfully", 3000);
    else
        this->ui->statusbar->showMessage(QString("could not connect, error: ").append(this->_saino_client->getSerialPortLastError()), 3000);
}

void MainWindow::apply()
{
    updateSettings();
}

void MainWindow::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    const QString blankString = tr(::blankString);

    const QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();
    ui->descriptionLabel->setText(tr("Description: %1").arg(list.value(1, blankString)));
    ui->manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.value(2, blankString)));
    ui->serialNumberLabel->setText(tr("Serial number: %1").arg(list.value(3, blankString)));
    ui->locationLabel->setText(tr("Location: %1").arg(list.value(4, blankString)));
    ui->vidLabel->setText(tr("Vendor Identifier: %1").arg(list.value(5, blankString)));
    ui->pidLabel->setText(tr("Product Identifier: %1").arg(list.value(6, blankString)));
}

void MainWindow::checkCustomBaudRatePolicy(int idx)
{
    const bool isCustomBaudRate = !ui->baudRateBox->itemData(idx).isValid();
    ui->baudRateBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        ui->baudRateBox->clearEditText();
        QLineEdit *edit = ui->baudRateBox->lineEdit();
        edit->setValidator(m_intValidator);
    }
}


void MainWindow::checkCustomDevicePathPolicy(int idx)
{
    const bool isCustomPath = !ui->serialPortInfoListBox->itemData(idx).isValid();
    ui->serialPortInfoListBox->setEditable(isCustomPath);
    if (isCustomPath)
        ui->serialPortInfoListBox->clearEditText();
}


void MainWindow::fillPortsParameters()
{
    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(tr("Custom"));

    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}

void MainWindow::fillPortsInfo()
{
    ui->serialPortInfoListBox->clear();
    const QString blankString = tr(::blankString);
    const auto infos = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        const QString description = info.description();
        const QString manufacturer = info.manufacturer();
        const QString serialNumber = info.serialNumber();
        const auto vendorId = info.vendorIdentifier();
        const auto productId = info.productIdentifier();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (vendorId ? QString::number(vendorId, 16) : blankString)
             << (productId ? QString::number(productId, 16) : blankString);

        ui->serialPortInfoListBox->addItem(list.constFirst(), list);
    }

    ui->serialPortInfoListBox->addItem(tr("Custom"));
}

void MainWindow::updateSettings()
{
    m_currentSettings.name = ui->serialPortInfoListBox->currentText();

    if (ui->baudRateBox->currentIndex() == 4) {
        m_currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
    } else {
        const auto baudRateData = ui->baudRateBox->currentData();
        m_currentSettings.baudRate = baudRateData.value<QSerialPort::BaudRate>();
    }
    m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);

    const auto dataBitsData = ui->dataBitsBox->currentData();
    m_currentSettings.dataBits = dataBitsData.value<QSerialPort::DataBits>();
    m_currentSettings.stringDataBits = ui->dataBitsBox->currentText();

    const auto parityData = ui->parityBox->currentData();
    m_currentSettings.parity = parityData.value<QSerialPort::Parity>();
    m_currentSettings.stringParity = ui->parityBox->currentText();

    const auto stopBitsData = ui->stopBitsBox->currentData();
    m_currentSettings.stopBits = stopBitsData.value<QSerialPort::StopBits>();
    m_currentSettings.stringStopBits = ui->stopBitsBox->currentText();

    const auto flowControlData = ui->flowControlBox->currentData();
    m_currentSettings.flowControl = flowControlData.value<QSerialPort::FlowControl>();
    m_currentSettings.stringFlowControl = ui->flowControlBox->currentText();

    m_currentSettings.localEchoEnabled = ui->localEchoCheckBox->isChecked();
    this->ui->statusbar->showMessage("setting updated successfully", 3000);
}

void MainWindow::show_message_overflow()
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setModal(true);
    msgBox->setText("message counter has overflowed");
    msgBox->setInformativeText("Do you want to reset message counter?");
    msgBox->setStandardButtons(QMessageBox::Apply | QMessageBox::Cancel);
    msgBox->setDefaultButton(QMessageBox::Apply);
    int ret = msgBox->exec();
    switch (ret) {
    case QMessageBox::Apply:
        this->_saino_client->reset_num_recieved_packets();
        break;
    default:
        break;
    }
}

void MainWindow::on_applyButton_clicked()
{
    this->_applyClicked = true;
    this->apply();
    this->_saino_client->setSrialPortSettings(this->m_currentSettings);
    this->ui->statusbar->showMessage("COM setting updated successfully", 3000);
}


void MainWindow::on_stop_btn_clicked()
{
    bool closing_result = this->_saino_client->closeSerialPort();
    if(closing_result)
        this->ui->statusbar->showMessage("closed successfully");
    else
        this->ui->statusbar->showMessage(QString("could not close, error: ").append(this->_saino_client->getSerialPortLastError()), 3000);

}


void MainWindow::on_export_pbn_clicked()
{
    // this->ui->statusbar->showMessage("to be implemented..", 3000);
    // QString current_dateTime = QDateTime::currentDateTime().toString();
    // Get the model from the QTableWidget
    QAbstractItemModel *model = ui->tableWidget->model();
    // Create file dialog to choose save location
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export to Excel"), "",
                                                    tr("Excel files (*.csv)"));
    if (!fileName.isEmpty()){
        // Create CSV file
        QFile csvFile(fileName);
        if (!csvFile.open(QIODevice::WriteOnly))
        {
            qDebug() << "Could not open file for writing";
            return;
        }
        QTextStream out(&csvFile);
        // Write header row
        QStringList headers;
        QHash<int, QByteArray> roleNames = model->roleNames();
        for (const auto& pair : roleNames) {
            // headers.append(QString::fromStdString(pair.toStdString()));
        }

        foreach (const QString &header, headers)
        {
            out << header << ",";
        }
        out << "\n";
        // Write data rows
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();
        for (int row = 0; row < rowCount; ++row)
        {
            for (int col = 0; col < columnCount; ++col)
            {
                QVariant value = model->data(model->index(row, col));
                if (!value.isNull())
                {
                    out << value.toString() << ",";
                }
                else
                {
                    out << ",";
                }
            }
            out << "\n";
        }
        csvFile.close();
        qDebug() << "Export successful!";
    }

}

void MainWindow::read_new_packet()
{
    // update gauges
    // might hit assertion
    if(this->_saino_client->getUnitTrueValue(1).metaType().id() == QMetaType::UInt)
        this->gaugeNeedles[0]->setCurrentValue(this->_saino_client->getUnitTrueValue(1).toUInt());
    else
        this->gaugeNeedles[0]->setCurrentValue(this->_saino_client->getUnitTrueValue(1).toFloat());

    if(this->_saino_client->getUnitTrueValue(2).metaType().id() == QMetaType::UInt)
        this->gaugeNeedles[1]->setCurrentValue(this->_saino_client->getUnitTrueValue(2).toUInt());
    else
        this->gaugeNeedles[1]->setCurrentValue(this->_saino_client->getUnitTrueValue(2).toFloat());

    if(this->_saino_client->getUnitTrueValue(4).metaType().id() == QMetaType::UInt)
        this->gaugeNeedles[2]->setCurrentValue(this->_saino_client->getUnitTrueValue(4).toUInt());
    else
        this->gaugeNeedles[2]->setCurrentValue(this->_saino_client->getUnitTrueValue(4).toFloat());

    if(this->_saino_client->getUnitTrueValue(5).metaType().id() == QMetaType::UInt)
        this->gaugeNeedles[3]->setCurrentValue(this->_saino_client->getUnitTrueValue(5).toUInt());
    else
        this->gaugeNeedles[3]->setCurrentValue(this->_saino_client->getUnitTrueValue(5).toFloat());

    if(this->_saino_client->getUnitTrueValue(2).metaType().id() == QMetaType::UInt)
        this->gaugeNeedles[4]->setCurrentValue(this->_saino_client->getUnitTrueValue(0x0b).toUInt());
    else
        this->gaugeNeedles[4]->setCurrentValue(this->_saino_client->getUnitTrueValue(0x0b).toFloat());

    // update tables
        // first table
        int column_counter = 0;
        int row_counts = this->ui->tableWidget->rowCount();
        this->ui->tableWidget->insertRow(row_counts);

        uint8_t msg_counter = this->_saino_client->getMsg_counter();
        this->ui->tableWidget->setItem(row_counts,column_counter++,new QTableWidgetItem(QString::number(msg_counter)));

        // result might be float!
        QVariant oil_pressure = this->_saino_client->getUnitTrueValue(1);
        QVariant oil_temprature = this->_saino_client->getUnitTrueValue(2);
        QVariant fuel_flow = this->_saino_client->getUnitTrueValue(3);
        QVariant fuel = this->_saino_client->getUnitTrueValue(4);
        QVariant egt = this->_saino_client->getUnitTrueValue(5);
        QVariant torque = this->_saino_client->getUnitTrueValue(6);
        QVariant indicated_power = this->_saino_client->getUnitTrueValue(7);
        QVariant frictional_power = this->_saino_client->getUnitTrueValue(8);
        QVariant thermal_efficiency = this->_saino_client->getUnitTrueValue(9);
        QVariant air_fuel_ratio = this->_saino_client->getUnitTrueValue(0x0a);
        QVariant motor_speed = this->_saino_client->getUnitTrueValue(0x0b);
        QVariant output_air_speed = this->_saino_client->getUnitTrueValue(0x0c);
        QVariant vibration = this->_saino_client->getUnitTrueValue(0x0d);
        QVariant body_temp = this->_saino_client->getUnitTrueValue(0x0e);
        QVariant air_temp = this->_saino_client->getUnitTrueValue(0x0f);

        if(oil_pressure.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_pressure.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_pressure.toFloat())));

        if(oil_temprature.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_temprature.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_temprature.toFloat())));

        if(fuel_flow.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel_flow.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel_flow.toFloat())));

        if(fuel.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel.toFloat())));

        if(egt.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(egt.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(egt.toFloat())));

        if(torque.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(torque.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(torque.toFloat())));

        if(indicated_power.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(indicated_power.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(indicated_power.toFloat())));

        if(frictional_power.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(frictional_power.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(frictional_power.toFloat())));

        if(thermal_efficiency.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(thermal_efficiency.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(thermal_efficiency.toFloat())));

        if(air_fuel_ratio.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_fuel_ratio.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_fuel_ratio.toFloat())));

        if(motor_speed.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(motor_speed.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(motor_speed.toFloat())));

        if(output_air_speed.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(output_air_speed.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(output_air_speed.toFloat())));

        if(vibration.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(vibration.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(vibration.toFloat())));

        if(body_temp.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(body_temp.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(body_temp.toFloat())));

        if(air_temp.metaType().id() == QMetaType::UInt)
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_temp.toUInt())));
        else
            this->ui->tableWidget->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_temp.toFloat())));

        // second table
        column_counter = 0;
        row_counts = this->ui->tableWidget_2->rowCount();
        this->ui->tableWidget_2->insertRow(row_counts);

        msg_counter = this->_saino_client->getMsg_counter();
        this->ui->tableWidget_2->setItem(row_counts,column_counter++,new QTableWidgetItem(QString::number(msg_counter)));

        QVariant oil_pressure_err = this->_saino_client->getUnitTrueValue(0x11);
        QVariant oil_temprature_err = this->_saino_client->getUnitTrueValue(0x12);
        QVariant fuel_flow_err = this->_saino_client->getUnitTrueValue(0x13);
        QVariant fuel_err = this->_saino_client->getUnitTrueValue(0x14);
        QVariant egt_err = this->_saino_client->getUnitTrueValue(0x15);
        QVariant torque_err = this->_saino_client->getUnitTrueValue(0x16);
        QVariant indicated_power_err = this->_saino_client->getUnitTrueValue(0x17);
        QVariant frictional_power_err = this->_saino_client->getUnitTrueValue(0x18);
        QVariant thermal_efficiency_err = this->_saino_client->getUnitTrueValue(0x19);
        QVariant air_fuel_ratio_err = this->_saino_client->getUnitTrueValue(0x1a);
        QVariant motor_speed_err = this->_saino_client->getUnitTrueValue(0x1b);
        QVariant output_air_speed_err = this->_saino_client->getUnitTrueValue(0x1c);
        QVariant vibration_err = this->_saino_client->getUnitTrueValue(0x1d);
        // these two return warning
        QVariant body_temp_err = this->_saino_client->getUnitTrueValue(0x1e);
        QVariant air_temp_err = this->_saino_client->getUnitTrueValue(0x1f);

        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_pressure_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(oil_temprature_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel_flow_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(fuel_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(egt_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(torque_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(indicated_power_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(frictional_power_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(thermal_efficiency_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_fuel_ratio_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(motor_speed_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(output_air_speed_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(vibration_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(body_temp_err.toUInt())));
        this->ui->tableWidget_2->setItem(row_counts, column_counter++, new QTableWidgetItem(QString::number(air_temp_err.toUInt())));

    // update sensor errors
        this->ui->oil_pressure_rdbtn->setChecked(oil_pressure_err.toUInt());
        this->ui->oil_temprature_rdbtn->setChecked(oil_temprature_err.toUInt());
        this->ui->fuel_flow_rdbtn->setChecked(fuel_flow_err.toUInt());
        this->ui->fuel_rdbtn->setChecked(fuel_err.toUInt());
        this->ui->EGT_rdbtn->setChecked(egt_err.toUInt());
        this->ui->torque_rdbtn->setChecked(torque_err.toUInt());
        this->ui->indicated_power_rdbtn->setChecked(indicated_power_err.toUInt());
        this->ui->frictional_power_rdbtn->setChecked(frictional_power_err.toUInt());
        this->ui->thermal_efficiency_rdbtn->setChecked(thermal_efficiency_err.toUInt());
        this->ui->airfuel_ratio_rdbtn->setChecked(air_fuel_ratio_err.toUInt());
        this->ui->motor_speed_rdbtn->setChecked(motor_speed_err.toUInt());
        this->ui->output_air_speed_rdbtn->setChecked(output_air_speed_err.toUInt());
        this->ui->vibration_rdbtn->setChecked(vibration_err.toUInt());
        this->ui->body_temp_rdbtn->setChecked(body_temp_err.toUInt());
        this->ui->air_temp_rdbtn->setChecked(air_temp_err.toUInt());
}


void MainWindow::on_actionblack_triggered()
{
    QFile  styleFile(":/resource/dark/darkstyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString  style(styleFile.readAll());
    this->setStyleSheet(style);
}


void MainWindow::on_actionwhite_triggered()
{
    QFile  styleFile(":/resource/light/lightstyle.qss");
    styleFile.open(QFile::ReadOnly);
    QString  style(styleFile.readAll());
    this->setStyleSheet(style);
}


void MainWindow::on_actiondark_triggered()
{
    QFile  styleFile(":/resource/dark2/dark2style.qss");
    styleFile.open(QFile::ReadOnly);
    QString  style(styleFile.readAll());
    this->setStyleSheet(style);
}


void MainWindow::on_export_pbn_2_clicked()
{
    QString current_dateTime = QDateTime::currentDateTime().toString();
    // Get the model from the QTableWidget
    QAbstractItemModel *model = ui->tableWidget_2->model();
    // Create file dialog to choose save location
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Export to Excel"), "",
                                                    tr("Excel files (*.csv)"));
    if (!fileName.isEmpty()){
        // Create CSV file
        QFile csvFile(fileName);
        if (!csvFile.open(QIODevice::WriteOnly))
        {
            qDebug() << "Could not open file for writing";
            return;
        }
        QTextStream out(&csvFile);
        // Write header row
        QStringList headers;
        QHash<int, QByteArray> roleNames = model->roleNames();
        for (const auto& pair : roleNames) {
            // headers.append(QString::fromStdString(pair.toStdString()));
        }

        foreach (const QString &header, headers)
        {
            out << header << ",";
        }
        out << "\n";
        // Write data rows
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();
        for (int row = 0; row < rowCount; ++row)
        {
            for (int col = 0; col < columnCount; ++col)
            {
                QVariant value = model->data(model->index(row, col));
                if (!value.isNull())
                {
                    out << value.toString() << ",";
                }
                else
                {
                    out << ",";
                }
            }
            out << "\n";
        }
        csvFile.close();
        qDebug() << "Export successful!";
    }

}


void MainWindow::on_pushButton_clicked()
{
    this->ui->tableWidget->clearContents();
    this->ui->tableWidget->setRowCount(0);
    this->ui->tableWidget_2->clearContents();
    this->ui->tableWidget_2->setRowCount(0);
}

