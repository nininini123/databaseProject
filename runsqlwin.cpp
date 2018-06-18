#include "runsqlwin.h"
#include "ui_runsqlwin.h"

#include <QSqlQuery>
#include <QDebug>

runSqlWin::runSqlWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::runSqlWin)
{
    ui->setupUi(this);
}

runSqlWin::~runSqlWin()
{
    delete ui;
}

void runSqlWin::on_pushButton_clicked()
{
    QSqlQuery q;
    ui->textBrowser->append( "running \""+ ui->textEdit->toPlainText() +"\"");
    if (q.exec( ui->textEdit->toPlainText() )) {
       ui->textBrowser->append( "ok");
    }
    else {
         ui->textBrowser->append( "failed");
    }
    ;;;;;;;;;;;
}
