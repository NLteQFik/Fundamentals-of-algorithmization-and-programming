#ifndef HANOISOLVER_H
#define HANOISOLVER_H

#include <QTableWidget>

class HanoiSolver
{
public:
    HanoiSolver();
    void Solve(int rings_num, int& steps_num, int from, int to, QTableWidget* w);
};

#endif // HANOISOLVER_H
