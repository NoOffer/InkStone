#pragma once

#include "Graphics/Window.h"
#include "LayerStack.h"

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

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}
