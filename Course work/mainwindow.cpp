#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateScene()
{
    if (cur_view->scene->isActive())
    {
        switch (cur_view->item_mode) {
        case 0:
            UpdateInfo();
            break;
        case 1:
            AddVertex();
            break;
        case 2:
            AddEdge();
            break;
        case 3:
            RemoveItem();
            break;
        }
        cur_view->scene->setActive(false);
    }

    cur_view->scene->update();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AddView();
    sel_view = cur_view;

    v_edit = new VertexEditor();
    e_edit = new EdgeEditor();
    a_edit = new AlgorithmEditor();

    ui->stackedEditorWidget->addWidget(v_edit);
    ui->stackedEditorWidget->addWidget(e_edit);
    ui->stackedEditorWidget->addWidget(a_edit);

    connect(v_edit, &VertexEditor::VertexInfoChanged,
            this, &MainWindow::SetVertexAttributes);

    connect(e_edit, &EdgeEditor::EdgeInfoChanged,
            this, &MainWindow::SetEdgeAttributes);

    connect(a_edit, &AlgorithmEditor::ExecuteAlgorithm,
            this, &MainWindow::ExecuteAlgorithm);

    connect(a_edit, &AlgorithmEditor::ChangedAlgorithm,
            this, &MainWindow::PrepareGraphWithChangedAlgorithm);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScene()));
    timer->start(10);

    ChangeMode(0);

    setWindowTitle("Graph Solver");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddView()
{
    if (ui->stackedSceneWidget->count() >= 10)
    {
        QMessageBox::critical(this, "Error", "It's forbidden to open more than 10 pages");
        return;
    }

    MyView* view_container = new MyView();
    ui->stackedSceneWidget->addWidget(view_container);

    ui->totalPageSpinBox->setValue(ui->stackedSceneWidget->count());
    SwitchToView(ui->stackedSceneWidget->count() - 1);
}

void MainWindow::RemoveView()
{
    if (ui->stackedSceneWidget->count() <= 1)
    {
        QMessageBox::critical(this, "Error", "It's forbidden to delete last page");
        return;
    }

    ui->stackedSceneWidget->removeWidget(cur_view);

    delete cur_view;
    cur_view = nullptr;

    ui->totalPageSpinBox->setValue(ui->stackedSceneWidget->count());
    SwitchToView(qMin(cur_index, ui->stackedSceneWidget->count() - 1));
}

void MainWindow::SwitchToView(int index)
{
    cur_index = index;
    ui->stackedSceneWidget->setCurrentIndex(index);

    ui->curPageSpinBox->setMaximum(ui->totalPageSpinBox->value());
    ui->selPageSpinBox->setMaximum(ui->totalPageSpinBox->value());
    ui->curPageSpinBox->setValue(index + 1);

    cur_view = dynamic_cast<MyView*>(ui->stackedSceneWidget->currentWidget());
    ChangeMode(cur_mode);
}

void MainWindow::AddVertex()
{
    int x = cur_view->scene->getPoint().x();
    int y = cur_view->scene->getPoint().y();

    Vertex* new_v = new Vertex(x, y);
    cur_view->graph->AddVertex(new_v);
    cur_view->scene->addItem(new_v);

    sel_v = new_v;
    SetVertexAttributes(v_edit->name);
    sel_v = nullptr;
}

void MainWindow::AddEdge()
{
    if (Vertex* v = dynamic_cast<Vertex*>(cur_view->scene->getSelectedItem()))
    {
        if (cur_view->pot_source == nullptr)
        {
            cur_view->pot_source = v;
            cur_view->pot_source->SetColor(Qt::blue);
            return;
        }
        else if (v != cur_view->pot_source)
        {
            Edge* new_e = new Edge(cur_view->pot_source, v);
            cur_view->graph->AddEdge(new_e);
            cur_view->scene->addItem(new_e);
            sel_e = new_e;
            SetEdgeAttributes(e_edit->weight, e_edit->price);
            sel_e = nullptr;
        }
    }
    if (cur_view->pot_source)
    {
        cur_view->pot_source->SetColorByName();
        cur_view->pot_source = nullptr;
    }
}

void MainWindow::RemoveItem()
{
    if (Vertex* v = dynamic_cast<Vertex*>(cur_view->scene->getSelectedItem()))
        cur_view->graph->RemoveVertex(v);
    else if (Edge* e = dynamic_cast<Edge*>(cur_view->scene->getSelectedItem()))
        cur_view->graph->RemoveEdge(e);
}

void MainWindow::ShowGraph()
{
    for (Vertex* v : cur_view->graph->_vertices)
    {
        cur_view->scene->addItem(v);

        sel_v = v;
        SetVertexAttributes(v->GetName());
        sel_v = nullptr;
    }

    for (Edge* e : cur_view->graph->_edges)
    {
        cur_view->scene->addItem(e);

        sel_e = e;
        SetEdgeAttributes(e->_weight, e->_price);
        sel_e = nullptr;
    }
}

void MainWindow::UpdateInfo()
{
    sel_v = nullptr;
    sel_e = nullptr;

    if (Vertex* v = dynamic_cast<Vertex*>(cur_view->scene->getSelectedItem()))
    {
        sel_v = v;
        v_edit->SetInfo(v->GetName());
        ui->stackedEditorWidget->setCurrentIndex(1);
    }
    else if (Edge* e = dynamic_cast<Edge*>(cur_view->scene->getSelectedItem()))
    {
        sel_e = e;
        e_edit->SetInfo(e->GetWeight(), e->GetPrice());
        ui->stackedEditorWidget->setCurrentIndex(2);
    }
    else
        ui->stackedEditorWidget->setCurrentIndex(0);
}

void MainWindow::ChangeMode(int new_mode)
{
    ui->flowReqiredSpinBox->hide();

    cur_mode = new_mode;

    sel_v = nullptr;
    sel_e = nullptr;
    ui->stackedEditorWidget->setCurrentIndex(0);

    if (cur_view->pot_source)
    {
        cur_view->pot_source->SetColorByName();
        cur_view->pot_source = nullptr;

        cur_view->scene->update();
    }

    if (new_mode == 1)
        ui->stackedEditorWidget->setCurrentIndex(1);

    if (new_mode == 2)
        ui->stackedEditorWidget->setCurrentIndex(2);

    if (!cur_view->normal_coloring && new_mode != 4)
        ChangeToNormalColoring();

    //cur_view->item_mode != 4 && new_mode == 4
    if (new_mode == 4)
    {
        PrepareSourcesAndTargets();
        ui->stackedEditorWidget->setCurrentIndex(3);
    }

    cur_view->scene->SetItemMode(new_mode);
    cur_view->item_mode = new_mode;

    ui->infoLable->setText("");
}

void MainWindow::ChangeToNormalColoring()
{
    for (Vertex* v : cur_view->graph->_vertices)
        v->SetColorByName();

    for (Edge* e : cur_view->graph->_edges)
        e->SetColor(Qt::black);

    cur_view->normal_coloring = true;
    ChangeEdgeMode(1);

    cur_view->scene->update();
}

void MainWindow::PrepareSourcesAndTargets()
{
    cur_view->graph->_sources.clear();
    cur_view->graph->_targets.clear();

    for (Vertex* v : cur_view->graph->_vertices)
    {
        if (v->GetName()[0] == "S")
            cur_view->graph->_sources.push_back(v);
        else if (v->GetName()[0] == "T")
            cur_view->graph->_targets.push_back(v);
    }
}

void MainWindow::ChangeEdgeMode(int new_mode)
{
    for (Edge* e : cur_view->graph->_edges)
    {
        e->_mode = new_mode;
    }

    //cur_view->scene->update();
}

QVector<QColor> MainWindow::GenerateColorPalette(int ammount)
{
    QVector<QColor> colors;
    for (int i = 0; i < ammount; ++i)
    {
        qreal hue = static_cast<qreal>(i) / ammount;
        colors.append(QColor::fromHsvF(hue, 0.8, 1.0));
    }

    return colors;
}

void MainWindow::FindShortestPath()
{
    if (cur_view->graph->_sources.size() != 1 || cur_view->graph->_targets.size() != 1)
    {
        ui->infoLable->setText("There must be exectly 1 source and only 1 target!");
        return;
    }

    int counter = 0;
    int weight = 0;

    for (Edge* e : ShortestPathSolver::Dijkstra(*cur_view->graph,
                                                cur_view->graph->_sources[0],
                                                cur_view->graph->_targets[0]))
    {
        ++counter;
        weight += e->_weight;
        e->SetColor(Qt::green);
    }

    if (counter)
        ui->infoLable->setText("Successfully found a minimal path and painted it green. It consists of " +
                               QString::number(counter) + " edges and it's total weight is " + QString::number(weight));
    else
        ui->infoLable->setText("Unfortunately there is no path between source and target");
}

void MainWindow::FindMinimalSpanningForest()
{
    int counter = 0;
    int weight = 0;

    for (Edge* e : MinSpanningForestSolver::Kruskal(*cur_view->graph))
    {
        ++counter;
        weight += e->_weight;
        e->SetColor(Qt::green);
    }

    if (counter)
        ui->infoLable->setText("Successfully found a minimal spanning forest and painted it green. It consists of " +
                               QString::number(counter) + " edges and it's total weight is " + QString::number(weight));
    else
        ui->infoLable->setText("Unfortunately there is no spanning forest in this graph");
}

void MainWindow::FindMaximalMathcingInBipartite()
{
    int counter = 0;

    for (Edge* e : MatchingSolver::HopcroftKarp(*cur_view->graph))
    {
        ++counter;
        e->SetColor(Qt::green);
    }

    if (counter)
        ui->infoLable->setText("Successfully found a maximal matching and painted it green. It consists of " +
                               QString::number(counter) + " pairs");
    else
        ui->infoLable->setText("Unfortunately this graph isn't bipartite");
}

void MainWindow::FindWeakComponents()
{
    QHash<Vertex*, int> coloring = ConnectivitySolver::WeakComponents(*cur_view->graph);
    int weak_components = ColoringSolver::ChromaticNumber(*cur_view->graph, coloring);
    QVector<QColor> colors = GenerateColorPalette(weak_components);
    for (Vertex* v : cur_view->graph->_vertices)
        v->SetColor(colors[coloring[v]]);

    ui->infoLable->setText("Weak components ammount is " + QString::number(weak_components) +
                           "and vertices are colored to represent components.");

    if (weak_components <= 1)
        ui->infoLable->setText(ui->infoLable->text() + "Also graph is weakly connected");
    else
        ui->infoLable->setText(ui->infoLable->text() + "Also graph isn't weakly connected");
}

void MainWindow::FindStrongComponents()
{
    QHash<Vertex*, int> coloring = ConnectivitySolver::Kosaraju(*cur_view->graph);
    int strong_components = ColoringSolver::ChromaticNumber(*cur_view->graph, coloring);
    QVector<QColor> colors = GenerateColorPalette(strong_components);
    for (Vertex* v : cur_view->graph->_vertices)
        v->SetColor(colors[coloring[v]]);

    ui->infoLable->setText("Strong components ammount is " + QString::number(strong_components) +
                           "and vertices are colored to represent components.");

    if (strong_components <= 1)
        ui->infoLable->setText(ui->infoLable->text() + "Also graph is strongly connected");
    else
        ui->infoLable->setText(ui->infoLable->text() + "Also graph isn't strongly connected");
}

void MainWindow::FindColoring()
{
    QHash<Vertex*, int> coloring = ColoringSolver::DSatur(*cur_view->graph);
    int colors_num = ColoringSolver::ChromaticNumber(*cur_view->graph, coloring);
    QVector<QColor> colors = GenerateColorPalette(colors_num);
    for (Vertex* v : cur_view->graph->_vertices)
        v->SetColor(colors[coloring[v]]);

    ui->infoLable->setText("Chromatic number of graph is " + QString::number(colors_num) +
                           "and vertices are colored to represent graph coloring.");
}

void MainWindow::FindEulerian()
{
    for (Edge* e : EulerianSolver::FindEulirianPath(*cur_view->graph))
        e->SetColor(Qt::green);

    if (EulerianSolver::IsEulerian(*cur_view->graph))
        ui->infoLable->setText("Graph is eulerian. Eulerian cycle exists");
    else if (EulerianSolver::IsHalfEulerian(*cur_view->graph))
        ui->infoLable->setText("Graph is half eulerian. Eulerian path exists");
    else
        ui->infoLable->setText("Graph isn't even half eulerian. Eulerian path doesn't exist");
}

void MainWindow::FindMaxFlowAndMinCut()
{
    if (cur_view->graph->_sources.size() < 1 || cur_view->graph->_targets.size() < 1)
    {
        ui->infoLable->setText("There must be at least 1 source and only 1 target!");
        return;
    }

    QPair<int, QList<Edge*>> result =
        MaxFlowSolver::MultyMaxFlow(*cur_view->graph,
                                    cur_view->graph->_sources,
                                    cur_view->graph->_targets);

    int counter = 0;

    for (Edge* e : result.second)
    {
        ++counter;
        e->SetColor(Qt::red);
    }

    if (counter)
        ui->infoLable->setText("Successfully found maxiumum flow with value " + QString::number(result.first)
                           + " and colored minimal cut red");
    else
        ui->infoLable->setText("Unfortunately there is no flow in graph");

    ChangeEdgeMode(2);
}

void MainWindow::FindIsomorphism()
{
    QList<QPair<Vertex*, Vertex*>> isomorphism = IsomorphismSolver::VF2Algorithm(*cur_view->graph, *sel_view->graph);
    if (!isomorphism.size())
    {
        ui->infoLable->setText("Unforunately graphs are not isomorphic");
        return;
    }

    int size = cur_view->graph->_vertices.size();
    QVector<QColor> colors = GenerateColorPalette(size);
    for (auto it : isomorphism)
    {
        --size;
        it.first->SetColor(colors[size]);
        it.second->SetColor(colors[size]);
    }

    sel_view->normal_coloring = false;

    ui->infoLable->setText("Successfully found an isomorphism");
}

void MainWindow::FindMinCostFlow()
{
    if (cur_view->graph->_sources.size() != 1 || cur_view->graph->_targets.size() != 1)
    {
        ui->infoLable->setText("There must be exactly 1 source and only 1 target!");
        return;
    }

    QPair<int, int> result;
    result = MinCostFlowSolver::MinCostFlow(*cur_view->graph, cur_view->graph->_sources[0],
                                            cur_view->graph->_targets[0], ui->flowReqiredSpinBox->value());

    if (result.first)
        ui->infoLable->setText("Successfully pushed the flow " + QString::number(result.first)
                           + " with minimal cost " + QString::number(result.second));
    else
        ui->infoLable->setText("Unfortunately there is no flow in graph");

    ChangeEdgeMode(2);
}

void MainWindow::ExecuteAlgorithm(int index)
{
    if (!cur_view->normal_coloring)
        ChangeToNormalColoring();

    switch (index) {
    case 0:
        FindShortestPath();
        break;
    case 1:
        FindMinimalSpanningForest();
        break;
    case 2:
        FindMaximalMathcingInBipartite();
        break;
    case 3:
        FindWeakComponents();
        break;
    case 4:
        FindStrongComponents();
        break;
    case 5:
        FindColoring();
        break;
    case 6:
        FindEulerian();
        break;
    case 7:
        FindMaxFlowAndMinCut();
        break;
    case 8:
        FindMinCostFlow();
        break;
    case 9:
        FindIsomorphism();
        break;
    }


    cur_view->scene->update();
    cur_view->normal_coloring = false;
}

void MainWindow::SetVertexAttributes(QString name)
{
    if (sel_v)
    {
        sel_v->SetName(name);

        if (name[0] == "S")
            sel_v->SetColor(Qt::cyan);
        else if (name[0] == "T")
            sel_v->SetColor(Qt::magenta);
        else
            sel_v->SetColor(Qt::white);
    }
}

void MainWindow::SetEdgeAttributes(int weight, int price)
{
    if (sel_e)
    {
        sel_e->SetWeight(weight);
        sel_e->SetPrice(price);
    }
}

void MainWindow::PrepareGraphWithChangedAlgorithm(int index)
{
    if (index == 8)
        ui->flowReqiredSpinBox->show();
    else
        ui->flowReqiredSpinBox->hide();

    ui->infoLable->setText("");

    if (!cur_view->normal_coloring)
        ChangeToNormalColoring();
}

void MainWindow::on_comboBox_activated(int index)
{
    cur_view->scene->SetItemIndex(index);
    cur_view->item_index = index;

    if (!cur_view->normal_coloring)
        ChangeToNormalColoring();
}

void MainWindow::on_modeComboBox_currentIndexChanged(int index)
{
    ChangeMode(index);
}

void MainWindow::on_leftPageButton_clicked()
{
    if (--cur_index == -1)
        cur_index = ui->stackedSceneWidget->count() - 1;

    SwitchToView(cur_index);
}

void MainWindow::on_rightPageButton_clicked()
{
    if (++cur_index == ui->stackedSceneWidget->count())
        cur_index = 0;

    SwitchToView(cur_index);
}

void MainWindow::on_addPageButton_clicked()
{
    AddView();
}

void MainWindow::on_closePageButton_clicked()
{
    RemoveView();
}

void MainWindow::on_openPageButton_clicked()
{
    if (cur_view->graph)
        delete cur_view->graph;
    cur_view->graph = new Graph();

    QString file_name = QFileDialog::getOpenFileName(this, "Load the graph", QDir::homePath(), "Graph Files (*.graph)");

    if (file_name.isEmpty())
        return;

    switch (cur_view->graph->LoadFromBinary(file_name))
    {
    case 1:
        QMessageBox::critical(this, "Error", "Cannot open a file");
        break;
    case 2:
        QMessageBox::critical(this, "Error", "Wrong file format");
        break;
    case 3:
        QMessageBox::critical(this, "Error", "Unsupported version of file");
        break;
    default:
        break;
    }

    ShowGraph();
}

void MainWindow::on_savePageButton_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save the graph", QDir::homePath(), "Graph Files (*.graph)");

    if (file_name.isEmpty())
        return;

    if (!file_name.endsWith(".graph", Qt::CaseInsensitive))
        file_name += ".graph";

    switch (cur_view->graph->SaveToBinary(file_name))
    {
    case 1:
        QMessageBox::critical(this, "Error", "Cannot create a file");
        break;
    default:
        break;
    }
}

void MainWindow::on_curPageSpinBox_valueChanged(int arg1)
{
    SwitchToView(arg1 - 1);
}

void MainWindow::on_selPageSpinBox_valueChanged(int arg1)
{
    sel_view = dynamic_cast<MyView*>(ui->stackedSceneWidget->widget(arg1 - 1));
}

void MainWindow::on_flowReqiredSpinBox_valueChanged(int arg1)
{

}

