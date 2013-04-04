#include "MainStatusbar.h"

MainStatusbar::MainStatusbar(wxWindow* parent, const long id)
: wxStatusBar(parent, id, wxST_SIZEGRIP, "MainStatusbar")
{
    progressGauge = new wxGauge(this, wxID_ANY, 100, wxPoint(60,3), wxSize(60, GetSize().GetHeight() - 6), wxGA_SMOOTH, wxDefaultValidator);
	progressGauge->SetValue(0);
}

MainStatusbar::~MainStatusbar()
{

}

void MainStatusbar::SetProgress(int progress)
{
    progressGauge->SetValue(progress);
}
