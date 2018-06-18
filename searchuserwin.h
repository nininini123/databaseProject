#ifndef SEARCHUSERWIN_H
#define SEARCHUSERWIN_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class searchUserWin;
}

class searchUserWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchUserWin(QWidget *parent = 0);
    ~searchUserWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::searchUserWin *ui;
    QSqlTableModel *InfoModel;
};

#endif // SEARCHUSERWIN_H
