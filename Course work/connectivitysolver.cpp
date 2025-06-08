#include "connectivitysolver.h"

QSet<Vertex *> ConnectivitySolver::BFSWeak(const Graph &graph, Vertex *start)
{
    QSet<Vertex*> visited;
    QQueue<Vertex*> queue;

    queue.enqueue(start);
    visited.insert(start);

    while (!queue.isEmpty())
    {
        Vertex* u = queue.dequeue();

        for (Edge* e : graph._out_edges[u])
            if (!visited.contains(e->_target))
            {
                visited.insert(e->_target);
                queue.enqueue(e->_target);
            }

        for (Edge* e : graph._in_edges[u])
            if (!visited.contains(e->_source))
            {
                visited.insert(e->_source);
                queue.enqueue(e->_source);
            }
    }

    return visited;
}

QHash<Vertex *, int> ConnectivitySolver::WeakComponents(const Graph &graph)
{
    int count = 0;
    QHash<Vertex*, int> coloring;
    QSet<Vertex*> unvisited = graph._vertices;

    while (!unvisited.isEmpty())
    {
        QSet<Vertex*> component = BFSWeak(graph, *unvisited.begin());
        for (Vertex* v : component)
            coloring[v] = count;
        unvisited.subtract(component);
        ++count;
    }

    return coloring;
}

int ConnectivitySolver::WeakComponentsAmmount(const Graph &graph)
{
    int count = 0;
    QSet<Vertex*> unvisited = graph._vertices;

    while (!unvisited.isEmpty())
    {
        QSet<Vertex*> component = BFSWeak(graph, *unvisited.begin());
        unvisited.subtract(component);
        ++count;
    }

    return count;
}

bool ConnectivitySolver::IsWeaklyConnected(const Graph &graph)
{
    return WeakComponentsAmmount(graph) <= 1;
}

void ConnectivitySolver::DFSFirstForKosaraju(const Graph &graph, Vertex *start, QSet<Vertex *> &visited, QStack<Vertex *> &order)
{
    visited.insert(start);

    for (Edge* e : graph._out_edges[start])
        if (!visited.contains(e->_target))
            DFSFirstForKosaraju(graph, e->_target, visited, order);

    order.push(start);
}

void ConnectivitySolver::DFSSecondForKosaraju(const Graph &graph, Vertex *start, QSet<Vertex *> &visited,
                                              int count, QHash<Vertex*, int>& result)
{
    visited.insert(start);
    result[start] = count;

    for (Edge* e : graph._in_edges[start])
        if (!visited.contains(e->_source))
            DFSSecondForKosaraju(graph, e->_source, visited, count, result);
}

int ConnectivitySolver::StrongComponentsAmmount(const Graph &graph)
{
    QHash<Vertex *, int> strong_components = Kosaraju(graph);
    int max_color = 0;
    for (Vertex* v : graph._vertices)
        if (strong_components[v] > max_color)
            max_color = strong_components[v];

    return max_color + 1;
}

bool ConnectivitySolver::IsStronglyConnected(const Graph &graph)
{
    return StrongComponentsAmmount(graph) <= 1;
}

QHash<Vertex *, int> ConnectivitySolver::Kosaraju(const Graph &graph)
{
    QSet<Vertex*> visited;
    QStack<Vertex*> order;

    for (Vertex* v : graph._vertices)
        if (!visited.contains(v))
            DFSFirstForKosaraju(graph, v, visited, order);

    visited.clear();
    int count = 0;
    QHash<Vertex*, int> result;

    while (!order.isEmpty())
    {
        Vertex* v = order.pop();
        if (!visited.contains(v))
        {
            DFSSecondForKosaraju(graph, v, visited, count, result);
            ++count;
        }
    }

    return result;
}


