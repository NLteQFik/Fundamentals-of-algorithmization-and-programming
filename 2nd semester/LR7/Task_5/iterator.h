#ifndef ITERATOR_H
#define ITERATOR_H

#include "deque.h"

template <typename T>
class Iterator
{
    friend class Deque<T>;
private:
    Deque<T>* deque_;
    size_t pos_;

public:
    Iterator(Deque *deque) : deque_(deque), pos_(0) {}
    Iterator(Deque *deque, size_t pos = 0) : deque_(deque), pos_(pos) {}
    Iterator(const Iterator& other) : deque_(other.deque_), pos_(other.pos_) {}
    Iterator(Iterator&& other) : deque_(other.deque_), pos_(other.pos_)
    {
        other.deque_ = nullptr;
        pos_ = 0;
    }

    T& operator*() const
    {
        return deque_->at(pos_);
    }

    Iterator& operator++() {
        ++pos_;
        return *this;
    }
    Iterator& operator--() {
        --pos_;
        return *this;
    }
    Iterator operator++(int) {
        Iterator temp = *this;
        ++*this;
        return temp;
    }
    Iterator operator--(int) {
        Iterator temp = *this;
        --*this;
        return temp;
    }

    Iterator operator+(size_t n) {
        return Iterator(deque_, pos_ + n);
    }
    Iterator operator-(size_t n) {
        return Iterator(deque_, pos_ - n);
    }
    Iterator& operator+=(size_t n) {
        pos_ += n;
        return *this;
    }
    Iterator& operator-=(size_t n) {
        pos_ -= n;
        return *this;
    }

    size_t operator-(const Iterator& other) {
        return pos_ - other.pos_;
    }

    bool operator==(const Iterator &other) {
        return pos_ == other.pos_;
    }
    bool operator!=(const Iterator &other) {
        return pos_ != other.pos_;
    }
};

#endif // ITERATOR_H
