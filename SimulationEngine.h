#pragma once
#include "Utilities.h"
#include "Branch.h"
#include "Event.h"
#include "Scheduler.h"
#include "LinkedList.h"

class SimulationEngine {
private:
    Utilities* utilities;
    LinkedList<Branch*>& branches;
    LinkedList<Event*>& events;
    Scheduler* scheduler;
    int currentTime;

public:
    SimulationEngine(Utilities* utilities, LinkedList<Branch*>& branches, LinkedList<Event*>& events, Scheduler* scheduler);

    // ---- Task 1: main loop orchestration ----
    void run();

    // ---- Task 2: doctor availability ----
    // likely lives as methods on Doctor itself (isAvailableAt, etc.) rather
    // than here -- see notes, this class mainly calls into those

    // ---- Task 7: output writer ----
    // void writeOutputFile(const string& filename);

    // ---- Task 8: statistics ----
    // void printStatistics();
};
