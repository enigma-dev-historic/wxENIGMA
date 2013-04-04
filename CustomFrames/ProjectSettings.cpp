/**
* @file ProjectSettings.cpp
* @brief Source file of the project settings frame.
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

#include "ProjectSettings.h"

//(*InternalHeaders(ProjectSettings)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ProjectSettings)
const long ProjectSettings::ID_STATICTEXT10 = wxNewId();
const long ProjectSettings::ID_RADIOBUTTON1 = wxNewId();
const long ProjectSettings::ID_RADIOBUTTON2 = wxNewId();
const long ProjectSettings::ID_STATICTEXT11 = wxNewId();
const long ProjectSettings::ID_COMBOBOX7 = wxNewId();
const long ProjectSettings::ID_STATICTEXT7 = wxNewId();
const long ProjectSettings::ID_STATICTEXT8 = wxNewId();
const long ProjectSettings::ID_STATICTEXT9 = wxNewId();
const long ProjectSettings::ID_BUTTON1 = wxNewId();
const long ProjectSettings::ID_BUTTON2 = wxNewId();
const long ProjectSettings::ID_BUTTON3 = wxNewId();
const long ProjectSettings::ID_BUTTON4 = wxNewId();
const long ProjectSettings::ID_PANEL1 = wxNewId();
const long ProjectSettings::ID_STATICTEXT1 = wxNewId();
const long ProjectSettings::ID_STATICTEXT2 = wxNewId();
const long ProjectSettings::ID_STATICTEXT3 = wxNewId();
const long ProjectSettings::ID_STATICTEXT4 = wxNewId();
const long ProjectSettings::ID_STATICTEXT5 = wxNewId();
const long ProjectSettings::ID_STATICTEXT6 = wxNewId();
const long ProjectSettings::ID_COMBOBOX1 = wxNewId();
const long ProjectSettings::ID_COMBOBOX2 = wxNewId();
const long ProjectSettings::ID_COMBOBOX3 = wxNewId();
const long ProjectSettings::ID_COMBOBOX4 = wxNewId();
const long ProjectSettings::ID_COMBOBOX5 = wxNewId();
const long ProjectSettings::ID_COMBOBOX6 = wxNewId();
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
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;
	
	Create(parent, wxID_ANY, _("Project Settings"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(601,437));
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(272,192), wxSize(544,437), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxPoint(267,123), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Compatibility/Progress"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	FlexGridSizer2->Add(RadioButton1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	FlexGridSizer2->Add(RadioButton2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer2->Add(StaticText11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Sample"));
	ComboBox7 = new wxComboBox(Panel1, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	ComboBox7->SetSelection( ComboBox7->Append(_("Be really slow to better emulate game maker")) );
	ComboBox7->Append(_("Be fast to suck eggs"));
	StaticBoxSizer3->Add(ComboBox7, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Unsupported option: [Radio-multi] [pick one]"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticBoxSizer3->Add(StaticText7, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("More Samples"));
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Unsupported: [Edit] [Encryption key]"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticBoxSizer1->Add(StaticText8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Unsupported: [Checkbox] [Do stuff]"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticBoxSizer1->Add(StaticText9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Definitions"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Global Locals"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Initialization"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer1->Add(Button3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("Cleanup"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer1->Add(Button4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(FlexGridSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer3);
	BoxSizer3->Fit(Panel1);
	BoxSizer3->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(135,13), wxSize(551,402), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Compiler :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Platform :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Graphics :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Audio :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer4->Add(StaticText4, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Collision :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Widgets :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer4->Add(StaticText6, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	ComboBox1 = new wxComboBox(Panel2, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	ComboBox1->SetSelection( ComboBox1->Append(_("GNU GCC G++")) );
	ComboBox1->Append(_("GNU GCC G++ 32"));
	ComboBox1->Append(_("Clang 32"));
	ComboBox1->Append(_("Clang"));
	ComboBox1->Append(_("Android Simulator"));
	ComboBox1->Append(_("Android Compile"));
	BoxSizer5->Add(ComboBox1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(Panel2, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	BoxSizer5->Add(ComboBox2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox3 = new wxComboBox(Panel2, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	BoxSizer5->Add(ComboBox3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox4 = new wxComboBox(Panel2, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	BoxSizer5->Add(ComboBox4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox5 = new wxComboBox(Panel2, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	BoxSizer5->Add(ComboBox5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox6 = new wxComboBox(Panel2, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	BoxSizer5->Add(ComboBox6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(238,12), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Notebook1->AddPage(Panel1, _("General"), false);
	Notebook1->AddPage(Panel2, _("Systems"), false);
	Notebook1->AddPage(Panel3, _("Extensions"), false);
	
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ProjectSettings::OnClose);
	//*)

    wxRichTextAttr rchtxtAttr;
    rchtxtAttr.SetLineSpacing(wxTEXT_ATTR_LINE_SPACING_NORMAL);
    wxFont monoFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);

    informationCtrl = new wxRichTextCtrl(Panel2, wxID_ANY, _("text\ngsdfgfdg\nafsdfsdf\ndsafsdfsad\sdfsdfa\sdf\sdaf\sdf\sad\fn\nsadfsdf\ndsfasdf\ndsfasdf\nfasdf"), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL|wxEXPAND, wxDefaultValidator, _T("ID_INFOCTRL"));
    informationCtrl->SetBasicStyle(rchtxtAttr);
    informationCtrl->SetFont(monoFont);

    BoxSizer1->Add(informationCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
}

ProjectSettings::~ProjectSettings()
{
	//(*Destroy(ProjectSettings)
	//*)
}


void ProjectSettings::OnClose(wxCloseEvent& event)
{
    Hide();
}
