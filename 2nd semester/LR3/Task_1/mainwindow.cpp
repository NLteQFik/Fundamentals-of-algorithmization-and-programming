#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->decBox->setDecimals(0);
    ui->decBox->setRange(0, 10000);

    cnvr = new Converter();
    Update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update()
{
    cnvr->Compute(decimal, precision);
    ui->binBrowser->setText(cnvr->GetBinary());
}

void MainWindow::on_precisionBox_valueChanged(int arg1)
{
    this->precision = arg1;
    Update();
}


void MainWindow::on_decBox_valueChanged(double arg1)
{
    this->decimal = arg1;
    Update();
}


void MainWindow::on_inputPrBox_valueChanged(int arg1)
{
    ui->decBox->setDecimals(arg1);
}

