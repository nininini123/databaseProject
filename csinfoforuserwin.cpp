#include "csinfoforuserwin.h"
#include "ui_csinfoforuserwin.h"

CSInfoForUserWin::CSInfoForUserWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSInfoForUserWin)
{
    ui->setupUi(this);

    InfoModel = new QSqlTableModel(this);
    InfoModel->setTable("CSInfoForUser");
    InfoModel->select();
    ui->tableView->setModel(InfoModel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,60);

}

CSInfoForUserWin::~CSInfoForUserWin()
{
    delete ui;
}
