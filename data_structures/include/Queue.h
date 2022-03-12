#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "Exceptions.h"

template<typename T, size_t max_elements>
class Queue {
    size_t head = 0;
    size_t tail = 0;
    size_t elementsCount = 0;
    T *array;
public:
    Queue() : array{new T[max_elements]} {}

    ~Queue() {
        delete[] array;
    }

    void enqueue(T object) {
        if (elementsCount == max_elements)
            throw QueueIsFull();
        array[tail] = object;
        if (tail == max_elements - 1)
            tail = 0;
        else
            tail++;
        elementsCount++;
    }

    T dequeue() {
        if (elementsCount == 0)
            throw QueueIsEmpty();
        T object = array[head];
        if (head == max_elements - 1)
            head = 0;
        else
            head++;
        elementsCount--;
        return object;
    }
};


#endif
