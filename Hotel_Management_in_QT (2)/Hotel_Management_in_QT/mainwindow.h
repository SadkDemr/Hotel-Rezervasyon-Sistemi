#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rezerve.h"
#include "odeme.h"
#include "odaUygunluk.h"
#include "islemler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    RoomAvailableDialog * ptrRoomAvailableDlg;
    CheckOutDialog * ptrCheckOutDlg;
    BookRoomDialog * ptrRoomBookingDlg;
    transaction * ptrTransaction;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRoomBooking_clicked();
    void on_btnRoomCheckout_clicked();
    void on_btnCheckAvailability_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
