 /**
* @file CrossThread.h
* @brief Header declaring a structure to facilitate cross-thread code execution
*
* Use the CrossThread class to specify code to be run under a separate thread.
*
* @section License
*
* Copyright (C) 2013 Josh Ventura, Robert B. Colton
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

#include "CrossThread.h"

wxDEFINE_EVENT(CROSS_THREAD_CODE, CT_Event);

CT_Event::CT_Event(CrossThread *c): wxCommandEvent(CROSS_THREAD_CODE), ctc(c), refc(new int(1)) {}
CT_Event::CT_Event(const CT_Event &copy): wxCommandEvent(CROSS_THREAD_CODE) {
    ++*copy.refc;
    refc = copy.refc;
    ctc = copy.ctc;
}
wxEvent *CT_Event::Clone() const {
    return new CT_Event(*this);
}
CT_Event::~CT_Event() {
    if (!--*refc) {
        delete ctc;
        delete refc;
    }
}
