#pragma once
#include "ObjectCamera.h"

namespace ygl
{
	class ObjectCameraPerspective : public ObjectCamera
	{
	private:
		float fovy;
		float zNear;
		float zFar;

	public:
		ObjectCameraPerspective(float fovy, float zNear, float zFar);

	public:
		virtual Matrix4x4 ProjMatrix() override;
	};
}