#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QItemDelegate>
#include <QDebug>

class NumberDelegate : public QItemDelegate {
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)

        QSpinBox *editor = new QSpinBox(parent);
        editor->setFrame(false);
        editor->setMinimum(std::numeric_limits<int>::min());
        editor->setMaximum(std::numeric_limits<int>::max());
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        editor->setGeometry(option.rect);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<QPair<int, QString>> a(16);
    for (int i = 0; i < 16; ++i) {
        a[i].first = QRandomGenerator::global()->bounded(26);
        a[i].second = QChar(i + 'A');
    }

    tree = LeavesCalcTree(a);

    ui->addStringButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->removeStringButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->inputButton->setStyleSheet(MyStyleSheets::redButtonStyle);
    ui->leavesButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->balanceButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->findButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->insertButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->removeButton->setStyleSheet(MyStyleSheets::blueButtonStyle);
    ui->preorderButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->postorderButton->setStyleSheet(MyStyleSheets::greenButtonStyle);
    ui->inorderButton->setStyleSheet(MyStyleSheets::greenButtonStyle);

    setStyleSheet(MyStyleSheets::mainWindowStyle);
    ui->tableWidget->setStyleSheet(MyStyleSheets::tableWidgetStyle);
    ui->treeWidget->setStyleSheet(MyStyleSheets::treeWidgetStyle);
    ui->label->setStyleSheet(MyStyleSheets::labelStyle);
    ui->label_1->setStyleSheet(MyStyleSheets::labelStyle);
    ui->label_2->setStyleSheet(MyStyleSheets::labelStyle);

    ui->keySpinBox->setStyleSheet(MyStyleSheets::spinBoxStyle);
    ui->infoLineEdit->setStyleSheet(MyStyleSheets::lineEditStyle);
    ui->resLAbel->setStyleSheet(MyStyleSheets::plainTextEditStyle);

    displayTree();

    ui->tableWidget->setRowCount(16);
    ui->tableWidget->setColumnCount(2);
    for (int row = 0; row < 16; ++row) {
        QTableWidgetItem *item0 = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 1, item1);
    }

    for (int i = 0; i < 16; ++i) {
        ui->tableWidget->item(i, 0)->setText(QString::number(a[i].first));
        ui->tableWidget->item(i, 1)->setText(a[i].second);
    }

    ui->resLAbel->setReadOnly(true);

    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setCentralWidget(ui->gridLayoutWidget);
    setWindowTitle("Search tree");

    ui->tableWidget->setItemDelegateForColumn(0, new NumberDelegate());

    tree.BalanceTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTreeWidgetFromBST(QTreeWidgetItem *item, LeavesCalcTree::Node *node)
{
    if (node == nullptr)
        return;

    item->setText(0, QString::number(node->key) + " " + node->info);

    if (node->left != nullptr) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(leftSon, node->left);
    }

    if (node->right != nullptr) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(rightSon, node->right);
    }
}

void MainWindow::displayTree()
{
    ui->treeWidget->clear();

    if (tree.root == nullptr)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);

    fillTreeWidgetFromBST(rootItem, tree.root);

    ui->treeWidget->addTopLevelItem(rootItem);
}

void MainWindow::on_insertButton_clicked()
{
    tree.Insert(ui->keySpinBox->value(), ui->infoLineEdit->text());
    displayTree();
}

void MainWindow::on_findButton_clicked()
{
    QString res = tree.Find(ui->keySpinBox->value());
    ui->resLAbel->setPlainText(res == "" ? "There is no such key!" : res);
}

void MainWindow::on_balanceButton_clicked()
{
    tree.BalanceTree();
    displayTree();
}

void MainWindow::on_removeButton_clicked()
{
    tree.Remove(ui->keySpinBox->value());
    displayTree();
}

void MainWindow::on_preorderButton_clicked()
{
    auto res = tree.preOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_inorderButton_clicked()
{
    auto res = tree.inOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_postorderButton_clicked()
{
    auto res = tree.postOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_addStringButton_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

    QTableWidgetItem *item0 = new QTableWidgetItem();
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item0);
    QTableWidgetItem *item1 = new QTableWidgetItem();
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item1);

    ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 0)->setText(QString::number(ui->keySpinBox->value()));
    ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 1)->setText(ui->infoLineEdit->text());
    qDebug() << 3;
}

void MainWindow::on_removeStringButton_clicked()
{
    ui->tableWidget->setRowCount(std::max(ui->tableWidget->rowCount() - 1, 0));
}

void MainWindow::on_inputButton_clicked()
{
    QVector<QPair<int, QString>> a(ui->tableWidget->rowCount());

    for (int i = 0; i < a.size(); ++i) {
        a[i].first = ui->tableWidget->item(i, 0)->text().toInt();
        a[i].second = ui->tableWidget->item(i, 1)->text();
    }

    tree = LeavesCalcTree(a);

    displayTree();
}

void MainWindow::on_leavesButton_clicked()
{
    ui->resLAbel->setPlainText(QString::number(tree.CalcLeaves()));
}

