#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>
#include "widget.h"
#include "myvideowindow.h"

namespace Ui {
class myMenu;
}

class myMenu : public QWidget
{
    Q_OBJECT

public:
    explicit myMenu(QWidget *parent = 0);
    ~myMenu();

private slots:
    void on_musicBtn_clicked();

    void on_videoBtn_clicked();

private:
    Ui::myMenu *ui;

    Widget *myWidget;
    myVideoWindow *myVideo;
};

#endif // MYMENU_H
