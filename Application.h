//
// Created by lullibeps on 14/07/21.
//

#ifndef CLOCKTIMER_APPLICATION_H
#define CLOCKTIMER_APPLICATION_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif


class Application : public wxApp {
public:
    virtual bool OnInit() override;
};


#endif //CLOCKTIMER_APPLICATION_H
