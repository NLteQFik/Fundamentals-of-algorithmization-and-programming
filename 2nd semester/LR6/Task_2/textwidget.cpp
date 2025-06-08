#include "textwidget.h"

TextWidget::TextWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Write a text");
    this->setFixedSize(500, 200);
    this->setStyleSheet("background-color: rgba(0, 51, 102, 150); "
                        "color: lightblue; "
                        "font: bold 12pt 'URW Bookman'; "
                        "padding: 5px; "
                        "border: 1px solid #003366; "
                        );

    text_input = new CustomTextEdit();
    //text_input->setGeometry(0, 0, 490, 190);
    //text_input->setFixedSize(490, 190);
    text_input->setStyleSheet("background-color: rgba(30, 30, 60, 150); "
                              "color: #CCCCCC; "
                              "font: bold 12pt 'Consolas'; "
                              "border: 2px solid #003366; "
                              "padding: 6px; "
                              "border-radius: 4px; "
                              );
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(text_input);
    layout->setGeometry(QRect(0, 0, 490, 190));
}
