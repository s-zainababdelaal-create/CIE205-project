#pragma once
#include "Doctor.h"
#include "LinkedList.h"

class Branch {
private:
    int branchNumber;
    LinkedList<Doctor> doctors;

public:
    Branch(int branchNumber);

    Branch(const Branch&) = delete;
    Branch& operator=(const Branch&) = delete;

    int getBranchNumber() const;
    int getNumDoctors() const;
    LinkedList<Doctor>& getDoctors();
};
