#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>
#include <lab_m1/Tema1/Tema1_object2D.h>
#include <lab_m1/Tema1/Tema1_transform2D.h>

class Square {
public:
    std::string meshName;
    float cx;
    float cy;
    bool lifeContor;

    Square(const std::string& name, float cx, float cy, bool lifeContor);

};

#endif