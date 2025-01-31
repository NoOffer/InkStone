#include "pch.h"

#include "OpenGL/OpenGLRenderer.h"

namespace NXTN {
	std::unique_ptr<Renderer> Renderer::s_Renderer = nullptr;

	void Renderer::Init()
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("Invalid API");
			break;
		case GraphicsAPI::OpenGL:
			s_Renderer.reset(new OpenGLRenderer());
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}
	}

	void Renderer::DrawMesh(const std::shared_ptr<const Mesh>& mesh)
	{
		if (!s_Renderer)
		{
			Log::Warning("Renderer not initialized");
			return;
		}
		s_Renderer->DrawMeshImpl(mesh);
	}

	void Renderer::ResizeViewport(int width, int height)
	{
		if (!s_Renderer)
		{
			Log::Warning("Renderer not initialized");
			return;
		}
		s_Renderer->ResizeViewportImpl(width, height);
	}

	void Renderer::SetClearColor(float r, float g, float b)
	{
		if (!s_Renderer)
		{
			Log::Warning("Renderer not initialized");
			return;
		}
		s_Renderer->SetClearColorImpl(r, g, b);
	}

	void Renderer::ClearFrameBuffer()
	{
		if (!s_Renderer)
		{
			Log::Warning("Renderer not initialized");
			return;
		}
		s_Renderer->ClearFrameBufferImpl();
	}

	//Renderer* Renderer::Create(GraphicsAPI api)
	//{
	//	switch (api)
	//	{
	//	case GraphicsAPI::None:
	//		Log::Error("Invalid API");
	//		break;
	//	case GraphicsAPI::OpenGL:
	//		return (Renderer*) new OpenGLRenderer();
	//	default:
	//		Log::Error("Unsupported rendering API");
	//		break;
	//	}

	//	return nullptr;
	//}
}