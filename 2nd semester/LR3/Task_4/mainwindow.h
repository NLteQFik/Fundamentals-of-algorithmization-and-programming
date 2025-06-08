#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "hanoisolver.h"

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

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    HanoiSolver solver;
};
#endif // MAINWINDOW_H
