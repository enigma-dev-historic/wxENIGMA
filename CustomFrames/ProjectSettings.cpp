#include "ProjectSettings.h"

//(*InternalHeaders(ProjectSettings)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ProjectSettings)
const long ProjectSettings::ID_PANEL1 = wxNewId();
const long ProjectSettings::ID_PANEL2 = wxNewId();
const long ProjectSettings::ID_PANEL3 = wxNewId();
const long ProjectSettings::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProjectSettings,wxFrame)
	//(*EventTable(ProjectSettings)
	//*)
END_EVENT_TABLE()

ProjectSettings::ProjectSettings(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ProjectSettings)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(272,192), wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(267,123), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(135,13), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(238,12), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Notebook1->AddPage(Panel1, _("General"), false);
	Notebook1->AddPage(Panel2, _("Plugins"), false);
	Notebook1->AddPage(Panel3, _("Systems"), false);
	//*)
}

ProjectSettings::~ProjectSettings()
{
	//(*Destroy(ProjectSettings)
	//*)
}

