#include "Branch.h"

Branch::Branch(int branchNumber)
    : branchNumber(branchNumber) {
}

int Branch::getBranchNumber() const {
    return branchNumber;
}

int Branch::getNumDoctors() const {
    return doctors.getSize();
}

LinkedList<Doctor>& Branch::getDoctors() {
    return doctors;
}
