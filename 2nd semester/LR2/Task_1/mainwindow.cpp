#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    error_box = new QMessageBox();
    error_box->setMinimumSize(400, 400);

    today = Date(QDate::currentDate().toString("dd.MM.yyyy"));

    addTable();

    date_widget = new QWidget();
    date_widget->setWindowTitle("Change date");
    date_widget->setMinimumSize(400, 150);
    QPushButton* confirm_ch = new QPushButton("Confirm");
    day_ch = new QSpinBox();
    day_ch->setMaximum(31);
    day_ch->setMinimum(1);
    month_ch = new QSpinBox();
    month_ch->setMaximum(12);
    month_ch->setMinimum(1);
    year_ch = new QSpinBox();
    year_ch->setMaximum(9999);
    year_ch->setMinimum(1);
    QGridLayout* layout_ch = new QGridLayout(date_widget);
    layout_ch->addWidget(day_ch, 0, 0);
    layout_ch->addWidget(month_ch, 0, 1);
    layout_ch->addWidget(year_ch, 0, 2);
    layout_ch->addWidget(confirm_ch, 1, 0, 1, 3);
    connect(month_ch, SIGNAL(valueChanged(int)), this, SLOT(on_day_possibility(int)));
    connect(year_ch, SIGNAL(valueChanged(int)), this, SLOT(on_day_possibility(int)));
    connect(confirm_ch, &QPushButton::clicked, this, &MainWindow::on_confirm_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    QString opened_file = QFileDialog::getOpenFileName(this, "Select .txt file with dates", QDir::homePath(), "Text files(*.txt)");
    if(!opened_file.isEmpty()) {
        file_name = opened_file;
    }
}

void MainWindow::ReadFromFile()
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        error_box->hide();
        error_box->setText("Can't open file");
        error_box->show();
        return;
    }

    dates.clear();
    int i = 0;
    QString str;
    while (!file.atEnd()) {
        str = file.readLine();
        dates.push_back(Date(str));
        if (dates[i].CheckValidity() == false) {
            error_box->hide();
            error_box->setText("File contain dates in wrong format");
            error_box->show();
            dates.clear();
            return;
        }
        i++;
    }

    file.close();
    updateTable();
}

void MainWindow::AddToFile(Date date)
{
    QFile file(file_name);

    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << date.DateToString() << "\n";
        file.close();
    }
    else {
        error_box->hide();
        error_box->setText("Can't open file");
        error_box->show();
    }
}

void MainWindow::ModifyFile(int row, Date date)
{
    QFile file(file_name);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        error_box->hide();
        error_box->setText("Can't open file");
        error_box->show();
        return;
    }
    QTextStream in(&file);
    for (int i = 1; i < row; ++i)
    {
        in.readLine();
        if (in.atEnd())
        {
            error_box->hide();
            error_box->setText("There is no date with this number");
            error_box->show();
            return;
        }
    }
    qint64 position = in.pos();
    in.seek(position);
    in << date.DateToString() + "\n";
    file.close();
}

void MainWindow::addTable()
{
    ui->datesTable->setRowCount(1);
    ui->datesTable->setColumnCount(9);
    ui->datesTable->verticalHeader()->setVisible(false);
    ui->datesTable->horizontalHeader()->setVisible(false);
    ui->datesTable->setColumnWidth(0, 30);
    ui->datesTable->setColumnWidth(1, 150);
    ui->datesTable->setColumnWidth(2, 150);
    ui->datesTable->setColumnWidth(3, 150);
    ui->datesTable->setColumnWidth(4, 150);
    ui->datesTable->setColumnWidth(5, 150);
    ui->datesTable->setColumnWidth(6, 150);
    ui->datesTable->setColumnWidth(7, 150);
    ui->datesTable->setColumnWidth(8, 150);
    ui->datesTable->setRowHeight(0, 50);
    ui->datesTable->setItem(0, 0, new QTableWidgetItem("No"));
    ui->datesTable->setItem(0, 1, new QTableWidgetItem("Date"));
    ui->datesTable->setItem(0, 2, new QTableWidgetItem("Next Day"));
    ui->datesTable->setItem(0, 3, new QTableWidgetItem("Previous Day"));
    ui->datesTable->setItem(0, 4, new QTableWidgetItem("Leap Year?"));
    ui->datesTable->setItem(0, 5, new QTableWidgetItem("Week number"));
    ui->datesTable->setItem(0, 6, new QTableWidgetItem("Days till birthday"));
    ui->datesTable->setItem(0, 7, new QTableWidgetItem("Duration between dates"));
    ui->datesTable->setItem(0, 8, new QTableWidgetItem("Duration between today"));
    ui->datesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->datesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->datesTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MainWindow::updateTable()
{
    int number = dates.size();
    ui->datesTable->setRowCount(number + 1);
    for (int i = 0; i < number; i++) {
        ui->datesTable->setItem(i + 1, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->datesTable->setItem(i + 1, 1, new QTableWidgetItem(dates[i].DateToString()));
        ui->datesTable->setItem(i + 1, 2, new QTableWidgetItem(dates[i].NextDay().DateToString()));
        ui->datesTable->setItem(i + 1, 3, new QTableWidgetItem(dates[i].PreviousDay().DateToString()));
        ui->datesTable->setItem(i + 1, 4, new QTableWidgetItem(dates[i].IsLeap() ? "Yes" : "No"));
        ui->datesTable->setItem(i + 1, 5, new QTableWidgetItem(QString::number(dates[i].WeekNumber())));
        ui->datesTable->setItem(i + 1, 6, new QTableWidgetItem(QString::number(dates[i].DaysTillYourBithday(birthday))));
        ui->datesTable->setItem(i + 1, 7, new QTableWidgetItem(i != number - 1 ? QString::number(dates[i].Duration(dates[i+1])) : "..."));
        ui->datesTable->setItem(i + 1, 8, new QTableWidgetItem(QString::number(dates[i].Duration(today))));
        //ui->datesTable->setItem(i + 1, 8, new QTableWidgetItem(QString::number(dates[i].DaysFromStart())));
    }
}

void MainWindow::on_day_possibility(int i)
{
    int year = year_ch->value();
    int month = month_ch->value();
    switch (month) {
    case 2:
        if (year % 400 == 0)
            day_ch->setMaximum(29);
        else if (year % 100 == 0)
            day_ch->setMaximum(28);
        else if (year % 4 == 0)
            day_ch->setMaximum(29);
        else
            day_ch->setMaximum(28);
        return;
    case 4:
    case 6:
    case 9:
    case 11:
        day_ch->setMaximum(30);
        return;
    default:
        day_ch->setMaximum(31);
        return;
    }
}

void MainWindow::on_confirm_clicked()
{
    Date new_date = Date(day_ch->value(), month_ch->value(), year_ch->value());
    switch (action){
    case 0:
        birthday = new_date;
        ui->birthdayLabel->setText("Birthday date: " + birthday.DateToString());
        break;
    case 1:
        AddToFile(new_date);
        break;
    case 2:
        ModifyFile(ui->datesTable->currentRow(), new_date);
        break;
    default:
        error_box->hide();
        error_box->setText("Forbiden access");
        error_box->show();
        break;
    }
    date_widget->hide();
    ReadFromFile();
    return;
}

void MainWindow::on_openButton_clicked()
{
    OpenFile();
    if (!file_name.isEmpty())
        ReadFromFile();
    qDebug() << file_name;
}


void MainWindow::on_birthdayButton_clicked()
{
    action = 0;
    date_widget->hide();
    date_widget->show();
}


void MainWindow::on_addButton_clicked()
{
    action = 1;
    date_widget->hide();
    date_widget->show();
}


void MainWindow::on_changeButton_clicked()
{
    if (ui->datesTable->currentRow() <= 0) {
        error_box->hide();
        error_box->setText("No date is chosen");
        error_box->show();
        return;
    }
    action = 2;
    date_widget->hide();
    date_widget->show();
}

void MainWindow::on_openButton_2_clicked()
{
    file_name = "/home/matsvei/Documents/453502/2sem/LR2/Task_1/Dates.txt";
    ReadFromFile();
}

