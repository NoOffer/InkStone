#include "inks_pch.h"
#include "WindowsWindow.h"

//#include "InkStone/Log.h"

namespace InkStone
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create()
	{
		return new WindowsWindow();
	}

	WindowsWindow::WindowsWindow(unsigned int height, unsigned int width, std::string title)
		: m_Width(width), m_Height(height)
	{
		Init(height, width, title);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(unsigned int height, unsigned int width, std::string title)
	{
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			//INKS_ASSERT(success);

			s_GLFWInitialized = true;
			//INKS_INFO("Window Created");
		}

		m_Window = glfwCreateWindow((int)height, (int)width, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		//glfwSetWindowUserPointer();
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(1 ? enabled : 0);
		m_IsVSync = enabled;
	}
}
