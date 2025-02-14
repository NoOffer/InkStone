#include "pch.h"

#include "Scene.h"

namespace NXTN {
	GameObject* Scene::CreateObject()
	{
		entt::entity e = m_Registry.create();

		m_Registry.emplace<Transform>(e);

		return new GameObject(e);
	}

	bool Scene::DeleteObject(unsigned long long objID)
	{
		return false;
	}

	void Scene::Update()
	{
		for (std::unique_ptr<GameSystem>& s : m_GameSystems)
		{
			s->Update(m_Registry);
		}
	}
}
