#include "pch.h"

#include "Platform/OpenGL/OpenGLUI.h"

namespace NXTN {
	std::unique_ptr<UI> UI::s_UI = nullptr;

	void UI::Init(const std::shared_ptr<Window>& window)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			s_UI.reset(new OpenGLUI(window));
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return;
	}

	void UI::Begin()
	{
		NXTN_PROFILE_FUNCTION()

		if (!s_UI)
		{
			Log::Warning("UI uninitialized");
			return;
		}
		s_UI->BeginImpl();
	}

	void UI::End()
	{
		NXTN_PROFILE_FUNCTION()

		if (!s_UI)
		{
			Log::Warning("UI uninitialized");
			return;
		}
		s_UI->EndImpl();
	}

	void UI::OnEvent(Event& event)
	{
		if (!s_UI)
		{
			Log::Warning("UI uninitialized");
			return;
		}
		s_UI->OnEventImpl(event);
	}
}
