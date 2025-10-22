#include <iostream>
#include "stack_vector.h"

// Implements a queue using two stacks
template<typename T>
class Queue {
private:
    Stack<T> s1, s2; // s1 for enqueue, s2 for dequeue

public:
    // Add an item to the back
    void Push(const T &item) {
        s1.Push(item);
    }

    // Remove and return the front item
    T Pop() {
        if (s2.Size() == 0) {
            while (s1.Size() > 0) {
                s2.Push(s1.Top());
                s1.Pop();
            }
        }

        if (s2.Size() == 0)
            throw std::underflow_error("Queue is empty!");

        T front = s2.Top();
        s2.Pop();
        return front;
    }

    // Returns total number of elements
    size_t Size() {
        return s1.Size() + s2.Size();
    }
};

/*
Push(): O(1)
Pop(): Amortized O(1), worst-case O(n) when transferring elements
*/

#ifndef NO_MAIN
int main() {
    Queue<int> q;
    std::vector<int> values = {59, 24, 49, 63, 41};

    for (int v : values)
        q.Push(v);

    std::cout << "Queue output (FIFO): ";
    while (q.Size() > 0) {
        std::cout << q.Pop();
        if (q.Size() > 0) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
#endif
