#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QRandomGenerator>
#include "../../LR7/Task_2/mystylesheets.h"
#include "binarysearchtree.h"

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
    void on_insertButton_clicked();

    void on_findButton_clicked();

    void on_balanceButton_clicked();

    void on_removeButton_clicked();

    void on_preorderButton_clicked();

    void on_inorderButton_clicked();

    void on_postorderButton_clicked();

    void on_addStringButton_clicked();

    void on_removeStringButton_clicked();

    void on_inputButton_clicked();

    void on_leavesButton_clicked();

private:
    void fillTreeWidgetFromBST(QTreeWidgetItem* treeWidget, BinarySearchTree<int, QString>::Node* node);

    void displayTree();

    Ui::MainWindow *ui;

    BinarySearchTree<int, QString>* tree;
};
#endif // MAINWINDOW_H
