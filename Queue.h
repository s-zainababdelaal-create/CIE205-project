#pragma once
#include <iostream>
#include <stdexcept>   // Needed for throwing runtime_error
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* frontPtr;   // Points to the oldest element
    Node* rearPtr;    // Points to the newest element
    int   count;      // How many elements are currently stored

public:
    Queue();                        // Constructor
    ~Queue();                       // Destructor

    Queue(const Queue<T>& other) = delete;              // Disable copying patient pointers 
    Queue<T>& operator=(const Queue<T>& other) = delete; 

    void enqueue(const T& value);   // Add to the rear
    T    dequeue();                 // Remove and return from the front
    T& front() const;               // Look at the front without removing it
    bool isEmpty() const;
    int  getSize() const;
    T removeByID(int id);          // Find by ID anywhere in queue, unlink, return it

    // --- Bonus 1: Snapshot Display ---
    void printIDs() const;          // Traverses queue and prints element IDs
};

// Constructor
template <typename T>
Queue<T>::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// enqueue 
// O(1): always attaches at rearPtr, no traversal needed.
template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        // First element: front and rear both point to it
        frontPtr = newNode;
        rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    count++;
}

// dequeue
// O(1): always detaches frontPtr, no traversal needed.
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty!");
    }
    Node* temp = frontPtr;
    T value = temp->data;
    frontPtr = frontPtr->next;
    if (frontPtr == nullptr) {
        rearPtr = nullptr;
    }
    delete temp;
    count--;
    return value;
}

// front
// O(1): just reads, does not remove.
template <typename T>
T& Queue<T>::front() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty!");
    }
    return frontPtr->data;
}

// isEmpty
template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

// getSize
template <typename T>
int Queue<T>::getSize() const {
    return count;
}

// removeByID
// O(n): walks the list for a matching ID, unlinks that node, reconnects rearPtr if needed.
template <typename T>
T Queue<T>::removeByID(int id) {
    Node* current = frontPtr;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data->getID() == id) {
            if (prev == nullptr) {
                frontPtr = current->next;
            }
            else {
                prev->next = current->next;
            }
            if (current == rearPtr) {
                rearPtr = prev;
            }
            T value = current->data;
            delete current;
            count--;
            return value;
        }
        prev = current;
        current = current->next;
    }
    return nullptr;
}

// printIDs (Bonus 1)
// O(n): traverses nodes to display stored element IDs
template <typename T>
void Queue<T>::printIDs() const {
    Node* current = frontPtr;
    while (current != nullptr) {
        if (current->data != nullptr) {
            std::cout << "[" << current->data->getID() << "] ";
        }
        current = current->next;
    }
}
