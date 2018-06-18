#ifndef EDITUSERWIN_H
#define EDITUSERWIN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>

namespace Ui {
class editUserWin;
}

class editUserWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit editUserWin(QWidget *parent = 0);
    ~editUserWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editUserWin *ui;
};

#endif // EDITUSERWIN_H
