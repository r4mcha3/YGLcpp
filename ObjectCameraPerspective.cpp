#include "pch.h"
#include "ObjectCameraPerspective.h"

namespace ygl
{
	ObjectCameraPerspective::ObjectCameraPerspective(float fovy, float zNear, float zFar) : ObjectCamera()
	{
		this->fovy = fovy;
		this->zNear = zNear;
		this->zFar = zFar;
	}

	Matrix4x4 ObjectCameraPerspective::ProjMatrix()
	{
		float aspect = static_cast<float>(viewportWidth) / viewportHeight;
		return glm::perspective(fovy, aspect, zNear, zFar);
	}
}
