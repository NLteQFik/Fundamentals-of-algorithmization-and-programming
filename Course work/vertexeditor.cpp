#include "vertexeditor.h"
#include "ui_vertexeditor.h"

VertexEditor::VertexEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VertexEditor)
{
    ui->setupUi(this);
}

VertexEditor::~VertexEditor()
{
    delete ui;
}

void VertexEditor::InfoChanged()
{
    name = QString::number(ui->idSpinBox->value());
    if (vertice_type == 1)
        name = "S" + name;
    else if (vertice_type == 2)
        name = "T" + name;

    emit VertexInfoChanged(name);
}

void VertexEditor::SetInfo(QString name)
{
    if (name[0] == "S")
    {
        ui->sourceCheckBox->setChecked(true);
        name.remove(0, 1);
    }
    else if (name[0] == "T")
    {
        ui->targetCheckBox->setChecked(true);
        name.remove(0, 1);
    }
    else
    {
        ui->sourceCheckBox->setChecked(false);
        ui->sourceCheckBox->setChecked(false);
    }

    ui->idSpinBox->setValue(name.toInt());
    this->name = name;
}

void VertexEditor::on_sourceCheckBox_stateChanged(int arg1)
{
    if (arg1)
        ui->targetCheckBox->setChecked(false);

    vertice_type = arg1 - 1;
    InfoChanged();
}

void VertexEditor::on_targetCheckBox_stateChanged(int arg1)
{
    if (arg1)
        ui->sourceCheckBox->setChecked(false);

    vertice_type = arg1;
    InfoChanged();
}

void VertexEditor::on_idSpinBox_textChanged(const QString &arg1)
{
    InfoChanged();
}
