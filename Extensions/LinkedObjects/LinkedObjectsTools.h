/**

GDevelop - LinkedObjects Extension
Copyright (c) 2011-2013 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#ifndef LINKEDOBJECTSTOOLS_H_INCLUDED
#define LINKEDOBJECTSTOOLS_H_INCLUDED
#include <string>
#include <map>
#include <vector>
class RuntimeObject;
class RuntimeScene;

namespace GDpriv
{

namespace LinkedObjects
{

void GD_EXTENSION_API LinkObjects(RuntimeScene & scene, RuntimeObject * a, RuntimeObject * b );
void GD_EXTENSION_API RemoveLinkBetween(RuntimeScene & scene, RuntimeObject * a, RuntimeObject * b);
void GD_EXTENSION_API RemoveAllLinksOf(RuntimeScene & scene, RuntimeObject * object);
bool GD_EXTENSION_API PickObjectsLinkedTo(RuntimeScene & scene, std::map <std::string, std::vector<RuntimeObject*> *> pickedObjectsLists, RuntimeObject * object);

}

}

#endif // LINKEDOBJECTSTOOLS_H_INCLUDED

