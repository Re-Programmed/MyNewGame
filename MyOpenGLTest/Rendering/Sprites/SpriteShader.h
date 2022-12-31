#pragma once
#include "../../Util/linmath.h"
#include "../Shaders/Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Rendering
{
	namespace Sprites
	{
		class SpriteShader
		{
		public:
			unsigned int ID;

			SpriteShader* Use();

			void Compile(std::string vertexSource, std::string fragmentSource, std::string geometrySource = "");

			void SetFloat(const char* name, float value, bool useShader);
			void SetInt(const char* name, int value, bool useShader);
			void SetVector2f(const char* name, float x, float y, bool useShader);
			void SetVector2f(const char* name, vec2 value, bool useShader);
			void SetVector3f(const char* name, float x, float y, float z, bool useShader);
			void SetVector3f(const char* name, vec3 value, bool useShader);
			void SetVector4f(const char* name, float x, float y, float z, float w, bool useShader);
			void SetVector4f(const char* name, vec4 value, bool useShader);

			void SetMat4x4(const char* name, mat4x4 value, bool useShader);
		private:
			void checkCompileErrors(unsigned int obj, const char* type);
		};
	}
}