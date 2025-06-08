#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ackermannfunction.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Update();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    AckermannFunction* calc;
    long long n = 0, m = 0;
};
#endif // MAINWINDOW_H
