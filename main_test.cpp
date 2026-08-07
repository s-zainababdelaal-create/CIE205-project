#include "Patient.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// declared in dummy_done_list.cpp
void makeDummyDoneList(LinkedList<Patient*>& doneList);

// declared in OutputWriter.cpp
void writeOutput(LinkedList<Patient*>& doneList, const string& filename);

// declared in Statistics.cpp
void printStatistics(LinkedList<Patient*>& doneList);

int main() {
    LinkedList<Patient*> doneList;
    makeDummyDoneList(doneList);

    writeOutput(doneList, "output_test.txt");
    printStatistics(doneList);

    cout << "Done! Check output_test.txt for the result." << endl;

    return 0;
}