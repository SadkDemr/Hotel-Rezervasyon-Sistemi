#include "rezerve.h"
#include "ui_rezerve.h"
//BookRoom denilen kısım oda rezervasyonun yapıldığı yerdir.
BookRoomDialog::BookRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookRoomDialog)
{
    ui->setupUi(this);

}
//Burası databaseden odaları alma kısmı
void BookRoomDialog:: readData()
{
    qDebug()<<"BookRoomDialog:readData";
    std::vector<int>odalar = Hotel::getInstance()->getRoomList("y");
    this->ui->cmbRoomList->clear();

    for(std::vector<int>::iterator it = odalar.begin(); it!=odalar.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
    }
}

BookRoomDialog::~BookRoomDialog()
{
    delete ui;
}
//Çıkış butonu
void BookRoomDialog::on_btnCancel_clicked()
{
    this->hide();
}
//Kayıt butonu
void BookRoomDialog::on_btnSubmit_clicked()
{
    //Burası kayıt alan verilen bilgiler bura kaydedilir
    int  odano = ui->cmbRoomList->currentText().toInt();
    QString isim = ui->txtName->text();
    QString telNo = ui->txtContactNumber->text();
    QString adres = ui->txtAddress->toPlainText();
    QString kaldigiGun = ui->txtIdProof->text();

    if(odano < 1)
    {
            QMessageBox::information(
            this,
            tr("Uyarı!"),
            tr("Yer Kalmadi") );
            return;
     }

    int ret = Hotel::getInstance()->BookRoom(odano, isim, telNo, kaldigiGun, adres);

    QString msg = "";
    ret==0?msg="Basarili Giris!":"Basarisiz Giris!";

    this->hide();

    if(ret == 0)
    {
        QMessageBox::information(
        this,
        tr("Basarili Giris!"),
        tr("Oda rezerve edildi!") );
    }
}
