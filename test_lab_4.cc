#include <gtest/gtest.h>
#include "stack_vector.h"

#define NO_MAIN
#include "q1-1.cc"
#include "q1-2.cc"
#include "q2.cc"
#undef NO_MAIN

// --- Q1.1: Sort() ---
TEST(StackSortTest, BasicSort) {
    Stack<int> s;
    s.Push(3); s.Push(1); s.Push(2);
    Stack<int> sorted = Sort(s);

    EXPECT_EQ(sorted.Top(), 1);
    sorted.Pop();
    EXPECT_EQ(sorted.Top(), 2);
}

TEST(StackSortTest, ReverseSortedInput) {
    Stack<int> s;
    s.Push(5); s.Push(4); s.Push(3);
    Stack<int> sorted = Sort(s);
    EXPECT_EQ(sorted.Top(), 3);
}

// --- Q1.2: DeleteMiddleElement() ---
TEST(DeleteMiddleTest, OddStack) {
    Stack<int> s;
    for (int v : {5, 4, 3, 2, 1}) s.Push(v);
    DeleteMiddleElement(s, s.Size());
    EXPECT_EQ(s.Size(), 4);
}

TEST(DeleteMiddleTest, EvenStack) {
    Stack<int> s;
    for (int v : {4, 3, 2, 1}) s.Push(v);
    DeleteMiddleElement(s, s.Size());
    EXPECT_EQ(s.Size(), 3);
}

// --- Q2: Queue ---
TEST(QueueTest, FIFOOrder) {
    Queue<int> q;
    q.Push(10); q.Push(20); q.Push(30);
    EXPECT_EQ(q.Pop(), 10);
    EXPECT_EQ(q.Pop(), 20);
    EXPECT_EQ(q.Pop(), 30);
}

TEST(QueueTest, EmptyPopThrows) {
    Queue<int> q;
    EXPECT_THROW(q.Pop(), std::underflow_error);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
