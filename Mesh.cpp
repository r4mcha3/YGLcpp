#include "pch.h"
#include "Mesh.h"
#include "OBJ_Loader.h"

namespace ygl
{
	Mesh::Mesh()
	{
		vao = NULL;
		ebo = NULL;
		memset(vbo, NULL, sizeof(vbo));

		vertexDirty = false;
		hasObject = false;
	}

	Mesh::~Mesh()
	{
		if (hasObject)
		{
			glDeleteVertexArrays(1, &vao);
			glDeleteBuffers(SIZEOF_VBO, vbo);
			glDeleteBuffers(1, &ebo);
		}
	}

	void Mesh::LoadFromFile(const char* fileName)
	{
		objl::Loader loader;
		if (!loader.LoadFile(PATH_PREFIX + fileName))
			return;

		auto& vv = loader.LoadedVertices;
		auto& iv = loader.LoadedIndices;

		for (int i = 0; i < vv.size(); ++i)
		{
			objl::Vector3 p = vv[i].Position;
			objl::Vector3 n = vv[i].Normal;
			objl::Vector2 u = vv[i].TextureCoordinate;
			ygl::Vector3 pp = Vector3(p.X, p.Y, p.Z);
			ygl::Vector3 np = Vector3(n.X, n.Y, n.Z);
			ygl::Vector2 up = Vector2(u.X, u.Y);

			AppendVertex(pp);
			AppendColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
			AppendNormal(np);
			AppendUV(up);
		}

		for (int i = 0; i < iv.size(); ++i)
		{
			GLuint u = iv[i];
			AppendIndex(u);
		}
	}

	void Mesh::AppendVertex(const Vector3& v)
	{
		positions.push_back(v.x);
		positions.push_back(v.y);
		positions.push_back(v.z);

		vertexDirty = true;
	}

	void Mesh::AppendColor(const Vector4& v)
	{
		colors.push_back(v.x);
		colors.push_back(v.y);
		colors.push_back(v.z);
		colors.push_back(v.w);

		vertexDirty = true;
	}

	void Mesh::AppendNormal(const Vector3& v)
	{
		normals.push_back(v.x);
		normals.push_back(v.y);
		normals.push_back(v.z);

		vertexDirty = true;
	}

	void Mesh::AppendUV(const Vector2& v)
	{
		uvs.push_back(v.x);
		uvs.push_back(v.y);

		vertexDirty = true;
	}

	void Mesh::AppendIndex(GLuint v)
	{
		indices.push_back(v);

		vertexDirty = true;
	}

	void Mesh::AppendIndex(GLuint v0, GLuint v1, GLuint v2)
	{
		indices.push_back(v0);
		indices.push_back(v1);
		indices.push_back(v2);

		vertexDirty = true;
	}

	void Mesh::MakeGLObjects()
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(SIZEOF_VBO, vbo);
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * positions.size(), positions.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * colors.size(), colors.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * normals.size(), normals.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * uvs.size(), uvs.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(3);

		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

		glBindVertexArray(NULL);
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

		hasObject = true;
		vertexDirty = false;
	}

	void Mesh::ValidateGLObjects()
	{
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * positions.size(), positions.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * colors.size(), colors.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * normals.size(), normals.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * uvs.size(), uvs.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

		glBindVertexArray(NULL);
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

		vertexDirty = false;
	}

	void Mesh::Draw(GLenum mode)
	{
		if (vertexDirty)
			ValidateGLObjects();
		glBindVertexArray(vao);
		glDrawElements(mode, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
		glBindVertexArray(NULL);
	}
}