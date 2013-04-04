/**
* @file AboutFrame.cpp
* @brief Source file of the about frame.
*
* The about frame shows information about the IDE, a list of contributors, as well as license information.
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

#include "AboutFrame.h"

//(*InternalHeaders(AboutFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(AboutFrame)
const long AboutFrame::ID_STATICBITMAP1 = wxNewId();
const long AboutFrame::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AboutFrame,wxFrame)
	//(*EventTable(AboutFrame)
	//*)
END_EVENT_TABLE()

AboutFrame::AboutFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AboutFrame)
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxTRANSPARENT_WINDOW, _T("wxID_ANY"));
	SetClientSize(wxSize(487,382));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./Resources/EDE_about_banner.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	BoxSizer1->Add(StaticBitmap1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(376,282), 0, _T("ID_NOTEBOOK1"));
	BoxSizer1->Add(Notebook1, 2, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&AboutFrame::OnClose);
	//*)

    wxRichTextAttr rchtxtAttr;
    rchtxtAttr.SetLineSpacing(wxTEXT_ATTR_LINE_SPACING_NORMAL);
    wxFont monoFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);

    informationCtrl = new wxRichTextCtrl(Notebook1, wxID_ANY, _("text"), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_INFOCTRL"));
    informationCtrl->SetBasicStyle(rchtxtAttr);
    informationCtrl->SetFont(monoFont);

    licenseCtrl = new wxRichTextCtrl(Notebook1, wxID_ANY, _("text"), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_INFOCTRL"));
    licenseCtrl->SetBasicStyle(rchtxtAttr);
    licenseCtrl->SetFont(monoFont);

    contributorCtrl = new wxRichTextCtrl(Notebook1, wxID_ANY, _("Robert B. Colton : Lead Developer/Founder"), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_INFOCTRL"));
    contributorCtrl->SetBasicStyle(rchtxtAttr);
    contributorCtrl->SetFont(monoFont);

    informationCtrl->DoLoadFile("Resources/information.txt", wxRICHTEXT_TYPE_ANY);
    licenseCtrl->DoLoadFile("Resources/license.txt", wxRICHTEXT_TYPE_ANY);
    contributorCtrl->DoLoadFile("Resources/contributors.txt", wxRICHTEXT_TYPE_ANY);

    Notebook1->AddPage(informationCtrl, _("Information"));
    Notebook1->AddPage(licenseCtrl, _("License"));
    Notebook1->AddPage(contributorCtrl, _("Contributors"));
}

AboutFrame::~AboutFrame()
{
	//(*Destroy(AboutFrame)
	//*)
}

void AboutFrame::OnClose(wxCloseEvent& event)
{
    Hide();
}
