#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    table_size = 100;
    table_occupancy = 50;
    tests_number = 1000;

    ui->sizeSpinBox->setValue(table_size);
    ui->occupancySpinBox->setValue(table_occupancy);
    ui->testsSpinBox->setValue(tests_number);

    ui->LinearLabel->setStyleSheet(MyStyleSheets::labelStyle);
    ui->QuadraticLabel->setStyleSheet(MyStyleSheets::labelStyle);
    ui->DoubleLabel->setStyleSheet(MyStyleSheets::labelStyle);

    ui->LinearLabel_2->setStyleSheet(MyStyleSheets::lightLabelStyle);
    ui->QuadraticLabel_2->setStyleSheet(MyStyleSheets::lightLabelStyle);
    ui->DoubleLabel_2->setStyleSheet(MyStyleSheets::lightLabelStyle);

    ui->occupancyLable->setStyleSheet(MyStyleSheets::labelStyle);
    ui->sizeLable->setStyleSheet(MyStyleSheets::labelStyle);
    ui->testsLabel->setStyleSheet(MyStyleSheets::labelStyle);

    ui->sizeSpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->occupancySpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->testsSpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);

    ui->pushButton_2->setStyleSheet(MyStyleSheets::redButtonStyle);

    setWindowTitle("Hash tables comparison");

    setCentralWidget(ui->gridLayoutWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TestHashTable(HashTable *table)
{
    for (int i = 0; i < tests_number; ++i) {
        table->Find(QRandomGenerator::global()->bounded(1, table_size));
    }
}

void MainWindow::FillTables()
{
    linear_table =  new LinearHashTable(table_size);
    quadratic_table = new QuadraticHashTable(table_size);
    double_table = new DoubleHashTable(table_size);

    for (int i = 0; i < table_occupancy; ++i) {
        linear_table->Insert(QRandomGenerator::global()->bounded(1, table_size), QRandomGenerator::global()->bounded(1, table_size));
        quadratic_table->Insert(QRandomGenerator::global()->bounded(1, table_size), QRandomGenerator::global()->bounded(1, table_size));
        double_table->Insert(QRandomGenerator::global()->bounded(1, table_size), QRandomGenerator::global()->bounded(1, table_size));
    }
}

void MainWindow::BuildGraphics()
{
    QElapsedTimer timer;

    double linear_result = 0;
    timer.start();
    TestHashTable(linear_table);
    linear_result = timer.nsecsElapsed();

    double quadratic_result = 0;
    timer.start();
    TestHashTable(quadratic_table);
    quadratic_result = timer.nsecsElapsed();

    double double_result = 0;
    timer.start();
    TestHashTable(double_table);
    double_result = timer.nsecsElapsed();

    ui->LinearLabel_2->setText(QString::number(linear_result / tests_number / 1e5 / 2) + " ms");
    ui->QuadraticLabel_2->setText(QString::number(quadratic_result / tests_number / 1e5 / 2) + " ms");
    ui->DoubleLabel_2->setText(QString::number(double_result / tests_number / 1e5 / 2) + " ms");

    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(0, -480, 805, 480, view);
    view->setScene(scene);

    double res = std::max(std::max(linear_result, quadratic_result), double_result);

    linear_result /= res / 480.0;
    quadratic_result /= res / 480.0;
    double_result /= res / 480.0;

    qDebug() << linear_result << quadratic_result << double_result;

    QGraphicsRectItem *linear_rect = new QGraphicsRectItem(66, -linear_result, 132, linear_result);
    QGraphicsRectItem *quadratic_rect = new QGraphicsRectItem(330, -quadratic_result, 132, quadratic_result);
    QGraphicsRectItem *double_rect = new QGraphicsRectItem(594, -double_result, 132, double_result);

    linear_rect->setBrush(QBrush("#00BC00"));
    linear_rect->setPen(QPen(QColor("#00DD00"), 3));

    quadratic_rect->setBrush(QBrush("#BC0000"));
    quadratic_rect->setPen(QPen(QColor("#DD0000"), 3));

    double_rect->setBrush(QBrush("#0000BC"));
    double_rect->setPen(QPen(QColor("#0000DD"), 3));

    scene->addItem(linear_rect);
    scene->addItem(quadratic_rect);
    scene->addItem(double_rect);
}


void MainWindow::on_pushButton_2_clicked()
{
    FillTables();
    BuildGraphics();
}


void MainWindow::on_sizeSpinBox_valueChanged(int arg1)
{
    table_size = arg1;
    ui->occupancySpinBox->setMaximum(arg1);
}


void MainWindow::on_occupancySpinBox_valueChanged(int arg1)
{
    table_occupancy = arg1;
}


void MainWindow::on_testsSpinBox_valueChanged(int arg1)
{
    tests_number = arg1;
}

