#pragma once
enum PatientType { REGULAR, EMERGENCY };
class Patient {
private:
    int id, checkInTime, branch, numTests;
    PatientType type;
    int finishTime = -1;   
    int waitTime = -1;     
    int visitTime = -1;    
    bool wasEscalated = false;
public:
    // Constructor
    Patient();
    Patient(int id, int checkInTime, int branch, int numTests, PatientType type);

    // Disable copying (prevent shallow copies / accidental duplication)
    Patient(const Patient&) = delete;
    Patient& operator=(const Patient&) = delete;

    // Getters
    int getId() const;
    int getCheckInTime() const;
    int getBranch() const;
    int getNumTests() const;
    PatientType getType() const;

    // Getters for finish stats
    int getFinishTime() const;
    int getWaitTime() const;
    int getVisitTime() const;
    bool getWasEscalated() const;

    // Setters
    void setType(PatientType newType);
    void setFinishStats(int ft, int wt, int vt);
    void setEscalated(bool escalated);
};
