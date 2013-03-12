/**
* @file Hierarchy.h
* @brief Header file of the project hierarchy viewer.
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

#ifndef HIEARCHY_H_INCLUDED
#define HIEARCHY_H_INCLUDED

class HierTreeCtrl;

#include "ENIGMA_IDEMain.h"
#include <wx/treectrl.h>
#include <wx/event.h>
#include <wx/menu.h>

struct HierTreeItemData: wxTreeItemData {
    bool is_directory = false;
    HierTreeItemData()
    {
    }
    HierTreeItemData(bool dir): is_directory(dir)
    {
    }
};

class HierTreeCtrl : public wxTreeCtrl
{
    public:
    wxArrayTreeItemIds draggedItems;
    wxMenu* contextMenu;
    wxMenuItem* dirMenuItem;
    wxMenuItem* fileMenuItem;
    wxMenuItem* resourceMenuItem;
    wxMenuItem* editMenuItem;
    wxMenuItem* renameMenuItem;
    wxMenuItem* deleteMenuItem;
    wxMenuItem* filextMenuItem;

    HierTreeCtrl(wxWindow* parent, const long id = wxID_ANY);
    void OnRename();
    void OnCreateDirectory();
    void OnCreateFile();
    void OnDelete();
    bool ItemIsAncestor(wxTreeItemId& ancestor, wxTreeItemId& descendant);
    wxTreeItemId AppendDirectory(wxTreeItemId& destination, const char *text);
    wxTreeItemId AppendFile(wxTreeItemId& destination, const char *text);
    wxTreeItemId MoveItem(wxTreeItemId& source, wxTreeItemId& destination, wxTreeItemId& parent);
    wxTreeItemId MoveItem(wxTreeItemId& source, wxTreeItemId& destination);

    private:

       // DECLARE_EVENT_TABLE()

    void OnContextMenu(wxMouseEvent& event);
    void OnBeginDrag(wxTreeEvent& event);
    void OnEndDrag(wxTreeEvent& event);
};

#endif // HIEARCHY_H_INCLUDED
