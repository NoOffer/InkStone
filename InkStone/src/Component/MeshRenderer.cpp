#include "pch.h"

#include "MeshRenderer.h"

namespace NXTN {
	MeshRenderer::MeshRenderer(Mesh* mesh)
		: m_Mesh(mesh)
	{

	}

	void MeshRenderer::Update()
	{
		Renderer::DrawMesh(m_Mesh);
	}
}
