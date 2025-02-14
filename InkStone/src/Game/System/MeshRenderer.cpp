#include "pch.h"

#include "MeshRenderer.h"

#include "src/Game/Component/Transform.h"
#include "src/Game/Component/MeshInfo.h"

#include "src/Rendering/Renderer.h"

namespace NXTN {
	void MeshRenderer::Update(entt::registry& scene)
	{
		//scene.view<MeshInfo, Transform>().each(
		//	[](MeshInfo& meshInfo, Transform& transform)
		//	{
		//		Renderer::DrawMesh(meshInfo.mesh, meshInfo.shader, transform.GetModelMatrix());
		//	}
		//);

		auto view = scene.view<MeshInfo, Transform>();
		for (const entt::entity& entity : view)
		{
			MeshInfo& meshInfo = view.get<MeshInfo>(entity);
			Transform& transform = view.get<Transform>(entity);

			Renderer::DrawMesh(meshInfo.mesh, meshInfo.shader, transform.GetModelMatrix());
		}
	}
}
