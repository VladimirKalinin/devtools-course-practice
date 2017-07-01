// Copyright 2017 Anna Mironova

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack {
 public:
    explicit TStack(int _size = MAX_STACK_SIZE);
    TStack(const TStack &v);
    ~TStack();

    int GetStackSize() const;
    int GetStackTop() const;
    void Push(const ValType elem);
    ValType Pop();
    ValType StTop();
    bool CheckFull() const;
    bool CheckEmpty() const;

    TStack& operator=(const TStack& s);

 private:
    ValType *p_vector_;
    int size_;
    int top_;
};

template <class ValType>
TStack<ValType>::TStack(int _size) {
    if (_size < 0) {
        throw "Negative size";
    } else if (_size > MAX_STACK_SIZE) {
        throw "Size more than MAX_VECTOR_SIZE";
    } else {
        top_ = -1;
        size_ = _size;
        p_vector_ = new ValType[size_];
    }
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType > &v) {
    size_ = v.GetStackSize();
    top_ = v.GetStackTop();
    p_vector_ = new ValType[size_];
    for (int i = 0; i < top_; i++)
        p_vector_[i] = v.p_vector_[i];
}

template <class ValType>
TStack<ValType>::~TStack() {
    if (p_vector_ != NULL) {
        delete[]p_vector_;
    }
}

template <class ValType>
int TStack<ValType>::GetStackSize()const {
    return size_;
}

template <class ValType>
int TStack<ValType>::GetStackTop()const {
    return top_;
}

template <class ValType>
void TStack<ValType>::Push(const ValType elem) {
    if (this->CheckFull()) {
        throw "Full stack";
    } else {
        top_++;
        p_vector_[top_] = elem;
    }
}

template <class ValType>
ValType TStack<ValType>::Pop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        ValType res;
        res = p_vector_[top_];
        top_--;
        return res;
    }
}

template <class ValType>
ValType TStack<ValType>::StTop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        return p_vector_[top_];
    }
}

template <class ValType>
bool TStack<ValType>::CheckFull() const {
    if (top_ == size_ - 1) {
        return true;
    } else {
        return false;
    }
}

template <class ValType>
bool TStack<ValType>::CheckEmpty() const {
    if (top_ == (-1)) {
        return true;
    } else {
        return false;
    }
}

template <class ValType>
TStack<ValType>& TStack<ValType>::operator=(const TStack<ValType>& s) {
    if (p_vector_ == s.p_vector_) {
        return *this;
    }
    size_ = s.size_;
    top_ = s.top_;
    delete[]p_vector_;
    p_vector_ = new ValType[size_];
    for (int i = 0; i < size_; i++) {
        p_vector_[i] = s.p_vector_[i];
    }
    return *this;
}
#endif  //  MODULES_STACK_INCLUDE_STACK_H_
