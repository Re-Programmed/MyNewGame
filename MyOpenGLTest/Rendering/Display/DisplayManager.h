#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

namespace Rendering
{
	namespace Display
	{
		class DisplayManager
		{
		public:
			static GLFWwindow* InitWindow(const char* title);
			static void CloseWindow();
		};
	}
}
