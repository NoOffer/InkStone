#pragma once

#include "GameObject.h"

namespace NXTN {
	class Camera : public GameObject
	{
	public:
		Camera(
			const float& fov,
			const vec2i& resolution,
			const bool& isPerspective = true,
			float nearPlane = 0.1f,
			float farPlane = 100.0f);
		~Camera() {}

		void inline ResetViewPortSize(vec2i& vpSize) { m_AspectRatio = vpSize.x / (float)vpSize.y; }
		void inline ResetViewPortSize(int x, int y) { m_AspectRatio = x / (float)y; }

		mat4 GetViewMatrix();
		mat4 GetProjMatrix();
		mat4 GetViewProjMatrix();

	private:
		float m_FOV;
		float m_AspectRatio;  // Width : height ratio
		bool m_IsPerspective;
		vec2 m_FarNear;

		//mat4 m_ProjMatrix;  // Save the projection matrix to avoid repeated calculation
		//bool m_ProjMatAvailable;
	};
}
