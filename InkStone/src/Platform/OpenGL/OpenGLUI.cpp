#include "pch.h"

#include "OpenGLUI.h"

namespace NXTN {
	OpenGLUI::OpenGLUI(const std::shared_ptr<Window>& window, const std::string& name)
		: UI(name + " (OpenGL)"), m_Window(window)
	{
		m_Name = name + " (OpenGL)";

		ImGui::CreateContext();

		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void OpenGLUI::Update()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(m_Window->GetWidth(), m_Window->GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin(m_Name.c_str() /*, 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize*/);

		float deltaTime = Time::GetDeltaTime();
		ImGui::Text("FPS: %.0f  (Avg %.2fms/frame)", 1000.0f / deltaTime, deltaTime * 1000.0f);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}