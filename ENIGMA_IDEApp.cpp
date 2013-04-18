/**
* @file ENIGMA_IDEApp.cpp
* @brief Source file of the IDE application thread.
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
    	SetTopWindow(Frame);
    }
    return wxsOK;
}
