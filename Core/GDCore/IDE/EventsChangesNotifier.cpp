/*
 * GDevelop Core
 * Copyright 2008-2015 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the MIT License.
 */

#include <algorithm>
#include <memory>
#include "GDCore/Events/EventsList.h"
#include "GDCore/Events/Event.h"
#include "GDCore/Events/Builtin/LinkEvent.h"
#include "GDCore/Events/ExpressionParser.h"
#include "GDCore/PlatformDefinition/ExternalEvents.h"
#include "GDCore/PlatformDefinition/Platform.h"
#include "GDCore/PlatformDefinition/Project.h"
#include "GDCore/PlatformDefinition/Layout.h"
#include "GDCore/IDE/EventsChangesNotifier.h"

namespace gd
{

void EventsChangesNotifier::NotifyChangesInEventsOfScene(gd::Project & project, gd::Layout & layout)
{
    for ( unsigned int j = 0; j < project.GetUsedPlatforms().size();++j)
        project.GetUsedPlatforms()[j]->GetChangesNotifier().OnEventsModified(project, layout);

    //Notify others scenes, which include the changed scene ( even indirectly ), that their events has changed
    for (unsigned int i = 0;i<project.GetLayoutsCount();++i)
    {
        if ( &project.GetLayout(i) == &layout ) continue;

        std::vector< gd::Layout* > linkedScenes;
        std::vector< gd::ExternalEvents * > notUsed;

        GetScenesAndExternalEventsLinkedTo(project.GetLayout(i).GetEvents(), project, linkedScenes, notUsed);

        for (unsigned int j = 0;j<linkedScenes.size();++j)
        {
            if ( linkedScenes[j]->GetName() == layout.GetName() )
            {
                for ( unsigned int k = 0; k < project.GetUsedPlatforms().size();++k)
                    project.GetUsedPlatforms()[k]->GetChangesNotifier().OnEventsModified(project, project.GetLayout(i), /*indirectChange=*/true, layout.GetName());
            }
        }
    }
    //Also notify external events
    for (unsigned int i = 0;i<project.GetExternalEventsCount();++i)
    {
        std::vector< gd::Layout* > linkedScenes;
        std::vector< gd::ExternalEvents * > notUsed;

        GetScenesAndExternalEventsLinkedTo(project.GetExternalEvents(i).GetEvents(), project, linkedScenes, notUsed);

        for (unsigned int j = 0;j<linkedScenes.size();++j)
        {
            if ( linkedScenes[j]->GetName() == layout.GetName() )
            {
                for ( unsigned int k = 0; k < project.GetUsedPlatforms().size();++k)
                    project.GetUsedPlatforms()[k]->GetChangesNotifier().OnEventsModified(project, project.GetExternalEvents(i), /*indirectChange=*/true, layout.GetName());
            }
        }
    }
}

void EventsChangesNotifier::NotifyChangesInEventsOfExternalEvents(gd::Project & project, gd::ExternalEvents & externalEvents)
{
    for ( unsigned int j = 0; j < project.GetUsedPlatforms().size();++j)
        project.GetUsedPlatforms()[j]->GetChangesNotifier().OnEventsModified(project, externalEvents);

    //Notify scenes, which include the external events ( even indirectly ), that their events has changed
    for (unsigned int i = 0;i<project.GetLayoutsCount();++i)
    {
        std::vector< gd::Layout* > notUsed;
        std::vector< gd::ExternalEvents * > linkedExternalEvents;

        GetScenesAndExternalEventsLinkedTo(project.GetLayout(i).GetEvents(), project, notUsed, linkedExternalEvents);

        for (unsigned int j = 0;j<linkedExternalEvents.size();++j)
        {
            if ( linkedExternalEvents[j]->GetName() == externalEvents.GetName() )
            {
                for ( unsigned int k = 0; k < project.GetUsedPlatforms().size();++k)
                    project.GetUsedPlatforms()[k]->GetChangesNotifier().OnEventsModified(project, project.GetLayout(i), /*indirectChange=*/true, externalEvents.GetName());
            }
        }
    }
    //Also notify external events
    for (unsigned int i = 0;i<project.GetExternalEventsCount();++i)
    {
        std::vector< gd::Layout* > notUsed;
        std::vector< gd::ExternalEvents * > linkedExternalEvents;

        GetScenesAndExternalEventsLinkedTo(project.GetExternalEvents(i).GetEvents(), project, notUsed, linkedExternalEvents);

        for (unsigned int j = 0;j<linkedExternalEvents.size();++j)
        {
            if ( linkedExternalEvents[j]->GetName() == externalEvents.GetName() )
            {
                for ( unsigned int k = 0; k < project.GetUsedPlatforms().size();++k)
                    project.GetUsedPlatforms()[k]->GetChangesNotifier().OnEventsModified(project, project.GetExternalEvents(i), /*indirectChange=*/true, externalEvents.GetName());
            }
        }
    }
}

void EventsChangesNotifier::GetScenesAndExternalEventsLinkedTo(const gd::EventsList & events,
                                                          gd::Project & project,
                                                          std::vector< gd::Layout * > & layouts,
                                                          std::vector< gd::ExternalEvents * > & externalEvents)
{
    for (unsigned int i = 0;i<events.size();++i)
    {
        try {
            const gd::LinkEvent & linkEvent = dynamic_cast<const gd::LinkEvent&>(events[i]);

            //We've got a link event, search now linked scene/external events
            if ( project.HasExternalEventsNamed(linkEvent.GetTarget()) )
            {
                gd::ExternalEvents & linkedExternalEvents = project.GetExternalEvents(linkEvent.GetTarget());

                //Protect against circular references
                if ( find(externalEvents.begin(), externalEvents.end(), &linkedExternalEvents) == externalEvents.end() )
                {
                    externalEvents.push_back(&linkedExternalEvents);
                    GetScenesAndExternalEventsLinkedTo(linkedExternalEvents.GetEvents(), project, layouts, externalEvents);
                }
            }
            else if ( project.HasLayoutNamed(linkEvent.GetTarget()) )
            {
                gd::Layout & linkedLayout = project.GetLayout(linkEvent.GetTarget());

                //Protect against circular references
                if ( find(layouts.begin(), layouts.end(), &linkedLayout) == layouts.end() )
                {
                    layouts.push_back(&linkedLayout);
                    GetScenesAndExternalEventsLinkedTo(linkedLayout.GetEvents(), project, layouts, externalEvents);
                }
            }
        } catch(...) {}

        if ( events[i].CanHaveSubEvents() )
            GetScenesAndExternalEventsLinkedTo(events[i].GetSubEvents(), project, layouts, externalEvents);
    }
}

}
