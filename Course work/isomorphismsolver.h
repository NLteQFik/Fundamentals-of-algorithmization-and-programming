#ifndef ISOMORPHISMSOLVER_H
#define ISOMORPHISMSOLVER_H
#pragma once

#include <QMap>

#include "graph.h"

//#include "QtAlgorithms"
//#include <algorithm>

namespace IsomorphismSolver
{
    QList<QPair<Vertex*, Vertex*>> VF2Algorithm(const Graph& graph1, const Graph& graph2);
    bool CheckBasicInvariants(const Graph& graph1, const Graph& graph2);
    bool IsomorphismBacktracking(const Graph& graph1, const Graph& graph2,
                                 QMap<Vertex*, Vertex*>& mapping, QSet<Vertex*> used,
                                 QList<Vertex*> unassigned);
    QList<Vertex*> FindCandidates(const Graph& graph1, const Graph& graph2,
                                   const QMap<Vertex*, Vertex*>& mapping, const QSet<Vertex*> used,
                                   Vertex* v);
    bool VerifyIsomorphism(const Graph& graph1, const Graph& graph2,
                           const QMap<Vertex*, Vertex*>& mapping);
}

#endif // ISOMORPHISMSOLVER_H
