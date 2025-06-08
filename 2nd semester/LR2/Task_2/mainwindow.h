#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QSpinBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QRadioButton>

#include "student.h"
#include "fileservices.h"
#include "studentwidget.h"
#include "sortwidget.h"
#include "student.h"

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

    void AddTable();
    void UpdateTable();
    void UpdateTable(QVector<Student> v);

    void SortAll();
    void SortGroup();
    void ShowPosit();
    void ShowPersons();

    void InitStudWidget();
    void InitSortWidget();

    void DisableFunction();
    void EnableFunction();

private slots:
    void on_confirm_clicked();
    void on_confirm_2_clicked();

    void on_findButton_clicked();
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_addButton_clicked();
    void on_correctButton_clicked();
    void on_deleteButton_clicked();
    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox* error_box;
    FileServices file;

    QVector<Student> students;
    int action = 0;
    int row = 0;

    QWidget* stud_widget;
    QLineEdit* subjects[5];
    QLineEdit* speciality;
    QLineEdit* name;
    QSpinBox* marks[5];
    QSpinBox* group;
    StudentWidget* st_widget;

    QWidget* sort_widget;
    QSpinBox* sr_group;
    QLineEdit* sr_name;
    QRadioButton* sort_all;
    QRadioButton* sort_group;
    QRadioButton* give_positive;
    QRadioButton* find_stud;
};
#endif // MAINWINDOW_H
