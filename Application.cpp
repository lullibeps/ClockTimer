//
// Created by lullibeps on 14/07/21.
//

#include "Application.h"
#include "ClockTimerFrame.h"

wxIMPLEMENT_APP(Application);

bool Application::OnInit() {

    ClockTimerFrame *frame = new ClockTimerFrame(NULL, FormatoData::europeo, FormatoOrario::h24);
    frame->Show(true);
    return true;
}
