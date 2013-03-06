/**
* @file MainMenubar.h
* @brief Header file of the main menu bar for the main frame.
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

#ifndef MAINMENUBAR_H_INCLUDED
#define MAINMENUBAR_H_INCLUDED

#include <wx/menu.h>

class MainMenubar : public wxMenuBar
{
    public:

    wxMenu* fileMenu;
    wxMenuItem* quitMenuItem;

    wxMenu* viewMenu;
    wxMenuItem* managementMenuItem;
    wxMenuItem* editingMenuItem;
    wxMenuItem* outputMenuItem;

    wxMenu* editMenu;
    wxMenuItem* cutMenuItem;
    wxMenuItem* copyMenuItem;
    wxMenuItem* pasteMenuItem;
    wxMenuItem* undoMenuItem;
    wxMenuItem* redoMenuItem;

    wxMenu* buildMenu;
    wxMenuItem* runMenuItem;
    wxMenuItem* debugMenuItem;

    wxMenu* resourcesMenu;
    wxMenuItem* directoryMenuItem;
    wxMenuItem* externalMenuItem;

    wxMenu* optionsMenu;
    wxMenuItem* settingsMenuItem;
    wxMenuItem* preferencesMenuItem;

    wxMenu* helpMenu;
    wxMenuItem* aboutMenuItem;

    MainMenubar()
    : wxMenuBar()
    {
        // ***** File Menu
        fileMenu = new wxMenu();
        quitMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
        fileMenu->Append(quitMenuItem);

        Append(fileMenu, _("&File"));

        // ***** View Menu
        viewMenu = new wxMenu();
        managementMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Management"), _("Toggle the management area"), wxITEM_NORMAL);
        viewMenu->Append(managementMenuItem);
        editingMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Editing"), _("Toggle the editing area"), wxITEM_NORMAL);
        viewMenu->Append(editingMenuItem);
        outputMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Output"), _("Toggle the output area"), wxITEM_NORMAL);
        viewMenu->Append(outputMenuItem);

        Append(viewMenu, _("&View"));

        // ***** Edit Menu
        editMenu = new wxMenu();

        cutMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Cut\tCtrl-X"), _("Cut to clipboard"), wxITEM_NORMAL);
        editMenu->Append(cutMenuItem);
        copyMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("Cop&y\tCtrl-C"), _("Copy to clipboard"), wxITEM_NORMAL);
        editMenu->Append(copyMenuItem);
        pasteMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Paste\tCtrl-V"), _("Paste clipboard"), wxITEM_NORMAL);
        editMenu->Append(pasteMenuItem);
        undoMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Undo\tCtrl-Z"), _("Undo changes"), wxITEM_NORMAL);
        editMenu->Append(undoMenuItem);
        redoMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Redo\tCtrl-Shift-Z"), _("Redo changes"), wxITEM_NORMAL);
        editMenu->Append(redoMenuItem);

        Append(editMenu, _("&Edit"));

        // ***** Resources Menu
        resourcesMenu = new wxMenu();

        Append(resourcesMenu, _("&Resources"));

        // ***** Build Menu
        buildMenu = new wxMenu();

        runMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Execute"), _("Run the game"), wxITEM_NORMAL);
        buildMenu->Append(runMenuItem);
        debugMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Debug"), _("Debug the game"), wxITEM_NORMAL);
        buildMenu->Append(debugMenuItem);

        Append(buildMenu, _("&Build"));

        // ***** Options Menu
        optionsMenu = new wxMenu();
        settingsMenuItem = new wxMenuItem(optionsMenu, wxID_ANY, _("Global Game Settings"), _("Settings for the current game"), wxITEM_NORMAL);
        optionsMenu->Append(settingsMenuItem);
        preferencesMenuItem = new wxMenuItem(optionsMenu, wxID_ANY, _("Preferences"), _("Editor Preferences"), wxITEM_NORMAL);
        optionsMenu->Append(preferencesMenuItem);
        Append(optionsMenu, _("&Options"));

        // ***** Help Menu
        helpMenu = new wxMenu();
        aboutMenuItem = new wxMenuItem(helpMenu, wxID_ANY, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
        helpMenu->Append(aboutMenuItem);
        Append(helpMenu, _("&Help"));

        Connect(quitMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainMenubar::OnQuit);
        Connect(aboutMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainMenubar::OnAbout);
    }

    ~MainMenubar()
    {

    }

    void OnAbout(wxCommandEvent& event)
    {
        //wxString msg = wxbuildinfo(long_f);
        //wxMessageBox(msg, _("Welcome to..."));
    }

    void OnQuit(wxCommandEvent& event)
    {
        Close(true);
    }

};

#endif // MAINMENUBAR_H_INCLUDED
