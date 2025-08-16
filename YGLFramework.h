#pragma once
#include "pch.h"
#include "Input.h"
#include "Mesh.h"
#include "Object.h"
#include "ObjectModel.h"
#include "ObjectModelBlend.h"
#include "Scene.h"
#include "Shader.h"
#include "Texture.h"
#include "ObjectCamera.h"
#include "ObjectCameraOrthographic.h"
#include "ObjectCameraPerspective.h"
#include "YGLMath.hpp"

namespace ygl
{
	class YGLFramework
	{
	private:
		static std::string applicationTitle;
		static Scene* currentScene;
		static void (*updateCallback)();

	public:
		static void Initialize(int argc, char** argv);
		static void BeginUpdateLoop();
		static void SetUpdateHandler(void (*callback)());
		static void SwitchScene(Scene* scene);

	private:
		static void Update();
		static void DrawScene();
		static void Reshape(int x, int y);
	};
}