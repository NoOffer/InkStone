#include "pch.h"

#include "Platform/GLFW/GLFWWindow.h"

namespace NXTN {
	Window* Window::Create(unsigned int width, unsigned int height, std::string title)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return new OpenGLWindow(width, height, title);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}