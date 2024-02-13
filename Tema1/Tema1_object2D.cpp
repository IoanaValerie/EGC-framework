#include "Tema1_object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* Tema1_object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Tema1_object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float lengthX,
    float lengthY,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(lengthX, 0, 0), color),
        VertexFormat(corner + glm::vec3(lengthX, lengthY, 0), color),
        VertexFormat(corner + glm::vec3(0, lengthY, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* Tema1_object2D::CreateDiamond(
    const std::string& name,
    glm::vec3 center,
    float diamondX,
    float diamondY,
    float rectangleX,
    float rectangleY,
    glm::vec3 color,
    bool fill)
{
    float halfDiamondWidth = diamondX / 2.0f;
    float halfDiamondHeight = diamondY / 2.0f;
    float halfRectangleWidth = rectangleX / 2.0f;
    float halfRectangleHeight = rectangleY / 2.0f;

    // Coordonatele pentru mijlocul laturii din stânga
    glm::vec3 leftMiddle = center - glm::vec3(0, halfRectangleHeight / 2.0f, 0);

    std::vector<VertexFormat> vertices =
    {
        // Diamond vertices
        VertexFormat(center + glm::vec3(0, halfDiamondHeight, 0.5), color),
        VertexFormat(center + glm::vec3(halfDiamondWidth, 0, 0.5), color),
        VertexFormat(center + glm::vec3(0, -halfDiamondHeight, 0.5), color),
        VertexFormat(center + glm::vec3(-halfDiamondWidth, 0, 0.5), color),

        // Rectangle vertices
        VertexFormat(leftMiddle, color),
        VertexFormat(leftMiddle + glm::vec3(halfRectangleWidth, 0, 0.5), color),
        VertexFormat(leftMiddle + glm::vec3(halfRectangleWidth, halfRectangleHeight, 0.5), color),
        VertexFormat(leftMiddle + glm::vec3(0, halfRectangleHeight, 0.5), color)
    };

    Mesh* combinedShape = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        combinedShape->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    indices.insert(indices.end(), { 4, 5, 6, 7 });

    if (!fill) {
        combinedShape->SetDrawMode(GL_LINE_LOOP);
    } 
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(4);
        indices.push_back(6);
    }

    combinedShape->InitFromData(vertices, indices);
    return combinedShape;
}

Mesh* Tema1_object2D::CreateHexagonWithInnerHexagon(
    const std::string& name,
    glm::vec3 center,
    float outerRadius,
    float innerRadius,
    glm::vec3 outerColor,
    glm::vec3 innerColor,
    bool fill)
{
    std::vector<VertexFormat> vertices;

    // Calculate the outer hexagon vertices
    for (int i = 0; i < 6; ++i) {
        float angle = glm::radians(60.0f * i);
        float x = outerRadius * cos(angle);
        float y = outerRadius * sin(angle);
        vertices.push_back(VertexFormat(center + glm::vec3(x, y, 0.6f), outerColor));
    }

    vertices.push_back(VertexFormat(center + glm::vec3(0, 0, 0.6f), outerColor)); // Center for the outer hexagon

    // Calculate the inner hexagon vertices
    for (int i = 0; i < 6; ++i) {
        float angle = glm::radians(60.0f * i);
        float x = innerRadius * cos(angle);
        float y = innerRadius * sin(angle);
        vertices.push_back(VertexFormat(center + glm::vec3(x, y, 0.7), innerColor));
    }

    vertices.push_back(VertexFormat(center + glm::vec3(0, 0, 0.7), innerColor)); // Center for the inner hexagon


    Mesh* hexagonWithInnerHexagon = new Mesh(name);
    std::vector<unsigned int> indices;
    
    if (!fill) {
        hexagonWithInnerHexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Create triangles for the outer hexagon
        for (int i = 0; i < 6; ++i) {
            indices.push_back(i);
            indices.push_back((i + 1) % 6);
            indices.push_back(13); // Index of the center vertex for the outer hexagon
        }

        // Create triangles for the inner hexagon
        for (int i = 7; i < 12; ++i) {
            indices.push_back(i);
            indices.push_back((i + 1) % 7 + 7); // Connect to the corresponding vertex in the outer hexagon
            indices.push_back(13); // Index of the center vertex for the inner hexagon
        }

        // Fix the missing triangle
        indices.push_back(7);
        indices.push_back(12);
        indices.push_back(13);
    }

    hexagonWithInnerHexagon->InitFromData(vertices, indices);
    return hexagonWithInnerHexagon;
}

Mesh* Tema1_object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float value,
    glm::vec3 color)
{
    std::vector<VertexFormat> vertices = {
     VertexFormat(center + glm::vec3(-5.0f * value, -5.0f * value, 0.8f), color),  // A 0
     VertexFormat(center + glm::vec3(5.0f * value, -5.0f * value, 0.8f), color),  // B 1
     VertexFormat(center + glm::vec3(8.0901f * value, 4.5105f * value, 0.8f), color),  // C 2
     VertexFormat(center + glm::vec3(0.0f * value, 10.3884f * value, 0.8f), color),  // D 3
     VertexFormat(center + glm::vec3(-8.9091f * value, 4.5105f * value, 0.8f), color),  // E 4
     VertexFormat(center + glm::vec3(3.0901f * value, 0.8778f * value, 0.8f), color),  // F 5
     VertexFormat(center + glm::vec3(0.0f * value, -1.3672f * value, 0.8f), color),  // G 6
     VertexFormat(center + glm::vec3(-3.4889f * value, 1.1675f * value, 0.8f), color),  // H 7
     VertexFormat(center + glm::vec3(-1.9098f * value, 4.5105f * value, 0.8f), color),  // I 8
     VertexFormat(center + glm::vec3(1.9098f * value, 4.5105f * value, 0.8f), color),  // J 9
    };

    std::vector<unsigned int> indices = {
     0, 6, 7,  // First triangle
     6, 7, 9,  // Second triangle
     5, 6, 9,  // Third triangle
     7, 8, 9,  // Fourth triangle
     1, 5, 6,  // Fifth triangle
     2, 5, 9,  // Sixth triangle
     3, 8, 9,  // Seventh triangle
     4, 7, 8,  // Eighth triangle
    };

    Mesh* starMesh = new Mesh(name);
    starMesh->SetDrawMode(GL_TRIANGLES);
    starMesh->InitFromData(vertices, indices);

    return starMesh;
}
