
#pragma once
#include <iostream>
#include "Utilities.h"
#include "LinkedList.h"
#include "Branch.h"
#include "Event.h"
#include "Scheduler.h"

class SimulationEngine {
private:
    Utilities* utilities;
    LinkedList<Branch*>& branches;
    LinkedList<Event*>& events;
    Scheduler* scheduler;
    int currentTime;
    bool isInteractive; // Bonus 1: Flag for interactive step-by-step mode

    // Helper method to print real-time simulation state
    void printSnapshot(int currentTime);

public:
    // Updated constructor receiving optional interactive mode flag
    SimulationEngine(Utilities* utilities, LinkedList<Branch*>& branches, 
                     LinkedList<Event*>& events, Scheduler* scheduler, 
                     bool isInteractive = false);

    void run();
};
