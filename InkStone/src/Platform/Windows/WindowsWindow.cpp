#include "pch.h"

#include "WindowsWindow.h"

namespace NXTN {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(unsigned int width, unsigned int height, std::string title)
	{
		return new WindowsWindow(width, height, title);
	}

	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		// GLFW initialization
		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				Log::Error("Failed To Initialize GLFW");
				NXTN_ERROR;
			}
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			Log::Error("Failed To Create Window (Title: %s)", title);
			NXTN_ERROR;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(m_VSync ? 1 : 0);

		// GLAD initialization
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Log::Error("Failed To Initialize GLAD");
			NXTN_ERROR;
		}
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_VSync = enabled;
	}
}
