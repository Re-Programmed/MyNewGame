#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Util/linmath.h"

using namespace std;

namespace Rendering
{
	class Shader
	{
	public:
		unsigned int ProgramID;

		Shader(string vertexCode, string fragmentCode)
		{
			this->vertexCode = vertexCode;
			this->fragmentCode = fragmentCode;
		}

		void Load();
		void Use();

		void SetMatrix4x4(string uniformName, mat4x4 mat);
		void SetVector3f(string uniformName, vec3 vec3);

		static float* GetMatrix4x4Values(mat4x4 matrix);
	private:
		string vertexCode;
		string fragmentCode;
	};
}


