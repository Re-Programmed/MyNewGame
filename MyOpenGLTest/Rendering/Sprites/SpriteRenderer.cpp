#include "SpriteRenderer.h"

namespace Rendering
{
	namespace Sprites
	{
		void SpriteRenderer::GetFlipMat(mat4x4& FlipMat)
		{
			vec4 id[4];
			mat4x4_identity(id);

			mat4x4_rotate_Y(id, FlipMat, M_PI);
		}

		float* SpriteRenderer::GetQuadTextureVerts()
		{
			return new float[24]{
			// pos      // tex
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
			};
		}

		void SpriteRenderer::InitShader(SpriteShader shader)
		{
			SpriteRenderer::shader = shader;
		}

		void SpriteRenderer::DrawSprite(Camera2d cam, vec3 Position, Texture2d &texture, vec3 color, bool UI)
		{
			shader.Use();


			mat4x4 trans, sca, sca_i;
			mat4x4 rot_i, rot;
			
			mat4x4_identity(sca_i);
			mat4x4_identity(rot_i);
			mat4x4_rotate_Z(rot_i, rot, 0 /*GameObject Rotation*/);

			//IDK MAKE A BETTER UI SYSTEM BECAUSE RENDERING AT CAM POSITION IS STUPID

			mat4x4_translate(trans, Position[0] + (0 /*If we are flipped, add scale, add when you add GameObjects*/), Position[1], 0);
			mat4x4_scale(sca_i, sca, 1);

			mat4x4 ret;
			mat4x4_mul(ret, sca, rot);

			mat4x4 ret_2;
			mat4x4_mul(ret_2, ret, trans);

			shader.SetMat4x4("model", ret_2, false); //REQUIERERERES MROE FOR FLIPPED TEXTURES

			shader.Use();
			shader.SetVector3f("spriteColor", color, false);

			mat4x4 mat;
			cam.UpdateProjectionMatrix(mat);

			shader.SetMat4x4("projection", mat, false);

			
			glActiveTexture(GL_TEXTURE0);
			texture.Bind();

			glDrawArrays(GL_TRIANGLES, 0, 24);
		}

		void SpriteRenderer::InitRenderData()
		{
			GLuint VAO;
			glGenVertexArrays(1, &VAO);

			quadVAO = VAO;
			cout << quadVAO;

			glGenBuffers(1, &VBO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);

			glBufferData(GL_ARRAY_BUFFER, 24, GetQuadTextureVerts(), GL_STATIC_DRAW);

			glBindVertexArray(quadVAO);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 4, GL_FLOAT, false, 4 * sizeof(float), NULL);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}
}