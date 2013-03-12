#include "AboutFrame.h"

//(*InternalHeaders(AboutFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(AboutFrame)
const long AboutFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AboutFrame,wxFrame)
	//(*EventTable(AboutFrame)
	//*)
END_EVENT_TABLE()

AboutFrame::AboutFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AboutFrame)
	Create(parent, wxID_ANY, _("About..."), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxTRANSPARENT_WINDOW, _T("wxID_ANY"));
	SetClientSize(wxSize(422,295));
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/owner/Desktop/wxENIGMA/Resources/EDE_about_banner.png"))), wxPoint(8,-16), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	//*)
}

AboutFrame::~AboutFrame()
{
	//(*Destroy(AboutFrame)
	//*)
}
