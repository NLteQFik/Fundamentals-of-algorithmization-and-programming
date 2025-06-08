#ifndef SHORTESTPATHSOLVER_H
#define SHORTESTPATHSOLVER_H
#pragma once

#include <queue>

#include "graph.h"

namespace ShortestPathSolver
{
    QList<Edge*> Dijkstra(const Graph& graph, Vertex* start, Vertex* end);
}

#endif // SHORTESTPATHSOLVER_H
