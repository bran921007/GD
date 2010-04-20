#if defined(GDE)
#include "EventsRenderingHelper.h"
#include "GDL/Instruction.h"
#include "GDL/ExtensionsManager.h"
#include "GDL/TranslateAction.h"
#include "GDL/TranslateCondition.h"

EventsRenderingHelper * EventsRenderingHelper::singleton = NULL;

EventsRenderingHelper::EventsRenderingHelper() :
eventGradient1(wxColour(209, 217, 255)),
eventGradient2(wxColour(196, 207, 255)),
eventGradient3(wxColour(233, 233, 255)),
eventGradient4(wxColour(205, 205, 255)),
eventBorderColor(wxColour(185, 185, 247)),
eventConditionsGradient1(wxColour(234, 242, 255)),
eventConditionsGradient2(wxColour(221, 232, 255)),
eventConditionsGradient3(wxColour(237, 237, 255)),
eventConditionsGradient4(wxColour(210, 210, 255)),
eventConditionsBorderColor(wxColour(185, 185, 247)),
selectionColor(wxColour(255,230,156)),
conditionsColumnWidth(200),
rectangleOutline(wxPen(wxColour(242/2,242/2,242/2), 1)),
rectangleFill(wxBrush(wxColour(242,242,242))),
conditionsRectangleFill(wxBrush(wxColour(230,235,239))),
selectedRectangleOutline(wxPen(wxColour(255, 85, 17), 1)),
selectedRectangleFill(wxBrush(wxColour(255,230,156))),
font( 8, wxDEFAULT, wxNORMAL, wxNORMAL ),
bigFont(12, wxDEFAULT, wxNORMAL, wxNORMAL ),
boldFont(8, wxDEFAULT, wxNORMAL, wxBOLD ),
italicFont( 8, wxDEFAULT, wxFONTSTYLE_ITALIC, wxNORMAL ),
italicSmallFont( 5, wxDEFAULT, wxFONTSTYLE_ITALIC, wxNORMAL )
{
    fakeBmp.Create(10,10,-1);
}

void EventsRenderingHelper::DrawNiceRectangle(wxDC & dc, const wxRect & rect, const wxColor & color1, const wxColor & color2,const wxColor & color3,const wxColor & color4,const wxColor & color5) const
{
    {
        wxRect background(rect);
        background.x += 2;
        background.width -= 4;
        background.height -= 2;

        background.height = 3;
        dc.GradientFillLinear(background, color1, color2, wxSOUTH);

        background.y += background.height;
        background.height = rect.height - 2 - background.height;
        dc.GradientFillLinear(background, color3, color4, wxSOUTH);
    }
    {
        wxPoint border_points[8];
        border_points[0] = wxPoint(2, 0);
        border_points[1] = wxPoint(1, 1);
        border_points[2] = wxPoint(1, rect.height - 4);
        border_points[3] = wxPoint(3, rect.height - 2);
        border_points[4] = wxPoint(rect.width - 4, rect.height - 2);
        border_points[5] = wxPoint(rect.width - 2, rect.height - 4);
        border_points[6] = wxPoint(rect.width - 2, 1);
        border_points[7] = wxPoint(rect.width - 4, -1);

        dc.SetPen(wxPen(color5));
        dc.DrawLines(sizeof(border_points)/sizeof(wxPoint), border_points, rect.x, rect.y);
    }
}

int EventsRenderingHelper::DrawConditionsList(const vector < Instruction > & conditions, wxDC & dc, const int x, const int y, const int width)
{
    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();
    const int iconWidth = 18;
    const int separation = 1;
    const int sideSeparation = 1;
    const int conditionsHeight = GetRenderedConditionsListHeight(conditions, width);

    if ( conditions.empty() )
    {
        //Pas de conditions, on affiche juste un petit message
        wxRect rect(x, y, width, 18);
        DrawNiceRectangle(dc, rect, eventConditionsGradient1,
                                eventConditionsGradient2,
                                eventConditionsGradient3,
                                eventConditionsGradient4,
                                eventConditionsBorderColor);

        dc.SetFont( GetItalicFont() );
        dc.DrawText( _("Pas de conditions"), x + 2, y + 1 );

        return 18;
    }


    htmlRenderer.SetDC(&dc);
    htmlRenderer.SetStandardFonts( 8 );

    //Draw Conditions rectangle
    wxRect rect(x, y, width, conditionsHeight);
    DrawNiceRectangle(dc, rect, eventConditionsGradient1,
                            eventConditionsGradient2,
                            eventConditionsGradient3,
                            eventConditionsGradient4,
                            eventConditionsBorderColor);

    //Draw each conditions
    int yCondition = y + 1;
    for ( unsigned int j = 0;j < conditions.size();j++ )
    {
        const InstructionInfos & instructionInfos = extensionManager->GetConditionInfos(conditions[j].GetType());

        //Draw needed icons
        int leftIconsWidth = 0;
        if ( conditions[j].IsInverted() )
        {
            dc.DrawBitmap( wxBitmap( "res/contraire.png", wxBITMAP_TYPE_ANY ), x  + sideSeparation + leftIconsWidth, yCondition, true );
            leftIconsWidth += 18;
        }
        if ( !conditions[j].IsLocal() )
        {
            dc.DrawBitmap( wxBitmap( "res/global.png", wxBITMAP_TYPE_ANY ), x  + sideSeparation + leftIconsWidth, yCondition, true );
            leftIconsWidth += 18;
        }

        //Get the width available
        int freeWidth = width - leftIconsWidth - iconWidth - sideSeparation*2;
        freeWidth = freeWidth <= 0 ? 1 : freeWidth;
        GetHTMLRenderer().SetSize(freeWidth, 9999);

        yCondition += separation;

        if ( conditions[j].selected )
        {
            dc.SetBrush(GetSelectedRectangleFillBrush());
            dc.SetPen(GetSelectedRectangleOutlinePen());
            dc.DrawRectangle(x + sideSeparation + leftIconsWidth + iconWidth,
                             yCondition,
                             width - (sideSeparation + leftIconsWidth + iconWidth),
                             conditions[j].renderedHeight);
        }

        //Draw the condition icon
        dc.DrawBitmap( instructionInfos.smallicon, x + sideSeparation + leftIconsWidth, yCondition, true );

        //Draw the condition text
        string TexteFinal = TranslateCondition::Translate(conditions[j], instructionInfos,  false, true);
        GetHTMLRenderer().SetHtmlText(TexteFinal);
        wxArrayInt neededArray;
        GetHTMLRenderer().Render(x + sideSeparation + leftIconsWidth + iconWidth, yCondition, neededArray);

        yCondition += GetHTMLRenderer().GetTotalHeight()+separation+1;
    }
    yCondition += 3;

    return yCondition-y;
}

int EventsRenderingHelper::DrawActionsList(const vector < Instruction > & actions, wxDC & dc, const int x, const int y, const int width)
{
    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();
    const int iconWidth = 18;
    const int separation = 1;
    const int sideSeparation = 1;

    if ( actions.empty() )
    {
        dc.SetFont( GetItalicFont() );
        dc.DrawText( _("Pas d'actions"), x+ 2, y + 1 );
        return 18;
    }

    htmlRenderer.SetDC(&dc);
    htmlRenderer.SetStandardFonts( 8 );

    //Draw each actions
    int yAction = y + 1;
    for ( unsigned int j = 0;j < actions.size();j++ )
    {
        const InstructionInfos & instructionInfos = extensionManager->GetActionInfos(actions[j].GetType());

        //Draw global icon, if needed.
        int leftIconsWidth = 0;
        if ( !actions[j].IsLocal() )
        {
            dc.DrawBitmap( wxBitmap( "res/global.png", wxBITMAP_TYPE_ANY ), x + sideSeparation + leftIconsWidth, yAction, true );
            leftIconsWidth += 18;
        }

        //Get the width available
        int freeWidth = width - leftIconsWidth - iconWidth - sideSeparation*2;
        freeWidth = freeWidth <= 0 ? 1 : freeWidth;
        GetHTMLRenderer().SetSize(freeWidth, 9999);

        //Draw the bitmap of the action
        yAction += separation;

        if ( actions[j].selected )
        {
            dc.SetBrush(GetSelectedRectangleFillBrush());
            dc.SetPen(GetSelectedRectangleOutlinePen());
            dc.DrawRectangle(x + leftIconsWidth + iconWidth + sideSeparation,
                             yAction,
                             width - (leftIconsWidth + iconWidth + sideSeparation)-2,
                             actions[j].renderedHeight);
        }

        dc.DrawBitmap( instructionInfos.smallicon, x + sideSeparation + leftIconsWidth, yAction, true );

        //Draw the action text
        GetHTMLRenderer().SetHtmlText(TranslateAction::Translate( actions[j], instructionInfos, false, true ));
        wxArrayInt neededArray;
        GetHTMLRenderer().Render(x + leftIconsWidth + iconWidth + sideSeparation, yAction, neededArray);

        yAction += GetHTMLRenderer().GetTotalHeight()+separation+1;
    }
    yAction += 3;

    return yAction-y;
}

unsigned int EventsRenderingHelper::GetRenderedConditionsListHeight(const vector < Instruction > & conditions, int width)
{
    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();

    const int separation = 1;
    const int sideSeparation = 1;

    if ( conditions.empty() )
        return 18; //Taille n�cessaire pour afficher "Pas de conditions" et "Pas d'actions"

    wxMemoryDC dc;
    dc.SelectObject(fakeBmp);

    //La classe de rendu de HTML
    GetHTMLRenderer().SetDC(&dc); //On a besoin du m�me DC que pour le rendu
    GetHTMLRenderer().SetStandardFonts( 8 );
    const int iconWidth = 18;

    int yCondition = 1;
    for ( unsigned int j = 0;j < conditions.size();j++ )
    {
        const InstructionInfos & instructionInfos = extensionManager->GetConditionInfos(conditions[j].GetType());

        //Largeur prise par les icones
        int leftIconsWidth = 0;
        if ( conditions[j].IsInverted() )
            leftIconsWidth += 18;

        if ( !conditions[j].IsLocal() )
            leftIconsWidth += 18;

        //Largeur libre pour le texte
        int freeWidth = width - leftIconsWidth - iconWidth - sideSeparation*2;
        freeWidth = freeWidth <= 0 ? 1 : freeWidth;
        GetHTMLRenderer().SetSize(freeWidth, 9999);

        yCondition += separation;

        //Calcul de la hauteur prise par le texte
        GetHTMLRenderer().SetHtmlText(TranslateCondition::Translate(conditions[j], instructionInfos, false, true));
        yCondition += GetHTMLRenderer().GetTotalHeight()+separation+1;

        conditions[j].renderedHeight = GetHTMLRenderer().GetTotalHeight();
        conditions[j].renderedHeightNeedUpdate = false;
    }
    yCondition += 3;
    return yCondition;
}

unsigned int EventsRenderingHelper::GetRenderedActionsListHeight(const vector < Instruction > & actions, int width)
{
    gdp::ExtensionsManager * extensionManager = gdp::ExtensionsManager::getInstance();

    const int separation = 1;
    const int sideSeparation = 1;

    if ( actions.empty() )
        return 18; //Taille n�cessaire pour afficher "Pas d'actions"

    wxMemoryDC dc;
    dc.SelectObject(fakeBmp);

    //La classe de rendu de HTML
    GetHTMLRenderer().SetDC(&dc); //On a besoin du m�me DC que pour le rendu
    GetHTMLRenderer().SetStandardFonts( 8 );
    const int iconWidth = 18;

    int yAction = 1;
    for ( unsigned int j = 0;j < actions.size();j++ )
    {
        const InstructionInfos & instructionInfos = extensionManager->GetActionInfos(actions[j].GetType());

        //Largeur prise par les icones
        int leftIconsWidth = 0;
        if ( !actions[j].IsLocal() )
            leftIconsWidth += 18;

        //Largeur libre pour le texte
        int freeWidth = width - leftIconsWidth - iconWidth - 0 - sideSeparation*2;
        freeWidth = freeWidth <= 0 ? 1 : freeWidth;
        GetHTMLRenderer().SetSize(freeWidth, 9999);

        yAction += separation;

        //Calcul de la hauteur prise par le texte
        GetHTMLRenderer().SetHtmlText(TranslateAction::Translate( actions[j], instructionInfos, false, true ));
        yAction += GetHTMLRenderer().GetTotalHeight()+separation+1;

        actions[j].renderedHeight = GetHTMLRenderer().GetTotalHeight();
        actions[j].renderedHeightNeedUpdate = false;
    }
    yAction += 3;

    return yAction;
}

int EventsRenderingHelper::GetConditionAt(const vector < Instruction > & conditions, int x, int y)
{
    unsigned int conditionsY = 1;
    for (unsigned int c = 0;c<conditions.size();++c)
    {
        conditionsY += 1;
        if ( y >= conditionsY && y <= conditionsY+conditions[c].renderedHeight)
        {
            return c;
        }
        conditionsY += conditions[c].renderedHeight+2;
    }
    return -1;
}

int EventsRenderingHelper::GetActionAt(const vector < Instruction > & actions, int x, int y)
{
    unsigned int actionsY = 1;
    for (unsigned int a = 0;a<actions.size();++a)
    {
        actionsY += 1;
        if ( y >= actionsY && y <= actionsY+actions[a].renderedHeight)
         {
            return a;
         }
        actionsY += actions[a].renderedHeight+2;
    }
    return -1;
}

EventsRenderingHelper * EventsRenderingHelper::getInstance()
{
    if ( NULL == singleton )
        singleton = new EventsRenderingHelper;

    return singleton;
}

void EventsRenderingHelper::kill()
{
    if ( NULL != singleton )
    {
        delete singleton;
        singleton = NULL;
    }
}
#endif