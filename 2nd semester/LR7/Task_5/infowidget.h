#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class InfoWidget : public QWidget
{
public:
    explicit InfoWidget(QWidget *parent = nullptr);
    QLabel* label;

};

#endif // INFOWIDGET_H
