#include "pch.h"
#include "Object.h"

namespace ygl
{
	Object::Object()
	{
		position = Vector3(0.0f, 0.0f, 0.0f);
		rotation = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
		scale = Vector3(1.0f, 1.0f, 1.0f);

		matrixTRSLocal = Matrix4x4(1.0f);
		matrixTRSWorld = Matrix4x4(1.0f);

		matrixDirty = true;
	}

	Object::~Object()
	{

	}

	void Object::ValidateMatrix(const Object* parentPtr)
	{
		Matrix4x4 matrixT = glm::translate(Matrix4x4(1.0f), position);
		Matrix4x4 matrixR = glm::mat4_cast(rotation);
		Matrix4x4 matrixS = glm::scale(Matrix4x4(1.0f), scale);
		matrixTRSLocal = matrixT * matrixR * matrixS;
		
		if (parentPtr != nullptr)
			matrixTRSWorld = parentPtr->matrixTRSWorld * matrixTRSLocal;
		else
			matrixTRSWorld = matrixTRSLocal;

		matrixDirty = false;
	}

	void Object::Redraw(const Object* parentPtr, bool forceValidate)
	{
		bool validate = matrixDirty || forceValidate;

		if (validate)
			ValidateMatrix(parentPtr);
		OnRedraw();

		for (Object* childObject : children)
			childObject->Redraw(this, validate);
	}

	void Object::RemoveFromParent()

	{
		if (parent == nullptr)
			return;
		parent->RemoveChild(this);
	}

	Vector3 Object::GetPosition() const
	{
		return position;
	}

	Quaternion Object::GetRotation() const
	{
		return rotation;
	}

	Vector3 Object::GetScale() const
	{
		return scale;
	}

	void Object::SetPosition(const Vector3& v)
	{
		position = v;
		matrixDirty = true;
	}

	void Object::SetPositionX(float s)
	{
		position.x = s;
		matrixDirty = true;
	}

	void Object::SetPositionY(float s)
	{
		position.y = s;
		matrixDirty = true;
	}

	void Object::SetPositionZ(float s)
	{
		position.z = s;
		matrixDirty = true;
	}

	void Object::Translate(const Vector3& v)
	{
		position += v;
		matrixDirty = true;
	}

	void Object::SetRotation(const Quaternion& v)
	{
		rotation = v;
		matrixDirty = true;
	}

	void Object::SetScale(const Vector3& v)
	{
		scale = v;
		matrixDirty = true;
	}

	void Object::SetScale(float s)
	{
		scale = glm::one<Vector3>() * s;
		matrixDirty = true;
	}

	void Object::OnRedraw()
	{

	}
}