#ifndef ADMINWIN_H
#define ADMINWIN_H

#include <QMainWindow>
#include "billwin.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "selectdatewin.h"
#include "csinfowin.h"
#include "workreportwin.h"

namespace Ui {
class adminwin;
}

class adminwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminwin(QWidget *parent = 0);
    ~adminwin();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionrun_sql_2_triggered();

private:
    Ui::adminwin *ui;
};

#endif // ADMINWIN_H
