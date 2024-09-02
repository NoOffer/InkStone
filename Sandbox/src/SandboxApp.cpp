#include "SandboxApp.h"

Sandbox::Sandbox()
{

}

void Sandbox::Run()
{
	// Camera
	NXTN::Camera camera(1.0f, NXTN::vec2i(500, 500), false);
	camera.transform.SetPosition(0.0f, 0.0f, -10.0f);

	// Temporary draw data
	std::shared_ptr<NXTN::VertexBuffer> vertexBuffer;
	std::shared_ptr<NXTN::Mesh> mesh;
	std::shared_ptr<NXTN::Shader> shader;

	// Vertex buffer
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};
	vertexBuffer.reset(NXTN::VertexBuffer::Create(vertices, 9));

	// Vertex array layout
	NXTN::VertexArrayLayout layout{ {NXTN::ShaderDataType::Float, 3, "Vertex Position"} };

	// Index buffer
	unsigned int indices[3] = { 0, 1, 2 };

	//Mesh
	mesh.reset(new NXTN::Mesh(NXTN::VertexArray::Create(vertexBuffer, layout), NXTN::IndexBuffer::Create(indices, 3)));

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
	shader.reset(NXTN::Shader::Create(vertShaderSrc, fragShaderSrc));

	// ---------------------------------------------------------------------------------------------------------------- Game loop
	while (true)
	{
		// Rendering
		NXTN::Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

		NXTN::Renderer::ClearFrameBuffer();

		shader->Bind();
		shader->SetUniformMat4("u_ModelMatrix", mesh->transform.GetModelMatrix());
		shader->SetUniformMat4("u_VPMatrix", camera.GetViewProjMatrix());

		NXTN::Renderer::DrawMesh(*mesh);

		m_Window->Update();
	}
	// ---------------------------------------------------------------------------------------------------------------- Game loop
}

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}