#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Tema1_object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float lengthX, float lengthY, glm::vec3 color, bool fill = false);
    Mesh* CreateDiamond(const std::string& name, glm::vec3 center, float diamondX, float diamondY, float rectangleX, float rectangleY, glm::vec3 color, bool fill = false);
    Mesh* CreateHexagonWithInnerHexagon(const std::string& name, glm::vec3 center, float outerRadius, float innerRadius, glm::vec3 outerColor, glm::vec3 innerColor, bool fill = false);
    Mesh* CreateStar(const std::string& name, glm::vec3 center, float value, glm::vec3 color);
}
