/**
* @file AboutFrame.h
* @brief Header file of the about frame.
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

#ifndef ABOUTFRAME_H
#define ABOUTFRAME_H

//(*Headers(AboutFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/frame.h>
//*)
#include <wx/richtext/richtextctrl.h>

class AboutFrame: public wxFrame
{
	public:

		AboutFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AboutFrame();

		//(*Declarations(AboutFrame)
		wxNotebook* Notebook1;
		wxStaticBitmap* StaticBitmap1;
		//*)

        wxRichTextCtrl* informationCtrl;
        wxRichTextCtrl* licenseCtrl;
        wxRichTextCtrl* contributorCtrl;

	protected:

		//(*Identifiers(AboutFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(AboutFrame)
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
