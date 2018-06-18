#ifndef CONFIRMPAYWIN_H
#define CONFIRMPAYWIN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class confirmPayWin;
}

class confirmPayWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit confirmPayWin(int CSID ,QSqlQuery q,QWidget *parent = 0);
    ~confirmPayWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::confirmPayWin *ui;
    int CSID ;
    QString updateSqlStr,updateSqlStr2,updateSqlStr3;
};

#endif // CONFIRMPAYWIN_H
