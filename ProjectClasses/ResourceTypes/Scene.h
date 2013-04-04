/**
* @file Scene.h
* @brief Header file of the scene type class.
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

#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "ResourceType.h"
#include "backend/EnigmaStruct.h"

class SceneT: public ResourceType
{
    vector<Room*> Scenes;
};

#endif // SCENE_H_INCLUDED
