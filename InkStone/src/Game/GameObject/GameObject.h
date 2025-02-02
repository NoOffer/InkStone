#pragma once

#include "src/Game/Component/Transform.h"

namespace NXTN {
	class GameObject
	{
	public:
		GameObject();
		GameObject(const GameObject& other);
		virtual ~GameObject() {}

		void AddComponent(Component* component_ptr);

		void AddChild(GameObject* child);

		void Update();

		inline unsigned long long GetID() { return m_ObjID; }

		Transform transform;

	private:
		std::vector<std::unique_ptr<Component>> m_Components;

		std::vector<std::unique_ptr<GameObject>> m_Children;

		unsigned long long m_ObjID;

	private:
		static unsigned long long s_ObjID;
	};
}

