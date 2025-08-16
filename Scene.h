#pragma once
#include "pch.h"
#include "Node.h"

namespace ygl
{
	class Object;
	class ObjectCamera;

	class Scene : public Node<Object>
	{
	private:
		ObjectCamera* camera;

	public:
		Scene(ObjectCamera* camera);
		~Scene();

		ObjectCamera* GetCamera() const;
		void SetCamera(ObjectCamera* camera);

	public:
		void Redraw();
	};
}
