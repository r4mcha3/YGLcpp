#pragma once
#include "pch.h"
#include "Node.h"

namespace ygl
{
	class Object : public Node<Object>
	{
	protected:
		Vector3		position;
		Quaternion	rotation;
		Vector3		scale;

		Matrix4x4	matrixTRSLocal;
		Matrix4x4	matrixTRSWorld;

		bool matrixDirty;

	public:
		Object();
		virtual ~Object();

	public:
		void ValidateMatrix(const Object* parentPtr);
		void Redraw(const Object* parentPtr, bool forceValidate);

		void RemoveFromParent();
		
	public:
		Vector3		GetPosition() const;
		Quaternion	GetRotation() const;
		Vector3		GetScale() const;

	public:
		void SetPosition(const Vector3& v);
		void SetPositionX(float s);
		void SetPositionY(float s);
		void SetPositionZ(float s);
		void Translate(const Vector3& v);
		void SetRotation(const Quaternion& v);
		void SetScale(const Vector3& v);
		void SetScale(float s);

	protected:
		virtual void OnRedraw();
	};
}