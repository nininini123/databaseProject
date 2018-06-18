#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("电信收费系统登陆");

    //connect to sql
    db=QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("dianxin");
        db.setHostName("localhost");
        db.setUserName("dianxin");
        db.setPassword("password");

        if(!db.open())
        {
            qDebug() << "Connect to MySql error: " << db.lastError().text();
            return;
        }
        else
        {
            qDebug() << "Connect to MySql! ";
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    //help
    QMessageBox::about(this,"help","\n1.客服人员请输入工号和密码登陆,\n注意要勾选employee;\n\n2.客户请输入姓名和证件号码进行登陆,\n无法登陆的用户和第一次办理业务的新用户请到人工窗口处排队等待客服为您进行业务办理.\n");
}

void MainWindow::on_pushButton_clicked()
{
    QString inputName=ui->lineEdit->text();
    QString inputPwd=ui->lineEdit_2->text();
    qDebug() << inputName <<"\t:\t" << inputPwd ;
    if (ui->checkBox->isChecked() ){
        //employee
        QSqlQuery query("select CSID,CSname,gender from CustomerService where valid = 'Y' and CSID=" + ui->lineEdit->text() +" and pwd='" + ui->lineEdit_2->text() +"'");//
        if (query.next()) {
            QMessageBox::about(this,tr("Message"),tr("success to login"));
            if(ui->lineEdit->text().toInt()==0){
                if( QMessageBox::question(this,"manager login","本账号为管理员账号,倘若未经授权擅自使用该账号进行非法操作,本公司将依法追究责任!\n确认登陆？")==QMessageBox::Yes){
                    adminwin *adwin = new adminwin(this);
                    adwin->show();
                }
                else{
                    ui->lineEdit->clear();
                    ui->lineEdit_2->clear();
                }
            }
            else {
                //客服登陆
                //QMessageBox::about(this,tr("客服登陆"),tr("客服登陆成功"));
                qDebug()<<"cswindow";
                CSWindow *cswin = new CSWindow(ui->lineEdit->text().toInt(),this);
                cswin->show();
            }
        }
        else {
            QMessageBox::about(this,tr("Message"),tr("fail to login"));
        }

        // QSqlQuery query1("select * from thinkcmf_menu");//查询表的内容
        // while (query1.next()) {
        //     QString country = query1.value(0).toString();//cmf_menu表第1个字段的内容
        //     qDebug()<<country;
        // }
    }
    else {
        //user login
        QSqlQuery query("select uid from User where uname ='" + ui->lineEdit->text() +"\' and uid=\'" + ui->lineEdit_2->text() +"';");//
        if (query.next()) {
            QMessageBox::about(this,tr("Message"),tr("user success to login"));
            userWindow * userWin = new userWindow( query.value(0).toString(),this);
            userWin->show();
        }
        else {
            QMessageBox::about(this,tr("Message"),tr("user fail to login"));
        }

    }
    ;//login
}
