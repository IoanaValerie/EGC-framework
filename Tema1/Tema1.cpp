#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/Tema1_transform2D.h"
#include "lab_m1/Tema1/Tema1_object2D.h"

#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();

	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);

	//grid

	float squareSide = 100;

	Mesh* square1 = Tema1_object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square1);

	Mesh* square2 = Tema1_object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square2);

	Mesh* square3 = Tema1_object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square3);

	Mesh* square4 = Tema1_object2D::CreateSquare("square4", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square4);

	Mesh* square5 = Tema1_object2D::CreateSquare("square5", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square5);

	Mesh* square6 = Tema1_object2D::CreateSquare("square6", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square6);

	Mesh* square7 = Tema1_object2D::CreateSquare("square7", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square7);

	Mesh* square8 = Tema1_object2D::CreateSquare("square8", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square8);

	Mesh* square9 = Tema1_object2D::CreateSquare("square9", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(square9);

	float rectangleX = 65;
	float rectangleY = 350;

	Mesh* rectangle = Tema1_object2D::CreateRectangle("rectangle", corner, rectangleX, rectangleY, glm::vec3(1, 0, 0), true);
	AddMeshToList(rectangle);

	//enemies

	float outerRadius = 30;
	float innerRadius = 20;

	cxHexagon = corner.x + outerRadius / 2;
	cyHexagon = corner.y + outerRadius / 2;

	Mesh* hexagon1 = Tema1_object2D::CreateHexagonWithInnerHexagon("hexagon1", corner, outerRadius, innerRadius, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), true);
	AddMeshToList(hexagon1);

	Mesh* hexagon2 = Tema1_object2D::CreateHexagonWithInnerHexagon("hexagon2", corner, outerRadius, innerRadius, glm::vec3(0, 0, 1), glm::vec3(0.5f, 0.5f, 0.5f), true);
	AddMeshToList(hexagon2);

	Mesh* hexagon3 = Tema1_object2D::CreateHexagonWithInnerHexagon("hexagon3", corner, outerRadius, innerRadius, glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), true);
	AddMeshToList(hexagon3);

	Mesh* hexagon4 = Tema1_object2D::CreateHexagonWithInnerHexagon("hexagon4", corner, outerRadius, innerRadius, glm::vec3(1, 0, 1), glm::vec3(0.5f, 0.5f, 0.5f), true);
	AddMeshToList(hexagon4);

	// GUI rectangles

	rectangleX = 100;
	rectangleY = 100;
	widthDiamond = 100 / 2.0f;
	heightDiamond = 100 / 2.0f;

	Mesh* rectangle1 = Tema1_object2D::CreateRectangle("rectangle1", corner, rectangleX, rectangleY, glm::vec3(1, 1, 1), false);
	AddMeshToList(rectangle1);

	Mesh* rectangle2 = Tema1_object2D::CreateRectangle("rectangle2", corner, rectangleX, rectangleY, glm::vec3(1, 1, 1), false);
	AddMeshToList(rectangle2);

	Mesh* rectangle3 = Tema1_object2D::CreateRectangle("rectangle3", corner, rectangleX, rectangleY, glm::vec3(1, 1, 1), false);
	AddMeshToList(rectangle3);

	Mesh* rectangle4 = Tema1_object2D::CreateRectangle("rectangle4", corner, rectangleX, rectangleY, glm::vec3(1, 1, 1), false);
	AddMeshToList(rectangle4);

	float diamondX = 40;
	float diamondY = 80;
	float rectangleDiamondX = 80;
	float rectangleDiamondY = 40;

	Mesh* diamond1 = Tema1_object2D::CreateDiamond("diamond1", corner, diamondX, diamondY, rectangleDiamondX, rectangleDiamondY, glm::vec3(1.0f, 0.5f, 0.0f), true);
	AddMeshToList(diamond1);

	Mesh* diamond2 = Tema1_object2D::CreateDiamond("diamond2", corner, diamondX, diamondY, rectangleDiamondX, rectangleDiamondY, glm::vec3(0, 0, 1), true);
	AddMeshToList(diamond2);

	Mesh* diamond3 = Tema1_object2D::CreateDiamond("diamond3", corner, diamondX, diamondY, rectangleDiamondX, rectangleDiamondY, glm::vec3(1.0f, 1.0f, 0.0f), true);
	AddMeshToList(diamond3);

	Mesh* diamond4 = Tema1_object2D::CreateDiamond("diamond4", corner, diamondX, diamondY, rectangleDiamondX, rectangleDiamondY, glm::vec3(1, 0, 1), true);
	AddMeshToList(diamond4);

	//life

	squareSide = 50;

	Mesh* square10 = Tema1_object2D::CreateSquare("square10", corner, squareSide, glm::vec3(1, 0, 0), true);
	AddMeshToList(square10);

	Mesh* square11 = Tema1_object2D::CreateSquare("square11", corner, squareSide, glm::vec3(1, 0, 0), true);
	AddMeshToList(square11);

	Mesh* square12 = Tema1_object2D::CreateSquare("square12", corner, squareSide, glm::vec3(1, 0, 0), true);
	AddMeshToList(square12);

	//stars for GUI

	float value = 2;

	Mesh* star1 = Tema1_object2D::CreateStar("star1", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star1);

	Mesh* star2 = Tema1_object2D::CreateStar("star2", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star2);

	Mesh* star3 = Tema1_object2D::CreateStar("star3", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star3);

	Mesh* star4 = Tema1_object2D::CreateStar("star4", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star4);

	Mesh* star5 = Tema1_object2D::CreateStar("star5", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star5);

	Mesh* star6 = Tema1_object2D::CreateStar("star6", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star6);

	Mesh* star7 = Tema1_object2D::CreateStar("star7", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star7);

	Mesh* star8 = Tema1_object2D::CreateStar("star8", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star8);

	// stele random
	value = 3;
	widthStar = 8.0901f * value - (-8.9091f * value);
	heightStar = 10.3884f * value - (-5.0f * value);

	Mesh* star9 = Tema1_object2D::CreateStar("star9", corner, value, glm::vec3(1.0f, 0.41f, 0.79f));
	AddMeshToList(star9);

	Mesh* star10 = Tema1_object2D::CreateStar("star10", corner, value, glm::vec3(1.0f, 0.41f, 0.79f));
	AddMeshToList(star10);

	Mesh* star11 = Tema1_object2D::CreateStar("star11", corner, value, glm::vec3(1.0f, 0.41f, 0.79f));
	AddMeshToList(star11);

	//proiectil
	value = 4;
	Mesh* star13 = Tema1_object2D::CreateStar("star13", corner, value, glm::vec3(1.0f, 0.5f, 0.0f));
	AddMeshToList(star13);

	Mesh* star14 = Tema1_object2D::CreateStar("star14", corner, value, glm::vec3(0, 0, 1));
	AddMeshToList(star14);

	Mesh* star15 = Tema1_object2D::CreateStar("star15", corner, value, glm::vec3(1.0f, 1.0f, 0.0f));
	AddMeshToList(star15);

	Mesh* star16 = Tema1_object2D::CreateStar("star16", corner, value, glm::vec3(1, 0, 1));
	AddMeshToList(star16);

	//completare stele ramase
	value = 2;

	Mesh* star12 = Tema1_object2D::CreateStar("star12", corner, value, glm::vec3(0.5f, 0.5f, 0.5f));
	AddMeshToList(star12);
}


void Tema1::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// Sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
	if (lifeContorSquare == 3)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else
	{
		glm::ivec2 resolution = window->GetResolution();

		// grid
		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(100, 50);
		RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(100, 175);
		RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(100, 300);
		RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(225, 50);
		RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(225, 175);
		RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(225, 300);
		RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(350, 50);
		RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(350, 175);
		RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(350, 300);
		RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(10, 50);
		RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

		//gui
		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(30, 600);
		RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(160, 600);
		RenderMesh2D(meshes["rectangle2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(290, 600);
		RenderMesh2D(meshes["rectangle3"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(420, 600);
		RenderMesh2D(meshes["rectangle4"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(35, 580);
		RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(165, 580);
		RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(200, 580);
		RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(295, 580);
		RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(330, 580);
		RenderMesh2D(meshes["star5"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(425, 580);
		RenderMesh2D(meshes["star6"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(460, 580);
		RenderMesh2D(meshes["star7"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(495, 580);
		RenderMesh2D(meshes["star8"], shaders["VertexColor"], modelMatrix);

		Square life1("square12", 730, 625, true);
		Square life2("square11", 660, 625, true);
		Square life3("square10", 590, 625, true);

		if (lifeContorSquare < 1)
		{
			modelMatrix = glm::mat3(1);
			modelMatrix *= Tema1_transform2D::Translate(life1.cx, life1.cy);
			RenderMesh2D(meshes[life1.meshName], shaders["VertexColor"], modelMatrix);
		}

		if (lifeContorSquare < 2)
		{
			modelMatrix = glm::mat3(1);
			modelMatrix *= Tema1_transform2D::Translate(life2.cx, life2.cy);
			RenderMesh2D(meshes[life2.meshName], shaders["VertexColor"], modelMatrix);
		}

		if (lifeContorSquare < 3)
		{
			modelMatrix = glm::mat3(1);
			modelMatrix *= Tema1_transform2D::Translate(life3.cx, life3.cy);
			RenderMesh2D(meshes[life3.meshName], shaders["VertexColor"], modelMatrix);
		}

		//animatii stele pe ecran

		float currentTimeStar = glfwGetTime();
		int randomCx;
		int randomCy;

		if (currentTimeStar - lastSpawnedMomentStars >= 6.0f)
		{
			lastSpawnedMomentStars = currentTimeStar;

			randomCx = rand() % resolution.x;
			randomCy = rand() % 560;

			RandomStar star1("star9", randomCx, randomCy, 0, false, false, 0, glm::vec3(0, 0, 0));
			stars.push_back(star1);

			randomCx = rand() % resolution.x;
			randomCy = rand() % 560;

			RandomStar star2("star10", randomCx, randomCy, 0, false, false, 0, glm::vec3(0, 0, 0));
			stars.push_back(star2);

			randomCx = rand() % resolution.x;
			randomCy = rand() % 560;

			RandomStar star3("star11", randomCx, randomCy, 0, false, false, 0, glm::vec3(0, 0, 0));
			stars.push_back(star3);
		}

		auto star = stars.begin();

		while (star != stars.end())
		{
			if (!star->click)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Tema1_transform2D::Translate(star->cx, star->cy);
				RenderMesh2D(meshes[star->meshName], shaders["VertexColor"], modelMatrix);
				star->Update(deltaTimeSeconds);
			}

			if ((star->timeStar >= 5.0f && !star->click) || star->click)
			{
				star = stars.erase(star);
			}
			else
			{
				star++;
			}

		}

		auto starr = diamondStars.begin();

		while (starr != diamondStars.end())
		{
			if (!starr->removed)
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Tema1_transform2D::Translate(starr->cx, starr->cy);
				RenderMesh2D(meshes[starr->meshName], shaders["VertexColor"], modelMatrix);
			}

			if (starr->removed)
			{
				starr = diamondStars.erase(starr);
			}
			else
			{
				starr++;
			}

		}

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(80, 650);
		RenderMesh2D(meshes["diamond1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(210, 650);
		RenderMesh2D(meshes["diamond2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(340, 650);
		RenderMesh2D(meshes["diamond3"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Tema1_transform2D::Translate(470, 650);
		RenderMesh2D(meshes["diamond4"], shaders["VertexColor"], modelMatrix);

		Diamond diamond1("diamond1", 80, 650, 1, false, false, false, false, false, false, false, false, false, false, false, false, glm::vec3(1.0f, 0.5f, 0.0f), projectils, 0, 1, 1, false);
		diamonds.push_back(diamond1);
		Diamond diamond2("diamond2", 210, 650, 2, false, false, false, false, false, false, false, false, false, false, false, false, glm::vec3(0, 0, 1), projectils, 0, 1, 1, false);
		diamonds.push_back(diamond2);
		Diamond diamond3("diamond3", 340, 650, 2, false, false, false, false, false, false, false, false, false, false, false, false, glm::vec3(1.0f, 1.0f, 0.0f), projectils, 0, 1, 1, false);
		diamonds.push_back(diamond3);
		Diamond diamond4("diamond4", 470, 650, 3, false, false, false, false, false, false, false, false, false, false, false, false, glm::vec3(1, 0, 1), projectils, 0, 1, 1, false);
		diamonds.push_back(diamond4);

		RandomStar star1("star13", 0, 0, 0, false, false, 0, glm::vec3(1.0f, 0.5f, 0.0f));
		RandomStar star2("star14", 0, 0, 0, false, false, 0, glm::vec3(0, 0, 1));
		RandomStar star3("star15", 0, 0, 0, false, false, 0, glm::vec3(1.0f, 1.0f, 0.0f));
		RandomStar star4("star16", 0, 0, 0, false, false, 0, glm::vec3(1, 0, 1));

		//animatii inamic
		float currentTime = glfwGetTime();

		int randomTime = rand() % 10 + 8;

		if (currentTime - lastSpawnedMoment >= randomTime)
		{
			lastSpawnedMoment = currentTime;

			int randomColorIndex = rand() % 4 + 1;
			std::string hexagonString = "hexagon" + std::to_string(randomColorIndex);

			int randomLine = rand() % 3;
			float lineOffset = 70.0f + randomLine * 125.0f;

			if (randomColorIndex == 1)
			{
				Enemy hexagon(hexagonString, lineOffset, cxHexagon, cyHexagon, resolution.x, glm::vec3(1.0f, 0.5f, 0.0f), 0, false, 1, 1);
				hexagons.push_back(hexagon);
			}
			if (randomColorIndex == 2)
			{
				Enemy hexagon(hexagonString, lineOffset, cxHexagon, cyHexagon, resolution.x, glm::vec3(0, 0, 1), 0, false, 1, 1);
				hexagons.push_back(hexagon);
			}
			if (randomColorIndex == 3)
			{
				Enemy hexagon(hexagonString, lineOffset, cxHexagon, cyHexagon, resolution.x, glm::vec3(1.0f, 1.0f, 0.0f), 0, false, 1, 1);
				hexagons.push_back(hexagon);
			}
			if (randomColorIndex == 4)
			{
				Enemy hexagon(hexagonString, lineOffset, cxHexagon, cyHexagon, resolution.x, glm::vec3(1, 0, 1), 0, false, 1, 1);
				hexagons.push_back(hexagon);
			}
		}

		auto hexagon = hexagons.begin();

		while (hexagon != hexagons.end())
		{
			hexagon->Update(deltaTimeSeconds);
			if (hexagon->translateX > 60)
			{
				modelMatrix = glm::mat3(1);
				if (hexagon->nr < 3) {
					modelMatrix *= Tema1_transform2D::Translate(hexagon->cx, hexagon->cy);
					modelMatrix *= Tema1_transform2D::Translate(hexagon->translateX, hexagon->translateY);
					modelMatrix *= Tema1_transform2D::Translate(-hexagon->cx, hexagon->cy);
					RenderMesh2D(meshes[hexagon->meshName], shaders["VertexColor"], modelMatrix);

					for (auto& diamond : diamondsGrid)
					{
						if (glm::distance(glm::vec2(diamond.cx + 40, diamond.cy), glm::vec2(hexagon->translateX, hexagon->translateY + 30)) < 40 && diamond.release)
						{
							diamond.setRemoved(true);
						}
					}
					++hexagon;
				}
				else {
					modelMatrix *= Tema1_transform2D::Translate(hexagon->cx, hexagon->cy);
					modelMatrix *= Tema1_transform2D::Translate(hexagon->translateX, hexagon->translateY);
					modelMatrix *= Tema1_transform2D::Translate(-hexagon->cx, hexagon->cy);
					modelMatrix *= Tema1_transform2D::Scale(hexagon->scaleX, hexagon->scaleY);
					RenderMesh2D(meshes[hexagon->meshName], shaders["VertexColor"], modelMatrix);
					if (hexagon->scaleX <= 0.1f || hexagon->scaleY <= 0.1f)
					{
						hexagon = hexagons.erase(hexagon);
					}
					else
					{
						hexagon++;
					}
				}
			}
			else
			{
				hexagon = hexagons.erase(hexagon);
				lifeContorSquare++;
			}
		}

		//animatii diamant
		angle -= deltaTimeSeconds;

		auto diamond = diamondsGrid.begin();
		while (diamond != diamondsGrid.end())
		{
			modelMatrix = glm::mat3(1);
			if (diamond->clicked) {
				modelMatrix *= Tema1_transform2D::Translate(diamond->cx, diamond->cy);
				RenderMesh2D(meshes[diamond->meshName], shaders["VertexColor"], modelMatrix);
			}

			if (diamond->release && !diamond->clicked2)
			{
				if (!diamond->removed)
				{
					modelMatrix *= Tema1_transform2D::Translate(diamond->cx, diamond->cy);
					RenderMesh2D(meshes[diamond->meshName], shaders["VertexColor"], modelMatrix);

				}
				//arunca stele

				if (star1.color == diamond->color)
				{
					for (auto& hexagonn : hexagons)
					{
						if (hexagonn.color == diamond->color && -1 < (hexagonn.translateY + 30 - diamond->cy) && 1 > (hexagonn.translateY + 30 - diamond->cy))
						{
							if (hexagonn.nr < 3)
							{
								float currentTimee = glfwGetTime();

								if (currentTimee - diamond->lastSpawned >= 3.0f)
								{
									diamond->lastSpawned = currentTimee;
									RandomStar starRotate(star1);
									starRotate.setX(diamond->cx + 20);
									starRotate.setY(diamond->cy);
									starRotate.setTranslate(0);
									diamond->projectils.push_back(starRotate);
								}

								auto projectile = diamond->projectils.begin();
								while (projectile != diamond->projectils.end())
								{
									bool ok = false;
									modelMatrix = glm::mat3(1);
									projectile->translate += deltaTimeSeconds * 100;
									modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20, diamond->cy);
									modelMatrix *= Tema1_transform2D::Translate(projectile->translate, 0);
									modelMatrix *= Tema1_transform2D::Rotate(angle);
									RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
									if (glm::distance(glm::vec2(diamond->cx + 20 + projectile->translate, diamond->cy), glm::vec2(hexagonn.translateX, hexagonn.translateY + 30)) < 40)
									{
										modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20 + projectile->translate, diamond->cy);
										modelMatrix *= Tema1_transform2D::Rotate(angle);
										modelMatrix *= Tema1_transform2D::Scale(0, 0);
										RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
										hexagonn.nr += 1;
										projectile = diamond->projectils.erase(projectile);
										ok = true;
									}
									if (hexagonn.nr == 3)
									{
										break;
									}
									if (!ok)
									{
										projectile++;
									}
								}
							}
							else
							{
								if (hexagonn.scaleX > 0 && hexagonn.scaleY > 0)
								{
									hexagonn.scaleX -= deltaTimeSeconds;
									hexagonn.scaleY -= deltaTimeSeconds;
								}
							}
						}
					}
				}

				if (star2.color == diamond->color)
				{
					for (auto& hexagonn : hexagons)
					{
						if (hexagonn.color == diamond->color && -1 < (hexagonn.translateY + 30 - diamond->cy) && 1 > (hexagonn.translateY + 30 - diamond->cy))
						{
							if (hexagonn.nr < 3)
							{
								float currentTimee = glfwGetTime();

								if (currentTimee - diamond->lastSpawned >= 3.0f)
								{
									diamond->lastSpawned = currentTimee;
									RandomStar starRotate(star2);
									starRotate.setX(diamond->cx + 20);
									starRotate.setY(diamond->cy);
									starRotate.setTranslate(0);
									diamond->projectils.push_back(starRotate);
								}

								auto projectile = diamond->projectils.begin();
								while (projectile != diamond->projectils.end())
								{
									bool ok = false;
									modelMatrix = glm::mat3(1);
									projectile->translate += deltaTimeSeconds * 100;
									modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20, diamond->cy);
									modelMatrix *= Tema1_transform2D::Translate(projectile->translate, 0);
									modelMatrix *= Tema1_transform2D::Rotate(angle);
									RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
									if (glm::distance(glm::vec2(diamond->cx + 20 + projectile->translate, diamond->cy), glm::vec2(hexagonn.translateX, hexagonn.translateY + 30)) < 30)
									{
										modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20 + projectile->translate, diamond->cy);
										modelMatrix *= Tema1_transform2D::Rotate(angle);
										modelMatrix *= Tema1_transform2D::Scale(0, 0);
										RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
										hexagonn.nr += 1;
										projectile = diamond->projectils.erase(projectile);
										ok = true;
									}
									if (hexagonn.nr == 3)
										break;
									if (!ok)
									{
										projectile++;
									}
								}
							}
							else
							{
								if (hexagonn.scaleX > 0 && hexagonn.scaleY > 0)
								{
									hexagonn.scaleX -= deltaTimeSeconds;
									hexagonn.scaleY -= deltaTimeSeconds;
								}
							}
						}
					}
				}

				if (star3.color == diamond->color)
				{
					for (auto& hexagonn : hexagons)
					{
						if (hexagonn.color == diamond->color && -1 < (hexagonn.translateY + 30 - diamond->cy) && 1 > (hexagonn.translateY + 30 - diamond->cy))
						{
							if (hexagonn.nr < 3)
							{
								float currentTimee = glfwGetTime();

								if (currentTimee - diamond->lastSpawned >= 3.0f)
								{
									diamond->lastSpawned = currentTimee;
									RandomStar starRotate(star3);
									starRotate.setX(diamond->cx + 20);
									starRotate.setY(diamond->cy);
									starRotate.setTranslate(0);
									diamond->projectils.push_back(starRotate);
								}

								auto projectile = diamond->projectils.begin();
								while (projectile != diamond->projectils.end())
								{
									bool ok = false;
									modelMatrix = glm::mat3(1);
									projectile->translate += deltaTimeSeconds * 100;
									modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20, diamond->cy);
									modelMatrix *= Tema1_transform2D::Translate(projectile->translate, 0);
									modelMatrix *= Tema1_transform2D::Rotate(angle);
									RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
									if (glm::distance(glm::vec2(diamond->cx + 20 + projectile->translate, diamond->cy), glm::vec2(hexagonn.translateX, hexagonn.translateY + 30)) < 30)
									{
										modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20 + projectile->translate, diamond->cy);
										modelMatrix *= Tema1_transform2D::Rotate(angle);
										modelMatrix *= Tema1_transform2D::Scale(0, 0);
										RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
										hexagonn.nr += 1;
										projectile = diamond->projectils.erase(projectile);
										ok = true;
									}
									if (hexagonn.nr == 3)
										break;
									if (!ok)
									{
										projectile++;
									}
								}
							}
							else
							{
								if (hexagonn.scaleX > 0 && hexagonn.scaleY > 0)
								{
									hexagonn.scaleX -= deltaTimeSeconds;
									hexagonn.scaleY -= deltaTimeSeconds;
								}
							}
						}
					}
				}

				if (star4.color == diamond->color)
				{
					for (auto& hexagonn : hexagons)
					{
						if (hexagonn.color == diamond->color && -1 < (hexagonn.translateY + 30 - diamond->cy) && 1 > (hexagonn.translateY + 30 - diamond->cy))
						{
							if (hexagonn.nr < 3)
							{
								float currentTimee = glfwGetTime();

								if (currentTimee - diamond->lastSpawned >= 3.0f)
								{
									diamond->lastSpawned = currentTimee;
									RandomStar starRotate(star4);
									starRotate.setX(diamond->cx + 20);
									starRotate.setY(diamond->cy);
									starRotate.setTranslate(0);
									diamond->projectils.push_back(starRotate);
								}

								auto projectile = diamond->projectils.begin();
								while (projectile != diamond->projectils.end())
								{
									bool ok = false;
									modelMatrix = glm::mat3(1);
									projectile->translate += deltaTimeSeconds * 100;
									modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20, diamond->cy);
									modelMatrix *= Tema1_transform2D::Translate(projectile->translate, 0);
									modelMatrix *= Tema1_transform2D::Rotate(angle);
									RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
									if (glm::distance(glm::vec2(diamond->cx + 20 + projectile->translate, diamond->cy), glm::vec2(hexagonn.translateX, hexagonn.translateY + 30)) < 30)
									{
										modelMatrix *= Tema1_transform2D::Translate(diamond->cx + 20 + projectile->translate, diamond->cy);
										modelMatrix *= Tema1_transform2D::Rotate(angle);
										modelMatrix *= Tema1_transform2D::Scale(0, 0);
										RenderMesh2D(meshes[projectile->meshName], shaders["VertexColor"], modelMatrix);
										hexagonn.nr += 1;
										projectile = diamond->projectils.erase(projectile);
										ok = true;
									}
									if (hexagonn.nr == 3)
										break;
									if (!ok)
									{
										projectile++;
									}
								}
							}
							else
							{
								if (hexagonn.scaleX > 0 && hexagonn.scaleY > 0)
								{
									hexagonn.scaleX -= deltaTimeSeconds;
									hexagonn.scaleY -= deltaTimeSeconds;
								}
							}
						}
					}
				}

			}

			if (diamond->clicked2 || diamond->removed) {
				if (diamond->square1)
				{
					square1 = true;
					squareContor--;
				}
				if (diamond->square2)
				{
					square2 = true;
					squareContor--;
				}
				if (diamond->square3)
				{
					square3 = true;
					squareContor--;
				}
				if (diamond->square4)
				{
					square4 = true;
					squareContor--;
				}
				if (diamond->square5)
				{
					square5 = true;
					squareContor--;
				}
				if (diamond->square6)
				{
					square6 = true;
					squareContor--;
				}
				if (diamond->square7)
				{
					square7 = true;
					squareContor--;
				}
				if (diamond->square8)
				{
					square8 = true;
					squareContor--;
				}
				if (diamond->square9)
				{
					square9 = true;
					squareContor--;
				}
				if (diamond->scaleX > 0 && diamond->scaleY > 0)
				{
					diamond->scaleX -= deltaTimeSeconds * 30;
					diamond->scaleY -= deltaTimeSeconds * 30;
				}
				modelMatrix *= Tema1_transform2D::Translate(diamond->cx, diamond->cy);
				modelMatrix *= Tema1_transform2D::Scale(diamond->scaleX, diamond->scaleY);
				RenderMesh2D(meshes[diamond->meshName], shaders["VertexColor"], modelMatrix);
				if (diamond->scaleX <= 0.05f || diamond->scaleY <= 0.05f)
				{
					diamond = diamondsGrid.erase(diamond);
				}
			}
			else diamond++;
		}
	}
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
	// Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
	// Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// Add mouse move event
	for (auto& diamond : diamondsGrid)
	{
		if (diamond.clicked)
		{
			diamond.setCx(mouseX);
			diamond.setCy(720 - mouseY);
		}
	}
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	//Add mouse button press event
	for (auto& star : stars)
	{
		if (mouseX >= star.cx - widthStar && mouseX <= star.cx + widthStar &&
			720 - mouseY >= star.cy - heightStar && 720 - mouseY <= star.cy + heightStar &&
			button == 1 && star.meshName != "star12" && star.meshName != "star13" && star.meshName != "star14" && star.meshName != "star15" && star.meshName != "star16")
		{
			RandomStar star2("star12", 595 + 35 * collectedStars1, 605, 0, true, false, 0, glm::vec3(0, 0, 0));
			diamondStars.push_back(star2);
			collectedStars1++;
			star.setClick(true);
		}
	}

	if (mouseX >= 30 && mouseX <= 130 && 720 - mouseY >= 600 && 720 - mouseY <= 700 && button == 1 && diamonds[0].maxim <= collectedStars1 && squareContor < 9) {
		Diamond diamond(diamonds[0]);
		diamond.setClick(true);
		diamondsGrid.push_back(diamond);
	}
	if (mouseX >= 160 && mouseX <= 260 && 720 - mouseY >= 600 && 720 - mouseY <= 700 && button == 1 && diamonds[1].maxim <= collectedStars1 && squareContor < 9) {
		Diamond diamond(diamonds[1]);
		diamond.setClick(true);
		diamondsGrid.push_back(diamond);
	}
	if (mouseX >= 290 && mouseX <= 390 && 720 - mouseY >= 600 && 720 - mouseY <= 700 && button == 1 && diamonds[2].maxim <= collectedStars1 && squareContor < 9) {
		Diamond diamond(diamonds[2]);
		diamond.setClick(true);
		diamondsGrid.push_back(diamond);
	}
	if (mouseX >= 420 && mouseX <= 520 && 720 - mouseY >= 600 && 720 - mouseY <= 700 && button == 1 && diamonds[3].maxim <= collectedStars1 && squareContor < 9) {
		Diamond diamond(diamonds[3]);
		diamond.setClick(true);
		diamondsGrid.push_back(diamond);
	}

	for (auto& diamond : diamondsGrid)
	{
		if (button == 2)
		{
			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && !square1 && diamond.square1) {
				square1 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && !square2 && diamond.square2) {
				square2 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && !square3 && diamond.square3) {
				square3 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && !square4 && diamond.square4) {
				square4 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && !square5 && diamond.square5) {
				square5 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && !square6 && diamond.square6) {
				square6 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && !square7 && diamond.square7) {
				square7 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && !square8 && diamond.square8) {
				square8 = true;
				diamond.clicked2 = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && !square9 && diamond.square9) {
				square9 = true;
				diamond.clicked2 = true;
			}
		}
	}
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// Add mouse button release event
	for (auto& diamond : diamondsGrid)
	{
		if (diamond.clicked && button == 1)
		{
			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && square1) {
				diamond.setCx(150);
				diamond.setCy(100);
				diamond.SetSquare1(true);
				square1 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && square2) {
				diamond.setCx(275);
				diamond.setCy(100);
				diamond.SetSquare2(true);
				square2 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 50 && 720 - mouseY <= 150 && square3) {
				diamond.setCx(400);
				diamond.setCy(100);
				diamond.SetSquare3(true);
				square3 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && square4) {
				diamond.setCx(150);
				diamond.setCy(225);
				diamond.SetSquare4(true);
				square4 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && square5) {
				diamond.setCx(275);
				diamond.setCy(225);
				diamond.SetSquare5(true);
				square5 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 175 && 720 - mouseY <= 275 && square6) {
				diamond.setCx(400);
				diamond.setCy(225);
				diamond.SetSquare6(true);
				square6 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 100 && mouseX <= 200 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && square7) {
				diamond.setCx(150);
				diamond.setCy(350);
				diamond.SetSquare7(true);
				square7 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 225 && mouseX <= 325 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && square8) {
				diamond.setCx(275);
				diamond.setCy(350);
				diamond.SetSquare8(true);
				square8 = false;
				squareContor++;
				subStars = true;
			}

			if (mouseX >= 350 && mouseX <= 450 && 720 - mouseY >= 300 && 720 - mouseY <= 400 && square9) {
				diamond.setCx(400);
				diamond.setCy(350);
				diamond.SetSquare9(true);
				square9 = false;
				squareContor++;
				subStars = true;
			}

			if (subStars)
			{
				collectedStars1 -= diamond.maxim;
				collectedStars2 = diamond.maxim;
				subStars = false;
				for (auto it = diamondStars.end() - collectedStars2; it != diamondStars.end(); ++it)
				{
					it->setClick(false);
					it->setRemove(true);
				}
				diamond.setRelease(true);
			}

			diamond.setClick(false);
		}

	}
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
