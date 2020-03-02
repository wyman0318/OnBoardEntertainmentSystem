#include "myvideowindow.h"
#include "ui_myvideowindow.h"
#include "tty.h"

myVideoWindow::myVideoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myVideoWindow)
{
    ui->setupUi(this);

    this->move(0,401);

    press = false;
    is_finish=true;
    pid=0;

    list = new listSection();
    list->show();

    DirFlush();
    list->showList();


    //串口蓝牙配置
    fd2 = tty_starts();
    ttylink = new mytty(fd2);
    ttylink->start();
    //外部进程配置
    myprocess = new QProcess(this);
    //配置进程参数列表
    list->initCurrentRow(0);
    music_name="./video/"+list->getItemCurrentString();
    listm << "-af" << "volume=-10" << "-zoom" << "-x" << "800" << "-y" << "400" <<music_name;
    //槽函数配置
    connect(myprocess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished()));
    connect(ttylink,SIGNAL(blue_msg(int)),this,SLOT(blue_action(int)));
    connect(list,&listSection::volChange,this,&myVideoWindow::volChangeSlot);
    connect(list,&listSection::rowChange,this,&myVideoWindow::listChangeSlot);
}

myVideoWindow::~myVideoWindow()
{
    delete ui;
}

void myVideoWindow::DirFlush()
{
    QDir dir("./video");
    QStringList nameFilters;
    nameFilters << "*.mp4" << "*.wav" << "*.flv";
    files = dir.entryList(nameFilters,QDir::Files|QDir::Readable,QDir::Name);
    foreach(QString str,files)
    {
        if(list->checkExist(str)) continue;
        list->addListItem(str);
    }
}

void myVideoWindow::cutMovie()
{
    music_name=QString("%1%2").arg("./video/").arg(list->getItemCurrentString());
    listm[listm.length()-1] = music_name;
    press=false;
    pid=0;
    is_finish=false;//防止与finish槽函数冲突
    on_ssBtn_clicked();
}

void myVideoWindow::on_prevBtn_clicked()
{
    list->moveListIndex(0);
    cutMovie();
}

void myVideoWindow::on_ssBtn_clicked()
{
    if(pid==0)
    {
        myprocess->close();
        myprocess->start("mplayer",listm);
        list->hide();
        press=true;
        myprocess->waitForStarted();
        is_finish=true;//防冲突
    }
    else if(!press&&pid!=0)
    {

        const char *c = QString("kill -18 %1").arg(QString::number(pid)).toStdString().c_str();
        system(c);

        press =true;
    }
    else if(press&&pid!=0)
    {
        const char *h = QString("kill -19 %1").arg(QString::number(pid)).toStdString().c_str();
        system(h);

        press = false;
    }

    pid = myprocess->pid();
}

void myVideoWindow::on_killBtn_clicked()
{
    is_finish=false;
    myprocess->terminate();
    myprocess->waitForFinished(2000);
    pid=0;
    list->show();
}

void myVideoWindow::on_nextBtn_clicked()
{
    list->moveListIndex(0);
    cutMovie();
}

void myVideoWindow::on_retBtn_clicked()
{
    is_finish=false;
    myprocess->terminate();
    ttylink->terminate();
    emit retSig();
    this->close();
}

void myVideoWindow::finished()
{
    if(is_finish)//因为切换歌曲也需要关闭mplayer，所以需要区分接受的时机
    {
        on_nextBtn_clicked();
    }
}

void myVideoWindow::blue_action(int sig)
{
    switch(sig)
    {
    case 3:on_nextBtn_clicked();break;
    case 4:on_prevBtn_clicked();break;
    case 5:on_ssBtn_clicked();break;
    case 6:DirFlush();break;
    }
}

void myVideoWindow::volChangeSlot(int value)
{
    listm[1]=QString("volume=%1").arg(QString().number(value));
}

void myVideoWindow::listChangeSlot(QString string)
{
    music_name=QString("%1%2").arg("./video/").arg(string);
    listm[listm.length()-1] = music_name;
}
