#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>

#include "mygraphicsscene.h"
#include "graph.h"

namespace Ui {
class MyView;
}

class MyView : public QWidget
{
    Q_OBJECT
    friend class MainWindow;

public:
    explicit MyView(QWidget *parent = nullptr);
    ~MyView();

private:
    MyGraphicsScene* scene = nullptr;
    Graph* graph = nullptr;
    Vertex* pot_source = nullptr;
    bool normal_coloring = true;
    int item_mode = 0;
    int vertex_mode = 0;
    int item_index = 0;
    Ui::MyView *ui;
};

#endif // MYVIEW_H
