#ifndef DEQUE_H
#define DEQUE_H

#pragma once

#include <initializer_list>
#include <utility>
#include <cstdio>
// #include "iterator.h"

template <typename T>
class Deque
{
    using int8_t = __int8_t;
private:
    static const size_t BLOCK_SIZE = 4;
    struct Block {
        T arr_[BLOCK_SIZE];
    };

    Block** blocks_;
    size_t block_amount_;
    size_t begin_;
    size_t size_;

public:
    Deque() : blocks_(nullptr), block_amount_(0), begin_(0), size_(0) {}
    Deque(size_t n) : block_amount_(0), begin_(0), size_(n)
    {
        // blocks_ = new Block*[block_amount_];
        // size_t current_block_size = BLOCK_SIZE;
        // for (size_t i = 0; i < block_amount_; i++)
        // {
        //     blocks_[i] = reinterpret_cast<Block*>(new int8_t[sizeof(Block)]);
        //     if (i == block_amount_ - 1)
        //         current_block_size = n - i * BLOCK_SIZE;
        //     for (size_t j = 0; j < current_block_size; j++) {
        //         new (blocks_[i]->arr_ + j) T();
        //     }
        // }
        reserve(n);
        for (int i = 0; i < n; i++)
            new (blocks_[i / BLOCK_SIZE]->arr_ + i % BLOCK_SIZE) T();
    }
    Deque(size_t n, T& value = T()) : block_amount_(0), begin_(0), size_(n)
    {
        reserve(n);
        for (int i = 0; i < n; i++)
            new (blocks_[i / BLOCK_SIZE]->arr_ + i % BLOCK_SIZE) T(value);
    }
    Deque(const Deque& other) : block_amount_(0), begin_(other.begin_), size_(other.size_)
    {
        // blocks_ = new Block*[block_amount_];
        // size_t current_block_size = BLOCK_SIZE;
        // for (size_t i = 0; i < block_amount_; i++)
        // {
        //     blocks_[i] = reinterpret_cast<Block*>(new int8_t[sizeof(Block)]);
        //     if (i == block_amount_ - 1)
        //         current_block_size = n - i * BLOCK_SIZE;
        //     for (size_t j = 0; j < current_block_size; j++) {
        //         new (blocks_[i]->arr_ + j) T(*(other.blocks_[i]->arr_ + j));
        //     }
        // }
        reserve(other.block_amount_ * BLOCK_SIZE);
        for (int i = 0; i < other.size_; i++)
            new (blocks_[i / BLOCK_SIZE]->arr_ + i % BLOCK_SIZE) T(*(blocks_[i / BLOCK_SIZE]->arr_ + i % BLOCK_SIZE));
    }
    Deque(Deque&& other) : block_amount_(other.block_amount_), begin_(other.begin_), size_(other.size_), blocks_(std::move(other.blocks_))
    {
        other.blocks_ = nullptr;
        other.block_amount_ = 0;
        other.size_ = 0;
        other.begin_ = 0;
    }
    Deque(std::initializer_list<T> list) : block_amount_(0), begin_(0), size_(list.size())
    {
        reserve(size_);
        for (int i = 0; i < size_; i++)
            new (blocks_[i / BLOCK_SIZE]->arr_ + i % BLOCK_SIZE) T(list[i]);
    }

    T& at(size_t pos)
    {
        if (pos >= size_ || pos < 0)
            throw "Out of range!";
        pos += begin_;
        if (pos >= block_amount_ * BLOCK_SIZE)
            pos -= block_amount_ * BLOCK_SIZE;
        return blocks_[pos / BLOCK_SIZE]->arr_[pos % BLOCK_SIZE];
    }
    const T& at(size_t pos) const
    {
        return at(pos);
    }

    T& operator[](size_t pos)
    {
        pos += begin_;
        if (pos >= block_amount_ * BLOCK_SIZE)
            pos -= block_amount_ * BLOCK_SIZE;
        return blocks_[pos / BLOCK_SIZE]->arr_[pos % BLOCK_SIZE];
    }
    const T& operator[](size_t pos) const
    {
        return operator[](pos);
    }

    bool empty() const
    {
        return size_ <= 0;
    }

    size_t size() const
    {
        return size_;
    }

    void clear()
    {
        for (int i = 0; i < size_; i++)
            (blocks_[((i + begin_) % block_amount_ * BLOCK_SIZE) / BLOCK_SIZE]->arr_ + ((i + begin_) % block_amount_ * BLOCK_SIZE) % BLOCK_SIZE)->~T();
        size_ = 0;
        begin_ = 0;
    }

    void push_back(const T& value)
    {
        if ((begin_ + size_ + 1) / BLOCK_SIZE == begin_ / BLOCK_SIZE + block_amount_)
            reserve((block_amount_ + 1) * BLOCK_SIZE);
        size_t pos = begin_ + size_;
        if (pos >= block_amount_ * BLOCK_SIZE)
            pos -= block_amount_ * BLOCK_SIZE;
        new (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE) T(value);
        ++size_;
    }
    void push_back(T&& value)
    {
        if ((begin_ + size_ + 1) / BLOCK_SIZE == begin_ / BLOCK_SIZE + block_amount_)
            reserve((block_amount_ + 1) * BLOCK_SIZE);
        size_t pos = begin_ + size_;
        if (pos >= block_amount_ * BLOCK_SIZE)
            pos -= block_amount_ * BLOCK_SIZE;
        new (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE) T(std::move(value));
        ++size_;
    }

    void pop_back()
    {
        if (!size_)
            throw "Empty deque";
        size_t pos = begin_ + size_ - 1;
        if (pos >= block_amount_ * BLOCK_SIZE)
            pos -= block_amount_ * BLOCK_SIZE;
        (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE)->~T();
        --size_;
    }

    void push_front(const T& value)
    {
        if ((begin_ + size_ + 1) / BLOCK_SIZE == begin_ / BLOCK_SIZE + block_amount_)
            reserve((block_amount_ + 1) * BLOCK_SIZE);
        size_t pos = begin_;
        if (pos <= 0)
            pos += block_amount_ * BLOCK_SIZE;
        pos -= 1;
        new (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE) T(value);
        ++size_;
        begin_ = pos;
    }
    void push_front(T&& value)
    {
        if ((begin_ + size_ + 1) / BLOCK_SIZE == begin_ / BLOCK_SIZE + block_amount_)
            reserve((block_amount_ + 1) * BLOCK_SIZE);
        size_t pos = begin_;
        if (pos <= 0)
            pos += block_amount_ * BLOCK_SIZE;
        pos -= 1;
        new (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE) T(std::move(value));
        ++size_;
        begin_ = pos;
    }

    void pop_front()
    {
        if (!size_)
            throw "Empty deque";
        size_t pos = begin_;
        (blocks_[pos / BLOCK_SIZE]->arr_ + pos % BLOCK_SIZE)->~T();
        --size_;
        begin_ += 1;
        if (begin_ >= BLOCK_SIZE * block_amount_)
            begin_ -= BLOCK_SIZE * block_amount_;
    }

    void reserve(size_t count)
    {
        if (count <= block_amount_ * BLOCK_SIZE)
            return;
        size_t begin_block = begin_ / 4;
        begin_ %= 4;
        size_t new_block_amount = (count + 3) / 4;
        Block** new_blocks = new Block*[new_block_amount];
        for (size_t i = 0; i < block_amount_; i++)
        {
            new_blocks[i] = blocks_[(i + begin_block) % block_amount_];
            blocks_[(i + begin_block) % block_amount_] = nullptr;
        }
        delete[] blocks_;
        blocks_ = new_blocks;
        //size_t current_block_size = BLOCK_SIZE;
        for (size_t i = block_amount_; i < new_block_amount; i++)
        {
            blocks_[i] = reinterpret_cast<Block*>(new int8_t[sizeof(Block)]);
        }
        block_amount_ = new_block_amount;
    }

    void swap(Deque& other)
    {
        Block** temp_blocks = blocks_;
        blocks_ = other.blocks_;
        other.blocks_ = temp_blocks;

        size_t temp_size = size_;
        size_ = other.size_;
        other.size_ = temp_size;

        size_t temp_amount = block_amount_;
        block_amount_ = other.block_amount_;
        other.block_amount_ = temp_amount;

        size_t temp_begin = begin_;
        begin_ = other.begin_;
        other.begin_ = temp_begin;
    }

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

    Iterator begin()
    {
        return Iterator(this, 0);
    }
    Iterator end()
    {
        return Iterator(this, size_);
    }
};

#endif // DEQUE_H
