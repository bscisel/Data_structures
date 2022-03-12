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
    EXPECT_EQ(queue.rear(), 10);
    int dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 10);
    EXPECT_EQ(queue.rear(), 20);
    EXPECT_FALSE(queue.is_empty());
    EXPECT_FALSE(queue.is_full());
    dequeued = queue.dequeue();
    EXPECT_EQ(dequeued, 20);
    EXPECT_TRUE(queue.is_empty());
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