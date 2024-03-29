/**
* @file ENIGMA_IDEMain.cpp
* @brief Source file of the main IDE frame.
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

#include "ENIGMA_IDEMain.h"
#include "CustomControls/CodeEditor.h"
#include <wx/msgdlg.h>

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>

#include "LoadLibrary.h"

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


ENIGMA_IDEFrame::ENIGMA_IDEFrame(wxWindow* parent, wxWindowID id)
{
    Create(parent, wxID_ANY, _("ENIGMA - <new game>"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(900,600));
    SetIcon(wxIcon(_T("Resources/enigmaicon.ico"), wxBITMAP_TYPE_ICO));
    //SetIcon(wxICON(aaaa));
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ENIGMA_IDEFrame::OnClose);

    // *** Create Main AUI Managers ***
    mainAUIManager = new wxAuiManager(this, wxAUI_MGR_LIVE_RESIZE|wxAUI_MGR_ALLOW_ACTIVE_PANE|wxAUI_MGR_DEFAULT);
    outputAUINotebook = new wxAuiNotebook(this, ID_OUTPUTAUINOTEBOOK, wxDefaultPosition, wxSize(95,431), wxAUI_NB_BOTTOM|wxAUI_NB_DEFAULT_STYLE);
    outputAUINotebook->SetMinSize(wxSize(0,150));
    mainAUIManager->AddPane(outputAUINotebook, wxAuiPaneInfo().Name(_T("OutputPane")).Caption(_("Output")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Bottom().BestSize(wxSize(95,431)).MinSize(wxSize(0,150)));
    managementAUINotebook = new wxAuiNotebook(this, ID_MANAGEMENTAUINOTEBOOK, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    managementAUINotebook->SetMinSize(wxSize(200,0));
    mainAUIManager->AddPane(managementAUINotebook, wxAuiPaneInfo().Name(_T("PaneName")).Caption(_("Management")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().Layer(1).Right().MinSize(wxSize(200,0)));
    editingAUINotebook = new wxAuiNotebook(this, ID_EDITINGAUINOTEBOOK, wxPoint(29,40), wxSize(153,431), wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_DEFAULT_STYLE);
    editingAUINotebook->SetMinSize(wxSize(50,0));
    mainAUIManager->AddPane(editingAUINotebook, wxAuiPaneInfo().Name(_T("EditingPane")).Caption(_("Editing")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().CloseButton(false).Center().BestSize(wxSize(153,431)).MinSize(wxSize(50,0)));

    // *** Create Toolbars ***

    CreateMainMenuBar();
    CreateMainStatusBar();

    editToolbar = new EditToolbar(this, wxID_ANY);
    buildToolbar = new BuildToolbar(this, wxID_ANY);
    resourcesToolbar = new ResourceToolbar(this, wxID_ANY);
    editToolbar->Hide();

    // *** Other Toolbars... ***
    helpToolbar = new wxAuiToolBar(this, ID_HELPTOOLBAR, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    helpToolbar->AddTool(ID_AUITOOLBARITEM11, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/help.png"))), wxNullBitmap, wxITEM_NORMAL, _("Help"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM12, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/layout.png"))), wxNullBitmap, wxITEM_NORMAL, _("Reset Layout"), wxEmptyString, NULL);
    helpToolbar->AddTool(ID_AUITOOLBARITEM13, _("Item label"), wxBitmap(wxImage(_T("Resources/icons/application_form.png"))), wxNullBitmap, wxITEM_NORMAL, _("Preferences"), wxEmptyString, NULL);
    helpToolbar->Realize();

    quickfindToolbar = new wxAuiToolBar(this, ID_QUICKFINDTOOLBAR, wxPoint(841,8), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    quickfindToolbar->Realize();

    // *** Add Created Toolbars... ***
    mainAUIManager->AddPane(quickfindToolbar, wxAuiPaneInfo().Name(_T("QuickFind")).ToolbarPane().Caption(_("Quick Find")).Layer(10).Top().Gripper());
    mainAUIManager->AddPane(resourcesToolbar, wxAuiPaneInfo().Name(_T("ResourcesPane")).ToolbarPane().Caption(_("Resources")).Layer(10).Top().Gripper());
    mainAUIManager->AddPane(helpToolbar, wxAuiPaneInfo().Name(_T("HelpPane")).ToolbarPane().Caption(_("Help")).Layer(10).Top().Gripper());
    mainAUIManager->AddPane(buildToolbar, wxAuiPaneInfo().Name(_T("BuildPane")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    mainAUIManager->AddPane(editToolbar, wxAuiPaneInfo().Name(_T("EditPane")).ToolbarPane().Caption(_("Edit")).Layer(10).Top().Gripper());
    mainAUIManager->Update();

    mainAUIManager->GetPane(quickfindToolbar).Hide();

//this->
    ControlImages = new wxImageList(16, 16, 14);
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/notice.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/warning.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/error.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/link_break.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/tag.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/text_superscript.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/folder.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/folder_open.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/page_white.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/page_white_code.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/style.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/picture.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/room.png"))));
    ControlImages->Add(wxBitmap(wxImage(_T("Resources/icons/sound.png"))));

    CreateOutputLogTab();
    CreateOuputMessagesTab();
    this->Show();
    OutputClearAll();

    OutputLine("Loading and linking compiler...");
    void *result = LoadPluginLib(this);
    //void *result;
    if (result == NULL)
    {
        wxMessageDialog (NULL, "Failed to communicate with the plugin. Have you compiled and built ENIGMA yet?",
                         "Plugin Loading Failed", wxOK|wxCENTRE|wxICON_ERROR, wxDefaultPosition).ShowModal();
        OutputMessage(MSG_ERROR, "Linking", "IDE Initialization",
                  "Failed to load the compiler library. ENIGMA may not have been compiled yet or is not in a relative directory.");
    }

    OutputMessage(MSG_NOTICE, "Notice", "IDE Initialization",
      "Failed to load the compiler library. ENIGMA may not have been compiled yet or is not in a relative directory.");
    OutputMessage(MSG_WARNING, "Warning", "IDE Initialization",
      "Failed to load the compiler library. ENIGMA may not have been compiled yet or is not in a relative directory.");
    OutputMessage(MSG_ERROR, "Error", "IDE Initialization",
      "Failed to load the compiler library. ENIGMA may not have been compiled yet or is not in a relative directory.");

    OutputLine("Loading definitions...");
    definitionsModified("", ((const char*) "%e-yaml\n"
    "---\n"
    "treat-literals-as: 0\n"
    "sample-lots-of-radios: 0\n"
    "inherit-equivalence-from: 0\n"
    "sample-checkbox: on\n"
    "sample-edit: DEADBEEF\n"
    "sample-combobox: 0\n"
    "inherit-strings-from: 0\n"
    "inherit-escapes-from: 0\n"
    "inherit-increment-from: 0\n"
    " \n"
    "target-audio: OpenAL\n"
    "target-windowing: xlib\n"
    "target-compiler: gcc\n"
    "target-graphics: OpenGL1\n"
    "target-widget: None\n"
    "target-collision: BBox\n"
    "target-networking: None\n"
    ));

    OutputLine("Parsing definitions...");
    const char* currentResource = (const char*) first_available_resource();
    // some edl keywords must be hard coded
    fncWords = wxString("return for while break if var global var repeat else mod");
    varWords = wxString("argument0 argument1 argument2 argument3 argument4 argument5 argument6 argument7 x y sprite_index image_index"
                        " true false");
    acpWords = wxString("");
    while (!resources_atEnd())
    {
        if (resource_isFunction())
        {
            functionWords.push_back(wxString(currentResource));
            fncWords.Append(currentResource).Append(" ");
            acpWords.Append(currentResource).Append("?0 ");
        }
        else
        {
            variableWords.push_back(wxString(currentResource));
            varWords.Append(currentResource).Append(" ");
            acpWords.Append(currentResource).Append("?1 ");
        }
        currentResource = next_available_resource();
    }

    CreateHierarchyTab();
    CreatePropertyTab();
    mainAUIManager->Update();
    CreateWelcomeTab();

    managementAUINotebook->ChangeSelection(0);
    outputAUINotebook->ChangeSelection(0);
    editingAUINotebook->ChangeSelection(0);

    OutputLine("IDE Loaded and Ready");
    mainStatusbar->SetStatusText(_T("Ready"));
}

ENIGMA_IDEFrame::~ENIGMA_IDEFrame()
{
    mainAUIManager->UnInit();
}

void ENIGMA_IDEFrame::ShowFindAndReplace()
{
    if (findAndReplace == NULL)
    {
      findAndReplace = new FindAndReplace(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
      findAndReplace->SetMinSize(wxSize(50,0));
      mainAUIManager->AddPane(findAndReplace, wxAuiPaneInfo().Name(_T("FindAndReplacePane")).Caption(_("Find and Replace")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().CloseButton(true).Float().Center().BestSize(wxDefaultSize).MinSize(wxSize(50,0)));
            mainAUIManager->Update();
    } else {
        mainAUIManager->Update();
      findAndReplace->Show();
    }
}

void ENIGMA_IDEFrame::ShowAboutFrame()
{
    if (aboutFrame == NULL)
    {
        aboutFrame = new AboutFrame(this, wxID_ANY);
    }

    aboutFrame->Show();
}

void ENIGMA_IDEFrame::ShowSettingsFrame()
{
    if (settingsFrame == NULL)
    {
        settingsFrame = new ProjectSettings(this, wxID_ANY);
    }

    settingsFrame->Show();
}

void ENIGMA_IDEFrame::ShowPreferencesFrame()
{
    if (preferencesFrame == NULL)
    {
        preferencesFrame = new Preferences(this, wxID_ANY);
    }

    preferencesFrame->Show();
}

void ENIGMA_IDEFrame::CreateMainMenuBar()
{
    mainMenuBar = new MainMenubar(this);
    SetMenuBar(mainMenuBar);
}

void ENIGMA_IDEFrame::CreateMainStatusBar()
{
    mainStatusbar = new MainStatusbar(this, ID_MAINSTATUSBAR);
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    mainStatusbar->SetFieldsCount(1,__wxStatusBarWidths_1);
    mainStatusbar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(mainStatusbar);
}

void ENIGMA_IDEFrame::CreateHierarchyTab()
{
   // wxDefaultPosition, wxDefaultSize,
   //   wxDefaultValidator, _T("ID_HIERARCHYTREECTRL")
    hierarchyTreeCtrl = new HierTreeCtrl(this, ID_HIERARCHYTREECTRL);
    hierarchyTreeCtrl->SetWindowStyle(wxTR_HIDE_ROOT|wxTR_MULTIPLE|wxTR_NO_LINES|wxTR_TWIST_BUTTONS|wxTR_EDIT_LABELS|wxTR_DEFAULT_STYLE|wxVSCROLL|wxHSCROLL|wxTR_HAS_VARIABLE_ROW_HEIGHT);
    wxFont Font_2(10, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    //hierarchyTreeCtrl->SetFont(Font_2);
    wxTreeItemId hierarchyTreeCtrl_rootItem = hierarchyTreeCtrl->AddRoot(_T("Root Node"));
    wxTreeItemId hierarchyTreeCtrl_Item2 = hierarchyTreeCtrl->AppendDirectory(hierarchyTreeCtrl_rootItem, "Scenes");
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
    hierarchyTreeCtrl->SetImageList(ControlImages);

    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item3, 12, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item6, 10, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item7, 10, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item9, 9, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item10, 9, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item11, 11, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item12, 11, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item13, 11, wxTreeItemIcon_Normal);
    hierarchyTreeCtrl->SetItemImage(hierarchyTreeCtrl_Item14, 13, wxTreeItemIcon_Normal);
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

void ENIGMA_IDEFrame::CreateScintillaTab()
{

    StyledTextCtrl* text;
    text = new StyledTextCtrl(this, wxID_ANY);

    wxFont Font_2(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_DEFAULT, Font_2);
    text->SetWrapMode (wxSTC_WRAP_NONE);

    text->StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour (0, 0, 0) );
    text->StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour (255, 255, 255));

    text->StyleClearAll();

    //text->MarkerSetBackground(wxSTC_MARK_BOXMINUS, wxColor(255, 0, 0) );
    //ext->MarkerSetBackground(wxSTC_MARK_VLINE, wxColor(255, 0, 0) );

    // caret and selected line
    text->SetCaretForeground(wxColor(0, 0, 0));
    text->SetCaretLineBackground(wxColor(255, 255, 255));
    text->SetCaretLineVisible(true);

    // line number style has to be set after clearing the styles
    text->StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (92, 92, 92) );
    //text->StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (239, 229, 220));
    wxFont Font_3(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    text->StyleSetFont(wxSTC_STYLE_LINENUMBER, Font_3);
    text->SetMarginWidth (MARGIN_LINE_NUMBERS, 40);
    text->SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

    // ----- Enable break points
    text->SetMarginWidth (MARGIN_LINE_BREAKS, 16);
    text->SetMarginType (MARGIN_LINE_BREAKS, wxSTC_MARGIN_SYMBOL);
    text->SetMarginSensitive(MARGIN_LINE_BREAKS, true);
    text->MarkerDefineBitmap(0, ControlImages->GetBitmap(3));

    // ----- Enable line edits
    text->SetMarginWidth (MARGIN_LINE_EDITS, 0);
    text->SetMarginType (MARGIN_LINE_EDITS, wxSTC_MARGIN_SYMBOL);
    text->SetMarginSensitive(MARGIN_LINE_EDITS, true);

    // ----- Enable code folding
    text->SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    text->SetMarginWidth(MARGIN_FOLD, 16);
    text->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);
    text->SetMarginSensitive(MARGIN_FOLD, true);

    // Properties found from http://www.scintilla.org/SciTEDoc.html
    text->SetProperty (wxT("fold"),         wxT("1") );
    text->SetProperty (wxT("fold.comment"), wxT("1") );
    text->SetProperty (wxT("fold.compact"), wxT("0") );

    wxColor grey( 255, 0, 0);
    wxColor white(0, 0, 0);
    wxColor black(255, 2, 5);
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
    text->StyleSetForeground (wxSTC_CACHE_CARET,         wxColour(255, 128, 128));
    text->StyleSetForeground (wxSTC_C_STRING,            wxColour(0, 0, 255));
    text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(0, 0, 255));
    text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(0, 0, 255));
    text->StyleSetForeground (wxSTC_C_WORD,              wxColour(0, 102, 153));
    text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(190, 80, 75));
    text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(0, 130, 0));
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(0, 130, 0));
    //----- End of styling

    text->AutoCompSetAutoHide(true);

    text->LoadFile(_T("Resources/examplescript.gml"));
    text->SetSelection(0, 0);
    editingAUINotebook->AddPage(text, _("examplescript"), true);
}

void ENIGMA_IDEFrame::CreateOutputLogTab()
{
    outputLogCtrl = new wxRichTextCtrl(outputAUINotebook, ID_OUTPUTLOGCTRL, _("Output log will be displayed here."), wxDefaultPosition, wxDefaultSize,
    wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_OUTPUTLOGCTRL"));
    wxRichTextAttr rchtxtAttr;
    rchtxtAttr.SetLineSpacing(wxTEXT_ATTR_LINE_SPACING_NORMAL);
    outputLogCtrl->SetBasicStyle(rchtxtAttr);
    wxFont monoFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    outputLogCtrl->SetFont(monoFont);
    outputAUINotebook->AddPage(outputLogCtrl, _("Log"));
    Bind(CROSS_THREAD_CODE, &ENIGMA_IDEFrame::OnMyEvent, this, wxID_ANY);
}

void ENIGMA_IDEFrame::CreateOuputMessagesTab()
{
    messagesListView = new wxListView(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    messagesListView->AppendColumn(wxString("Origin"));
    messagesListView->AppendColumn(wxString("Location"));
    messagesListView->AppendColumn(wxString("Description"));
    messagesListView->SetColumnWidth(0, 140);
    messagesListView->SetColumnWidth(1, 100);
    messagesListView->SetColumnWidth(2, 600);
    messagesListView->SetImageList(ControlImages, wxIMAGE_LIST_SMALL);
    wxFont Font_2(8, wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    messagesListView->SetFont(Font_2);
    outputAUINotebook->AddPage(messagesListView, _("Messages"));
}

struct CTF_OutputClear: ENIGMA_IDEFrame::CrossThreadFrame {
    bool clog;
    bool cmessages;
    CTF_OutputClear(ENIGMA_IDEFrame *f, bool clearlog, bool clearmessages): CrossThreadFrame(f), clog(clearlog), cmessages(clearmessages) {}

    void exec() {
        if (cmessages)
        {
            frame->messagesListView->DeleteAllItems();
        }
        if (clog)
        {
            frame->outputLogCtrl->Clear();
            frame->outputLogCtrl->Update(); // this forces it to repaint so that u see the change immediately
        }
    }
};

void ENIGMA_IDEFrame::OutputClearAll()
{
  wxPostEvent(this, CT_Event(new CTF_OutputClear(this, true, true)));
}

void ENIGMA_IDEFrame::OutputMessagesClear()
{
  wxPostEvent(this, CT_Event(new CTF_OutputClear(this, false, true)));
}

void ENIGMA_IDEFrame::OutputLogClear()
{
  wxPostEvent(this, CT_Event(new CTF_OutputClear(this, true, false)));
}

void ENIGMA_IDEFrame::OnMyEvent(CT_Event& event)
{
    // do something
    wxMutexGuiEnter();
        event.fire();
    wxMutexGuiLeave();
}

struct CTF_OutputText: ENIGMA_IDEFrame::CrossThreadFrame {
    wxString text;
    CTF_OutputText(ENIGMA_IDEFrame *f, const char* t): CrossThreadFrame(f), text(t) {}

    void exec() {
        frame->outputLogCtrl->AppendText(wxString::FromUTF8(text)); // this appends it to the rtf ctrl
        // repaints the control...
        frame->outputLogCtrl->ShowPosition(frame->outputLogCtrl->GetLastPosition()); // this makes it scroll to the very bottom
        frame->outputLogCtrl->Update(); // this forces it to repaint so that u see the change immediately
    }
};

void ENIGMA_IDEFrame::OutputText(const char *text) {
    wxPostEvent(this, CT_Event(new CTF_OutputText(this, text)));
}

struct CTF_SetProgress: ENIGMA_IDEFrame::CrossThreadFrame {
    int progress;
    CTF_SetProgress(ENIGMA_IDEFrame *f, int p): CrossThreadFrame(f), progress(p) {}
    void exec() {
        if (progress > 0) { frame->mainStatusbar->SetProgress(progress); }
        else { cout << progress; puts(" ERROR: Progress gauge cannot be set lower than 0"); }
        frame->mainStatusbar->progressGauge->Update();
    }
};

struct CTF_SetProgressText: ENIGMA_IDEFrame::CrossThreadFrame {
    wxString text;
    CTF_SetProgressText(ENIGMA_IDEFrame *f, const char* t): CrossThreadFrame(f), text(t) {}

    void exec() {
        frame->mainStatusbar->SetStatusText(text);
    }
};

void ENIGMA_IDEFrame::SetProgress(int progress) {
    wxPostEvent(this, CT_Event(new CTF_SetProgress(this, progress)));
}

void ENIGMA_IDEFrame::SetProgressText(const char *text) {
    wxPostEvent(this, CT_Event(new CTF_SetProgressText(this, text)));
}


void ENIGMA_IDEFrame::OutputLine(const char *text)
{
    wxPostEvent(this, CT_Event(new CTF_OutputText(this, text)));
    wxPostEvent(this, CT_Event(new CTF_OutputText(this, "\n")));
}

struct CTF_OutputMessage: ENIGMA_IDEFrame::CrossThreadFrame {
    int type;
    const char* origin;
    const char* location;
    const char* description;
    CTF_OutputMessage(ENIGMA_IDEFrame *f, int t, const char *orig, const char *locat, const char *desc):
    CrossThreadFrame(f), type(t), origin(orig), location(locat), description(desc) {}

    void exec() {
      int id = frame->messagesListView->GetItemCount();
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

      frame->messagesListView->InsertItem(listItem);

      frame->messagesListView->SetItem(id, 0, wxString::FromUTF8(origin));
      frame->messagesListView->SetItem(id, 1, wxString::FromUTF8(location));
      frame->messagesListView->SetItem(id, 2, wxString::FromUTF8(description));
    }
};

void ENIGMA_IDEFrame::OutputMessage(int type, const char *origin, const char *location, const char *description)
{
    wxPostEvent(this, CT_Event(new CTF_OutputMessage(this, type, origin, location, description)));
}

void ENIGMA_IDEFrame::OnClose(wxCloseEvent& event)
{
    //mainAUIManager->SavePerspective();
    //mainAUIManager->LoadPerspective()
    event.Skip();
}
