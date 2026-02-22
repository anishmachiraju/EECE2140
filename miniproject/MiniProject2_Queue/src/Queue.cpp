#include "Queue.h"

Queue::Queue(std::size_t capacity)
    : data_(nullptr), capacity_(capacity), front_index_(0), rear_index_(0), count_(0) {
    if (capacity_ == 0) {
        throw std::invalid_argument("Capacity must be > 0");
    }
    data_ = new int[capacity_];
}

Queue::~Queue() {
    delete[] data_;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        throw std::overflow_error("enqueue on full queue");
    }
    data_[rear_index_] = item;
    rear_index_ = (rear_index_ + 1) % capacity_;
    ++count_;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("dequeue on empty queue");
    }
    int value = data_[front_index_];
    front_index_ = (front_index_ + 1) % capacity_;
    --count_;
    return value;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::underflow_error("front on empty queue");
    }
    return data_[front_index_];
}

bool Queue::isEmpty() const {
    return count_ == 0;
}

bool Queue::isFull() const {
    return count_ == capacity_;
}

std::size_t Queue::size() const {
    return count_;
}

void Queue::clear() {
    front_index_ = 0;
    rear_index_ = 0;
    count_ = 0;
}

void Queue::print() const {
    if (isEmpty()) {
        std::cout << "[empty]\n";
        return;
    }
    std::cout << "Front -> ";
    std::size_t idx = front_index_;
    for (std::size_t i = 0; i < count_; ++i) {
        std::cout << data_[idx];
        if (i + 1 < count_) std::cout << " | ";
        idx = (idx + 1) % capacity_;
    }
    std::cout << " <- Rear\n";
}
