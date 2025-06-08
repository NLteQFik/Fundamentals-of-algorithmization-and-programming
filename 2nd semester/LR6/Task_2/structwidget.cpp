#include "structwidget.h"

StructWidget::StructWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Create structure");
    this->setFixedSize(500, 400);
    this->setStyleSheet("background-color: rgba(0, 51, 102, 150); "
                        "color: lightblue; "
                        "font: bold 12pt 'URW Bookman'; "
                        "padding: 5px; "
                        "border: 1px solid #003366; "
                        );
    age->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    height->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    category->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    professional->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    name->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    result1->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    result2->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    result3->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    button->setStyleSheet("background-color: rgba(50, 0, 50, 150); "
                          "color: lime; "
                          "font: bold 12pt 'Source Code Pro'; "
                          "padding: 5px; "
                          "border: 1px solid #330033; "
                          );


    age->setValidator(new QIntValidator(0, 100));
    height->setValidator(new QDoubleValidator(100, 300, 1));
    category->setMaxLength(1);
    professional->setValidator(new QIntValidator(0, 1));
    name->setMaxLength(20);
    result1->setValidator(new QDoubleValidator(0, 100, 2));
    result2->setValidator(new QDoubleValidator(0, 100, 2));
    result3->setValidator(new QDoubleValidator(0, 100, 2));
    QFormLayout* formLayout = new QFormLayout(this);

    formLayout->addRow(new QLabel("Age: "), age);
    formLayout->addRow(new QLabel("Height: "), height);
    formLayout->addRow(new QLabel("Category: "), category);
    formLayout->addRow(new QLabel("Professional: "), professional);
    formLayout->addRow(new QLabel("Name: "), name);
    formLayout->addRow(new QLabel("Results: "), result1);
    formLayout->addRow(new QLabel(""), result2);
    formLayout->addRow(new QLabel(""), result3);
    formLayout->addRow(button);
}
