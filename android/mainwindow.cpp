#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtAndroid;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SendModeSelect=0;   //默认发送模式
    over=false;
    lena=0;

    MsgRefresh();

    m_foundHeartRateService=false;
    isconnected=false;

    //搜索设备
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(20000);
    connect(m_deviceDiscoveryAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this,
            SLOT(addDevice(QBluetoothDeviceInfo)));//
    connect(m_deviceDiscoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));
    connect(this, SIGNAL(returnAddress(QBluetoothDeviceInfo)), this, SLOT(createCtl(QBluetoothDeviceInfo)));
    connect(ui->bluemsg,SIGNAL(cursorPositionChanged()),this,SLOT(autoScroll()));

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    ui->blue_search->setEnabled(false);
}

bool MainWindow::checkPermission()
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied)
    {
        QtAndroid::requestPermissionsSync( QStringList() << "android.permission.WRITE_EXTERNAL_STORAGE" );
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied)
        {
            return false;
        }
    }
    return true;
}

void MainWindow::MsgRefresh()
{
    if(!checkPermission())
    {
        ui->bluemsg->append("安卓写权限获取失败");
    }
    else
    {
        ui->bluemsg->append("安卓写权限获取成功");
    }

    QAndroidJniEnvironment env;
    ui->bluemsg->append(QString("SDK版本:%1").arg(QtAndroid::androidSdkVersion()));
}

void MainWindow::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send_file(QString file)
{
    SendMsg(QByteArray("file"));

    Delay_MSec(50);
    QFileInfo fileinfo(file);

    //datastream
//    char *buf;

    //#文件名字#文件大小#文件包
    QString fileRoad;
    if(file.endsWith(".mp3"))
    {
        fileRoad=QString("./music/%1").arg(file.split("/").last());
    }
    else if(file.endsWith(".flv")||file.endsWith(".mp4"))
    {
        fileRoad=QString("./video/%1").arg(file.split("/").last());
    }
    else if(file.endsWith(".tfif")||file.endsWith(".jpg")||file.endsWith(".png"))
    {
        fileRoad=QString("./image/%1").arg(file.split("/").last());
    }
    else
        fileRoad=QString("./other/%1").arg(file.split("/").last());

    QString path = "#" + fileRoad + "#" //./music/
            + QString::number(fileinfo.size())+"#f";

    int i=0;
    int current_len=0;
    int filelen=path.length();
    while(filelen)
    {
        Delay_MSec(50);
        if(filelen<=20)
        {
            SendMsg(path.mid(i,filelen));
            break;
        }
        SendMsg(path.mid(i,20));
        filelen-=20;
        i+=20;
    }
    Delay_MSec(50);

    QFile qfile(file);
//    char buff[20] = {0};
    if(!isconnected)
    {
        ui->bluemsg->append("蓝牙未连接，发送失败");
        return;
    }
    else
    {

        if(!qfile.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "提示",QString("文件%1打开失败").arg(file));
            qfile.close();
            return;
        }

        QByteArray array;
        array=qfile.readAll();

        int lenth=array.length();

        ui->progressBar->setValue(0);
        ui->progressBar->setRange(0,lenth);
        while(lenth)
        {
            Delay_MSec(50);
            if(lenth<=20)
            {
                SendMsg(array.mid(current_len));
                current_len+=lenth;
                ui->progressBar->setValue(current_len);
                break;
            }
            SendMsg(array.mid(current_len,20));
            ui->progressBar->setValue(current_len);
            current_len+=20;
            lenth-=20;
        }
    }

    ui->bluemsg->append("传输完毕,请在车载上查看");
//    delete []buf;
    qfile.close();
}

void MainWindow::addDevice(const QBluetoothDeviceInfo &info)
{
    if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
    {//判断是否是BLE设备
        QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());//按顺序显示地址和设备名称
        QList<QListWidgetItem *> items = ui->bluelist->findItems(label, Qt::MatchExactly);//检查设备是否已存在，避免重复添加
        if (items.empty())
        {//不存在则添加至设备列表
            QListWidgetItem *item = new QListWidgetItem(label);
            ui->bluelist->addItem(item);
            m_devices.append(info);
        }
    }
}

void MainWindow::on_blue_connect_clicked(bool checked)
{
    if(ui->bluelist->currentItem()->text().isEmpty()){}//确认选取有效
    else
    {
        QString bltAddress = ui->bluelist->currentItem()->text().left(17);//获取选择的地址
        for (int i = 0; i<m_devices.count(); i++)
        {
            if(m_devices.at(i).address().toString().left(17) == bltAddress)//地址对比
            {
                QBluetoothDeviceInfo choosenDevice = m_devices.at(i);
                emit returnAddress(choosenDevice);//发送设备信息
                m_deviceDiscoveryAgent->stop();//停止搜索服务
                break;
            }
        }
    }
}

void MainWindow::on_blue_search_clicked(bool checked)
{
    ui->blue_search->setEnabled(false);
    ui->bluelist->clear();
    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void MainWindow::scanFinished()
{
    ui->blue_search->setEnabled(true);
}

void MainWindow::createCtl(QBluetoothDeviceInfo info)
{
    m_control = QLowEnergyController::createCentral(info, this);
    connect(m_control, &QLowEnergyController::serviceDiscovered,
            this,&MainWindow::serviceDiscovered);

    connect(m_control, &QLowEnergyController::discoveryFinished,
            this, &MainWindow::serviceScanDone);

    connect(m_control, static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
            this, [this](QLowEnergyController::Error error) {
        Q_UNUSED(error);
        ui->bluemsg->append("Cannot connect to remote device.");
    });

    connect(m_control, &QLowEnergyController::connected, this, [this]() {
        ui->bluemsg->append("Controller connected. Search services...\n");
        m_control->discoverServices();
        isconnected=true;
    });

    connect(m_control, &QLowEnergyController::disconnected, this, [this]() {
        ui->bluemsg->append("LowEnergy controller disconnected");
    });

    //connect
    ui->bluemsg->append("start to connect\n");

    m_control->connectToDevice();
}

void MainWindow::serviceDiscovered(const QBluetoothUuid &gatt)
{
    ui->bluemsg->insertPlainText(QString("%1").arg(gatt.toString()));
    m_foundHeartRateService = true;
}

void MainWindow::serviceScanDone()
{
    //setInfo("Service scan done.");
    ui->bluemsg->append("Service scan done.");

    m_service = m_control->createServiceObject(QBluetoothUuid(serviceUuid),
                                               this);
    if(m_service)
    {
        ui->bluemsg->append("服务建立成功\n");

        m_service->discoverDetails();
    }
    else
    {
        ui->bluemsg->append("Service not found");
        return;
    }
    connect(m_service, &QLowEnergyService::stateChanged, this,
            &MainWindow::serviceStateChanged);
    connect(m_service, &QLowEnergyService::characteristicChanged, this,
            &MainWindow::BleServiceCharacteristicChanged);
    connect(m_service, &QLowEnergyService::characteristicRead, this,
            &MainWindow::BleServiceCharacteristicRead);
    connect(m_service, SIGNAL(characteristicWritten(QLowEnergyCharacteristic,QByteArray)),
            this, SLOT(BleServiceCharacteristicWrite(QLowEnergyCharacteristic,QByteArray)));

    if(m_service->state()==QLowEnergyService::DiscoveryRequired)
    {
        m_service->discoverDetails();
    }
    else
    {
        searchCharacteristic();
    }
}

void MainWindow::serviceStateChanged(QLowEnergyService::ServiceState s)
{
    if(s == QLowEnergyService::ServiceDiscovered)
    {
        ui->bluemsg->append("服务已同步\n");
        searchCharacteristic();
    }

}

void MainWindow::searchCharacteristic()
{
    if(m_service)
    {
        QList<QLowEnergyCharacteristic> list=m_service->characteristics();
        qDebug()<<"list.count()="<<list.count();
        //characteristics 获取详细特性
        SendMaxMode=list.count();  //设置模式选择上限
        for(int i=0;i<list.count();i++)
        {
            QLowEnergyCharacteristic c=list.at(i);
            /*如果QLowEnergyCharacteristic对象有效，则返回true，否则返回false*/
            if(c.isValid())
            {
                //                返回特征的属性。
                //                这些属性定义了特征的访问权限。
                if(c.properties() & QLowEnergyCharacteristic::WriteNoResponse || c.properties() & QLowEnergyCharacteristic::Write)
                    // if(c.properties() & QLowEnergyCharacteristic::Write)
                {
                    ui->bluemsg->insertPlainText("具有写权限!\n");
                    m_writeCharacteristic[i] = c;  //保存写权限特性
                    if(c.properties() & QLowEnergyCharacteristic::WriteNoResponse)
                        //                        如果使用此模式写入特性，则远程外设不应发送写入确认。
                        //                        无法确定操作的成功，并且有效负载不得超过20个字节。
                        //                        一个特性必须设置QLowEnergyCharacteristic :: WriteNoResponse属性来支持这种写模式。
                        //                         它的优点是更快的写入操作，因为它可能发生在其他设备交互之间。
                        m_writeMode = QLowEnergyService::WriteWithoutResponse;
                    else
                        m_writeMode = QLowEnergyService::WriteWithResponse;
                    //如果使用此模式写入特性，则外设应发送写入确认。
                    //如果操作成功，则通过characteristicWritten（）信号发出确认。
                    //否则，发出CharacteristicWriteError。
                    //一个特性必须设置QLowEnergyCharacteristic :: Write属性来支持这种写模式。
                }
                if(c.properties() & QLowEnergyCharacteristic::Read)
                {
                    m_readCharacteristic = c; //保存读权限特性
                }
                //描述符定义特征如何由特定客户端配置。
                m_notificationDesc = c.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
                //值为真
                if(m_notificationDesc.isValid())
                {
                    //写描述符
                    m_service->writeDescriptor(m_notificationDesc, QByteArray::fromHex("0100"));
                    //   m_service->writeDescriptor(m_notificationDesc, QByteArray::fromHex("FEE1"));
                    ui->bluemsg->insertPlainText("写描述符!\n");
                }
            }
        }
    }
}

void MainWindow::BleServiceCharacteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    ui->bluemsg->insertPlainText(QString(value));
}

void MainWindow::BleServiceCharacteristicRead(const QLowEnergyCharacteristic &c, const QByteArray &value)
{

}

void MainWindow::BleServiceCharacteristicWrite(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
//    ui->bluemsg->append(QString("指令%1发送成功").arg(QString(value)));
//    ui->bluemsg->append(QString().number(value.length()));
}

void MainWindow::SendMsg(QString text)
{
    QByteArray array=text.toLocal8Bit();
    m_service->writeCharacteristic(m_writeCharacteristic[SendModeSelect],array, m_writeMode);

}

void MainWindow::SendMsg(QByteArray buf)
{
    QByteArray array=buf;
    m_service->writeCharacteristic(m_writeCharacteristic[SendModeSelect],array, m_writeMode);
}

bool MainWindow::PermissionApply(QString str)
{
    QtAndroid::PermissionResult r = QtAndroid::checkPermission(str);

    if(r == QtAndroid::PermissionResult::Denied)
    {
        QtAndroid::requestPermissionsSync(QStringList() << str);

        r=QtAndroid::checkPermission(str);
        if(r == QtAndroid::PermissionResult::Denied)
        {
            ui->bluemsg->append("权限申请失败");
            return false;
        }
    }
    ui->bluemsg->append("权限申请成功");
    return true;
}

void MainWindow::autoScroll()
{
    ui->bluemsg->moveCursor(QTextCursor::End);
}

void MainWindow::on_blue_ss_clicked(bool checked)
{
    SendMsg(QString("ss"));
}

void MainWindow::on_blue_prev_clicked()
{
    SendMsg(QString("prev"));
}

void MainWindow::on_blue_next_clicked()
{
    SendMsg(QString("next"));
}

//每次最多写20个字节
void MainWindow::on_blue_file_clicked()
{
    Dirname="/storage/emulated/0/360/mp3/";
    QDir dir(Dirname);
    QStringList nameFilters;
    nameFilters << "*.mp3";


    checkDirFile(dir,nameFilters);
}

void MainWindow::on_musiclist_itemActivated(QListWidgetItem *item)
{
    send_file(QString("%1%2").arg(Dirname).arg(item->text()));
}

void MainWindow::on_blue_send_5_clicked()
{
    Dirname="/storage/emulated/0/360/video/";
    QDir dir(Dirname);
    QStringList nameFilters;
    nameFilters << "*.mp4" << "*.flv";

    checkDirFile(dir,nameFilters);
}

void MainWindow::checkDirFile(QDir dir, QStringList nameFilters)
{
    QStringList files = dir.entryList(nameFilters,QDir::Files | QDir::Readable,QDir::Name);
    QStringList nameonly;

    ui->bluemsg->append("正在检索目标文件夹...");
    foreach(QString list,files)
    {
        ui->bluemsg->append(QString("检索到%1!").arg(list));
        nameonly << QString(list.split("/").last());
    }


    ui->musiclist->clear();
    ui->musiclist->addItems(nameonly);
    ui->bluemsg->append("请双击目标文件");
}

void MainWindow::on_blue_send_6_clicked()
{
    Dirname="/storage/emulated/0/360/picture/";
    QDir dir(Dirname);
    QStringList nameFilters;
    nameFilters << "*.png" << "*.jpg" << "*.jfif";

    checkDirFile(dir,nameFilters);
}

void MainWindow::on_blue_disconnect_clicked()
{
    if(!isconnected) return;
    ui->blue_search->setEnabled(true);
    m_control->disconnectFromDevice();
    ui->bluemsg->append("成功解除连接");
}
