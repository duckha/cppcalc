#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>

namespace Ui {
class CalcWindow;
}

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalcWindow(QWidget *parent = 0);
    ~CalcWindow();

private:
    Ui::CalcWindow *ui;

private slots:
    void digits_numbers();
    void dot_push();
    void operations();
    void on_equal_clicked();
    void math();
};

#endif // CALCWINDOW_H
