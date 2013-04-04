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

#include "MainMenubar.h"
#include <wx/filedlg.h>

MainMenubar::MainMenubar(ENIGMA_IDEFrame* frame)
{
    mainFrame = frame;

    // ***** File Menu
    fileMenu = new wxMenu();
    newMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("New"), _("popup"), wxITEM_NORMAL);
    fileMenu->Append(newMenuItem);
    openMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("Open"), _("Open a project"), wxITEM_NORMAL);
    fileMenu->Append(openMenuItem);
    saveMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("Save"), _("Save a project"), wxITEM_NORMAL);
    fileMenu->Append(saveMenuItem);
    importMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("Import"), _("Import a project"), wxITEM_NORMAL);
    fileMenu->Append(importMenuItem);
    exportMenuItem = new wxMenuItem(fileMenu, wxID_ANY, _("Export"), _("Export a project"), wxITEM_NORMAL);
    fileMenu->Append(exportMenuItem);
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


    toolbarsMenu = new wxMenu();
    // customizeable toolbars we can do after wxAUI 1.0 is released, because thats when they plan to support it
    //customToolbarsMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Customize"), _("Customize the toolbars"), wxITEM_NORMAL);
    //toolbarsMenu->Append(customToolbarsMenuItem);
    editToolbarMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Edit"), _("Edit toolbar"), wxITEM_CHECK);
    toolbarsMenu->Append(editToolbarMenuItem);
    buildToolbarMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Build"), _("Build toolbar"), wxITEM_NORMAL);
    toolbarsMenu->Append(buildToolbarMenuItem);
    helpToolbarMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Help"), _("Help toolbar"), wxITEM_NORMAL);
    toolbarsMenu->Append(helpToolbarMenuItem);
    resourcesToolbarMenuItem = new wxMenuItem(viewMenu, wxID_ANY, _("Resources"), _("Resources toolbar"), wxITEM_NORMAL);
    toolbarsMenu->Append(resourcesToolbarMenuItem);
    viewMenu->AppendSubMenu(toolbarsMenu, _("&Toolbars"));

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
    selectAllMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Select All"), _("Select All"), wxITEM_NORMAL);
    editMenu->Append(selectAllMenuItem);
    editMenu->AppendSeparator();
    commentMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Comment"), _("Comment selected code."), wxITEM_NORMAL);
    editMenu->Append(commentMenuItem);
    uncommentMenuItem = new wxMenuItem(editMenu, wxID_ANY, _("&Uncomment"), _("Uncomment selected code."), wxITEM_NORMAL);
    editMenu->Append(uncommentMenuItem);

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
    runMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Compile"), _("Compile the game for distribution"), wxITEM_NORMAL);
    buildMenu->Append(runMenuItem);
    runMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Stop"), _("Run the game"), wxITEM_NORMAL);
    buildMenu->Append(runMenuItem);
    runMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Pause"), _("Run the game"), wxITEM_NORMAL);
    buildMenu->Append(runMenuItem);
    runMenuItem = new wxMenuItem(buildMenu, wxID_ANY, _("Step Into"), _("Run the game"), wxITEM_NORMAL);
    buildMenu->Append(runMenuItem);

    Append(buildMenu, _("&Build"));

    // ***** Options Menu
    optionsMenu = new wxMenu();
    settingsMenuItem = new wxMenuItem(optionsMenu, wxID_ANY, _("Project Settings"), _("Settings for the current game"), wxITEM_NORMAL);
    optionsMenu->Append(settingsMenuItem);
    preferencesMenuItem = new wxMenuItem(optionsMenu, wxID_ANY, _("Preferences"), _("Editor Preferences"), wxITEM_NORMAL);
    optionsMenu->Append(preferencesMenuItem);
    Append(optionsMenu, _("&Options"));

    // ***** Help Menu
    helpMenu = new wxMenu();
    aboutMenuItem = new wxMenuItem(helpMenu, wxID_ANY, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    helpMenu->Append(aboutMenuItem);
    //aboutMenuItem = new wxMenuItem(helpMenu, wxID_ANY, _("Documentation\tF1"), _("Read documentation for the program"), wxITEM_NORMAL);
    //helpMenu->Append(aboutMenuItem);

    Append(helpMenu, _("&Help"));

    frame->Connect(editToolbarMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnEditToolbar), NULL, this);
    frame->Connect(helpToolbarMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnHelpToolbar), NULL, this);
    frame->Connect(buildToolbarMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnBuildToolbar), NULL, this);
    frame->Connect(resourcesToolbarMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnResourcesToolbar), NULL, this);
    frame->Connect(openMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnOpen), NULL, this);
    frame->Connect(quitMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnQuit), NULL, this);
    frame->Connect(aboutMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnAbout), NULL, this);
    frame->Connect(settingsMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnSettings), NULL, this);
    frame->Connect(preferencesMenuItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainMenubar::OnPreferences), NULL, this);
}

MainMenubar::~MainMenubar()
{

}

void MainMenubar::OnEditToolbar(wxCommandEvent& event)
{
    if (mainFrame->editToolbar->IsShown())
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->editToolbar).Hide();
    }
    else
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->editToolbar).Show();
    }
    mainFrame->mainAUIManager->Update();
}

void MainMenubar::OnBuildToolbar(wxCommandEvent& event)
{
    if (mainFrame->buildToolbar->IsShown())
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->buildToolbar).Hide();
    }
    else
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->buildToolbar).Show();
    }
    mainFrame->mainAUIManager->Update();
}

void MainMenubar::OnHelpToolbar(wxCommandEvent& event)
{
    if (mainFrame->helpToolbar->IsShown())
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->helpToolbar).Hide();
    }
    else
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->helpToolbar).Show();
    }
    mainFrame->mainAUIManager->Update();
}

void MainMenubar::OnResourcesToolbar(wxCommandEvent& event)
{
    if (mainFrame->resourcesToolbar->IsShown())
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->resourcesToolbar).Hide();
    }
    else
    {
        mainFrame->mainAUIManager->GetPane(mainFrame->resourcesToolbar).Show();
    }
    mainFrame->mainAUIManager->Update();
}

void MainMenubar::OnSettings(wxCommandEvent& event)
{
    mainFrame->ShowSettingsFrame();
}

void MainMenubar::OnPreferences(wxCommandEvent& event)
{
    mainFrame->ShowPreferencesFrame();
}


void MainMenubar::OnAbout(wxCommandEvent& event)
{
    mainFrame->ShowAboutFrame();
}

void MainMenubar::OnOpen(wxCommandEvent& event)
{
     wxFileDialog
openFileDialog(this, _("Open Project"), "", "",
"ENIGMA XML Project (*.egp)|*.egp", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
if (openFileDialog.ShowModal() == wxID_CANCEL)
return; // the user changed idea...
}

void MainMenubar::OnQuit(wxCommandEvent& event)
{
    mainFrame->Close(true);
}
