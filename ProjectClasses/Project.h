/**
* @file Project.h
* @brief Header file of the project class.
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

#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

class Project;

#include "ENIGMA_IDEMain.h"
#include <vector>
#include <map>

using namespace std;

#include "backend/EnigmaStruct.h"
#include "Background.h"
#include "Sprite.h"
#include "Path.h"
#include "Scene.h"
#include "Shader.h"
#include "Polygon.h"
#include "Model.h"
#include "Timeline.h"
#include "Font.h"
#include "Script.h"
#include "Object.h"

class Project
{
    public:

    map<wxString, ResourceManager> resources; ///< Vector of all resource types in this project
    EnigmaStruct* es; ///< Any pre-serialized resources to be passed to the compiler

    private:

};

#endif // PROJECT_H_INCLUDED
