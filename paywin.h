#ifndef PAYWIN_H
#define PAYWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class payWin;
}

class payWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit payWin(QString uid,QWidget *parent = 0);
    ~payWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::payWin *ui;
    QString uid;
};

#endif // PAYWIN_H
