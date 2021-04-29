#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   new_user_= new Kayit ();
   connect(new_user_,SIGNAL(add_new_user_clicked(),this,SLOT(add_new_user_slot)));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    new_user_->show();

}

void MainWindow::add_new_user_slot()
{
    new_user_->close();
    QString new_name = new_user_->get_new_username();
    ui->comboBox_users->addItem(new_name);
    new_user_->clear_lineEdit();

}
