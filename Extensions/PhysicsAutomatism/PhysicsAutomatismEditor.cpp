/**

Game Develop - Physic Automatism Extension
Copyright (c) 2010 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

*/

#if defined(GDE)
#include "PhysicsAutomatismEditor.h"

//(*InternalHeaders(PhysicsAutomatismEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "GDL/Game.h"
#include "PhysicsAutomatism.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"
#include "GDL/Scene.h"

//(*IdInit(PhysicsAutomatismEditor)
const long PhysicsAutomatismEditor::ID_STATICTEXT11 = wxNewId();
const long PhysicsAutomatismEditor::ID_RADIOBUTTON1 = wxNewId();
const long PhysicsAutomatismEditor::ID_RADIOBUTTON2 = wxNewId();
const long PhysicsAutomatismEditor::ID_CHECKBOX1 = wxNewId();
const long PhysicsAutomatismEditor::ID_CHECKBOX3 = wxNewId();
const long PhysicsAutomatismEditor::ID_CHECKBOX2 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT1 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL1 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT2 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL2 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT9 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL7 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT10 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL8 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT3 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL3 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT4 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL4 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT5 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT7 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL5 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT6 = wxNewId();
const long PhysicsAutomatismEditor::ID_TEXTCTRL6 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICTEXT8 = wxNewId();
const long PhysicsAutomatismEditor::ID_STATICLINE1 = wxNewId();
const long PhysicsAutomatismEditor::ID_BUTTON1 = wxNewId();
const long PhysicsAutomatismEditor::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PhysicsAutomatismEditor,wxDialog)
	//(*EventTable(PhysicsAutomatismEditor)
	//*)
END_EVENT_TABLE()

PhysicsAutomatismEditor::PhysicsAutomatismEditor(wxWindow* parent, Game & game_, Scene * scene_, PhysicsAutomatism & automatism_, MainEditorCommand & mainEditorCommand_ ) :
automatism(automatism_),
game(game_),
scene(scene_),
mainEditorCommand(mainEditorCommand_)
{
	//(*Initialize(PhysicsAutomatismEditor)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer6;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;

	Create(parent, wxID_ANY, _("Editer l\'automatisme"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Param�tres initiaux"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Forme du masque de collision :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer5->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	rectCheck = new wxRadioButton(this, ID_RADIOBUTTON1, _("Rectangle"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	rectCheck->SetValue(true);
	FlexGridSizer5->Add(rectCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	circleCheck = new wxRadioButton(this, ID_RADIOBUTTON2, _("Cercle"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	FlexGridSizer5->Add(circleCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer11 = new wxFlexGridSizer(0, 3, 0, 0);
	staticCheck = new wxCheckBox(this, ID_CHECKBOX1, _("Objet statique"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	staticCheck->SetValue(false);
	FlexGridSizer11->Add(staticCheck, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	fixedRotationCheck = new wxCheckBox(this, ID_CHECKBOX3, _("Empecher la rotation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	fixedRotationCheck->SetValue(false);
	FlexGridSizer11->Add(fixedRotationCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	bulletCheck = new wxCheckBox(this, ID_CHECKBOX2, _("Assimilable � un projectile ( meilleure gestion de la collision, mais plus lent )"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	bulletCheck->SetValue(false);
	FlexGridSizer2->Add(bulletCheck, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer7->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Densit� de masse :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer7->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	massDensityEdit = new wxTextCtrl(this, ID_TEXTCTRL1, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer7->Add(massDensityEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer8 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer8->AddGrowableCol(1);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Friction :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer8->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	frictionEdit = new wxTextCtrl(this, ID_TEXTCTRL2, _("0.8"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer8->Add(frictionEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer9 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer9->AddGrowableCol(1);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Amortissement lin�aire :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer9->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	linearDampingEdit = new wxTextCtrl(this, ID_TEXTCTRL7, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	FlexGridSizer9->Add(linearDampingEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer10 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer10->AddGrowableCol(1);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Amortissement angulaire :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer10->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	angularDampingEdit = new wxTextCtrl(this, ID_TEXTCTRL8, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	FlexGridSizer10->Add(angularDampingEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Param�tres globaux du moteur physique"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Coordonn�es du vecteur de gravit� :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	gravityXEdit = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer1->Add(gravityXEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _(";"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer1->Add(StaticText4, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	gravityYEdit = new wxTextCtrl(this, ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer1->Add(gravityYEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Echelle de taille de la repr�sentation :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 5, 0, 0);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("1m ="), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer6->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	scaleXEdit = new wxTextCtrl(this, ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer6->Add(scaleXEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("en X;"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer6->Add(StaticText6, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	scaleYEdit = new wxTextCtrl(this, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	FlexGridSizer6->Add(scaleYEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("en Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer6->Add(StaticText8, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cancelBt = new wxButton(this, ID_BUTTON2, _("Annuler"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(cancelBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PhysicsAutomatismEditor::OnokBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PhysicsAutomatismEditor::OncancelBtClick);
	//*)

    //Setup object datas
	if ( automatism.shapeType == PhysicsAutomatism::Circle )
	{
	    rectCheck->SetValue(false);
	    circleCheck->SetValue(true);
	}
	else
	{
	    rectCheck->SetValue(true);
	    circleCheck->SetValue(false);
	}
	staticCheck->SetValue(!automatism.dynamic);
	fixedRotationCheck->SetValue(automatism.fixedRotation);
	massDensityEdit->SetValue(ToString(automatism.massDensity));
	bulletCheck->SetValue(automatism.isBullet);
	frictionEdit->SetValue(ToString(automatism.averageFriction));
	linearDampingEdit->SetValue(ToString(automatism.linearDamping));
	angularDampingEdit->SetValue(ToString(automatism.angularDamping));

    //Setup shared datas
	if ( !scene || scene->automatismsInitialSharedDatas.find(automatism.GetAutomatismId()) == scene->automatismsInitialSharedDatas.end())
	{
	    wxLogError(_("Impossible d'acc�der aux donn�es partag�es."));
	    return;
	}

	sharedDatas = boost::dynamic_pointer_cast<ScenePhysicsDatas>(scene->automatismsInitialSharedDatas[automatism.GetAutomatismId()]);

    if ( sharedDatas == boost::shared_ptr<ScenePhysicsDatas>() )
    {
	    wxLogError(_("Impossible d'acc�der aux donn�es partag�es : Donn�es de mauvais type"));
	    return;
    }

	gravityXEdit->SetValue(ToString(sharedDatas->gravityX));
	gravityYEdit->SetValue(ToString(sharedDatas->gravityY));
	scaleXEdit->SetValue(ToString(sharedDatas->scaleX));
	scaleYEdit->SetValue(ToString(sharedDatas->scaleY));
}

PhysicsAutomatismEditor::~PhysicsAutomatismEditor()
{
	//(*Destroy(PhysicsAutomatismEditor)
	//*)
}


void PhysicsAutomatismEditor::OncancelBtClick(wxCommandEvent& event)
{
    EndModal(0);
}

void PhysicsAutomatismEditor::OnokBtClick(wxCommandEvent& event)
{
    if ( circleCheck->GetValue() )
        automatism.shapeType = PhysicsAutomatism::Circle;
    else
        automatism.shapeType = PhysicsAutomatism::Box;

    automatism.dynamic = !staticCheck->GetValue();
    automatism.fixedRotation = fixedRotationCheck->GetValue();
    automatism.isBullet = bulletCheck->GetValue();
    automatism.massDensity = ToFloat(massDensityEdit->GetValue().mb_str());
    automatism.averageFriction = ToFloat(frictionEdit->GetValue().mb_str());
    automatism.linearDamping = ToFloat(linearDampingEdit->GetValue().mb_str());
    automatism.angularDamping = ToFloat(angularDampingEdit->GetValue().mb_str());

    sharedDatas->gravityX = ToFloat(gravityXEdit->GetValue().mb_str());
    sharedDatas->gravityY = ToFloat(gravityYEdit->GetValue().mb_str());
    sharedDatas->scaleX = ToFloat(scaleXEdit->GetValue().mb_str());
    sharedDatas->scaleY = ToFloat(scaleYEdit->GetValue().mb_str());

    EndModal(1);
}
#endif