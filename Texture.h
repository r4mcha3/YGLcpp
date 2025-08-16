#pragma once
#include "pch.h"

namespace ygl
{
	class Texture
	{
	private:
		const string PATH_PREFIX = "resource/texture/";

	private:
		unsigned char* data;

		GLuint id;
		GLsizei width;
		GLsizei height;
		GLsizei channels;

		bool hasObject;

	public:
		Texture();
		~Texture();

		void LoadFromFile(const char* fileName);
		void MakeGLObject();
		void BindTexture();
	};
}