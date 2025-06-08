#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    info_widget = new InfoWidget(parent);

    ui->label->setStyleSheet(MyStyleSheets::labelStyle);
    ui->atButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->emptyButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->sizeButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->clearButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->popBackButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->popFrontButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->pushBackButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->pushFrontButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->spinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);

    setCentralWidget(ui->gridLayoutWidget);
    setWindowTitle("Deque");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printDeque()
{
    ui->label->clear();
    for (auto el : deque) {
        ui->label->setText(ui->label->text() + " " + QString::number(el));
    }
}

void MainWindow::on_pushBackButton_clicked()
{
    deque.push_back(ui->spinBox->value());
    printDeque();
}

void MainWindow::on_pushFrontButton_clicked()
{
    deque.push_front(ui->spinBox->value());
    printDeque();
}

void MainWindow::on_popBackButton_clicked()
{
    deque.pop_back();
    printDeque();
}

void MainWindow::on_popFrontButton_clicked()
{
    deque.pop_front();
    printDeque();
}

void MainWindow::on_clearButton_clicked()
{
    deque.clear();
    printDeque();
}

void MainWindow::on_sizeButton_clicked()
{
    info_widget->setWindowTitle("Size");
    info_widget->label->setText(QString::number(deque.size()));
    info_widget->show();
}


void MainWindow::on_emptyButton_clicked()
{
    info_widget->setWindowTitle("Empty");
    QString text = deque.empty() ? "Empty" : "Not empty";
    info_widget->label->setText(text);
    info_widget->show();
}


void MainWindow::on_atButton_clicked()
{
    info_widget->setWindowTitle("At" + QString::number(ui->spinBox->value()));
    if (ui->spinBox->value() >= 0 && ui->spinBox->value() < deque.size())
        info_widget->label->setText(QString::number(deque.at(ui->spinBox->value())));
    else
        info_widget->label->setText("Wrong Index");
    info_widget->show();
}

