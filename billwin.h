#ifndef BILLWIN_H
#define BILLWIN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>


namespace Ui {
class billWin;
}

class billWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit billWin(QWidget *parent = 0);
    ~billWin();

private:
    Ui::billWin *ui;
};

#endif // BILLWIN_H
