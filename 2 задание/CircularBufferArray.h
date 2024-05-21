#pragma once
#include <iostream>

template<class T>
class CircularBufferArray {

public:
    CircularBufferArray(int size)
        : capacity_(size), tail_(0), head_(0), full_(false) {
        buffer_ = new T[capacity_];
        for (size_t i = 0; i < capacity_; i++) {
            buffer_[i] = 0;
        }
    }

    ~CircularBufferArray() {
        delete[] buffer_;
    }

    size_t length() {
        return capacity_;
    }

    bool IsEmpty() const {
        return (!full_ && (head_ == tail_));
    }

    bool IsFull() const
    {
        return full_;
    }

    void Push_front(const T& value) {
        if (full_) {
            throw std::runtime_error("Buffer is full");
        }
        head_ = (head_ + capacity_ - 1) % capacity_;
        buffer_[head_] = value;
        full_ = head_ == tail_;
    }

    void Push_back(const T& value) {
        if (full_) {
            throw std::runtime_error("Buffer is full");
        }
        buffer_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
        full_ = head_ == tail_;
    }

    T Pop_back() {
        if (IsEmpty()) {
            throw std::runtime_error("Buffer is empty");
        }
        tail_ = (tail_ + capacity_ - 1) % capacity_;
        T result = buffer_[tail_];
        buffer_[tail_] = T();
        full_ = false;
        return result;
    }

    T Pop_front() {
        if (IsEmpty()) {
            throw std::runtime_error("Buffer is empty");
        }
        T result = buffer_[head_];
        buffer_[head_] = 0;
        head_ = (head_ + 1) % capacity_;
        full_ = false;
        return result;
    }

    void Resize(int new_capacity) {
        T* new_buffer = new T[new_capacity];
        for (int i = 0; i < new_capacity; i++) {
            new_buffer[i] = i < capacity_ ? buffer_[i] : 0;
        }
        delete[] buffer_;
        buffer_ = new_buffer;
        capacity_ = new_capacity;
    }

    void Print() const
    {
        for (int i = 0; i < capacity_; i++) {
            std::cout << buffer_[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    size_t capacity_;
    size_t head_;
    size_t tail_;
    bool full_;
    T* buffer_;
};