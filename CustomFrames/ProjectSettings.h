#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H

//(*Headers(ProjectSettings)
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/frame.h>
//*)

class ProjectSettings: public wxFrame
{
	public:

		ProjectSettings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ProjectSettings();

		//(*Declarations(ProjectSettings)
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxPanel* Panel3;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(ProjectSettings)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(ProjectSettings)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
