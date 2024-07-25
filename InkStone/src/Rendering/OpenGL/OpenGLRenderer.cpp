#include "pch.h"

#include "OpenGLRenderer.h"

namespace NXTN {
	OpenGLRenderer::OpenGLRenderer()
	{
		// GLFW initialization
		if (glfwInit())
		{
			Log::Info("GLFW initialized");
		}
		else
		{
			Log::Error("Failed to initialize GLFW");
			NXTN_ERROR;
		}
	}

	void OpenGLRenderer::DrawMesh(const Mesh& mesh)
	{
		mesh.Bind();
		glDrawElements(GL_TRIANGLES, mesh.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
		mesh.Unbind();
	}

	void OpenGLRenderer::SetClearColor(float r, float g, float b)
	{
		glClearColor(r, g, b, 1.0f);
	}

	void OpenGLRenderer::ClearFrameBuffer()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
}
