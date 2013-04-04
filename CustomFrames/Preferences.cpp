/**
* @file Preferences.cpp
* @brief Source file of the preferences frame.
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
const long Preferences::ID_BUTTON1 = wxNewId();
const long Preferences::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Preferences,wxFrame)
	//(*EventTable(Preferences)
	//*)
END_EVENT_TABLE()

Preferences::Preferences(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Preferences)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Preferences"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(396,374));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(272,289), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Notebook1->AddPage(Panel1, _("Page name"), false);
	Notebook1->AddPage(Panel2, _("Page name"), false);
	Notebook1->AddPage(Panel3, _("Page name"), false);
	BoxSizer1->Add(Notebook1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Preferences::OnClose);
	//*)
}

Preferences::~Preferences()
{
	//(*Destroy(Preferences)
	//*)
}


void Preferences::OnClose(wxCloseEvent& event)
{
    Hide();
}
