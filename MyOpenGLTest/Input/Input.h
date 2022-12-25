#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Game/Game.h"

namespace Input
{
	class Input
	{
	public:
		static int GetKey(Game::Game &tGame, int key);
		static double* GetMousePosition(Game::Game &tGame);
		static bool GetMouseButton(Game::Game &tGame, int button);
	};
}
