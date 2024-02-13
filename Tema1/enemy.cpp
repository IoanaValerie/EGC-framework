#include "enemy.h"

Enemy::Enemy(const std::string& name, float offset, float cx, float cy, float resolution, glm::vec3 color, int nr, bool scale, float scaleX, float scaleY)
    : meshName(name), cx(cx), cy(cy), translateX(resolution), translateY(offset), color(color), nr(nr), scale(scale), scaleX(scaleX), scaleY(scaleY){}

void Enemy::Update(float deltaTimeSeconds)
{
    translateX -= deltaTimeSeconds * 40.0f;
}

void Enemy::setScale(bool scale)
{
    this->scale = scale;
}