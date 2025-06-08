#ifndef MAXFLOWSOLVER_H
#define MAXFLOWSOLVER_H
#pragma once

#include "graph.h"
#include <QQueue>

namespace MaxFlowSolver
{
    QPair<int, QList<Edge*>> MultyMaxFlow(Graph& graph, const QList<Vertex*>& sources, const QList<Vertex*>& sinks);

    int DinicMaxFlow(const Graph& graph, Vertex* source, Vertex* sink);
    bool BFSLayeredNetwork(const Graph& graph, QHash<Vertex*, int>& level,
                           Vertex* source, Vertex* sink);
    int DFSBlockingFlow(const Graph& graph, Vertex* u, Vertex* sink,
                        int flow, QHash<Vertex*, int>& level,
                        QHash<Vertex*, int>& ptr);
    QList<Edge*> FindMinCut(const Graph& graph, Vertex* source, Vertex* sink);
    QSet<Vertex*> BFSResidual(const Graph& graph, Vertex* source, Vertex* sink);
}

#endif // MAXFLOWSOLVER_H
