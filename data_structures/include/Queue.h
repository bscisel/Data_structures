#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

template <typename T, size_t max_elements>
class Queue {
    size_t head = 0;
    size_t tail = 0;
    T* array;
public:
    Queue() : array{new T[max_elements]} {}
    ~Queue() {
        delete[] array;
    }
    void enqueue(T object) {
        array[tail] = object;
        if (tail == max_elements)
            tail = 1;
        else
            tail++;
    }
    T dequeue() {
        T object = array[head];
        if (head == max_elements)
            head = 1;
        else
            head++;
        return object;
    }
};


#endif
