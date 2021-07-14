//
// Created by lullibeps on 14/07/21.
//

#include <ctime>
#include <memory>
#include "ClockData.h"

std::string ClockData::getClockData(int format) {
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    char buf[80];

    strftime(buf, sizeof(buf), "%d-%m-%Y - %X", &tstruct);

    return buf;
}
