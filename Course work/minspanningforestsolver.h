#ifndef MINSPANNINGFORESTSOLVER_H
#define MINSPANNINGFORESTSOLVER_H
#pragma once

#include "graph.h"
#include <algorithm>

namespace MinSpanningForestSolver
{
    QList<Edge*> Kruskal(const Graph& graph);
    Vertex* FindParent(Vertex* v, QHash<Vertex*, Vertex*>& parent);
}

#endif // MINSPANNINGFORESTSOLVER_H
