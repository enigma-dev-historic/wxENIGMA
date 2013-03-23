/**
* @file BuildToolbar.h
* @brief Header file of the build toolbar.
*
* Write a description about the file here...
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

#ifndef BUILDTOOLBAR_H_INCLUDED
#define BUILDTOOLBAR_H_INCLUDED

class BuildToolbar : public wxAuiToolBar
{
    public:

    BuildToolbar(wxWindow* parent, const long id = wxID_ANY)
    : wxAuiToolBar(parent, id, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE)
    {

    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/stop_red.png"))), wxNullBitmap, wxITEM_NORMAL, _("Stop"), wxEmptyString, NULL);
   // EnableTool(ID_AUITOOLBARITEM6, false);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/pause_blue.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxEmptyString, NULL);
  //  EnableTool(ID_AUITOOLBARITEM8, false);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_large_right.png"))), wxNullBitmap, wxITEM_NORMAL, _("Run"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_large_right_orange.png"))), wxNullBitmap, wxITEM_NORMAL, _("Debug"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/application_xp_terminal.png"))), wxNullBitmap, wxITEM_NORMAL, _("Compile"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/controller.png"))), wxNullBitmap, wxITEM_NORMAL, _("Global Game Settings"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/plugin.png"))), wxNullBitmap, wxITEM_NORMAL, _("Game Plugins"), wxEmptyString, NULL);
    Realize();
    }

    ~BuildToolbar()
    {

    }

};

#endif // BUILDTOOLBAR_H_INCLUDED
