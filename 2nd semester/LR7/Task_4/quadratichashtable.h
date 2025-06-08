#ifndef QUADRATICHASHTABLE_H
#define QUADRATICHASHTABLE_H

#include "hashtable.h"

class QuadraticHashTable : public HashTable
{
protected:
    int colisionFunction(int index, int& counter) override
    {
        ++counter;
        return (index + counter * counter) % size;
    }

public:
    QuadraticHashTable(int size) : HashTable(size) {}
};

#endif // QUADRATICHASHTABLE_H
