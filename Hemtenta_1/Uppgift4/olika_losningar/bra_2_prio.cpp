#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>

// Template class for a priority queue
template <typename T>
class PriorityQueue {
private:
    // Two queues for high and low priority elements
    std::queue<T> high_priority; 
    std::queue<T> low_priority;

public:
    // Enqueue element with priority level
    void enqueuePrio(const T& element, int priority) {
        // If the priority level is 1, add to high priority queue
        if (priority == 1) {
            high_priority.push(element);
        // If the priority level is 0, add to low priority queue
        } else if (priority == 0) {
            low_priority.push(element);
        // Throw exception for invalid priority level
        } else {
            throw std::invalid_argument("Invalid priority level. Must be 0 or 1.");
        }
    }

    // Dequeue the element with the highest priority
    T dequeue() {
        // Dequeue from high priority queue if not empty
        if (!high_priority.empty()) {
            T element = high_priority.front();
            high_priority.pop();
            return element;
        // Dequeue from low priority queue if not empty
        } else if (!low_priority.empty()) {
            T element = low_priority.front();
            low_priority.pop();
            return element;
        } else {
            throw std::out_of_range("Queue is empty. Cannot dequeue.");
        }
    }

    // Display the element with the highest priority
    T peek() const {
        if (!high_priority.empty()) {
            return high_priority.front();
        } else if (!low_priority.empty()) {
            return low_priority.front();
        } else {
            throw std::out_of_range("Queue is empty. Cannot peek.");
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return high_priority.empty() && low_priority.empty();
    }

    // Get the size of the queue
    size_t size() const {
        return high_priority.size() + low_priority.size();
    }
};

// Test program
int main() {
    try {
        // Test with integer priority queue
        PriorityQueue<int> int_queue;

        // Test enqueuePrio
        int_queue.enqueuePrio(10, 1); // High priority
        int_queue.enqueuePrio(50, 0); // Low priority
        int_queue.enqueuePrio(40, 1); // High priority

        std::cout << "Peek: " << int_queue.peek() << std::endl;

        // Test dequeue
        std::cout << "Dequeue: " << int_queue.dequeue() << std::endl;
        std::cout << "Dequeue: " << int_queue.dequeue() << std::endl;

        // Test size and isEmpty
        std::cout << "Queue size: " << int_queue.size() << std::endl;
        std::cout << "Is queue empty? " << (int_queue.isEmpty() ? "Yes" : "No") << std::endl;

        // Test invalid priority level
        try {
            int_queue.enqueuePrio(40, 2);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test dequeue from empty queue
        int_queue.dequeue(); // Should work
        int_queue.dequeue(); // Should be empty
        int_queue.dequeue(); // Should throw exception

    } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    try {
        // Test with string priority queue
        PriorityQueue<std::string> string_queue;

        // Test enqueuePrio with "Hello" and "!" with high priority and "," and "World" with low priority
        string_queue.enqueuePrio("Hello", 1);
        string_queue.enqueuePrio(",", 0);
        string_queue.enqueuePrio("World", 0);
        string_queue.enqueuePrio("!", 1);

        std::cout << "Peek: " << string_queue.peek() << std::endl;

        std::cout << "Dequeue: " << string_queue.dequeue() << std::endl;
        std::cout << "Dequeue: " << string_queue.dequeue() << std::endl;

        // Test size and isEmpty and to check if elements are dequeued correctly
        std::cout << "Queue size: " << string_queue.size() << std::endl;
        std::cout << "Is queue empty? " << (string_queue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Dequeue: " << string_queue.dequeue() << std::endl;
        std::cout << "Queue size: " << string_queue.size() << std::endl;
        std::cout << "Is queue empty? " << (string_queue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Dequeue: " << string_queue.dequeue() << std::endl;
        std::cout << "Queue size: " << string_queue.size() << std::endl;
        std::cout << "Is queue empty? " << (string_queue.isEmpty() ? "Yes" : "No") << std::endl;
        std::cout << "Dequeue: " << string_queue.dequeue() << std::endl;
        std::cout << "Queue size: " << string_queue.size() << std::endl;
        std::cout << "Is queue empty? " << (string_queue.isEmpty() ? "Yes" : "No") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

/*
Om vi skulle behöva implementera ytterligare prioritetsnivåer i vårt program så skulle alla funktioner behövas skrivas om då den just nu är hårdkodad att bara fungera med 2 prioritetsnivåer och den kastar fel om någon annan skulle användas.
Majoriteten av kodrader i klassen skulle behöva skrivas om för att hantera fler prioritetsnivåer och alla metoder skulle behövas modifieras för att hantera detta.
*/