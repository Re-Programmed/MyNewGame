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

		void UpdateProjectionMatrix();
		float* MouseToWorldCoords(vec2 mouse);

		void LerpTowards(vec2 target, float speed);
	private:
		vec2 focusPosition;
		float zoom;
	};

}


