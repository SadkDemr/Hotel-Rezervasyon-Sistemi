#include "odaUygunluk.h"
#include "ui_odaUygunluk.h"
#include <QDebug>

RoomAvailableDialog::RoomAvailableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomAvailableDialog)
{
    ui->setupUi(this);
    this->setFixedSize(380,200);
    qDebug()<<"In RoomAvailableDialog()";
    ui->groupBox->setTitle("Odalar");
    ui->lblinfo->setText("Doluluk");

}
//Burası Odalar kısmına renk ekleme yeri
void RoomAvailableDialog::readData()
{
    qDebug()<<"in readData()";

    std::vector<int>odalar = Hotel::getInstance()->getRoomList("y");
    ui->lblinfo->setStyleSheet("QLabel { background-color : grey; color : aqua; }");

    std::vector<int>uygunOda =  {101, 102, 103, 104, 105, 201, 202, 203, 204, 205};

    //Varsayılan rengi hepsi için ayarlama
    for(std::vector<int>::iterator it = uygunOda.begin(); it!=uygunOda.end(); it++ )
    {
        //Odadan çıkış yapıldığında etiket rengi  değiştiren bölüm
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : aqua; }");
        }

    }

    for(std::vector<int>::iterator it = odalar.begin(); it!=odalar.end(); it++ )
    {
        //Oda rezerve edildiğinde Etiketlerin rengini değiştiren bölüm
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            //pLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");

            ptr->setStyleSheet("QLabel { background-color : grey; color : aqua; }");
        }

    }
}

RoomAvailableDialog::~RoomAvailableDialog()
{
    qDebug()<<"Deleting RoomAvailableDialog";
    delete ui;
}

void RoomAvailableDialog::on_pushButton_clicked()
{
    this->hide();
}
