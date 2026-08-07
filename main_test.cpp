// Temporary test driver — NOT the real main.cpp of the project.
// Just used to check that Task 7 (writeOutput) works correctly
// before the real simulation engine is ready.

#include "Patient.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// declared in dummy_done_list.cpp
void makeDummyDoneList(LinkedList<Patient*>& doneList);

// declared in OutputWriter.cpp
void writeOutput(LinkedList<Patient*>& doneList, const string& filename);

int main() {
    LinkedList<Patient*> doneList;
    makeDummyDoneList(doneList);

    writeOutput(doneList, "output_test.txt");

    cout << "Done! Check output_test.txt for the result." << endl;

    return 0;
}