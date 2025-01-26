#include "InkStoneEditor.h"

namespace NXTN {
	// Editor Layer
	EditorLayer::EditorLayer(unsigned int windowWidth, unsigned int windowHeight)
	{
		m_Name = "Sandbox Gameplay Layer";

		// Camera
		m_Camera.reset(new NXTN::Camera(1.0f, NXTN::vec2i(windowWidth, windowHeight), false));
		m_Camera->transform.SetPosition(0.0f, 0.0f, -10.0f);

		m_FrameBuffer.reset(NXTN::FrameBuffer::Create(windowWidth, windowHeight));

		// Temporary draw data
		// Vertex buffer
		// 1 3
		// 0 2
		float vertices[20] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f
		};

		// Vertex array layout
		NXTN::VertexArrayLayout layout({
			{NXTN::VertexDataType::Float, 3, "Vertex Position"},
			{NXTN::VertexDataType::Float, 2, "Texture Coordinate"}
			});

		// Index buffer
		unsigned int indices[6] = {
			0, 1, 3,
			0, 3, 2
		};

		//Mesh
		m_Mesh.reset(
			new NXTN::Mesh(
				NXTN::VertexArray::Create(NXTN::VertexBuffer::Create(vertices, 20), layout),
				NXTN::IndexBuffer::Create(indices, 6)
			)
		);

		m_Shader.reset(NXTN::Shader::Create("Asset/Shader/Texture.glsl"));

		m_Texture.reset(NXTN::Texture2D::Create("Asset/Texture/Logo.png"));

		// UI config
		// Create dockspace
		UI::NewFrame();
		m_DockspaceID = ImGui::GetID("MainDockSpace");
		UI::EndFrame();
		// Window flag
		m_WindowFlag =
			ImGuiWindowFlags_MenuBar |
			ImGuiWindowFlags_NoDocking |
			ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBringToFrontOnFocus |
			ImGuiWindowFlags_NoNavFocus;
	}

	void EditorLayer::Update()
	{
		m_FrameBuffer->Bind();
		// Rendering
		NXTN::Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

		NXTN::Renderer::ClearFrameBuffer();

		m_Shader->Bind();
		m_Shader->SetUniformMat4("u_ModelMatrix", m_Mesh->transform.GetModelMatrix());
		m_Shader->SetUniformMat4("u_VPMatrix", m_Camera->GetViewProjMatrix());

		m_Texture->Bind(0);
		m_Shader->SetUniformInt("u_MainTex", 0);

		NXTN::Renderer::DrawMesh(*m_Mesh);

		m_FrameBuffer->Unbind();
	}

	void EditorLayer::UIUpdate()
	{
		// Prepare dockspace
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
		ImGui::Begin("Dockspace", NULL, m_WindowFlag);
		{
			ImGui::PopStyleVar(3);

			// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render the background and handle pass-thru holes, so Begin() should not render a background.
			ImGui::DockSpace(m_DockspaceID, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None /*ImGuiWindowFlags_NoBackground*/);

			// View window
			ImGui::SetNextWindowDockID(m_DockspaceID, ImGuiCond_FirstUseEver);
			ImGui::Begin("View", NULL, ImGuiWindowFlags_NoCollapse);
			{
				// ImGui::Image defines uv0 and uv1 as the top-left and the bottom-right corner
				// While OpenGL defines uv0 and uv1 as the bottom-left and the top-right corner
				// The uv0 and uv1 parameters are manully set to fix this
				ImGui::Image((ImTextureID)(intptr_t)m_FrameBuffer->GetHandle(), ImVec2(1024.0f, 576.0f), ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
			}
			ImGui::End();

			// FPS
			ImGui::SetNextWindowDockID(m_DockspaceID, ImGuiCond_FirstUseEver);
			ImGui::Begin("Scene Info", NULL, ImGuiWindowFlags_NoCollapse);
			{
				float deltaTime = Time::GetDeltaTime();
				ImGui::Text("FPS: %.0f  (Avg %.2fms/frame)", 1000.0f / deltaTime, deltaTime * 1000.0f);

			}
			ImGui::End();

		}
		ImGui::End();
	}

	bool EditorLayer::OnEvent(NXTN::Event& event)
	{
		if (event.GetEventType() == NXTN::EventType::WindowResized)
		{
			NXTN::WindowResizeEvent e = *(NXTN::WindowResizeEvent*)(&event);
			std::cout << e.GetNewWidth() << ", " << e.GetNewHeight() << std::endl;
			m_Camera->ResizeViewport(e.GetNewWidth(), e.GetNewHeight());
		}
		return false;
	}

	// Sandbox Application
	InkStoneEditor::InkStoneEditor()
		: Application()
	{
		m_LayerStack.PushLayer(new EditorLayer(m_Window->GetWidth(), m_Window->GetHeight()));
	}

	void InkStoneEditor::Update()
	{
		Application::Update();
	}

	Application* CreateApplication()
	{
		return new InkStoneEditor();
	}
}