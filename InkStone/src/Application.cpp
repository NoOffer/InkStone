#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application::Application()
	{
		Renderer::Init();

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		// Camera
		Camera camera(1.0f, vec2i(500, 500), false);
		camera.transform.SetPosition(0.0f, 0.0f, -10.0f);

		// Temporary draw data
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Shader> shader;

		// Vertex buffer
		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};
		vertexBuffer.reset(VertexBuffer::Create(vertices, 9));

		// Vertex array layout
		VertexArrayLayout layout{ {ShaderDataType::Float, 3, "Vertex Position"} };

		// Index buffer
		unsigned int indices[3] = { 0, 1, 2 };

		//Mesh
		mesh.reset(new Mesh(VertexArray::Create(vertexBuffer, layout), IndexBuffer::Create(indices, 3)));

		// Shader
		std::string vertShaderSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_PositionOS;

			uniform mat4 u_VPMatrix;

			out vec3 v_PositionOS;

			void main()
			{
				v_PositionOS = a_PositionOS;

				gl_Position = u_VPMatrix * vec4(a_PositionOS, 1);
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
		shader.reset(Shader::Create(vertShaderSrc, fragShaderSrc));

		// ------------------------------------------------------------------------------------------------------------------ Game loop
		while (!m_Paused)
		{
			m_LayerStack.Update();

			// Rendering
			Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

			Renderer::ClearFrameBuffer();

			shader->Bind();
			shader->SetUniformMat4("u_VPMatrix", camera.GetViewProjMatrix());

			Renderer::DrawMesh(*mesh);

			m_Window->Update();
		}
		// ------------------------------------------------------------------------------------------------------------------ Game loop
	}
}