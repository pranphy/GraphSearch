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
#include <wx/bitmap.h>
#include <wx/image.h>
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
const long GraphSearchFrame::ID_STATICBITMAP1 = wxNewId();
const long GraphSearchFrame::ID_PANEL1 = wxNewId();
const long GraphSearchFrame::ID_BUTTONss = wxNewId();
const long GraphSearchFrame::ID_BUTTONTWO = wxNewId();
const long GraphSearchFrame::ID_DisplayPanel = wxNewId();
const long GraphSearchFrame::idMenuQuit = wxNewId();
const long GraphSearchFrame::idMenuAbout = wxNewId();
const long GraphSearchFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GraphSearchFrame,wxFrame)
    //(*EventTable(GraphSearchFrame)
    //*)
END_EVENT_TABLE()

GraphSearchFrame::GraphSearchFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GraphSearchFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* PhotoSBSizer;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(352,327));
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(101,185), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMinSize(wxSize(150,0));
    FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Label"));
    FlexGridSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Label"));
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/pranphy/Pictures/8.jpg"))), wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticBoxSizer3->Add(StaticBitmap1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Panel1);
    FlexGridSizer2->SetSizeHints(Panel1);
    AuiManager1->AddPane(Panel1, wxAuiPaneInfo().Name(_T("PaneName")).DefaultPane().Caption(_("Pane caption")).CaptionVisible().Left().MinSize(wxSize(150,0)));
    DisplayPanel = new wxPanel(this, ID_DisplayPanel, wxPoint(153,159), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_DisplayPanel"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableRow(0,8);
    FlexGridSizer1->AddGrowableRow(1,1);
    PhotoSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, DisplayPanel, _("Move Pieces"));
    FlexGridSizer1->Add(PhotoSBSizer, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, DisplayPanel, _("Label"));
    FirstButton = new wxButton(DisplayPanel, ID_BUTTONss, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONss"));
    StaticBoxSizer2->Add(FirstButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SecondButton = new wxButton(DisplayPanel, ID_BUTTONTWO, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONTWO"));
    StaticBoxSizer2->Add(SecondButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DisplayPanel->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(DisplayPanel);
    FlexGridSizer1->SetSizeHints(DisplayPanel);
    AuiManager1->AddPane(DisplayPanel, wxAuiPaneInfo().Name(_T("PaneName")).CenterPane().Caption(_("Pane caption")).Row(1).Position(-1));
    AuiManager1->Update();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphSearchFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GraphSearchFrame::OnAbout);
    //*)
    PhotoCanvas = new DisplayCanvas(DisplayPanel);
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
