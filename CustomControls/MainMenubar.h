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

class MainMenubar;

#include "ENIGMA_IDEMain.h"
#include <wx/menu.h>

class MainMenubar : public wxMenuBar
{
    public:
    ENIGMA_IDEFrame* mainFrame;

    wxMenu* fileMenu;
    wxMenuItem* newMenuItem;
    wxMenuItem* openMenuItem;
    wxMenuItem* saveMenuItem;
    wxMenuItem* exportMenuItem;
    wxMenuItem* importMenuItem;
    wxMenuItem* quitMenuItem;

    wxMenu* viewMenu;
    wxMenuItem* managementMenuItem;
    wxMenuItem* editingMenuItem;
    wxMenuItem* outputMenuItem;
    wxMenu* toolbarsMenu;
    wxMenuItem* resourcesToolbarMenuItem;
    wxMenuItem* editToolbarMenuItem;
    wxMenuItem* buildToolbarMenuItem;
    wxMenuItem* helpToolbarMenuItem;

    wxMenu* editMenu;
    wxMenuItem* cutMenuItem;
    wxMenuItem* copyMenuItem;
    wxMenuItem* pasteMenuItem;
    wxMenuItem* undoMenuItem;
    wxMenuItem* redoMenuItem;
    wxMenuItem* selectAllMenuItem;
    wxMenuItem* commentMenuItem;
    wxMenuItem* uncommentMenuItem;

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

    MainMenubar(ENIGMA_IDEFrame* frame);
    virtual ~MainMenubar();

    private:

    void OnEditToolbar(wxCommandEvent& event);
    void OnResourcesToolbar(wxCommandEvent& event);
    void OnHelpToolbar(wxCommandEvent& event);
    void OnBuildToolbar(wxCommandEvent& event);

    void OnSettings(wxCommandEvent& event);
    void OnPreferences(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);

};

#endif // MAINMENUBAR_H_INCLUDED
