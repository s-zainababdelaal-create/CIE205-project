#include "Event.h"

Event::Event(EventKind kind, int timestamp, int patientId,
    PatientType patientType, int branch, int numTests)
    : kind(kind), timestamp(timestamp), patientId(patientId),
    patientType(patientType), branch(branch), numTests(numTests) {
}

EventKind Event::getKind() const {
    return kind;
}

int Event::getTimestamp() const {
    return timestamp;
}

int Event::getPatientId() const {
    return patientId;
}

PatientType Event::getPatientType() const {
    return patientType;
}

int Event::getBranch() const {
    return branch;
}

int Event::getNumTests() const {
    return numTests;
}
