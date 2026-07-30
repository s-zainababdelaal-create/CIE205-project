#include "Utilities.h"

Utilities::Utilities(int setupDuration, int wrapUpDuration, int seniorPerTest,
    int juniorPerTest, int autoEscalateLimit)
    : setupDuration(setupDuration), wrapUpDuration(wrapUpDuration),
    seniorPerTest(seniorPerTest), juniorPerTest(juniorPerTest),
    autoEscalateLimit(autoEscalateLimit) {
}

int Utilities::getSetupDuration() const {
    return setupDuration;
}

int Utilities::getWrapUpDuration() const {
    return wrapUpDuration;
}

int Utilities::getSeniorPerTest() const {
    return seniorPerTest;
}

int Utilities::getJuniorPerTest() const {
    return juniorPerTest;
}

int Utilities::getAutoEscalateLimit() const {
    return autoEscalateLimit;
}