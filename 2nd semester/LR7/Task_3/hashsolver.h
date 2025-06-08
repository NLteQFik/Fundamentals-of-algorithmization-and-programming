#ifndef HASHSOLVER_H
#define HASHSOLVER_H

#include <QDebug>
#include "hashtable.h"

class HashSolver : public HashTable<int>
{
public:
    HashSolver(int num) : HashTable<int>(num) {}

    void DeleteEvenKeys() {
        for (int i = 1; i < size; i += 2)
            while (!table[i].empty())
                table[i].pop();
    }

    QVector<QVector<int>> DisplayHashTable(){
        QVector<QVector<int>> result;
        result.resize(size);

        for (int i = 0; i < size; i++) {
            Stack<int> temp = table[i];
            while (!temp.empty())
            {
                result[i].push_back(temp.Top());
                temp.pop();
            }
        }
        return result;
    }
};

#endif // HASHSOLVER_H
