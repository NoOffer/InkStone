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

		glfwSetWindowUserPointer(m_Window, &m_EventDispatcher);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new WindowClosedEvent());
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new WindowResizedEvent(width, height));
			});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
			if (focused == GL_TRUE)
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new WindowFocusedEvent());
			else
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new WindowLostFocusEvent());
			});

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xPos, int yPos) {
			(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new WindowMovedEvent(xPos, yPos));
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			switch (action) {
			case GLFW_PRESS:
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new KeyPressedEvent(key));
				break;
			case GLFW_REPEAT:
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new KeyRepeatedEvent(key));
				break;
			case GLFW_RELEASE:
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new KeyReleasedEvent(key));
				break;
			}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			switch (action) {
			case GLFW_PRESS:
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new MouseButtonPressedEvent(button));
				break;
			case GLFW_RELEASE:
				(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new MouseButtonReleasedEvent(button));
				break;
			}
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new MouseMovedEvent(xPos, yPos));
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			(*(EventDispatcher*)glfwGetWindowUserPointer(window)).Distpatch(new MouseWheelScrolledEvent(xOffset, yOffset));
			});
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::SetEventCallback(EventType eventType, std::function<void(Event*)> callback)
	{
		m_EventDispatcher.PushCallback(eventType, callback);
	}

	//void WindowsWindow::Init(unsigned int height, unsigned int width, std::string title) {}

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
