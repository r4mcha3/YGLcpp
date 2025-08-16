#pragma once
#include "Object.h"

namespace ygl
{
	class Mesh;
	class Shader;
	class Texture;

	class ObjectModel : public Object
	{
	protected:
		Mesh*	modelMesh;
		Shader*	modelShader;
		Texture* modelTexture;
		GLuint drawMode;

	public:
		ObjectModel(Mesh* mesh, Shader* shader, Texture* texture = nullptr);
		virtual ~ObjectModel() override;

	public:
		Mesh* GetMesh() const;
		Shader* GetShader() const;
		Texture* GetTexture() const;
		GLuint GetDrawMode() const;

	public:
		void SetMesh(Mesh* mesh);
		void SetShader(Shader* shader);
		void SetTexture(Texture* texture);
		void SetDrawMode(GLuint mode);

	protected:
		virtual void OnRedraw() override;
	};
}