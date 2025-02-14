#pragma once

#include "GameObject.h"
#include "Component/Transform.h"
#include "System/GameSystem.h"

#include "src/Log.h"

namespace NXTN {
	class Scene
	{
	public:
		Scene() {}
		~Scene() {}

		GameObject* CreateObject();

		bool DeleteObject(unsigned long long objID);

		template<typename T>
		T* AddComponent(GameObject& gameObj)
		{
			if (typeid(T) != typeid(Transform) && typeid(T) != typeid(const Transform))
			{
				Log::Warning("Cannot duplicate Transform.");
				return nullptr;
			}

			return &(m_Registry.emplace<T>(gameObj.GetInternalID()));
		}

		template<typename T>
		bool HasComponent(GameObject& gameObj)
		{
			return m_Registry.any_of<T>(gameObj.GetInternalID());
		}

		template<typename T>
		T* GetComponent(GameObject& gameObj)
		{
			if (!HasComponent<T>(gameObj))
			{
				Log::Warning("Given object (%s) does not have component %s.", gameObj.name, typeid(T).name());
				return nullptr;
			}

			return &(m_Registry.emplace<T>(gameObj.GetInternalID()));
		}

		template<typename T>
		void AddSystem()
		{
			m_GameSystems.emplace_back(new T());
		}

		void Update();

	private:
		template<typename T>
		void CreateObjectHelper(entt::entity& entity)
		{
			if (typeid(T) != typeid(Transform) && typeid(T) != typeid(const Transform))
			{
				m_Registry.emplace<T>(entity);
			}
		}

		entt::registry m_Registry;

		std::vector<std::unique_ptr<GameSystem>> m_GameSystems;
	};
}
