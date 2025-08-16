#include "pch.h"
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace ygl
{
	Texture::Texture()
	{
		data = nullptr;
		hasObject = false;

		id = NULL;
		width = 0;
		height = 0;
		channels = 0;
	}

	Texture::~Texture()
	{
		if (hasObject)
		{
			glDeleteTextures(1, &id);
		}
	}

	void Texture::LoadFromFile(const char* fileName)
	{
		stbi_set_flip_vertically_on_load(true);
		data = stbi_load((PATH_PREFIX + fileName).c_str(), &width, &height, &channels, 0);
	}

	void Texture::MakeGLObject()
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //--- 현재 바인딩된 텍스처의 파라미터 설정하기
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		hasObject = true;
	}

	void Texture::BindTexture()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}
}
