/**
* @file BuildToolbar.cpp
* @brief Source file of the build tool bar for the main frame.
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

#include "BuildToolbar.h"
#include "LoadLibrary.h"
#include <thread>

BuildToolbar::BuildToolbar(ENIGMA_IDEFrame* frame, const long id)
: wxAuiToolBar(frame, id, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE)
{
    mainFrame = frame;

    stopItem = AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/stop_red.png"))), wxNullBitmap, wxITEM_NORMAL, _("Stop"), wxEmptyString, NULL);
   // EnableTool(stopItem->GetId(), false);
DeleteTool(stopItem->GetId());
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/pause_blue.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxEmptyString, NULL);
  //  EnableTool(ID_AUITOOLBARITEM8, false);
    runItem = AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_large_right.png"))), wxNullBitmap, wxITEM_NORMAL, _("Run"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/beaker.png"))), wxNullBitmap, wxITEM_NORMAL, _("Debug"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/application_xp_terminal.png"))), wxNullBitmap, wxITEM_NORMAL, _("Compile"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/cog.png"))), wxNullBitmap, wxITEM_NORMAL, _("Project Settings"), wxEmptyString, NULL);
    AddTool(wxID_ANY, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/plugin.png"))), wxNullBitmap, wxITEM_NORMAL, _("Game Plugins"), wxEmptyString, NULL);
    Realize();

    Connect(runItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(BuildToolbar::OnRun), NULL, this);
    Connect(stopItem->GetId(),wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(BuildToolbar::OnStop), NULL, this);
//    Connect(mainFrame->mainAUIManager->GetPane(this).GetId(), wxEVT_SHOW, wxShowEventHandler(BuildToolbar::OnShow), NULL, this);
    //Connect(this->GetId(), wxEVT_HIDE, wxHideEventHandler(BuildToolbar::OnHide), NULL, this);

}

BuildToolbar::~BuildToolbar()
{

}

void BuildToolbar::OnShow(wxShowEvent& event)
{
   // if (mainFrame->mainMenuBar->editToolbarMenuItem != NULL)
    //{
        mainFrame->mainMenuBar->editToolbarMenuItem->Check(true);
        //wxEVT_
  //  }
  mainFrame->Close(true);
    event.Skip();
}

unsigned long RGBA2DWORD(int iR, int iG, int iB, int iA)
{
  return (((((iR << 8) + iG) << 8) + iB) << 8) + iA;
}

void Compile(void)
{
    EnigmaStruct* es = new EnigmaStruct();
    es->gameSettings.alwaysOnTop = true;
    es->gameSettings.gameId = 03434534;
    es->filename = "examplegamefilename";
    Room rms[1];
    rms[0] = Room();
    rms[0].drawBackgroundColor = true;
    rms[0].width = 500;
    rms[0].height=500;
    rms[0].creationCode = "show_message('hello world')";
    rms[0].name = "exampleroom";
    rms[0].id = 0543;
    rms[0].speed = 30;
    rms[0].caption = "Example Game Room Caption";
    rms[0].instanceCount = 0;
    rms[0].backgroundColor = RGBA2DWORD(3, 149, 255, 255);
    GmObject obj[10];

    obj[0] = GmObject();
    //obj[0].name="pissmonkey";
    obj[0].id = 0;
  //  Sprite spr[0];
  //  Font fnt[0];
  //  Timeline tln[0];
  //  Script scr[0];
  //  Path pth[0];
  //  Background bgd[0];

    es->rooms = rms;
    es->roomCount = 1;
    //es->gmObjects = obj;
    //es->gmObjectCount = 1;
  //  es->scripts = scr;
  //  es->fonts = fnt;
  //  es->sprites = spr;
  //  es->timelines = tln;
   // es->backgrounds = bgd;
    compileEGMf(es, "/tmp/testes.tmp", emode_run);
}

void BuildToolbar::OnRun(wxCommandEvent& event)
{
    std::thread* t = new thread( Compile );
    t->detach(); // detach will tell it to well detach from the main thread and close on its own when finished
//    mainFrame->CompilerThread = t; // i store this so that i can... ohhh i stored it cause i thought maybe i could terminate it
    return;
}

void BuildToolbar::OnStop(wxCommandEvent& event)
{

    // in order to write this button event i dnt know how else to force terminationu get
    return;
}
