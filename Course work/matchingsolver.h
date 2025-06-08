#ifndef MATCHINGSOLVER_H
#define MATCHINGSOLVER_H
#pragma once

#include <QQueue>
#include "graph.h"

namespace MatchingSolver
{
    bool IsBipartite(const Graph& graph, QSet<Vertex*>& left, QSet<Vertex*>& right);
    bool BFSColoring(const Graph& graph, Vertex* start,
                 QHash<Vertex*, int>& color,
                 QSet<Vertex*>& left, QSet<Vertex*>& right);

    QList<Edge*> HopcroftKarp(const Graph& graph);
    bool BFSHopcroft(const Graph& graph, const QSet<Vertex*>& left,
                     QHash<Vertex*, Vertex*>& pair_u,
                     QHash<Vertex*, Vertex*>& pair_v,
                     QHash<Vertex*, int>& dist);
    bool DFSHopcroft(const Graph& graph, Vertex* u,
                     QHash<Vertex*, Vertex*>& pair_u,
                     QHash<Vertex*, Vertex*>& pair_v,
                     QHash<Vertex*, int>& dist);
}

#endif // MATCHINGSOLVER_H
