#pragma once
template <typename T>
class PQNode {
private:
    T* data;             // pointer to data Patient
    int priority;   // priority = CT + α × TESTS
    PQNode<T>* next;
public:
    T* getData();
    PQNode<T>* getNext();
    double getPriority();
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
    void enqueue(T* item,int priority);
    T* dequeue();                           
    T* removeByID(int id);
    bool ismpty();
    int getSize();
    void display();
};

//Test