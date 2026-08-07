#include "Priority_Queue.h"

template <typename T>
T* PQNode<T>::getData() {
    return data;
}
template <typename T>
PQNode<T>* PQNode<T>::getNext() {
    return next;
}
template <typename T>
int PQNode<T>::getPriority() {
    return priority;
}
template <typename T>
void PQNode<T>::setNext(PQNode<T>* next) {
    this->next = next;
}
template <typename T>
void PQNode<T>::setData(T* item) {
    this->data = item;
}
template <typename T>
void PQNode<T>::setPriority(double p) {
    this->priority = p;
}
template <typename T>
PriorityQueue<T>::PriorityQueue() {
    Front = nullptr;
}
template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}
template <typename T>
void PriorityQueue<T>::enqueue(T* item, int priority)
{
<<<<<<< HEAD
	PQNode<T>* newNode = new PQNode<T>();
	newNode->setData(item);
	newNode->setPriority(priority);
	if (isEmpty() || priority < Front->getPriority()) {
		newNode->setNext(Front);
		Front = newNode;
	}
	else {
		PQNode<T>* current = Front;
		while (current->getNext() != nullptr && current->getNext()->getPriority() >= priority) {
			current = current->getNext();
		}
		newNode->setNext(current->getNext());
		current->setNext(newNode);
	}
	count++;
}  


=======
    PQNode<T>* newNode = new PQNode<T>();
    newNode->setData(item);
    newNode->setPriority(priority);
    if (isEmpty() || priority < Front->getPriority()) {
        newNode->setNext(Front);
        Front = newNode;
    }
    else {
        PQNode<T>* current = Front;
        while (current->getNext() != nullptr && current->getNext()->getPriority() <= priority) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    count++;
}
>>>>>>> 986632a6cf8c56103aafcd00d7623a92921f3426
template <typename T>
T* PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    PQNode<T>* temp = Front;
    T* item = temp->getData();
    Front = Front->getNext();
    delete temp;
    count--;
    return item;
}
template <typename T>
T* PriorityQueue<T>::removeByID(int id)
{
    if (isEmpty()) {
        return nullptr;
    }
    PQNode<T>* current = Front;
    PQNode<T>* previous = nullptr;
    while (current != nullptr && current->getData()->getId() != id) {
        previous = current;
        current = current->getNext();
    }
    if (current == nullptr) {
        return nullptr;
    }
    if (previous == nullptr) {
        Front = current->getNext();
    }
    else {
        previous->setNext(current->getNext());
    }
    T* item = current->getData();
    delete current;
    count--;
    return item;
}
template <typename T>
bool PriorityQueue<T>::isEmpty() {
    return count == 0;
}
template <typename T>
int PriorityQueue<T>::getSize() {
    return count;
}
template <typename T>
void PriorityQueue<T>::collectExpiredIDs(int currentTime, int limit, LinkedList<int>& outIDs) const {
    PQNode<T>* current = Front;
    while (current != nullptr) {
        int waitTime = currentTime - current->getData()->getCheckInTime();
        if (waitTime > limit) {
            outIDs.insertEnd(current->getData()->getId());
        }
        current = current->getNext();
    }
}
template <typename T>
void PriorityQueue<T>::display() {
    // Note: getName() was removed -- Patient has no such method.
    // Prints fields that actually exist on Patient (id, branch, check-in time, priority).
    PQNode<T>* current = Front;
    while (current != nullptr) {
        std::cout << "ID: " << current->getData()->getId()
                   << ", Branch: " << current->getData()->getBranch()
                   << ", CheckIn: " << current->getData()->getCheckInTime()
                   << ", Priority: " << current->getPriority() << std::endl;
        current = current->getNext();
    }
}
