#ifndef VERTEXEDITOR_H
#define VERTEXEDITOR_H

#include <QWidget>
#include <QString>

namespace Ui {
class VertexEditor;
}

class VertexEditor : public QWidget
{
    Q_OBJECT
    friend class MainWindow;

public:
    explicit VertexEditor(QWidget *parent = nullptr);
    ~VertexEditor();
    void InfoChanged();

public slots:
    void SetInfo(QString name);

private slots:
    void on_sourceCheckBox_stateChanged(int arg1);
    void on_targetCheckBox_stateChanged(int arg1);
    void on_idSpinBox_textChanged(const QString &arg1);

private:
    Ui::VertexEditor *ui;
    QString name = "0";
    int vertice_type = 0;

signals:
    void VertexInfoChanged(QString name);
};

#endif // VERTEXEDITOR_H
