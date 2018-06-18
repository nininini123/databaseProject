#include "paywin.h"
#include "ui_paywin.h"

payWin::payWin(QString uid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::payWin)
{
    this->uid = uid;
    qDebug()<<"paywin3333333";
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(9);
}

payWin::~payWin()
{
    delete ui;
}

void payWin::on_pushButton_clicked()
{
    bool ok1,ok2;
    int csid,money;
    QSqlQuery query;
    csid= ui->lineEditCSID->text().toInt(&ok1);
    money = ui->lineEditMoney->text().toInt(&ok2);
    if(ok1 && ok2 && money>0) {
        QString insertSql= "INSERT INTO Payment(uid ,money,	paydate, CSID ,svcRank) VALUES(\'" + this->uid +"\',"+this->ui->lineEditMoney->text() +",'"+QDateTime::currentDateTime().toString("yyyy/MM/dd") +"\',"+ui->lineEditCSID->text()+"," + ui->comboBox->currentText() +");";
        qDebug()<<insertSql;//
        if (query.exec(insertSql) ) {
            QMessageBox::about(this,"insert success","insert success");
//            QSqlQuery query1("select account from User where uid = '"+this->uid + "'");//查询表的内容
//            if (query1.next()) {
//                int curAccount = query1.value(0).toInt();//
//                qDebug()<<curAccount<<" curAccount\n";
//                curAccount += ui->lineEditMoney->text().toInt();
//                qDebug()<<curAccount<<" curAccount\n";
//                QString updateSql = "update User set account = " + QString::number(curAccount)+ " where uid = '"+this->uid+ "';";
//                qDebug() <<updateSql;
//                if (query.exec(updateSql) ){
//                    qDebug() << "update account success\n";
//                }
//                else {
//                    qDebug() << "update account failure\n";
//                }
//            }

            this->close();
            return ;
        }

    }
    QMessageBox::about(this,"input error","缴费登记失败，请检查输入是否正确或咨询客服");
}
