#pragma once
#include "Patient.h"

enum EventKind { CHECK_IN, LEAVE, ESCALATE };

// This class only holds data 

class Event {
private:
    EventKind kind;
    int timestamp;
    int patientId;

    // Only meaningful when kind == CHECK_IN; ignored otherwise.
    PatientType patientType;
    int branch;
    int numTests;

public:
    Event(EventKind kind, int timestamp, int patientId,
        PatientType patientType = REGULAR, int branch = 0, int numTests = 0);

    EventKind getKind() const;
    int getTimestamp() const;
    int getPatientId() const;
    PatientType getPatientType() const;
    int getBranch() const;
    int getNumTests() const;
};

