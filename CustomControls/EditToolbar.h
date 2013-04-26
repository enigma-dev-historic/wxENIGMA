/**
* @file EditToolbar.h
* @brief Header file of the edit toolbar.
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

#ifndef EDITTOOLBAR_H_INCLUDED
#define EDITTOOLBAR_H_INCLUDED

class EditToolbar;

#include "ENIGMA_IDEMain.h"
#include <wx/aui/aui.h>

class EditToolbar : public wxAuiToolBar
{
    public:
    ENIGMA_IDEFrame* mainFrame;

    wxAuiToolBarItem* codeCompItem;
    wxAuiToolBarItem* intellisenseItem;
    wxAuiToolBarItem* findReplaceItem;

    EditToolbar(ENIGMA_IDEFrame* frame, const long id = wxID_ANY);
    virtual ~EditToolbar();

    private:

    void OnFindReplace(wxCommandEvent& event);
   // DECLARE_EVENT_TABLE()

};


#endif // EDITTOOLBAR_H_INCLUDED
