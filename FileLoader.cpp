#include <iostream>
#include <fstream>
#include "Utilities.h"
#include "Doctor.h"
#include "Patient.h"
#include "Priority_Queue.h"
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Could not open the file!" << endl;
        return 1;
    }

    int B, SU, WU, PS, PJ;
    file >> B >> SU >> WU >> PS >> PJ;

    cout << "Branches: " << B << endl;
    cout << "Setup: " << SU << endl;
    cout << "WrapUp: " << WU << endl;
    cout << "Senior per test: " << PS << endl;
    cout << "Junior per test: " << PJ << endl;

    // TEMPORARY: doctors-per-branch counts, read into a plain array.
    // Replace with the real per-branch doctor LinkedList once Nada's LinkedList is ready.
    int doctorsPerBranch[50];
    for (int i = 0; i < B; i++) {
        file >> doctorsPerBranch[i];
        cout << "Branch " << (i + 1) << " has " << doctorsPerBranch[i] << " doctors" << endl;
    }

    int totalDoctors = 0;
    for (int i = 0; i < B; i++) totalDoctors += doctorsPerBranch[i];

    // TEMPORARY fixed-size array, replace with inserting into each branch's LinkedList
    Doctor doctors[100];
    for (int i = 0; i < totalDoctors; i++) {
        int br, sh, ba, bd;
        char specChar;
        file >> br >> specChar >> sh >> ba >> bd;

        Specialization spec = (specChar == 'S') ? SENIOR : JUNIOR;
        doctors[i] = Doctor(br, spec, sh, ba, bd);

        cout << "Doctor " << i << ": branch=" << doctors[i].getBranchNumber()
            << " shiftStart=" << doctors[i].getShiftStartTime() << endl;
    }

    int autoEscalateLimit;
    file >> autoEscalateLimit;
    cout << "AutoE: " << autoEscalateLimit << endl;

    int M;
    file >> M;
    cout << "Number of events: " << M << endl;

    // TEMPORARY: events read into plain arrays, one per event type.
    // Replace with pushing check-ins into Haneen's Emergency Queue / the Regular
    // PriorityQueue (once ready), and applying L/U events to move patients between them.
    PriorityQueue<Patient> regularPatients;


    for (int i = 0; i < M; i++) {
        char eventType;
        file >> eventType;

        if (eventType == 'C') {
            char typeChar;
            int ts, id, br, tests;
            file >> typeChar >> ts >> id >> br >> tests;

            PatientType type = (typeChar == 'E') ? EMERGENCY : REGULAR;
            Patient* p = new Patient(id, ts, br, tests, type);

            if (type == EMERGENCY) {
                // يتحط في Queue بتاعة حنين (لو جاهزة)
            }
            else {
                int priority = ts + ALPHA * tests; // معادلة الأولوية المتفق عليها
                regularPatients.enqueue(p, priority);
            }


            cout << "Check-in: id=" << id << " type=" << typeChar
                << " ts=" << ts << " branch=" << br << " tests=" << tests << endl;
        }

        else if (eventType == 'L') {
            int ts, id;
            file >> ts >> id;
            Patient* left = regularPatients.removeByID(id);
            if (left != nullptr) {
                // هنقرر نحطه فين (Done/Left list) بعد شوية
            }
        }
        else if (eventType == 'U') {
            int ts, id;
            file >> ts >> id;
            Patient* escalated = regularPatients.removeByID(id);
            if (escalated != nullptr) {
                // ده اللي زميلتك هتحطه في emergencyPatients.enqueue(escalated)
            }

        }
    }

    file.close();
    return 0;
}