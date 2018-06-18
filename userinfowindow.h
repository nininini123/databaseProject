#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QDateTime>

namespace Ui {
class UserInfoWindow;
}

class UserInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInfoWindow(QString uid,QWidget *parent = 0);
    ~UserInfoWindow();

private slots:
    void on_action_triggered();

private:
    Ui::UserInfoWindow *ui;
    QSqlTableModel *InfoModel;
    QSqlTableModel *RecordModel;
    QString uid;
};

#endif // USERINFOWINDOW_H
