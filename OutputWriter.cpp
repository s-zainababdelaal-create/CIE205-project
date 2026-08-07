#include "Patient.h"
#include "LinkedList.h"
#include <fstream>
using namespace std;

// Decides output order: FT ascending, then fewer tests, then lower ID
bool comesBefore(Patient* a, Patient* b) {
    if (a->getFinishTime() != b->getFinishTime())
        return a->getFinishTime() < b->getFinishTime();
    if (a->getNumTests() != b->getNumTests())
        return a->getNumTests() < b->getNumTests();
    return a->getId() < b->getId();
}

void writeOutput(LinkedList<Patient*>& doneList, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Could not open output file!" << endl;
        return;
    }

    // Copy pointers into a temporary array just to sort them for printing
    // (the LinkedList itself stays untouched/unsorted).
    int n = doneList.getSize();
    Patient** sorted = new Patient*[n];

    int i = 0;
    auto current = doneList.getHead();
    while (current != nullptr) {
        sorted[i] = current->data;
        i++;
        current = current->next;
    }

    // Simple insertion sort (n is small: number of finished patients)
    for (int j = 1; j < n; j++) {
        Patient* key = sorted[j];
        int k = j - 1;
        while (k >= 0 && comesBefore(key, sorted[k])) {
            sorted[k + 1] = sorted[k];
            k--;
        }
        sorted[k + 1] = key;
    }

    for (int idx = 0; idx < n; idx++) {
        Patient* p = sorted[idx];
        outFile << p->getFinishTime() << " "
                << p->getId() << " "
                << p->getCheckInTime() << " "
                << p->getWaitTime() << " "
                << p->getVisitTime() << endl;
    }

    delete[] sorted;
    outFile.close();
}
