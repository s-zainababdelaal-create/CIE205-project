#pragma once
#include <iostream>
using namespace std;
template <typename T>
class PQNode {
private:
    T* data;             // pointer to data Patient
    int priority;   // priority = CT + α × TESTS
    PQNode<T>* next = nullptr;
public:
    T* getData();
    PQNode<T>* getNext();
    int getPriority();
    void setNext(PQNode<T>* next);
    void setData(T* item);
    void setPriority(double p);
};

template <typename T>

class PriorityQueue {
    int count = 0;
    PQNode<T>* Front = nullptr;

public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(T* item, int priority);
    T* dequeue();
    T* removeByID(int id);   // "No structural duplication or shallow copies (Patient p2 = p1) are allowed." (SHARE, MOVE, BUT DON'T COPY)
    bool isEmpty();
    int getSize();
    void display();
};

//#include "Priority_Queue.cpp"

