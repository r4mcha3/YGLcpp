#pragma once
#include "pch.h"

namespace ygl
{
	class Mesh
	{
	private:
		const string PATH_PREFIX = "resource/mesh/";
		constexpr static unsigned int SIZEOF_VBO = 4U;

	private:
		vector<GLfloat> positions;
		vector<GLfloat> colors;
		vector<GLfloat> normals;
		vector<GLfloat> uvs;
		vector<GLuint>	indices;

		GLuint vao;
		GLuint vbo[SIZEOF_VBO];
		GLuint ebo;

		bool vertexDirty;
		bool hasObject;

	public:
		Mesh();
		~Mesh();

		void LoadFromFile(const char* fileName);
		void AppendVertex(const Vector3& v);
		void AppendColor(const Vector4& v);
		void AppendNormal(const Vector3& v);
		void AppendUV(const Vector2& v);
		void AppendIndex(GLuint v);
		void AppendIndex(GLuint v0, GLuint v1, GLuint v2);

		void MakeGLObjects();
		void ValidateGLObjects();

		void Draw(GLenum mode);
	};
}