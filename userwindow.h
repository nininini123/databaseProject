#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>
#include "userinfowindow.h"
#include "paywin.h"
#include "csinfoforuserwin.h"
#include "svrmenuwin.h"

namespace Ui {
class userWindow;
}

class userWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userWindow(QString uid,QWidget *parent = 0);
    ~userWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::userWindow *ui;
    UserInfoWindow *userInfoWin;
    CSInfoForUserWin* csinfowin;
    //svrMenuWin * svrmenuWin;
    QString uid;
};

#endif // USERWINDOW_H
