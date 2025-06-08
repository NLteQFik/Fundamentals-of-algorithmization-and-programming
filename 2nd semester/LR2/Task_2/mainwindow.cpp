#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitStudWidget();
    InitSortWidget();

    DisableFunction();

    error_box = new QMessageBox();
    error_box->setMinimumSize(400, 400);

    AddTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTable()
{
    ui->studentsTable->setRowCount(1);
    ui->studentsTable->setColumnCount(15);
    ui->studentsTable->verticalHeader()->setVisible(false);
    ui->studentsTable->horizontalHeader()->setVisible(false);
    ui->studentsTable->setRowHeight(0, 50);
    ui->studentsTable->setColumnWidth(0, 30);
    ui->studentsTable->setColumnWidth(1, 150);
    ui->studentsTable->setColumnWidth(2, 150);
    ui->studentsTable->setColumnWidth(3, 150);
    ui->studentsTable->setItem(0, 0, new QTableWidgetItem("No"));
    ui->studentsTable->setItem(0, 1, new QTableWidgetItem("Speciality"));
    ui->studentsTable->setItem(0, 2, new QTableWidgetItem("Group"));
    ui->studentsTable->setItem(0, 3, new QTableWidgetItem("Name"));
    for (int i = 0; i < 5; i++) {
        ui->studentsTable->setColumnWidth(4 + 2 * i, 150);
        ui->studentsTable->setColumnWidth(5 + 2 * i, 50);
        ui->studentsTable->setItem(0, 4 + 2 * i, new QTableWidgetItem("Subject"));
        ui->studentsTable->setItem(0, 5 + 2 * i, new QTableWidgetItem("Mark"));
    }
    ui->studentsTable->setColumnWidth(14, 70);
    ui->studentsTable->setItem(0, 14, new QTableWidgetItem("Average mark"));
    ui->studentsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->studentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->studentsTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MainWindow::UpdateTable()
{
    int number = students.size();
    ui->studentsTable->setRowCount(number + 1);
    for (int i = 0; i < number; i++) {
        ui->studentsTable->setRowHidden(i + 1, 0);
        ui->studentsTable->setItem(i + 1, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->studentsTable->setItem(i + 1, 1, new QTableWidgetItem(students[i].GetSpeciality()));
        ui->studentsTable->setItem(i + 1, 2, new QTableWidgetItem(QString::number(students[i].GetGroup())));
        ui->studentsTable->setItem(i + 1, 3, new QTableWidgetItem(students[i].GetName()));
        for (int j = 0; j < 5; j++) {
            ui->studentsTable->setItem(i + 1, 4 + 2 * j, new QTableWidgetItem(students[i].GetSubjects()[j]));
            ui->studentsTable->setItem(i + 1, 5 + 2 * j, new QTableWidgetItem(QString::number(students[i].GetMarks()[j])));
        }
        ui->studentsTable->setItem(i + 1, 14, new QTableWidgetItem(QString::number(students[i].GetAverageMark())));
    }
}

void MainWindow::SortAll()
{
    std::sort(students.begin(), students.end(), [](Student a, Student b) {return a.GetAverageMark() > b.GetAverageMark();});
    UpdateTable();
}

void MainWindow::SortGroup()
{
    int i = 0;
    while (i != students.size()) {
        if (students[i].GetGroup() != sr_group->value()) {
            students.remove(i);
        }
        else {
            i++;
        }
    }
    SortAll();
}

void MainWindow::ShowPosit()
{
    int i = 0;
    bool check = true;
    while (i != students.size()) {
        for (int j = 0; j < 5; j++) {
            check = check && students[i].GetMarks()[j] >= 4;
        }
        if (!check) {
            students.remove(i);
        }
        else {
            i++;
        }
        check = true;
    }
    UpdateTable();
}

void MainWindow::ShowPersons()
{
    for (int i = 0; i < students.size(); i++) {
        if (students[i].GetName() != sr_name->displayText()) {
            ui->studentsTable->setRowHidden(i + 1, 1);
        }
    }
}

void MainWindow::InitStudWidget()
{
    stud_widget = new QWidget();
    stud_widget->setWindowTitle("Edit student");
    stud_widget->setMinimumSize(400, 150);
    QPushButton* confirm = new QPushButton("Confirm");

    speciality = new QLineEdit();
    name = new QLineEdit();
    group = new QSpinBox();
    group->setMinimum(100000);
    group->setMaximum(999999);
    for (int i = 0; i < 5; i++) {
        subjects[i] = new QLineEdit();
        marks[i] = new QSpinBox();
        marks[i]->setMinimum(0);
        marks[i]->setMaximum(10);
    }
    QLabel* sp_l = new QLabel();
    QLabel* gr_l = new QLabel();
    QLabel* nm_l = new QLabel();
    QLabel* sb_l = new QLabel();
    QLabel* mr_l = new QLabel();
    sp_l->setText("Speciality");
    gr_l->setText("Group");
    nm_l->setText("Name");
    sb_l->setText("Subject");
    mr_l->setText("Mark");

    QGridLayout* layout = new QGridLayout(stud_widget);
    layout->addWidget(sp_l, 0, 0, 1, 5);
    layout->addWidget(speciality, 1, 0, 1, 5);
    layout->addWidget(gr_l, 2, 0, 1, 5);
    layout->addWidget(group, 3, 0, 1, 5);
    layout->addWidget(nm_l, 4, 0, 1, 5);
    layout->addWidget(name, 5, 0, 1, 5);
    layout->addWidget(sb_l, 6, 0, 1, 4);
    layout->addWidget(mr_l, 6, 4);
    for (int i = 0; i < 5; i++) {
        layout->addWidget(subjects[i], i + 7, 0, 1, 4);
        layout->addWidget(marks[i], i + 7, 4);
    }
    layout->addWidget(confirm, 12, 0, 1, 5);
    connect(confirm, &QPushButton::clicked, this, &MainWindow::on_confirm_clicked);
}

void MainWindow::InitSortWidget()
{
    sort_widget = new QWidget();
    sort_widget->setWindowTitle("Choose action");
    sort_widget->setMinimumSize(400, 150);
    QPushButton* confirm = new QPushButton("Confirm");

    sort_all = new QRadioButton();
    sort_group = new QRadioButton();
    give_positive = new QRadioButton();
    find_stud = new QRadioButton();
    sort_all->setText("Sort all students in decreasion order");
    sort_group->setText("Sort students from group in decreasion order");
    give_positive->setText("Show students with positive marks");
    find_stud->setText("Find student");

    sr_group = new QSpinBox();
    sr_group->setMinimum(100000);
    sr_group->setMaximum(999999);

    sr_name = new QLineEdit();

    QGridLayout* layout = new QGridLayout(sort_widget);
    layout->addWidget(sort_all, 0, 0, 1, 5);
    layout->addWidget(sort_group, 1, 0, 1, 4);
    layout->addWidget(sr_group, 1, 4);
    layout->addWidget(give_positive, 2, 0, 1, 5);
    layout->addWidget(find_stud, 3, 0, 1, 2);
    layout->addWidget(sr_name, 3, 2, 1, 4);
    layout->addWidget(confirm, 4, 0, 1, 5);
    connect(confirm, &QPushButton::clicked, this, &MainWindow::on_confirm_2_clicked);
}

void MainWindow::DisableFunction()
{
    ui->addButton->setDisabled(true);
    ui->correctButton->setDisabled(true);
    ui->deleteButton->setDisabled(true);
    ui->sortButton->setDisabled(true);
    ui->saveButton->setDisabled(true);
}

void MainWindow::EnableFunction()
{
    ui->addButton->setEnabled(true);
    ui->correctButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->sortButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_confirm_clicked()
{
    int marks_n[5];
    QString subjects_n[5];
    for (int i = 0; i < 5; i++) {
        marks_n[i] = marks[i]->value();
        subjects_n[i] = subjects[i]->displayText();
    }
    Student student = Student(speciality->displayText(), group->value(), name->displayText(), subjects_n, marks_n);
    action = student.CheckValidity() ? action : 0;
    switch (action) {
    case 1:
        if (row == students.size()) {
            students.append(student);
            break;
        }
        students.insert(row, student);
        break;
    case 2:
        students.replace(row, student);
        break;
    default:
        error_box->hide();
        error_box->setText("Wrong input");
        error_box->show();
        break;
    }
    stud_widget->hide();
    UpdateTable();
}

void MainWindow::on_confirm_2_clicked()
{
    if (sort_all->isChecked()) {
        SortAll();
        DisableFunction();
    }
    if (sort_group->isChecked()) {
        SortGroup();
        DisableFunction();
    }
    if (give_positive->isChecked()) {
        ShowPosit();
        DisableFunction();
    }
    if (find_stud->isChecked()) {
        ShowPersons();
    }
    sort_widget->hide();
}

void MainWindow::on_findButton_clicked()
{
    file.FindFile(this);
    DisableFunction();
}


void MainWindow::on_loadButton_clicked()
{
    int result = file.ReadFromFile(students);
    switch (result) {
    case 1:
        error_box->hide();
        error_box->setText("Can't open file");
        error_box->show();
        students.clear();
        return;
    case 2:
        error_box->hide();
        error_box->setText("File contain list of students in wrong format");
        error_box->show();
        students.clear();
        return;
    }
    UpdateTable();
    EnableFunction();
}


void MainWindow::on_saveButton_clicked()
{
    int result = file.SaveToFile(students);
    switch (result) {
    case 1:
        error_box->hide();
        error_box->setText("Can't open file");
        error_box->show();
        students.clear();
        return;
    }
}


void MainWindow::on_addButton_clicked()
{
    if (ui->studentsTable->currentRow() < 0) {
        error_box->hide();
        error_box->setText("No place is chosen");
        error_box->show();
        return;
    }
    action = 1;
    row = ui->studentsTable->currentRow();
    stud_widget->hide();

    speciality->setText("");
    group->setValue(100000);
    name->setText("");
    for (int i = 0; i < 5; i++) {
        subjects[i]->setText("");
        marks[i]->setValue(0);
    }

    stud_widget->show();
}


void MainWindow::on_correctButton_clicked()
{
    if (ui->studentsTable->currentRow() <= 0) {
        error_box->hide();
        error_box->setText("No student is chosen");
        error_box->show();
        return;
    }
    action = 2;
    row = ui->studentsTable->currentRow() - 1;
    stud_widget->hide();

    speciality->setText(students[row].GetSpeciality());
    group->setValue(students[row].GetGroup());
    name->setText(students[row].GetName());
    for (int i = 0; i < 5; i++) {
        subjects[i]->setText(students[row].GetSubjects()[i]);
        marks[i]->setValue(students[row].GetMarks()[i]);
    }

    stud_widget->show();
}


void MainWindow::on_deleteButton_clicked()
{
    if (ui->studentsTable->currentRow() <= 0) {
        error_box->hide();
        error_box->setText("No student is chosen");
        error_box->show();
        return;
    }
    students.remove(ui->studentsTable->currentRow() - 1);
    UpdateTable();
    stud_widget->hide();
}


void MainWindow::on_sortButton_clicked()
{
    sort_widget->show();
}

