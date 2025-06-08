#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::set()
{
    a.age = ui->info_age->value();
    a.height = ui->info_height->value();
    if (!ui->info_category->text().toStdString().empty())
        a.category = ui->info_category->text().toStdString().at(0);
    a.professional = ui->info_professional->isChecked();
    if (!ui->info_name->text().toStdString().empty())
        strcpy(a.name, ui->info_name->text().toStdString().data());
    a.results[0] = ui->info_res1->value();
    a.results[1] = ui->info_res2->value();
    a.results[2] = ui->info_res3->value();

    QString txt = QString::number(a.age) + "|" + QString::number(a.height) + "|" +
                  QString(a.category) + "|" + QVariant(a.professional).toString() + "|" +
                  QString(a.name) + "|" + QString::number(a.results[0]) + " " +
                  QString::number(a.results[1]) + " " + QString::number(a.results[2]);
    ui->info_spr_1->setText(txt);

    if (a.professional)
        QDesktopServices::openUrl(QUrl("https://www.google.com/search?client=ubuntu-sn&channel=fs&q=" + QString(a.name)));

    // if (!strcmp(a.name, "Karenik"))
    //     QDesktopServices::openUrl(QUrl("https://bbrovar.by/ru/brands/ohota/"));
    // if (!strcmp(a.name, "Abelski"))
    //     QDesktopServices::openUrl(QUrl("https://tanki.su"));
    // if (!strcmp(a.name, "Sbakeoff"))
    //     QDesktopServices::openUrl(QUrl("https://www.zmiaikou.com"));
    // if (!strcmp(a.name, "Onoshko"))
    //     QDesktopServices::openUrl(QUrl("https://vk.com/wall40558425_15048"));
    // if (!strcmp(a.name, "Shmygaliov"))
    //     QDesktopServices::openUrl(QUrl("https://io.sb.by/storage01/medialibrary/bd1/bd127e1488191311323e0786ceae6433.jpg"));
}

void MainWindow::setByInit()
{
    sportsman t = {21, 183.5, 'C', false, "Mihaylov", {9.41, 9.34, 9.21}};
    QString txt = QString::number(t.age) + "|" + QString::number(t.height) + "|" +
                  QString(t.category) + "|" + QVariant(t.professional).toString() + "|" +
                  QString(t.name) + "|" + QString::number(t.results[0]) + " " +
                  QString::number(t.results[1]) + " " + QString::number(t.results[2]);
    ui->info_spr_2->setText(txt);
}

void MainWindow::SetByAssign()
{
    sportsman t;
    t.age = 24;
    t.height = 179.4;
    t.category = 'C';
    t.professional = false;
    strcpy(t.name, "Vasilyev");
    t.results[0] = 9.21;
    t.results[1] = 9.35;
    t.results[2] = 9.14;

    QString txt = QString::number(t.age) + "|" + QString::number(t.height) + "|" +
                  QString(t.category) + "|" + QVariant(t.professional).toString() + "|" +
                  QString(t.name) + "|" + QString::number(t.results[0]) + " " +
                  QString::number(t.results[1]) + " " + QString::number(t.results[2]);
    ui->info_spr_3->setText(txt);
}

void MainWindow::setByPointer()
{
    sportsman *t = new sportsman();
    t->age = 19;
    t->height = 178.5;
    t->category = 'B';
    t->professional = true;
    strcpy(t->name, "Shmygailov");
    t->results[0] = 8.58;
    t->results[1] = 9.01;
    t->results[2] = 8.56;

    QString txt = QString::number(t->age) + "|" + QString::number(t->height) + "|" +
                  QString(t->category) + "|" + QVariant(t->professional).toString() + "|" +
                  QString(t->name) + "|" + QString::number(t->results[0]) + " " +
                  QString::number(t->results[1]) + " " + QString::number(t->results[2]);
    ui->info_spr_4->setText(txt);
}

void MainWindow::setByReference()
{
    sportsman &t = a;
    t.age = 18;
    t.height = 192.6;
    t.category = 'B';
    t.professional = true;
    strcpy(t.name, "Aleksnadrov");
    t.results[0] = 8.79;
    t.results[1] = 8.82;
    t.results[2] = 8.81;

    QString txt = QString::number(a.age) + "|" + QString::number(a.height) + "|" +
                  QString(a.category) + "|" + QVariant(a.professional).toString() + "|" +
                  QString(a.name) + "|" + QString::number(a.results[0]) + " " +
                  QString::number(a.results[1]) + " " + QString::number(a.results[2]);
    ui->info_spr_5->setText(txt);
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_empty->setText("");
    ui->info_spr_1->setText("");
    ui->info_spr_2->setText("");
    ui->info_spr_3->setText("");
    ui->info_spr_4->setText("");
    ui->info_spr_5->setText("");

    formLayout = new QFormLayout();

    formLayout->addRow(ui->label_age, ui->info_age);
    formLayout->addRow(ui->label_height, ui->info_height);
    formLayout->addRow(ui->label_category, ui->info_category);
    formLayout->addRow(ui->label_professional, ui->info_professional);
    formLayout->addRow(ui->label_name, ui->info_name);
    formLayout->addRow(ui->label_results, ui->info_res1);
    formLayout->addRow(ui->label_empty, ui->info_res2);
    formLayout->addRow(ui->label_empty, ui->info_res3);
    formLayout->addRow(ui->confirmButton);
    formLayout->addRow(ui->label_spr_1, ui->info_spr_1);
    formLayout->addRow(ui->label_spr_2, ui->info_spr_2);
    formLayout->addRow(ui->label_spr_3, ui->info_spr_3);
    formLayout->addRow(ui->label_spr_4, ui->info_spr_4);
    formLayout->addRow(ui->label_spr_5, ui->info_spr_5);

    ui->widget->setMinimumWidth(420);
    ui->widget->setMinimumHeight(600);
    ui->widget->setLayout(formLayout);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_confirmButton_clicked()
{
    set();
    setByInit();
    SetByAssign();
    setByPointer();
    setByReference();
}

