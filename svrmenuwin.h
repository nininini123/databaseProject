#ifndef SVRMENUWIN_H
#define SVRMENUWIN_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include "userwindow.h"

namespace Ui {
class svrMenuWin;
}

class svrMenuWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit svrMenuWin(QString uid,QWidget *parent = 0);
    ~svrMenuWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::svrMenuWin *ui;
    QSqlTableModel *InfoModel;
    QString uid;
};

#endif // SVRMENUWIN_H
