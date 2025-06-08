#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setMaximum(999999999);
    calc = new Converter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->textBrowser->setText(QString::number(calc->Compute(arg1)));
}

