#ifndef LINEWIDGET_H
#define LINEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QIntValidator>

class LineWidget : public QWidget
{
public:
    LineWidget(QWidget *parent = nullptr);

    QLineEdit *text_input;
};

#endif // LINEWIDGET_H
