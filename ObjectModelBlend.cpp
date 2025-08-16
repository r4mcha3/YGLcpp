#include "ObjectModelBlend.h"

namespace ygl
{
	ObjectModelBlend::ObjectModelBlend(Mesh* mesh, Shader* shader, Texture* texture, GLenum sFactor, GLenum dFactor) : ObjectModel(mesh, shader, texture)
	{
		sourceFactor = sFactor;
		destinationFactor = dFactor;
	}

	void ObjectModelBlend::OnRedraw()
	{
		glEnable(GL_BLEND);
		glBlendFunc(sourceFactor, destinationFactor);
		ObjectModel::OnRedraw();
		glDisable(GL_BLEND);
	}
}