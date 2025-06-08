#ifndef CONNECTIVITYSOLVER_H
#define CONNECTIVITYSOLVER_H
#pragma once

#include "graph.h"
#include <QQueue>
#include <QStack>

namespace ConnectivitySolver
{
    QSet<Vertex*> BFSWeak(const Graph& graph, Vertex* start);
    QHash<Vertex*, int> WeakComponents(const Graph& graph);
    int WeakComponentsAmmount(const Graph& graph);
    bool IsWeaklyConnected(const Graph& graph);

    void DFSFirstForKosaraju(const Graph& graph, Vertex* start,
                             QSet<Vertex*>& visited, QStack<Vertex*>& order);
    void DFSSecondForKosaraju(const Graph& graph, Vertex* start, QSet<Vertex*>& visited,
                              int count, QHash<Vertex*, int>& result);
    QHash<Vertex*, int> Kosaraju(const Graph& graph);
    int StrongComponentsAmmount(const Graph& graph);
    bool IsStronglyConnected(const Graph& graph);
}

#endif // CONNECTIVITYSOLVER_H
