#include "odarezerve.h"
#include "ui_odarezerve.h"
#include <QDebug>

OdaRezerve::OdaRezerve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OdaRezerve)
{
    ui->setupUi(this);
    this->setFixedSize(320,240);
}
void OdaRezerve:: readData()
{
    qDebug()<<"BookRoomDialog:readData";
    std::vector<int>odalar = Hotel::getInstance()->getRoomList("y");
    this->ui->cmbRoomList->clear();

    for(std::vector<int>::iterator it = odalar.begin(); it!=odalar.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
    }
}
OdaRezerve::~OdaRezerve()
{
    delete ui;
}
