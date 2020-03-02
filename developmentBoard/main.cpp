#include "widget.h"
#include <QApplication>
#include "mymenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    myMenu m;
    m.show();

    return a.exec();
}
