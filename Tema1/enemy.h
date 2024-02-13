#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>
#include <lab_m1/Tema1/Tema1_object2D.h>
#include <lab_m1/Tema1/Tema1_transform2D.h>

class Enemy {
public:
    std::string meshName;
    float cx;
    float cy;
    float translateX;
    float translateY;
    glm::vec3 color;
    int nr;
    bool scale;
    float scaleX;
    float scaleY;

    Enemy(const std::string& name, float offset, float cx, float cy, float resolution, glm::vec3 color, int nr, bool scale, float scaleX, float scaleY);

    void Update(float deltaTimeSeconds);
    void setScale(bool scale);
};

#endif