/***************************************************************
 * Name:      ENIGMA_IDEApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Robert B Colton (robertbcolton@hotmail.com)
 * Created:   2013-01-28
 * Copyright: Robert B Colton (enigma-dev.org)
 * License:
 **************************************************************/

#include "ENIGMA_IDEApp.h"
#include <wx/fs_inet.h>

#include "ENIGMA_IDEMain.h"
#include <wx/image.h>
#include <stdio.h>

#include "ENIGMAlink.h"
#include "LoadLibrary.h"


IMPLEMENT_APP(ENIGMA_IDEApp);

bool ENIGMA_IDEApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        wxFileSystem::AddHandler(new wxInternetFSHandler);
    	ENIGMA_IDEFrame* Frame = new ENIGMA_IDEFrame(0);
        //Frame->SetIcon(wxIcon(_T("Resources/enigmaicon.ico")));
        //Frame->SetIcon(wxICON(aaaa));
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    return wxsOK;
}
