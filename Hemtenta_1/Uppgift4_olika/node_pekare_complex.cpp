#include <iostream>
#include <vector>
#include <exception>

// Template för en node som innehåller prioritet och ett värde av typen T.
template <typename T>
struct Node {
    int priority;
    T value;
};

template <typename T>
class Queue {
    private:
        std::vector<Node<T>*> data;
    public:
        ~Queue();
        void enqueueWithPriority(T value, int priority);
        void dequeue();
        Node<T>* peek();
        bool isEmpty();
        int size();
};

template <typename T>
Queue<T>::~Queue() {
    for (auto node : data) {
        delete node;
    }
}

template <typename T>
void Queue<T>::enqueueWithPriority(T value, int priority) {
    if (priority < 2 && priority > -1) {
        // Skapa en node
        Node<T>* n = new Node<T>;
        n->priority = priority;
        n->value = value;

        // Lagra i vectorn
        data.push_back(n);
    } else {
        throw std::invalid_argument("Invalid range of priority. Use a range of (0-1).");
    }
}

template <typename T>
void Queue<T>::dequeue() {
    int removed = false;
    if (!isEmpty()) {
        // Min iterator höll bara på att jävlas med mig så skrev en vanlig for loop istället,
        // tappade orken
        //
        // Ta bort tidigaste noden med prioritet 1
        // Om det inte finns något ta bort tidigaste noden med prioritet 0
        for (int i = 0; i < size(); i++) {
            if (data[i]->priority == 1) {
                delete data[i];
                data.erase(data.begin() + i);
                removed = true;
                break;
            }
        }

        if (!removed) {
            delete data[0];
            data.erase(data.begin());
        }
    } else {
        throw std::out_of_range("Invalid call to dequeue, Queue is empty.");
    }
}

template <typename T>
Node<T>* Queue<T>::peek() {
    if (!isEmpty()) {
        // Iterera igenom vectorn av noder och retunera första tidigaste noden med prioritet 1.
        // Om inte det finns något node med prioritet 1, retunera tidigaste noden med prioritet 0.
        // Kommer inte gå igenom loopen om data är tom.
        for (auto node : data) {
            if (node->priority == 1) {
                return node;
            } 
        }

        return data[0];
    } else {
        throw std::out_of_range("Invalid call to peek, Queue is empty.");
    }
}

template <typename T>
bool Queue<T>::isEmpty() {
    return (data.empty());
}

template <typename T>
int Queue<T>::size() {
    return (data.size());
}


// Uppgift 4
// Mallbasred Prioritetskö
// Jag valde att göra det enklelt för mig och kör med en node struct
// och en Queue klass som lagrar nodes i en vector
int main() {
    try {
        Queue<int> q;
        q.enqueueWithPriority(33, 0);
        q.enqueueWithPriority(89, 0);
        q.enqueueWithPriority(5, 1);

        Node<int>* p = q.peek();
        std::cout << "Queue of type int" << std::endl;
        std::cout << "Peek, value: " << p->value << ", priority: " << p->priority << std::endl;

        q.dequeue();
        p = q.peek();
        std::cout << "Peek, value: " << p->value << ", priority: " << p->priority << std::endl;

        Queue<float> qf;
        qf.enqueueWithPriority(12.1, 0);
        qf.enqueueWithPriority(19.1, 1);
        qf.enqueueWithPriority(11.1, 1);
        qf.enqueueWithPriority(32.1, 0);

        std::cout << std::endl;
        std::cout << "Queue of type float" << std::endl;
        Node<float>* pf = qf.peek();
        std::cout << "Peek, value: " << pf->value << ", priority: " << pf->priority << std::endl;

        qf.dequeue();
        pf = qf.peek();
        std::cout << "Peek, value: " << pf->value << ", priority: " << pf->priority << std::endl;
    }

    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
