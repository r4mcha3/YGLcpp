#include "pch.h"
#include "ObjectModel.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace ygl
{
	ObjectModel::ObjectModel(Mesh* mesh, Shader* shader, Texture* texture)
	{
		modelMesh = mesh;
		modelShader = shader;
		modelTexture = texture;
		drawMode = GL_TRIANGLES;
	}

	ObjectModel::~ObjectModel()
	{
		modelMesh = nullptr;
		modelShader = nullptr;
	}

	Mesh* ObjectModel::GetMesh() const
	{
		return modelMesh;
	}

	Shader* ObjectModel::GetShader() const
	{
		return modelShader;
	}

	Texture* ObjectModel::GetTexture() const
	{
		return modelTexture;
	}

	GLuint ObjectModel::GetDrawMode() const
	{
		return drawMode;
	}

	void ObjectModel::SetMesh(Mesh* mesh)
	{
		modelMesh = mesh;
	}

	void ObjectModel::SetShader(Shader* shader)
	{
		modelShader = shader;
	}

	void ObjectModel::SetTexture(Texture* texture)
	{
		modelTexture = texture;
	}

	void ObjectModel::SetDrawMode(GLuint mode)
	{
		drawMode = mode;
	}

	void ObjectModel::OnRedraw()
	{
		modelShader->UseProgram();
		modelShader->SetUniformMatrix4x4("model_Transform", matrixTRSWorld);
		if (modelTexture != nullptr)
			modelTexture->BindTexture();
		modelMesh->Draw(drawMode);
	}
}