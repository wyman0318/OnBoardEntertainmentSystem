#ifndef LISTSECTION_H
#define LISTSECTION_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class listSection;
}

class listSection : public QWidget
{
    Q_OBJECT

public:
    explicit listSection(QWidget *parent = 0);
    ~listSection();

    bool checkExist(QString info);
    void addListItem(QString info);
    QString getItemCurrentString();
    void moveListIndex(int request);
    int getVolValue();
    void initCurrentRow(int row);
    void showList();

private slots:
    void on_volSd_valueChanged(int value);

    void on_movieLw_itemClicked(QListWidgetItem *item);

private:
    Ui::listSection *ui;

signals:
    void volChange(int value);
    void rowChange(QString info);
};

#endif // LISTSECTION_H
