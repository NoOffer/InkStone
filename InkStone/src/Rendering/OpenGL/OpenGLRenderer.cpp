#include "pch.h"

#include "OpenGLRenderer.h"

namespace NXTN {
	OpenGLRenderer::OpenGLRenderer()
	{
		glEnable(GL_BLEND);
		// Blend function: newColor = inColor * a + bgColor * (1 - a)
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderer::DrawMeshImpl(const Mesh& mesh)
	{
		mesh.Bind();
		glDrawElements(GL_TRIANGLES, mesh.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
		mesh.Unbind();
	}

	void OpenGLRenderer::ResizeViewportImpl(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void OpenGLRenderer::SetClearColorImpl(float r, float g, float b)
	{
		glClearColor(r, g, b, 1.0f);
	}

	void OpenGLRenderer::ClearFrameBufferImpl()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
}
