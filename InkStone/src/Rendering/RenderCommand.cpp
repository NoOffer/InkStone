#include "pch.h"

#include "RenderCommand.h"

namespace NXTN {
	std::unique_ptr<Renderer> RenderCommand::s_Renderer = nullptr;

	void RenderCommand::InitRenderer(GraphicsAPI api)
	{
		s_Renderer.reset(Renderer::Create(api));
	}

	GraphicsAPI RenderCommand::GetGraphicsAPI()
	{
		if (s_Renderer) return s_Renderer->GetGraphicsAPI();

		return GraphicsAPI::None;
	}

	void RenderCommand::SetClearColor(float r, float g, float b)
	{
		if (!s_Renderer)
		{
			s_Renderer->SetClearColor(r, g, b);
		}
		else
		{
			Log::Warning("No renderer initialized");
		}
	}

	void RenderCommand::ClearFrameBuffer()
	{
		if (!s_Renderer)
		{
			s_Renderer->ClearFrameBuffer();
		}
		else
		{
			Log::Warning("No renderer initialized");
		}
	}
}
