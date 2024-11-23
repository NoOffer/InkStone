#include "pch.h"

#include "OpenGLUI.h"

namespace NXTN {
	OpenGLUI::OpenGLUI(const std::shared_ptr<Window>& window, const std::string& name)
		: m_Window(window)
	{
		m_WindowTitle = name + " (OpenGL)";

		ImGui::CreateContext();

		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init("#version 410");

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(m_Window->GetWidth(), m_Window->GetHeight());
	}

	bool OpenGLUI::OnEvent(Event& event)
	{
		ImGuiIO& io = ImGui::GetIO();

		switch (event.GetEventType())
		{
		case EventType::WindowResized:
		{
			io.DisplaySize = ImVec2(m_Window->GetWidth(), m_Window->GetHeight());
			break;
		}
		case EventType::KeyPressed:
			break;
		case EventType::KeyReleased:
			break;
		case EventType::MouseButtonPressed:
		{
			MouseButtonPressEvent mouseBtnPressEvent = *(MouseButtonPressEvent*)&event;
			io.MouseDown[mouseBtnPressEvent.GetButton()] = true;
			break;
		}
		case EventType::MouseButtonReleased:
		{
			MouseButtonPressEvent mouseBtnReleaseEvent = *(MouseButtonPressEvent*)&event;
			io.MouseDown[mouseBtnReleaseEvent.GetButton()] = false;
			break;
		}
		case EventType::MouseMove:
		{
			MouseMoveEvent mouseMoveEvent = *(MouseMoveEvent*)&event;
			io.MousePos = ImVec2(mouseMoveEvent.GetX(), mouseMoveEvent.GetY());
			break;
		}
		case EventType::MouseScroll:
		{
			MouseScrollEvent mouseScrollEvent = *(MouseScrollEvent*)&event;
			io.MouseWheel = mouseScrollEvent.GetX();
			break;
		}
		}

		return false;
	}

	void OpenGLUI::Update()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin(m_WindowTitle.c_str() /*, 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize*/);

		float deltaTime = Time::GetDeltaTime();
		ImGui::Text("FPS: %.0f  (Avg %.2fms/frame)", 1000.0f / deltaTime, deltaTime * 1000.0f);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}