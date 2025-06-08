#ifndef EULERIANSOLVER_H
#define EULERIANSOLVER_H
#pragma once

#include "connectivitysolver.h"

namespace EulerianSolver
{
    bool IsEulerian(const Graph& graph);
    bool IsHalfEulerian(const Graph& graph);

    QList<Edge*> FindEulirianPath(const Graph& graph);
};

#endif // EULERIANSOLVER_H
