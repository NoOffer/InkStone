#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application::Application()
	{
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

		// ------------------------------------------------------------------------------------------------------------------ Game loop
		while (!m_Paused)
		{
			m_LayerStack.Update();

			// Rendering
			glClear(GL_COLOR_BUFFER_BIT);

			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

			vertexArray->Bind();
			indexBuffer->Bind();
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Window->Update();
		}
		// ------------------------------------------------------------------------------------------------------------------ Game loop
	}
}