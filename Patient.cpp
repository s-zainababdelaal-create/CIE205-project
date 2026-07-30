#include "Patient.h"

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

void Patient::setType(PatientType newType) {
    type = newType;
}
