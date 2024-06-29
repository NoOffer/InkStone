#pragma once

#include "Graphics/Window.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace NXTN {
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(unsigned int width, unsigned int height, std::string title, bool vSync = false);
		virtual ~OpenGLWindow();

		void Update() override;

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		void SetVSync(bool enabled) override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		GLFWwindow* m_Window;

		unsigned int m_Width, m_Height;
		std::string m_Title;
	};
}

