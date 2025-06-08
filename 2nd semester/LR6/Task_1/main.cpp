#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(420, 450);
    w.setWindowTitle("Sportsmen");
    w.setStyleSheet("background-color: rgb(240, 240, 220);");
    w.show();
    return a.exec();
}
