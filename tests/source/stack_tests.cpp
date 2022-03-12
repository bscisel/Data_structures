#include "gtest/gtest.h"

#include "Stack.h"

TEST(StackTest, basic_functionality) {
    Stack<unsigned char, 10> stack;
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.pop(), 10);
}