#ifndef MYTTY_H
#define MYTTY_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QFile>

class mytty : public QThread
{
    Q_OBJECT
public:
    explicit mytty(int fd);
    void run() override;

signals:
    void blue_msg(int);
    void blue_msgc(QString);

public slots:

private:
    int fd2;
};

#endif // MYTTY_H
