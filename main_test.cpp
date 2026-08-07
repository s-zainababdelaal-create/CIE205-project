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

// declared in InteractiveMode.cpp
void runInteractiveMode();

int main() {
    runInteractiveMode();
    return 0;
}
