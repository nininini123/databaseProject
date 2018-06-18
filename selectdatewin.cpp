#include "selectdatewin.h"
#include "ui_selectdatewin.h"

selectDateWin::selectDateWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectDateWin)
{
    ui->setupUi(this);
    ui->dateEdit->setDate( QDateTime::currentDateTime().date().addMonths(-1) );
    ui->dateEdit_2->setDate( QDateTime::currentDateTime().date() );
}

selectDateWin::~selectDateWin()
{
    delete ui;
}

void selectDateWin::on_pushButton_clicked()
{
    workReportWin *wrwin = new workReportWin(this);
    wrwin->setStartDate(ui->dateEdit->dateTime());
    wrwin->setEndDate(ui->dateEdit_2->dateTime());
    wrwin->display();
    wrwin->show();
}
