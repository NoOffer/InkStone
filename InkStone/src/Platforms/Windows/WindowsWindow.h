#pragma once

#include "InkStone/Window.h"

#include <GLFW/glfw3.h>

namespace InkStone
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(unsigned int height = 1280, unsigned int width = 720, std::string title = "");
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Width; }
		inline unsigned int GetHeight() const override { return m_Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override {}
		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_IsVSync; };

	private:
		void Init(unsigned int height, unsigned int width, std::string title);
		void Shutdown();

	private:
		unsigned int m_Width;
		unsigned int m_Height;
		bool m_IsVSync;

		GLFWwindow* m_Window;
	};
}

