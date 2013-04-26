#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H

//(*Headers(FindAndReplace)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

class FindAndReplace: public wxPanel
{
	public:

		FindAndReplace(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~FindAndReplace();

		//(*Declarations(FindAndReplace)
		wxRadioButton* RadioButton1;
		wxStaticText* StaticText2;
		wxRadioButton* RadioButton2;
		wxButton* Button1;
		wxCheckBox* CheckBox3;
		wxCheckBox* CheckBox2;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxRadioButton* RadioButton3;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox4;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(FindAndReplace)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_RADIOBUTTON3;
		static const long ID_RADIOBUTTON2;
		static const long ID_RADIOBUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(FindAndReplace)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
