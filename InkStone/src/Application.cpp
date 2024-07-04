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
		unsigned int vertexArray;
		std::unique_ptr<VertexBuffer> vertexBuffer;
		std::unique_ptr<IndexBuffer> indexBuffer;
		// Temporary draw data
		// Vertex array
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		// Vertex buffer
		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};
		vertexBuffer.reset(VertexBuffer::Create(vertices, 9));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, nullptr);

		// Index buffer
		unsigned int indices[3] = { 0, 1, 2 };
		indexBuffer.reset(IndexBuffer::Create(indices, 3));

		// Game loop
		while (!m_Paused)
		{
			m_LayerStack.Update();

			// Rendering
			glClear(GL_COLOR_BUFFER_BIT);

			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Window->Update();
		}
	}
}