#ifndef CSINFOFORUSERWIN_H
#define CSINFOFORUSERWIN_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class CSInfoForUserWin;
}

class CSInfoForUserWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSInfoForUserWin(QWidget *parent = 0);
    ~CSInfoForUserWin();

private:
    Ui::CSInfoForUserWin *ui;
    QSqlTableModel *InfoModel;
};

#endif // CSINFOFORUSERWIN_H
