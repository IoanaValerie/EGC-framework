#ifndef RANDOMSTAR_H
#define RANDOMSTAR_H
#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>
#include <lab_m1/Tema1/Tema1_object2D.h>
#include <lab_m1/Tema1/Tema1_transform2D.h>

class RandomStar {
public:
    std::string meshName;
    float cx;
    float cy;
    float timeStar;
    bool click;
    bool removed;
    float translate;
    glm::vec3 color;

    RandomStar(const std::string& name, float cx, float cy, float time, bool clicked, bool remove, float translate, glm::vec3 color);
    RandomStar(const RandomStar& other);
    ~RandomStar();

    void setX(float x);
    void setY(float y);
    void setName(const std::string& name);
    void setClick(bool ok);
    void setRemove(bool remove);
    void setTranslate(float translate);

    void Update(float deltaTimeSeconds);
    void UpdateTranslate(float deltaTimeSeconds);
};

#endif