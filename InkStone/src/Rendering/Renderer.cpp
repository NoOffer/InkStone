#include "pch.h"

#include "OpenGL/OpenGLRenderer.h"

namespace NXTN {
	Renderer* Renderer::Create(GraphicsAPI api)
	{
		switch (api)
		{
		case GraphicsAPI::None:
			Log::Error("Invalid API");
			break;
		case GraphicsAPI::OpenGL:
			return (Renderer*) new OpenGLRenderer();
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}