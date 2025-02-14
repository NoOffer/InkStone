#pragma once

#include "GameComponent.h"

#include "src/Math/Math.h"

namespace NXTN {
	class Camera : public GameComponent
	{
		// TODO: Add a static GetMainCamera() function
	public:
		Camera() {}
		~Camera() {}

		void Init(float i_Fov, vec2i i_Resolution, bool i_IsPerspective = true, float i_NearPlane = 0.1f, float i_FarPlane = 100.0f);

		void inline ResizeViewport(vec2i& vpSize) { aspectRatio = vpSize.x / (float)vpSize.y; }
		void inline ResizeViewport(int width, int height) { aspectRatio = width / (float)height; }

		inline mat4 GetViewProjMatrix() { return mul(viewMatrix, projMatrix); }

		float fov;
		float aspectRatio;  // Width : height ratio
		bool isPerspective;
		vec2 farNear;

		mat4 viewMatrix;  // Save the matrix to avoid repeated calculation
		mat4 projMatrix;  // Save the matrix to avoid repeated calculation
	};
}
