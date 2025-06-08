#include "myview.h"
#include "ui_myview.h"

MyView::MyView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyView)
{
    ui->setupUi(this);

    scene = new MyGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(-ui->graphicsView->width() / 2,
                                   -ui->graphicsView->height() / 2,
                                   ui->graphicsView->width(),
                                   ui->graphicsView->height());

    graph = new Graph();
    pot_source = nullptr;

}

MyView::~MyView()
{
    delete graph;
    delete scene;
    delete ui;
}
