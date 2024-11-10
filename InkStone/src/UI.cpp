#include "pch.h"

#include "Platform/OpenGL/OpenGLUI.h"

namespace NXTN {
	UI* UI::Create(const std::shared_ptr<Window>& window, const std::string& name)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return (UI*) new OpenGLUI(window, name);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}
