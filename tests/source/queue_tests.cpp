#include "gtest/gtest.h"
#include "Queue.h"

class QueueTest : public ::testing::Test {
protected:
    Queue<int, 4> queue;
    void SetUp() override {
        queue.enqueue(10);
        queue.enqueue(20);
    }

    void TearDown() override {

    }
};


TEST_F(QueueTest, basic_functionality) {
    int dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 10);
    dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 20);
}

TEST_F(QueueTest, dequeue_empty) {
    queue.dequeue();
    queue.dequeue();
    ASSERT_THROW(queue.dequeue(), QueueIsEmpty);
}


TEST_F(QueueTest, queue_full) {
    queue.enqueue(30);
    queue.enqueue(40);
    ASSERT_THROW(queue.enqueue(50), QueueIsFull);
}