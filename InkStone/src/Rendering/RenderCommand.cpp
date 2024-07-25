#include "pch.h"

#include "RenderCommand.h"

namespace NXTN {
	std::unique_ptr<Renderer> RenderCommand::s_Renderer = nullptr;

	void RenderCommand::Init()
	{
		s_Renderer.reset(Renderer::Create(System::GetGraphicsAPI()));
	}

	void RenderCommand::DrawMesh(const Mesh& mesh)
	{
		if (s_Renderer)
		{
			s_Renderer->DrawMesh(mesh);
		}
		else
		{
			Log::Warning("No renderer initialized");
		}
	}

	void RenderCommand::SetClearColor(float r, float g, float b)
	{
		if (s_Renderer)
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
		if (s_Renderer)
		{
			s_Renderer->ClearFrameBuffer();
		}
		else
		{
			Log::Warning("No renderer initialized");
		}
	}
}
