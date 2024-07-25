#pragma once

#include "Rendering/Renderer.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace NXTN {
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer() {}

		virtual void DrawMesh(const Mesh& mesh) override;

		virtual void SetClearColor(float r, float g, float b) override;
		virtual void ClearFrameBuffer() override;
	};
}

