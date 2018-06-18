#ifndef SELECTDATEWIN_H
#define SELECTDATEWIN_H

#include <QMainWindow>
#include <QDateTime>
#include <workreportwin.h>

namespace Ui {
class selectDateWin;
}

class selectDateWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit selectDateWin(QWidget *parent = 0);
    ~selectDateWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::selectDateWin *ui;
};

#endif // SELECTDATEWIN_H
