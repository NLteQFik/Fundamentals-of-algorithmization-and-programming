#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateScene()
{
    if (scene->getActive() == true)
    {
        switch (item_mode) {
        case 0:
            MainWindow::addItemToScene(item_index);
            break;
        case 2:
            scene->removeItem(scene->getSelectedItem());
            break;
        }
        scene->setActive(false);
    }
    scene->update();
    updateArea();
    updatePerimeter();
    //qDebug() << (scene->mouseGrabberItem() == nullptr);
}

// void MainWindow::getAr(qreal ar)
// {
//     //return ar;
// }

// qreal MainWindow::getPer()
// {
//     return 1;
// }

// QPointF MainWindow::getOld(QPointF old)
// {
//     return old;
// }

// QPointF MainWindow::getCur(QPointF cur)
// {
//     return cur;
// }

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(-ui->graphicsView->width() / 2, -ui->graphicsView->height() / 2, ui->graphicsView->width(), ui->graphicsView->height());

    ui->comboBox->addItems({"Circle", "Ellipse", "Square", "Rectangle", "Romb", "Hexagon", "Star"});

    //scene->addItem(new Ellipse(0, 0, 200, 100));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScene()));
    timer->start(10);

    //ui->horizontalSlider->setValue(10);
    //ui->horizontalSlider_2->setValue(0);

    //connect(this, SIGNAL(loh(qreal)), this, SLOT(getAr(qreal)));
    //connect(shape, SIGNAL(arSignal(qreal)), this, SLOT(getAr(qreal)));

    //connect(shape, SIGNAL(oldCent(QPointF)), this, SLOT(getOld(QPointF)));
    //connect(shape, SIGNAL(curCent(QPointF)), this, SLOT(getCur(QPointF)));

    ui->spinBox_2->setDisabled(true);
    ui->spinBox->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItemToScene(int index)
{
    int x = scene->getPoint().x();
    int y = scene->getPoint().y();
    //int x = 0;
    //int y = 0;

    switch (index) {
    case 0:
        scene->addItem(new Circle(x, y, value1));
        break;
    case 1:
        scene->addItem(new Ellipse(x, y, value1, value2));
        break;
    case 2:
        scene->addItem(new Square(x, y, value1));
        break;
    case 3:
        scene->addItem(new Rectangle(x, y, value1, value2));
        break;
    case 4:
        scene->addItem(new Romb(x, y, value1, value2));
        break;
    case 5:
        scene->addItem(new Hexagon(x, y, value1));
        break;
    case 6:
        scene->addItem(new Star(x, y, value3, value1, value2));
        break;
    }
}

void MainWindow::updateArea()
{
    // if (scene->getSelectedItem()->getCurAr() < 0) {
    //     qDebug() << "loh";
    //     scene->getSelectedItem()->setCurAr(scene->getSelectedItem()->GetAr());
    // }
    ui->label_3->setText("Area: ");
    if (scene->getSelectedItem() != nullptr)
        ui->label_3->setText(QString("Area: ") + QString::number((scene->getSelectedItem()->getCurAr())));
}

void MainWindow::updatePerimeter()
{
    // if (scene->getSelectedItem()->getCurPer() < 0) {
    //     qDebug() << "loh";
    //     scene->getSelectedItem()->setCurPer(scene->getSelectedItem()->GetPer());
    // }
    ui->label_2->setText("Perimeter: ");
    if (scene->getSelectedItem() != nullptr)
        ui->label_2->setText(QString("Perimeter: ") + QString::number(scene->getSelectedItem()->getCurPer()));

    ui->label_4->setText("X-center: ");
    if (scene->getSelectedItem() != nullptr)
        ui->label_4->setText(QString("X-center: ") + QString::number(scene->getSelectedItem()->GetCur().x()));

    ui->label_5->setText("Y-center: ");
    if (scene->getSelectedItem() != nullptr)
        ui->label_5->setText(QString("Y-center: ") + QString::number(scene->getSelectedItem()->GetCur().y()));
}

// void MainWindow::setVal1(int v)
// {
//     value1 = v;
// }

// int MainWindow::giveVal1()
// {
//     return value1;
// }

// void MainWindow::setVal2(int v)
// {
//     value2 = v;
// }

// int MainWindow::giveVal2()
// {
//     return value2;
// }

// void MainWindow::setVal3(int v)
// {
//     value3 = v;
// }

// int MainWindow::giveVal3()
// {
//     return value3;
// }

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    item = scene->getSelectedItem();

    if (item != nullptr && value > 0.2) {
        item->setTransformOriginPoint(scene->getSelectedItem()->GetOld());

        //qDebug() << "loh";
        //ui->horizontalSlider->setValue(item->scale() * 10);
        item->setScale((qreal)value / 10);

        item->setCurAr(item->GetAr() * value / 10 * value / 10);
        item->setCurPer(item->GetPer() * value / 10);
    }
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{

    item = scene->getSelectedItem();

    if (item != nullptr) {
        item->setTransformOriginPoint(scene->getSelectedItem()->GetOld());

        //ui->horizontalSlider_2->setValue(item->rotation() / 3.6);
        item->setRotation((qreal)value * 3.59);


    }
}

void MainWindow::on_comboBox_activated(int index)
{
    scene->SetItemIndex(index);
    item_index = index;

    switch (index) {
    case 0:
        ui->label_6->setText("radius");
        ui->label_7->setText("");
        ui->label_8->setText("");
        ui->spinBox_2->setDisabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 1:
        ui->label_6->setText("x-axis");
        ui->label_7->setText("y-axis");
        ui->label_8->setText("");
        ui->spinBox_2->setEnabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 2:
        ui->label_6->setText("half side");
        ui->label_7->setText("");
        ui->label_8->setText("");
        ui->spinBox_2->setDisabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 3:
        ui->label_6->setText("half width");
        ui->label_7->setText("half height");
        ui->label_8->setText("");
        ui->spinBox_2->setEnabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 4:
        ui->label_6->setText("half width");
        ui->label_7->setText("half height");
        ui->label_8->setText("");
        ui->spinBox_2->setEnabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 5:
        ui->label_6->setText("radius");
        ui->label_7->setText("");
        ui->label_8->setText("");
        ui->spinBox_2->setDisabled(true);
        ui->spinBox->setDisabled(true);
        break;
    case 6:
        ui->label_6->setText("first radius");
        ui->label_7->setText("second radius");
        ui->label_8->setText("number");
        ui->spinBox_2->setEnabled(true);
        ui->spinBox->setEnabled(true);
        break;
    }
}

void MainWindow::on_radioButton_clicked()
{
    scene->SetItemMode(0);
    item_mode = 0;
}

void MainWindow::on_radioButton_2_clicked()
{
    scene->SetItemMode(1);
    item_mode = 1;
}


void MainWindow::on_radioButton_3_clicked()
{
    scene->SetItemMode(2);
    item_mode = 2;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    value1 = arg1;
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    value2 = arg1;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    value3 = arg1;
}

