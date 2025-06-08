#ifndef QUEUE_H
#define QUEUE_H

#include <initializer_list>
#include <utility>
#include <cstdio>

template<typename T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node* next = nullptr;

        Node(const T &value = T(), Node* next = nullptr) : value(value), next(next) {}
        Node(T &&value, Node* next = nullptr) : value(std::move(value)), next(next) { value = T(); }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    Queue(const Queue& other)
    {
        Node* current = other.head;
        while (current) {
            push(current->value);
            current = current->next;
        }
    }
    Queue(Queue&& other) : head(std::move(other.head)), tail(std::move(other.tail))
    {
        other.head = nullptr;
        other.tail = nullptr;
    }
    Queue(std::initializer_list<T> list) {
        for (auto it : list) {
            push(*it);
        }
    }

    bool empty() const
    {
        return !head;
    }

    T& front() const
    {
        if (!head) {
            throw "Queue is empty";
        }
        return head->value;
    }

    T& back() const {
        if (!tail) {
            throw "Queue is empty";
        }
        return tail->value;
    }

    size_t size() const
    {
        size_t count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    void push(const T& value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    void push(T&& value)
    {
        Node* newNode = new Node(std::move(value));
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    template<typename... Args >
    void emplace(Args&&... args)
    {
        T temp(args...);
        push(temp);
    }

    void pop()
    {
        if (!head) throw "Queue is empty";
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void swap(Queue& other) noexcept
    {
        Queue temp = std::move(*this);
        *this = std::move(other);
        other = std::move(temp);
    }
};

#endif // QUEUE_H
