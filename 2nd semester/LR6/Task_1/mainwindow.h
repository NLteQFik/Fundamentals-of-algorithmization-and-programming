#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVariant>
#include <QString>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include "sportsman.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    void set();
    void setByInit();
    void SetByAssign();
    void setByPointer();
    void setByReference();

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void on_confirmButton_clicked();

private:
    int curQ = -1;
    sportsman a;
    Ui::MainWindow *ui;
    QFormLayout *formLayout;
};


#endif // MAINWINDOW_H
