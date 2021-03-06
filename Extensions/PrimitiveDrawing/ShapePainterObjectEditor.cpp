/**

GDevelop - Primitive Drawing Extension
Copyright (c) 2008-2015 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#if defined(GD_IDE_ONLY)

#include "ShapePainterObjectEditor.h"

//(*InternalHeaders(ShapePainterObjectEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>

#include "GDCpp/Project.h"
#include "ShapePainterObject.h"
#include "GDCore/IDE/Dialogs/MainFrameWrapper.h"

//(*IdInit(ShapePainterObjectEditor)
const long ShapePainterObjectEditor::ID_STATICTEXT3 = wxNewId();
const long ShapePainterObjectEditor::ID_BUTTON1 = wxNewId();
const long ShapePainterObjectEditor::ID_STATICTEXT5 = wxNewId();
const long ShapePainterObjectEditor::ID_SPINCTRL3 = wxNewId();
const long ShapePainterObjectEditor::ID_STATICTEXT1 = wxNewId();
const long ShapePainterObjectEditor::ID_BUTTON3 = wxNewId();
const long ShapePainterObjectEditor::ID_STATICTEXT2 = wxNewId();
const long ShapePainterObjectEditor::ID_SPINCTRL2 = wxNewId();
const long ShapePainterObjectEditor::ID_STATICTEXT4 = wxNewId();
const long ShapePainterObjectEditor::ID_SPINCTRL1 = wxNewId();
const long ShapePainterObjectEditor::ID_RADIOBOX1 = wxNewId();
const long ShapePainterObjectEditor::ID_STATICLINE1 = wxNewId();
const long ShapePainterObjectEditor::ID_BUTTON2 = wxNewId();
const long ShapePainterObjectEditor::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ShapePainterObjectEditor,wxDialog)
	//(*EventTable(ShapePainterObjectEditor)
	//*)
END_EVENT_TABLE()

ShapePainterObjectEditor::ShapePainterObjectEditor( wxWindow* parent, gd::Project & game_, ShapePainterObject & object_ ) :
game(game_),
object(object_)
{
	//(*Initialize(ShapePainterObjectEditor)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer6;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Edition of the Shape Painter object"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Filling"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Color :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	fillColorBt = new wxButton(this, ID_BUTTON1, _("Choose the color"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(fillColorBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Opacity :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	fillOpacityEdit = new wxSpinCtrl(this, ID_SPINCTRL3, _T("255"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 255, _T("ID_SPINCTRL3"));
	fillOpacityEdit->SetValue(_T("255"));
	FlexGridSizer2->Add(fillOpacityEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer4->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Outline"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Color :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	outlineColorBt = new wxButton(this, ID_BUTTON3, _("Choose the color"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(outlineColorBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Opacity :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	outlineOpacityEdit = new wxSpinCtrl(this, ID_SPINCTRL2, _T("255"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 255, _T("ID_SPINCTRL2"));
	outlineOpacityEdit->SetValue(_T("255"));
	FlexGridSizer3->Add(outlineOpacityEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Size :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	outlineSizeEdit = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 1, _T("ID_SPINCTRL1"));
	outlineSizeEdit->SetValue(_T("1"));
	FlexGridSizer3->Add(outlineSizeEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer4->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer6->AddGrowableCol(0);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("Absolute"),
		_("Relative to the position of the Shape Painter object")
	};
	coordinatesRadio = new wxRadioBox(this, ID_RADIOBOX1, _("Drawing coordinates"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
	FlexGridSizer6->Add(coordinatesRadio, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	okBt = new wxButton(this, ID_BUTTON2, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer5->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cancelBt = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer5->Add(cancelBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShapePainterObjectEditor::OnfillColorBtClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShapePainterObjectEditor::OnoutlineColorBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShapePainterObjectEditor::OnokBtClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ShapePainterObjectEditor::OncancelBtClick);
	//*)

	fillOpacityEdit->SetValue(object.GetFillOpacity());
	fillColorBt->SetBackgroundColour(wxColour(object.GetFillColorR(), object.GetFillColorG(), object.GetFillColorB()));

	outlineSizeEdit->SetValue(object.GetOutlineSize());
	outlineOpacityEdit->SetValue(object.GetOutlineOpacity());
	outlineColorBt->SetBackgroundColour(wxColour(object.GetOutlineColorR(), object.GetOutlineColorG(), object.GetOutlineColorB()));

	if ( !object.AreCoordinatesAbsolute() )
        coordinatesRadio->SetSelection(1);
}

ShapePainterObjectEditor::~ShapePainterObjectEditor()
{
	//(*Destroy(ShapePainterObjectEditor)
	//*)
}

/**
 * Click on Ok : Update the object according to the editor.
 */
void ShapePainterObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetFillOpacity(fillOpacityEdit->GetValue());
    object.SetFillColor(static_cast<int>(fillColorBt->GetBackgroundColour().Red()),
                        static_cast<int>(fillColorBt->GetBackgroundColour().Green()),
                        static_cast<int>(fillColorBt->GetBackgroundColour().Blue()));

    object.SetOutlineOpacity(outlineOpacityEdit->GetValue());
    object.SetOutlineSize(outlineSizeEdit->GetValue());
    object.SetOutlineColor(static_cast<int>(outlineColorBt->GetBackgroundColour().Red()),
                        static_cast<int>(outlineColorBt->GetBackgroundColour().Green()),
                        static_cast<int>(outlineColorBt->GetBackgroundColour().Blue()));

    object.SetCoordinatesAbsolute();
    if ( coordinatesRadio->GetSelection() == 1 )
        object.SetCoordinatesRelative();

    EndModal(1);
}

void ShapePainterObjectEditor::OncancelBtClick(wxCommandEvent& event)
{
    EndModal(0);
}

void ShapePainterObjectEditor::OnfillColorBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, fillColorBt->GetBackgroundColour());
    if ( color.IsOk() )
    {
        fillColorBt->SetBackgroundColour(color);
    }
}

void ShapePainterObjectEditor::OnoutlineColorBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, outlineColorBt->GetBackgroundColour());
    if ( color.IsOk() )
    {
        outlineColorBt->SetBackgroundColour(color);
    }
}

#endif

