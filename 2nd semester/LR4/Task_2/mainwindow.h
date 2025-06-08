#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "heapsorter.h"
#include "qsorter.h"
#include "mergesorter.h"
#include "interpolationsorter.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fillButton_clicked();

    void on_sortButton_clicked();

    void on_findButton_clicked();
    void on_amountOfElementsSpinBox_valueChanged(int arg1);

protected:
    void showEvent(QShowEvent* event) override;
private:
    Ui::MainWindow *ui;

    QVector<int> vectForTime;
    QVector<int> vectForAniamtion;

    QTimer *animationTimer;
    QVector<QVector<int>> listOfStates;

    QGraphicsScene* scene;

    int amountOfElementsInArray;

    void drawArr();
    int currState;
    bool isSorted;

    QVector<QGraphicsRectItem*> rects;
    QVector<int> listOfSearch;

    int binarySearch(int, int, int);
    QTimer *searchAnimationTimer;
    int currStepOfSearch;
    void drawSearch();
    bool isElement;

    long long binpow(long long, long long, long long);
};
#endif // MAINWINDOW_H
