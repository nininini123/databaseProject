#include "svrmenuwin.h"
#include "ui_svrmenuwin.h"

svrMenuWin::svrMenuWin(QString uid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::svrMenuWin)
{
    this->uid=uid;
    ui->setupUi(this);

    InfoModel = new QSqlTableModel(this);
    InfoModel->setTable("SVRMenu");
    InfoModel->select();
    ui->tableView->setModel(InfoModel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,150);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,60);
}

svrMenuWin::~svrMenuWin()
{
    delete ui;
}

void svrMenuWin::on_pushButton_clicked()
{
    //更改套餐
    if(QMessageBox::question(this,"confirm","are u sure to change ur service ?")==QMessageBox::Yes) {
        qDebug()<<"accepted";
        QSqlQuery query;
        qDebug()<<"update User set sid = " + ui->lineEdit->text()+" where uid ='"+this->uid+"' ;";
        if(query.exec("update User set sid = " + ui->lineEdit->text()+" where uid ='"+this->uid+"' ;") ){
            qDebug()<<"success update service\n";
        }
        else {
            qDebug()<<"fail to update service\n";
        }
    }
    else {
        qDebug()<<"cancelled";
    }
}
