#include "GDL/BaseObjectExtension.h"
#include "GDL/ExtensionBase.h"
#include "GDL/Object.h"

BaseObjectExtension::BaseObjectExtension()
{
    DECLARE_THE_EXTENSION("BuiltinObject",
                          _("Objet de base"),
                          _("Objet de base integr� en standard"),
                          "Compil Games",
                          "Freeware")

    DeclareExtensionFirstPart();
    DeclareExtensionSecondPart();
}

void BaseObjectExtension::DeclareExtensionFirstPart()
{
    //Declaration of all objects available
    DECLARE_OBJECT("",
                   _("Objet de base"),
                   _("Objet de base"),
                   "res/objeticon24.png",
                   &CreateBaseObject,
                   &DestroyBaseObject,
                   "");

        DECLARE_OBJECT_CONDITION("PosX",
                       _("Tester la position X d'un objet"),
                       _("Teste si la position X de l'objet correspond au test effectu�."),
                       _("La position X de l'objet _PARAM0_ est _PARAM2_ � _PARAM1_"),
                       _("Position"),
                       "res/conditions/position24.png",
                       "res/conditions/position.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position X"), "", false)
            DECLARE_PARAMETER("relationalOperator", _("Signe du test"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("GetX").SetTypeManipulated("number");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_ACTION("MettreX",
                       _("Position X d'un objet"),
                       _("Change la position x d'un objet."),
                       _("Faire _PARAM2__PARAM1_ � la position X de l'objet _PARAM0_"),
                       _("Position"),
                       "res/actions/position24.png",
                       "res/actions/position.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Valeur"), "", false)
            DECLARE_PARAMETER("operator", _("Signe de la modification"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("SetX").SetTypeManipulated("number").SetAssociatedGetter("GetX");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_CONDITION("PosY",
                       _("Tester la position Y d'un objet"),
                       _("Teste si la position Y de l'objet correspond au test effectu�."),
                       _("La position Y de l'objet _PARAM0_ est _PARAM2_ � _PARAM1_"),
                       _("Position"),
                       "res/conditions/position24.png",
                       "res/conditions/position.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position Y"), "", false)
            DECLARE_PARAMETER("relationalOperator", _("Signe du test"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("GetY").SetTypeManipulated("number");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_ACTION("MettreY",
                       _("Position Y d'un objet"),
                       _("Change la position Y d'un objet."),
                       _("Faire _PARAM2__PARAM1_ � la position Y de l'objet _PARAM0_"),
                       _("Position"),
                       "res/actions/position24.png",
                       "res/actions/position.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Valeur"), "", false)
            DECLARE_PARAMETER("operator", _("Signe de la modification"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("SetY").SetTypeManipulated("number").SetAssociatedGetter("GetY");

        DECLARE_END_OBJECT_ACTION()

        /*DECLARE_OBJECT_ACTION("MettreXY",
                       _("Position d'un objet"),
                       _("Change la position d'un objet."),
                       _("Faire _PARAM2__PARAM1_;_PARAM4__PARAM3_ � la position de l'objet _PARAM0_"),
                       _("Position"),
                       "res/actions/position24.png",
                       "res/actions/position.png",
                       &Object::ActMettreXY);

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position X"), "", false)
            DECLARE_PARAMETER("signe", _("Signe de la modification"), "", false)
            DECLARE_PARAMETER("expression", _("Position Y"), "", false)
            DECLARE_PARAMETER("signe", _("Signe de la modification"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

        DECLARE_END_OBJECT_ACTION()*/

        DECLARE_OBJECT_ACTION("MettreAutourPos",
                       _("Mettre un objet autour d'une position"),
                       _("Positionne un objet autour d'une position, avec l'angle et la distance indiqu�e."),
                       _("Mettre _PARAM0_ autour de _PARAM1_;_PARAM2_ � _PARAM4_� et � _PARAM3_ pixels de distance"),
                       _("Position"),
                       "res/actions/positionAutour24.png",
                       "res/actions/positionAutour.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position X"), "", false)
            DECLARE_PARAMETER("expression", _("Position Y"), "", false)
            DECLARE_PARAMETER("expression", _("Distance"), "", false)
            DECLARE_PARAMETER("expression", _("Angle en degr�"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("PutAroundAPosition");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("AddForceXY",
                       _("Ajouter une force � un objet"),
                       _("Ajouter une force � un objet. L'objet bougera ensuite en fonction de\ntoutes les forces qui s'exercent sur lui. Cette action cr�� la force en utilisant des coordonn�es X et Y."),
                       _("Ajouter � _PARAM0_ une force de _PARAM1_ p/s en X et _PARAM2_ p/s en Y"),
                       _("D�placement"),
                       "res/actions/force24.png",
                       "res/actions/force.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("D�placement en X"), "", false)
            DECLARE_PARAMETER("expression", _("D�placement en Y"), "", false)
            DECLARE_PARAMETER("expression", _("Dissipation ( 0 par d�faut )"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("AddForce");

        DECLARE_END_OBJECT_ACTION()
        DECLARE_OBJECT_ACTION("AddForceAL",
                       _("Ajouter une force ( Par angle )"),
                       _("Ajouter une force � un objet. L'objet bougera ensuite en fonction de\ntoutes les forces qui s'exercent sur lui. Cette action cr�� la force en utilisant l'angle et la longueur indiqu�e."),
                       _("Ajouter � _PARAM0_ une force d'angle _PARAM1_� et de longueur _PARAM2_ pixels"),
                       _("D�placement"),
                       "res/actions/force24.png",
                       "res/actions/force.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Angle"), "", false)
            DECLARE_PARAMETER("expression", _("Longueur ( en pixels )"), "", false)
            DECLARE_PARAMETER("expression", _("Dissipation ( 0 par d�faut )"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("AddForceUsingPolarCoordinates");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("AddForceVersPos",
                       _("Ajouter une force dirig�e vers une position"),
                       _("Ajouter une force � un objet pour qu'il se dirige vers la position."),
                       _("Diriger _PARAM0_ vers _PARAM1_;_PARAM2_ avec une force de longueur _PARAM3_ pixels"),
                       _("D�placement"),
                       "res/actions/force24.png",
                       "res/actions/force.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position X"), "", false)
            DECLARE_PARAMETER("expression", _("Position Y"), "", false)
            DECLARE_PARAMETER("expression", _("Longueur ( en pixels )"), "", false)
            DECLARE_PARAMETER("expression", _("Dissipation ( 0 par d�faut )"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("AddForceTowardPosition");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("AddForceTournePos",
                       _("Ajouter une force pour tourner autour d'une position"),
                       _("Ajouter une force � un objet pour qu'il tourne autour d'une position.\nNotez que le d�placement n'est pas forc�ment pr�cis, notamment si la vitesse est �lev�e.\nPour positionner de fa�on parfaite un objet autour d'une position, utilisez les actions de la cat�gorie Position."),
                       _("Faire tourner _PARAM0_ autour de _PARAM1_;_PARAM2_ � _PARAM3_�/sec et � _PARAM4_ pixels de distance"),
                       _("D�placement"),
                       "res/actions/forceTourne24.png",
                       "res/actions/forceTourne.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Position X du point autour duquel tourner"), "", false)
            DECLARE_PARAMETER("expression", _("Position Y du point autour duquel tourner"), "", false)
            DECLARE_PARAMETER("expression", _("Vitesse ( en Degr�s par secondes )"), "", false)
            DECLARE_PARAMETER("expression", _("Distance ( en pixels )"), "", false)
            DECLARE_PARAMETER("expression", _("Dissipation ( 0 par d�faut )"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("AddForceToMoveAround");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("Arreter",
                       _("Arr�ter l'objet"),
                       _("Arr�te l'objet en supprimant toutes ses forces."),
                       _("Arr�ter l'objet _PARAM0_"),
                       _("D�placement"),
                       "res/actions/arreter24.png",
                       "res/actions/arreter.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("ClearForce");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("Delete",
                       _("Supprimer un objet"),
                       _("Supprime l'objet indiqu�."),
                       _("Supprimer l'objet _PARAM0_"),
                       _("Objets"),
                       "res/actions/delete24.png",
                       "res/actions/delete.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_CODEONLY_PARAMETER("inlineCode", "\"\"")

            instrInfo.cppCallingInformation.SetFunctionName("SetName");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("Duplicate",
                       _("Dupliquer un objet"),
                       _("Cr�e une copie d'un objet ( m�me position, m�me animation... )."),
                       _("Dupliquer l'objet _PARAM0_"),
                       _("Objets"),
                       "res/actions/duplicate24.png",
                       "res/actions/duplicate.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_CODEONLY_PARAMETER("currentScene", "")
            DECLARE_CODEONLY_PARAMETER("objectsOfParameter", "0")

            instrInfo.cppCallingInformation.SetFunctionName("Duplicate");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("ChangePlan",
                       _("Changer le plan d'un objet"),
                       _("Modifier le num�ro du plan d'un objet"),
                       _("Faire _PARAM2__PARAM1_ au plan de _PARAM0_"),
                       _("Plan"),
                       "res/actions/planicon24.png",
                       "res/actions/planicon.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Valeur"), "", false)
            DECLARE_PARAMETER("signe", _("Signe de la modification"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("SetZOrder");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("ChangeLayer",
                       _("Changer le calque sur lequel est un objet"),
                       _("Change le calque sur lequel est actuellement situ� l'objet."),
                       _("Mettre _PARAM0_ sur le calque _PARAM1_"),
                       _("Calques et cam�ras"),
                       "res/actions/layer24.png",
                       "res/actions/layer.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("layer", _("Mettre sur le calque ( calque de base si vide )"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("SetLayer").SetAssociatedGetter("GetLayer").SetTypeManipulated("string");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("ModVarObjet",
                       _("Modifier une variable d'un objet"),
                       _("Modifie la valeur d'une variable d'un objet."),
                       _("Faire _PARAM3__PARAM2_ � la variable _PARAM1_ de l'objet _PARAM0_"),
                       _("Variables"),
                       "res/actions/var24.png",
                       "res/actions/var.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
            DECLARE_PARAMETER("expression", _("Valeur"), "", false)
            DECLARE_PARAMETER("operator", _("Signe de la modification"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("variablesObjet.ObtainVariable").SetTypeManipulated("number");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("ModVarObjetTxt",
                       _("Modifier le texte d'une variable d'un objet"),
                       _("Modifie le texte d'une variable d'un objet."),
                       _("Faire _PARAM3__PARAM2_ au texte de la variable _PARAM1_ de _PARAM0_"),
                       _("Variables"),
                       "res/actions/var24.png",
                       "res/actions/var.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
            DECLARE_PARAMETER("string", _("Texte"), "", false)
            DECLARE_PARAMETER("operator", _("Signe de la modification"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("variablesObjet.ObtainVariable").SetTypeManipulated("string");

        DECLARE_END_OBJECT_ACTION()


        DECLARE_OBJECT_ACTION("Cache",
                       _("Cacher un objet ( rendre invisible )"),
                       _("Rend invisible l'objet indiqu�."),
                       _("Cacher l'objet _PARAM0_"),
                       _("Visibilit�"),
                       "res/actions/visibilite24.png",
                       "res/actions/visibilite.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("SetHidden");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_ACTION("Montre",
                       _("Montrer un objet ( rendre visible )"),
                       _("Rend visible l'objet indiqu� ( si il a �t� pr�cedemment rendu invisible )"),
                       _("Montrer l'objet _PARAM0_"),
                       _("Visibilit�"),
                       "res/actions/visibilite24.png",
                       "res/actions/visibilite.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_CODEONLY_PARAMETER("inlineCode", "false")

            instrInfo.cppCallingInformation.SetFunctionName("SetHidden");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_CONDITION("Plan",
                       _("Tester le plan d'un objet"),
                       _("Teste si le plan de l'objet correspond au test effectu�."),
                       _("Le plan de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                       _("Plan"),
                       "res/conditions/planicon.png",
                       "res/conditions/planicon.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Plan"), "", false)
            DECLARE_PARAMETER("signe", _("Signe du test"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("SetZOrder").SetAssociatedGetter("GetZOrder").SetTypeManipulated("number");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("Layer",
                       _("Tester le calque d'un objet"),
                       _("Teste si l'objet est sur le calque indiqu�."),
                       _("_PARAM0_ est sur le calque _PARAM1_"),
                       _("Calque"),
                       "res/conditions/layer24.png",
                       "res/conditions/layer.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("layer", _("Calque"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("GetLayer").SetTypeManipulated("string");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("Visible",
                       _("Visibilit� d'un objet"),
                       _("Teste si un objet est visible ( non masqu� )."),
                       _("L'objet _PARAM0_ est visible"),
                       _("Visibilit�"),
                       "res/conditions/visibilite24.png",
                       "res/conditions/visibilite.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("IsVisible");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("Invisible",
                       _("Invisibilit� d'un objet"),
                       _("Teste si un objet est invisible ( masqu� )."),
                       _("L'objet _PARAM0_ est invisible"),
                       _("Visibilit�"),
                       "res/conditions/visibilite24.png",
                       "res/conditions/visibilite.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("IsHidden");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("Arret",
                       _("L'objet est � l'arr�t"),
                       _("Teste si l'objet ne bouge pas."),
                       _("L'objet _PARAM0_ est � l'arr�t"),
                       _("D�placement"),
                       "res/conditions/arret24.png",
                       "res/conditions/arret.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("IsStopped");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("Vitesse",
                       _("Vitesse de l'objet"),
                       _("Teste si la vitesse globale de l'objet correspond au test effectu�."),
                       _("La vitesse de _PARAM0_ est _PARAM2_ � _PARAM1_"),
                       _("D�placement"),
                       "res/conditions/vitesse24.png",
                       "res/conditions/vitesse.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Vitesse"), "", false)
            DECLARE_PARAMETER("signe", _("Signe du test"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("TotalForceLength").SetTypeManipulated("number");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("AngleOfDisplacement",
                       _("Angle de d�placement"),
                       _("Teste l'angle de d�placement d'un objet"),
                       _("L'angle de d�placement de _PARAM0_ est de _PARAM1_ ( Tol�rance : _PARAM2_� )"),
                       _("D�placement"),
                       "res/conditions/vitesse24.png",
                       "res/conditions/vitesse.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("expression", _("Angle ( en degr�s )"), "", false)
            DECLARE_PARAMETER("expression", _("Tol�rance"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("TestAngleOfDisplacement");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("VarObjet",
                       _("Variable d'un objet"),
                       _("Teste si la valeur d'une variable d'un objet correspond au test effectu�."),
                       _("La variable _PARAM1_ de _PARAM0_ est _PARAM3_ � _PARAM2_"),
                       _("Variables"),
                       "res/conditions/var24.png",
                       "res/conditions/var.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
            DECLARE_PARAMETER("expression", _("Valeur � tester"), "", false)
            DECLARE_PARAMETER("relationalOperator", _("Signe du test"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("variablesObjet.ObtainVariable").SetTypeManipulated("number");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("VarObjetTxt",
                       _("Texte d'une variable d'un objet"),
                       _("Teste si le texte de la variable d'un objet correspond au test effectu�."),
                       _("Le texte de la variable _PARAM1_ de _PARAM0_ est _PARAM3_ � _PARAM2_"),
                       _("Variables"),
                       "res/conditions/var24.png",
                       "res/conditions/var.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
            DECLARE_PARAMETER("text", _("Texte � tester"), "", false)
            DECLARE_PARAMETER("relationalOperator", _("Signe du test"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("variablesObjet.ObtainVariable").SetTypeManipulated("string");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("VarObjetDef",
                       _("Variable d�finie"),
                       _("Teste si une variable d'un objet existe."),
                       _("La variable _PARAM1_ de _PARAM0_ est d�finie"),
                       _("Variables"),
                       "res/conditions/var24.png",
                       "res/conditions/var.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
            MAIN_OBJECTS_IN_PARAMETER(0)

            instrInfo.cppCallingInformation.SetFunctionName("variablesObjet.HasVariable");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_CONDITION("AutomatismActivated",
                       _("Automatisme activ�"),
                       _("Renvoi vrai si l'automatisme sp�cifi� est activ� pour l'objet."),
                       _("L'automatisme _PARAM1_ de _PARAM0_ est activ�"),
                       _("Automatismes"),
                       "res/automatism24.png",
                       "res/automatism16.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("automatism", _("Automatisme"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("AutomatismActivated");

        DECLARE_END_OBJECT_CONDITION()

        DECLARE_OBJECT_ACTION("ActivateAutomatism",
                       _("De/Activer un automatisme"),
                       _("D�s/active l'automatisme sp�cifi� pour l'objet."),
                       _("Activer l'automatisme _PARAM1_ de _PARAM0_ : _PARAM2_"),
                       _("Automatismes"),
                       "res/automatism24.png",
                       "res/automatism16.png");

            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("automatism", _("Automatisme"), "", false)
            DECLARE_PARAMETER("yesorno", _("Activer ?"), "", false)

            instrInfo.cppCallingInformation.SetFunctionName("ActivateAutomatism");

        DECLARE_END_OBJECT_ACTION()

        DECLARE_OBJECT_EXPRESSION("X", _("Position X"), _("Position X de l'objet"), _("Position"), "res/actions/position.png", "GetX")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("Y", _("Position Y"), _("Position Y de l'objet"), _("Position"), "res/actions/position.png", "GetY")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("ForceX", _("Force moyenne en X"), _("Force moyenne en X"), _("D�placement"), "res/actions/force.png", "TotaleForceX")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("ForceY", _("Force moyenne en Y"), _("Force moyenne en Y"), _("D�placement"), "res/actions/force.png", "TotaleForceY")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("ForceAngle", _("Angle moyen des forces"), _("Angle moyen des forces"), _("D�placement"), "res/actions/force.png", "TotaleForceAngle")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_HIDDEN_EXPRESSION("Angle", _("Angle moyen des forces"), _("Angle moyen des forces"), _("D�placement"), "res/actions/force.png", "TotaleForceAngle")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("ForceLength", _("Longueur moyenne des forces"), _("Longueur moyenne des forces"), _("D�placement"), "res/actions/force.png", "TotaleForceLength")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_HIDDEN_EXPRESSION("Longueur", _("Longueur moyenne des forces"), _("Longueur moyenne des forces"), _("D�placement"), "res/actions/force.png", "TotaleForceLength")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()


        DECLARE_OBJECT_EXPRESSION("Width", _("Largeur d'un objet"), _("Largeur d'un objet"), _("Taille"), "res/actions/scaleWidth.png", "GetWidth")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_HIDDEN_EXPRESSION("Largeur", _("Largeur d'un objet"), _("Largeur d'un objet"), _("Taille"), "res/actions/scaleWidth.png", "GetWidth")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("Height", _("Hauteur d'un objet"), _("Hauteur d'un objet"), _("Taille"), "res/actions/scaleHeight.png", "GetHeight")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_HIDDEN_EXPRESSION("Hauteur", _("Hauteur d'un objet"), _("Hauteur d'un objet"), _("Taille"), "res/actions/scaleHeight.png", "GetHeight")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("ZOrder", _("Plan d'un objet"), _("Plan d'un objet"), _("Visibilit�"), "res/actions/planicon.png", "GetZOrder")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_HIDDEN_EXPRESSION("Plan", _("Plan d'un objet"), _("Plan d'un objet"), _("Visibilit�"), "res/actions/planicon.png", "GetZOrder")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("Distance", _("Distance entre deux objets"), _("Distance entre deux objets"), _("Position"), "res/conditions/distance.png", "GetDistanceWithObject")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("SqDistance", _("Distance au carr� entre deux objets"), _("Distance au carr� entre deux objets"), _("Position"), "res/conditions/distance.png", "GetSqDistanceWithObject")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("object", _("Objet"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_EXPRESSION("Variable", _("Variable d'un objet"), _("Variable d'un objet"), _("Variables"), "res/actions/var.png", "variablesObjet.ObtainVariable")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
        DECLARE_END_OBJECT_EXPRESSION()

        DECLARE_OBJECT_STR_EXPRESSION("VariableString", _("Variable d'un objet"), _("Texte d'une variable d'un objet"), _("Variables"), "res/actions/var.png", "variablesObjet.ObtainVariable")
            DECLARE_PARAMETER("object", _("Objet"), "", false)
            DECLARE_PARAMETER("objectvar", _("Nom de la variable"), "", false)
        DECLARE_END_OBJECT_STR_EXPRESSION()

    DECLARE_END_OBJECT()
}
