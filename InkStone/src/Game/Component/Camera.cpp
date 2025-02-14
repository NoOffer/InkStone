#include "pch.h"

#include "Camera.h"

namespace NXTN {
	void Camera::Init(float i_Fov, vec2i i_Resolution, bool i_IsPerspective, float i_NearPlane, float i_FarPlane)
	{
		fov = i_Fov;
		isPerspective = i_IsPerspective;
		farNear.x = i_FarPlane;
		farNear.y = i_NearPlane;

		aspectRatio = i_Resolution.x / (float)i_Resolution.y;

		farNear.y = max(farNear.y, 0.01f);
		farNear.x = max(farNear.x, farNear.y);
	}
}
