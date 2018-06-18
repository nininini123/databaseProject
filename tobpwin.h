#ifndef TOBPWIN_H
#define TOBPWIN_H

#include <QMainWindow>
//#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

namespace Ui {
class tobpwin;
}

class tobpwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit tobpwin(int CSID ,QWidget *parent = 0);
    ~tobpwin();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::tobpwin *ui;
    int CSID ;
    QSqlRelationalTableModel *InfoModel;
    QSqlRelationalDelegate * mysqlDelegate;
};

#endif // TOBPWIN_H
