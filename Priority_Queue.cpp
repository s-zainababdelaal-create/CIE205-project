#include"Priority_Queue.h"

template <typename T>
void PriorityQueue<T>::collectExpiredIDs(int currentTime, int limit, LinkedList<int>& outIDs) const {
    PQNode<T>* current = Front;
    while (current != nullptr) {
        int waitTime = currentTime - current->getData()->getCheckInTime();
        if (waitTime > limit) {
            outIDs.insertEnd(current->getData()->getID());
        }
        current = current->getNext();
    }
}
