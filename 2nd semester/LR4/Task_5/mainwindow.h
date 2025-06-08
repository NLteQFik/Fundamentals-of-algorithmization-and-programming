#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTableWidget>
#include <QMainWindow>
#include "vector.h"
#include "pair.h"

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

    void Initialise();
    void Show();

private:
    Ui::MainWindow *ui;
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vector;
};
#endif // MAINWINDOW_H
