#pragma once

#include "Component.h"

#include "src/Rendering/Renderer.h"

namespace NXTN {
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer(Mesh* mesh);
		~MeshRenderer() {}

		virtual void Update() override;

	private:
		std::shared_ptr<const Mesh> m_Mesh;
	};
}
