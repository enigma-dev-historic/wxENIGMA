/**
* @file Preferences.h
* @brief Header file of the preferences frame.
*
* Add description here...
*
* @section License
*
* Copyright (C) 2013 Robert B. Colton
* This file is part of wxENIGMA.
*
* wxENIGMA is free software: you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation, version 3 of the License, or (at your option) any later version.
*
* wxENIGMA is distributed in the hope that it will be useful, but WITHOUT ANY
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
* PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* wxENIGMA. If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef PREFERENCES_H
#define PREFERENCES_H

//(*Headers(Preferences)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class Preferences: public wxFrame
{
	public:

		Preferences(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Preferences();

		//(*Declarations(Preferences)
		wxNotebook* Notebook1;
		wxButton* Button1;
		wxPanel* Panel1;
		wxButton* Button2;
		wxPanel* Panel3;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(Preferences)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Preferences)
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
