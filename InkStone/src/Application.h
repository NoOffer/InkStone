#pragma once

#include "Input.h"
#include "Time.h"
#include "Window.h"
#include "Rendering/Renderer.h"

namespace NXTN {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Init();
		virtual void Update();

		void Run();

	protected:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}
