/**
* @file ENIGMA_IDEApp.h
* @brief Header file of the main application thread.
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

#ifndef ENIGMA_IDEAPP_H
#define ENIGMA_IDEAPP_H

#include <wx/app.h>

class ENIGMA_IDEApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ENIGMA_IDEAPP_H
