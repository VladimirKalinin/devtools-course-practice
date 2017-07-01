// Copyright 2017 Gvozdeva Viktoriia

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

const int MAX_SIZE = 1000000;

template <typename valType>
class Queue {
 public:
    explicit Queue(int _max_size = 10);
    ~Queue();
    Queue(const Queue &);
    bool IsFull() const;
    bool operator==(const Queue<valType>&) const;
    Queue<valType>& operator=(const Queue<valType>&);
    bool IsEmpty() const;
    void Push(const valType&);
    valType Pop();
    valType Top();

 private:
    int head_, tail_, len_, max_size_;
    valType *queue_ptr_;
};

template <class valType>
Queue <valType> ::Queue(int _max_size) {
    if ((_max_size > 0) || (_max_size > MAX_SIZE)) {
        max_size_ = _max_size;
    } else if (_max_size > MAX_SIZE) {
        max_size_ = MAX_SIZE;
    } else {
        throw "Size is incorrect!";
    }
    queue_ptr_ = new valType[max_size_];
    if (queue_ptr_ == nullptr) throw "Memory was not allocated";
    len_ = 0;
    head_ = 0;
    tail_ = -1;
}

template <class valType>
Queue <valType> ::Queue(const Queue& Q) {
    max_size_ = Q.max_size_;
    head_ = Q.head_;
    tail_ = Q.tail_;
    len_ = Q.len_;
    queue_ptr_ = new valType[max_size_];
    if (queue_ptr_ == nullptr) throw "Memory was not allocated";
    for (int i = 0; i <= len_; i++)
       queue_ptr_[i] = Q.queue_ptr_[i];
}

template <class valType>
Queue<valType> :: ~Queue() {
    delete[] queue_ptr_;
    queue_ptr_ = nullptr;
}
template <class valType>
bool Queue<valType> :: operator==(const Queue<valType>& Q) const {
    if (this == &Q) return true;
    if (len_ != Q.len_) return false;
    for (int i = 0; i < len_; i++) {
       if (queue_ptr_[i] != Q.queue_ptr_[i])
            return false;
    }
    return true;
}

template <class valType>
Queue<valType>& Queue<valType> :: operator=(const Queue<valType>& Q) {
    if (max_size_ != Q.max_size_) {
        delete[] queue_ptr_;
        queue_ptr_ = new valType[Q.max_size_];
    }
    max_size_ = Q.max_size_;
    head_ = Q.head_;
    tail_ = Q.tail_;
    len_ = Q.len_;
    for (int i = 0; i <= len_; i++)
        queue_ptr_[i] = Q.queue_ptr_[i];
    return *this;
}

template <class valType>
bool Queue <valType> ::IsFull() const {
    return (len_ == max_size_);
}

template <class valType>
bool Queue <valType> ::IsEmpty() const {
    return  (len_ == 0);
}

template <class valType>
void Queue <valType> ::Push(const valType &elem) {
    if (queue_ptr_ == nullptr) throw "Queue was deleted!";
    if (IsFull()) {
        throw "Queue is full!";
    } else {
        if (tail_ == max_size_ - 1) {
            tail_ = 0;
        } else {
            tail_++;
            queue_ptr_[tail_] = elem;
            len_++;
        }
    }
}

template <class valType>
valType Queue <valType> ::Pop() {
    if (queue_ptr_ == nullptr) throw "Queue was deleted!";
    if (IsEmpty()) {
        throw "Queue is empty!";
    } else {
        valType elem = queue_ptr_[head_];
        if (head_ == max_size_ - 1) {
            head_ = 0;
        } else {
            head_--;
        }
        len_--;
        return elem;
    }
}

template <class valType>
valType Queue <valType> ::Top() {
    if (queue_ptr_ == nullptr) throw "Queue was deleted!";
    if (IsEmpty()) {
        throw "Queue is empty!";
    } else {
        return queue_ptr_[head_];
    }
}

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
