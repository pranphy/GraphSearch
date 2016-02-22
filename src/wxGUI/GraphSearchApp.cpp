/***************************************************************
 * Name:      GraphSearchApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Prakash (pranphy@gmail.com)
 * Created:   2015-08-30
 * Copyright: Prakash (pranphy.com)
 * License:
 **************************************************************/

#include "wxGUI/GraphSearchApp.h"

//(*AppHeaders
#include "wxGUI/GraphSearchMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GraphSearchApp);

bool GraphSearchApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    GraphSearchFrame* Frame = new GraphSearchFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
