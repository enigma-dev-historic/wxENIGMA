#ifndef MAINSTATUSBAR_H_INCLUDED
#define MAINSTATUSBAR_H_INCLUDED

// NO FORWARD DECLARATION NEEDED

#include <wx/statusbr.h>
#include <wx/gauge.h>

class MainStatusbar : public wxStatusBar
{
    public:
    wxGauge* progressGauge;

    MainStatusbar(wxWindow* parent, const long id = wxID_ANY);
    virtual ~MainStatusbar();

    void SetProgress(int progress);

    private:

};

#endif // MAINSTATUSBAR_H_INCLUDED
