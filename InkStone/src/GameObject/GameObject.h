#pragma once

#include "src/Component/Transform.h"

namespace NXTN {
	class GameObject
	{
	public:
		GameObject() {}
		virtual ~GameObject() {}
		
		void AddComponent(Component* component_ptr);

		void AddChild(GameObject* child);
		
		void Update();

		Transform transform;

	private:
		std::vector<std::unique_ptr<Component>> m_Components;

		std::vector<std::unique_ptr<GameObject>> m_Children;
	};
}

