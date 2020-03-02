#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QList>
#include <QBluetoothDeviceInfo>
#include <QListWidgetItem>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include <QtAndroid>
#include <QTime>
#include <QDataStream>

#include <QDebug>
#include <qandroidjnienvironment.h>
#include <qandroidjniobject.h>

static const QLatin1String serviceUuid("{0000FFE0-0000-1000-8000-00805F9B34FB}");

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void send_file(QString file);
    void SendMsg(QString);
    void SendMsg(QByteArray);
    bool PermissionApply(QString);
    bool checkPermission();
    void MsgRefresh();
    void Delay_MSec(unsigned int msec);
    void checkDirFile(QDir dir,QStringList nameFilters);

private:
    Ui::MainWindow *ui;

    bool m_foundHeartRateService;
    bool over;

    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QList<QBluetoothDeviceInfo> m_devices;
    QLowEnergyController  *m_control;
    QLowEnergyService *m_service;

    QLowEnergyCharacteristic m_writeCharacteristic[5]; //写特性
    QLowEnergyService::WriteMode m_writeMode;
    QLowEnergyDescriptor m_notificationDesc;
    QLowEnergyCharacteristic m_readCharacteristic; //读特性
    int SendMaxMode; //发送模式
    int SendModeSelect;//选择发送模式
    int lena;
    QString filename;
    QString Dirname;
    QDir *folder;
    bool isconnected;

private slots:
    void addDevice(const QBluetoothDeviceInfo &device);

    void on_blue_connect_clicked(bool checked);

    void on_blue_search_clicked(bool checked);
    void scanFinished();
    void createCtl(QBluetoothDeviceInfo);

    void serviceDiscovered(const QBluetoothUuid &gatt);
    void serviceScanDone();
    void serviceStateChanged(QLowEnergyService::ServiceState s);

    void searchCharacteristic();
    void BleServiceCharacteristicChanged(const QLowEnergyCharacteristic &c,const QByteArray &value);
    void BleServiceCharacteristicRead(const QLowEnergyCharacteristic &c,
                                      const QByteArray &value);
    void BleServiceCharacteristicWrite(const QLowEnergyCharacteristic &c,
                                                   const QByteArray &value);

    void autoScroll();

    void on_blue_ss_clicked(bool checked);

    void on_blue_prev_clicked();

    void on_blue_next_clicked();

    void on_blue_file_clicked();

    void on_musiclist_itemActivated(QListWidgetItem *item);

    void on_blue_send_5_clicked();

    void on_blue_send_6_clicked();

    void on_blue_disconnect_clicked();

signals:
    void returnAddress(QBluetoothDeviceInfo);//
};

#endif // MAINWINDOW_H
