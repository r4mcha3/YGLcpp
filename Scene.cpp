#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "ObjectCameraOrthographic.h"
#include "ObjectCameraPerspective.h"

namespace ygl
{
	Scene::Scene(ObjectCamera* camera)
	{
		SetCamera(camera);
	}

	Scene::~Scene()
	{

	}

	ObjectCamera* Scene::GetCamera() const
	{
		return camera;
	}

	void Scene::SetCamera(ObjectCamera* camera)
	{
		if (this->camera != nullptr)
			RemoveChild(this->camera);
		this->camera = camera;
		AddChild(camera);
	}

	void Scene::Redraw()
	{
		camera->BeginDraw();
		for (Object* sceneObject : children)
			sceneObject->Redraw(nullptr, false);
	}
}