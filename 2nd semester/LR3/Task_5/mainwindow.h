#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileSystemModel>

#include "dirsfilescounter.h"
#include "directorymodel.h"

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

private:
    Ui::MainWindow *ui;
    QString sel_dir;
    DirsFilesCounter dfc;
    long long files, dirs;
    DirectoryModel* model;
};
#endif // MAINWINDOW_H
