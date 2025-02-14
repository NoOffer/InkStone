#pragma once

#include "GameComponent.h"

#include "src/Rendering/Renderer.h"

namespace NXTN {
	class MeshInfo : public GameComponent
	{
	public:
		MeshInfo() {}
		MeshInfo(Mesh* mesh, Shader* shader) : mesh(mesh), shader(shader) {}
		~MeshInfo() {}

	public:
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Shader> shader;
	};
}
