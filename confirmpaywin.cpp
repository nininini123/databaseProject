#include "confirmpaywin.h"
#include "ui_confirmpaywin.h"
#include <QMessageBox>

confirmPayWin::confirmPayWin(int CSID ,QSqlQuery q,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::confirmPayWin)
{
    ui->setupUi(this);
    this->CSID = CSID;
    for(int i=0;i<8;i++) {
        ui->textBrowser->append(q.value(i).toString()+"\t");
    }
    int account ;
    QSqlQuery qselect("select account from User where uid = '"+q.value(2).toString()+"'");
    if(qselect.next()){
        account = qselect.value(0).toInt() + q.value(4).toInt();
    }
    else{
        qDebug()<<"error confirmpaywin.23333333333";
        QMessageBox::warning(this,"error","error at: select account from User where uid = '"+q.value(2).toString()+"'");
    }
    updateSqlStr = "update User set account =" +QString::number( account) +
            " , valid = 'Y' where uid = '" + q.value(2).toString() +"'";
    updateSqlStr2 = "update Payment set isDone = 'D' where NO = '" + q.value(1).toString() + "'";
    updateSqlStr3 = "update Payment set isDone = 'Y' where NO = '" + q.value(1).toString() + "'";
    qDebug()<<"updateSqlStr = \n"<<updateSqlStr<<"\n"<<updateSqlStr2<<"\n"<<updateSqlStr3<<"\n";
}

confirmPayWin::~confirmPayWin()
{
    delete ui;
}

void confirmPayWin::on_pushButton_clicked()
{
    QSqlQuery q;
    int index = ui->comboBox->currentIndex();
    switch (index) {
    case 0:
        qDebug()<<"NNNNNNNNNN";
        break;
    case 1:
        qDebug()<<"YYYYYYYYYYYYYY";
        if (!(q.exec(updateSqlStr) && q.exec(updateSqlStr3)) )  {
            qDebug()<<"error confirmpaywin.4555555555555555555";
            QMessageBox::warning(this,"error","error at: "+updateSqlStr+"\n"+updateSqlStr3 );
        }
        break;
    case 2:
        qDebug()<<"DDDDDDDDDDDDDDDDD";
        if (!(q.exec(updateSqlStr2) ) )  {
            qDebug()<<"error confirmpaywin.5666666666666666";
            QMessageBox::warning(this,"error","error at: "+updateSqlStr2 );
        }
        break;
    default:
        break;
    }
    qDebug()<<"to be closed";
    this->close();
}
