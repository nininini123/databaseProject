#include "csinfowin.h"
#include "ui_csinfowin.h"

csinfoWin::csinfoWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::csinfoWin)
{
    ui->setupUi(this);

    InfoModel = new QSqlTableModel(this);
    InfoModel->setTable("CustomerService");
    InfoModel->setFilter("valid = 'Y'");
    InfoModel->select();
    ui->tableView->setModel(InfoModel);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

csinfoWin::~csinfoWin()
{
    delete ui;
}

void csinfoWin::on_pushButton_clicked()
{
    QSqlQuery q;
    if( q.exec("INSERT INTO CustomerService(CSID , gender,CSname ,pwd) VALUES("  + ui->lineEdit->text() +",'"+ ui->comboBox->currentText() + "','"+ui->lineEdit_3->text() +"','"+ui->lineEdit_4->text()+"');" ) ){
        QMessageBox::about(this,"msg","employee "+ ui->lineEdit->text()+" added ");
    }
    else {
        QMessageBox::about(this,"fail","cannot add new employee" );
    }
}

void csinfoWin::on_pushButton_3_clicked()
{
    QSqlQuery q;
    if( q.exec( "update CustomerService set valid ='N' where CSID =" +ui->lineEdit_del->text() ) ) {
        QMessageBox::about(this,"msg","employee "+ ui->lineEdit_del->text()+" deleted ");
    }
    else {
        QMessageBox::about(this,"fail","cannot delete "+ ui->lineEdit_del->text() );
    }
}

void csinfoWin::on_pushButton_2_clicked()
{
    InfoModel->setTable("CustomerService");
    InfoModel->setFilter("valid = 'Y' and CSname like'%" + ui->lineEdit_5->text()+"%'");
    InfoModel->select();
}
