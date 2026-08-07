#include "SimulationEngine.h"
#include <iostream>
using namespace std;

// Constructor with isInteractive initialization
SimulationEngine::SimulationEngine(Utilities* utilities, LinkedList<Branch*>& branches, 
                                 LinkedList<Event*>& events, Scheduler* scheduler, 
                                 bool isInteractive)
    : utilities(utilities), branches(branches), events(events), scheduler(scheduler), 
      currentTime(0), isInteractive(isInteractive) {
}

// Bonus 1: Prints a complete snapshot of all branches, doctors, and queues at currentTime
void SimulationEngine::printSnapshot(int currentTime) {
    cout << "\n======== Timestep " << currentTime << " ========\n";

    // 1. Doctor status per branch
    typename LinkedList<Branch*>::Node* branchNode = branches.getHead();
    int branchIdx = 1;
    while (branchNode != nullptr) {
        cout << "Branch " << branchIdx++ << ": ";
        Branch* currentBranch = branchNode->data;
        
        // Traverse senior and junior doctors in the branch
        auto docNode = currentBranch->getDoctors().getHead();
        while (docNode != nullptr) {
            cout << docNode->data->getStatusString(currentTime) << "   ";
            docNode = docNode->next;
        }
        cout << "\n";
        branchNode = branchNode->next;
    }

    // 2. Waiting queues state
    cout << "Waiting Emergency: ";
    scheduler->getEmergencyQueue().printIDs();
    cout << "\n";

    cout << "Waiting Regular:   ";
    scheduler->getRegularQueue().printIDs();
    cout << "\n";

    // 3. Completed patients count
    cout << "Done so far:       " << scheduler->getDoneList().getSize() << "\n";
    cout << "-- press Enter to continue --";
}

// run: the tick-by-tick simulation loop
void SimulationEngine::run() {
    // Loop until all events are processed and all active patients complete treatment
    while (!events.isEmpty() || !scheduler->isSimulationFinished()) {
        currentTime++;

        // 1. Process events scheduled for the current timestamp
        while (!events.isEmpty() && events.getHead()->data->getTimestamp() == currentTime) {
            Event* currentEvent = nullptr;
            events.removeHead(currentEvent);
            if (currentEvent != nullptr) {
                currentEvent->execute(scheduler);
                delete currentEvent;
            }
        }

        // 2. Process auto-escalations for regular patients exceeding max wait time
        scheduler->checkAutoEscalations(currentTime);

        // 3. Assign free doctors to waiting patients
        scheduler->assignPatientsToDoctors(currentTime);

        // 4. Bonus 1: Display snapshot and pause for user input in interactive mode
        if (isInteractive) {
            printSnapshot(currentTime);
            cin.get(); // Wait for user to press Enter
        }
    }
}
