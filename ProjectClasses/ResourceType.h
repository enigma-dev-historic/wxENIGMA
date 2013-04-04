/**
* @file ResourceType.h
* @brief Header file of the resource type class.
*
* Write a description about the file here...
*
* @section License
*
* Copyright (C) 2013 Robert B. Colton
* This file is part of wxENIGMA.
*
* wxENIGMA is free software: you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation, version 3 of the License, or (at your option) any later version.
*
* wxENIGMA is distributed in the hope that it will be useful, but WITHOUT ANY
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
* PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* wxENIGMA. If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef RESOURCETYPE_H_INCLUDED
#define RESOURCETYPE_H_INCLUDED

#include "backend/EnigmaStruct.h"
#include <wx/wx.h> // < i thot it was
#include <vector>
using std::vector;

class ResourceType
{
    public:

    virtual wxString GetName(); ///< Returns the human-readable name of this resource, eg, "Some Resource"
    virtual wxString GetSerializerName(); ///< Returns a universally unique serializer name for this resource, eg, "someresource"
    virtual wxIcon &GetGenericIcon(); ///< Returns an icon for this resource
    virtual vector<wxString> &GetPreferredExtensions(); ///< Returns a list of preferred file extensions, in order of preference
    // virtual void LoadFromEGM(EGMFile &file); ///< Loads all matching resources from an EGM
    // virtual void AddFromRaw(char *data);

    virtual ~ResourceType();
};

class ResourceInstance {
    ResourceType *type; ///< The type of this particular resource
  public:
    virtual wxIcon &GetInstanceIcon() { return type->GetGenericIcon(); }
    virtual void Edit(); ///< The user tried to edit this resource
    virtual void Delete(); ///< The user tried to delete this resource
    virtual void Duplicate(wxString newname); ///< The user tried to duplicate this resource; newname is provided by the IDE
    virtual void Rename(wxString newname); ///< Rename this resource to newname
};

class ResourceManager {
    public:
    ResourceType *type; ///< The kind of resource contained
    vector<ResourceInstance*> instances; ///< A list of all resources of this type in the project
};

extern vector<ResourceType*> ResourceTypes; ///< Vector of all resource types available to any project

#endif // RESOURCETYPE_H_INCLUDED
