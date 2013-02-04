/***************************************************************
 * Name:      ENIGMA_IDEMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Robert B Colton (robertbcolton@hotmail.com)
 * Created:   2013-01-28
 * Copyright: Robert B Colton (enigma-dev.org)
 * License:
 **************************************************************/

#include "ENIGMA_IDEMain.h"
#include <wx/msgdlg.h>

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/event.h>

// designer headers right meow bitches
//(*InternalHeaders(ENIGMA_IDEFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

// Designer code right meow
//(*IdInit(ENIGMA_IDEFrame)
const long ENIGMA_IDEFrame::ID_EDITINGAUINOTEBOOK = wxNewId();
const long ENIGMA_IDEFrame::ID_MESSAGESLISTVIEW = wxNewId();
const long ENIGMA_IDEFrame::ID_OUTPUTAUINOTEBOOK = wxNewId();
const long ENIGMA_IDEFrame::ID_MANAGEMENTAUINOTEBOOK = wxNewId();
const long ENIGMA_IDEFrame::ID_SAVETOOLITEM = wxNewId();
const long ENIGMA_IDEFrame::ID_SAVEALLTOOLITEM = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM1 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM2 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM3 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM4 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM5 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM28 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM29 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBAR1 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM6 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM8 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM7 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM9 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM10 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM14 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM24 = wxNewId();
const long ENIGMA_IDEFrame::ID_BUILDTOOLBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM22 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM23 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM26 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM27 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM15 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM25 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM16 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM17 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM18 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM19 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM20 = wxNewId();
const long ENIGMA_IDEFrame::ID_RESOURCESTOOLBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM11 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM12 = wxNewId();
const long ENIGMA_IDEFrame::ID_AUITOOLBARITEM13 = wxNewId();
const long ENIGMA_IDEFrame::ID_HELPTOOLBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_SEARCHCTRL1 = wxNewId();
const long ENIGMA_IDEFrame::ID_QUICKFINDTOOLBAR = wxNewId();
//*)

const long ENIGMA_IDEFrame::ID_MAINSTATUSBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_HIERARCHYTREECTRL = wxNewId();
const long ENIGMA_IDEFrame::ID_HTMLWELCOME = wxNewId();
const long ENIGMA_IDEFrame::ID_PROPERTYCTRL = wxNewId();
const long ENIGMA_IDEFrame::ID_OUTPUTLOGCTRL = wxNewId();

const long ENIGMA_IDEFrame::id_cutMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_copyMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_pasteMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_undoMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_redoMenuItem = wxNewId();

const long ENIGMA_IDEFrame::id_editingMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_managementMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_outputMenuItem = wxNewId();

const long ENIGMA_IDEFrame::id_settingsMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_preferencesMenuItem = wxNewId();

const long ENIGMA_IDEFrame::id_quitMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_aboutMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_debugMenuItem = wxNewId();
const long ENIGMA_IDEFrame::id_runMenuItem = wxNewId();

enum
{
    MARGIN_LINE_NUMBERS,
    MARGIN_FOLD
};

BEGIN_EVENT_TABLE(ENIGMA_IDEFrame, wxFrame)
    //(*EventTable(ENIGMA_IDEFrame)
    //*)
END_EVENT_TABLE()

ENIGMA_IDEFrame::ENIGMA_IDEFrame(wxWindow* parent,wxWindowID id)
{
    // Designer generated code below so don't touch it
    //(*Initialize(ENIGMA_IDEFrame)
    Create(parent, wxID_ANY, _("ENIGMA IDE - <new game>"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(886,465));
    mainAUIManager = new wxAuiManager(this, wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_DEFAULT);
    editingAUINotebook = new wxAuiNotebook(this, ID_EDITINGAUINOTEBOOK, wxPoint(29,40), wxSize(153,431), wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_DEFAULT_STYLE);
    editingAUINotebook->SetMinSize(wxSize(50,0));
    editingAUINotebook->SetFocus();
    mainAUIManager->AddPane(editingAUINotebook, wxAuiPaneInfo().Name(_T("EditingPane")).Caption(_("Editing")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().CloseButton(false).Center().BestSize(wxSize(153,431)).MinSize(wxSize(50,0)));
    outputAUINotebook = new wxAuiNotebook(this, ID_OUTPUTAUINOTEBOOK, wxDefaultPosition, wxSize(95,431), wxAUI_NB_BOTTOM|wxAUI_NB_DEFAULT_STYLE);
    outputAUINotebook->SetMinSize(wxSize(0,150));
    messagesListView = new wxListView(outputAUINotebook, ID_MESSAGESLISTVIEW, wxPoint(355,97), wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_MESSAGESLISTVIEW"));
    outputAUINotebook->AddPage(messagesListView, _("Messages"));
    mainAUIManager->AddPane(outputAUINotebook, wxAuiPaneInfo().Name(_T("OutputPane")).Caption(_("Output")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Bottom().BestSize(wxSize(95,431)).MinSize(wxSize(0,150)));
    managementAUINotebook = new wxAuiNotebook(this, ID_MANAGEMENTAUINOTEBOOK, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    managementAUINotebook->SetMinSize(wxSize(200,0));
    mainAUIManager->AddPane(managementAUINotebook, wxAuiPaneInfo().Name(_T("PaneName")).Caption(_("Management")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Layer(1).Right().MinSize(wxSize(200,0)));
    editToolbar = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    editToolbar->AddTool(ID_SAVETOOLITEM, _("SaveItem"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\disk.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_SAVEALLTOOLITEM, _("SaveAllItem"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\disk_multiple.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save All"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM1, _("Hello"), wxBitmap(wxImage(_T("Resources\\icons\\cut.png"))), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM2, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\page_copy.png"))), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM3, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\page_paste.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pase"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM4, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\arrow_undo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM5, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\arrow_redo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM28, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\page_white_code.png"))), wxNullBitmap, wxITEM_CHECK, _("Code Completion"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM29, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\spellcheck.png"))), wxNullBitmap, wxITEM_CHECK, _("Intellisense"), wxEmptyString, NULL);
    editToolbar->Realize();
    mainAUIManager->AddPane(editToolbar, wxAuiPaneInfo().Name(_T("EditPane")).ToolbarPane().Caption(_("Edit")).Layer(10).Top().Gripper());
    buildToolbar = new wxAuiToolBar(this, ID_BUILDTOOLBAR, wxPoint(168,10), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    buildToolbar->AddTool(ID_AUITOOLBARITEM6, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\stop_red.png"))), wxNullBitmap, wxITEM_NORMAL, _("Stop"), wxEmptyString, NULL);
    buildToolbar->EnableTool(ID_AUITOOLBARITEM6, false);
    buildToolbar->AddTool(ID_AUITOOLBARITEM8, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\pause_blue.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxEmptyString, NULL);
    buildToolbar->EnableTool(ID_AUITOOLBARITEM8, false);
    buildToolbar->AddTool(ID_AUITOOLBARITEM7, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\arrow_large_right.png"))), wxNullBitmap, wxITEM_NORMAL, _("Run"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM9, _("Item label"), wxBitmap(wxImage(_T("Resources\\icons\\arrow_large_right_orange.png"))), wxNullBitmap, wxITEM_NORMAL, _("Debug"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM10, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\application_xp_terminal.png"))), wxNullBitmap, wxITEM_NORMAL, _("Compile"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM14, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\controller.png"))), wxNullBitmap, wxITEM_NORMAL, _("Global Game Settings"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM24, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\plugin.png"))), wxNullBitmap, wxITEM_NORMAL, _("Game Plugins"), wxEmptyString, NULL);
    buildToolbar->Realize();
    mainAUIManager->AddPane(buildToolbar, wxAuiPaneInfo().Name(_T("BuildPane")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    resourcesToolbar = new wxAuiToolBar(this, ID_RESOURCESTOOLBAR, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM22, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\folder_add.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Folder"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM23, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\page_add.png"))), wxNullBitmap, wxITEM_NORMAL, _("Add External File"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM26, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\3d.png"))), wxNullBitmap, wxITEM_NORMAL, _("New 3D Primitive"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM27, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\images.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sprite"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM15, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\picture.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Image"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM25, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\chart_line.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Path"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM16, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\sound.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sound"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM17, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\font.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Font"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM18, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\script.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Script"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM19, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\cog.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Object"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM20, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\map.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Room"), wxEmptyString, NULL);
    resourcesToolbar->Realize();
    mainAUIManager->AddPane(resourcesToolbar, wxAuiPaneInfo().Name(_T("ResourcesPane")).ToolbarPane().Caption(_("Resources")).Layer(10).Top().Gripper());
    helpToolbar = new wxAuiToolBar(this, ID_HELPTOOLBAR, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    helpToolbar->AddTool(ID_AUITOOLBARITEM11, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\help.png"))), wxNullBitmap, wxITEM_NORMAL, _("Help"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM12, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\information.png"))), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM13, _("Item label"), wxBitmap(wxImage(_T("C:\\Users\\Owner\\Desktop\\ENIGMA IDE\\Resources\\icons\\application_form.png"))), wxNullBitmap, wxITEM_NORMAL, _("Preferences"), wxEmptyString, NULL);
    helpToolbar->Realize();
    mainAUIManager->AddPane(helpToolbar, wxAuiPaneInfo().Name(_T("HelpPane")).ToolbarPane().Caption(_("Help")).Layer(10).Top().Gripper());
    quickfindToolBar = new wxAuiToolBar(this, ID_QUICKFINDTOOLBAR, wxPoint(841,8), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    SearchCtrl1 = new wxSearchCtrl(quickfindToolBar, ID_SEARCHCTRL1, wxEmptyString, wxPoint(26,13), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    SearchCtrl1->ShowCancelButton(true);
    quickfindToolBar->AddControl(SearchCtrl1, _("Item label"));
    quickfindToolBar->Realize();
    mainAUIManager->AddPane(quickfindToolBar, wxAuiPaneInfo().Name(_T("QuickFind")).ToolbarPane().Caption(_("Quick Find")).Layer(10).Top().Gripper());
    mainAUIManager->Update();
    hierarchyImageList = new wxImageList(16, 16, 11);
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_0_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_1_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_2_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_3_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_4_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_5_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_6_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_7_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_8_XPM));
    hierarchyImageList->Add(wxBitmap(hierarchyImageList_9_XPM));

    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ENIGMA_IDEFrame::OnClose);
    //*)

    SetIcon(wxICON(aaaa));

    CreateMainMenuBar();
    CreateMainStatusBar();
    CreateHierarchyTab();
    CreatePropertyTab();
    mainAUIManager->Update();
    CreateWelcomeTab();
    CreateScintillaTab();
    CreateScintillaTab();

    // doesnt work on windows because of native widgets
    // need to create my own status bar control or override the paint event
    //mainMenuBar->SetBackgroundColour(wxColour(0, 0, 0, 255));
    mainStatusBar->SetStatusText(_T("Ready"));

    // NOTE: The CreateOutputLogTab() function will set the default text of the control, the OutputClear() should
    // remove it.
    CreateOutputLogTab();
    OutputClear();
    OutputLine("IDE Loaded");
    OutputText("Test Output Line \n");
    OutputText("Test Output Line 2");

    messagesListView->AppendColumn(wxString("test"));
    messagesListView->AppendColumn(wxString("testc2"));
    messagesListView->SetImageList(hierarchyImageList, 1);
    messagesListView->InsertItem(0, wxString("test.cpp"), 9);
    messagesListView->InsertItem(1, wxString("test.cpp"), 9);
    messagesListView->InsertItem(2, wxString("test.cpp"), 9);
    messagesListView->InsertItem(3, wxString("test.cpp"), 8);
    messagesListView->InsertItem(4, wxString("test.cpp"), 8);

//text->
//    messagesListView->SetColu
}

ENIGMA_IDEFrame::~ENIGMA_IDEFrame()
{
    //(*Destroy(ENIGMA_IDEFrame)
    //*)
}

void ENIGMA_IDEFrame::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void ENIGMA_IDEFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ENIGMA_IDEFrame::CreateMainMenuBar()
{
    wxMenuBar* mainMenuBar;

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

    mainMenuBar = new wxMenuBar();

    // ***** File Menu
    fileMenu = new wxMenu();
    quitMenuItem = new wxMenuItem(fileMenu, id_quitMenuItem, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    fileMenu->Append(quitMenuItem);
    mainMenuBar->Append(fileMenu, _("&File"));
    // *****

    // ***** View Menu
    viewMenu = new wxMenu();
    managementMenuItem = new wxMenuItem(viewMenu, id_managementMenuItem, _("Management"), _("Toggle the management area"), wxITEM_NORMAL);
    viewMenu->Append(managementMenuItem);
    editingMenuItem = new wxMenuItem(viewMenu, id_editingMenuItem, _("Editing"), _("Toggle the editing area"), wxITEM_NORMAL);
    viewMenu->Append(editingMenuItem);
    outputMenuItem = new wxMenuItem(viewMenu, id_outputMenuItem, _("Output"), _("Toggle the output area"), wxITEM_NORMAL);
    viewMenu->Append(outputMenuItem);
    mainMenuBar->Append(viewMenu, _("&View"));
    // *****

    // ***** Edit Menu
    editMenu = new wxMenu();

    cutMenuItem = new wxMenuItem(editMenu, id_cutMenuItem, _("&Cut\tCtrl-X"), _("Cut to clipboard"), wxITEM_NORMAL);
    editMenu->Append(cutMenuItem);
    copyMenuItem = new wxMenuItem(editMenu, id_copyMenuItem, _("Cop&y\tCtrl-C"), _("Copy to clipboard"), wxITEM_NORMAL);
    editMenu->Append(copyMenuItem);
    pasteMenuItem = new wxMenuItem(editMenu, id_pasteMenuItem, _("&Paste\tCtrl-V"), _("Paste clipboard"), wxITEM_NORMAL);
    editMenu->Append(pasteMenuItem);
    undoMenuItem = new wxMenuItem(editMenu, id_undoMenuItem, _("&Undo\tCtrl-Z"), _("Undo changes"), wxITEM_NORMAL);
    editMenu->Append(undoMenuItem);
    redoMenuItem = new wxMenuItem(editMenu, id_redoMenuItem, _("&Redo\tCtrl-Shift-Z"), _("Redo changes"), wxITEM_NORMAL);
    editMenu->Append(redoMenuItem);

    mainMenuBar->Append(editMenu, _("&Edit"));
    // *****

    // ***** Resources Menu
    resourcesMenu = new wxMenu();

    mainMenuBar->Append(resourcesMenu, _("&Resources"));
    // *****

    // ***** Build Menu
    buildMenu = new wxMenu();

    runMenuItem = new wxMenuItem(buildMenu, id_runMenuItem, _("Execute"), _("Run the game"), wxITEM_NORMAL);
    buildMenu->Append(runMenuItem);
    debugMenuItem = new wxMenuItem(buildMenu, id_debugMenuItem, _("Debug"), _("Debug the game"), wxITEM_NORMAL);
    buildMenu->Append(debugMenuItem);

    mainMenuBar->Append(buildMenu, _("&Build"));
    // *****

    // ***** Options Menu
    optionsMenu = new wxMenu();
    settingsMenuItem = new wxMenuItem(optionsMenu, id_settingsMenuItem, _("Global Game Settings"), _("Settings for the current game"), wxITEM_NORMAL);
    optionsMenu->Append(settingsMenuItem);
    preferencesMenuItem = new wxMenuItem(optionsMenu, id_preferencesMenuItem, _("Preferences"), _("Editor Preferences"), wxITEM_NORMAL);
    optionsMenu->Append(preferencesMenuItem);
    mainMenuBar->Append(optionsMenu, _("&Options"));
    // *****

    // ***** Help Menu
    helpMenu = new wxMenu();
    aboutMenuItem = new wxMenuItem(helpMenu, id_aboutMenuItem, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    helpMenu->Append(aboutMenuItem);
    mainMenuBar->Append(helpMenu, _("&Help"));
    // *****

    SetMenuBar(mainMenuBar);

    Connect(id_quitMenuItem,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ENIGMA_IDEFrame::OnQuit);
    Connect(id_aboutMenuItem,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ENIGMA_IDEFrame::OnAbout);
}

void ENIGMA_IDEFrame::CreateMainStatusBar()
{
    mainStatusBar = new wxStatusBar(this, ID_MAINSTATUSBAR, 0, _T("ID_MAINSTATUSBAR"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    mainStatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    mainStatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(mainStatusBar);
}

void ENIGMA_IDEFrame::CreateHierarchyTab()
{
    hierarchyTreeCtrl = new wxTreeCtrl(this, ID_HIERARCHYTREECTRL, wxDefaultPosition, wxDefaultSize, wxTR_NO_LINES|wxTR_TWIST_BUTTONS|wxTR_EDIT_LABELS|wxTR_HIDE_ROOT|wxTR_DEFAULT_STYLE|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_HIERARCHYTREECTRL"));
    wxTreeItemId hierarchyTreeCtrl_Item1 = hierarchyTreeCtrl->AddRoot(_T("Root Node"));
    wxTreeItemId hierarchyTreeCtrl_Item2 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Rooms"));
    wxTreeItemId hierarchyTreeCtrl_Item3 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item2, _T("Room"));
    wxTreeItemId hierarchyTreeCtrl_Item4 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Fonts"));
    wxTreeItemId hierarchyTreeCtrl_Item5 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item4, _T("HUD"));
    wxTreeItemId hierarchyTreeCtrl_Item6 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item5, _T("Font"));
    wxTreeItemId hierarchyTreeCtrl_Item7 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item4, _T("Font"));
    wxTreeItemId hierarchyTreeCtrl_Item8 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Guns"));
    wxTreeItemId hierarchyTreeCtrl_Item9 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item8, _T("Script"));
    wxTreeItemId hierarchyTreeCtrl_Item10 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Script"));
    wxTreeItemId hierarchyTreeCtrl_Item11 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Image"));
    wxTreeItemId hierarchyTreeCtrl_Item12 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Image"));
    wxTreeItemId hierarchyTreeCtrl_Item13 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Image"));
    wxTreeItemId hierarchyTreeCtrl_Item14 = hierarchyTreeCtrl->AppendItem(hierarchyTreeCtrl_Item1, _T("Sound"));
    hierarchyTreeCtrl->ScrollTo(hierarchyTreeCtrl_Item2);
    hierarchyTreeCtrl->SetMinSize(wxSize(150,0));
    managementAUINotebook->AddPage(hierarchyTreeCtrl, _("Hierarchy"), true);

    // Set the images for hierarchyTreeCtrl.
    hierarchyTreeCtrl->SetImageList(hierarchyImageList);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item2, 0, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item3, 5, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item4, 0, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item5, 0, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item6, 2, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item7, 2, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item8, 0, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item9, 1, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item10, 1, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item11, 3, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item12, 3, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item13, 3, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item14, 6, wxTreeItemIcon_Normal);
}

void ENIGMA_IDEFrame::CreateWelcomeTab()
{
    htmlWelcome = new wxHtmlWindow(editingAUINotebook, ID_HTMLWELCOME, wxPoint(214,121), wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxVSCROLL|wxHSCROLL, _T("ID_HTMLWELCOME"));
    htmlWelcome->LoadPage(_("Resources\\welcome\\Welcome.html"));
    editingAUINotebook->AddPage(htmlWelcome, _("Welcome"), true);
}

void ENIGMA_IDEFrame::CreatePropertyTab()
{
    propertyCtrl = new wxPropertyGrid(managementAUINotebook, ID_PROPERTYCTRL, wxPoint(214,121), wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxVSCROLL|wxHSCROLL, _T("ID_PROPERTYCTRL"));
    // Add a bool property
    propertyCtrl->Append( new wxBoolProperty(wxT("Bool Property"), wxPG_LABEL, false) );
    // Add int property
    propertyCtrl->Append( new wxIntProperty(wxT("Int Property"), wxPG_LABEL, 12345678) );
    // A file selector property.
    propertyCtrl->Append( new wxFileProperty(wxT("File Property"), wxPG_LABEL, wxEmptyString) );
    // A file selector property.
    propertyCtrl->Append( new wxColourProperty(wxT("Colour Property"), wxPG_LABEL, wxColour(242,109,0)) );
    // A file selector property.
    propertyCtrl->Append( new wxColourProperty(wxT("Colour Property2"), wxPG_LABEL, wxColour(20,109,20)) );
    managementAUINotebook->AddPage(propertyCtrl, _("Properties"), true);
}


wxStyledTextCtrl* text;
void ENIGMA_IDEFrame::CreateScintillaTab()
{
    text = new wxStyledTextCtrl(this, wxID_ANY);
    text->StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour (255, 255, 255) );
    text->StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour (0, 0, 0));
    wxFont Font_2(10, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier New"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_DEFAULT, Font_2);
    text->SetWrapMode (wxSTC_WRAP_NONE);
text->StyleSetBackground(wxSTC_MARK_EMPTY, wxColour (255,0,0));
text->MarkerSetBackground(wxSTC_MARK_EMPTY, wxColor(255, 0, 0) );
text->MarkerSetBackground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );
text->StyleSetBackground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );

    text->StyleClearAll();
text->MarkerSetBackground(wxSTC_MARGIN_SYMBOL, wxColor(255, 0, 0) );
text->SetCaretForeground(wxColor(255, 255, 255));
text->SetCaretLineBackground(wxColor(64,64,64));
text->SetCaretLineVisible(true);

//text->MarkerSetBackground(wxSTC_MARK_EMPTY, wxColor(255, 0, 0) );
//text->MarkerSetBackground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );
//text->StyleSetForeground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );
    // line number style has to after clearing the styles
    text->StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (192, 192, 192) );
    text->StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (0, 13, 26));
    wxFont Font_3(10, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_LINENUMBER, Font_3);
    text->SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
    text->SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

    // ----- Enable code folding
    text->SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    text->SetMarginWidth(MARGIN_FOLD, 15);
    text->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);


    text->SetMarginSensitive(MARGIN_FOLD, true);

    // Properties found from http://www.scintilla.org/SciTEDoc.html
    text->SetProperty (wxT("fold"),         wxT("1") );
    text->SetProperty (wxT("fold.comment"), wxT("1") );
    text->SetProperty (wxT("fold.compact"), wxT("0") );

    wxColor grey( 150, 150, 150);
    wxColor white(0, 0, 0);
    wxColor black(255, 255, 255);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUSCONNECTED);
    text->MarkerSetForeground (wxSTC_MARKNUM_FOLDER, black);
    text->MarkerSetBackground (wxSTC_MARKNUM_FOLDER, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_BOXMINUSCONNECTED);
    text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPEN, black);
    text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPEN, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_VLINE);
    text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERSUB, black);
    text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERSUB, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_BOXPLUSCONNECTED);
    text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEREND, black);
    text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEREND, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUSCONNECTED);
    text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPENMID, black);
   text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPENMID, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_TCORNER);
   text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERMIDTAIL, black);
   text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);

    text->MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_LCORNER);
   text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERTAIL, black);
   text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    // ----- End of code folding part

    // ----- Styling
    text->SetLexer(wxSTC_LEX_CPP);
    text->StyleSetForeground (wxSTC_CACHE_CARET,            wxColour(255,128,128));
    text->StyleSetForeground (wxSTC_C_STRING,            wxColour(255,128,128));
    text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(255,128,128));
    text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(255,128,128));
    text->StyleSetForeground (wxSTC_C_WORD,              wxColour(0,165,244));
    text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(255,184,113));
    text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(128,255,0));
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(128,255,0));
    text->StyleSetBackground (wxSTC_C_COMMENTLINE,       wxColour(0,0,0));
    text->StyleSetBold(wxSTC_C_WORD, true);
    text->StyleSetBold(wxSTC_C_WORD2, true);
    //----- End of styling

    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, wxT("return for while break if var globalvar repeat"));
    text->SetKeyWords(1, wxT("draw_clear draw_line draw_set_color random"));
    text->SetKeyWords(2, wxT("printf"));

    text->LoadFile(_T("Resources/examplescript.txt"));
    editingAUINotebook->AddPage(text, _("Scintilla Tab"), true);

    text->Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(ENIGMA_IDEFrame::OnMarginClick), NULL, this);
    text->Connect(wxEVT_STC_CHARADDED, wxStyledTextEventHandler(ENIGMA_IDEFrame::ShowAutoComplete), NULL, this);
    text->AutoCompSetAutoHide(true);
}

void ENIGMA_IDEFrame::ShowAutoComplete(wxStyledTextEvent& event)
{
    text->AutoCompShow(0, _T("draw_clear draw_line draw_set_color random"));
}

void ENIGMA_IDEFrame::OnMarginClick(wxStyledTextEvent& event)
{
    if (event.GetMargin() == MARGIN_FOLD)
    {
        int lineClick = text->LineFromPosition(event.GetPosition());
        int levelClick = text->GetFoldLevel(lineClick);

        if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0)
        {
            text->ToggleFold(lineClick);
        }
    }
}

void ENIGMA_IDEFrame::CreateOutputLogTab()
{
    outputLogCtrl = new wxRichTextCtrl(outputAUINotebook, ID_OUTPUTLOGCTRL, _("Output log will be displayed here when the IDE builds a game.\nfdsgdfg\ndfg\nsd\ngdf\ng"), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_OUTPUTLOGCTRL"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetLineSpacing(wxTEXT_ATTR_LINE_SPACING_NORMAL);
    outputLogCtrl->SetBasicStyle(rchtxtAttr_1);
    wxFont Font_1(8.25,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    outputLogCtrl->SetFont(Font_1);
    outputAUINotebook->AddPage(outputLogCtrl, _("Log"));
}

void ENIGMA_IDEFrame::OutputClear()
{
    outputLogCtrl->Clear();
}

void ENIGMA_IDEFrame::OutputText(const char *text)
{
    outputLogCtrl->WriteText(wxString::FromUTF8(text));
}

void ENIGMA_IDEFrame::OutputLine(const char *text)
{
    outputLogCtrl->WriteText(wxString::FromUTF8(text) + _T("\n"));
}


void ENIGMA_IDEFrame::OnClose(wxCloseEvent& event)
{
    event.Skip();
}
