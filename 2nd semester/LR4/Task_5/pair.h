#ifndef PAIR_H
#define PAIR_H

#include "vector.h"
#include <initializer_list>

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;
    ~Pair()
    {
    }
    Pair() = default;
    Pair(T1& first, T2& second) : first(first), second(second)
    {
    }
    Pair(const T1& first, const T2& second) : first(first), second(second)
    {
    }
    Pair(T1&& first, T2&& second) : first(std::move(first)), second(std::move(second))
    {
    }
    Pair(const Pair& other) : first(other.first), second(other.second)
    {
    }
    template <typename U1, typename U2>
    Pair(const Pair<U1,U2>& other) : first(other.first), second(other.second)
    {
    }

    Pair& operator=(const Pair& other) {
        this->first = other.first;
        this->second = other.second;
        return *this;
    }
    Pair& operator=(Pair&& other) {
        this->first = std::move(other.first);
        this->second = std::move(other.second);
        return *this;
    }
    template <typename U1, typename U2>
    Pair& operator=(const Pair<U1,U2> &other)
    {
        this->first = other.first;
        this->second = other.second;
        return *this;
    }

    void swap(Pair& other)
    {
        T1 temp1 = first;
        first = other.first;
        other.first = temp1;

        T2 temp2 = second;
        second = other.second;
        other.second = temp2;
    }


};

#endif // PAIR_H
