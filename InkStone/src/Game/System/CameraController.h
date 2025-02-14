#pragma once

#include "GameSystem.h"

namespace NXTN {
	class CameraController : public GameSystem
	{
	public:
		CameraController() {}
		~CameraController() {}

		virtual void Update(entt::registry& scene) override;
	};
}
