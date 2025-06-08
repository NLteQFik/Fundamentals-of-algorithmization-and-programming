#ifndef MINCOSTFLOWSOLVER_H
#define MINCOSTFLOWSOLVER_H

#include "graph.h"

namespace MinCostFlowSolver
{
QPair<int, int> MinCostFlow(const Graph& graph, Vertex* source, Vertex* sink, int required_flow);
QPair<QList<Edge*>, QHash<Vertex*, int>> BellmanFord(const Graph& graph, Vertex* source,
                                                       Vertex* sink, QHash<Vertex*, int>& pot);
}

#endif // MINCOSTFLOWSOLVER_H
