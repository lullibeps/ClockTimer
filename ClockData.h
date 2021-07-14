//
// Created by lullibeps on 14/07/21.
//

#ifndef CLOCKTIMER_CLOCKDATA_H
#define CLOCKTIMER_CLOCKDATA_H

class ClockData {
private:
    static int numOfFormat;
public:
    static std::string getClockData(int format);

    static int getNumOfFormat();
};

#endif //CLOCKTIMER_CLOCKDATA_H
