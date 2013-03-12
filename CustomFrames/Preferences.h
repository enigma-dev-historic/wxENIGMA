#ifndef PREFERENCES_H
#define PREFERENCES_H

//(*Headers(Preferences)
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/frame.h>
//*)

class Preferences: public wxFrame
{
	public:

		Preferences(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Preferences();

		//(*Declarations(Preferences)
		wxNotebook* Notebook1;
		wxPanel* Panel1;
		wxPanel* Panel3;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(Preferences)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(Preferences)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
