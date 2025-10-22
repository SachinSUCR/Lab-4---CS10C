#include <iostream>
#include "stack_vector.h"

// Sorts a stack so that the smallest element ends up on top.
// Uses a temporary stack to store items in sorted order.
template<typename T>
Stack<T> Sort(Stack<T> &s1) {
    Stack<T> temp;

    while (s1.Size() > 0) {
        T current = s1.Top();
        s1.Pop();

        // Move elements from temp back to s1 until correct spot found
        while (temp.Size() > 0 && temp.Top() > current) {
            s1.Push(temp.Top());
            temp.Pop();
        }
        temp.Push(current);
    }

    return temp;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#ifndef NO_MAIN
int main() {
    Stack<int> s1;
    std::vector<int> values = {44, 12, 59, 41};
    for (int v : values)
        s1.Push(v);

    Stack<int> sorted = Sort(s1);

    std::cout << "Sorted stack (top to bottom): ";
    while (sorted.Size() > 0) {
        std::cout << sorted.Top();
        sorted.Pop();
        if (sorted.Size() > 0) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
#endif
