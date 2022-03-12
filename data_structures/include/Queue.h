#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "Exceptions.h"

template<typename T, size_t max_elements>
class Queue {
    size_t head = 0;
    size_t tail = 0;
    size_t current_size = 0;
    T *array;
public:
    Queue() : array{new T[max_elements]} {}

    ~Queue() {
        delete[] array;
    }

    size_t size() {
        return current_size;
    }

    bool is_empty() {
        return (current_size == 0);
    }

    bool is_full() {
        return (current_size == max_elements);
    }

    T rear() {
        return array[head];
    }

    T front() {
        return array[(tail - 1) % max_elements];
    }

    void enqueue(T object) {
        if (is_full())
            throw QueueIsFull();
        array[tail] = object;
        tail = (tail + 1) % max_elements;
        current_size++;
    }

    T dequeue() {
        if (is_empty())
            throw QueueIsEmpty();
        T object = array[head];
        head = (head + 1) % max_elements;
        current_size--;
        return object;
    }
};


#endif
