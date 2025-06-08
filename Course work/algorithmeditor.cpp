#include "algorithmeditor.h"
#include "ui_algorithmeditor.h"

AlgorithmEditor::AlgorithmEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AlgorithmEditor)
{
    ui->setupUi(this);
}

AlgorithmEditor::~AlgorithmEditor()
{
    delete ui;
}

void AlgorithmEditor::on_executeButton_clicked()
{
    emit ExecuteAlgorithm(ui->solversComboBox->currentIndex());
}


void AlgorithmEditor::on_solversComboBox_currentIndexChanged(int index)
{

}

void AlgorithmEditor::on_solversComboBox_activated(int index)
{
    emit ChangedAlgorithm(index);
}

