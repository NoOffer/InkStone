#include "pch.h"

#include "GameObject.h"

namespace NXTN {
	void GameObject::AddComponent(Component* component_ptr)
	{
		// Note: typeid returns an std::type_info object, which an std::type_index is implicitly constructed from
		m_Components.emplace_back(std::unique_ptr<Component>(component_ptr));
	}

	void GameObject::Update()
	{
		for (std::unique_ptr<Component>& c : m_Components)
		{
			c->Update();
		}
	}
}