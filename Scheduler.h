#pragma once
#include "Queue.h"
#include "Priority_Queue.h"
#include "Patient.h"
#include "Branch.h"
#include "Utilities.h"
#include "LinkedList.h"

class Scheduler {
private:
    Queue<Patient*> emergencyQueue;        // waiting Emergency patients, FIFO
    PriorityQueue<Patient> regularQueue;  // waiting Regular patients, sorted by priority
    Utilities* utilities;                 // shared, not owned -- gives us AutoE
    double alpha;                          // priority formula weight

public:
    Scheduler(Utilities* utilities, double alpha);

    // ---- Task 3: event handling ----
    void admitCheckIn(int id, int checkInTime, int branch, int numTests, PatientType type);
    void leavePatient(int id);
    void escalatePatient(int id);

    // ---- Task 4: auto-escalation ----
    void checkAutoEscalations(int currentTime);

    // ---- Task 5: Emergency Assignment ----
    void assignEmergency(LinkedList<Branch*>& branches, int currentTime);

    // ---- Task 6: Regular Assignment ----
    void assignRegular(LinkedList<Branch*>& branches, int currentTime) {
        if (regularQueue.isEmpty()) return;

        // Step 1: Assign to available Junior Doctors first across branches
        auto branchNode = branches.getHead();
        while (branchNode != nullptr && !regularQueue.isEmpty()) {
            Branch* branch = branchNode->data;
            
            auto docNode = branch->getJuniorDoctors().getHead();
            while (docNode != nullptr && !regularQueue.isEmpty()) {
                Doctor* doc = docNode->data;
                
                // Using Task 2 availability logic
                if (doc->isFree(currentTime)) {
                    Patient* p = nullptr;
                    regularQueue.dequeue(p); // Retrieve highest priority patient
                    
                    int finishTime = currentTime + p->getVisitTime();
                    doc->setFreeAtTime(finishTime);
                    p->setFinishTime(finishTime);
                }
                docNode = docNode->next;
            }
            branchNode = branchNode->next;
        }

        // Step 2: Assign remaining patients to available Senior Doctors
        branchNode = branches.getHead();
        while (branchNode != nullptr && !regularQueue.isEmpty()) {
            Branch* branch = branchNode->data;
            
            auto docNode = branch->getSeniorDoctors().getHead();
            while (docNode != nullptr && !regularQueue.isEmpty()) {
                Doctor* doc = docNode->data;
                
                if (doc->isFree(currentTime)) {
                    Patient* p = nullptr;
                    regularQueue.dequeue(p);
                    
                    int finishTime = currentTime + p->getVisitTime();
                    doc->setFreeAtTime(finishTime);
                    p->setFinishTime(finishTime);
                }
                docNode = docNode->next;
            }
            branchNode = branchNode->next;
        }
    }
};
