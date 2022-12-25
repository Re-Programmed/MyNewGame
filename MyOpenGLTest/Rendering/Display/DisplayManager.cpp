#include "DisplayManager.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace Rendering
{
	namespace Display
	{
		GLFWwindow* DisplayManager::InitWindow(const char* title)
		{
			if (!glfwInit()) { return nullptr; }

			GLFWmonitor* p_monitor = glfwGetPrimaryMonitor();

			const GLFWvidmode* mode = glfwGetVideoMode(p_monitor);

			GLFWwindow* Window = glfwCreateWindow(mode->width, mode->height, title, p_monitor, NULL);

			if (!Window) { glfwTerminate(); return nullptr; }

			glfwMakeContextCurrent(Window);
			
			glfwSwapInterval(1);
			
			return Window;
		}

		void DisplayManager::CloseWindow()
		{
			glfwTerminate();
		}
	}
}