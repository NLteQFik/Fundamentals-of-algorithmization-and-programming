#ifndef STACK_H
#define STACK_H

#include <initializer_list>
#include <utility>
#include <cstdio>
#include <QDebug>

template<typename T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node* next = nullptr;

        Node(const T &value = T(), Node* next = nullptr) : value(value), next(next) {}
        Node(T &&value, Node* next = nullptr) : value(std::move(value)), next(next) { value = T(); }
    };

    Node* top = nullptr;

public:
    Stack() : top(nullptr) {}
    Stack(const Stack& other)
    {
        Node* current = other.top;
        while (current) {
            push(current->value);
            current = current->next;
        }
    }
    Stack(Stack&& other) : top(std::move(other.top))
    {
        other.top = nullptr;
    }
    Stack(std::initializer_list<T> list) {
        for (auto it : list) {
            push(*it);
        }
    }

    bool empty() const
    {
        return !top;
    }

    T& Top() const
    {
        if (!top) {
            throw "Stack is empty";
        }
        return top->value;
    }

    size_t size() const
    {
        size_t count = 0;
        Node* current = top;
        if (!top)
            return 0;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    void push(const T& value)
    {
        Node* newNode = new Node(value);
        if (top) {
            newNode->next = top;
        }
        top = newNode;
    }
    void push(T&& value)
    {
        Node* newNode = new Node(std::move(value));
        if (top) {
            newNode->next = top;
        }
        top = newNode;
    }

    template<typename... Args >
    void emplace(Args&&... args)
    {
        T temp(args...);
        push(temp);
    }

    void pop()
    {
        if (!top) throw "Stack is empty";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void swap(Stack& other) noexcept
    {
        Stack temp = std::move(*this);
        *this = std::move(other);
        other = std::move(temp);
    }
};

#endif // STACK_H
