#include "pch.h"

#include "GLFWWindow.h"

namespace NXTN {
	static bool s_GLFWInitialized = false;

	OpenGLWindow::OpenGLWindow(unsigned int width, unsigned int height, std::string title, bool vSync)
	{
		m_WinData.width = width;
		m_WinData.height = height;
		m_WinData.vSync = vSync;
		m_WinData.EventCallback = [](Event&) {};

		// GLFW initialization
		// Create window and context
		m_Window = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			Log::Error("Failed to create window (Title: %s)", title);
			NXTN_ERROR;
		}
		glfwMakeContextCurrent(m_Window);

		glfwSetWindowUserPointer(m_Window, &m_WinData);

		// GLAD initialization
		if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Log::Info("GLAD initialized");
		}
		else
		{
			Log::Error("Failed to initialize GLAD");
			NXTN_ERROR;
		}

		// Log context information
		Log::Info("OpenGL context initialized");
		Log::Info("  ©À- Hardware Info:  %s", glGetString(GL_RENDERER));
		Log::Info("  ©¸- OpenGL Version: %s", glGetString(GL_VERSION));

		// V Sync
		glfwSwapInterval(m_WinData.vSync ? 1 : 0);

		// GLFW event callbacks
		// Window close
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				(*(WindowData*)glfwGetWindowUserPointer(window)).EventCallback(WindowCloseEvent());
			}
		);
		// Window resize
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

		windowData.width = width;
		windowData.height = height;

		windowData.EventCallback(WindowResizeEvent(width, height));
			}
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

		m_WinData.vSync = enabled;
	}
}
