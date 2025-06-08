#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include "hashtable.h"
#include "linearhashtable.h"
#include "quadratichashtable.h"
#include "doublehashtable.h"
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

private slots:
    void on_pushButton_2_clicked();

    void on_sizeSpinBox_valueChanged(int arg1);

    void on_occupancySpinBox_valueChanged(int arg1);

    void on_testsSpinBox_valueChanged(int arg1);

private:
    void TestHashTable(HashTable* table);
    void FillTables();
    void BuildGraphics();

    Ui::MainWindow *ui;

    int table_occupancy;
    int table_size;
    int tests_number;

    LinearHashTable* linear_table;
    QuadraticHashTable* quadratic_table;
    DoubleHashTable* double_table;
};
#endif // MAINWINDOW_H
