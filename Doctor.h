
   #pragma once
#include <string>

enum Specialization { SENIOR, JUNIOR };

class Doctor {
private:
    int branchNumber;
    Specialization spec;
    int shiftStartTime;
    int breakAfter;
    int breakDuration;

    // Runtime state (Checkpoint 2)
    int patientsSeenSinceBreak;
    int freeAtTime;          // Time when doctor finishes current patient
    int onBreakUntil;        // -1 if not currently on break
    int currentPatientId;    // -1 if not currently serving anyone

public:
    Doctor(); // Default constructor
    Doctor(int branchNumber, Specialization spec, int shiftStartTime, int breakAfter, int breakDuration);

    // --- Task 2: Doctor Availability ---
    bool isFree(int currentTimestamp) const {
        // 1. Shift has not started yet
        if (currentTimestamp < shiftStartTime) {
            return false;
        }
        // 2. Busy with a patient
        if (currentTimestamp < freeAtTime) {
            return false;
        }
        // 3. Currently on break
        if (onBreakUntil != -1 && currentTimestamp < onBreakUntil) {
            return false;
        }

        return true;
    }

    // --- Bonus 1: Status Formatting ---
    // Generates a formatted string representing the doctor's current status
    std::string getStatusString(int currentTime) const;

    // --- Setters for Task 2 & Simulation ---
    void setFreeAtTime(int finishTime) {
        this->freeAtTime = finishTime;
    }

    void setOnBreakUntil(int breakEndTime) {
        this->onBreakUntil = breakEndTime;
    }

    void setCurrentPatientId(int patientId) {
        this->currentPatientId = patientId;
    }

    // --- Getters ---
    int getBranchNumber() const;
    Specialization getSpecialization() const;
    int getShiftStartTime() const;
    int getBreakAfter() const;
    int getBreakDuration() const;
    int getFreeAtTime() const { return freeAtTime; }
    int getCurrentPatientId() const { return currentPatientId; }
};
