#include "diamond.h"

Diamond::Diamond(const std::string& name, float cx, float cy, int starMaxim, bool click, bool click2, bool click3, bool square1, bool square2, 
    bool square3, bool square4, bool square5, bool square6, bool square7, bool square8, bool square9, glm::vec3 color, std::vector<RandomStar> projectils, 
    float last, float scaleX, float scaleY, bool remove)
    : meshName(name), cx(cx), cy(cy), maxim(starMaxim), clicked(click), release(click2), clicked2(click3),
      square1(square1), square2(square2), square3(square3), square4(square4), square5(square5), square6(square6), square7(square7), 
      square8(square8), square9(square9), color(color), projectils(projectils), lastSpawned(last), scaleX(scaleX), scaleY(scaleY), removed(remove) {}

Diamond::Diamond(const Diamond& other) {
    this->meshName = other.meshName;
    this->cx = other.cx;
    this->cy = other.cy;
    this->maxim = other.maxim;
    this->clicked = other.clicked;
    this->clicked2 = other.clicked2;
    this->release = other.release;
    this->square1 = other.square1;
    this->square2 = other.square2;
    this->square3 = other.square3;
    this->square4 = other.square4;
    this->square5 = other.square5;
    this->square6 = other.square6;
    this->square7 = other.square7;
    this->square8 = other.square8;
    this->square9 = other.square9;
    this->color = other.color;
    this->projectils = other.projectils;
    this->lastSpawned = other.lastSpawned;
    this->scaleX = other.scaleX;
    this->scaleY = other.scaleY;
    this->removed = other.removed;
}

Diamond::~Diamond() {}

void Diamond::setCx(float cx)
{
    this->cx = cx;
}

void Diamond::setCy(float cy)
{
    this->cy = cy;
}

void Diamond::setClick(bool click)
{
    this->clicked = click;
}

void Diamond::setRelease(bool click2)
{
    this->release = click2;
}

void Diamond::setRemoved(bool remove)
{
    this->removed = remove;
}

void Diamond::setScalex(float scaleX)
{
    this->scaleX = scaleX;
}

void Diamond::setScaley(float scaleY)
{
    this->scaleY = scaleY;
}

void Diamond::SetSquare1(bool square) {
    this->square1 = square;
}

void Diamond::SetSquare2(bool square) {
    this->square2 = square;
}

void Diamond::SetSquare3(bool square) {
    this->square3 = square;
}

void Diamond::SetSquare4(bool square) {
    this->square4 = square;
}

void Diamond::SetSquare5(bool square) {
    this->square5 = square;
}

void Diamond::SetSquare6(bool square) {
    this->square6 = square;
}

void Diamond::SetSquare7(bool square) {
    this->square7 = square;
}

void Diamond::SetSquare8(bool square) {
    this->square8 = square;
}

void Diamond::SetSquare9(bool square) {
    this->square9 = square;
}