#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QRadioButton>

class SortWidget
{
public:
    SortWidget();

private:
    QWidget* sort_widget;
    QSpinBox* sr_group;
    QLineEdit* sr_name;
    QRadioButton* sort_all;
    QRadioButton* sort_group;
    QRadioButton* give_positive;
    QRadioButton* find_stud;
};

#endif // SORTWIDGET_H
