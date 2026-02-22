#ifndef MINIPROJECT2_QUEUE_QUEUE_H
#define MINIPROJECT2_QUEUE_QUEUE_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

class Queue {
public:
    explicit Queue(std::size_t capacity);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    int front() const;
    bool isEmpty() const;
    bool isFull() const;
    std::size_t size() const;
    void clear();
    void print() const;

private:
    int* data_;
    std::size_t capacity_;
    std::size_t front_index_;
    std::size_t rear_index_;
    std::size_t count_;
};

#endif
