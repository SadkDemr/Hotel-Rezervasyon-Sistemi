#ifndef BOOKROOMDIALOG_H
#define BOOKROOMDIALOG_H

#include <QDialog>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <vector>
#include <QMessageBox.h>

#include "otelRezarvasyon.h"

namespace Ui {
class BookRoomDialog;
}

class BookRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookRoomDialog(QWidget *parent = nullptr);
    ~BookRoomDialog();
    void readData();
private slots:
    void on_btnCancel_clicked();
    void on_btnSubmit_clicked();

private:
    Ui::BookRoomDialog *ui;
};

#endif // BOOKROOMDIALOG_H
