#ifndef KAYIT_H
#define KAYIT_H

#include <QWidget>

namespace Ui {
class Kayit;
}

class Kayit : public QWidget
{
    Q_OBJECT

public:
    explicit Kayit(QWidget *parent = nullptr);
    ~Kayit();

    QString get_new_username();
    void clear_lineEdit();
signals:
    void add_new_user_clicked();


private:
    Ui::Kayit *ui;
};

#endif // KAYIT_H
