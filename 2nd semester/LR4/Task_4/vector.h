#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>
#include <initializer_list>
#include <QDebug>
#include "iterator.h"

template <typename T>
class Vector
{
    using int8_t = __int8_t;
private:
    T* arr_ = nullptr;
    size_t sz_ = 0;
    size_t cap_ = 0;

public:
    Vector()
    {
        arr_ = nullptr;
        sz_ = 0;
        cap_ = 0;
        reserve(1);
    }
    Vector(size_t n)
    {
        reserve(n);
        sz_ = n;
        for (size_t i = 0; i < n; i++) {
            new (arr_ + i) T();
        }
    }
    Vector(size_t n, const T& value = T()) {
        reserve(n);
        sz_ = n;
        for (size_t i = 0; i < n; i++) {
            new (arr_ + i) T(value);
        }
    }
    Vector(const Vector<T>& other)
    {
        sz_ = other.sz_;
        cap_ = other.cap_;
        arr_ = reinterpret_cast<T*>(new int8_t[cap_ * sizeof(T)]);
        for (size_t i = 0; i < sz_; i++) {
            new (arr_ + i) T(other[i]);
        }
    }

    Vector(Vector<T> &&other){
        arr_ = std::move(other.arr_);
        sz_ = other.sz_;
        cap_ = other.cap_;
        other.arr_ = nullptr;
        other.sz_ = 0;
        other.cap_ = 0;
    }

    Vector(std::initializer_list<T> list) {
        reserve(list.size());
        sz_ = list.size();
        auto list_iter = list.begin();
        for (size_t i = 0; i < sz_; i++) {
            T temp = *list_iter;
            new (arr_ + i) T(std::move(temp));
            ++list_iter;
        }
    }
    ~Vector()
    {
        for (size_t i = 0; i < sz_; i++) {
            (arr_ + i)->~T();
        }
        delete[] reinterpret_cast<int8_t*>(arr_);
        arr_ = nullptr;
        cap_ = 0;
        sz_ = 0;
    }

    Vector<T>& operator=(const Vector<T> &other) {
        arr_ = other.arr_;
        sz_ = other.sz_;
        cap_ = other.cap_;
    }

    void assign(size_t count, const T& value)
    {
        clear();
        resize(count, value);
    }
    void assign(Iterator<T> begin, Iterator<T> end)
    {
        clear();
        size_t sz = begin.toPointer() - end.toPointer();
        resize(sz);
        for (size_t i = 0; i < sz; i++) {
            new(arr_ + i) T(*(begin + i));
        }
    }

    T& at(size_t pos)
    {
        if (pos >= sz_)
            throw "Out of range!";
        return arr_[pos];
    }
    T& operator[](size_t pos)
    {
        return arr_[pos];
    }
    T& operator[](size_t pos) const
    {
        return arr_[pos];
    }
    T& front()
    {
        return arr_[0];
    }
    T* data()
    {
        return arr_;
    }
    T& back()
    {
        return arr_[sz_ - 1];
    }

    Iterator<T> begin()
    {
        return Iterator<T>(arr_);
    }
    ReverseIterator<T> rbegin()
    {
        return ReverseIterator<T>(arr_ + sz_);
    }
    Iterator<const T> cbegin() const
    {
        return Iterator<const T>(arr_);
    }
    Iterator<T> end()
    {
        return Iterator<T>(arr_ + sz_);
    }
    ReverseIterator<T> rend()
    {
        return ReverseIterator<T>(arr_);
    }
    Iterator<const T> cend() const
    {
        return Iterator<const T>(arr_ + sz_);
    }

    bool empty() const
    {
        return sz_ == 0;
    }
    size_t size() const
    {
        return sz_;
    }
    size_t max_size() const
    {
        return INT64_MAX / sizeof(T);
    }
    void reserve(size_t n)
    {
        if (n <= cap_) return;
        T* newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
        for (size_t i = 0; i < sz_; i++) {
            new (newarr + i) T(arr_[i]);
        }
        for (size_t i = 0; i < sz_; i++) {
            (arr_ + i)->~T();
        }
        delete[] reinterpret_cast<int8_t*>(arr_);
        arr_ = newarr;
        cap_ = n;
    }
    size_t capacity() const
    {
        return cap_;
    }

    void clear()
    {
        resize(0);
    }
    Iterator<T> insert(Iterator<const T> pos, const T& value)
    {
        return insert(pos, 1, value);
    }
    Iterator<T> insert(Iterator<const T> pos, size_t count, const T& value)
    {
        if (count == 0) {
            return Iterator<T>((T*)pos.toPointer());
            //return Iterator<T>(begin());
        }
        size_t place = pos.toPointer() - arr_;
        reserve(sz_ + count);
        sz_ += count;
        for (size_t i = sz_ - 1; i >= place + count; i--) {
            new (arr_ + i) T(arr_[i - count]);
            (arr_ + i - count)->~T();
        }
        for (size_t i = 0; i < count; i++) {
            new (arr_ + place + i) T(value);
        }
        return Iterator<T>(arr_ + place);
    }
    template<typename ... Args>
    inline void emplace(Iterator<const T> pos, Args &&... args)
    {
        T temp(args...);
        insert(pos, temp);
    }
    template<typename ... Args>
    inline void emplace_back(Args &&... args) {
        T temp(args...);
        push_back(temp);
    }
    Iterator<T> erase(Iterator<T> pos)
    {
        return erase(pos, pos + 1);
    }
    Iterator<T> erase(Iterator<T> first, Iterator<T> last)
    {
        size_t f = first.toPointer() - arr_;
        size_t l = last.toPointer() - arr_;
        if (l == f) {
            return last;
        }
        for (size_t i = f; i < sz_ - l + f; i++) {
            (arr_ + i)->~T();
            new (arr_ + i) T(arr_[i + l - f]);
        }
        sz_ += f - l;
        return Iterator(arr_ + f);
    }
    void push_back(const T& value)
    {
        if (sz_ >= cap_) {
            reserve(2 * cap_);
        }
        new (arr_ + sz_) T(value);
        ++sz_;
    }
    void pop_back()
    {
        if (empty())
            throw "Vector is empty!";
        --sz_;
        (arr_ + sz_)->~T();
    }
    void resize(size_t n, const T& value = T())
    {
        if (n > cap_) reserve(n);
        for (size_t i = sz_; i < n; i++) {
            new (arr_ + i) T(value);
        }
        for (size_t i = n; i < sz_; i++) {
            (arr_ + i)->~T();
        }
        sz_ = n;
    }
    void swap(Vector<T>& other)
    {
        T* temp_arr = arr_;
        arr_ = other.arr_;
        other.arr_ = temp_arr;

        size_t temp_sz = sz_;
        sz_ = other.sz_;
        other.sz_ = temp_sz;

        size_t temp_cap = cap_;
        cap_ = other.cap_;
        other.cap_ = temp_cap;
    }

};

#endif // VECTOR_H
