//
// Created by lullibeps on 14/07/21.
//

#include <ctime>
#include <memory>
#include "ClockData.h"

int ClockData::numOfFormat = 4;

std::string ClockData::getClockData(int format) {
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    char buf[80];

    switch (format) {
        case 1:
            strftime(buf, sizeof(buf), "%d-%m-%Y - %X", &tstruct);
            break;
        case 2:
            strftime(buf, sizeof(buf), "%d/%m/%Y - %X", &tstruct);
            break;
        case 3:
            strftime(buf, sizeof(buf), "%m-%d-%Y - %X", &tstruct);
            break;
        case 4:
            strftime(buf, sizeof(buf), "%m/%d/%Y - %X", &tstruct);
            break;
        default:
            strftime(buf, sizeof(buf), "%d/%m/%Y - %X", &tstruct);
    }

    return buf;
}

int ClockData::getNumOfFormat() {
    return numOfFormat;
}
