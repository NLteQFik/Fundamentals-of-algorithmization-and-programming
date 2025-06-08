#ifndef EDGEEDITOR_H
#define EDGEEDITOR_H

#include <QWidget>

namespace Ui {
class EdgeEditor;
}

class EdgeEditor : public QWidget
{
    Q_OBJECT
    friend class MainWindow;

public:
    explicit EdgeEditor(QWidget *parent = nullptr);
    ~EdgeEditor();

public slots:
    void SetInfo(int weight, int price);

private slots:
    void on_weightSpinBox_valueChanged(int arg1);
    void on_priceSpinBox_valueChanged(int arg1);

private:
    Ui::EdgeEditor *ui;
    int weight = 0;
    int price = 0;

signals:
    void EdgeInfoChanged(int weight, int price);
};

#endif // EDGEEDITOR_H
