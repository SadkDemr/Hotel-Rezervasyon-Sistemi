#include "kayit.h"
#include "ui_kayit.h"

Kayit::Kayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kayit)
{
    ui->setupUi(this);

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SIGNAL(add_new_user_clicked()));

}

Kayit::~Kayit()
{
    delete ui;
}

QString Kayit::get_new_username()
{

    return ui->pushButton->text();
}

void Kayit::clear_lineEdit()
{
  ui->pushButton->clearFocus();
}
