#pragma once

#include "Window.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace NXTN {
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(unsigned int width, unsigned int height, std::string title, bool vSync = false);
		virtual ~OpenGLWindow();

		virtual void Update() override;

		virtual inline unsigned int GetWidth() const override { return m_Width; }
		virtual inline unsigned int GetHeight() const override { return m_Height; }

		virtual inline bool IsVSync() const override { return m_VSync; }
		inline void SetVSync(bool enabled) override;

		virtual inline void* GetNativeWindow() const override { return m_Window; }

	private:
		GLFWwindow* m_Window;

		unsigned int m_Width, m_Height;
		std::string m_Title;
		bool m_VSync;
	};
}

