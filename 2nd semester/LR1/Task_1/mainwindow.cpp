#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    cart = new Cart();
    scene->addItem(cart);

    timer_l = new QTimer(this);
    timer_l->setInterval(50);
    connect(ui->LButton, SIGNAL(pressed()), timer_l, SLOT(start()));
    connect(ui->LButton, SIGNAL(released()), timer_l, SLOT(stop()));
    connect(timer_l, SIGNAL(timeout()), cart, SLOT(accelerateLeft()));

    timer_r = new QTimer(this);
    timer_r->setInterval(50);
    connect(ui->RButton, SIGNAL(pressed()), timer_r, SLOT(start()));
    connect(ui->RButton, SIGNAL(released()), timer_r, SLOT(stop()));
    connect(timer_r, SIGNAL(timeout()), cart, SLOT(accelerateRight()));

    timer_decr = new QTimer(this);
    timer_decr->setInterval(100);
    connect(timer_decr, SIGNAL(timeout()), cart, SLOT(decreaseAccel()));
    timer_decr->start();

    timer = new QTimer(this);
    timer->setInterval(1);
    connect(timer, SIGNAL(timeout()), cart, SLOT(move()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
