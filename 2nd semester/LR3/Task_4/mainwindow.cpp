#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hanoi Tower");
    this->setFixedSize(this->size());

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setRowHeight(0, 25);
    ui->tableWidget->setColumnWidth(0, 70);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 100);
    ui->tableWidget->setColumnWidth(3, 100);
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("Element"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("From"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("To"));
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Step"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int value)
{
    int step_num = 1;
    solver.Solve(value, step_num, 0, 2, ui->tableWidget);
}

