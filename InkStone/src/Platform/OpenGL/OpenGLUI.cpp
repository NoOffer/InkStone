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

		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking

		io.DisplaySize = ImVec2(m_Window->GetWidth(), m_Window->GetHeight());

		if (io.BackendRendererUserData == nullptr)
		{
			ImGui_ImplOpenGL3_Init("#version 410");
		}

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;  // Enable cursor functionalities defined by backend
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;  // Allow manually setting cursor position

		// Per ImGui documentation, the docking branch of ImGui seems to not accept custom KeyMap
		//io.KeyMap[ImGuiMouseButton_Left] = NXTN_MOUSE_BUTTON_LEFT;
		//io.KeyMap[ImGuiMouseButton_Right] = NXTN_MOUSE_BUTTON_RIGHT;
		//io.KeyMap[ImGuiMouseButton_Middle] = NXTN_MOUSE_BUTTON_MIDDLE;
		//io.KeyMap[ImGuiKey_Tab] = NXTN_KEY_TAB;
		//io.KeyMap[ImGuiKey_LeftArrow] = NXTN_KEY_LEFT;
		//io.KeyMap[ImGuiKey_RightArrow] = NXTN_KEY_RIGHT;
		//io.KeyMap[ImGuiKey_UpArrow] = NXTN_KEY_UP;
		//io.KeyMap[ImGuiKey_DownArrow] = NXTN_KEY_DOWN;
		//io.KeyMap[ImGuiKey_PageUp] = NXTN_KEY_PAGE_UP;
		//io.KeyMap[ImGuiKey_PageDown] = NXTN_KEY_PAGE_DOWN;
		//io.KeyMap[ImGuiKey_Home] = NXTN_KEY_HOME;
		//io.KeyMap[ImGuiKey_End] = NXTN_KEY_END;
		//io.KeyMap[ImGuiKey_Insert] = NXTN_KEY_INSERT;
		//io.KeyMap[ImGuiKey_Delete] = NXTN_KEY_DELETE;
		//io.KeyMap[ImGuiKey_Backspace] = NXTN_KEY_BACKSPACE;
		//io.KeyMap[ImGuiKey_Space] = NXTN_KEY_SPACE;
		//io.KeyMap[ImGuiKey_Enter] = NXTN_KEY_ENTER;
		//io.KeyMap[ImGuiKey_Escape] = NXTN_KEY_ESCAPE;
		//io.KeyMap[ImGuiKey_A] = NXTN_KEY_A;  // Map for Ctrl+A
		//io.KeyMap[ImGuiKey_C] = NXTN_KEY_C;  // Map for Ctrl+C
		//io.KeyMap[ImGuiKey_V] = NXTN_KEY_V;  // Map for Ctrl+V
		//io.KeyMap[ImGuiKey_X] = NXTN_KEY_X;  // Map for Ctrl+X
		//io.KeyMap[ImGuiKey_Y] = NXTN_KEY_Y;  // Map for Ctrl+Y
		//io.KeyMap[ImGuiKey_Z] = NXTN_KEY_Z;  // Map for Ctrl+Z
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
			io.MouseDown[mouseBtnCode] = true;
			break;
		}
		case EventType::MouseButtonReleased:
		{
			int mouseBtnCode = (*(MouseButtonPressEvent*)&event).GetButton();
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

	void OpenGLUI::BeginImpl()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		// Prepare dockspace
		ImGuiWindowFlags window_flags = 
			ImGuiWindowFlags_MenuBar |
			ImGuiWindowFlags_NoDocking |
			ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBringToFrontOnFocus|
			ImGuiWindowFlags_NoNavFocus;

		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		// Note: Do not abort even if Begin() returns false (aka window is collapsed)
		// Since dockspace should remain active, otherwise all active windows docked into it will lose their parent and become undocked.
		// Note: Even though dockspace has no titlebar, ImGui requires a non-empty (not "") title for each window
		ImGui::Begin("Dockspace", NULL, window_flags);
		ImGui::PopStyleVar(3);

		// Create dockspace
		m_DockspaceID = ImGui::GetID("MainDockSpace");
		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render the background and handle pass-thru holes, so Begin() should not render a background.
		ImGui::DockSpace(m_DockspaceID, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None /*ImGuiWindowFlags_NoBackground*/);
	}

	void OpenGLUI::EndImpl()
	{
		// FPS
		ImGui::SetNextWindowDockID(m_DockspaceID, ImGuiCond_FirstUseEver);
		ImGui::Begin("Scene Info", NULL, ImGuiWindowFlags_NoCollapse);
		float deltaTime = Time::GetDeltaTime();
		ImGui::Text("FPS: %.0f  (Avg %.2fms/frame)", 1000.0f / deltaTime, deltaTime * 1000.0f);
		ImGui::End();

		// End
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}