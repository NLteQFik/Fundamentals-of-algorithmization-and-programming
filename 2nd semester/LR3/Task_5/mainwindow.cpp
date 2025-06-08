#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_dirs->setText("Number of directories: ");
    ui->label_files->setText("Number of files: ");
    this->setFixedSize(this->size());
    this->setWindowTitle("Dirs and files calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sel_dir = QFileDialog::getExistingDirectory(this, "Select a directory", QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (sel_dir.isEmpty())
        return;
    dirs = 0;
    files = 0;
    dfc.Count(dirs, files, sel_dir);
    ui->label_dirs->setText("Number of directories: " + QString::number(dirs));
    ui->label_files->setText("Number of files: " + QString::number(files));
    model = new DirectoryModel(this);
    model->setRootPath(QDir::homePath());
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(sel_dir));
    ui->treeView->setHeaderHidden(true);
}

