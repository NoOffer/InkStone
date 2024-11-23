#include "pch.h"

#include "Platform/OpenGL/OpenGLUI.h"

namespace NXTN {
	Layer* UI::Create(const std::shared_ptr<Window>& window, const std::string& name)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return (Layer*) new OpenGLUI(window, name);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}
