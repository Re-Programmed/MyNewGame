#pragma once
#include "../../Util/linmath.h"
#include "../Display/DisplayManager.h"

using namespace Rendering::Display;

namespace Rendering
{
	class Camera2d
	{
	public:
		Camera2d(vec2 focusPosition, float zoom);

		void UpdateProjectionMatrix(mat4x4& u);
		float* MouseToWorldCoords(vec2 mouse);

		void LerpTowards(vec2 target, float speed);

		void CameraData(float* focusPosition, float& zoom);
	private:
		vec2 focusPosition;
		float zoom;
	};

}


