/**
* @file ENIGMA_IDEMain.h
* @brief Header file of the IDE Frame
*
* This is the main frame which has a handle to the main window.
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

#ifndef ENIGMA_IDEMAIN_H
#define ENIGMA_IDEMAIN_H

class ENIGMA_IDEFrame;

#include "MainMenubar.h"
#include "EditToolbar.h"
#include "ResourceToolbar.h"
#include "BuildToolbar.h"
#include "Hierarchy.h"
#include "MainStatusbar.h"
#include "Project.h"
#include "AboutFrame.h"
#include "Preferences.h"
#include "ProjectSettings.h"
#include "FindAndReplace.h"
#include <stdio.h>
#include <deque>
#include <thread>
using namespace std;

#include <wx/menu.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
#include <wx/html/htmlwin.h>
#include <wx/stc/stc.h>
#include <wx/treectrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/richtext/richtextctrl.h>

#include <wx/listctrl.h>
#include <wx/srchctrl.h>
#include <wx/aui/aui.h>
#include <wx/imaglist.h>

#include "CrossThread.h"

enum {
    MSG_NOTICE,
    MSG_WARNING,
    MSG_ERROR
};

class ENIGMA_IDEFrame: public wxFrame
{
    public:

        ENIGMA_IDEFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ENIGMA_IDEFrame();

        // Identifiers
        static const long ID_MAINSTATUSBAR;
        static const long ID_HTMLWELCOME;
        static const long ID_PROPERTYCTRL;
        static const long ID_HIERARCHYTREECTRL;
        static const long ID_OUTPUTLOGCTRL;
        static const long ID_MESSAGESLISTVIEW;

        static const long ID_EDITINGAUINOTEBOOK;
        static const long ID_OUTPUTAUINOTEBOOK;
        static const long ID_MANAGEMENTAUINOTEBOOK;

        static const long ID_AUITOOLBARITEM11;
        static const long ID_AUITOOLBARITEM12;
        static const long ID_AUITOOLBARITEM13;
        static const long ID_HELPTOOLBAR;
        static const long ID_QUICKFINDTOOLBAR;
        static const long ID_CUSTOM1;

        // Declarations
        vector<Project*> openProjects;

        wxImageList* ControlImages;
        MainStatusbar* mainStatusbar;
        wxGauge* progressGauge;

        wxHtmlWindow* htmlWelcome;
        wxPropertyGrid* propertyCtrl;
        wxRichTextCtrl* outputLogCtrl;
        wxListView* messagesListView;
        HierTreeCtrl* hierarchyTreeCtrl;

        wxAuiManager* mainAUIManager;
        wxAuiNotebook* editingAUINotebook;
        wxAuiNotebook* managementAUINotebook;
        wxAuiNotebook* outputAUINotebook;
        FindAndReplace* findAndReplace;

        BuildToolbar* buildToolbar;
        EditToolbar* editToolbar;
        wxAuiToolBar* helpToolbar;
        wxAuiToolBar* quickfindToolbar;
        ResourceToolbar* resourcesToolbar;
        MainMenubar* mainMenuBar;

        deque<wxString> functionWords;
        deque<wxString> variableWords;
        wxString fncWords;
        wxString varWords;
        wxString acpWords;

        AboutFrame* aboutFrame;
        Preferences* preferencesFrame;
        ProjectSettings* settingsFrame;
        void ShowFindAndReplace();
        void ShowAboutFrame();
        void ShowSettingsFrame();
        void ShowPreferencesFrame();
        void CreateMainMenuBar();
        void CreateMainStatusBar();
        void CreateHierarchyTab();
        void CreateOutputLogTab();
        void CreateOuputMessagesTab();
        void CreateWelcomeTab();
        void CreatePropertyTab();
        void CreateScintillaTab();

        void OutputText(const char *text);
        void OutputLine(const char *text);
        void OutputMessage(int type, const char *origin, const char *location, const char *description);
        void OutputClearAll();
        void OutputLogClear();
        void OutputMessagesClear();
        void SetProgress(int progress);
        void SetProgressText(const char *text);
        void OnMyEvent(CT_Event& event);

        struct CrossThreadFrame : CrossThread {
          ENIGMA_IDEFrame* frame;
          CrossThreadFrame(ENIGMA_IDEFrame *f): frame(f) {}
        };

    private:

        // Handlers
        void OnClose(wxCloseEvent& event);

};

#endif // ENIGMA_IDEMAIN_H
