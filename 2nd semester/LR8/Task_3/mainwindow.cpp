#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; ++i) {
        //set.Insert(QRandomGenerator::global()->bounded(100));
        map.Insert(QRandomGenerator::global()->bounded(100), QRandomGenerator::global()->bounded(100));
        //map.Insert(i + 1, QRandomGenerator::global()->bounded(100));
    }
    set.Insert(1);

    ui->mapTable->horizontalHeader()->setStretchLastSection(true);

    displayMap();
    displaySet();

    ui->tabWidget->setStyleSheet(MyStyleSheets::tableWidgetStyle);
    ui->mapAtButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->mapInsertButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->mapClearButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->mapRemoveButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->mapContainsButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->mapResLabel->setStyleSheet(MyStyleSheets::lightLabelStyle);
    ui->label->setStyleSheet(MyStyleSheets::labelStyle);
    ui->label_2->setStyleSheet(MyStyleSheets::labelStyle);
    ui->keySpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->valSpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);

    ui->label_3->setStyleSheet(MyStyleSheets::labelStyle);
    ui->label_4->setStyleSheet(MyStyleSheets::labelStyle);
    ui->setResLabel->setStyleSheet(MyStyleSheets::lightLabelStyle);
    ui->setLabel->setStyleSheet(MyStyleSheets::lightLabelStyle);
    ui->setValSpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->setInsertButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->setClearButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->setRemoveButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->setContainsButton->setStyleSheet(MyStyleSheets::blueButtonStyle);


    setFixedSize(size());

    setWindowTitle("Map & Set");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMap()
{
    ui->mapTable->clear();
    ui->mapTable->setRowCount(map.Size());
    int i = 0;
    for (auto& el : map) {
        ui->mapTable->setItem(i, 0, new QTableWidgetItem(QString::number(el.key)));
        ui->mapTable->setItem(i, 1, new QTableWidgetItem(QString::number(el.value)));
        i++;
    }
}

void MainWindow::displaySet()
{
    QString text = "";
    for (auto& el : set) {
        text += QString::number(el.key) + " ";
    }
    ui->setLabel->setText(text);
}

void MainWindow::on_mapInsertButton_clicked()
{
    map.Insert(ui->keySpinBox->value(), ui->valSpinBox->value());
    displayMap();
}

void MainWindow::on_mapRemoveButton_clicked()
{
    map.Erase(ui->keySpinBox->value());

    displayMap();
}

void MainWindow::on_mapContainsButton_clicked()
{
    ui->mapResLabel->setText(map.Contains(ui->keySpinBox->value()) ? "YES" : "NO");
}


void MainWindow::on_mapClearButton_clicked()
{
    map.Clear();
    displayMap();
}


void MainWindow::on_setInsertButton_clicked()
{
    set.Insert(ui->setValSpinBox->value());

    displaySet();
}


void MainWindow::on_setRemoveButton_clicked()
{
    set.Erase(ui->setValSpinBox->value());
    displaySet();
}


void MainWindow::on_setContainsButton_clicked()
{
    ui->setResLabel->setText(set.Contains(ui->setValSpinBox->value()) ? "YES" : "NO");
}


void MainWindow::on_setClearButton_clicked()
{
    set.Clear();
    displaySet();
}


void MainWindow::on_mapAtButton_clicked()
{
    if (map.Find(ui->keySpinBox->value()))
        ui->mapResLabel->setText(map.Find(ui->keySpinBox->value()) ? QString::number(map.Find(ui->keySpinBox->value())->value) : "NO");
}

