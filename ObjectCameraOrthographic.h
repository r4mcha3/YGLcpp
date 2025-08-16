#pragma once
#include "ObjectCamera.h"

namespace ygl
{
	class ObjectCameraOrthographic : public ObjectCamera
	{
	private:
		float size;

	public:
		ObjectCameraOrthographic(float size);

	public:
		virtual Matrix4x4 ProjMatrix() override;
	};
}