#ifndef DATA_STRUCTURES_EXCEPTIONS_H
#define DATA_STRUCTURES_EXCEPTIONS_H

#include "exception"

struct QueueIsEmpty : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Attempting to remove an object from an empty queue.";
    }
};

struct QueueIsFull : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Attempting to add an object to the full queue.";
    }
};

struct StackIsEmpty : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Attempting to remove an object from an empty stack.";
    }
};

struct StackIsFull : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Attempting to add an object to the full stack.";
    }
};

#endif
