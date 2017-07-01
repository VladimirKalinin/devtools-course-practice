// Copyright 2017 Grachev Vlad

#include <string>
#include "include/bit_array.h"

BitArray::BitArray(const int size) {
    if (size > 0) {
        size_ = size;
        nblocks_ = size / block_size_;
        nblocks_++;
        if (size % block_size_ == 0)
            nblocks_--;
        memory_blocks_ = new MemoryBlock[nblocks_];
        for (unsigned int i = 0; i < nblocks_; i++)
            memory_blocks_[i] = 0;
    } else {
        throw std::string("Incorrect array size");
    }
}



BitArray::BitArray(const BitArray& bit_array) {
    size_ = bit_array.size_;
    nblocks_ = bit_array.nblocks_;
    memory_blocks_ = new MemoryBlock[nblocks_];
    for (unsigned int i = 0; i < nblocks_; i++)
        memory_blocks_[i] = bit_array.memory_blocks_[i];
}



BitArray::~BitArray() {
    delete [] memory_blocks_;
    memory_blocks_ = nullptr;
}



BitArray& BitArray::operator = (const BitArray& bit_array) {
    if (this != &bit_array) {
        delete[] memory_blocks_;
        size_ = bit_array.size_;
        nblocks_ = bit_array.nblocks_;
        memory_blocks_ = new MemoryBlock[nblocks_];
        for (unsigned int i = 0; i < nblocks_; i++)
            memory_blocks_[i] = bit_array.memory_blocks_[i];
    }
    return *this;
}



unsigned int BitArray::GetSize() const {
    return size_;
}



unsigned int BitArray::GetBlockNumber
                       (const unsigned int global_bit_number) const {
    return global_bit_number / block_size_;
}



unsigned int BitArray::GetLocalBitNumber
                       (const unsigned int global_bit_number) const {
    return global_bit_number % block_size_;
}



MemoryBlock BitArray::GetMask
                      (const unsigned int global_bit_number) const {
    MemoryBlock mask = 1;
    mask <<= GetLocalBitNumber(global_bit_number);
    return mask;
}

void BitArray::SetBit(const unsigned int bit_number) {
    if (bit_number < size_) {
        memory_blocks_[GetBlockNumber(bit_number)] |= GetMask(bit_number);
    } else {
        throw std::string("Incorrect index");
    }
}



void BitArray::ClearBit(const unsigned int bit_number) {
    if (bit_number < size_) {
        memory_blocks_[GetBlockNumber(bit_number)] &= ~GetMask(bit_number);
    } else {
        throw std::string("Incorrect index");
    }
}


int BitArray::GetBit(const unsigned int bit_number) const {
    if (bit_number < size_) {
        int bit_value;
        int block_number = GetBlockNumber(bit_number);
        bit_value = memory_blocks_[block_number] & GetMask(bit_number);
        if (bit_value > 0)
            bit_value = 1;
        return bit_value;
    } else {
        throw std::string("Incorrect index");
    }
}



BitArray BitArray::operator & (const BitArray& bit_array) const {
    int size = size_;
    if (size_ < bit_array.size_)
        size = bit_array.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nblocks_; i++)
        tempBitArray.memory_blocks_[i] = memory_blocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nblocks_; i++)
        tempBitArray.memory_blocks_[i] &= bit_array.memory_blocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator | (const BitArray& bit_array) const {
    int size = size_;
    if (size_ < bit_array.size_)
        size = bit_array.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nblocks_; i++)
        tempBitArray.memory_blocks_[i] = memory_blocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nblocks_; i++)
        tempBitArray.memory_blocks_[i] |= bit_array.memory_blocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator ^ (const BitArray& bit_array) const {
    int size = size_;
    if (size_ < bit_array.size_)
        size = bit_array.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nblocks_; i++)
        tempBitArray.memory_blocks_[i] = memory_blocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nblocks_; i++)
        tempBitArray.memory_blocks_[i] ^= bit_array.memory_blocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator ~() const {
    BitArray tempBitArray(*this);

    for (unsigned int i = 0; i < tempBitArray.size_; i++) {
        if (GetBit(i) == 0) {
            tempBitArray.SetBit(i);
        } else {
            tempBitArray.ClearBit(i);
        }
    }

    return tempBitArray;
}



bool BitArray::operator == (const BitArray& bit_array) const {
    if (size_ == bit_array.size_) {
        for (unsigned int i = 0; i < nblocks_; i++)
        if (memory_blocks_[i] != bit_array.memory_blocks_[i])
            return false;
        return true;
    }
    return false;
}



bool BitArray::operator != (const BitArray& bit_array) const {
    return !(*this == bit_array);
}



std::string BitArray::ToString() const {
    std::string outputString;
    for (int i = size_ - 1; i >= 0; i--)
    if (GetBit(i) == 1)
        outputString+= '1';
    else
        outputString += '0';
    return outputString;
}

