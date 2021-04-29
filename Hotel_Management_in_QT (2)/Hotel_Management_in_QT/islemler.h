#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>

namespace Ui {
class transaction;
}

class transaction : public QDialog
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    void readData();
    ~transaction();

private:
    Ui::transaction *ui;
};
#endif // TRANSACTION_H
