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
    void display();            //for  print
};

#include "Priority_Queue.cpp" // Included for template compilation (checkpoint 2)