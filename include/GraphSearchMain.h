/***************************************************************
 * Name:      GraphSearchMain.h
 * Purpose:   Defines Application Frame
 * Author:    Prakash (pranphy@gmail.com)
 * Created:   2015-08-30
 * Copyright: Prakash (pranphy.com)
 * License:
 **************************************************************/

#ifndef GRAPHSEARCHMAIN_H
#define GRAPHSEARCHMAIN_H

//(*Headers(GraphSearchFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/dirdlg.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/aui/aui.h>
#include <wx/textctrl.h>
//*)

#include "DisplayCanvas.h"


#include <sstream>
#include <string>
using namespace std;

class GraphSearchFrame: public wxFrame
{
    public:

        GraphSearchFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GraphSearchFrame();

    private:

        //(*Handlers(GraphSearchFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSelectImageMenuItemSelected(wxCommandEvent& event);
        void OnAnalyzeButtonClick(wxCommandEvent& event);
        void OnSolveAutomaticButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(GraphSearchFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_FullImagePanel;
        static const long ID_AnalyzeButton;
        static const long ID_SolveAutomaticButton;
        static const long ID_DisplayPanel;
        static const long ID_SelectImageMenu;
        static const long ID_MenuQuit;
        static const long ID_MenuAbout;
        static const long ID_OnlyStatusBar;
        //*)
        static const long ID_FullImageSBitmap;
		static const long ID_FullImageBitmap;

		static const int ScaledImageWidth,ScaledImageHeight;

        //(*Declarations(GraphSearchFrame)
        wxPanel* DisplayPanel;
        wxMenuItem* SelectImageMenuItem;
        wxStaticText* StaticText1;
        wxButton* SolveAutomaticButton;
        wxAuiManager* OutermostAuiManager;
        wxPanel* FullImagePanel;
        wxTextCtrl* TextCtrl1;
        wxStatusBar* OnlyStatusBar;
        wxButton* AnalyzeButton;
        wxDirDialog* ImageFolderDirDialog;
        //*)
		wxBitmap* FullImageBitmap;
		wxStaticBitmap* FullImage;
        DisplayCanvas* PhotoCanvas;

        void ScaleImage(wxImage&,int,int);

        string ImagePath;
        string DefaultFolder;


        DECLARE_EVENT_TABLE()
};

#endif // GRAPHSEARCHMAIN_H
