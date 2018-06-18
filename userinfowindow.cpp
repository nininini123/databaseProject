#include "userinfowindow.h"
#include "ui_userinfowindow.h"
#include "mainwindow.h"

UserInfoWindow::UserInfoWindow(QString uid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInfoWindow)
{
    ui->setupUi(this);////////////这个要在前面！！！！！！！！！！！！！

//    InfoModel = new QSqlTableModel(this);
//    InfoModel->setTable("SVRMenu");
//    InfoModel->select();
//    ui->tableView->setModel(InfoModel);
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->uid = QString(uid);
    InfoModel = new QSqlTableModel(this);
    InfoModel->setTable("userView");
    InfoModel->setFilter("uid = "+uid );
    InfoModel->select();
    qDebug()<<"userinfowin() 2223477\n";
    ui->tableView->setModel(InfoModel);
    ui->tableView->setRowHeight(0,60);
    ui->tableView->setColumnWidth(0,40);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,50);
    ui->tableView->setColumnWidth(5,150);
    ui->tableView->setColumnWidth(6,50);
    ui->tableView->setColumnWidth(7,50);
    ui->tableView->setColumnWidth(9,50);
    qDebug()<<"column width = ";
    qDebug()<< ui->tableView->columnWidth(0);
    qDebug()<<"userinfowin() 22239984\n";
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    qDebug()<<"userinfowin() 321\n";
    RecordModel = new QSqlTableModel(this);
    RecordModel->setTable("payRecord");
    RecordModel->setFilter("uid = "+uid );
    RecordModel->select();
    ui->tableView_2->setModel(RecordModel);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    ui->setupUi(this);
}

UserInfoWindow::~UserInfoWindow()
{
    delete InfoModel;
    delete RecordModel;
    delete ui;
}


void UserInfoWindow::on_action_triggered()
{
    QString fName ;
    fName=QFileDialog::getExistingDirectory(this);
    qDebug()<<fName;
    if(!fName.isNull()){
        fName.append("/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss_" )+"out.csv");
        QMessageBox::about(this,"文件导出","file is exported as "+fName);
        QFile fileout(fName);
        if(!fileout.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream out(&fileout);

        QSqlQuery query("select * from userView where uid = \'" + uid  +"\'");//
        out<<QString("证件号,证件类型 ,电话号码,	性别,姓名,地址 ,套餐号, 余额 , 备注 ,	valid ,套餐名,description\n").toUtf8();
        while (query.next()) {
            for(int i=0;i<12;i++){
                out<<query.value(i).toString()<<",";
            }
            out<<"\n";
        }
        out<<"\n";
        QSqlQuery query2("select * from payRecord where uid = \'" + uid  +"\'");
        out<<QString("NO,证件号,姓名,缴费金额,受理客服,客服姓名, 日期,服务评价,交易成功\n").toUtf8();
        while (query2.next()) {
            for(int i=0;i<9;i++){
                out<<query2.value(i).toString()<<",";
            }
            out<<"\n";
        }

        out.flush();
        fileout.close();
    }

    else {
        QMessageBox::warning(this,"fbi warning","no dir selected");
    }
}
