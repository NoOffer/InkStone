#include "SandboxApp.h"

// Sandbox Layer
SandboxLayer::SandboxLayer(unsigned int windowWidth, unsigned int windowHeight)
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
}

void SandboxLayer::Update()
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

void SandboxLayer::UIUpdate()
{
	NXTN::UI::ViewWindow(m_FrameBuffer->GetHandle());
}

bool SandboxLayer::OnEvent(NXTN::Event& event)
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
Sandbox::Sandbox()
	: Application()
{
	m_LayerStack.PushLayer(new SandboxLayer(m_Window->GetWidth(), m_Window->GetHeight()));
}

void Sandbox::Update()
{
	Application::Update();
}

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}