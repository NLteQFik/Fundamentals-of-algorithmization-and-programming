#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = nullptr);
    ~MainWindow ();

private slots:
    void on_reloadVectorButton_clicked();

    void on_amountOfElementsSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow  *ui;

    QVector<int> vect;

    int amountOfElementsInArray;

    void printVector();
    void printMedians();

    double findMedian(int);
};
#endif // WIDGET_H
