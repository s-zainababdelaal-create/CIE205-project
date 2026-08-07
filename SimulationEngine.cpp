#include "SimulationEngine.h"
#include <iostream>
using namespace std;

SimulationEngine::SimulationEngine(Utilities* utilities, LinkedList<Branch*>& branches, LinkedList<Event*>& events, Scheduler* scheduler)
    : utilities(utilities), branches(branches), events(events), scheduler(scheduler), currentTime(0) {
}

// run: the tick-by-tick loop. TODO (task 1 owner):
//   - advance currentTime
//   - pull events whose timestamp == currentTime, dispatch each to the
//     matching Scheduler method (admitCheckIn / leavePatient / escalatePatient)
//   - call scheduler->checkAutoEscalations(currentTime) each tick
//   - call the assignment methods on scheduler
//   - stop once all events are processed and all patients are done
void SimulationEngine::run() {
    // TODO: implement the loop described above
}
