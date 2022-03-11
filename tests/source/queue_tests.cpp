#include "gtest/gtest.h"
#include "Queue.h"

TEST(queue, test_one) {
    Queue<int, 10> queue;
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    int dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 20);
    dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 30);
    dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 40);
}
