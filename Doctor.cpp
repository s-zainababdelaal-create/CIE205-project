#include "Doctor.h"

Doctor::Doctor(int branchNumber, Specialization spec, int shiftStartTime,
    int breakAfter, int breakDuration)
    : branchNumber(branchNumber), spec(spec), shiftStartTime(shiftStartTime),
    breakAfter(breakAfter), breakDuration(breakDuration),
    patientsSeenSinceBreak(0), freeAtTime(0), onBreakUntil(-1), currentPatientId(-1) {
}

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