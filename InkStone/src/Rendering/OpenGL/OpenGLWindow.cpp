#include "pch.h"

#include "OpenGLWindow.h"

namespace NXTN {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(unsigned int width, unsigned int height, std::string title)
	{
		return new OpenGLWindow(width, height, title);
	}

	OpenGLWindow::OpenGLWindow(unsigned int width, unsigned int height, std::string title, bool vSync)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		// GLFW initialization
		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				Log::Error("Failed to initialize GLFW");
				NXTN_ERROR;
			}
			s_GLFWInitialized = true;
		}

		// Create window and context
		m_Window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			Log::Error("Failed to create window (Title: %s)", title);
			NXTN_ERROR;
		}
		glfwMakeContextCurrent(m_Window);

		// V Sync
		m_VSync = vSync;
		glfwSwapInterval(m_VSync ? 1 : 0);

		// GLAD initialization
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Log::Error("Failed to initialize GLAD");
			NXTN_ERROR;
		}

		Log::Info(
			"OpenGL context Initialized\n		   ©À- Hardware:       %s\n		   ©¸- OpenGL Version: %s",
			glGetString(GL_RENDERER),
			glGetString(GL_VERSION)
		);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void OpenGLWindow::Update()
	{
		glfwPollEvents();

		glfwSwapBuffers(m_Window);
	}

	void OpenGLWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);

		m_VSync = enabled;
	}
}
