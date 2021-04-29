#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <otelRezarvasyon.h>
#include <QMessageBox>

namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDialog(QWidget *parent = nullptr);
    ~CheckOutDialog();
    void readData();

private slots:
    void on_btnCancel_clicked();
    void on_btnCheckout_clicked();
private:
    Ui::CheckOutDialog *ui;
};

#endif // CHECKOUTDIALOG_H
