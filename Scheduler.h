#pragma once
#include "Queue.h"
#include "Priority_Queue.h"
#include "Patient.h"
#include "Branch.h"
#include "Utilities.h"
#include "LinkedList.h"

class Scheduler {
private:
    Queue<Patient*> emergencyQueue;      // waiting Emergency patients, FIFO
    PriorityQueue<Patient> regularQueue; // waiting Regular patients, sorted by priority
    Utilities* utilities;                // shared, not owned -- gives us AutoE
    double alpha;                        // priority formula weight

public:
    Scheduler(Utilities* utilities, double alpha);

    // ---- Task 3: event handling ----
    void admitCheckIn(int id, int checkInTime, int branch, int numTests, PatientType type);
    void leavePatient(int id);
    void escalatePatient(int id);

    // ---- Task 4: auto-escalation ----
    void checkAutoEscalations(int currentTime);

    // ---- Tasks 5 & 6 (teammate): assignment logic goes here later ----
    // void assignEmergency(LinkedList<Branch*>& branches, int currentTime);
    // void assignRegular(LinkedList<Branch*>& branches, int currentTime);
};
