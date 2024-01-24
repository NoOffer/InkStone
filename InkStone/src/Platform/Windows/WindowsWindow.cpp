#include "pch.h"

#include "WindowsWindow.h"

namespace NXTN {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(unsigned int width, unsigned int height, std::string title)
	{
		return new WindowsWindow(width, height, title);
		;
	}

	WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, std::string title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				Log::Error("GLFW Initialization Failed");
				NXTN_ERROR;
			}
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(m_VSync ? 1 : 0);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
		m_VSync = enabled;
	}
}
