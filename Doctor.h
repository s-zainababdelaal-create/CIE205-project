#ifndef DOCTOR_H
#define DOCTOR_H

enum Specialization { SENIOR, JUNIOR };

class Doctor {
private:
    int branchNumber;
    Specialization spec;
    int shiftStartTime;
    int breakAfter;
    int breakDuration;

    // Runtime state, used later in Checkpoint 2's simulation logic
    int patientsSeenSinceBreak;
    int freeAtTime;
    int onBreakUntil;    // -1 if not currently on break
    int currentPatientId; // -1 if not currently serving anyone

public:
    Doctor(); // default constructor, needed for array declarations
    Doctor(int branchNumber, Specialization spec, int shiftStartTime,
        int breakAfter, int breakDuration);

    int getBranchNumber() const;
    Specialization getSpecialization() const;
    int getShiftStartTime() const;
    int getBreakAfter() const;
    int getBreakDuration() const;
};

#endif