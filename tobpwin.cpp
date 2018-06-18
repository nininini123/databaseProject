#include "tobpwin.h"
#include "ui_tobpwin.h"
#include <QSqlError>

tobpwin::tobpwin(int CSID ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tobpwin)
{
    this->CSID = CSID;
    ui->setupUi(this);
    InfoModel = new QSqlRelationalTableModel(this);
    // InfoModel->setEditStrategy(QSqlTableModel:: //OnManualSubmit);//  OnFieldChange);
    InfoModel->setTable("toBePro");
    InfoModel->setRelation(6,QSqlRelation("isDone","isDone","isDone"));
    InfoModel->setFilter("CSID = "+QString::number(CSID) +" and toBePro.isDone = 'N'" );

    InfoModel->setHeaderData(6,Qt::Horizontal,QObject::tr("isDone"));
    InfoModel->select();
    ui->tableView->setModel(InfoModel);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mysqlDelegate = new QSqlRelationalDelegate(ui->tableView);
    ui->tableView->setItemDelegate(mysqlDelegate );
    // ui->tableView->setEditTriggers(QAbstractItemView:: )//::NoEditTriggers);

    ui->tableView->setColumnWidth(0,40);
    ui->tableView->setColumnWidth(1,40);
    ui->tableView->setColumnWidth(3,70);
    ui->tableView->setColumnWidth(4,40);
    ui->tableView->setColumnWidth(6,50);
}

tobpwin::~tobpwin()
{
    delete ui;
}

void tobpwin::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<"checkBox_stateChanged";
    if(ui->checkBox->isChecked()){
        qDebug()<<"1\n"<<arg1;
        InfoModel->setTable("toBePro");
        InfoModel->setRelation(6,QSqlRelation("isDone","isDone","isDone"));
        InfoModel->setFilter("CSID = "+QString::number(CSID) );

        InfoModel->setHeaderData(6,Qt::Horizontal,QObject::tr("isDone"));
        InfoModel->select();
        ui->tableView->setModel(InfoModel);

//        ui->tableView->setItemDelegate(mysqlDelegate );
        ui->tableView->setColumnWidth(0,40);
        ui->tableView->setColumnWidth(1,40);
        ui->tableView->setColumnWidth(3,70);
        ui->tableView->setColumnWidth(4,40);
        ui->tableView->setColumnWidth(6,40);
        ui->tableView->setColumnWidth(7,150);
//        ui->tableView->setModel(InfoModel);
//        this->update();
    }
    else {
        qDebug()<<"2\n"<<arg1;
        InfoModel->setTable("toBePro");
        InfoModel->setRelation(6,QSqlRelation("isDone","isDone","isDone"));
        InfoModel->setFilter("CSID = "+QString::number(CSID) +" and toBePro.isDone = 'N'" );

        InfoModel->setHeaderData(6,Qt::Horizontal,QObject::tr("isDone"));
        InfoModel->select();
        ui->tableView->setModel(InfoModel);
//        ui->tableView->setItemDelegate(mysqlDelegate );
        ui->tableView->setColumnWidth(0,40);
        ui->tableView->setColumnWidth(1,40);
        ui->tableView->setColumnWidth(3,70);
        ui->tableView->setColumnWidth(4,40);
        ui->tableView->setColumnWidth(6,40);
        ui->tableView->setColumnWidth(7,150);
//        ui->tableView->setModel(InfoModel);
//        this->update();
    }
}

void tobpwin::on_pushButton_clicked()
{
    if(InfoModel->submitAll() ){
        qDebug()<< "submit success";
    }
    else {
        qDebug()<< InfoModel->lastError().databaseText();
        qDebug()<< InfoModel->lastError().text();
        qDebug()<< InfoModel->lastError().driverText();
        qDebug()<< InfoModel->lastError().nativeErrorCode();
    }
    qDebug()<< InfoModel->lastError().databaseText();
    qDebug()<< InfoModel->lastError().text();
    qDebug()<< InfoModel->lastError().driverText();
    qDebug()<< InfoModel->lastError().nativeErrorCode();
}
