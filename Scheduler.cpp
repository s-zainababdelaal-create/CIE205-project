#include "Scheduler.h"

Scheduler::Scheduler(Utilities* utilities, double alpha)
    : utilities(utilities), alpha(alpha) {
}

// admitCheckIn: called by SimulationEngine when a CHECK_IN event's timestamp
// is reached. Creates the real Patient here, then routes it to the right list.
void Scheduler::admitCheckIn(int id, int checkInTime, int branch, int numTests, PatientType type) {
    Patient* p = new Patient(id, checkInTime, branch, numTests, type);

    if (type == EMERGENCY) {
        emergencyQueue.enqueue(p);
    }
    else {
        int priority = checkInTime + static_cast<int>(alpha * numTests);
        regularQueue.enqueue(p, priority);
    }
}

// leavePatient: called on an L event. Patient could be waiting in either
// list -- try Regular first, then Emergency.
void Scheduler::leavePatient(int id) {
    Patient* p = regularQueue.removeByID(id);
    if (p == nullptr) {
        p = emergencyQueue.removeByID(id);
    }
    if (p != nullptr) {
        delete p; // never served, nothing else references it
    }
    // still nullptr here means the patient was already pulled out and
    // assigned to a doctor before this L event's timestamp arrived -- not an error
}

// escalatePatient: called on a U event. Spec guarantees this always targets a Regular patient.
void Scheduler::escalatePatient(int id) {
    Patient* p = regularQueue.removeByID(id);
    if (p != nullptr) {
        p->setType(EMERGENCY);
        emergencyQueue.enqueue(p);
    }
    // nullptr here means the patient already left or was already served -- ignore
}

// checkAutoEscalations: scans the WHOLE regular list, not just the front, since priority order and wait-time order can differ once TESTS counts vary.
void Scheduler::checkAutoEscalations(int currentTime) {
    LinkedList<int> expiredIDs; // collect first, then remove -- don't mutate mid-traversal
    regularQueue.collectExpiredIDs(currentTime, utilities->getAutoEscalateLimit(), expiredIDs);

    auto* node = expiredIDs.getHead();
    while (node != nullptr) {
        escalatePatient(node->data); // reuse the exact same logic as a manual U event
        node = node->next;
    }
}
