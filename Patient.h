#ifndef PATIENT_H
#define PATIENT_H

enum PatientType { REGULAR, EMERGENCY };

class Patient {
private:
    int id;              
    int checkInTime;     
    int branch;         
    int numTests;        
    PatientType type;    

public:
    // Constructor
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

    // Setter 
    void setType(PatientType newType);
};
#endif
