#include "odeme.h"
#include "ui_odeme.h"
#include "QDebug"

CheckOutDialog::CheckOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);

    qDebug()<<"in constructor of CheckOutDialog";
    ui->label->setText("Oda Sec");
    ui->btnCheckout->setText("Sil");
    ui->btnCancel->setText("Kapat");

}


void CheckOutDialog::readData()
{
    std::vector<int>odalar = Hotel::getInstance()->getRoomList("n");
    this->ui->cmbRoomList->clear();
    char flag = 0;
    for(std::vector<int>::iterator it = odalar.begin(); it!=odalar.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
        flag = 1;
    }

    if(flag==1) this->ui->btnCheckout->setEnabled(true);

}
CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}
//Kapatma butonu
void CheckOutDialog::on_btnCancel_clicked()
{
    this->hide();
}
//Kaydı silme butonu
void CheckOutDialog::on_btnCheckout_clicked()
{

    //Oda çıkışını aratıp kaydı silme
    int  odano = ui->cmbRoomList->currentText().toInt();

    if(odano < 1)
    {
            QMessageBox::information(
            this,
            tr("Hata!"),
            tr("Kontrol edlicek kayit yok!") );
            return;
     }
    int ret = Hotel::getInstance()->CheckOut(odano);

    QString msg = "";
    ret==0?msg="Basarili!":"Hatali!";

    this->hide();

    if(ret == 0)
    {
        QMessageBox::information(
        this,
        tr("Basarili!"),
        tr("Oda cikisi yapildi!") );
    }
}
