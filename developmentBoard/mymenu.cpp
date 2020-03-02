#include "mymenu.h"
#include "ui_mymenu.h"

myMenu::myMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myMenu)
{
    ui->setupUi(this);
}

myMenu::~myMenu()
{
    delete ui;
}

void myMenu::on_musicBtn_clicked()
{
    const char *str="killall -9 mplayer";
    system(str);
    myWidget = new Widget();

    connect(myWidget,&Widget::retSig,this,&myMenu::show);
    myWidget->show();
    this->hide();
}

void myMenu::on_videoBtn_clicked()
{
    const char *str="killall -9 mplayer";
    system(str);
    myVideo = new myVideoWindow();

    connect(myVideo,&myVideoWindow::retSig,this,&myMenu::show);
    myVideo->show();
    this->hide();
}
