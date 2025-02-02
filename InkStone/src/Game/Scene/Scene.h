#pragma once

#include "src/Game/GameObject/GameObject.h"

namespace NXTN {
	class Scene
	{
	public:
		Scene() {}
		~Scene() {}

		void AddObject(GameObject* gameObj);
		bool DeleteObject(unsigned long long objID);
		size_t inline GetObjectCount() { return m_GameObjects.size(); }

		void Update();

	private:
		std::vector<std::unique_ptr<GameObject>> m_GameObjects;
	};
}

