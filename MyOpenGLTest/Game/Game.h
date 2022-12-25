#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Util/linmath.h"

namespace Game
{
#define VERTEX_SHADER "./Shaders/sprite.vs"
#define FRAGMENT_SHADER "./Shaders/sprite.frag"s

	class Game
	{
	public:
		Game(std::string gameTitle);

		void SetClearColor(vec4 color) { *clearColor = *color; }

		void Run();

		GLFWwindow* GetWindow();
	protected:
		virtual void LoadContent();
		virtual void Init();
		virtual void Update();
		void RenderScreen(GLFWwindow* window);
		virtual void Render() = 0;
		virtual void LateUpdate() = 0;
		virtual void Close() = 0;
	private:	
		std::string gameTitle;
		vec4 clearColor = { 0, 0, 0, 1 };
		void clearWindow();

		GLFWwindow* Window;
	};
}