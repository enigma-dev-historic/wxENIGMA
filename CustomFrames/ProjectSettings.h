/**
* @file ProjectSettings.h
* @brief Header file of the project settings frame.
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

#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H

//(*Headers(ProjectSettings)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
//*)
#include <wx/richtext/richtextctrl.h>
#include <wx/dialog.h>
class ProjectSettings: public wxFrame
{
	public:

		ProjectSettings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ProjectSettings();

		//(*Declarations(ProjectSettings)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxRadioButton* RadioButton1;
		wxButton* Button4;
		wxComboBox* ComboBox6;
		wxNotebook* Notebook1;
		wxStaticText* StaticText2;
		wxRadioButton* RadioButton2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* Button2;
		wxPanel* Panel3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox7;
		wxComboBox* ComboBox3;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox1;
		wxPanel* Panel2;
		wxComboBox* ComboBox2;
		wxStaticText* StaticText4;
		//*)
        wxRichTextCtrl* informationCtrl;

	protected:

		//(*Identifiers(ProjectSettings)
		static const long ID_STATICTEXT10;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT11;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX1;
		static const long ID_COMBOBOX2;
		static const long ID_COMBOBOX3;
		static const long ID_COMBOBOX4;
		static const long ID_COMBOBOX5;
		static const long ID_COMBOBOX6;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(ProjectSettings)
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
