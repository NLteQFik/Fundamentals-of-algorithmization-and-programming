#ifndef DOUBLEHASHTABLE_H
#define DOUBLEHASHTABLE_H

#include "hashtable.h"

class DoubleHashTable : public HashTable
{
protected:
    int c, d;
    int second_hash;

    int colisionFunction(int index, int& counter) override
    {
        if (!counter)
            second_hash = (c * index + d) % prime % (size - 1) + 1;
        ++counter;
        return (index + counter * second_hash) % size;
    }

public:
    DoubleHashTable(int size) : HashTable(size)
    {
        c = QRandomGenerator::global()->bounded(1, prime - 1);
        d = QRandomGenerator::global()->bounded(0, prime - 1);
    }
};

#endif // DOUBLEHASHTABLE_H
