#include "edgeeditor.h"
#include "ui_edgeeditor.h"

EdgeEditor::EdgeEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EdgeEditor)
{
    ui->setupUi(this);
}

EdgeEditor::~EdgeEditor()
{
    delete ui;
}

void EdgeEditor::SetInfo(int weight, int price)
{
    this->weight = weight;
    this->price = price;

    ui->weightSpinBox->setValue(weight);
    ui->priceSpinBox->setValue(price);
}

void EdgeEditor::on_weightSpinBox_valueChanged(int arg1)
{
    weight = arg1;
    emit EdgeInfoChanged(weight, price);
}

void EdgeEditor::on_priceSpinBox_valueChanged(int arg1)
{
    price = arg1;
    emit EdgeInfoChanged(weight, price);
}

