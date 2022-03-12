#include "gtest/gtest.h"

#include "Stack.h"

TEST(StackTest, basic_functionality) {
    Stack<unsigned char, 10> stack;
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.pop(), 10);
}

TEST(StackTest, full_empty_stack) {
    Stack<unsigned char, 3> stack;
    ASSERT_TRUE(stack.is_empty());
    stack.push(10);
    stack.push(20);
    stack.push(30);
    ASSERT_EQ(stack.size(), 3);
    ASSERT_TRUE(stack.is_full());
    ASSERT_THROW(stack.push(40), StackIsFull);
    EXPECT_EQ(stack.pop(), 30);
    EXPECT_EQ(stack.on_top(), 20);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.pop(), 10);
    ASSERT_EQ(stack.size(), 0);
    ASSERT_THROW(stack.pop(), StackIsEmpty);
}
