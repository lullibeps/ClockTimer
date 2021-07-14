#include "ClockTimerFrame.h"
#include "ClockData.h"

ClockTimerFrame::ClockTimerFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                 const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    wxGridSizer *gSizer1;
    gSizer1 = new wxGridSizer(1, 2, 0, 0);

    clockDataLabel = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250, -1), 0);
    clockDataLabel->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    clockDataLabel->SetEditable(false);
    clockDataLabel->SetCanFocus(false);
    gSizer1->Add(clockDataLabel, 0, wxALL, 5);

    changeFormatButton = new wxButton(this, wxID_ANY, wxT("Change Format"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer1->Add(changeFormatButton, 0, wxALL, 5);

    bSizer1->Add(gSizer1, 1, wxEXPAND, 5);

    wxGridSizer *gSizer2;
    gSizer2 = new wxGridSizer(1, 3, 0, 0);

    timerLabel = new wxTextCtrl(this, wxID_ANY, "0:00:00:00", wxDefaultPosition, wxSize(130, -1), 0);
    timerLabel->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    timerLabel->SetEditable(false);
    timerLabel->SetCanFocus(false);
    updateTimer();
    gSizer2->Add(timerLabel, 0, wxALL, 5);

    wxWrapSizer *wSizer1;
    wSizer1 = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("hour"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->Wrap(-1);
    wSizer1->Add(m_staticText1, 0, wxALL, 5);

    hourTimer = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, 0);
    hourTimer->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    wSizer1->Add(hourTimer, 0, wxALL, 5);


    gSizer2->Add(wSizer1, 1, wxEXPAND, 5);

    wxWrapSizer *wSizer2;
    wSizer2 = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

    m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("minute"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText2->Wrap(-1);
    wSizer2->Add(m_staticText2, 0, wxALL, 5);

    minuteTimer = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, 0);
    minuteTimer->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    wSizer2->Add(minuteTimer, 0, wxALL, 5);


    gSizer2->Add(wSizer2, 1, wxEXPAND, 5);


    bSizer1->Add(gSizer2, 1, wxEXPAND, 5);

    wxGridSizer *gSizer3;
    gSizer3 = new wxGridSizer(0, 3, 0, 0);

    startButton = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer3->Add(startButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    pauseButton = new wxButton(this, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer3->Add(pauseButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    resetButton = new wxButton(this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0);
    gSizer3->Add(resetButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);


    bSizer1->Add(gSizer3, 1, wxEXPAND, 5);


    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    updateClock();

    m_clockTimer.Bind(wxEVT_TIMER, &ClockTimerFrame::onUpdateClock, this);
    m_clockTimer.Start(1000);

    m_timer.Bind(wxEVT_TIMER, &ClockTimerFrame::onUpdateTimer, this);

    changeFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::changeClockFormat),
                                nullptr, this);
    startButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::startTimer), nullptr,
                         this);
    pauseButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::pauseTimer), nullptr,
                         this);
    resetButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::resetTimer), nullptr,
                         this);
}

ClockTimerFrame::~ClockTimerFrame() {
    // Disconnect Events
    changeFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                   wxCommandEventHandler(ClockTimerFrame::changeClockFormat), nullptr, this);
    startButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::startTimer), nullptr,
                            this);
    pauseButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::pauseTimer), nullptr,
                            this);
    resetButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ClockTimerFrame::resetTimer), nullptr,
                            this);
}

void ClockTimerFrame::onUpdateClock(wxTimerEvent &) {
    updateClock();
}

void ClockTimerFrame::updateClock() {
    clockDataLabel->Clear();
    clockDataLabel->AppendText(ClockData::getClockData(format));
}

void ClockTimerFrame::changeClockFormat(wxCommandEvent &event) {
    if (format < ClockData::getNumOfFormat()) {
        format++;
    } else {
        format = 1;
    }
    updateClock();
}

void ClockTimerFrame::startTimer(wxCommandEvent &event) {
    m_startTime = wxDateTime::Now();
    m_timer.Start(1000);

    if (currentTimer == 0) {
        int hour = wxAtoi(hourTimer->GetValue());
        int minute = wxAtoi(minuteTimer->GetValue());
        wxTimeSpan timeValue(hour, minute);

        timerStartTime = timeValue;
    }
    updateTimer();
}

void ClockTimerFrame::pauseTimer(wxCommandEvent &event) {
    wxDateTime currentTime = wxDateTime::Now();
    currentTimer += currentTime - m_startTime;
    m_timer.Stop();
}

void ClockTimerFrame::resetTimer(wxCommandEvent &event) {
    m_timer.Stop();
    currentTimer = 0;
    timerLabel->Clear();
    timerLabel->AppendText("0:00:00:00");
}

void ClockTimerFrame::updateTimer() {
    if (m_timer.IsRunning()) {
        wxDateTime currentTime = wxDateTime::Now();
        wxTimeSpan elapsedTime = currentTime - m_startTime + currentTimer;
        elapsedTime = timerStartTime - elapsedTime;
        if (elapsedTime == 0 && timerStartTime != 0) {
            m_timer.Stop();
            currentTimer = 0;
            timerLabel->Clear();
            timerLabel->AppendText("0:00:00:00");
        }

        timerLabel->Clear();
        timerLabel->AppendText(elapsedTime.Format("%D:%H:%M:%S"));
    }
}

void ClockTimerFrame::onUpdateTimer(wxTimerEvent &) {
    updateTimer();
}
