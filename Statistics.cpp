#include "Patient.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// Task 8: walks the done-list once and computes summary statistics.
void printStatistics(LinkedList<Patient*>& doneList) {
    int totalPatients = doneList.getSize();

    if (totalPatients == 0) {
        cout << "No patients to report statistics for." << endl;
        return;
    }

    int totalWait = 0;
    int totalVisit = 0;
    int escalatedCount = 0;

    auto current = doneList.getHead();
    while (current != nullptr) {
        Patient* p = current->data;

        totalWait += p->getWaitTime();
        totalVisit += p->getVisitTime();
        if (p->getWasEscalated()) {
            escalatedCount++;
        }

        current = current->next;
    }

    double avgWait = (double)totalWait / totalPatients;
    double avgVisit = (double)totalVisit / totalPatients;
    double escalationPercent = (double)escalatedCount / totalPatients * 100.0;

    cout << "----- Statistics -----" << endl;
    cout << "Total patients: " << totalPatients << endl;
    cout << "Average wait time: " << avgWait << endl;
    cout << "Average visit time: " << avgVisit << endl;
    cout << "Auto-escalation percentage: " << escalationPercent << "%" << endl;
}
