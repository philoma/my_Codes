#include <iostream>
#include <deque>

int main() {
    // 1. Create a deque
    std::deque<int> dq;

    // 2. Insert elements
    dq.push_back(10);          // Add to the back
    dq.push_front(5);          // Add to the front
    dq.push_back(15);          // Add to the back
    std::cout << "Deque after push_back and push_front: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    // 3. Access elements
    std::cout << "Front: " << dq.front() << "\n";
    std::cout << "Back: " << dq.back() << "\n";
    std::cout << "Element at index 1: " << dq[1] << "\n";

    // 4. Remove elements
    dq.pop_front();            // Remove from the front
    dq.pop_back();             // Remove from the back
    std::cout << "Deque after pop_front and pop_back: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    // 5. Insert at a specific position
    dq.push_back(20);
    dq.push_back(30);
    dq.insert(dq.begin() + 1, 25);  // Insert 25 at the second position
    std::cout << "Deque after inserting 25: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    // 6. Erase elements
    dq.erase(dq.begin() + 1);  // Erase the element at the second position
    std::cout << "Deque after erasing second element: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    // 7. Erase a range of elements
    dq.erase(dq.begin(), dq.begin() + 1);  // Erase the first element
    std::cout << "Deque after erasing first element: ";
    for (int x : dq) std::cout << x << " ";
    std::cout << "\n";

    // 8. Check size and if empty
    std::cout << "Size of deque: " << dq.size() << "\n";
    if (dq.empty()) {
        std::cout << "Deque is empty!\n";
    } else {
        std::cout << "Deque is not empty!\n";
    }

    // 9. Clear the deque
    dq.clear();
    std::cout << "Deque after clear operation: ";
    for (int x : dq) std::cout << x << " ";  // Should print nothing
    std::cout << (dq.empty() ? "Deque is now empty!" : "Deque is not empty!") << "\n";

    return 0;
}
