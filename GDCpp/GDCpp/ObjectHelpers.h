/*
 * GDevelop C++ Platform
 * Copyright 2008-2015 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the MIT License.
 */
/**
 * \file File containing tools to manipulate objects easier.
 */

#ifndef OBJECTHELPERS_H
#define OBJECTHELPERS_H
#include "GDCpp/Object.h"
#include "GDCpp/RuntimeObject.h"
#include <memory>
#include <vector>

/**
 * An object list is a vector containing (smart) pointers to objects.
 */
typedef std::vector < std::shared_ptr<RuntimeObject> > RuntimeObjList;

/**
 * Objects are usually managed thanks to (smart) pointers.
 */
typedef std::shared_ptr<RuntimeObject> RuntimeObjSPtr;

/**
 * \brief Functor testing object name
 *
 * \see Object
 */
struct ObjectHasName : public std::binary_function<std::shared_ptr<gd::Object>, std::string, bool> {
    bool operator()(const std::shared_ptr<gd::Object> & object, const std::string & name) const { return object->GetName() == name; }
};

#endif // OBJECTHELPERS_H

