#ifndef DIAMOND_H
#define DIAMOND_H
#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>
#include <lab_m1/Tema1/Tema1_object2D.h>
#include <lab_m1/Tema1/Tema1_transform2D.h>
#include "lab_m1/Tema1/randomStar.h"

class Diamond {
public:
    std::string meshName;
    float cx;
    float cy;
    int maxim;
    bool clicked;
    bool release;
    bool clicked2;
    bool square1;
    bool square2;
    bool square3;
    bool square4;
    bool square5;
    bool square6;
    bool square7;
    bool square8;
    bool square9;
    glm::vec3 color;
    std::vector<RandomStar> projectils;
    float lastSpawned;
    float scaleX;
    float scaleY;
    bool removed;

    Diamond(const std::string& name, float cx, float cy, int starMaxim, bool click, bool click2, bool click3, bool square1, bool square2, bool square3, bool square4, bool square5, 
        bool square6, bool square7, bool square8, bool square9, glm::vec3 color, std::vector<RandomStar> projectils, float last, float scaleX, float scaleY, bool remove);
    Diamond(const Diamond& other);
    ~Diamond();

    void setCy(float cy);
    void setCx(float cx);
    void setClick(bool click);
    void setRelease(bool click2);
    void setRemoved(bool remove);
    void setScalex(float scalex);
    void setScaley(float scaley);
    void SetSquare1(bool square);
    void SetSquare2(bool square);
    void SetSquare3(bool square);
    void SetSquare4(bool square);
    void SetSquare5(bool square);
    void SetSquare6(bool square);
    void SetSquare7(bool square);
    void SetSquare8(bool square);
    void SetSquare9(bool square);
};

#endif