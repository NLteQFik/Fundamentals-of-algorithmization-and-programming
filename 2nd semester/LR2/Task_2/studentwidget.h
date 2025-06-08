#ifndef STUDENTWIDGET_H
#define STUDENTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class StudentWidget
{
public:
    StudentWidget();

private:
    QWidget* stud_widget;
    QLineEdit* subjects[5];
    QLineEdit* speciality;
    QLineEdit* name;
    QSpinBox* marks[5];
    QSpinBox* group;
signals:
    void confirm_pressed();
};

#endif // STUDENTWIDGET_H
