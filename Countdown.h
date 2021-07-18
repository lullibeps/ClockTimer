//
// Created by lullibeps on 17/07/21.
//

#ifndef CLOCKTIMER_COUNTDOWN_H
#define CLOCKTIMER_COUNTDOWN_H

#include "wx/timer.h"

class Countdown {
private:
    wxDateTime startTime; // ora di inizio quando si preme start
    wxTimeSpan countdownStartTime = 0; // ore e minuti in input del countdown
    wxTimeSpan currentPausedTime = 0; // tempo trascorso quando si preme pausa
    wxDateTime currentTime; // ora di quando si preme pausa
    wxTimeSpan countdownTime; // tempo rimasto, output
    bool paused = true; // boolean per sapere se sono in pausa


    void updateCountdownTime();

public:
    bool startTimer(int hour = 0, int min = 0);

    void pauseTimer();

    void resetTimer();

    const wxTimeSpan &getCountdownTime();

};


#endif //CLOCKTIMER_COUNTDOWN_H
