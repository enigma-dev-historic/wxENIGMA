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

#ifndef _CROSS_THREAD__H
#define _CROSS_THREAD__H

#include <iostream>
#include <wx/event.h>
using namespace std;

/// Class defining a vtable for code to be called from another event
struct CrossThread {
  virtual void exec() = 0;
  virtual ~CrossThread() {}
};

/// Class defining a wxEvent containing a cross-thread event
class CT_Event: public wxCommandEvent {
  CrossThread *ctc;
  int *refc;
  public:
  /// Run the code attached to this event
  inline void fire() { ctc->exec(); }
  /// Construct with a pointer to a cross-thread event; this will be freed automatically
  CT_Event(CrossThread *c);
  /// Copy constructor, which wx is too fucking stupid to use
  CT_Event(const CT_Event &copy);
  /// CLone method, which wx thinks is better than a fucking copy constructor
  wxEvent *Clone() const;
  /// Destructor; frees given event if no one else is using it.
  ~CT_Event();
};

wxDECLARE_EVENT(CROSS_THREAD_CODE, CT_Event);

#endif
