#include "workreportwin.h"
#include "ui_workreportwin.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>

workReportWin::workReportWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::workReportWin)
{
    ui->setupUi(this);
}

void workReportWin::setStartDate(QDateTime t)
{
    this->t1 = t;
}
void workReportWin::setEndDate(QDateTime t)
{
    this->t2 = t;
}

void workReportWin::display()
{
    InfoModel = new QSqlTableModel(this);
    InfoModel->setTable("Payment");
    InfoModel->setFilter("CSID>0 and isDone = 'Y' and date(paydate)  between '" +t1.toString("yyyy/MM/dd") + "' and '" +t2.toString("yyyy/MM/dd") +"'");

    qDebug()<<"select * from payment where CSID>0 and isDone = 'Y' and date(paydate)  between '" +t1.toString("yyyy/MM/dd") + "' and '" +t2.toString("yyyy/MM/dd") +"'";
    InfoModel->select();
    ui->tableView->setModel(InfoModel);
//    select * from product where date(add_time) between '2013-01-01' and '2013-01-31'
}

workReportWin::~workReportWin()
{
    delete ui;
}

void workReportWin::on_actionexport_as_file_triggered()
{
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    QString fName ;
    fName=QFileDialog::getExistingDirectory(this);
    qDebug()<<fName;
    if(!fName.isNull()){
        fName.append("/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss_" )+"report.csv");
        QMessageBox::about(this,"文件导出","file is exported as "+fName);
        QFile fileout(fName);
        if(!fileout.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream out(&fileout);

        QSqlQuery query("select * from payment where CSID>0 and isDone = 'Y' and date(paydate)  between '" +t1.toString("yyyy/MM/dd") + "' and '" +t2.toString("yyyy/MM/dd") +"'");//
        out<<QString(" NO,uid,money,paydate,CSID,svcRank,isDone\n").toUtf8();
        while (query.next()) {
            for(int i=0;i<7;i++){
                out<<query.value(i).toString()<<",";
            }
            out<<"\n";
        }
        out<<"\n";
        out.flush();
        fileout.close();
    }
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
}

void workReportWin::on_pushButton_clicked()
{
    //查看用户评价
    qDebug()<<"select CSID,avg(svcRank) from payment where CSID>0 and isDone = 'Y' and date(paydate)  between '" +t1.toString("yyyy/MM/dd") + "' and '" +t2.toString("yyyy/MM/dd") +"' group by CSID"<<"\n";
    QSqlQuery query("select CSID,avg(svcRank) from payment where CSID>0 and isDone = 'Y' and date(paydate)  between '" +t1.toString("yyyy/MM/dd") + "' and '" +t2.toString("yyyy/MM/dd") +"' group by CSID");
    int row=0;
//    ui->tableWidget->setRowCount(3);
    qDebug()<<"66";
    while (query.next()) {

        ui->tableWidget->setRowCount(row+1);
        qDebug()<<"22";
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString() )) ;
        qDebug()<<"22";
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString() )) ;
//        ui->tableWidget->item(row,1)->setText(query.value(1).toString() );
        qDebug()<<"22";
        row++;
    }
}

void workReportWin::on_pushButton_2_clicked()
{
    ;;;;;;;;;;;;;;;;;;;;;
    QSqlQuery q;
    int row = ui->tableWidget->rowCount();
    for (int i=0;i<row;i++){
        if(! q.exec("update CustomerService set rank =" +ui->tableWidget->item(i,1)->text()+" where CSID= "+ ui->tableWidget->item(i,0)->text() )){
            QMessageBox::warning(this,"error","cannot exec: \"update CustomerService set rank =" +ui->tableWidget->item(i,1)->text()+" where CSID= "+ ui->tableWidget->item(i,0)->text()+"\" at workreportwin.cpp.988888888888888 ");
        }
    }
    QMessageBox::about(this,"updating rank","done updating employee's rank");
}
