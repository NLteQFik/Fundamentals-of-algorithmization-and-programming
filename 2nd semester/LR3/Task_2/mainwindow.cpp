#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc = new AckermannFunction();
    Update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update()
{
    if (m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)) {
    ui->ansLabel->setText("A(" + QString::number(m) + ", " + QString::number(n)  + ") too large!");
    return;
    }
    ui->ansLabel->setText("A(" + QString::number(m) + ", " + QString::number(n) + ") = " + QString::number(calc->Compute(m, n)));
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    m = arg1;
    Update();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    n = arg1;
    Update();
}

