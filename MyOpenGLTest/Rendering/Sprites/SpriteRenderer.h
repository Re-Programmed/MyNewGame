#pragma once
#include "SpriteShader.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Cameras/Camera2d.h"
#include "Texture2d.h"

namespace Rendering
{
	namespace Sprites
	{
		class SpriteRenderer
		{
		public:
			SpriteShader shader;
			GLuint quadVAO;
			GLuint VBO;

			float* GetQuadTextureVerts();

			void GetFlipMat(mat4x4& FlipMat);

			void InitShader(SpriteShader shader);

			void DrawSprite(Camera2d cam, vec3 Position /*Switch Out For GameObject*/, Texture2d &texture, vec3 color, bool UI = false);

			void InitRenderData();
		};
	}
}