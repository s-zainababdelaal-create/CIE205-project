#include "Patient.h"

Patient::Patient()
    : id(0), checkInTime(0), branch(0), numTests(0), type(REGULAR) {
}

Patient::Patient(int id, int checkInTime, int branch, int numTests, PatientType type)
    : id(id), checkInTime(checkInTime), branch(branch), numTests(numTests), type(type) {
}

int Patient::getId() const {
    return id;
}

int Patient::getCheckInTime() const {
    return checkInTime;
}

int Patient::getBranch() const {
    return branch;
}

int Patient::getNumTests() const {
    return numTests;
}

PatientType Patient::getType() const {
    return type;
}

int Patient::getFinishTime() const {
    return finishTime;
}

int Patient::getWaitTime() const {
    return waitTime;
}

int Patient::getVisitTime() const {
    return visitTime;
}

void Patient::setType(PatientType newType) {
    type = newType;
}

void Patient::setFinishStats(int ft, int wt, int vt) {
    finishTime = ft;
    waitTime = wt;
    visitTime = vt;
}
