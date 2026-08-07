#include "Doctor.h"
#include <string>

// Default constructor
Doctor::Doctor()
    : branchNumber(0), spec(JUNIOR), shiftStartTime(0), breakAfter(0), breakDuration(0),
      patientsSeenSinceBreak(0), freeAtTime(0), onBreakUntil(-1), currentPatientId(-1) {
}

// Parameterized constructor
Doctor::Doctor(int branchNumber, Specialization spec, int shiftStartTime,
               int breakAfter, int breakDuration)
    : branchNumber(branchNumber), spec(spec), shiftStartTime(shiftStartTime),
      breakAfter(breakAfter), breakDuration(breakDuration),
      patientsSeenSinceBreak(0), freeAtTime(0), onBreakUntil(-1), currentPatientId(-1) {
}

// Getters
int Doctor::getBranchNumber() const {
    return branchNumber;
}

Specialization Doctor::getSpecialization() const {
    return spec;
}

int Doctor::getShiftStartTime() const {
    return shiftStartTime;
}

int Doctor::getBreakAfter() const {
    return breakAfter;
}

int Doctor::getBreakDuration() const {
    return breakDuration;
}

// --- Bonus 1: Status Formatting ---
std::string Doctor::getStatusString(int currentTime) const {
    // Determine title prefix based on specialization
    std::string title = (spec == SENIOR) ? "Dr S" : "Dr J";
    std::string docName = title + ": ";

    // 1. Shift not started yet
    if (currentTime < shiftStartTime) {
        return docName + "shift not started";
    }

    // 2. Currently on break
    if (onBreakUntil != -1 && currentTime < onBreakUntil) {
        return docName + "on break until t=" + std::to_string(onBreakUntil);
    }

    // 3. Busy serving a patient
    if (currentTime < freeAtTime && currentPatientId != -1) {
        return docName + "busy with patient " + std::to_string(currentPatientId) + 
               " until t=" + std::to_string(freeAtTime);
    }

    // 4. Free and available
    return docName + "free";
}
