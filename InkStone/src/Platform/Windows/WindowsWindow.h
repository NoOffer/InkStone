#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace NXTN {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(unsigned int width, unsigned int height, std::string title);
		virtual ~WindowsWindow();

		void Update() override;

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_VSync; };

	private:
		GLFWwindow* m_Window;

		unsigned int m_Width, m_Height;
		std::string m_Title;
		bool m_VSync = true;
	};
}

