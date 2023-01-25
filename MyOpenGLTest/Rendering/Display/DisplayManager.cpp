#include "DisplayManager.h"
#include <iostream>
using namespace std;

namespace Rendering
{
	namespace Display
	{
		GLFWwindow* DisplayManager::InitWindow(const char* title)
		{
			GLFWmonitor* p_monitor = glfwGetPrimaryMonitor();

			const GLFWvidmode* mode = glfwGetVideoMode(p_monitor);

			GLFWwindow* Window = glfwCreateWindow(mode->width, mode->height, title, p_monitor, NULL);

			if (!Window) { glfwTerminate(); return nullptr; }

			glfwMakeContextCurrent(Window);
			
			glfwSwapInterval(0);
			
			return Window;
		}

		void DisplayManager::CloseWindow()
		{
			glfwTerminate();
		}

		GLFWwindow* DisplayManager::getWindow()
		{
			return glfwGetCurrentContext();
		}

		int* DisplayManager::GetWindowSize()
		{
			int w, h;
			
			glfwGetWindowSize(DisplayManager::getWindow(), &w, &h);

			return new int[2] { w, h };
		}
	}
}