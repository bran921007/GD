/**

GDevelop - Top-down movement Automatism Extension
Copyright (c) 2010-2015 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/
#if defined(GD_IDE_ONLY)
#include "GDCore/PlatformDefinition/PlatformExtension.h"
#include "GDCore/Tools/Localization.h"
#include "GDCore/Tools/Version.h"

#include <iostream>

void DeclareTopDownMovementAutomatismExtension(gd::PlatformExtension & extension);

/**
 * \brief This class declares information about the JS extension.
 */
class TopDownMovementAutomatismJsExtension : public gd::PlatformExtension
{
public:

    /**
     * \brief Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    TopDownMovementAutomatismJsExtension()
    {
        DeclareTopDownMovementAutomatismExtension(*this);

        GetAutomatismMetadata("TopDownMovementAutomatism::TopDownMovementAutomatism")
            .SetIncludeFile("TopDownMovementAutomatism/topdownmovementruntimeautomatism.js");

        std::map<std::string, gd::InstructionMetadata > & autActions = GetAllActionsForAutomatism("TopDownMovementAutomatism::TopDownMovementAutomatism");
        std::map<std::string, gd::InstructionMetadata > & autConditions = GetAllConditionsForAutomatism("TopDownMovementAutomatism::TopDownMovementAutomatism");
        std::map<std::string, gd::ExpressionMetadata > & autExpressions = GetAllExpressionsForAutomatism("TopDownMovementAutomatism::TopDownMovementAutomatism");

        autConditions["TopDownMovementAutomatism::IsMoving"].codeExtraInformation.SetFunctionName("isMoving");

        autActions["TopDownMovementAutomatism::Acceleration"].codeExtraInformation.SetFunctionName("setAcceleration").SetAssociatedGetter("getAcceleration");
        autConditions["TopDownMovementAutomatism::Acceleration"].codeExtraInformation.SetFunctionName("getAcceleration");
        autActions["TopDownMovementAutomatism::Deceleration"].codeExtraInformation.SetFunctionName("setDeceleration").SetAssociatedGetter("getDeceleration");
        autConditions["TopDownMovementAutomatism::Deceleration"].codeExtraInformation.SetFunctionName("getDeceleration");
        autActions["TopDownMovementAutomatism::MaxSpeed"].codeExtraInformation.SetFunctionName("setMaxSpeed").SetAssociatedGetter("getMaxSpeed");
        autConditions["TopDownMovementAutomatism::MaxSpeed"].codeExtraInformation.SetFunctionName("getMaxSpeed");
        autConditions["TopDownMovementAutomatism::Speed"].codeExtraInformation.SetFunctionName("getSpeed");
        autActions["TopDownMovementAutomatism::AngularMaxSpeed"].codeExtraInformation.SetFunctionName("setAngularMaxSpeed").SetAssociatedGetter("getAngularMaxSpeed");
        autConditions["TopDownMovementAutomatism::AngularMaxSpeed"].codeExtraInformation.SetFunctionName("getAngularMaxSpeed");
        autActions["TopDownMovementAutomatism::AngleOffset"].codeExtraInformation.SetFunctionName("setAngleOffset").SetAssociatedGetter("getAngleOffset");
        autConditions["TopDownMovementAutomatism::AngleOffset"].codeExtraInformation.SetFunctionName("getAngleOffset");

        autActions["TopDownMovementAutomatism::AllowDiagonals"].codeExtraInformation.SetFunctionName("allowDiagonals");
        autConditions["TopDownMovementAutomatism::DiagonalsAllowed"].codeExtraInformation.SetFunctionName("diagonalsAllowed");
        autActions["TopDownMovementAutomatism::RotateObject"].codeExtraInformation.SetFunctionName("setRotateObject");
        autConditions["TopDownMovementAutomatism::ObjectRotated"].codeExtraInformation.SetFunctionName("isObjectRotated");

        autActions["TopDownMovementAutomatism::SimulateLeftKey"].codeExtraInformation.SetFunctionName("simulateLeftKey");
        autActions["TopDownMovementAutomatism::SimulateRightKey"].codeExtraInformation.SetFunctionName("simulateRightKey");
        autActions["TopDownMovementAutomatism::SimulateUpKey"].codeExtraInformation.SetFunctionName("simulateUpKey");
        autActions["TopDownMovementAutomatism::SimulateDownKey"].codeExtraInformation.SetFunctionName("simulateDownKey");
        autActions["TopDownMovementAutomatism::SimulateControl"].codeExtraInformation.SetFunctionName("simulateControl");
        autActions["TopDownMovementAutomatism::IgnoreDefaultControls"].codeExtraInformation.SetFunctionName("ignoreDefaultControls");

        autExpressions["Acceleration"].codeExtraInformation.SetFunctionName("getAcceleration");
        autExpressions["Deceleration"].codeExtraInformation.SetFunctionName("getDeceleration");
        autExpressions["MaxSpeed"].codeExtraInformation.SetFunctionName("getMaxSpeed");
        autExpressions["Speed"].codeExtraInformation.SetFunctionName("getSpeed");
        autExpressions["AngularMaxSpeed"].codeExtraInformation.SetFunctionName("getAngularMaxSpeed");
        autExpressions["AngleOffset"].codeExtraInformation.SetFunctionName("getAngleOffset");

        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
};

#if defined(EMSCRIPTEN)
extern "C" gd::PlatformExtension * CreateGDJSTopDownMovementAutomatismExtension() {
    return new TopDownMovementAutomatismJsExtension;
}
#else
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" gd::PlatformExtension * GD_EXTENSION_API CreateGDJSExtension() {
    return new TopDownMovementAutomatismJsExtension;
}
#endif
#endif
