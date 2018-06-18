#ifndef RUNSQLWIN_H
#define RUNSQLWIN_H

#include <QMainWindow>

namespace Ui {
class runSqlWin;
}

class runSqlWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit runSqlWin(QWidget *parent = 0);
    ~runSqlWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::runSqlWin *ui;
};

#endif // RUNSQLWIN_H
