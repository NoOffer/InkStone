#pragma once

#include "entt.hpp"

namespace NXTN {
	class GameSystem
	{
	public:
		virtual void Update(entt::registry& scene) = 0;

	protected:
		GameSystem() {}
	};
}