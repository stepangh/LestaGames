#pragma once
#include <vector>

template<class T>
class CircularBufferVector {

public:
    CircularBufferVector(int size)
        : capacity_(size), tail_(0), head_(0), 
        full_(false), buffer_(std::vector<T>(size, T())) {}

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
        buffer_[head_] = T();
        head_ = (head_ + 1) % capacity_;
        full_ = false;
        return result;
    }

    void Resize(int new_capacity) {
        std::vector<T> new_buffer(new_capacity, T());
        for (int i = 0; i < new_capacity; i++) {
            new_buffer[i] = i < capacity_ ? buffer_[i] : T();
        }
        buffer_ = new_buffer;
        capacity_ = new_capacity;
        head_ = 0;
        tail_ = full_ ? 0 : capacity_ - 1;
    }

    void Print() const
    {
        for (const T& item : buffer_) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

private:
    size_t capacity_;
    size_t head_;
    size_t tail_;
    bool full_;
    std::vector<T> buffer_;
};
