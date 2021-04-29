#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include<vector>

class Hotel
{
private:
    Hotel(){}
    Hotel(Hotel const &){}
    static Hotel * instance;
    void updateHotelData(int room); //update DB & Vector

public:
    int BookRoom(int roomno, QString name, QString contactno, QString govid, QString address);
    int CheckOut(int roomno);
    std::vector<int> RoomAvailability();
    std::vector<int> getRoomList(QString);  //return vector
    static Hotel* getInstance();

};

#endif // HOTEL_H
