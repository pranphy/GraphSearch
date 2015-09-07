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
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/statbmp.h>
//*)

#include "DisplayCanvas.h"

class GraphSearchFrame: public wxFrame
{
    public:

        GraphSearchFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GraphSearchFrame();

    private:

        //(*Handlers(GraphSearchFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(GraphSearchFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_PANEL1;
        static const long ID_BUTTONss;
        static const long ID_BUTTONTWO;
        static const long ID_DisplayPanel;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GraphSearchFrame)
        wxPanel* DisplayPanel;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* FirstButton;
        wxButton* SecondButton;
        wxStaticBitmap* StaticBitmap1;
        wxAuiManager* AuiManager1;
        //*)

        DisplayCanvas* PhotoCanvas;

        DECLARE_EVENT_TABLE()
};

#endif // GRAPHSEARCHMAIN_H
