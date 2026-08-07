#include <iostream>
using namespace std;

void runInteractiveMode() {
    int choice = -1;

    while (choice != 4) {
        cout << "\n===== Hospital Simulation - Interactive Mode =====" << endl;
        cout << "1. Show finished patients" << endl;
        cout << "2. Show statistics" << endl;
        cout << "3. Export finished patients to output.txt" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
    }

    cout << "Goodbye!" << endl;
}
