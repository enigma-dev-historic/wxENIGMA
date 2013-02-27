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
#include <wx/bitmap.h>
#include <wx/image.h>

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

const long ENIGMA_IDEFrame::ID_EDITINGAUINOTEBOOK = wxNewId();
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
const long ENIGMA_IDEFrame::ID_QUICKFINDTOOLBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_CUSTOM1 = wxNewId();

const long ENIGMA_IDEFrame::ID_MAINSTATUSBAR = wxNewId();
const long ENIGMA_IDEFrame::ID_HIERARCHYTREECTRL = wxNewId();
const long ENIGMA_IDEFrame::ID_HTMLWELCOME = wxNewId();
const long ENIGMA_IDEFrame::ID_PROPERTYCTRL = wxNewId();
const long ENIGMA_IDEFrame::ID_OUTPUTLOGCTRL = wxNewId();
const long ENIGMA_IDEFrame::ID_MESSAGESLISTVIEW = wxNewId();

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

END_EVENT_TABLE()

ENIGMA_IDEFrame::ENIGMA_IDEFrame(wxWindow* parent,wxWindowID id)
{
    Create(parent, wxID_ANY, _("wxENIGMA - <new game>"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(886,465));
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ENIGMA_IDEFrame::OnClose);

    // *** Create Main AUI Managers ***
    mainAUIManager = new wxAuiManager(this, wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_DEFAULT);
    outputAUINotebook = new wxAuiNotebook(this, ID_OUTPUTAUINOTEBOOK, wxDefaultPosition, wxSize(95,431), wxAUI_NB_BOTTOM|wxAUI_NB_DEFAULT_STYLE);
    outputAUINotebook->SetMinSize(wxSize(0,150));
    mainAUIManager->AddPane(outputAUINotebook, wxAuiPaneInfo().Name(_T("OutputPane")).Caption(_("Output")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Bottom().BestSize(wxSize(95,431)).MinSize(wxSize(0,150)));
    managementAUINotebook = new wxAuiNotebook(this, ID_MANAGEMENTAUINOTEBOOK, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    managementAUINotebook->SetMinSize(wxSize(200,0));
    mainAUIManager->AddPane(managementAUINotebook, wxAuiPaneInfo().Name(_T("PaneName")).Caption(_("Management")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Layer(1).Right().MinSize(wxSize(200,0)));
    editingAUINotebook = new wxAuiNotebook(this, ID_EDITINGAUINOTEBOOK, wxPoint(29,40), wxSize(153,431), wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_DEFAULT_STYLE);
    editingAUINotebook->SetMinSize(wxSize(50,0));
    mainAUIManager->AddPane(editingAUINotebook, wxAuiPaneInfo().Name(_T("EditingPane")).Caption(_("Editing")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().CloseButton(false).Center().BestSize(wxSize(153,431)).MinSize(wxSize(50,0)));

    // *** Create Edit Toolbar ***
    editToolbar = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    editToolbar->AddTool(ID_SAVETOOLITEM, _("SaveItem"), wxBitmap(wxImage(_T("Resources/icons/disk.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_SAVEALLTOOLITEM, _("SaveAllItem"), wxBitmap(wxImage(_T("Resources/icons/disk_multiple.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save All"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM1, _("Hello"), wxBitmap(wxImage(_T("Resources/icons/cut.png"))), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM2, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_copy.png"))), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM3, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_paste.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pase"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM4, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_undo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM5, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_redo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL);
    editToolbar->AddSeparator();
    editToolbar->AddTool(ID_AUITOOLBARITEM28, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_white_code.png"))), wxNullBitmap, wxITEM_CHECK, _("Code Completion"), wxEmptyString, NULL);
    editToolbar->AddTool(ID_AUITOOLBARITEM29, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/spellcheck.png"))), wxNullBitmap, wxITEM_CHECK, _("Intellisense"), wxEmptyString, NULL);
    editToolbar->Realize();
    mainAUIManager->AddPane(editToolbar, wxAuiPaneInfo().Name(_T("EditPane")).ToolbarPane().Caption(_("Edit")).Layer(10).Top().Gripper());

    // *** Create Build Toolbar ***
    buildToolbar = new wxAuiToolBar(this, ID_BUILDTOOLBAR, wxPoint(168,10), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    buildToolbar->AddTool(ID_AUITOOLBARITEM6, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/stop_red.png"))), wxNullBitmap, wxITEM_NORMAL, _("Stop"), wxEmptyString, NULL);
    buildToolbar->EnableTool(ID_AUITOOLBARITEM6, false);
    buildToolbar->AddTool(ID_AUITOOLBARITEM8, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/pause_blue.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pause"), wxEmptyString, NULL);
    buildToolbar->EnableTool(ID_AUITOOLBARITEM8, false);
    buildToolbar->AddTool(ID_AUITOOLBARITEM7, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_large_right.png"))), wxNullBitmap, wxITEM_NORMAL, _("Run"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM9, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/arrow_large_right_orange.png"))), wxNullBitmap, wxITEM_NORMAL, _("Debug"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM10, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/application_xp_terminal.png"))), wxNullBitmap, wxITEM_NORMAL, _("Compile"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM14, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/controller.png"))), wxNullBitmap, wxITEM_NORMAL, _("Global Game Settings"), wxEmptyString, NULL);
    buildToolbar->AddTool(ID_AUITOOLBARITEM24, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/plugin.png"))), wxNullBitmap, wxITEM_NORMAL, _("Game Plugins"), wxEmptyString, NULL);
    buildToolbar->Realize();
    mainAUIManager->AddPane(buildToolbar, wxAuiPaneInfo().Name(_T("BuildPane")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());

    // *** Create Resources Toolbar ***
    resourcesToolbar = new wxAuiToolBar(this, ID_RESOURCESTOOLBAR, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM22, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/folder_add.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Folder"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM23, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/page_add.png"))), wxNullBitmap, wxITEM_NORMAL, _("Add External File"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM26, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/3d.png"))), wxNullBitmap, wxITEM_NORMAL, _("New 3D Primitive"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM27, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/images.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sprite"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM15, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/picture.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Image"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM25, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/chart_line.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Path"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM16, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/sound.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Sound"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM17, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/font.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Font"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM18, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/script.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Script"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM19, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/cog.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Object"), wxEmptyString, NULL);
    resourcesToolbar->AddTool(ID_AUITOOLBARITEM20, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/map.png"))), wxNullBitmap, wxITEM_NORMAL, _("New Room"), wxEmptyString, NULL);
    resourcesToolbar->Realize();
    mainAUIManager->AddPane(resourcesToolbar, wxAuiPaneInfo().Name(_T("ResourcesPane")).ToolbarPane().Caption(_("Resources")).Layer(10).Top().Gripper());

    // *** Other Toolbars... ***
    helpToolbar = new wxAuiToolBar(this, ID_HELPTOOLBAR, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    helpToolbar->AddTool(ID_AUITOOLBARITEM11, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/help.png"))), wxNullBitmap, wxITEM_NORMAL, _("Help"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM12, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/information.png"))), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM13, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/application_form.png"))), wxNullBitmap, wxITEM_NORMAL, _("Preferences"), wxEmptyString, NULL);
    helpToolbar->Realize();
    mainAUIManager->AddPane(helpToolbar, wxAuiPaneInfo().Name(_T("HelpPane")).ToolbarPane().Caption(_("Help")).Layer(10).Top().Gripper());
    quickfindToolBar = new wxAuiToolBar(this, ID_QUICKFINDTOOLBAR, wxPoint(841,8), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    quickfindToolBar->Realize();
    mainAUIManager->AddPane(quickfindToolBar, wxAuiPaneInfo().Name(_T("QuickFind")).ToolbarPane().Caption(_("Quick Find")).Layer(10).Top().Gripper());

    mainAUIManager->Update();

    hierarchyImageList = new wxImageList(16, 16, 11);
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/notice.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/warning.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/error.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/folder.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/page_white.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/script.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/font.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/picture.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/map.png"))));
    hierarchyImageList->Add(wxBitmap(wxImage(_T("Resources/icons/sound.png"))));

    CreateOutputLogTab();
    CreateOuputMessagesTab();
    OutputClearAll();

    CreateMainMenuBar();
    CreateMainStatusBar();
    CreateHierarchyTab();
    CreatePropertyTab();
    mainAUIManager->Update();
    CreateWelcomeTab();
    CreateScintillaTab();
    CreateScintillaTab();

    managementAUINotebook->ChangeSelection(0);
    outputAUINotebook->ChangeSelection(0);
    editingAUINotebook->ChangeSelection(0);

    OutputLine("IDE Loaded and Ready");
    mainStatusBar->SetStatusText(_T("Ready"));
}

ENIGMA_IDEFrame::~ENIGMA_IDEFrame()
{

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

struct MyTreeItemData: wxTreeItemData {
    bool is_directory = false;
    MyTreeItemData()
    {
    }
    MyTreeItemData(bool dir): is_directory(dir)
    {
    }
};

class HierTreeCtrl : public wxTreeCtrl
{
public:
        HierTreeCtrl(wxWindow* parent, long id);
        wxTreeItemId m_draggedItem;
        wxArrayTreeItemIds draggedItems;

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
            SetItemData(newItem, new MyTreeItemData(true));
            SetItemImage(newItem, 3, wxTreeItemIcon_Normal);
            return newItem;
        }


        wxTreeItemId AppendFile(wxTreeItemId& destination, const char *text)
        {
            wxTreeItemId newItem;
            newItem = AppendItem(destination, wxString::FromUTF8(text));
            SetItemData(newItem, new MyTreeItemData(false));
            SetItemImage(newItem, 4, wxTreeItemIcon_Normal);
            return newItem;
        }

        wxTreeItemId MoveItem(wxTreeItemId& source, wxTreeItemId& destination, wxTreeItemId& parent)
        {
            wxTreeItemId newItem;
            if (parent != destination)
            {
                newItem = InsertItem(parent, destination, GetItemText(source), GetItemImage(source), -1,
                                    new MyTreeItemData(*(MyTreeItemData*)GetItemData(source)));
            }
            else
            {
                newItem = AppendItem(destination, GetItemText(source), GetItemImage(source), -1,
                                    new MyTreeItemData(*(MyTreeItemData*)GetItemData(source)));
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

        void OnBeginDrag(wxTreeEvent& event)
        {
                GetSelections(draggedItems);
                // need to explicitly allow drag
                if ( event.GetItem() != GetRootItem() )
                {
                        m_draggedItem = event.GetItem();
                        SelectItem(m_draggedItem);

                        wxPoint clientpt = event.GetPoint();
                        wxPoint screenpt = ClientToScreen(clientpt);
                        event.Allow();
                }
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
                    draggedItems.Clear();
                    return;
                }

                if (((MyTreeItemData*)GetItemData(itemDst))->is_directory == false)
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


HierTreeCtrl::HierTreeCtrl(wxWindow* parent, const long id = wxID_ANY)
: wxTreeCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_LINES_AT_ROOT)
{

}

HierTreeCtrl* hierarchyTreeCtrl;
void ENIGMA_IDEFrame::CreateHierarchyTab()
{
   // wxDefaultPosition, wxDefaultSize,
   //   wxDefaultValidator, _T("ID_HIERARCHYTREECTRL")
    hierarchyTreeCtrl = new HierTreeCtrl(this, ID_HIERARCHYTREECTRL);
    hierarchyTreeCtrl->SetWindowStyle(wxTR_HIDE_ROOT|wxTR_MULTIPLE|wxTR_NO_LINES|wxTR_TWIST_BUTTONS|wxTR_EDIT_LABELS|wxTR_DEFAULT_STYLE|wxVSCROLL|wxHSCROLL|wxTR_HAS_VARIABLE_ROW_HEIGHT);
    wxFont Font_2(10, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    //hierarchyTreeCtrl->SetFont(Font_2);
    wxTreeItemId hierarchyTreeCtrl_rootItem = hierarchyTreeCtrl->AddRoot(_T("Root Node"));
    wxTreeItemId hierarchyTreeCtrl_Item2 = hierarchyTreeCtrl->AppendDirectory(hierarchyTreeCtrl_rootItem, "Rooms");
    wxTreeItemId hierarchyTreeCtrl_Item3 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_Item2, "Room");
    wxTreeItemId hierarchyTreeCtrl_Item4 = hierarchyTreeCtrl->AppendDirectory(hierarchyTreeCtrl_rootItem, "Fonts");
    wxTreeItemId hierarchyTreeCtrl_Item5 = hierarchyTreeCtrl->AppendDirectory(hierarchyTreeCtrl_Item4, "HUD");
    wxTreeItemId hierarchyTreeCtrl_Item6 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_Item5, "Font");
    wxTreeItemId hierarchyTreeCtrl_Item7 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_Item4, "Font");
    wxTreeItemId hierarchyTreeCtrl_Item8 = hierarchyTreeCtrl->AppendDirectory(hierarchyTreeCtrl_rootItem, "Guns");
    wxTreeItemId hierarchyTreeCtrl_Item9 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_Item8, "Script");
    wxTreeItemId hierarchyTreeCtrl_Item10 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_rootItem, "Script");
    wxTreeItemId hierarchyTreeCtrl_Item11 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_rootItem, "Image");
    wxTreeItemId hierarchyTreeCtrl_Item12 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_rootItem, "Image");
    wxTreeItemId hierarchyTreeCtrl_Item13 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_rootItem, "Image");
    wxTreeItemId hierarchyTreeCtrl_Item14 = hierarchyTreeCtrl->AppendFile(hierarchyTreeCtrl_rootItem, "Sound");
    hierarchyTreeCtrl->ScrollTo(hierarchyTreeCtrl_Item2);
    hierarchyTreeCtrl->SetMinSize(wxSize(150,0));
    managementAUINotebook->AddPage(hierarchyTreeCtrl, _("Hierarchy"), true);

    // Set the images for hierarchyTreeCtrl.
    hierarchyTreeCtrl->SetImageList(hierarchyImageList);

    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item3, 8, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item6, 6, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item7, 6, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item9, 5, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item10, 5, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item11, 7, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item12, 7, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item13, 7, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item14, 9, wxTreeItemIcon_Normal);
}

void ENIGMA_IDEFrame::CreateWelcomeTab()
{
    htmlWelcome = new wxHtmlWindow(editingAUINotebook, ID_HTMLWELCOME, wxPoint(214,121), wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxVSCROLL|wxHSCROLL, _T("ID_HTMLWELCOME"));
    htmlWelcome->LoadPage(_("Resources/welcome/welcome.html"));

   // htmlWelcome->SetVirtualSize(wxSize(500, 500));
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
    propertyCtrl->Append( new wxColourProperty(wxT("Colour Property"), wxPG_LABEL, wxColour(21,190,237)) );
    // A file selector property.
    propertyCtrl->Append( new wxColourProperty(wxT("Colour Property2"), wxPG_LABEL, wxColour(20,109,20)) );
    managementAUINotebook->AddPage(propertyCtrl, _("Properties"), true);
}


wxStyledTextCtrl* text;
void ENIGMA_IDEFrame::CreateScintillaTab()
{

    text = new wxStyledTextCtrl(this, wxID_ANY);
    text->StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour (0, 0, 0) );
    text->StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour (255, 255, 255));
    wxFont Font_2(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_DEFAULT, Font_2);
    text->SetWrapMode (wxSTC_WRAP_NONE);

text->StyleSetBackground(wxSTC_MARK_EMPTY, wxColour (255,0,0));
text->StyleSetBackground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );
text->MarkerSetBackground(MARGIN_FOLD, wxColor(255, 0, 0) );
    text->StyleClearAll();
text->MarkerSetBackground(wxSTC_MARK_BOXMINUS, wxColor(255, 0, 0) );
text->MarkerSetBackground(wxSTC_MARK_VLINE, wxColor(255, 0, 0) );
//text->StyleSetForeground(wxSTC_MARK_BACKGROUND, wxColor(255, 0, 0) );

    // caret and selected line
    text->SetCaretForeground(wxColor(0, 0, 0));
    text->SetCaretLineBackground(wxColor(255, 255, 255));
    text->SetCaretLineVisible(true);

    // line number style has to be set after clearing the styles
    text->StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (92, 92, 92) );
    //text->StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (239, 229, 220));
    wxFont Font_3(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_LINENUMBER, Font_3);
    text->SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
    text->SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

    // ----- Enable code folding
    text->SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    text->SetMarginWidth(MARGIN_FOLD, 16);
    text->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);


    text->SetMarginSensitive(MARGIN_FOLD, true);

    // Properties found from http://www.scintilla.org/SciTEDoc.html
    text->SetProperty (wxT("fold"),         wxT("1") );
    text->SetProperty (wxT("fold.comment"), wxT("1") );
    text->SetProperty (wxT("fold.compact"), wxT("0") );

    wxColor grey( 150, 150, 150);
    wxColor white(0, 0, 0);
    wxColor black(255, 255, 255);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_BOXMINUS, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_VLINE, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_BOXPLUSCONNECTED, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUSCONNECTED, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_TCORNER, black, grey);
    text->MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_LCORNER, black, grey);
    // ----- End of code folding part

    // ----- Styling
    text->SetLexer(wxSTC_LEX_CPP);
    text->StyleSetForeground (wxSTC_CACHE_CARET,            wxColour(255,128,128));
    text->StyleSetForeground (wxSTC_C_STRING,            wxColour(0,0,255));
    text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(0,0,255));
    text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(0,0,255));
    text->StyleSetForeground (wxSTC_C_WORD,              wxColour(0,102,153));
    text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(190, 80, 75));
    text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(0, 130, 0));
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(0, 130, 0));
    //----- End of styling

    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0,
    wxT("return for while break if var globalvar repeat else mod draw_sprite_part_ext draw_set_color random sprite_get_width sprite_get_height"));
    text->SetKeyWords(1, wxT("c_yellow c_white argument0 argument1 argument2 argument3 argument4 argument5 argument6 argument7"));

    text->LoadFile(_T("Resources/examplescript.txt"));
    text->SetSelection(0, 0);
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
    wxFont Font_1(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    outputLogCtrl->SetFont(Font_1);
    outputAUINotebook->AddPage(outputLogCtrl, _("Log"));
}

void ENIGMA_IDEFrame::CreateOuputMessagesTab()
{
    messagesListView = new wxListView(this);
    messagesListView->AppendColumn(wxString("Origin"));
    messagesListView->AppendColumn(wxString("Location"));
    messagesListView->AppendColumn(wxString("Description"));
    messagesListView->SetColumnWidth(0, 140);
    messagesListView->SetColumnWidth(1, 100);
    messagesListView->SetColumnWidth(2, 500);
    messagesListView->SetImageList(hierarchyImageList, wxIMAGE_LIST_NORMAL);
    wxFont Font_2(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    messagesListView->SetFont(Font_2);
    //messagesListView->SetSingleStyle(wxLC_HRULES, true);
    outputAUINotebook->AddPage(messagesListView, _("Messages"));
}

void ENIGMA_IDEFrame::OutputClearAll()
{
    ENIGMA_IDEFrame::OutputLogClear();
    ENIGMA_IDEFrame::OutputMessagesClear();
}

void ENIGMA_IDEFrame::OutputMessagesClear()
{
    messagesListView->DeleteAllItems();
}

void ENIGMA_IDEFrame::OutputLogClear()
{
    outputLogCtrl->Clear();
    // repaints the control...
    outputLogCtrl->Update();
}

void ENIGMA_IDEFrame::OutputText(const char *text)
{
    outputLogCtrl->WriteText(wxString::FromUTF8(text));
    // repaints the control...
    outputLogCtrl->Update();
}

void ENIGMA_IDEFrame::OutputLine(const char *text)
{
    outputLogCtrl->WriteText(wxString::FromUTF8(text) + _T("\n"));
    // repaints the control...
    outputLogCtrl->Update();
}

void ENIGMA_IDEFrame::OutputMessage(int type, const char *origin, const char *location, const char *description)
{
    int id = messagesListView->GetItemCount();
    wxListItem listItem;
    listItem.SetId(id);
    //listItem.SetText(uniquename);
    switch (type)
    {
        case MSG_NOTICE:
            // notice
            listItem.SetImage(0);
            break;
        case MSG_WARNING:
            listItem.SetImage(1);
            // warning
            break;
        case MSG_ERROR:
            listItem.SetImage(2);
            // error
            break;
        default:
            // other
            break;
    }
    messagesListView->InsertItem(listItem);
    messagesListView->SetItem(id, 0, wxString::FromUTF8(origin));
    messagesListView->SetItem(id, 1, wxString::FromUTF8(location));
    messagesListView->SetItem(id, 2, wxString::FromUTF8(description));
}

void ENIGMA_IDEFrame::OnClose(wxCloseEvent& event)
{
    //mainAUIManager->SavePerspective();
    event.Skip();
}
