#include "otelRezarvasyon.h"
#include "QDebug"

Hotel* Hotel::instance = nullptr;

int Hotel::CheckOut(int odano)
{
    qDebug()<<"in CheckOut for room no : " << odano;
    //Odaların Database Yükleme kısmı

    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
    Database.setDatabaseName("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db");
    if(QFile::exists("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db"))
        qDebug() << "DB file exist";
    else
       qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("update odaRezervasyonu set available ='y' where number='" +QString::number(odano)+ "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();


    Database.close();
    //getRoomList();
    return 0;
}

int Hotel::BookRoom(int odano, QString isim, QString telNo, QString kaldigiGun, QString adres)
{
    qDebug() << "in BookRoom for room no : "<< odano;

    //Kaıt ettiğimiz kişilerin database atıldığı kısım

    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
    Database.setDatabaseName("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db/database.db");
    if(QFile::exists("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db/database.db"))
        qDebug() << "DB file exist";
    else
       qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);

    //Hotel odası sorgu hazırlama bölümü
    query.prepare("update odaRezervasyonu set available ='n' where number='" +QString::number(odano)+ "'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();

    //Müşteri sorgulama bölümü
    query.clear();
    query.prepare("insert into musteri (isim, telNo, kaldigiGun, adres) values ('" + isim + "','" + telNo + "','" + kaldigiGun + "','" + adres + "')");
    QString customer_id;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() << "Update was successful "<< query.lastQuery();
        customer_id = query.lastInsertId().toString();
        qDebug() <<"Last Inserted Id is  : "<< customer_id;
    }

    //Ödeme bölümü
    query.clear();
    query.prepare("insert into islemler (room, customer_id) values ('" + QString::number(odano) + "','" + customer_id + "')");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        qDebug() <<"Update was successful "<< query.lastQuery();
        qDebug() <<"Last Inserted Id is  : "<<query.lastInsertId().toString();
    }

    Database.close();
    //getRoomList();
    return 0;
}

std::vector<int> Hotel::getRoomList(QString flag = "y")
{
        std::vector<int> odalar;
        //if(availableRooms.empty())
        QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
        Database.setDatabaseName("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db/database.db");
        if(QFile::exists("C:/Users/msdemir/Downloads/Hotel-Rezervasyon-Sistemi-master (1)/Hotel-Rezervasyon-Sistemi-master/Hotel_Management_in_QT (2)/database/database.db/database.db"))
            qDebug() << "DB file exist";
        else
           qDebug() << "DB file doesn't exists";

        if (!Database.open())
            qDebug() << Database.lastError().text();
        else
            qDebug() << "Database loaded successfull!";

        QSqlQuery query(Database);
        query.prepare("select number from odaRezervasyonu where available = '" + flag + "'");

        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "Fetch was successful";

        while(query.next())
        {
            QString kayit = query.value(0).toString();
            odalar.push_back(kayit.toInt());
            qDebug()<<"Line is : "<<kayit;
        }

        Database.close();
        return odalar;
}

Hotel *Hotel::getInstance()
{
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}
