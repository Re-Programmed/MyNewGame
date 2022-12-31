#include "SpriteShader.h"

namespace Rendering
{
	namespace Sprites
	{
		SpriteShader* SpriteShader::Use()
		{
			glUseProgram(ID);
			return this;
		}

		void SpriteShader::Compile(std::string vertexSource, std::string fragmentSource, std::string geometrySource)
		{
			unsigned int sVertex, sFragment, gShader = 0;

			sVertex = glCreateShader(GL_VERTEX_SHADER);

			GLchar const* vFiles[] = { vertexSource.c_str() };
			GLint vLengths[] = { vertexSource.size() };

			glShaderSource(sVertex, 1, vFiles, vLengths);
			glCompileShader(sVertex);
			checkCompileErrors(sVertex, "VERTEX");

			sFragment = glCreateShader(GL_FRAGMENT_SHADER);
			
			GLchar const* fFiles[] = { fragmentSource.c_str() };
			GLint fLengths[] = { fragmentSource.size() };

			glShaderSource(sFragment, 1, fFiles, fLengths);
			glCompileShader(sFragment);
			checkCompileErrors(sFragment, "FRAGMENT");

			if (geometrySource != "")
			{
				gShader = glCreateShader(GL_GEOMETRY_SHADER);

				GLchar const* gFiles[] = { geometrySource.c_str() };
				GLint gLengths[] = { geometrySource.size() };

				glShaderSource(gShader, 1, gFiles, gLengths);
				glCompileShader(gShader);
				checkCompileErrors(gShader, "GEOMETRY");
			}

			ID = glCreateProgram();
			glAttachShader(ID, sVertex);
			glAttachShader(ID, sFragment);
			if (geometrySource != "") { glAttachShader(ID, gShader); }

			glLinkProgram(ID);
			checkCompileErrors(ID, "PROGRAM");

			glDeleteShader(sVertex);
			glDeleteShader(sFragment);
			if (geometrySource != "") { glDeleteShader(gShader); }
		}
		
		void SpriteShader::SetFloat(const char* name, float value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform1f(location, value);
		}

		void SpriteShader::SetInt(const char* name, int value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform1i(location, value);
		}

		void SpriteShader::SetVector2f(const char* name, float x, float y, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform2f(location, x, y);
		}

		void SpriteShader::SetVector2f(const char* name, vec2 value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform2f(location, value[0], value[1]);
		}

		void SpriteShader::SetVector3f(const char* name, float x, float y, float z, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform3f(location, x, y, z);
		}

		void SpriteShader::SetVector3f(const char* name, vec3 value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform3f(location, value[0], value[1], value[2]);
		}

		void SpriteShader::SetVector4f(const char* name, float x, float y, float z, float w, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform4f(location, x, y, z, w);
		}

		void SpriteShader::SetVector4f(const char* name, vec4 value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniform4f(location, value[0], value[1], value[2], value[3]);
		}

		void SpriteShader::SetMat4x4(const char* name, mat4x4 value, bool useShader)
		{
			if (useShader) { Use(); }

			int location = glGetUniformLocation(ID, name);
			glUniformMatrix4fv(location, 1, false, Shader::GetMatrix4x4Values(value));
		}

		void SpriteShader::checkCompileErrors(unsigned int obj, const char* type)
		{
			if (type != "PROGRAM")
			{
				int status;
				glGetShaderiv(obj, GL_COMPILE_STATUS, &status);

				if (status == GL_FALSE)
				{
					GLint infoLogLength;
					glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infoLogLength);

					GLchar* strInfoLog = new GLchar[infoLogLength + 1];
					glGetShaderInfoLog(obj, infoLogLength, NULL, strInfoLog);

					cout << strInfoLog << endl;
					delete[] strInfoLog;
				}
			}
		}
	}
}