#include "SandboxApp.h"

// Sandbox Layer
SandboxLayer::SandboxLayer()
{
	m_Name = "Sandbox Gameplay Layer";

	// Camera
	m_Camera.reset(new NXTN::Camera(1.0f, NXTN::vec2i(500, 500), false));
	m_Camera->transform.SetPosition(0.0f, 0.0f, -10.0f);

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

	// Shader
	std::string vertShaderSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_PositionOS;
			layout(location = 1) in vec2 a_TexCoord;

			uniform mat4 u_ModelMatrix;
			uniform mat4 u_VPMatrix;

			out vec2 v_TexCoord;

			void main()
			{
				v_TexCoord = a_TexCoord;

				gl_Position = u_VPMatrix * u_ModelMatrix * vec4(a_PositionOS, 1);
			}
		)";

	std::string fragShaderSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec2 v_TexCoord;

			uniform sampler2D u_MainTex;

			void main()
			{
				color = texture(u_MainTex, v_TexCoord);
			}
		)";
	m_Shader.reset(NXTN::Shader::Create("Asset/Shader/Texture.glsl"));

	m_Texture.reset(NXTN::Texture2D::Create("Asset/Texture/Logo.png"));
}

void SandboxLayer::Update()
{
	// Rendering
	NXTN::Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

	NXTN::Renderer::ClearFrameBuffer();

	m_Shader->Bind();
	m_Shader->SetUniformMat4("u_ModelMatrix", m_Mesh->transform.GetModelMatrix());
	m_Shader->SetUniformMat4("u_VPMatrix", m_Camera->GetViewProjMatrix());

	m_Texture->Bind(0);
	m_Shader->SetUniformInt("u_MainTex", 0);

	NXTN::Renderer::DrawMesh(*m_Mesh);
}

bool SandboxLayer::OnEvent(NXTN::Event& event)
{
	if (event.GetEventType() == NXTN::EventType::WindowResized)
	{
		NXTN::WindowResizeEvent e = *(NXTN::WindowResizeEvent*)(&event);
		m_Camera->ResizeViewport(e.GetNewWidth(), e.GetNewHeight());
	}
	return false;
}

// Sandbox Application
Sandbox::Sandbox()
	: Application()
{
	m_LayerStack.PushLayer(new SandboxLayer());
}

void Sandbox::Update()
{
	Application::Update();
}

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}