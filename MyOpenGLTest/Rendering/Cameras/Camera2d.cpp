#include "Camera2d.h"

namespace Rendering
{
	Camera2d::Camera2d(vec2 focusPosition, float zoom)
	{
		this->focusPosition[0] = focusPosition[0];
		this->focusPosition[1] = focusPosition[1];
		this->zoom = zoom;
	}
	
	void Camera2d::UpdateProjectionMatrix(mat4x4& u)
	{
		int* WindowSize = DisplayManager::GetWindowSize();
		float l = focusPosition[0] - WindowSize[0] / 2;
		float r = focusPosition[0] + WindowSize[0] / 2;
		float t = focusPosition[1] - WindowSize[1] / 2;
		float b = focusPosition[1] + WindowSize[1] / 2;

		mat4x4 projectionMatrix;
		mat4x4_ortho(projectionMatrix, l, r, b, t, 0.01f, 100);

		mat4x4_scale(u, projectionMatrix, zoom);
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

	void Camera2d::CameraData(float* focusPosition, float& zoom)
	{
		focusPosition = this->focusPosition;
		zoom = this->zoom;
	}

}