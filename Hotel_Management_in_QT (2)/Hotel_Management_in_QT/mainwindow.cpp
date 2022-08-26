#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFixedSize(1000,600);

    ptrRoomAvailableDlg = new RoomAvailableDialog(this);
    ptrCheckOutDlg = new CheckOutDialog(this);
    ptrRoomBookingDlg = new BookRoomDialog(this);

    ptrCheckOutDlg->setWindowTitle("Ödeme");
    ptrRoomAvailableDlg->setWindowTitle("Odalar");




}

MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow: Deleting";
    delete ui;
    delete ptrRoomBookingDlg;
    delete ptrCheckOutDlg;
    delete ptrRoomAvailableDlg;
    delete ptrTransaction;
}
//Burası Oda Rezervasyonu Yapılan buton
void MainWindow::on_btnRoomBooking_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Room Booking";
    ptrRoomBookingDlg->readData();
    ptrRoomBookingDlg->show();

    if(ptrRoomBookingDlg->isVisible())
        qDebug()<<"New Window is visible";
    else
        qDebug()<<"New Window is not visible";
    //myHotel.BookRoom();
}
//Kayıt silme ödeme yapma ekranını açan buton
void MainWindow::on_btnRoomCheckout_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Room Checkout";
    ptrCheckOutDlg->readData();
    ptrCheckOutDlg->show();
}
//Odaların Doluluk Oranını gösterme
void MainWindow::on_btnCheckAvailability_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": In Check Availability";
    ptrRoomAvailableDlg->readData();
    ptrRoomAvailableDlg->show();
}


//Burası Kayıt edilen müşterilerin gösterildiği yer
void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
    Database.setDatabaseName("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db");
   QSqlQueryModel * modal= new QSqlQueryModel();
   Database.open();
   QSqlQuery* query=new QSqlQuery(Database);



    query->prepare("select * from musteri");

    query->exec();

    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    Database.close();
    qDebug()<<(modal->rowCount());
}
