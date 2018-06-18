#include "adminwin.h"
#include "ui_adminwin.h"
#include "runsqlwin.h"

adminwin::adminwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminwin)
{
    ui->setupUi(this);
}

adminwin::~adminwin()
{
    delete ui;
}

void adminwin::on_pushButton_3_clicked()
{
    billWin *billwin = new billWin(this);
    billwin->show();
}

void adminwin::on_pushButton_clicked()
{
    selectDateWin *sdwin = new selectDateWin(this);
    sdwin->show();
}

void adminwin::on_pushButton_2_clicked()
{
    csinfoWin* csinfo = new csinfoWin(this);
    csinfo->show();
}

void adminwin::on_actionrun_sql_2_triggered()
{
    if(QMessageBox::question(this,"warning","this operation may be dangerous, do not continue unless you know what you are doing!\nConsult IT department for details")==QMessageBox::Yes) {
        runSqlWin *runWin = new runSqlWin(this);
        runWin->show();
    }
}
