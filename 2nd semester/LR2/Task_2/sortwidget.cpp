#include "sortwidget.h"

SortWidget::SortWidget()
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
}
