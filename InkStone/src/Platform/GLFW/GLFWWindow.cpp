#include "pch.h"

#include "GLFWWindow.h"

namespace NXTN {
	static bool s_GLFWInitialized = false;

	OpenGLWindow::OpenGLWindow(unsigned int width, unsigned int height, std::string title, bool vSync)
		: m_Width(width), m_Height(height), m_Title(title), m_VSync(vSync)
	{
		// Create window and context
		m_Window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			Log::Error("Failed to create window (Title: %s)", title);
			NXTN_ERROR;
		}
		glfwMakeContextCurrent(m_Window);

		// GLAD initialization
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Log::Error("Failed to initialize GLAD");
			NXTN_ERROR;
		}

		// Log context information
		Log::Info("OpenGL context Initialized");
		Log::Info("  ©À- Hardware Info:  %s", glGetString(GL_RENDERER));
		Log::Info("  ©¸- OpenGL Version: %s", glGetString(GL_VERSION));

		// V Sync
		glfwSwapInterval(m_VSync ? 1 : 0);
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
