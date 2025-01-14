#pragma once

#include "src/UI.h"

#include "ImGuiBackend/imgui_impl_opengl3.h"

namespace NXTN {
	class OpenGLUI : public UI
	{
	public:
		OpenGLUI(const std::shared_ptr<Window>& window, const char* name);
		~OpenGLUI() {}

		virtual bool OnEvent(Event& event) override;
		virtual void Update() override;

	private:
		const std::shared_ptr<Window>& m_Window;

		const char* m_WindowTitle;
	};
}