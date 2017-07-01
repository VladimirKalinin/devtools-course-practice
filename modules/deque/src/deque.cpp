// Copyright 2017 Vinogradova Ekaterina

#include "include/deque.h"

Deque::Deque(int size) : front_(-1), back_(0) {
    data_count_ = 0;
    mem_size_ = size;
    if (size < 0)
        throw "DataErr";
    else if (size == 0)
        memory_ = nullptr;
    else
        memory_ = new Elem[mem_size_];
}

Deque::~Deque() {
    delete[] memory_;
    memory_ = nullptr;
}

int Deque::GetNextFrontIndex(int index) {
    return ++index % mem_size_;
}

int Deque::GetNextBackIndex(int index) {
    return (index == 0) ? mem_size_ - 1 : --index;
}

void Deque::InsFront(Elem element) {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsFull()) {
        throw "DataFull";
    } else {
        front_ = GetNextFrontIndex(front_);
        memory_[front_] = element;
        data_count_++;
    }
}

void Deque::InsBack(Elem element) {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsFull()) {
        throw "DataFull";
    } else {
        back_ = GetNextBackIndex(back_);
        memory_[back_] = element;
        data_count_++;
    }
}

Elem Deque::GetFront() {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsEmpty()) {
        throw "DataEmpty";
    } else {
        data_count_--;
        Elem tmp = memory_[front_];
        front_ = GetNextBackIndex(front_);
        return tmp;
    }
}

Elem Deque::GetBack() {
    if (memory_ == nullptr) {
        throw "DataNoMem";
    } else if (IsEmpty()) {
        throw "DataEmpty";
    } else {
        data_count_--;
        Elem tmp = memory_[back_];
        back_ = GetNextFrontIndex(back_);
        return tmp;
    }
}

bool Deque::IsEmpty(void) const {
    return data_count_ == 0;
}

bool Deque::IsFull(void) const {
    return data_count_ == mem_size_;
}
