#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QDate>
#include <QSpinBox>


#include <QGridLayout>

#include <QDebug>

#include "date.h"

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

    void OpenFile();
    void ReadFromFile();
    void AddToFile(Date date);
    void ModifyFile(int row, Date date);

    void addTable();
    void updateTable();

private slots:
    void on_day_possibility(int i);

    void on_confirm_clicked();

    void on_openButton_clicked();

    void on_birthdayButton_clicked();

    void on_addButton_clicked();

    void on_changeButton_clicked();

    void on_openButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox* error_box;
    QString file_name = "";

    Date today = Date(0, 0, 0);
    Date birthday = Date(27, 3, 2007);
    QVector<Date> dates;

    QWidget* date_widget;
    QSpinBox* day_ch;
    QSpinBox* month_ch;
    QSpinBox* year_ch;
    int action = -1;


};
#endif // MAINWINDOW_H
