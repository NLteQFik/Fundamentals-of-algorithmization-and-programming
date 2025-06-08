#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstdio>

template <typename T>
class Iterator
{
private:
    T* iterator_;

public:
    explicit Iterator(T *obj)
    {
        iterator_ = obj;
    }
    ~Iterator() = default;

    T* toPointer()
    {
        return iterator_;
    }

    Iterator<T>& operator++()
    {
        ++iterator_;
        return *this;
    }
    Iterator<T>& operator--()
    {
        --iterator_;
        return *this;
    }
    Iterator<T> operator++(int)
    {
        Iterator temp = *this;
        ++*this;
        return temp;
    }
    Iterator<T> operator--(int)
    {
        Iterator temp = *this;
        --*this;
        return temp;
    }
    Iterator<T> operator+(int n)
    {
        return Iterator(iterator_ + n);
    }
    Iterator<T> operator-(int n)
    {
        return Iterator(iterator_ - n);
    }
    Iterator<T>& operator+=(int n)
    {
        iterator_ += n;
        return *this;
    }
    Iterator<T>& operator-=(int n)
    {
        iterator_ -= n;
        return *this;
    }

    T& operator*()
    {
        return *iterator_;
    }
    T& operator[](size_t n)
    {
        return *(iterator_ + n);
    }
};

template <typename T>
class ReverseIterator
{
    using Iterator = ReverseIterator;
private:
    T* iterator_;

public:
    explicit ReverseIterator(T *obj)
    {
        iterator_ = obj;
    }
    ~ReverseIterator() = default;

    T* toPointer()
    {
        return iterator_;
    }

    ReverseIterator<T>& operator++()
    {
        --iterator_;
        return *this;
    }
    ReverseIterator<T>& operator--()
    {
        ++iterator_;
        return *this;
    }
    ReverseIterator<T> operator++(int)
    {
        ReverseIterator temp = *this;
        --*this;
        return temp;
    }
    ReverseIterator<T> operator--(int)
    {
        ReverseIterator temp = *this;
        ++*this;
        return temp;
    }
    ReverseIterator<T> operator+(int n)
    {
        return Iterator(iterator_ - n);
    }
    ReverseIterator<T> operator-(int n)
    {
        return Iterator(iterator_ + n);
    }
    ReverseIterator<T>& operator+=(int n)
    {
        iterator_ -= n;
        return *this;
    }
    ReverseIterator<T>& operator-=(int n)
    {
        iterator_ += n;
        return *this;
    }

    T& operator*()
    {
        return *iterator_;
    }
    T& operator[](size_t n)
    {
        return *(iterator_ - n);
    }
};

#endif // ITERATOR_H
