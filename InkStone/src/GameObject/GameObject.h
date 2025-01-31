#pragma once

#include "src/Component/Transform.h"

namespace NXTN {
	class GameObject
	{
	public:
		GameObject() {}
		virtual ~GameObject() {}
		
		void AddComponent(Component* component_ptr);
		
		void Update();

		Transform transform;

	private:
		// Warning: the std::type_id of a same type may differ across different environments and compilations
		// Also this implementation limits the map to contain one object per type
		std::vector<std::unique_ptr<Component>> m_Components;
	};
}

