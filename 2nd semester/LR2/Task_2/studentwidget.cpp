#include "studentwidget.h"

StudentWidget::StudentWidget()
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
    //emit confirm_pressed();
    //connect(confirm, &QPushButton::clicked, this, &MainWindow::on_confirm_clicked);
}
