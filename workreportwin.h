#ifndef WORKREPORTWIN_H
#define WORKREPORTWIN_H

#include <QMainWindow>
#include <QDateTime>
#include <QSqlTableModel>
#include <QDebug>
#include "selectdatewin.h"

namespace Ui {
class workReportWin;
}

class workReportWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit workReportWin(QWidget *parent = 0);
    void setStartDate(QDateTime t);
    void setEndDate(QDateTime t);
    void display();
    ~workReportWin();

private slots:
    void on_actionexport_as_file_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::workReportWin *ui;
    QDateTime t1,t2;
    QSqlTableModel* InfoModel;
};

#endif // WORKREPORTWIN_H
