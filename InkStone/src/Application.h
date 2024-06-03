#pragma once

#include "Window.h"

namespace NXTN {
	class NXTN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		bool m_Paused = false;

		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}
