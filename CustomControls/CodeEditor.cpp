/**
* @file CodeEditor.cpp
* @brief Source file of the code editor that uses wxStyledTextCtrl/Scintilla Wrapper.
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

#include "CodeEditor.h"

StyledTextCtrl::StyledTextCtrl(ENIGMA_IDEFrame* frame, const long id)
: wxStyledTextCtrl(frame, id)
{
    mainFrame = frame;

    functionWords = &(frame->fncWords);
    variableWords = &(frame->varWords);
    autoCompWords = &(frame->acpWords);

    SetKeyWords(0, *functionWords);
    SetKeyWords(1, *variableWords);

    ClearRegisteredImages();
    RegisterImage(0, frame->ControlImages->GetBitmap(4));
    RegisterImage(1, frame->ControlImages->GetBitmap(5));

    Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(StyledTextCtrl::OnMarginClick), NULL, this);
    Connect(wxEVT_STC_CHARADDED, wxStyledTextEventHandler(StyledTextCtrl::OnAutoComplete), NULL, this);
    Connect(wxEVT_STC_CHANGE, wxStyledTextEventHandler(StyledTextCtrl::OnChange), NULL, this);
}

StyledTextCtrl::~StyledTextCtrl()
{

}

void StyledTextCtrl::OnAutoComplete(wxStyledTextEvent& event)
{

    if (!AutoCompActive())
    {
        AutoCompShow(1, *autoCompWords);
    }
    //AutoCompStops(functionKeywords);
}

void StyledTextCtrl::OnChange(wxStyledTextEvent& event)
{
//            int lineEdit = event.GetLinesAdded
            //MarkerAdd(0,0);
           // cout << lineEdit;
           // puts("test");
}

void StyledTextCtrl::OnMarginClick(wxStyledTextEvent& event)
{
    int lineClick = LineFromPosition(event.GetPosition());
    int levelClick = GetFoldLevel(lineClick);
    switch (event.GetMargin())
    {
        case MARGIN_FOLD:
            if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0)
            {
                ToggleFold(lineClick);
            }
            break;
        case MARGIN_LINE_BREAKS:
            if (MarkerGet(lineClick) == 0)
            {
                MarkerAdd(lineClick, 0);
            }
            else
            {
                MarkerDelete(lineClick, 0);
            }
            break;
        case MARGIN_LINE_EDITS:
            break;
        case MARGIN_LINE_NUMBERS:
            break;
        default:
            break;
    }
}
