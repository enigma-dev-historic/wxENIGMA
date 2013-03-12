/**
* @file EditToolbar.cpp
* @brief Source file of the edit tool bar for the main frame.
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

#include "EditToolbar.h"

//BEGIN_EVENT_TABLE(EditToolbar, wxAuiToolBar)

//END_EVENT_TABLE()

EditToolbar::EditToolbar(ENIGMA_IDEFrame* frame, const long id)
: wxAuiToolBar(frame, id, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE)
{
    mainFrame = frame;

    AddTool(wxID_ANY, _("Save"), wxBitmap(wxImage(_T("Resources/icons/disk.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("SaveAll"), wxBitmap(wxImage(_T("Resources/icons/disk_multiple.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save All"), wxEmptyString, NULL);
    AddSeparator();
    AddTool(wxID_ANY, _("Cut"), wxBitmap(wxImage(_T("Resources/icons/cut.png"))), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_copy.png"))), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_paste.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pase"), wxEmptyString, NULL);
    AddSeparator();
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_undo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_redo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL);
    AddSeparator();
    codeCompItem = AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_white_code.png"))), wxNullBitmap, wxITEM_CHECK, _("Code Completion"), wxEmptyString, NULL);
    intellisenseItem = AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/spellcheck.png"))), wxNullBitmap, wxITEM_CHECK, _("Intellisense"), wxEmptyString, NULL);
    Realize();

    ToggleTool(codeCompItem->GetId(), true);
    ToggleTool(intellisenseItem->GetId(), true);
}

EditToolbar::~EditToolbar()
{

}


