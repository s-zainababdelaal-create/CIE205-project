#pragma once
#include <iostream>
#include "LinkedList.h"

template <typename T>
class PQNode
    // PQNode<T> — Node class for Priority Queue
{
private:
    T* data;             // Pointer to stored object to avoid copying memory
    int priority;        // Computed priority (CT + alpha * TESTS)
    PQNode<T>* next = nullptr; // Pointer to next node in list and nullptr if last node by default

public:
    // Getters
    T* getData();
    PQNode<T>* getNext();
    int getPriority();

    // Setters
    void setNext(PQNode<T>* next);
    void setData(T* item);
    void setPriority(double p); // Note: double converted to int
};


template <typename T>
class PriorityQueue  // PriorityQueue<T> — Hand-built Sorted Linked List Queue
{
    int count = 0;              // Current queue size
    PQNode<T>* Front = nullptr; // Pointer to highest priority node (Head)

public:
    PriorityQueue();
    ~PriorityQueue();           // Deletes PQNodes only, keeps actual data

    void enqueue(T* item, int priority); // Inserts item in sorted order
    T* dequeue();              // Removes & returns highest priority item
    T* removeByID(int id);      // Removes specific patient by ID (for Leave event)

    bool isEmpty(); // Make sure to check if queue is empty before dequeueing or removing by ID
    int getSize();  // Returns current queue size
    void display();            // For print

    // Read-only: doesn't remove anything, just reports who qualifies for auto-escalation.
    void collectExpiredIDs(int currentTime, int limit, LinkedList<int>& outIDs) const;

    // --- Bonus 1: Snapshot Display ---
    // Helper method to traverse nodes and print active element IDs
    void printIDs() const {
        PQNode<T>* current = Front;
        while (current != nullptr) {
            if (current->getData() != nullptr) {
                std::cout << "[" << current->getData()->getId() << "] ";
            }
            current = current->getNext();
        }
    }
};

// Included at the BOTTOM, after both classes are fully declared above --
// this is required for template method bodies to compile (they reference
// PQNode<T>/PriorityQueue<T> which must already be known types).
#include "Priority_Queue.cpp"
