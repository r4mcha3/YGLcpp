#pragma once
#include "pch.h"

namespace ygl
{
	typedef glm::vec<2, float, glm::defaultp> Vector2;
	typedef glm::vec<3, float, glm::defaultp> Vector3;
	typedef glm::vec<4, float, glm::defaultp> Vector4;

	typedef glm::vec<2, int, glm::defaultp> Vector2Int;
	typedef glm::vec<3, int, glm::defaultp> Vector3Int;
	typedef glm::vec<4, int, glm::defaultp> Vector4Int;

	typedef glm::mat<2, 2, float, glm::defaultp> Matrix2x2;
	typedef glm::mat<3, 3, float, glm::defaultp> Matrix3x3;
	typedef glm::mat<4, 4, float, glm::defaultp> Matrix4x4;

	typedef glm::qua<float, glm::defaultp> Quaternion;
}