#include "Branch.h"

Branch::Branch(int branchNumber, int numDoctors)
    : branchNumber(branchNumber), numDoctors(numDoctors) {
}

int Branch::getBranchNumber() const {
    return branchNumber;
}

int Branch::getNumDoctors() const {
    return numDoctors;
}