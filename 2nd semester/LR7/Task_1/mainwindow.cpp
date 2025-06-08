#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Methods");
    ui->tabWidget->setTabText(1, "Problem solution");

    msgBox = new QMessageBox(parent);
    msgBox->setFixedSize(100, 50);

    msgBox->setStyleSheet("QMessageBox {"
                         "background-color: #666666;"
                         "color: white;"
                         "border: 2px solid #888888;"
                         "border-radius: 6px;"
                         "font-size: 16px;"
                         "}"
                         "QMessageBox QLabel {"
                         "color: white;"
                         "}"
                         "QMessageBox QPushButton {"
                         "background-color: #3498db;"
                         "color: white;"
                         "border-radius: 4px;"
                         "padding: 5px 10px;"
                         "font-size: 14px;"
                         "font-weight: bold;"
                         "}"
                         "QMessageBox QPushButton:hover {"
                         "background-color: #2980b9;"
                         "}"
                         "QMessageBox QPushButton:pressed {"
                         "background-color: #1f618d;"
                         "}");

    QString redButtonStyle = "QPushButton {"
                            "background-color: #8B0000;"
                            "color: white;"
                            "border-radius: 4px;"
                            "padding: 4px 8px;"
                            "font-size: 14px;"
                            "font-weight: bold;"
                            "border: 2px solid #600000;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: #600000;"
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #400000;"
                            "}"
                            "QPushButton:disabled {"
                            "background-color: #101010;"
                            "color: #111111;"
                            "}";
    QString greenButtonStyle = "QPushButton {"
                            "background-color: #006400;"
                            "color: white;"
                            "border-radius: 4px;"
                            "padding: 4px 8px;"
                            "font-size: 14px;"
                            "font-weight: bold;"
                            "border: 2px solid #004d00;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: #004d00;"
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #002000;"
                            "}";
    QString blueButtonStyle = "QPushButton {"
                            "background-color: #00008B;"
                            "color: white;"
                            "border-radius: 4px;"
                            "padding: 4px 8px;"
                            "font-size: 14px;"
                            "font-weight: bold;"
                            "border: 2px solid #000060;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: #000060;"
                            "}"
                            "QPushButton:pressed {"
                            "background-color: #000040;"
                            "}"
                            "QPushButton:disabled {"
                            "background-color: #101010;"
                            "color: #111111;"
                            "}";

    ui->tabWidget->setStyleSheet("background-color: rgba(152, 152, 152, 220);" "color: white;" "font-weight: bold; ");

    ui->pushButton->setStyleSheet(blueButtonStyle);
    ui->popButton->setStyleSheet(blueButtonStyle);
    ui->sizeButton->setStyleSheet(greenButtonStyle);
    ui->emptyButton->setStyleSheet(greenButtonStyle);
    ui->frontButton->setStyleSheet(redButtonStyle);
    ui->backButton->setStyleSheet(redButtonStyle);
    ui->insertedElComboBox->setStyleSheet("QSpinBox {"
                                          "background-color: #555555; "
                                          "color: white; "
                                          "font-weight: bold; "
                                          "border-radius: 4px; "
                                          "padding: 5px; "
                                          "font-size: 14px; "
                                          "border: 2px solid #666666;"
                                          "}"
                                          "QSpinBox::up-button {"
                                          "background-color: #666666; "
                                          "border-radius: 2px;"
                                          "}"
                                          "QSpinBox::down-button {"
                                          "background-color: #666666; "
                                          "border-radius: 2px;"
                                          "}");
    ui->label->setStyleSheet("color: white; font-size: 14px; font-weight: bold; padding: 5px;");

    ui->insertButton->setStyleSheet(blueButtonStyle);
    ui->fillButton->setStyleSheet(blueButtonStyle);
    ui->insertButton->setDisabled(true);
    ui->popButton->setDisabled(true);
    ui->frontButton->setDisabled(true);
    ui->backButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->popButton->setDisabled(false);
    ui->frontButton->setDisabled(false);
    ui->backButton->setDisabled(false);
    queue.push(ui->insertedElComboBox->value());
    showQueue(ui->demoMethodsList, queue);
}


void MainWindow::on_popButton_clicked()
{
    queue.pop();
    if (queue.size() == 0) {
        ui->popButton->setDisabled(true);
        ui->frontButton->setDisabled(false);
        ui->backButton->setDisabled(false);
    }
    showQueue(ui->demoMethodsList, queue);
}

void MainWindow::on_fillButton_clicked()
{
    ui->insertButton->setDisabled(false);
    while (!queue1.empty()){
        queue1.pop();
    }
    while (!queue2.empty()){
        queue2.pop();
    }

    for (int i = 0; i < 20; ++i) {
        queue1.push(QRandomGenerator64::global()->bounded(100));
    }
    for (int i = 0; i < 20; ++i) {
        queue2.push(QRandomGenerator64::global()->bounded(100));
    }

    showQueue(ui->queue1Widget, queue1);
    showQueue(ui->queue2Widget, queue2);
}


void MainWindow::on_insertButton_clicked()
{
    int max = queue1.front();
    for (int i = 0; i < queue1.size(); i++){
        int el = queue1.front();
        queue1.pop();
        queue1.push(el);
        if (el > max) max = el;
    }

    bool b = 1;
    int old_sz = queue1.size();
    for (int i = 0; i < old_sz; i++){
        int el = queue1.front();
        queue1.pop();
        queue1.push(el);
        if (el == max && b)
        {
            for (int i = 0; i < queue2.size(); i++){
                int el = queue2.front();
                queue2.pop();
                queue2.push(el);
                queue1.push(el);
            }
            b = 0;
        }
    }

    showQueue(ui->queue1Widget, queue1);
    showQueue(ui->queue2Widget, queue2);

    ui->insertButton->setDisabled(true);
}

void MainWindow::showQueue(QListWidget* showingWidget, Queue<int>& showed)
{
    showingWidget->clear();
    for (int i = 0; i < showed.size(); i++)
    {
        int el = showed.front();
        showed.pop();
        showed.push(el);
        showingWidget->addItem(QString::number(el));
    }
}

void MainWindow::on_sizeButton_clicked()
{
    msgBox->setWindowTitle("Size");
    msgBox->setText(QString::number(queue.size()));
    msgBox->exec();
}

void MainWindow::on_emptyButton_clicked()
{
    msgBox->setWindowTitle("Is empty?");
    QString str = queue.empty() ? "True" : "False";
    msgBox->setText(str);
    msgBox->exec();
}

void MainWindow::on_frontButton_clicked()
{
    if (queue.empty())
        return;
    msgBox->setWindowTitle("Front");
    msgBox->setText(QString::number(queue.front()));
    msgBox->exec();
}

void MainWindow::on_backButton_clicked()
{
    if (queue.empty())
        return;
    msgBox->setWindowTitle("Back");
    msgBox->setText(QString::number(queue.back()));
    msgBox->exec();
}
