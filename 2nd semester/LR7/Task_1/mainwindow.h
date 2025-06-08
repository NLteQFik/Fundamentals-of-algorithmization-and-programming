#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include <QListWidget>
#include <QRandomGenerator64>
#include <QMessageBox>

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
    void on_pushButton_clicked();

    void on_popButton_clicked();

    void on_fillButton_clicked();

    void on_insertButton_clicked();

    void on_sizeButton_clicked();

    void on_emptyButton_clicked();

    void on_frontButton_clicked();

    void on_backButton_clicked();

private:
    void showQueue(QListWidget* showingWidget, Queue<int>& showedQueue);

    Ui::MainWindow *ui;

    QMessageBox* msgBox = new QMessageBox();

    Queue<int> queue;
    Queue<int> queue1;
    Queue<int> queue2;
};
#endif // MAINWINDOW_H
