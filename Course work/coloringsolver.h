#ifndef COLORINGSOLVER_H
#define COLORINGSOLVER_H

#include <queue>
#include <tuple>
#include "graph.h"

namespace ColoringSolver
{
    QHash<Vertex*, int> DSatur(const Graph& graph);
    int ChromaticNumber(const Graph& graph, const QHash<Vertex*, int>& colors);
    QSet<Vertex*> GetNeighbors(const Graph& graph, Vertex* v);
}

#endif // COLORINGSOLVER_H
