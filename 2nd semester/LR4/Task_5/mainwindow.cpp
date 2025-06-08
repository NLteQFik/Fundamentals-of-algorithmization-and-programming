#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initialise();
    Show();
    this->setMinimumSize(800, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialise()
{
    Vector<int> vec_int1 = {1, 2, 3};
    Vector<int> vec_int2 = {4, 5, 6};
    Vector<int> vec_int3 = {7, 8, 9};
    Vector<Pair<int, double>> vec_pair1 = {{1, 1.1}, {2, 2.2}, {3, 3.3}};
    Vector<Pair<int, double>> vec_pair2 = {{4, 4.4}, {5, 5.5}, {6, 6.6}};
    Vector<Pair<int, double>> vec_pair3 = {{7, 7.7}, {8, 8.8}, {9, 9.9}};
    vector.push_back({vec_int1, vec_pair1});
    vector.push_back({vec_int2, vec_pair2});
    vector.push_back({vec_int3, vec_pair3});
}

void MainWindow::Show()
{
    int rowCount = vector[0].first.size();
    int colCount1 = vector[0].first.size();
    int colCount2 = vector[0].second.size();
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(colCount1 + colCount2);
    QStringList headers;
    for (int i = 0; i < colCount1; ++i) {
        headers << QString("Matrix 1, Col %1").arg(i + 1);
    }
    for (int i = 0; i < colCount2; ++i) {
        headers << QString("Matrix 2, Col %1").arg(i + 1);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount1; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(vector[0].first[j]));
            ui->tableWidget->setItem(i, j, item);
        }
        for (int j = 0; j < colCount2; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(vector[0].second[j].first) + ", " + QString::number(vector[0].second[j].second));
            ui->tableWidget->setItem(i, colCount1 + j, item);
        }
    }
}
