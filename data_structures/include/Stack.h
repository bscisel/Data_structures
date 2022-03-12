#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include "Exceptions.h"

template<typename T, size_t max_elements>
class Stack {
    size_t top = 0;
    T *array;
public:
    Stack() : array{new T[max_elements]} {}

    size_t size() {
        return top;
    }

    bool is_empty() {
        return (top == 0);
    }

    bool is_full() {
        return (top == max_elements);
    }

    T on_top() {
        return array[top - 1];
    }

    void push(T object) {
        if (is_full())
            throw StackIsFull();
        array[top] = object;
        top++;
    }

    T pop() {
        if (is_empty())
            throw StackIsEmpty();
        T object = array[top - 1];
        top--;
        return object;
    }
};

#endif
