#include "hanoisolver.h"

HanoiSolver::HanoiSolver() {}

void HanoiSolver::Solve(int rings_num, int &steps_num, int from, int to, QTableWidget *w)
    {
        if (rings_num == 0)
            return;
        if (rings_num == 1)
        {
            w->setRowCount(1 + steps_num);
            w->setItem(steps_num, 0, new QTableWidgetItem(QString::number(steps_num)));
            w->setItem(steps_num, 1, new QTableWidgetItem(QString::number(1)));
            w->setItem(steps_num, 2, new QTableWidgetItem(QString((char)(from + 'A'))));
            w->setItem(steps_num, 3, new QTableWidgetItem(QString((char)(to + 'A'))));
            steps_num++;
            return;
        }

        Solve(rings_num - 1, steps_num, from, 3 - from - to, w);
        w->setRowCount(1 + steps_num);
        w->setItem(steps_num, 0, new QTableWidgetItem(QString::number(steps_num)));
        w->setItem(steps_num, 1, new QTableWidgetItem(QString::number(rings_num)));
        w->setItem(steps_num, 2, new QTableWidgetItem(QString((char)(from + 'A'))));
        w->setItem(steps_num, 3, new QTableWidgetItem(QString((char)(to + 'A'))));
        steps_num++;
        Solve(rings_num - 1, steps_num, 3 - from - to, to, w);
    }
