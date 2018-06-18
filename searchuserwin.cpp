#include "searchuserwin.h"
#include "ui_searchuserwin.h"

searchUserWin::searchUserWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchUserWin)
{
    ui->setupUi(this);

    InfoModel = new QSqlTableModel(this);
    //InfoModel->setTable("CSInfoForUser");
    InfoModel->select();
    ui->tableView->setModel(InfoModel);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

searchUserWin::~searchUserWin()
{
    delete ui;
}

void searchUserWin::on_pushButton_clicked()
{
    InfoModel->setTable("User");
    InfoModel->select();
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(3,40);
    ui->tableView->setColumnWidth(4,70);
    ui->tableView->setColumnWidth(6,40);
    ui->tableView->setColumnWidth(7,40);
    ui->tableView->setColumnWidth(8,60);
    ui->tableView->setColumnWidth(9,40);
}

void searchUserWin::on_pushButton_search_clicked()
{
    InfoModel->setTable("User");
    InfoModel->setFilter(" uid like '%"+ui->lineEdit->text() +"%'");
    InfoModel->select();
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(3,40);
    ui->tableView->setColumnWidth(4,70);
    ui->tableView->setColumnWidth(6,40);
    ui->tableView->setColumnWidth(7,40);
    ui->tableView->setColumnWidth(8,60);
    ui->tableView->setColumnWidth(9,40);
}
