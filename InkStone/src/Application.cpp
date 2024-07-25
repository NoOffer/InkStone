#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application::Application()
	{
		RenderCommand::InitRenderer(GraphicsAPI::OpenGL);

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		// Temporary draw data
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<Shader> shader;

		// Vertex buffer
		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};
		vertexBuffer.reset(VertexBuffer::Create(vertices, 9));

		// Vertex array
		VertexArrayLayout layout{ {ShaderDataType::Float, 3, "Vertex Position"} };
		vertexArray.reset(VertexArray::Create(vertexBuffer, layout));

		// Index buffer
		unsigned int indices[3] = { 0, 1, 2 };
		indexBuffer.reset(IndexBuffer::Create(indices, 3));

		// Shader
		std::string vertShaderSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_PositionOS;

			out vec3 v_PositionOS;

			void main()
			{
				v_PositionOS = a_PositionOS;

				gl_Position = vec4(a_PositionOS, 1);
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
			RenderCommand::SetClearColor(1.0f, 0.0f, 1.0f);

			RenderCommand::ClearFrameBuffer();

			shader->Bind();
			vertexArray->Bind();
			indexBuffer->Bind();
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Window->Update();
		}
		// ------------------------------------------------------------------------------------------------------------------ Game loop
	}
}