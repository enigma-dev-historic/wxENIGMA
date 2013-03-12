/**
* @file CodeEditor.h
* @brief Header file of the custom code editor.
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

#ifndef CODEEDITOR_H_INCLUDED
#define CODEEDITOR_H_INCLUDED

class StyledTextCtrl;

#include "ENIGMA_IDEMain.h"
#include <wx/stc/stc.h>

enum
{
    MARGIN_LINE_NUMBERS,
    MARGIN_LINE_BREAKS,
    MARGIN_LINE_EDITS,
    MARGIN_FOLD
};

class StyledTextCtrl : public wxStyledTextCtrl
{
    public:
    ENIGMA_IDEFrame* mainFrame;

    wxString* functionWords;
    wxString* variableWords;
    wxString* autoCompWords;

    StyledTextCtrl(ENIGMA_IDEFrame* frame, const long id = wxID_ANY);
    virtual ~StyledTextCtrl();

    void StyleEDL();
    void StyleCPP();
    void StyleXML();
    void StyleHTML();
    void Restyle();

    private:

    void OnAutoComplete(wxStyledTextEvent& event);
    void OnChange(wxStyledTextEvent& event);
    void OnMarginClick(wxStyledTextEvent& event);
};


#endif // CODEEDITOR_H_INCLUDED
