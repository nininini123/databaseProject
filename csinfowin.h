#ifndef CSINFOWIN_H
#define CSINFOWIN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class csinfoWin;
}

class csinfoWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit csinfoWin(QWidget *parent = 0);
    ~csinfoWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::csinfoWin *ui;
     QSqlTableModel* InfoModel ;
};

#endif // CSINFOWIN_H
