#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
public:
    // Node structure inside LinkedList
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

private:
    Node* head;   // points to the first element
    Node* tail;   // points to the last element
    int   count;  // how many elements are currently stored

public:
    LinkedList();                                                 // constructor
    ~LinkedList();                                                // destructor

    LinkedList(const LinkedList<T>& other) = delete;              // disable copy constructor
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete; // disable assignment operator

    void insertBegin(const T& value); // add to the front
    void insertEnd(const T& value);   // add to the back
    bool removeHead(T& value);        // remove and return from front
    bool removeNode(Node* node);      // remove a specific node directly
    bool removeByVal(const T& value); // search and remove a specific value
    bool isEmpty() const;
    int  getSize() const;
    void clear();                     // remove all nodes
    Node* getHead() const;            // look at head pointer
    Node* getTail() const;            // look at tail pointer
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// insertBegin
// O(1): attaches at head, updates prev/next pointers without traversal.
template <typename T>
void LinkedList<T>::insertBegin(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        // first element: head and tail both point to it
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

// insertEnd
// O(1): attaches at tail, updates prev/next pointers without traversal.
template <typename T>
void LinkedList<T>::insertEnd(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        // first element: head and tail both point to it
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

// removeHead
// O(1): detaches head node and returns true if successful.
template <typename T>
bool LinkedList<T>::removeHead(T& value) {
    if (isEmpty()) {
        return false;
    }

    Node* temp = head;
    value = head->data;

    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr; // list became empty
    }

    delete temp;
    count--;
    return true;
}

// removeNode
// O(1): removes a specific node pointer directly by adjusting links.
template <typename T>
bool LinkedList<T>::removeNode(Node* node) {
    if (node == nullptr || isEmpty()) {
        return false;
    }

    if (node == head) {
        T tempValue;
        return removeHead(tempValue);
    }

    if (node == tail) {
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete node;
        count--;
        return true;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    count--;
    return true;
}

// removeByVal
// O(N): searches for the value and removes its node if found.
template <typename T>
bool LinkedList<T>::removeByVal(const T& value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return removeNode(current);
        }
        current = current->next;
    }
    return false;
}

// isEmpty
template <typename T>
bool LinkedList<T>::isEmpty() const {
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

// getSize
template <typename T>
int LinkedList<T>::getSize() const {
    return count;
}

// clear
// O(N): deletes all nodes in the list.
template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// getHead
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getHead() const {
    return head;
}

// getTail
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getTail() const {
    return tail;
}

#endif
