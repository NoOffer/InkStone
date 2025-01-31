#pragma once

#include "src/Rendering/Renderer.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace NXTN {
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer() {}

		virtual void DrawMeshImpl(const std::shared_ptr<const Mesh>& mesh) override;

		virtual void ResizeViewportImpl(int width, int height) override;

		virtual void SetClearColorImpl(float r, float g, float b) override;
		virtual void ClearFrameBufferImpl() override;
	};
}

