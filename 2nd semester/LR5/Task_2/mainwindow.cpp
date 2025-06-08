#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outLabel->setFont(QFont("arial", 20));

    setWindowTitle("String");
    setFixedSize(size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_constructButton_clicked()
{
    ui->outLabel->setText(String(ui->str1LineEditt->text().toStdString().c_str()).begin());
}


void MainWindow::on_memcmpButton_clicked()
{
    int a = strcmp(ui->str1LineEditt->text().toUtf8().data(),
                            ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "First is larger" : (a == 0 ? "Equal" : "Second is larger"));
}


void MainWindow::on_memmoveButton_clicked()
{
    ui->outLabel->setText((char *)memmove(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_memcpyButton_clicked()
{
    ui->outLabel->setText((char *)memcpy(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcpyButton_clicked()
{
    ui->outLabel->setText((char *)strcpy(ui->str1LineEditt->text().toUtf8().data(),
                                                  ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_strncpyButton_clicked()
{
    ui->outLabel->setText((char *)strncpy(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcatButton_clicked()
{
    ui->outLabel->setText((char *)strcat(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_strncatButton_clicked()
{
    ui->outLabel->setText((char *)strncat(ui->str1LineEditt->text().toUtf8().data(),
                    ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strcmpButton_clicked()
{
    int a = strcmp(ui->str1LineEditt->text().toUtf8().data(),
                           ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "First is larger" : (a == 0 ? "Equal" : "Second is larger"));
}


void MainWindow::on_strcollButton_clicked()
{
    int a = strcoll(ui->str1LineEditt->text().toUtf8().data(),
                           ui->str2LineEdit->text().toUtf8().data());
    ui->outLabel->setText(a > 0 ? "First is larger" : (a == 0 ? "Equal" : "Second is larger"));
}


void MainWindow::on_strncmpButton_clicked()
{
    int a = strncmp(ui->str1LineEditt->text().toUtf8().data(),
            ui->str2LineEdit->text().toUtf8().data(), ui->nSpinBox->value());
    ui->outLabel->setText(a > 0 ? "First is larger" : (a == 0 ? "Equal" : "Second is larger"));
}


void MainWindow::on_strxfrmButton_clicked()
{
    ui->outLabel->setText((char *)strxfrm(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data(), (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strtokButton_clicked()
{
    ui->outLabel->setText((char *)strtok(ui->str1LineEditt->text().toUtf8().data(),
                        ui->str2LineEdit->text().toUtf8().data()));
}


void MainWindow::on_memsetButton_clicked()
{
    ui->outLabel->setText((char *)memset(ui->str1LineEditt->text().toUtf8().data(),
                    (int)ui->str2LineEdit->text().toUtf8().data()[0], (size_t)ui->nSpinBox->value()));
}


void MainWindow::on_strerrorButton_clicked()
{
    ui->outLabel->setText(strerror(ui->nSpinBox->value()));
}


void MainWindow::on_strlenButton_clicked()
{
    ui->outLabel->setText(QString::number(
        String(ui->str1LineEditt->text().toStdString().c_str()).size()));
}

