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

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ClockTimerFrame
///////////////////////////////////////////////////////////////////////////////
class ClockTimerFrame : public wxFrame {
private:
    int format = 1;
    wxTimer m_clockTimer;

protected:
    wxTextCtrl *clockDataLabel;
    wxButton *changeFormatButton;
    wxTextCtrl *timerLabel;
    wxTextCtrl *hourTimer;
    wxTextCtrl *minuteTimer;
    wxStaticText *m_staticText1;
    wxStaticText *m_staticText2;
    wxButton *startButton;
    wxButton *pauseButton;
    wxButton *resetButton;

public:

    explicit ClockTimerFrame(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString,
                             const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(500, 300),
                             long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~ClockTimerFrame() override;

    void updateClock();

    void onUpdateClock(wxTimerEvent &);

    void changeClockFormat(wxCommandEvent &event);

};