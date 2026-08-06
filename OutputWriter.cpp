#include "Patient.h"
#include "LinkedList.h"
#include <fstream>
using namespace std;

void writeOutput(LinkedList<Patient*>& doneList, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Could not open output file!" << endl;
        return;
    }

    LinkedList<Patient*>::Node* current = doneList.getHead();
    while (current != nullptr) {
        Patient* p = current->data;
        outFile << p->getFinishTime() << " "
                << p->getId() << " "
                << p->getCheckInTime() << " "
                << p->getWaitTime() << " "
                << p->getVisitTime() << endl;
        current = current->next;
    }

    outFile.close();
}
