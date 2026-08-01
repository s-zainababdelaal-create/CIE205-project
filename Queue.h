#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontPtr;   //points to the oldest element
    Node* rearPtr;    //points to the newest element
    int   count;      //how many elements are currently stored

public:
    Queue();                       // constructor
    ~Queue();                      // destructor

    Queue(const Queue<T>& other) = delete;                        ////////////
    Queue<T>& operator=(const Queue<T>& other) = delete;          /////////////

    void enqueue(const T& value);   // add to the rear
    T    dequeue();                 // remove and return from the front
    T& front() const;             // look at the front without removing it
    bool isEmpty() const;
    int  getSize() const;
};

//Constructor
template <typename T>
Queue<T>::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

//Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

//enqueue 
// O(1): always attaches at rearPtr, no traversal needed.
template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        // first element: front and rear both point to it
        frontPtr = newNode;
        rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    count++;
}

//dequeue
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

//front
// O(1): just reads, does not remove.
template <typename T>
T& Queue<T>::front() const {
    if (isEmpty()) {
        cout << "Queue is empty! \n";
    }
    return frontPtr->data;
}

//isEmpty
template <typename T>
bool Queue<T>::isEmpty() const {
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

//getSize
template <typename T>
int Queue<T>::getSize() const {
    return count;
}
#endif
