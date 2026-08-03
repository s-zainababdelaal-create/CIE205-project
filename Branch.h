#pragma once

class Branch {
private:
    int branchNumber;
    int numDoctors;

public:
    Branch(int branchNumber, int numDoctors);

    int getBranchNumber() const;
    int getNumDoctors() const;
};

