#include "Game.h"
#include <iostream>
#include "../Rendering/Display/DisplayManager.h"
#include "GameTime.h"

using namespace std;
using namespace Rendering::Display;

namespace Game
{
	Game::Game(string gameTitle)
	{
		this->gameTitle = gameTitle;
	}

	void Game::Run()
	{

		LoadContent();
		Init();

		while (!glfwWindowShouldClose(Window))
		{
			GameTime::UpdateTime(glfwGetTime());

			Update();

			glfwPollEvents();

			RenderScreen(Window);

			LateUpdate();
		}

		Close();
		DisplayManager::CloseWindow();
	}

	//This function can be overriden to add more content (Always call base function)
	void Game::LoadContent()
	{
		if (!glewInit()) { return; }
		if (!glfwInit()) { return; }

		Window = DisplayManager::InitWindow(gameTitle.c_str());
		if (!Window) { return; }

		spriteRenderer = new SpriteRenderer();

		SpriteShader ss;

		ss.Compile(VERTEX_SHADER, FRAGMENT_SHADER);

		cout << "Shaders/sprite.vs";

		spriteRenderer->InitShader(ss);
		spriteRenderer->InitRenderData();
		cam = new Camera2d(vec2{ 0, 0 }, 10);
		//Init Camera

		//Init Sprites

		//Init Shaders
	}

	void Game::Update()
	{
		//Run Instantiations
	}

	void Game::Init()
	{
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	GLFWwindow* Game::GetWindow()
	{
		return Window;
	}

	float i = 0;
	bool r = false;
	Texture2d tex = AssetManager::DecodePNG("iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAAXNSR0IArs4c6QAAAEpJREFUOE9jZKAQMFKon2HUAAbsYfD/////yIHLyMiIM6ywSsAMgGlE56MYjh6NIMW4bMQmh+ECig0AuQg9DPCFx2hCwpGQSMmhAHj7IBE9pYuJAAAAAElFTkSuQmCC", true);

	void Game::RenderScreen(GLFWwindow* window)
	{
 		if (r) { i++; if (i > 1000) { r = false; } }
		else { i--; if (i < -1000) { r = true; } }

		cout << i << endl;
		SetClearColor(vec4{ i / 1000, i / 1000, i / 1000, 1 });

		clearWindow();
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBindVertexArray(spriteRenderer->quadVAO);

		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		Render();

		//Render Each Object
		cout << "TEXTURE: " << tex.ID << endl;
		spriteRenderer->DrawSprite(*cam, vec3{ 0,0,0 }, tex, vec3{0, 0, 0});

		//glDrawArrays(GL_TRIANGLES, 0, 24);

		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}

	void Game::clearWindow()
	{
		glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	}

	Game::~Game()
	{
		delete cam;
		delete spriteRenderer;
		delete Window;
	}
}