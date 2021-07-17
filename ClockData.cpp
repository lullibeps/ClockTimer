//
// Created by lullibeps on 14/07/21.
//

#include <ctime>
#include <memory>
#include "ClockData.h"

std::string ClockData::getClockData() {
    time_t now = time(nullptr);
    if (useCustomData)
        now += customDataDiff;
    tm *ltm = localtime(&now);

    std::string result;
    std::string timeSpecifier;

    std::string dataDiv = "/";
    std::string timeDiv = ":";

    std::string day = std::to_string(ltm->tm_mday);
    std::string mon = std::to_string(ltm->tm_mon + 1);
    std::string year = std::to_string(ltm->tm_year + 1900);

    std::string hour = std::to_string(ltm->tm_hour);
    std::string hour12h = std::to_string(ltm->tm_hour - 12);
    std::string min = std::to_string(ltm->tm_min);
    std::string sec = std::to_string(ltm->tm_sec);

    switch (formatoData) {
        case FormatoData::europeo:
            result = day + dataDiv + mon + dataDiv + year;
            break;
        case FormatoData::cinese:
            result = year + dataDiv + mon + dataDiv + day;
            break;
        case FormatoData::statunitense:
            result = mon + dataDiv + day + dataDiv + year;
            break;
    }

    result += " - ";

    switch (formatoOrario) {
        case FormatoOrario::h12:
            if (ltm->tm_hour > 12) {
                result += hour12h + timeDiv;
                timeSpecifier = " PM";
            } else {
                result += hour + timeDiv;
                timeSpecifier = " AM";
            }
            break;
        case FormatoOrario::h24:
            result += hour + timeDiv;
            break;
    }

    result += min + timeDiv + sec + timeSpecifier;

    return result;
}

void ClockData::setFormatoData(FormatoData formatData) {
    ClockData::formatoData = formatData;
}

void ClockData::setFormatoOrario(FormatoOrario formatOrario) {
    ClockData::formatoOrario = formatOrario;
}

FormatoData ClockData::getFormatoData() const {
    return formatoData;
}

FormatoOrario ClockData::getFormatoOrario() const {
    return formatoOrario;
}

void ClockData::setCustomData(int day, int mon, int year, int hour, int min, int sec) {
    customData.tm_mday = day;
    customData.tm_mon = mon - 1;
    customData.tm_year = year - 1900;
    customData.tm_hour = hour;
    customData.tm_min = min;
    customData.tm_sec = sec;
    useCustomData = true;
    time_t now = time(nullptr);
    customDataDiff = difftime(mktime(&customData), now);
}

void ClockData::setUseCustomData(bool useCustomDate) {
    ClockData::useCustomData = useCustomDate;
}

ClockData::ClockData(FormatoData formatoData, FormatoOrario formatoOrario) : formatoData(formatoData),
                                                                             formatoOrario(formatoOrario) {
    useCustomData = false;
    customDataDiff = 0;
}

bool ClockData::isUseCustomData() const {
    return useCustomData;
}
