#include "billwin.h"
#include "ui_billwin.h"
#include <QDateTime>

billWin::billWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::billWin)
{
    ui->setupUi(this);

    QString timeStr = QDateTime::currentDateTime().toString("yyyy/MM/dd");
    QSqlQuery query("select uid,account,sid from User where sid > 1;");
    QSqlQuery q2;
    int account,sid,temp;
    QString uid;
    while(query.next()) {
        uid=query.value(0).toString();
        account =query.value(1).toInt();
        sid=query.value(2).toInt();
        q2.exec( "select sprice from SVRMenu where sid = "+QString::number(sid) );
        if(q2.next()) {
            temp =  q2.value(0).toInt();
            if( temp <= account ){
                //扣费
                if(q2.exec( "update User set account = " + QString::number(account-temp) + " where uid = " + uid )){
                    qDebug()<<"q2.exec";
                    ui->textBrowser->append( "用户"+ uid +" 扣款成功");
                }
                else {
                    qDebug()<<"fail!!!!!!!!!!!!!!!billwin.26666666";
                }

                if(q2.exec( "INSERT INTO Payment(uid ,money,	paydate,	CSID ,isDone) VALUES(\'" + uid +"\'," + QString::number(temp-account)+",'" +timeStr +"',0,'Y');") )   {
                    qDebug()<<"q2.exec33987568\t"<<"INSERT INTO Payment(uid ,money,	paydate,	CSID ,isDone) VALUES(\'" + uid +"\'," + QString::number(temp-account)+",'" +timeStr +"',0,'Y');\n";
                }
                else {
                    qDebug()<<"fail!!!!!!!!!!!!!!!billwin.13579377777";
                }
            }
            else{
                //余额不足
                if(q2.exec( "update User set valid = 'N' where uid = "+ uid )) {
                    ui->textBrowser->append( "用户"+ uid +" 扣款失败,余额不足,服务停用");
                    qDebug()<<"q2.exec billwin.322323232\n";
                }
                else {
                    qDebug()<<"fail!!!!!!!!!!!!!!!billwin.333666666\n";
                }
            }
        }
        else {
            QMessageBox::warning(this,"eror updating data","error executing select sprice from SVRMenu where sid = "+QString::number(sid));
        }
    }
}

billWin::~billWin()
{
    delete ui;
}
