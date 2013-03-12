#include "Preferences.h"

//(*InternalHeaders(Preferences)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Preferences)
const long Preferences::ID_PANEL1 = wxNewId();
const long Preferences::ID_PANEL2 = wxNewId();
const long Preferences::ID_PANEL3 = wxNewId();
const long Preferences::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Preferences,wxFrame)
	//(*EventTable(Preferences)
	//*)
END_EVENT_TABLE()

Preferences::Preferences(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Preferences)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(272,88), wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(166,181), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(149,9), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(218,10), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Notebook1->AddPage(Panel1, _("General"), false);
	Notebook1->AddPage(Panel2, _("Editors"), false);
	Notebook1->AddPage(Panel3, _("Code Editor"), false);
	//*)
}

Preferences::~Preferences()
{
	//(*Destroy(Preferences)
	//*)
}

