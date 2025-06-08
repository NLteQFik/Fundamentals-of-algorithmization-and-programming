#ifndef STRUCTWIDGET_H
#define STRUCTWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>

#include "sportsman.h"

class StructWidget : public QWidget
{
public:
    StructWidget(QWidget *parent = nullptr);

    QLineEdit* age = new QLineEdit();
    QLineEdit* height = new QLineEdit();
    QLineEdit* category = new QLineEdit();
    QLineEdit* professional = new QLineEdit();
    QLineEdit* name = new QLineEdit();
    QLineEdit* result1 = new QLineEdit();
    QLineEdit* result2 = new QLineEdit();
    QLineEdit* result3 = new QLineEdit();
    QPushButton* button = new QPushButton("Confirm");
};

#endif // STRUCTWIDGET_H
