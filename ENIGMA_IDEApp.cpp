/***************************************************************
 * Name:      ENIGMA_IDEApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Robert B Colton (robertbcolton@hotmail.com)
 * Created:   2013-01-28
 * Copyright: Robert B Colton (enigma-dev.org)
 * License:
 **************************************************************/

#include "ENIGMA_IDEApp.h"

//(*AppHeaders
#include "ENIGMA_IDEMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ENIGMA_IDEApp);

bool ENIGMA_IDEApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ENIGMA_IDEFrame* Frame = new ENIGMA_IDEFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
