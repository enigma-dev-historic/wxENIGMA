/**
* @file MainMenubar.cpp
* @brief Source file of the main menu bar for the main frame.
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

#include "ResourceToolbar.h"

ResourceToolbar::ResourceToolbar(ENIGMA_IDEFrame* frame, const long id)
: wxAuiToolBar(frame, id, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE)
{
    mainFrame = frame;
    //AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/folder.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Folder"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_white_stack.png"))), wxNullBitmap, wxITEM_NORMAL, _("Add External File"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/model.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Model"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/material.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Material"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/pacman.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sprite"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/background.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Background"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/polygon.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Polygon"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/path.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Path"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/timeline.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Timeline"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/sound.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sound"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/style.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Font"), wxEmptyString, NULL);
    createScriptItem = AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_white_code.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Script"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/object.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Object"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/room.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Scene"), wxEmptyString, NULL);
    Realize();
    Update();

    frame->Connect(createScriptItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(ResourceToolbar::OnCreateScript), NULL, this);
}

ResourceToolbar::~ResourceToolbar()
{

}

void ResourceToolbar::OnCreateScript(wxCommandEvent& event)
{
    mainFrame->CreateScintillaTab();
}
