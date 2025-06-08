#ifndef ALGORITHMEDITOR_H
#define ALGORITHMEDITOR_H

#include <QWidget>

namespace Ui {
class AlgorithmEditor;
}

class AlgorithmEditor : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit AlgorithmEditor(QWidget *parent = nullptr);
    ~AlgorithmEditor();

private slots:
    void on_executeButton_clicked();

    void on_solversComboBox_currentIndexChanged(int index);

    void on_solversComboBox_activated(int index);

private:
    Ui::AlgorithmEditor *ui;

signals:
    void ExecuteAlgorithm(int index);
    void ChangedAlgorithm(int index);
};

#endif // ALGORITHMEDITOR_H
