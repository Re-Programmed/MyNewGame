#include "Shader.h"

namespace Rendering
{
	void Shader::Load()
	{
		unsigned int vs, fs;

		vs = glCreateShader(GL_VERTEX_SHADER);

		const char* vs_str = vertexCode.c_str();
		glShaderSource(vs, 1, &vs_str, NULL);

		glCompileShader(vs);

		GLint status = 1;
		glGetShaderiv(vs, GL_COMPILE_STATUS, &status);

		if(status == 0)
		{
			//error
			cout << "ERROR COMPILING VERTEX SHADER" << endl;
		}

		fs = glCreateShader(GL_FRAGMENT_SHADER);

		const char* fs_str = fragmentCode.c_str();
		glShaderSource(fs, 1, &fs_str, NULL);

		glCompileShader(fs);

		glGetShaderiv(vs, GL_COMPILE_STATUS, &status);

		if (status == 0)
		{
			//error
			cout << "ERROR COMPILING FRAGMENT SHADER" << endl;
		}

		ProgramID = glCreateProgram();
		glAttachShader(ProgramID, vs);
		glAttachShader(ProgramID, fs);

		glLinkProgram(ProgramID);

		glDetachShader(ProgramID, vs);
		glDetachShader(ProgramID, fs);
		glDeleteShader(fs);
		glDeleteShader(vs);
	}

	void Shader::Use()
	{
		glUseProgram(ProgramID);
	}

	void Shader::SetMatrix4x4(string uniformName, mat4x4 mat)
	{
		int location = glGetUniformLocation(ProgramID, uniformName.c_str());
		glUniformMatrix4fv(location, 1, false, GetMatrix4x4Values(mat));
	}

	void Shader::SetVector3f(string uniformName, vec3 vec3)
	{
		int location = glGetUniformLocation(ProgramID, uniformName.c_str());
		glUniform3f(location, vec3[0], vec3[1], vec3[2]);
	}

	float* Shader::GetMatrix4x4Values(mat4x4 m)
	{
		return new float[16]
		{
			m[0][0], m[0][1], m[0][2], m[0][3],
			m[1][0], m[1][1], m[1][2], m[1][3],
			m[2][0], m[2][1], m[2][2], m[2][3],
			m[3][0], m[3][1], m[3][2], m[3][3]
		};
	}

}