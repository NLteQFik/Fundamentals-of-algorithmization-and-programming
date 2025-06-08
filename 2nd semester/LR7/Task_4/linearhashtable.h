#ifndef LINEARHASHTABLE_H
#define LINEARHASHTABLE_H

#include "hashtable.h"

class LinearHashTable : public HashTable
{
protected:
    int colisionFunction(int index, int& counter) override
    {
        ++counter;
        return (index + counter) % size;
    }

public:
    LinearHashTable(int size) : HashTable(size) {}
};

#endif // LINEARHASHTABLE_H
