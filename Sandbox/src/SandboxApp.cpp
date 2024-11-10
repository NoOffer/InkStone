#include "SandboxApp.h"

// Sandbox Layer
SandboxLayer::SandboxLayer()
{
	m_Name = "Sandbox Gameplay Layer";

	// Camera
	m_Camera.reset(new NXTN::Camera(1.0f, NXTN::vec2i(500, 500), false));
	m_Camera->transform.SetPosition(0.0f, 0.0f, -10.0f);

	// Temporary draw data
	std::shared_ptr<NXTN::VertexBuffer> vertexBuffer;

	// Vertex buffer
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};
	vertexBuffer.reset(NXTN::VertexBuffer::Create(vertices, 9));

	// Vertex array layout
	NXTN::VertexArrayLayout layout{ {NXTN::VertexDataType::Float, 3, "Vertex Position"} };

	// Index buffer
	unsigned int indices[3] = { 0, 1, 2 };

	//Mesh
	m_Mesh.reset(new NXTN::Mesh(NXTN::VertexArray::Create(vertexBuffer, layout), NXTN::IndexBuffer::Create(indices, 3)));

	// Shader
	std::string vertShaderSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_PositionOS;

			uniform mat4 u_ModelMatrix;
			uniform mat4 u_VPMatrix;

			out vec3 v_PositionOS;

			void main()
			{
				v_PositionOS = a_PositionOS;

				gl_Position = u_VPMatrix * u_ModelMatrix * vec4(a_PositionOS, 1);
			}
		)";

	std::string fragShaderSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_PositionOS;

			void main()
			{
				color = vec4(v_PositionOS + 0.5, 1.0);
			}
		)";
	m_Shader.reset(NXTN::Shader::Create(vertShaderSrc, fragShaderSrc));
}

void SandboxLayer::Update()
{
	// Rendering
	NXTN::Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

	NXTN::Renderer::ClearFrameBuffer();

	m_Shader->Bind();
	m_Shader->SetUniformMat4("u_ModelMatrix", m_Mesh->transform.GetModelMatrix());
	m_Shader->SetUniformMat4("u_VPMatrix", m_Camera->GetViewProjMatrix());

	NXTN::Renderer::DrawMesh(*m_Mesh);
}

void SandboxLayer::Dispatch(NXTN::Event& event)
{

}

// Sandbox Application
Sandbox::Sandbox()
	: Application()
{
	m_LayerStack.PushLayer(new SandboxLayer());
	m_LayerStack.PushLayer(NXTN::UI::Create(m_Window, "Test Window"));
}

void Sandbox::Update()
{
	Application::Update();
}

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}