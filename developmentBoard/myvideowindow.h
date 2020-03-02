#ifndef MYVIDEOWINDOW_H
#define MYVIDEOWINDOW_H

#include <QWidget>
#include <QDir>
#include <QStringList>
#include <QDebug>
#include <Q_PID>
#include <QProcess>
#include <unistd.h>
#include "mytty.h"
#include "vol.h"
#include "listsection.h"

namespace Ui {
class myVideoWindow;
}

class myVideoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit myVideoWindow(QWidget *parent = 0);
    ~myVideoWindow();
    void DirFlush();
    void cutMovie();

private slots:
    void on_prevBtn_clicked();
    void on_ssBtn_clicked();
    void on_killBtn_clicked();
    void on_nextBtn_clicked();
    void on_retBtn_clicked();
    void finished();
    void blue_action(int);
    void volChangeSlot(int value);
    void listChangeSlot(QString string);

private:
    Ui::myVideoWindow *ui;

    bool press;
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

    listSection *list;

signals:
    void retSig();
};

#endif // MYVIDEOWINDOW_H
