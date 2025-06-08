#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"

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
    void on_precisionBox_valueChanged(int arg1);

    void on_decBox_valueChanged(double arg1);

    void on_inputPrBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    double decimal = 0;
    int precision = 0;
    Converter* cnvr;
};
#endif // MAINWINDOW_H
