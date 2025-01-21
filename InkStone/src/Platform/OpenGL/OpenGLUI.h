#pragma once

#include "src/UI.h"

#include "ImGuiBackend/imgui_impl_glfw.h"
#include "ImGuiBackend/imgui_impl_opengl3.h"

namespace NXTN {
	class OpenGLUI : public UI
	{
	public:
		OpenGLUI(const std::shared_ptr<Window>& window);
		~OpenGLUI() {}

		virtual void BeginImpl() override;
		virtual void EndImpl() override;
		virtual void OnEventImpl(Event& event) override;

	private:
		const std::shared_ptr<Window>& m_Window;

		ImGuiID m_DockspaceID;
	};
}