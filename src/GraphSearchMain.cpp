/***************************************************************
 * Name:      GraphSearchMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Prakash (pranphy@gmail.com)
 * Created:   2015-08-30
 * Copyright: Prakash (pranphy.com)
 * License:
 **************************************************************/

#include "GraphSearchMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(GraphSearchFrame)
#include <wx/string.h>
#include <wx/intl.h>
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

//(*IdInit(GraphSearchFrame)
const long GraphSearchFrame::ID_STATICTEXT1 = wxNewId();
const long GraphSearchFrame::ID_TEXTCTRL1 = wxNewId();
const long GraphSearchFrame::ID_FullImagePanel = wxNewId();
const long GraphSearchFrame::ID_AnalyzeButton = wxNewId();
const long GraphSearchFrame::ID_SolveAutomaticButton = wxNewId();
const long GraphSearchFrame::ID_DisplayPanel = wxNewId();
const long GraphSearchFrame::ID_SelectImageMenu = wxNewId();
const long GraphSearchFrame::ID_MenuQuit = wxNewId();
const long GraphSearchFrame::ID_MenuAbout = wxNewId();
const long GraphSearchFrame::ID_OnlyStatusBar = wxNewId();
//*)

const long GraphSearchFrame::ID_FullImageSBitmap = wxNewId();
const long GraphSearchFrame::ID_FullImageBitmap = wxNewId();

const int GraphSearchFrame::ScaledImageHeight = 600;
const int GraphSearchFrame::ScaledImageWidth = 400;


BEGIN_EVENT_TABLE(GraphSearchFrame,wxFrame)
    //(*EventTable(GraphSearchFrame)
    //*)
END_EVENT_TABLE()

GraphSearchFrame::GraphSearchFrame(wxWindow* parent,wxWindowID id)
{
	ImagePath = string("./res/images");
	DefaultFolder = string("/BKD");

	ostringstream FullImagePath;
	FullImagePath<<ImagePath<<DefaultFolder<<"/Full.png";

	wxImage ScaledImage(wxString::FromUTF8(FullImagePath.str().c_str()));
	wxImage DupImage = ScaledImage.Scale(ScaledImageWidth,ScaledImageHeight);

	FullImageBitmap = new wxBitmap(DupImage);


    //(*Initialize(GraphSearchFrame)
    wxMenuItem* AboutMenuItem;
    wxStaticBoxSizer* ControlSBSizer;
    wxMenuBar* OnlyMenuBar;
    wxStaticBoxSizer* ButtonsSBSizer;
    wxMenu* FileMenu;
    wxFlexGridSizer* ControlFGSizer;
    wxFlexGridSizer* PlayFGSizer;
    wxStaticBoxSizer* PhotoSBSizer;
    wxFlexGridSizer* UserFormFGSizer;
    wxMenu* HelpMenu;
    wxStaticBoxSizer* FullImageSBSizer;
    wxMenuItem* QuitMenuItem;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1000,850));
    OutermostAuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    FullImagePanel = new wxPanel(this, ID_FullImagePanel, wxPoint(101,185), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_FullImagePanel"));
    FullImagePanel->SetMinSize(wxSize(250,0));
    ControlFGSizer = new wxFlexGridSizer(1, 2, 0, 0);
    ControlFGSizer->AddGrowableCol(0);
    ControlFGSizer->AddGrowableRow(0);
    ControlSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, FullImagePanel, _("Label"));
    UserFormFGSizer = new wxFlexGridSizer(3, 2, 0, 0);
    StaticText1 = new wxStaticText(FullImagePanel, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    UserFormFGSizer->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(FullImagePanel, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(124,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    UserFormFGSizer->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ControlSBSizer->Add(UserFormFGSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ControlFGSizer->Add(ControlSBSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    FullImageSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, FullImagePanel, _("Label"));
    ControlFGSizer->Add(FullImageSBSizer, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    FullImagePanel->SetSizer(ControlFGSizer);
    ControlFGSizer->Fit(FullImagePanel);
    ControlFGSizer->SetSizeHints(FullImagePanel);
    OutermostAuiManager->AddPane(FullImagePanel, wxAuiPaneInfo().Name(_T("PaneName")).DefaultPane().Caption(_("Pane caption")).CaptionVisible().Left().MinSize(wxSize(250,0)));
    DisplayPanel = new wxPanel(this, ID_DisplayPanel, wxPoint(153,159), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_DisplayPanel"));
    DisplayPanel->SetMinSize(wxSize(400,-1));
    PlayFGSizer = new wxFlexGridSizer(2, 1, 0, 0);
    PlayFGSizer->AddGrowableCol(0);
    PlayFGSizer->AddGrowableCol(1);
    PlayFGSizer->AddGrowableRow(0,8);
    PlayFGSizer->AddGrowableRow(1,1);
    PhotoSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, DisplayPanel, _("Move Pieces"));
    PlayFGSizer->Add(PhotoSBSizer, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 1);
    ButtonsSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, DisplayPanel, _("Label"));
    AnalyzeButton = new wxButton(DisplayPanel, ID_AnalyzeButton, _("Analyze"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_AnalyzeButton"));
    ButtonsSBSizer->Add(AnalyzeButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SolveAutomaticButton = new wxButton(DisplayPanel, ID_SolveAutomaticButton, _("Solve Automatic"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SolveAutomaticButton"));
    ButtonsSBSizer->Add(SolveAutomaticButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PlayFGSizer->Add(ButtonsSBSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DisplayPanel->SetSizer(PlayFGSizer);
    PlayFGSizer->Fit(DisplayPanel);
    PlayFGSizer->SetSizeHints(DisplayPanel);
    OutermostAuiManager->AddPane(DisplayPanel, wxAuiPaneInfo().Name(_T("PaneName")).CenterPane().Caption(_("Pane caption")).Row(1).Position(-1).MinSize(wxSize(400,-1)));
    OutermostAuiManager->Update();
    OnlyMenuBar = new wxMenuBar();
    FileMenu = new wxMenu();
    SelectImageMenuItem = new wxMenuItem(FileMenu, ID_SelectImageMenu, _("SelectImage\tCtrl+H"), _("Select The Image"), wxITEM_NORMAL);
    FileMenu->Append(SelectImageMenuItem);
    QuitMenuItem = new wxMenuItem(FileMenu, ID_MenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    FileMenu->Append(QuitMenuItem);
    OnlyMenuBar->Append(FileMenu, _("&File"));
    HelpMenu = new wxMenu();
    AboutMenuItem = new wxMenuItem(HelpMenu, ID_MenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    HelpMenu->Append(AboutMenuItem);
    OnlyMenuBar->Append(HelpMenu, _("Help"));
    SetMenuBar(OnlyMenuBar);
    OnlyStatusBar = new wxStatusBar(this, ID_OnlyStatusBar, 0, _T("ID_OnlyStatusBar"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    OnlyStatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    OnlyStatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(OnlyStatusBar);
    ImageFolderDirDialog = new wxDirDialog(this, _("Select directory"), _("./res/images"), wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));

    Connect(ID_AnalyzeButton,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GraphSearchFrame::OnAnalyzeButtonClick);
    Connect(ID_SolveAutomaticButton,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GraphSearchFrame::OnSolveAutomaticButtonClick);
    Connect(ID_SelectImageMenu,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphSearchFrame::OnSelectImageMenuItemSelected);
    Connect(ID_MenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphSearchFrame::OnQuit);
    Connect(ID_MenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphSearchFrame::OnAbout);
    //*)

	FullImage = new wxStaticBitmap(FullImagePanel,-1,*FullImageBitmap);
	FullImageSBSizer->Add(FullImage);
    PhotoCanvas = new DisplayCanvas(DisplayPanel);
    PhotoCanvas->SetImagePath(ImagePath+DefaultFolder);
    PhotoSBSizer->Add(PhotoCanvas,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,5);
}

GraphSearchFrame::~GraphSearchFrame()
{
    //(*Destroy(GraphSearchFrame)
    //*)
}

void GraphSearchFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GraphSearchFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void GraphSearchFrame::ScaleImage(wxImage& Image,int Width,int Height)
{
	Image.Scale(Width,Height);
}

void GraphSearchFrame::OnSelectImageMenuItemSelected(wxCommandEvent& event)
{
	ImageFolderDirDialog->ShowModal();
	wxString SelectedImagePath = ImageFolderDirDialog->GetPath();
	//wxMessageBox(ImagePath,wxT("Folder Selected"));
	/*Change playing picture*/
	PhotoCanvas->SetImagePath(string(SelectedImagePath.mb_str()));
	PhotoCanvas->LoadAllImages();

	/*Changed playing picture*/

	/*Now change the full picture*/
	wxImage SelectedImage(SelectedImagePath+_("/Full.png"));
	wxImage ScaledSelected = SelectedImage.Scale(ScaledImageWidth,ScaledImageHeight);
	wxBitmap  SelectedFullImage(ScaledSelected);
    FullImage->SetBitmap(SelectedFullImage);

	/*Full Image changed*/
	/* Repaint canvas*/
	wxPaintEvent Dummy;
	PhotoCanvas->OnPaint(Dummy);
	/*Canvas repainted*/
}

void GraphSearchFrame::OnAnalyzeButtonClick(wxCommandEvent& event)
{
	PhotoCanvas->Analyze();
}

void GraphSearchFrame::OnSolveAutomaticButtonClick(wxCommandEvent& event)
{
	PhotoCanvas->SolveAutomatic();
}
