#pragma once
#include "pch.h"
#include "YGLMath.hpp"

namespace ygl
{
	struct GlobalUniformBlock
	{
		Matrix4x4 view_Transform;
		Matrix4x4 proj_Transform;
	};

	class Shader
	{
	private:
		static GLuint globalUniformID;
	public:
		static void CreateGlobalUBO();
		static void SetGlobalUBO(const GlobalUniformBlock& v);

	private:
		const string PATH_PREFIX = "resource/shader/";

	private:
		GLuint programID;
		GLuint shaderFragmentID;
		GLuint shaderVertexID;

	private:
		GLuint MakeShaders(const char* fileName, GLenum shaderTyp);
		void MakeShaderProgram(GLuint vertShader, GLuint fragShader);

	public:
		Shader(const char* vertFile, const char* fragFile);
		~Shader();

		void UseProgram();
		void SetUniformFloat(const char* key, float value);
		void SetUniformVector2(const char* key, const Vector2& value);
		void SetUniformVector3(const char* key, const Vector3& value);
		void SetUniformVector4(const char* key, const Vector4& value);
		void SetUniformMatrix4x4(const char* key, const Matrix4x4& value);
	};
}