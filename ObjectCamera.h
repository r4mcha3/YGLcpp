#pragma once
#include "pch.h"
#include "Object.h"

namespace ygl
{
	class ObjectCamera : public Object
	{
	protected:
		GLint viewportX;
		GLint viewportY;
		GLsizei viewportWidth;
		GLsizei viewportHeight;

	public:
		ObjectCamera();
		~ObjectCamera() override;

	public:
		virtual Matrix4x4 ViewMatrix();
		virtual Matrix4x4 ProjMatrix();
		void BeginDraw();
	};
}