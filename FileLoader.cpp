#include <iostream>
#include <fstream>
#include "Utilities.h"
#include "Doctor.h"
#include "Patient.h"
#include "Branch.h"
#include "Event.h"
#include "LinkedList.h"
using namespace std;
int main() {
    ifstream file("input.txt");     //opening the input file
    if (!file) {
        cout << "Could not open the file!" << endl;
        return 1;
    }
    
    //cout lines here are only for the purpose of tetsing whether 
    // the FileLoader interprets data correctly and will be removed later on
    //header line: B SU WU PS PJ 
    int B, SU, WU, PS, PJ;
    file >> B >> SU >> WU >> PS >> PJ; // read the 5 header values in file order
    cout << "Branches: " << B << endl;
    cout << "Setup: " << SU << endl;
    cout << "WrapUp: " << WU << endl;
    cout << "Senior per test: " << PS << endl;
    cout << "Junior per test: " << PJ << endl;

    // Branch lines: doctors-per-branch counts, one real Branch created per line
    LinkedList<Branch*> branches; 
    Branch** branchByNumber = new Branch * [B + 1]; // 1-indexed lookup, used only while loading doctors below
    int totalDoctors = 0; //across all branches
    for (int i = 1; i <= B; i++) {
        int ni;
        file >> ni; 
        totalDoctors += ni;
        Branch* branch = new Branch(i); // heap-allocated so branches.insertEnd can store a pointer, not a copy
        branches.insertEnd(branch);
        branchByNumber[i] = branch; // remember this branch by number for the doctor loop below
        cout << "Branch " << i << " declares " << ni << " doctors" << endl;
    }
    
    // doctor lines: BR SP SH BA BD 
    for (int i = 0; i < totalDoctors; i++) {
        int br, sh, ba, bd;
        char specChar;
        file >> br >> specChar >> sh >> ba >> bd; // br shows which branch this doctor belongs to
        Specialization spec = (specChar == 'S') ? SENIOR : JUNIOR; // convert file's S/J char to our enum
        Doctor doctor(br, spec, sh, ba, bd);
        branchByNumber[br]->getDoctors().insertEnd(doctor); // look up the right branch by br, attach the doctor to it
        cout << "Doctor: branch=" << doctor.getBranchNumber()
            << " shiftStart=" << doctor.getShiftStartTime() << endl;
    }
    delete[] branchByNumber; // only a lookup helper, branches keep the real doctors
    // confirm each branch actually holds the doctor
    auto* branchNode = branches.getHead(); // auto avoids naming LinkedList's private Node type
    while (branchNode != nullptr) {
        Branch* b = branchNode->data;
        cout << "Branch " << b->getBranchNumber() << " loaded "
            << b->getNumDoctors() << " doctors" << endl; 
        branchNode = branchNode->next; // advance to the next branch in the list
    }

    
    //AutoE
    int autoEscalateLimit;
    file >> autoEscalateLimit;
    cout << "AutoE: " << autoEscalateLimit << endl;
    Utilities utilities(SU, WU, PS, PJ, autoEscalateLimit); // built once all 5 values are known
    //M events: parsed and stored only, to be completed using SimulationEngine in checkpoint 2
    int M;
    file >> M;
    cout << "Number of events: " << M << endl;
    LinkedList<Event*> events; // not used yet
    for (int i = 0; i < M; i++) {
        char eventType;
        file >> eventType; // C, L, or U decides which fields to read next
        if (eventType == 'C') {
            char typeChar;
            int ts, id, br, tests;
            file >> typeChar >> ts >> id >> br >> tests;
            PatientType type = (typeChar == 'E') ? EMERGENCY : REGULAR; 
            events.insertEnd(new Event(CHECK_IN, ts, id, type, br, tests)); 
        }
        else if (eventType == 'L') {
            int ts, id;
            file >> ts >> id;
            events.insertEnd(new Event(LEAVE, ts, id));
        }
        else if (eventType == 'U') {
            int ts, id;
            file >> ts >> id;
            events.insertEnd(new Event(ESCALATE, ts, id));
        }
    }
    file.close();
    cout << "Loaded " << branches.getSize() << " branches and "
        << events.getSize() << " events." << endl;
    /*
     * CHECKPOINT 2 PLACEHOLDER
     * SimulationEngine will take `utilities`, `branches`, and `events` from
     * here and run the tick-by-tick loop: walk `events` in order, and only
     * once the simulation clock reaches an event's timestamp, act on it 
     * create a Patient and push it into the Emergency Queue or Regular
     * PriorityQueue, apply L/U events, check doctor availability, etc.
     * None of that logic belongs in the file loader.
     */
    return 0;
}
