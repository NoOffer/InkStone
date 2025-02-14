#include "pch.h"

#include "CameraController.h"

#include "src/Game/Component/Transform.h"
#include "src/Game/Component/Camera.h"

#include "src/Rendering/Renderer.h"

namespace NXTN {
	void CameraController::Update(entt::registry& scene)
	{
		auto view = scene.view<Camera, Transform>();
		for (const entt::entity& entity : view)
		{
			Camera& camera = view.get<Camera>(entity);
			Transform& transform = view.get<Transform>(entity);

			// View matrix
			vec3 position = transform.GetPosition();

			// Z should be, but is not, negated for OpenGL
			vec3 z(normalize(-position));  // Look direction
			vec3 x(normalize(vec3(z.z, 0.0f, -z.x)));  // Cross((0, 1, 0), z)
			vec3 y(normalize(cross(z, x)));

			camera.viewMatrix = mat4(
				x.x, x.y, x.z, -dot(x, position),
				y.x, y.y, y.z, -dot(y, position),
				z.x, z.y, z.z, -dot(z, position),
				0.0f, 0.0f, 0.0f, 1.0f
			);

			// Proj matrix
			if (camera.isPerspective)  // Perspective
			{
				camera.projMatrix = mat4();
			}
			else  // Orthogonal
			{
				// m22 should be, but is not, negated for OpenGL
				camera.projMatrix = mat4(
					1 / camera.fov / camera.aspectRatio, 0.0f, 0.0f, 0.0f,
					0.0f, 1 / camera.fov, 0.0f, 0.0f,
					0.0f, 0.0f, 2.0f / (camera.farNear.x - camera.farNear.y), -(camera.farNear.x + camera.farNear.y) / (camera.farNear.x - camera.farNear.y),
					0.0f, 0.0f, 0.0f, 1.0f
				);
			}
		}
	}
}
