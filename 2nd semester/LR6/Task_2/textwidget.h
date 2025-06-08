#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QGridLayout>

#include "customtextedit.h"

class TextWidget : public QWidget
{
public:
    TextWidget(QWidget *parent = nullptr);

    CustomTextEdit* text_input;
};

#endif // TEXTWIDGET_H
