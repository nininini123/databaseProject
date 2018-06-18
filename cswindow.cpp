#include "cswindow.h"
#include "ui_cswindow.h"

CSWindow::CSWindow(int CSID ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSWindow)
{
    this->CSID = CSID;
    qDebug()<<"ready to set up cswin\n";
    ui->setupUi(this);
    this->parentWidget()->setVisible(false);
}

CSWindow::~CSWindow()
{
    delete ui;
}

void CSWindow::on_pushButton_clicked()
{

    confirmPayWin *cfwin;
    QSqlQuery query("select * from toBePro where CSID = "+QString::number(CSID) +" and toBePro.isDone = 'N'");
    while(query.next()) {
        cfwin = new confirmPayWin(CSID,query,this);
        cfwin->show();
    }
}

void CSWindow::on_pushButton_2_clicked()
{
    searchUserWin *suwin = new searchUserWin(this);
    suwin->show();
}

void CSWindow::on_pushButton_3_clicked()
{
    editUserWin *euwin = new editUserWin(this);
    euwin->show();
}

void CSWindow::on_pushButton_4_clicked()
{
    tobpwin *tbpwin=new tobpwin(this->CSID,this);
    tbpwin->show();
}
