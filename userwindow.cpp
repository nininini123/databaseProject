#include "userwindow.h"
#include "ui_userwindow.h"


userWindow::userWindow(QString uid,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userWindow)
{
    this->uid=uid;
    this->parentWidget()->setVisible(false);
    ui->setupUi(this);
    if(this->parentWidget()){
        qDebug()<<(int) (this->parentWidget()) ;
    }
}

userWindow::~userWindow()
{
//    this->parentWidget()->setVisible(true);
    delete ui;
}

void userWindow::on_pushButton_clicked()
{
    //缴费
    qDebug()<<"paywin2222222222";
    QMessageBox::about(this,"attention","\n请向工作人员完成缴费后录入该缴费信息,\n完成后记得向工作人员拿纸质的缴费凭证并妥善保存\n");
    payWin *pwin=new payWin(this->uid,this);
    pwin->show();
}

void userWindow::on_pushButton_2_clicked()
{
    qDebug()<<"click the button to get userinfowin...\n";
    userInfoWin=new UserInfoWindow(uid,this);
    userInfoWin->show();
}

void userWindow::on_pushButton_3_clicked()
{
    qDebug()<<"csinfowin2222222222";
    csinfowin=new CSInfoForUserWin(this);
    qDebug()<<"csinfowin333";
    csinfowin->show();
}

void userWindow::on_pushButton_4_clicked()
{
    svrMenuWin *svrmenuWin= new svrMenuWin(uid,this);
    svrmenuWin->show();
}
