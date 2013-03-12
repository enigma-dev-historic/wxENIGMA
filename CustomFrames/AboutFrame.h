#ifndef ABOUTFRAME_H
#define ABOUTFRAME_H

//(*Headers(AboutFrame)
#include <wx/statbmp.h>
#include <wx/frame.h>
//*)

class AboutFrame: public wxFrame
{
	public:

		AboutFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AboutFrame();

		//(*Declarations(AboutFrame)
		wxStaticBitmap* StaticBitmap1;
		//*)

	protected:

		//(*Identifiers(AboutFrame)
		static const long ID_STATICBITMAP1;
		//*)

	private:

		//(*Handlers(AboutFrame)

		//*)

		DECLARE_EVENT_TABLE()
};

#endif
