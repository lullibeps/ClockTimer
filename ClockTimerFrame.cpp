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

}
