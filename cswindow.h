#ifndef CSWINDOW_H
#define CSWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <tobpwin.h>
#include <QMessageBox>
#include "searchuserwin.h"
#include "edituserwin.h"
#include "confirmpaywin.h"

namespace Ui {
class CSWindow;
}

class CSWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSWindow(int CSID ,QWidget *parent = 0);
    ~CSWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::CSWindow *ui;
    int CSID ;
};

#endif // CSWINDOW_H
