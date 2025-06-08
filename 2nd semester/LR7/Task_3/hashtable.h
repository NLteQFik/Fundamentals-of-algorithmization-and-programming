#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include "stack.h"

template<typename T>
class HashTable
{
protected:
    QVector<Stack<T>> table;
    int size;

    int hashFunction(int key) {
        return (key + size - 1) % size;
    }
public:
    HashTable(int num)
    {
        size = num;
        table.resize(num);
    }

    void Insert(int key, const T& value)
    {
        table[hashFunction(key)].push(value);
    }
    void Insert(int key, T&& value)
    {
        table[hashFunction(key)].push(std::move(value));
    }

    T& Get(int key)
    {
        if (table[hashFunction(key)].empty())
            return T();
        return table[hashFunction(key)].Top();
    }

    void Remove(int key)
    {
        if (table[hashFunction(key)].empty())
            return;
        table[hashFunction(key)].pop();
    }
};

#endif // HASHTABLE_H
