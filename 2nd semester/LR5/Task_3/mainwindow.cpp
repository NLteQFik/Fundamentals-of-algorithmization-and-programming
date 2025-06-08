#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 100; ++i)
        if (QRandomGenerator::global()->bounded(2) - 1 == 0)
            bitset.set(i);


    ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                        QString::fromUtf8(bitset.to_string().c_str()).right(50));

    connect(ui->setBtn, &QPushButton::clicked, [&]() {
        bitset.set(ui->spinBox->value());
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });

    connect(ui->flipBtn, &QPushButton::clicked, [&]() {
        bitset.flip(ui->spinBox->value());
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });

    connect(ui->resetBtn, &QPushButton::clicked, [&]() {
        bitset.reset(ui->spinBox->value());
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });

    connect(ui->setAllBtn, &QPushButton::clicked, [&]() {
        bitset.set();
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });

    connect(ui->flipAllBtn, &QPushButton::clicked, [&]() {
        bitset.flip();
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });

    connect(ui->resetAllBtn, &QPushButton::clicked, [&]() {
        bitset.reset();
        ui->labell->setText(QString::fromUtf8(bitset.to_string().c_str()).left(50) + "\n" +
                            QString::fromUtf8(bitset.to_string().c_str()).right(50));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
