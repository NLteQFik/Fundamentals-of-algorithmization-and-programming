#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QStackedWidget>
#include <QFileDialog>
#include <QMessageBox>

#include "myview.h"
#include "vertexeditor.h"
#include "edgeeditor.h"
#include "algorithmeditor.h"
#include "mygraphicsscene.h"
#include "graph.h"
#include "shortestpathsolver.h"
#include "minspanningforestsolver.h"
#include "matchingsolver.h"
#include "euleriansolver.h"
#include "coloringsolver.h"
#include "maxflowsolver.h"
#include "isomorphismsolver.h"
#include "mincostflowsolver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void updateScene();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddView();
    void RemoveView();
    void SwitchToView(int index);

    void AddVertex();
    void AddEdge();
    void RemoveItem();
    void ShowGraph();

    void UpdateInfo();
    void ChangeMode(int new_mode);

    void ChangeToNormalColoring();
    void PrepareSourcesAndTargets();
    void ChangeEdgeMode(int new_mode);

    QVector<QColor> GenerateColorPalette(int ammount);

    void FindShortestPath();
    void FindMinimalSpanningForest();
    void FindMaximalMathcingInBipartite();
    void FindWeakComponents();
    void FindStrongComponents();
    void FindColoring();
    void FindEulerian();
    void FindMaxFlowAndMinCut();
    void FindIsomorphism();
    void FindMinCostFlow();

public slots:
    void ExecuteAlgorithm(int index);
    void SetVertexAttributes(QString name);
    void SetEdgeAttributes(int weight, int price);
    void PrepareGraphWithChangedAlgorithm(int index);

private slots:
    void on_comboBox_activated(int index);
    void on_modeComboBox_currentIndexChanged(int index);
    void on_leftPageButton_clicked();
    void on_rightPageButton_clicked();
    void on_addPageButton_clicked();
    void on_closePageButton_clicked();
    void on_openPageButton_clicked();
    void on_savePageButton_clicked();
    void on_curPageSpinBox_valueChanged(int arg1);
    void on_selPageSpinBox_valueChanged(int arg1);

    void on_flowReqiredSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    MyView* cur_view;
    int cur_index;
    int cur_mode;

    MyView* sel_view;

    VertexEditor* v_edit;
    EdgeEditor* e_edit;
    AlgorithmEditor* a_edit;

    Vertex* sel_v = nullptr;
    Edge* sel_e = nullptr;
};
#endif // MAINWINDOW_H
