#pragma once
#include "Core.h"

#include "Window.h"

namespace InkStone
{
	class INKS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}

