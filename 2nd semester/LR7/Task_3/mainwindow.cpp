#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->pushButton_2->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->pushButton_3->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->pushButton_4->setStyleSheet(MyStyleSheets::greenButtonStyle);

    ui->tableWidget->setStyleSheet(MyStyleSheets::tableWidgetStyle);
    ui->tableWidget->horizontalHeader()->setStyleSheet(MyStyleSheets::headerStyle);
    ui->tableWidget->verticalHeader()->setStyleSheet(MyStyleSheets::headerStyle);

    ui->label->setStyleSheet(MyStyleSheets::labelStyle);
    ui->label_2->setStyleSheet(MyStyleSheets::labelStyle);

    ui->spinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->spinBox_2->setStyleSheet(MyStyleSheets::spinBoxStyle);

    ui->tableWidget->horizontalHeader()->setVisible(false);

    createTable();

    setCentralWidget(ui->gridLayoutWidget);

    setWindowTitle("Hash Table");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    table.Insert(ui->spinBox->value(), ui->spinBox_2->value());
    showTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    table.Remove(ui->spinBox->value());
    showTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    table.DeleteEvenKeys();
    showTable();
}

void MainWindow::showTable()
{
    ui->tableWidget->clear();

    QVector<QVector<int>> res = table.DisplayHashTable();

    ui->tableWidget->setRowCount(res.size());
    for (int i = 0; i < res.size(); ++i)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());

    for (int i = 0; i < res.size(); ++i)
        for (auto el : res[i])
            ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i, 0)->text() + " " + QString::number(el));
}

void MainWindow::createTable()
{
    table = HashSolver(size);

    for (int i = 0; i < size; ++i) {
        table.Insert(QRandomGenerator::global()->bounded(1e9), QRandomGenerator::global()->bounded(1e9));
    }

    qDebug() << "fsfs" << size;

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    showTable();
}


void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "dfsdf";
    size = ui->spinBox_2->value();
    createTable();
}

