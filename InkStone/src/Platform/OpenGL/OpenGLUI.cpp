#include "pch.h"

#include "OpenGLUI.h"

#include "src/Keycode.h"

namespace NXTN {
	OpenGLUI::OpenGLUI(const std::shared_ptr<Window>& window)
		: m_Window(window)
	{
		ImGui::CreateContext();

		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		if (io.BackendRendererUserData == nullptr)
		{
			ImGui_ImplOpenGL3_Init("#version 410");
		}

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.DisplaySize = ImVec2(m_Window->GetWidth(), m_Window->GetHeight());

		io.KeyMap[ImGuiMouseButton_Left] = NXTN_MOUSE_BUTTON_LEFT;
		io.KeyMap[ImGuiMouseButton_Right] = NXTN_MOUSE_BUTTON_RIGHT;
		io.KeyMap[ImGuiMouseButton_Middle] = NXTN_MOUSE_BUTTON_MIDDLE;
		io.KeyMap[ImGuiKey_Tab] = NXTN_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = NXTN_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = NXTN_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = NXTN_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = NXTN_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = NXTN_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = NXTN_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = NXTN_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = NXTN_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = NXTN_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = NXTN_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = NXTN_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = NXTN_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = NXTN_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = NXTN_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = NXTN_KEY_A;  // Map for Ctrl+A
		io.KeyMap[ImGuiKey_C] = NXTN_KEY_C;  // Map for Ctrl+C
		io.KeyMap[ImGuiKey_V] = NXTN_KEY_V;  // Map for Ctrl+V
		io.KeyMap[ImGuiKey_X] = NXTN_KEY_X;  // Map for Ctrl+X
		io.KeyMap[ImGuiKey_Y] = NXTN_KEY_Y;  // Map for Ctrl+Y
		io.KeyMap[ImGuiKey_Z] = NXTN_KEY_Z;  // Map for Ctrl+Z
	}

	void OpenGLUI::OnEventImpl(Event& event)
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
			int mouseBtnCode = (*(MouseButtonPressEvent*)&event).GetButton();
			if (mouseBtnCode < NXTN_MOUSE_BUTTON_3)  // ImGui mostly uses left, right, and middle button only. Setting other buttons could cause problem
				io.MouseDown[mouseBtnCode] = true;
			break;
		}
		case EventType::MouseButtonReleased:
		{
			int mouseBtnCode = (*(MouseButtonPressEvent*)&event).GetButton();
			if (mouseBtnCode < NXTN_MOUSE_BUTTON_3)  // ImGui mostly uses left, right, and middle button only. Setting other buttons could cause problem
				io.MouseDown[mouseBtnCode] = false;
			break;
		}
		case EventType::MouseMove:
		{
			MouseMoveEvent e = *(MouseMoveEvent*)&event;
			io.MousePos = ImVec2(e.GetX(), e.GetY());
			break;
		}
		case EventType::MouseScroll:
		{
			MouseScrollEvent e = *(MouseScrollEvent*)&event;
			io.MouseWheelH += e.GetX();
			io.MouseWheel += e.GetY();
			break;
		}
		}

		return;
	}

	void OpenGLUI::BeginImpl(const char* windowName)
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin(windowName /*, 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize*/);
	}

	void OpenGLUI::EndImpl()
	{
		// FPS
		float deltaTime = Time::GetDeltaTime();
		ImGui::Text("FPS: %.0f  (Avg %.2fms/frame)", 1000.0f / deltaTime, deltaTime * 1000.0f);

		// End
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}