#include "pch.h"
#include "ObjectCameraOrthographic.h"

namespace ygl
{
	ObjectCameraOrthographic::ObjectCameraOrthographic(float size) : ObjectCamera()
	{
		this->size = size;
	}

	Matrix4x4 ObjectCameraOrthographic::ProjMatrix()
	{
		float aspect = static_cast<float>(viewportWidth) / viewportHeight;
		return glm::ortho(aspect * -size, aspect * size, -size, size, 0.0f, 10.0f);
	}
}