#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "deque.h"
#include "infowidget.h"
#include "../Task_2/mystylesheets.h"

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

    void printDeque();

private slots:

    void on_pushBackButton_clicked();

    void on_pushFrontButton_clicked();

    void on_popBackButton_clicked();

    void on_popFrontButton_clicked();

    void on_clearButton_clicked();

    void on_sizeButton_clicked();

    void on_emptyButton_clicked();

    void on_atButton_clicked();

private:
    Ui::MainWindow *ui;
    InfoWidget* info_widget;
    Deque<int> deque;
};
#endif // MAINWINDOW_H
