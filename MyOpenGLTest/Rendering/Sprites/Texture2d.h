#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Rendering
{
	namespace Sprites
	{
		class Texture2d
		{
		public:
			GLuint ID;

			int Width, Height;

			int InternalFormat, ImageFormat;

			int Wrap_S, Wrap_T;

			int Filter_Min, Filter_Max;

			Texture2d();

			void Generate(int width, int height, const void* data);

			void Bind();
		};
	}
}