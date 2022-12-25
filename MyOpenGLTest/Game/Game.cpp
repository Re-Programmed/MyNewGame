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
		GLFWwindow* window = DisplayManager::InitWindow(gameTitle.c_str());
		if (!window) { return; }

		LoadContent();
		Init();

		while (!glfwWindowShouldClose(window))
		{
			GameTime::UpdateTime(glfwGetTime());

			Update();

			glfwPollEvents();

			RenderScreen(window);

			LateUpdate();
		}

		Close();
		DisplayManager::CloseWindow();
	}

	//This function can be overriden to add more content (Always call base function)
	void Game::LoadContent()
	{
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

	void Game::RenderScreen(GLFWwindow* window)
	{
		clearWindow();
		glClear(GL_COLOR_BUFFER_BIT);

		//glBindVertexArray(SPRITE SHADER QUAD VAO);
	
		Render();

		//Render Each Object

		//glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	void Game::clearWindow()
	{
		glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	}
}