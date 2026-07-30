#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities {
private:
    int setupDuration;      // SU
    int wrapUpDuration;     // WU
    int seniorPerTest;      // PS
    int juniorPerTest;      // PJ
    int autoEscalateLimit;  // AutoE

public:
    Utilities(int setupDuration, int wrapUpDuration, int seniorPerTest,
        int juniorPerTest, int autoEscalateLimit);

    int getSetupDuration() const;
    int getWrapUpDuration() const;
    int getSeniorPerTest() const;
    int getJuniorPerTest() const;
    int getAutoEscalateLimit() const;
};

#endif