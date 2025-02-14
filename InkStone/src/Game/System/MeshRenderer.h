#pragma once

#include "GameSystem.h"

namespace NXTN {
	class MeshRenderer : public GameSystem
	{
	public:
		MeshRenderer() {}
		~MeshRenderer() {}

		virtual void Update(entt::registry& scene) override;
	};
}

