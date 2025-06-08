#include "hashtable.h"

int HashTable::hashFunction(int key) {
    //return (a * key + b) % prime % size;
    return key % size;
}

int HashTable::colisionFunction(int index, int &counter) {
    ++counter;
    return (index + counter) % size;
}

HashTable::HashTable(int size) {
    this->size = size;
    table.resize(size);
    prime = 10037;
    a = QRandomGenerator::global()->bounded(1, prime - 1);
    b = QRandomGenerator::global()->bounded(0, prime - 1);
}

bool HashTable::Insert(int key, int value)
{
    int index = hashFunction(key);
    int counter = 0;
    while (table[index].first != 0 && counter < size) {
        index = colisionFunction(index, counter);
    }
    if (counter == size)
        return false;
    table[index] = qMakePair(key, value);
    return true;
}

int HashTable::Find(int key)
{
    int index = hashFunction(key);
    int counter = 0;
    while (table[index].first != key && table[index].first != 0 && counter < size) {
        index = colisionFunction(index, counter);
    }
    if (table[index].first == key)
        return table[index].second;
    return -1;
}

bool HashTable::Remove(int key)
{
    int index = hashFunction(key);
    int counter = 0;
    while (table[index].first != key && table[index].first != 0 && counter < size) {
        index = colisionFunction(index, counter);
    }
    if (table[index].first != key)
        return false;
    table[index] = qMakePair(-1, 0);
    return true;
}
