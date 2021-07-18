//
// Created by lullibeps on 17/07/21.
//

#include "Countdown.h"

bool Countdown::startTimer(int hour, int min) {

    startTime = wxDateTime::Now();

    if (currentPausedTime == 0) {
        if (hour < 0 || min < 0 || hour + min <= 0) {
            return false;
        } else {
            wxTimeSpan timeValue(hour, min);
            countdownStartTime = timeValue;
        }
    }

    paused = false;

    return true;

}

void Countdown::pauseTimer() {
    currentTime = wxDateTime::Now();

    currentPausedTime += currentTime - startTime;

    paused = true;
}

void Countdown::resetTimer() {
    currentPausedTime = 0;
    countdownStartTime = 0;
    countdownTime = 0;
    paused = true;
}

void Countdown::updateCountdownTime() {
    if (!paused) {
        currentTime = wxDateTime::Now();
        countdownTime = countdownStartTime - (currentTime - startTime + currentPausedTime);
    } else {
        countdownTime = countdownStartTime - (currentPausedTime);
    }

    if (countdownTime == 0) {
        resetTimer();
    }
}

const wxTimeSpan &Countdown::getCountdownTime() {
    updateCountdownTime();
    return countdownTime;
}
