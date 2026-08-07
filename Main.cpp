#include <iostream>
#include "SimulationEngine.h"
using namespace std;

int main() {
    int modeChoice = 1;
    cout << "Select Run Mode:\n";
    cout << "[1] Silent Mode (Default)\n";
    cout << "[2] Interactive Mode\n";
    cout << "Enter choice (1 or 2): ";
    cin >> modeChoice;

    // Clear input buffer so cin.get() works properly in interactive mode
    cin.ignore(1000, '\n');

    bool isInteractive = (modeChoice == 2);

    // Instantiate and run the simulation engine with the selected mode
    SimulationEngine engine(isInteractive);
    engine.runSimulation();

    return 0;
}
