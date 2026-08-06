// Temporary test file — dummy done-list to develop Task 7 (output writer)
// and Task 8 (statistics) without waiting for the rest of the team.
// This is NOT part of the final submission; it's just for local testing.

#include "Patient.h"
#include "LinkedList.h"

LinkedList<Patient*> makeDummyDoneList() {
    LinkedList<Patient*> doneList;

    Patient* p1 = new Patient(1, 5, 1, 2, REGULAR);
    p1->setFinishStats(20, 10, 5);   // FT=20, WT=10, VT=5
    doneList.insertEnd(p1);

    Patient* p2 = new Patient(2, 8, 1, 1, EMERGENCY);
    p2->setFinishStats(15, 2, 5);    // FT=15, WT=2, VT=5
    doneList.insertEnd(p2);

    Patient* p3 = new Patient(3, 12, 2, 3, REGULAR);
    p3->setFinishStats(35, 15, 8);   // FT=35, WT=15, VT=8
    doneList.insertEnd(p3);

    return doneList;
}
