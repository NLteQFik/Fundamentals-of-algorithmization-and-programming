#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QString>

#include "mygraphicsitem.h"
#include "mygraphicsscene.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "romb.h"
#include "star.h"
#include "hexagon.h"
#include "square.h"
#include "ellipse.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void updateScene();

    // void getAr(qreal ar);
    // qreal getPer();
    // QPointF getOld(QPointF old);
    // QPointF getCur(QPointF cur);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addItemToScene(int index);
    void updateArea();
    void updatePerimeter();
    // void setVal1();
    // int giveVal1();
    // void setVal2();
    // int giveVal2();
    // void setVal3();
    // int giveVal3();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_comboBox_activated(int index);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    MyGraphicsScene* scene;
    MyGraphicsItem* item;
    //Shape* shape;
    int item_mode = -1;
    int item_index = 0;
    int value1 = 10, value2 = 20, value3 = 5;
};
#endif // MAINWINDOW_H
