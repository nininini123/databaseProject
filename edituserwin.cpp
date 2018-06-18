#include "edituserwin.h"
#include "ui_edituserwin.h"

editUserWin::editUserWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editUserWin)
{
    ui->setupUi(this);
    ui->tableWidget->setRowHeight(0,100);
    QComboBox *comBox = new QComboBox();
    comBox->addItem("身份证");
    comBox->addItem("护照");
    comBox->addItem("其他");
    ui->tableWidget->setCellWidget(0,1,comBox);


    QComboBox *comBox2 = new QComboBox();
    comBox2->addItem("F");
    comBox2->addItem("M");
    ui->tableWidget->setCellWidget(0,3,comBox2);


}

editUserWin::~editUserWin()
{
    delete ui;
}

void editUserWin::on_pushButton_clicked()
{
    QString str = "INSERT INTO User(uid,idType,uname,gender,phone,address) VALUES ('"+ui->tableWidget->item(0,0)->text()+"','"+((QComboBox *)ui->tableWidget->cellWidget(0,1))->currentText() +"','" +ui->tableWidget->item(0,2)->text()+"','" +((QComboBox *)ui->tableWidget->cellWidget(0,3))->currentText() +"','" +ui->tableWidget->item(0,4)->text()+"','" +ui->tableWidget->item(0,5)->text()+"')";
    qDebug()<<"\t" << str<<"\n";
    QSqlQuery query;
    if (query.exec(str)) {
        QMessageBox::about(this,"ok","user added!");
    }
    else  {
        QMessageBox::about(this,"error","operation failed");
    }
}
