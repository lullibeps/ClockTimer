///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 24 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once


#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <cstring>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/wrapsizer.h>
#include <wx/frame.h>
#include "wx/timer.h"
#include "ClockData.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ClockTimerFrameformat
///////////////////////////////////////////////////////////////////////////////
class ClockTimerFrame : public wxFrame {
private:
    ClockData clockData;
    wxTimer m_clockTimer;
    wxTimeSpan currentTimer = 0;
    wxTimeSpan timerStartTime = 0;
    wxTimer m_timer;
    wxDateTime m_startTime;

protected:
    wxTextCtrl *clockDataLabel;
    wxButton *changeTimeFormatButton;
    wxButton *changeDataFormatButton;
    wxTextCtrl *timerLabel;
    wxTextCtrl *hourTimer;
    wxTextCtrl *minuteTimer;
    wxStaticText *m_staticText1;
    wxStaticText *m_staticText2;
    wxButton *startButton;
    wxButton *pauseButton;
    wxButton *resetButton;

public:

    ClockTimerFrame(wxWindow *parent, FormatoData formatoData, FormatoOrario formatoOrario, wxWindowID id = wxID_ANY,
                    const wxString &title = wxEmptyString,
                    const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(520, 300),
                    long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~ClockTimerFrame() override;

    void updateClock();

    void onUpdateClock(wxTimerEvent &);

    void changeTimeFormat(wxCommandEvent &event);

    void changeDataFormat(wxCommandEvent &event);

    void startTimer(wxCommandEvent &event);

    void pauseTimer(wxCommandEvent &event);

    void resetTimer(wxCommandEvent &event);

    void updateTimer();

    void onUpdateTimer(wxTimerEvent &);

};