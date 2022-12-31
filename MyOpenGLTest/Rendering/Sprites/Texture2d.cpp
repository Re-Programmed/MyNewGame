#include "Texture2d.h"

namespace Rendering
{
	namespace Sprites
	{
		Texture2d::Texture2d()
		{
			Width = 0;
			Height = 0;

			InternalFormat = GL_RGB;
			ImageFormat = GL_RGB;
			Wrap_S = GL_REPEAT;
			Wrap_T = GL_REPEAT;
			Filter_Min = GL_NEAREST;
			Filter_Max = GL_NEAREST;

			glGenTextures(1, &ID);
		}

		void Texture2d::Generate(int width, int height, const void* data)
		{
			this->Width = width;
			this->Height = height;

			Bind();

			glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, width, height, 0, ImageFormat, GL_UNSIGNED_BYTE, data);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void Texture2d::Bind()
		{
			glBindTexture(GL_TEXTURE_2D, ID);
		}
	}
}