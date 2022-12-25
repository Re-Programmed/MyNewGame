#include "Input.h"

namespace Input
{
	int Input::GetKey(Game::Game &tGame, int key)
	{
		return glfwGetKey(tGame.GetWindow(), key);
	}

	double* Input::GetMousePosition(Game::Game &tGame)
	{
		double xpos = 0, ypos = 0;
		glfwGetCursorPos(tGame.GetWindow(), &xpos, &ypos);

		return new double[2] { xpos, ypos };
	}

	bool Input::GetMouseButton(Game::Game &tGame, int button)
	{
		return glfwGetMouseButton(tGame.GetWindow(), button);
	}
}