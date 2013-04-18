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

#include "ENIGMA_IDEMain.h"
#include <wx/treectrl.h>

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
        wxMenuItem* deleteMenuItem;
        wxMenuItem* renameMenuItem;
        wxMenuItem* filextMenuItem;

        HierTreeCtrl(wxWindow* parent, const long id = wxID_ANY)
        : wxTreeCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_LINES_AT_ROOT)
        {
            contextMenu = new wxMenu();
            dirMenuItem = new wxMenuItem(contextMenu, wxNewId(), _("Create Directory"), _("Create a new file directory."), wxITEM_NORMAL);
            contextMenu->Append(dirMenuItem);
            fileMenuItem = new wxMenuItem(contextMenu, wxNewId(), _("Create File"), _("Create a new file."), wxITEM_NORMAL);
            contextMenu->Append(fileMenuItem);
            deleteMenuItem = new wxMenuItem(contextMenu, wxNewId(), _("Delete"), _("Delete the file from the project."), wxITEM_NORMAL);
            contextMenu->Append(deleteMenuItem);
            renameMenuItem = new wxMenuItem(contextMenu, wxNewId(), _("Rename"), _("Rename the file or directory."), wxITEM_NORMAL);
            contextMenu->Append(renameMenuItem);
            filextMenuItem = new wxMenuItem(contextMenu, wxNewId(), _("Show File Extensions"), _("Hide or show the extensions of files."), wxITEM_NORMAL);
            contextMenu->Append(filextMenuItem);

            Connect(dirMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HierTreeCtrl::OnCreateDirectory);
            Connect(fileMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HierTreeCtrl::OnCreateFile);
            Connect(deleteMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HierTreeCtrl::OnDelete);
            Connect(renameMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&HierTreeCtrl::OnRename);

            Connect(this->GetId(), wxEVT_RIGHT_UP, wxMouseEventHandler(HierTreeCtrl::OnContextMenu));
            SetSpacing(10);
        }

        void OnRename()
        {
            wxArrayTreeItemIds selItems;
            GetSelections(selItems);
            wxTreeItemId selItem = selItems.Item(0);
            EditLabel(selItem);
        }

        void OnCreateDirectory()
        {
            wxTreeItemId rootItem = GetRootItem();
            wxTreeItemId newItem = AppendDirectory(rootItem, "New Directory");
            EditLabel(newItem);
        }

        void OnCreateFile()
        {
            wxTreeItemId rootItem = GetRootItem();
            wxTreeItemId newItem = AppendFile(rootItem, "New File");
            EditLabel(newItem);
        }

        void OnDelete()
        {
            GetSelections(draggedItems);
            wxTreeItemId item;

            for (int i = 0; i < draggedItems.GetCount(); i++)
            {
                item = draggedItems.Item(i);
                if (item == GetRootItem() || item == NULL)
                {
                    break;
                }
                Delete(item);
            }

            draggedItems.Clear();
        }

        bool ItemIsAncestor(wxTreeItemId& ancestor, wxTreeItemId& descendant) {
            if (ancestor == descendant) return true;
            if (descendant == GetRootItem()) return false;
            wxTreeItemId parent = GetItemParent(descendant);
            return ItemIsAncestor(ancestor, parent);
        }

        wxTreeItemId AppendDirectory(wxTreeItemId& destination, const char *text)
        {
            wxTreeItemId newItem;
            newItem = AppendItem(destination, wxString::FromUTF8(text));
            SetItemData(newItem, new HierTreeItemData(true));
            SetItemImage(newItem, 6, wxTreeItemIcon_Normal);
            SetItemImage(newItem, 7, wxTreeItemIcon_Expanded);
            return newItem;
        }


        wxTreeItemId AppendFile(wxTreeItemId& destination, const char *text)
        {
            wxTreeItemId newItem;
            newItem = AppendItem(destination, wxString::FromUTF8(text));
            SetItemData(newItem, new HierTreeItemData(false));
            SetItemImage(newItem, 8, wxTreeItemIcon_Normal);
            return newItem;
        }

        wxTreeItemId MoveItem(wxTreeItemId& source, wxTreeItemId& destination, wxTreeItemId& parent)
        {
            wxTreeItemId newItem;
            if (parent != destination)
            {
                newItem = InsertItem(parent, destination, GetItemText(source), GetItemImage(source), -1,
                                    new HierTreeItemData(*(HierTreeItemData*)GetItemData(source)));
            }
            else
            {
                newItem = AppendItem(destination, GetItemText(source), GetItemImage(source), -1,
                                    new HierTreeItemData(*(HierTreeItemData*)GetItemData(source)));
            }

            // Move all the children from the old parent to the new one recursively
            wxTreeItemIdValue cookie;
            wxTreeItemId oldChild = GetFirstChild(source, cookie);
            while (GetChildrenCount(source, false) > 0)
            {
                MoveItem(oldChild, newItem, newItem);
                oldChild = GetFirstChild(source, cookie);
            }

            Delete(source);
            return newItem;
        }

        wxTreeItemId MoveItem(wxTreeItemId& source, wxTreeItemId& destination)
        {
            wxTreeItemId parent = GetItemParent(destination);
            MoveItem(source, destination, parent);
        }

        DECLARE_EVENT_TABLE()

        void OnContextMenu(wxMouseEvent& event)
        {
                wxPoint clientpt = event.GetPosition();
                wxPoint screenpt = ScreenToClient(clientpt);
                //event.Allow();
                PopupMenu(contextMenu, clientpt.x, clientpt.y);
        }

        void OnBeginDrag(wxTreeEvent& event)
        {
                GetSelections(draggedItems);

                wxPoint clientpt = event.GetPoint();
                wxPoint screenpt = ClientToScreen(clientpt);
                event.Allow();
        }

        void OnEndDrag(wxTreeEvent& event)
        {
            wxTreeItemId itemSrc, itemDst = event.GetItem();


            for (int i = 0; i < draggedItems.GetCount(); i++)
            {
                itemSrc = draggedItems.Item(i);
                if (itemDst == NULL || itemSrc == NULL || itemDst == itemSrc ||
                    ItemIsAncestor(itemSrc, itemDst))
                {
                    break;
                }

                if (((HierTreeItemData*)GetItemData(itemDst))->is_directory == false)
                {
                    MoveItem(itemSrc, itemDst);
                }
                else
                {
                    MoveItem(itemSrc, itemDst, itemDst);
                }
            }

            draggedItems.Clear();
        }
};

BEGIN_EVENT_TABLE(HierTreeCtrl, wxTreeCtrl)
EVT_TREE_BEGIN_DRAG(wxID_ANY, HierTreeCtrl::OnBeginDrag)
EVT_TREE_END_DRAG(wxID_ANY, HierTreeCtrl::OnEndDrag)
END_EVENT_TABLE()

#endif // HIEARCHY_H_INCLUDED
