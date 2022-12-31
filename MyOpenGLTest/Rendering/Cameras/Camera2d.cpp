#include "Camera2d.h"

namespace Rendering
{
	Camera2d::Camera2d(vec2 focusPosition, float zoom)
	{
		this->focusPosition[0] = focusPosition[0];
		this->focusPosition[1] = focusPosition[1];
		this->zoom = zoom;
	}
	
	void Camera2d::UpdateProjectionMatrix()
	{
		int* WindowSize = DisplayManager::GetWindowSize();

		glViewport(0, 0, WindowSize[0], WindowSize[1]);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, WindowSize[0], WindowSize[1], 0.0, -1.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
	}

	float* Camera2d::MouseToWorldCoords(vec2 mouse)
	{
		int* windowSize = DisplayManager::GetWindowSize();

		return new float[2]{ mouse[0] / zoom + focusPosition[0] - (windowSize[0] / zoom) / 2, mouse[1] / zoom + (focusPosition[1] - (windowSize[1] / zoom) / 2) };
	}

	void Camera2d::LerpTowards(vec2 target, float speed)
	{
		vec2 newFocus{ focusPosition[0] + speed * (target[0] - focusPosition[0]), focusPosition[1] + speed * (target[1] - focusPosition[1]) };

		focusPosition[0] = newFocus[0];
		focusPosition[1] = newFocus[1];
	}

}