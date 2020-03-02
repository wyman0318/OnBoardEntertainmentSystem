#include "widget.h"
#include "ui_widget.h"
#include "tty.h"
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->cutMusic->setCheckable(true);
    press = false;
    is_show=false;
    is_finish=true;

    pid=0;

    ui->lineEdit->setReadOnly(true);

    DirFlush();

    ui->listWidget->hide();
    ui->listWidget->setCurrentRow(0);


    fd2 = tty_starts();
    ttylink = new mytty(fd2);
    ttylink->start();
    myprocess = new QProcess(this);
    connect(myprocess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished()));
    connect(ttylink,SIGNAL(blue_msg(int)),this,SLOT(blue_action(int)));

    music_name=QString("%1%2").arg("./music/").arg(ui->listWidget->currentItem()->text());
    listm << "-af" << "volume=-10" <<music_name;
    ui->lineEdit->setText(QString(ui->listWidget->currentItem()->text()).remove(".mp3"));

    ui->vol_ctl->setRange(-20,0);
    ui->vol_ctl->setValue(-10);

    ui->musicImage->setPixmap(QPixmap("./image/default.jfif").scaled(ui->musicImage->size()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::DirFlush()
{

    QDir dir("./music");
    QStringList nameFilters;
    nameFilters << "*.mp3";
    files = dir.entryList(nameFilters,QDir::Files|QDir::Readable,QDir::Name);
    foreach(QString str,files)
    {
        if(!ui->listWidget->findItems(str,Qt::MatchFixedString).isEmpty())
            continue;
        ui->listWidget->addItem(str);
    }
}


void Widget::on_go_Btn_clicked()
{
    if(pid==0)
    {
        myprocess->close();
        myprocess->start("mplayer",listm);
        ui->lineEdit->setText(QString(listm[2]).remove(".mp3").split("/").last());
        ui->go_Btn->setText("暂停");
        press=true;

        //设置海报图
        QString str(QString("./image/%2.jfif").arg(ui->lineEdit->text()));
        QFile exFile(str);
        if(exFile.exists())
        {
            ui->musicImage->setPixmap(QPixmap(str).scaled(ui->musicImage->size()));
        }
        else{
            ui->musicImage->setPixmap(QPixmap("./image/default.jfif").scaled(ui->musicImage->size()));
        }

        myprocess->waitForStarted();
        is_finish=true;//防冲突
    }
    else if(!press&&pid!=0)
    {

        const char *c = QString("kill -18 %1").arg(QString::number(pid)).toStdString().c_str();
        system(c);

        ui->go_Btn->setText("暂停");
        press =true;
    }
    else if(press&&pid!=0)
    {
        const char *h = QString("kill -19 %1").arg(QString::number(pid)).toStdString().c_str();
        system(h);
        ui->go_Btn->setText("开始");
        press = false;
    }

    pid = myprocess->pid();
}

//前一首,通过直接改变QListWidget的条目并直接调用它的槽函数
void Widget::on_prev_clicked()
{
    if(ui->listWidget->currentRow()==0)
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    else
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-1);

    on_listWidget_itemClicked(ui->listWidget->currentItem());
}

//后一首
void Widget::on_next_clicked()
{
    ui->listWidget->setCurrentRow((ui->listWidget->currentRow()+1)%ui->listWidget->count());
    on_listWidget_itemClicked(ui->listWidget->currentItem());
}

void Widget::on_cutMusic_clicked()
{
    if(!is_show)
    {
        ui->listWidget->show();
        ui->cutMusic->setText("隐藏列表");
        is_show=true;
    }
    else
    {
        ui->listWidget->hide();
        ui->cutMusic->setText("打开列表选择歌曲");
        is_show=false;
    }
}

//歌结束时的槽函数
void Widget::finished()
{
    if(is_finish)//因为切换歌曲也需要关闭mplayer，所以需要区分接受的时机
    {
        on_next_clicked();
    }
}

//接受到蓝牙的指令并做出相应操作
void Widget::blue_action(int sig)
{
    switch(sig)
    {
    case 3:on_next_clicked();break;
    case 4:on_prev_clicked();break;
    case 5:on_go_Btn_clicked();break;
    case 6:DirFlush();break;
    }
}

//调节音量，只能在程序开始前调节
void Widget::on_vol_ctl_valueChanged(int value)
{
    listm[1]=QString("volume=%1").arg(QString().number(value));
}

void Widget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    music_name=QString("%1%2").arg("./music/").arg(item->text());
    listm[2] = music_name;
    curr=ui->listWidget->currentRow();
    press=false;
    pid=0;
    is_finish=false;//防止与finish槽函数冲突
    this->on_go_Btn_clicked();
}

void Widget::on_returnBtn_clicked()
{
    is_finish=false;
    myprocess->terminate();
    ttylink->terminate();
    emit retSig();
    this->close();
}
