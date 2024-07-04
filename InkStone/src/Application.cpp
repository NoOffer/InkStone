#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		// Temporary draw data
		// Vertex array
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

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

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (!m_Paused)
		{
			m_LayerStack.Update();

			// Rendering
			glClear(GL_COLOR_BUFFER_BIT);

			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Window->Update();
		}
	}
}