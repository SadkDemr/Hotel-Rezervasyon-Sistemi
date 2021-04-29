#ifndef ODAREZERVE_H
#define ODAREZERVE_H

#include <QDialog>

namespace Ui {
class OdaRezerve;
}

class OdaRezerve : public QDialog
{
    Q_OBJECT

public:
    explicit OdaRezerve(QWidget *parent = nullptr);
    ~OdaRezerve();

private:
    Ui::OdaRezerve *ui;
};

#endif // ODAREZERVE_H
