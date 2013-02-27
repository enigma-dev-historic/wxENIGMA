/***************************************************************
 * Name:      ENIGMA_IDEMain.h
 * Purpose:   Defines Application Frame
 * Author:    Robert B Colton (robertbcolton@hotmail.com)
 * Created:   2013-01-28
 * Copyright: Robert B Colton (enigma-dev.org)
 * License:
 **************************************************************/

#ifndef ENIGMA_IDEMAIN_H
#define ENIGMA_IDEMAIN_H

#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/html/htmlwin.h>
#include <wx/stc/stc.h>
#include <wx/treectrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/richtext/richtextctrl.h>

#include <wx/listctrl.h>
#include <wx/srchctrl.h>
#include "wximages/ENIGMA_IDEMain_hierarchyImageList.xpm"
#include <wx/aui/aui.h>
#include <wx/imaglist.h>

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

    private:

        // Handlers
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMarginClick(wxStyledTextEvent& event);
        void ShowAutoComplete(wxStyledTextEvent& event);

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

        // Identifiers
        static const long id_cutMenuItem;
        static const long id_copyMenuItem;
        static const long id_pasteMenuItem;
        static const long id_undoMenuItem;
        static const long id_redoMenuItem;

        static const long id_settingsMenuItem;
        static const long id_preferencesMenuItem;

        static const long id_directoryMenuItem;
        static const long id_externalMenuItem;
        static const long id_imageMenuItem;
        static const long id_fontMenuItem;
        static const long id_pathMenuItem;
        static const long id_scriptMenuItem;
        static const long id_objectMenuItem;
        static const long id_roomMenuItem;

        static const long id_managementMenuItem;
        static const long id_editingMenuItem;
        static const long id_outputMenuItem;

        static const long id_quitMenuItem;
        static const long id_aboutMenuItem;
        static const long id_runMenuItem;
        static const long id_debugMenuItem;

        static const long ID_MAINSTATUSBAR;
        static const long ID_HTMLWELCOME;
        static const long ID_PROPERTYCTRL;
        static const long ID_HIERARCHYTREECTRL;
        static const long ID_OUTPUTLOGCTRL;
        static const long ID_MESSAGESLISTVIEW;

                static const long ID_EDITINGAUINOTEBOOK;
        static const long ID_OUTPUTAUINOTEBOOK;
        static const long ID_MANAGEMENTAUINOTEBOOK;
        static const long ID_SAVETOOLITEM;
        static const long ID_SAVEALLTOOLITEM;
        static const long ID_AUITOOLBARITEM1;
        static const long ID_AUITOOLBARITEM2;
        static const long ID_AUITOOLBARITEM3;
        static const long ID_AUITOOLBARITEM4;
        static const long ID_AUITOOLBARITEM5;
        static const long ID_AUITOOLBARITEM28;
        static const long ID_AUITOOLBARITEM29;
        static const long ID_AUITOOLBAR1;
        static const long ID_AUITOOLBARITEM6;
        static const long ID_AUITOOLBARITEM8;
        static const long ID_AUITOOLBARITEM7;
        static const long ID_AUITOOLBARITEM9;
        static const long ID_AUITOOLBARITEM10;
        static const long ID_AUITOOLBARITEM14;
        static const long ID_AUITOOLBARITEM24;
        static const long ID_BUILDTOOLBAR;
        static const long ID_AUITOOLBARITEM22;
        static const long ID_AUITOOLBARITEM23;
        static const long ID_AUITOOLBARITEM26;
        static const long ID_AUITOOLBARITEM27;
        static const long ID_AUITOOLBARITEM15;
        static const long ID_AUITOOLBARITEM25;
        static const long ID_AUITOOLBARITEM16;
        static const long ID_AUITOOLBARITEM17;
        static const long ID_AUITOOLBARITEM18;
        static const long ID_AUITOOLBARITEM19;
        static const long ID_AUITOOLBARITEM20;
        static const long ID_RESOURCESTOOLBAR;
        static const long ID_AUITOOLBARITEM11;
        static const long ID_AUITOOLBARITEM12;
        static const long ID_AUITOOLBARITEM13;
        static const long ID_HELPTOOLBAR;
        static const long ID_QUICKFINDTOOLBAR;
        static const long ID_CUSTOM1;

        // Declarations
        wxStatusBar* mainStatusBar;
        wxHtmlWindow* htmlWelcome;
        wxTreeCtrl* hierarchyTreeCtrl;
        wxPropertyGrid* propertyCtrl;
        wxRichTextCtrl* outputLogCtrl;
        wxListView* messagesListView;

        wxAuiToolBar* buildToolbar;
        wxAuiNotebook* editingAUINotebook;
        wxImageList* hierarchyImageList;
        wxAuiToolBar* editToolbar;
        wxAuiToolBar* helpToolbar;
        wxAuiToolBar* quickfindToolBar;
        wxAuiNotebook* managementAUINotebook;
        wxAuiNotebook* outputAUINotebook;
        wxAuiToolBar* resourcesToolbar;
        wxAuiManager* mainAUIManager;

        DECLARE_EVENT_TABLE()
};

#endif // ENIGMA_IDEMAIN_H
