#include <iostream>
#include "stack_vector.h"

// Recursively removes the middle element from the stack.
// The middle is defined as index n/2 (0-based from the top).
template<typename T>
void DeleteMiddleElement(Stack<T> &s, unsigned int n, unsigned int curr = 0) {
    if (s.Size() == 0 || curr == n) return;

    T top = s.Top();
    s.Pop();

    // Recurse until we hit the middle
    if (curr != n / 2) {
        DeleteMiddleElement(s, n, curr + 1);
        s.Push(top); // rebuild stack except for middle
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n) due to recursion
*/

#ifndef NO_MAIN
int main() {
    Stack<int> s1;
    std::vector<int> values = {59, 24, 49, 63, 41};
    for (int v : values)
        s1.Push(v);

    std::cout << "Original stack (top to bottom): 41, 63, 49, 24, 59\n";
    DeleteMiddleElement(s1, s1.Size());

    std::cout << "After deleting middle element: ";
    while (s1.Size() > 0) {
        std::cout << s1.Top();
        s1.Pop();
        if (s1.Size() > 0) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
#endif
