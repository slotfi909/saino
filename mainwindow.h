#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sainoprotocol.h"
#include "settingsdialog.h"
#include <QMainWindow>
#include <QSerialPortInfo>
#include "structsaino.h"
#include "libs/qcgaugewidget/qcgaugewidget.h"
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class QIntValidator;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setting_pbn_clicked();
    void on_start_btn_clicked();
    void on_applyButton_clicked();
    void on_stop_btn_clicked();
    void on_export_pbn_clicked();
    void read_new_packet();

    void on_actionblack_triggered();

    void on_actionwhite_triggered();

    void on_actiondark_triggered();

    void on_export_pbn_2_clicked();

    void on_pushButton_clicked();

public slots:
    void apply();
    void showPortInfo(int idx);
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();
    void show_message_overflow();

private:
    QStringList _gauge_names = {"OIL PRESUURE", "OIL TEMPRATURE",
    "FUEL", "TORQUE", "MOTOR SPEED"};
    QList<uint16_t> _gauge_limits = {1000, 400, 800, 400, 1000};
    Ui::MainWindow *ui;
    Settings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;
    QSharedPointer<sainoprotocol> _saino_client;
    bool _applyClicked = false;
    bool _is_creating_random_data = false;
    QTimer* random_data_timer = nullptr;

    // these should be deleted in deconstructor
    QList<QcGaugeWidget*> circularGauges;
    QList<QcNeedleItem*> gaugeNeedles;
    QList<QcColorBand*> gaugeColorBands;
    QList<QcLabelItem*> gaugeLabels;
    QList<QcDegreesItem*> returned_degrees_item;
    QList<QcValuesItem*>  returned_values_item;

};
#endif // MAINWINDOW_H
