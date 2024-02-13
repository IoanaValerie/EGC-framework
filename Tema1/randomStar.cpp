#include "randomStar.h"

RandomStar::RandomStar(const std::string& name, float cx, float cy, float time, bool clicked, bool remove, float translate, glm::vec3 color)
    : meshName(name), cx(cx), cy(cy), timeStar(time), click(clicked), removed(remove), translate(translate), color(color){}

RandomStar::RandomStar(const RandomStar& other)
{
	this->meshName = other.meshName;
	this->cx = other.cx;
	this->cy = other.cy;
	this->timeStar = other.timeStar;
	this->click = other.click;
	this->removed = other.removed;
	this->translate = other.translate;
	this->color = other.color;
}

RandomStar::~RandomStar() {}

void RandomStar::setX(float x)
{
	this->cx = x;
}

void RandomStar::setY(float y)
{
	this->cy = y;
}

void RandomStar::setName(const std::string& name)
{
	this->meshName = name;
}

void RandomStar::setClick(bool ok)
{
	this->click = ok;
}

void RandomStar::setRemove(bool remove)
{
	this->removed = remove;
}

void RandomStar::setTranslate(float translate)
{
	this->translate = translate;
}

void RandomStar::Update(float deltaTimeSeconds)
{
	timeStar += deltaTimeSeconds;
}

void RandomStar::UpdateTranslate(float deltaTimeSeconds)
{
	this->translate += deltaTimeSeconds * 80;
}