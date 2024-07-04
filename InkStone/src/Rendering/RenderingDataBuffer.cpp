#include "pch.h"

#include "OpenGL/OpenGLDataBuffer.h"

namespace NXTN {
	VertexBuffer* VertexBuffer::Create(const float* vertices, const unsigned int count)
	{
		switch (Renderer::GetRenderingAPI())
		{
		case RenderingAPI::None:
			Log::Error("No rendering API specified");
			break;
		case RenderingAPI::OpenGL:
			return (VertexBuffer*) new OpenGLVertexBuffer(vertices, count);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(const unsigned int* indices, const unsigned int count)
	{
		switch (Renderer::GetRenderingAPI())
		{
		case RenderingAPI::None:
			Log::Error("No rendering API specified");
			break;
		case RenderingAPI::OpenGL:
			return (IndexBuffer*) new OpenGLIndexBuffer(indices, count);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}