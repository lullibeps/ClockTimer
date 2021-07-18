#include "ClockTimerFrame.h"
#include "ClockData.h"

ClockTimerFrame::ClockTimerFrame(wxWindow *parent, FormatoData formatoData, FormatoOrario formatoOrario, wxWindowID id,
                                 const wxString &title, const wxPoint &pos,
                                 const wxSize &size, long style) : clockData(formatoData, formatoOrario),
                                                                   wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    wxWrapSizer *wSizer3;
    wSizer3 = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

    clockDataLabel = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(280, -1), 0);
    clockDataLabel->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    clockDataLabel->SetEditable(false);
    clockDataLabel->SetCanFocus(false);
    wSizer3->Add(clockDataLabel, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    changeTimeFormatButton = new wxButton(this, wxID_ANY, wxT("Change Time"), wxDefaultPosition, wxDefaultSize, 0);
    wSizer3->Add(changeTimeFormatButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    changeDataFormatButton = new wxButton(this, wxID_ANY, wxT("Change Data"), wxDefaultPosition, wxDefaultSize, 0);
    wSizer3->Add(changeDataFormatButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    bSizer1->Add(wSizer3, 1, wxEXPAND, 5);

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
    pauseButton->Enable(false);
    gSizer3->Add(pauseButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    resetButton = new wxButton(this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0);
    resetButton->Enable(false);
    gSizer3->Add(resetButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);


    bSizer1->Add(gSizer3, 1, wxEXPAND, 5);


    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    //clockData.setCustomData(25,12,2018,16,30,0);

    updateClock();

    m_clockTimer.Bind(wxEVT_TIMER, &ClockTimerFrame::onUpdateClock, this);
    m_clockTimer.Start(1000);

    m_timer.Bind(wxEVT_TIMER, &ClockTimerFrame::onUpdateTimer, this);

    changeTimeFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(ClockTimerFrame::changeTimeFormat),
                                    nullptr, this);
    changeDataFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(ClockTimerFrame::changeDataFormat),
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
    changeTimeFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                       wxCommandEventHandler(ClockTimerFrame::changeTimeFormat), nullptr, this);
    changeDataFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(ClockTimerFrame::changeDataFormat),
                                    nullptr, this);
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
    clockDataLabel->AppendText(clockData.getClockData());
}

void ClockTimerFrame::changeTimeFormat(wxCommandEvent &event) {
    switch (clockData.getFormatoOrario()) {
        case FormatoOrario::h24:
            clockData.setFormatoOrario(FormatoOrario::h12);
            break;
        case FormatoOrario::h12:
            clockData.setFormatoOrario(FormatoOrario::h24);
            break;
    }
    updateClock();
}

void ClockTimerFrame::changeDataFormat(wxCommandEvent &event) {
    switch (clockData.getFormatoData()) {
        case FormatoData::europeo:
            clockData.setFormatoData(FormatoData::cinese);
            break;
        case FormatoData::cinese:
            clockData.setFormatoData(FormatoData::statunitense);
            break;
        case FormatoData::statunitense:
            clockData.setFormatoData(FormatoData::europeo);
            break;
    }
    updateClock();
}

void ClockTimerFrame::startTimer(wxCommandEvent &event) {

    int hour = wxAtoi(hourTimer->GetValue());
    int minute = wxAtoi(minuteTimer->GetValue());

    if (myTimer.startTimer(hour, minute)) {
        m_timer.Start(1000);

        startButton->Enable(false);
        pauseButton->Enable(true);
        resetButton->Enable(true);

        updateTimer();
    }
}

void ClockTimerFrame::pauseTimer(wxCommandEvent &event) {
    m_timer.Stop();

    myTimer.pauseTimer();

    pauseButton->Enable(false);
    startButton->Enable(true);
}

void ClockTimerFrame::resetTimer(wxCommandEvent &event) {
    m_timer.Stop();

    myTimer.resetTimer();

    timerLabel->Clear();
    timerLabel->AppendText("0:00:00:00");

    resetButton->Enable(false);
    pauseButton->Enable(false);
    startButton->Enable(true);
}

void ClockTimerFrame::updateTimer() {
    if (m_timer.IsRunning()) {

        wxTimeSpan countdownTime = myTimer.getCountdownTime();

        if (countdownTime == 0) {
            m_timer.Stop();
        }

        timerLabel->Clear();
        timerLabel->AppendText(countdownTime.Format("%D:%H:%M:%S"));
    }
}

void ClockTimerFrame::onUpdateTimer(wxTimerEvent &) {
    updateTimer();
}
