#include "listsection.h"
#include "ui_listsection.h"
#include <QDebug>

listSection::listSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listSection)
{
    ui->setupUi(this);

    ui->volSd->setRange(-20,0);
    ui->volSd->setValue(-10);
}

listSection::~listSection()
{
    delete ui;
}

bool listSection::checkExist(QString info)
{
    return !ui->movieLw->findItems(info,Qt::MatchFixedString).isEmpty();
}

void listSection::addListItem(QString info)
{
    ui->movieLw->addItem(info);
}

QString listSection::getItemCurrentString()
{
    return ui->movieLw->currentItem()->text();
}

void listSection::moveListIndex(int request)
{
    if(request==0)
    {
        if(ui->movieLw->currentRow()==0)
        {
            ui->movieLw->setCurrentRow(ui->movieLw->count()-1);
        }
    }
    else
    {
        ui->movieLw->setCurrentRow((ui->movieLw->currentRow()+1)%ui->movieLw->count());
    }
}

int listSection::getVolValue()
{
    return ui->volSd->value();
}

void listSection::initCurrentRow(int row)
{
    ui->movieLw->setCurrentRow(row);
}

void listSection::showList()
{
    qDebug() << "list:"<<ui->movieLw->count();
}

void listSection::on_volSd_valueChanged(int value)
{
    emit volChange(value);
}

void listSection::on_movieLw_itemClicked(QListWidgetItem *item)
{
    emit rowChange(item->text());
}
