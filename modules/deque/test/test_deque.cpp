// Copyright 2017 Vinogradova Ekaterina

#include <gtest/gtest.h>

#include "include/deque.h"

TEST(Deque, can_create_deque) {
    ASSERT_NO_THROW(Deque deq);
}

TEST(Deque, cant_create_deque_with_negative_size) {
    ASSERT_ANY_THROW(Deque deq(-3));
}

TEST(Deque, can_InsFront_in_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_NO_THROW(deq.InsFront(1));
}

TEST(Deque, cant_InsFront_in_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.InsFront(1));
}

TEST(Deque, cant_InsFront_in_full_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_ANY_THROW(deq.InsFront(1));
}

TEST(Deque, can_InsBack_in_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_NO_THROW(deq.InsBack(1));
}

TEST(Deque, cant_InsBack_in_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.InsBack(1));
}

TEST(Deque, cant_InsBack_in_full_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsBack(i);

    ASSERT_ANY_THROW(deq.InsBack(1));
}

TEST(Deque, can_GetFront_from_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_NO_THROW(deq.GetFront());
}

TEST(Deque, GetFront_get_front_element) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_EQ(deq.GetFront(), 4);
}

TEST(Deque, cant_GetFront_from_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.GetFront());
}

TEST(Deque, cant_GetFront_from_empty_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_ANY_THROW(deq.GetFront());
}

TEST(Deque, can_GetBack_from_deque) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_NO_THROW(deq.GetBack());
}

TEST(Deque, GetBack_get_back_element) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_EQ(deq.GetBack(), 0);
}

TEST(Deque, cant_GetBack_from_deque_with_null_size) {
    Deque deq(0);

    ASSERT_ANY_THROW(deq.GetBack());
}

TEST(Deque, cant_GetBack_from_empty_deque) {
    const int size = 5;
    Deque deq(size);

    ASSERT_ANY_THROW(deq.GetBack());
}

TEST(Deque, empty_deque_is_empty) {
    const int size = 5;
    Deque deq(size);

    ASSERT_TRUE(deq.IsEmpty());
}

TEST(Deque, deque_with_elements_not_empty) {
    const int size = 5;
    Deque deq(size);

    deq.InsFront(1);
    deq.InsBack(10);

    ASSERT_FALSE(deq.IsEmpty());
}

TEST(Deque, full_deque_is_full) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);

    ASSERT_TRUE(deq.IsFull());
}

TEST(Deque, full_deque_not_full_after_get) {
    const int size = 5;
    Deque deq(size);

    for (int i = 0; i < size; i++)
        deq.InsFront(i);
    deq.GetFront();

    ASSERT_FALSE(deq.IsFull());
}

TEST(Deque, empty_deque_not_empty_after_put) {
    const int size = 5;
    Deque deq(size);

    deq.InsBack(10);

    ASSERT_FALSE(deq.IsEmpty());
}
