#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Util/linmath.h"
#include "../Rendering/Sprites/SpriteRenderer.h"
#include "../Rendering/Cameras/Camera2d.h"
#include "../Util/AssetManagment/AssetManager.h"

using namespace Rendering;
using namespace Sprites;

namespace Game
{
#define VERTEX_SHADER "Shaders/sprite.vert"
#define FRAGMENT_SHADER "Shaders/sprite.frag"

	class Game
	{
	public:
		Game(std::string gameTitle);
		~Game();

		void SetClearColor(vec4 color) { *clearColor = *color; }

		void Run();

		GLFWwindow* GetWindow();
	protected:
		SpriteRenderer* spriteRenderer;
		Camera2d* cam;

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