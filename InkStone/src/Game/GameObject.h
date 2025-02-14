#pragma once

#include "entt.hpp"

namespace NXTN {
	class GameObject
	{
	public:
		GameObject(entt::entity entity) : name("GameObject"), m_Entity(entity) {}
		//GameObject(const GameObject& other);

		inline entt::entity& GetInternalID() { return m_Entity; }

	public:
		std::string name;

	private:
		// This is basically an uint32_t or smth
		entt::entity m_Entity;
	};
}

