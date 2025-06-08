#ifndef HASHTABLE_H
#define HASHTABLE_H

#pragma once

#include <QRandomGenerator>
#include <QVector>
#include <QPair>

class HashTable
{
protected:
    QVector<QPair<int, int>> table;
    int size;
    int a, b, prime;

    int hashFunction(int key);

    virtual int colisionFunction(int index, int& counter);

public:
    HashTable(int size);

    bool Insert(int key, int value);

    int Find(int key);

    bool Remove(int key);
};

#endif // HASHTABLE_H
