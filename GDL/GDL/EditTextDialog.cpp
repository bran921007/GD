#if defined(GDE)
#include "GDL/EditTextDialog.h"

//(*InternalHeaders(EditTextDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "GDL/EditExpression.h"
#include "GDL/ExtensionBase.h"
#include "GDL/ChooseObject.h"
#include "GDL/ChooseLayer.h"
#include "GDL/ChooseObjectExpression.h"
#include "GDL/ChooseVariableDialog.h"
#include <wx/textdlg.h>
#include "GDL/Game.h"
#include "GDL/Scene.h"
#include "GDL/Chercher.h"
#include "GDL/CommonTools.h"
#include "GDL/ExtensionsManager.h"
#include "GDL/gdTreeItemStringData.h"

//(*IdInit(EditTextDialog)
const long EditTextDialog::ID_TEXTCTRL1 = wxNewId();
const long EditTextDialog::ID_STATICTEXT5 = wxNewId();
const long EditTextDialog::ID_BUTTON2 = wxNewId();
const long EditTextDialog::ID_BUTTON1 = wxNewId();
const long EditTextDialog::ID_STATICTEXT1 = wxNewId();
const long EditTextDialog::ID_TREECTRL1 = wxNewId();
const long EditTextDialog::ID_BUTTON10 = wxNewId();
const long EditTextDialog::ID_STATICTEXT4 = wxNewId();
const long EditTextDialog::ID_TREECTRL2 = wxNewId();
const long EditTextDialog::ID_BUTTON7 = wxNewId();
const long EditTextDialog::ID_STATICTEXT2 = wxNewId();
const long EditTextDialog::ID_BUTTON3 = wxNewId();
const long EditTextDialog::ID_STATICLINE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EditTextDialog,wxDialog)
	//(*EventTable(EditTextDialog)
	//*)
END_EVENT_TABLE()

EditTextDialog::EditTextDialog(wxWindow* parent, string texte, Game & game_, Scene & scene_, bool canSelectGroup_, const vector < string > & mainObjectsName_) :
game(game_),
scene(scene_),
canSelectGroup(canSelectGroup_),
mainObjectsName(mainObjectsName_)
{
	//(*Initialize(EditTextDialog)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;
	
	Create(parent, wxID_ANY, _("Editer le texte"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	wxIcon FrameIcon;
	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/texteicon.png"))));
	SetIcon(FrameIcon);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer9 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer9->AddGrowableCol(0);
	FlexGridSizer9->AddGrowableRow(0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableRow(0);
	TexteEdit = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(478,110), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(TexteEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	errorTxt = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	errorTxt->SetForegroundColour(wxColour(120,0,0));
	FlexGridSizer3->Add(errorTxt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer8->AddGrowableCol(0);
	OkBt = new wxButton(this, ID_BUTTON2, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer8->Add(OkBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	AnnulerBt = new wxButton(this, ID_BUTTON1, _("Annuler"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer8->Add(AnnulerBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(FlexGridSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Editer le texte"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	FlexGridSizer7 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer7->AddGrowableCol(0);
	FlexGridSizer7->AddGrowableRow(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Propri�t�s des objets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer7->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ObjList = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(195,177), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	FlexGridSizer7->Add(ObjList, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AddPropBt = new wxButton(this, ID_BUTTON10, _("Ajouter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer7->Add(AddPropBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer10->AddGrowableCol(0);
	FlexGridSizer10->AddGrowableRow(1);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Valeurs sp�ciales"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer10->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ValList = new wxTreeCtrl(this, ID_TREECTRL2, wxDefaultPosition, wxSize(195,177), wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL2"));
	FlexGridSizer10->Add(ValList, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AddFunctionBt = new wxButton(this, ID_BUTTON7, _("Ajouter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer10->Add(AddFunctionBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer11 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Expression num�rique :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer11->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	InsertBt = new wxButton(this, ID_BUTTON3, _("Ins�rer une expression num�rique"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	InsertBt->SetToolTip(_("Permet d\'ins�rer un calcul, ou la valeur d\'une variable"));
	FlexGridSizer11->Add(InsertBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	FlexGridSizer2->Add(StaticLine2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();
	
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EditTextDialog::OnTexteEditText);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditTextDialog::OnOkBtClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditTextDialog::OnAnnulerBtClick);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&EditTextDialog::OnObjListItemActivated);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&EditTextDialog::OnObjListSelectionChanged);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditTextDialog::OnAddPropBtClick);
	Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&EditTextDialog::OnTreeCtrl1ItemActivated);
	Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&EditTextDialog::OnTreeCtrl1SelectionChanged);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditTextDialog::OnAddFunctionBtClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EditTextDialog::OnInsertBtClick);
	//*)

    //Prepare image lists
    imageListObj = new wxImageList( 16, 16 );
    imageListObj->Add(( wxBitmap( "res/actions/uneaction.png", wxBITMAP_TYPE_ANY ) ) );
    ObjList->AssignImageList( imageListObj );

    imageListVal = new wxImageList( 16, 16 );
    imageListVal->Add(( wxBitmap( "res/actions/uneaction.png", wxBITMAP_TYPE_ANY ) ) );
    ValList->AssignImageList( imageListVal );

    //Prepare lists
    ObjList->DeleteAllItems();
    ObjList->AddRoot( _( "Toutes les propriet�s" ), 0 );

    ValList->DeleteAllItems();
    ValList->AddRoot( _( "Toutes les valeurs sp�ciales" ), 0 );

    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();
    const vector < boost::shared_ptr<ExtensionBase> > extensions = extensionManager->GetExtensions();

    //Insert extension objects expressions
	for (unsigned int i = 0;i<extensions.size();++i)
	{
	    //Verify if that extension is enabled
	    if ( find(game.extensionsUsed.begin(),
                  game.extensionsUsed.end(),
                  extensions[i]->GetName()) == game.extensionsUsed.end() )
            continue;

	    vector<string> objectsTypes = extensions[i]->GetExtensionObjectsTypes();

        wxTreeItemId extensionItem = ObjList->GetRootItem();

	    for(unsigned int j = 0;j<objectsTypes.size();++j)
	    {
            wxTreeItemId objectTypeItem =   objectsTypes[j] == "" ?
                                            ObjList->AppendItem(extensionItem, _("Tous les objets"), 0) :
                                            ObjList->AppendItem(extensionItem, _("Objet") + wxString(" ") + extensions[i]->GetExtensionObjectName(objectsTypes[j]),0) ;

            //Add each object expression
            std::map<string, StrExpressionInfos > allObjExpr = extensions[i]->GetAllStrExpressionsForObject(objectsTypes[j]);
            for(std::map<string, StrExpressionInfos>::const_iterator it = allObjExpr.begin(); it != allObjExpr.end(); ++it)
            {
                if ( it->second.shown )
                {
                    //Search and/or add group item
                    wxTreeItemIdValue cookie;
                    wxTreeItemId groupItem = ObjList->GetFirstChild(objectTypeItem, cookie);
                    while ( groupItem.IsOk() && ObjList->GetItemText(groupItem) != it->second.group )
                    {
                        groupItem = ObjList->GetNextSibling(groupItem);
                    }
                    if ( !groupItem.IsOk() ) groupItem = ObjList->AppendItem(objectTypeItem, it->second.group, 0);

                    //Add expression item
                    int IDimage = 0;
                    if ( it->second.smallicon.IsOk() )
                    {
                        imageListObj->Add(it->second.smallicon);
                        IDimage = imageListObj->GetImageCount()-1;
                    }

                    gdTreeItemStringData * associatedData = new gdTreeItemStringData(it->first, objectsTypes[j]);
                    ObjList->AppendItem(groupItem, it->second.fullname, IDimage, -1, associatedData);
                }
            }
	    }

        //Add each expression
        extensionItem = ValList->GetRootItem();

        std::map<string, StrExpressionInfos > allExpr = extensions[i]->GetAllStrExpressions();
        for(std::map<string, StrExpressionInfos>::const_iterator it = allExpr.begin(); it != allExpr.end(); ++it)
        {
            if ( it->second.shown )
            {
                //Search and/or add group item
                wxTreeItemIdValue cookie;
                wxTreeItemId groupItem = ValList->GetFirstChild(extensionItem, cookie);
                while ( groupItem.IsOk() && ValList->GetItemText(groupItem) != it->second.group )
                {
                    groupItem = ValList->GetNextSibling(groupItem);
                }
                if ( !groupItem.IsOk() ) groupItem = ValList->AppendItem(extensionItem, it->second.group, 0);

                //Add expression item
                int IDimage = 0;
                if ( it->second.smallicon.IsOk() )
                {
                    imageListVal->Add(it->second.smallicon);
                    IDimage = imageListVal->GetImageCount()-1;
                }

                gdTreeItemStringData * associatedData = new gdTreeItemStringData(it->first);
                ValList->AppendItem(groupItem, it->second.fullname, IDimage, -1, associatedData);
            }
        }
	}

    ObjList->Expand(ObjList->GetRootItem());
    ValList->Expand(ValList->GetRootItem());

	TexteEdit->SetValue(texte);
}

EditTextDialog::~EditTextDialog()
{
	//(*Destroy(EditTextDialog)
	//*)
}


void EditTextDialog::OnAnnulerBtClick(wxCommandEvent& event)
{
    EndModal(0);
}

void EditTextDialog::OnOkBtClick(wxCommandEvent& event)
{
    returnedText = string(TexteEdit->GetValue().mb_str());

    GDExpression expressionTest(returnedText);
    if ( !expressionTest.PrepareForTextEvaluationOnly(game, scene) )
    {
        if ( wxMessageBox(_("L'expression est mal formul�e. �tes vous s�r de vouloir valider cette expression ?"), _("L'expression contient une ou plusieurs erreurs."), wxYES_NO | wxICON_EXCLAMATION, this) == wxNO )
            return;
    }

    EndModal(1);
}

/**
 * Show a dialog for completing a parameter
 */
string EditTextDialog::ShowParameterDialog(const ParameterInfo & parameterInfo, std::string objectNameAssociated)
{
    if ( parameterInfo.type == "expression" )
    {
        string param = static_cast<string> (wxGetTextFromUser(parameterInfo.description, _("Param�tre"), "0", this));
        return param;
    }
    else if ( parameterInfo.type == "object" )
    {
        ChooseObject Dialog(this, game, scene, true, parameterInfo.objectType);
        if ( Dialog.ShowModal() == 0 ) return "";

        return Dialog.objectChosen;
    }
    else if ( parameterInfo.type == "text" )
    {
        string param = static_cast<string> (wxGetTextFromUser(parameterInfo.description, _("Param�tre"), "\"\"", this));
        return param;
    }
    else if ( parameterInfo.type == "layer" )
    {
        ChooseLayer dialog(this, scene.initialLayers);
        if ( dialog.ShowModal() == 0 ) return "";

        return dialog.layerChosen;
    }
    else if ( parameterInfo.type == "scenevar" )
    {
        ChooseVariableDialog dialog(this, scene.variables);
        if ( dialog.ShowModal() == 1 )
        {
            scene.variables = dialog.variables;
            return dialog.selectedVariable;
        }

        return "";
    }
    else if ( parameterInfo.type == "globalvar" )
    {
        ChooseVariableDialog dialog(this, game.variables);
        if ( dialog.ShowModal() == 1 )
        {
            game.variables = dialog.variables;
            return dialog.selectedVariable;
        }

        return "";
    }
    else if ( parameterInfo.type == "objectvar" )
    {
        int IDsceneObject = Picker::PickOneObject( &scene.initialObjects, objectNameAssociated );
        int IDglobalObject = Picker::PickOneObject( &game.globalObjects, objectNameAssociated );

        ObjSPtr object = boost::shared_ptr<Object> ();

        if ( IDsceneObject != -1)
            object = scene.initialObjects[IDsceneObject];
        else if ( IDglobalObject != -1)
            object = game.globalObjects[IDglobalObject];
        else
            return "";

        ChooseVariableDialog dialog(this, object->variablesObjet);
        if ( dialog.ShowModal() == 1 )
        {
            object->variablesObjet = dialog.variables;
            return dialog.selectedVariable;
        }

        return "";
    }
    else if ( parameterInfo.type == "camera" )
    {
        string param = static_cast<string> (wxGetTextFromUser(parameterInfo.description, _("Num�ro de la cam�ra"), "0", this));
        return param;
    }

    return "";
}

/**
 * Insert a numeric expression
 */
void EditTextDialog::OnInsertBtClick(wxCommandEvent& event)
{
    EditExpression dialog(this, "", game, scene, true, mainObjectsName);
    dialog.ShowModal();

    TexteEdit->WriteText("ToString("+dialog.expression+")");
}

/**
 * Real time expression checking
 */
void EditTextDialog::OnTexteEditText(wxCommandEvent& event)
{
    string text = string(TexteEdit->GetValue().mb_str());

    TexteEdit->SetStyle(0, text.length()-1, wxColour(0,0,0) );

    GDExpression expressionTest(text);
    if ( !expressionTest.PrepareForTextEvaluationOnly(game, scene) )
    {
        errorTxt->SetLabel(expressionTest.GetFirstErrorDuringPreprocessingText());
        if ( expressionTest.GetFirstErrorDuringPreprocessingPosition() != string::npos )
            TexteEdit->SetStyle(expressionTest.GetFirstErrorDuringPreprocessingPosition(), expressionTest.GetFirstErrorDuringPreprocessingPosition()+1, wxColour(120,0,0) );
    }
    else
    {
        errorTxt->SetLabel("");
    }
}

void EditTextDialog::OnAddPropBtClick(wxCommandEvent& event)
{
    if ( !itemObj.IsOk() ) return;

    gdTreeItemStringData * associatedData = dynamic_cast<gdTreeItemStringData*>(ObjList->GetItemData(itemObj));
    if ( associatedData != NULL )
    {
        gdp::ExtensionsManager * extensionsManager = gdp::ExtensionsManager::getInstance();

        StrExpressionInfos infos = extensionsManager->GetObjectStrExpressionInfos(associatedData->GetSecondString(), associatedData->GetString());

        if ( infos.parameters.empty() ) return; //Not even a parameter for the object ?

        string object = ShowParameterDialog(infos.parameters[0]);

        string parametersStr;
        for (unsigned int i = 1;i<infos.parameters.size();++i)
        {
            if ( i != 1 ) parametersStr += ",";
            parametersStr += ShowParameterDialog(infos.parameters[i], object);
        }

        TexteEdit->WriteText(ReplaceSpacesByTildes(object)+"."+associatedData->GetString()+"("+parametersStr+")");
        return;
    }
}

void EditTextDialog::OnObjListItemActivated(wxTreeEvent& event)
{
    itemObj = event.GetItem();
    wxCommandEvent uselessEvent;
    OnAddPropBtClick(uselessEvent);
}

void EditTextDialog::OnObjListSelectionChanged(wxTreeEvent& event)
{
    itemObj = event.GetItem();
}

void EditTextDialog::OnAddFunctionBtClick(wxCommandEvent& event)
{
    if ( !itemVal.IsOk() ) return;

    gdTreeItemStringData * associatedData = dynamic_cast<gdTreeItemStringData*>(ValList->GetItemData(itemVal));
    if ( associatedData != NULL )
    {
        gdp::ExtensionsManager * extensionsManager = gdp::ExtensionsManager::getInstance();

        StrExpressionInfos infos = extensionsManager->GetStrExpressionInfos(associatedData->GetString());

        string parametersStr;
        for (unsigned int i = 0;i<infos.parameters.size();++i)
        {
            if ( i != 0 ) parametersStr += ",";
            parametersStr += ShowParameterDialog(infos.parameters[i]);
        }

        TexteEdit->WriteText(associatedData->GetString()+"("+parametersStr+")");
        return;
    }
}

void EditTextDialog::OnTreeCtrl1ItemActivated(wxTreeEvent& event)
{
    itemVal = event.GetItem();
    wxCommandEvent uselessEvent;
    OnAddFunctionBtClick(uselessEvent);
}

void EditTextDialog::OnTreeCtrl1SelectionChanged(wxTreeEvent& event)
{
    itemVal = event.GetItem();
}
#endif