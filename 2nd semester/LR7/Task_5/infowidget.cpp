#include "infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) : QWidget{parent}
{
    this->setWindowTitle("Write a text");
    this->setFixedSize(150, 60);
    this->setStyleSheet("background-color: rgba(0, 51, 102, 150); "
                        "color: lightblue; "
                        "font: bold 12pt 'URW Bookman'; "
                        "padding: 5px; "
                        "border: 1px solid #003366; "
                        );

    label = new QLabel();
    label->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(label);
    layout->setGeometry(QRect(0, 0, 140, 50));
}
