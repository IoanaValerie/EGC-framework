#pragma once

#include "components/simple_scene.h"
#include "enemy.h"
#include "randomStar.h"
#include "square.h"
#include "diamond.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        std::vector<Enemy> hexagons; // Lista de hexagoane
        std::vector<RandomStar> stars; // Lista stele de pe ecran
        std::vector<RandomStar> diamondStars; // Lista cu stele pentru a lua romburi
        std::vector<RandomStar> Projectils;
        std::vector<RandomStar> projectils;
        std::vector<Square> lifeSquare;
        std::vector<Diamond> diamonds;
        std::vector<Diamond> diamondsGrid;
        float lastSpawnedMoment = 0.0f;
        float lastSpawnedMomentStars = 0.0f;
        float widthStar, heightStar;
        float widthDiamond, heightDiamond;
        int collectedStars1 = 0, collectedStars2 = 0;
        int lifeContorSquare = 0;
        int deadEnemies = 0;
        bool ok = false;
        float cxHexagon, cyHexagon;
        glm::mat3 modelMatrix;
        float translate = 0;
        float angle = 0;
        bool square1 = true, square2 = true, square3 = true, square4 = true, square5 = true, square6 = true, square7 = true, square8 = true, square9 = true;
        int squareContor = 0;
        bool subStars = false;
    };
}
