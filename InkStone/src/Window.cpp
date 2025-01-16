#include "pch.h"

#include "Platform/OpenGL/OpenGLWindow.h"

namespace NXTN {
	Window* Window::Create(std::string title)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return new OpenGLWindow(title);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}