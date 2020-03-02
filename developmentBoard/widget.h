#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QStringList>
#include <QListWidgetItem>
#include <QListWidget>
//#include "audio.h"
#include <Q_PID>
#include <QDebug>
#include <unistd.h>
#include "mytty.h"
#include "vol.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void DirFlush();

private slots:
    void on_go_Btn_clicked();

//    void on_qiangzhi_clicked();

    void on_prev_clicked();

    void on_next_clicked();

    void on_cutMusic_clicked();
    void finished();
    void blue_action(int);
//    void show_buf(QString);

    void on_vol_ctl_valueChanged(int value);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_returnBtn_clicked();

private:
    Ui::Widget *ui;

    bool press;
    bool is_show;
    bool is_finish;
    QString music_name;
    //audio *myaudio;
    QProcess *myprocess;
    QStringList listm;
    QStringList files;
    long long int pid;
    int curr;
    mytty *ttylink;
    int fd2;

signals:
    void retSig();
};

#endif // WIDGET_H
