#pragma once
#include "ObjectModel.h"

namespace ygl
{
	class Mesh;
	class Shader;
	class Texture;

	class ObjectModelBlend : public ObjectModel
	{
	protected:
		GLenum sourceFactor;
		GLenum destinationFactor;

	public:
		ObjectModelBlend(Mesh* mesh, Shader* shader, Texture* texture = nullptr, GLenum sFactor = GL_ONE, GLenum dFactor = GL_ZERO);

	protected:
		virtual void OnRedraw() override;
	};
}