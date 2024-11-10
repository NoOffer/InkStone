#pragma once

#include "Input.h"
#include "LayerStack.h"
#include "UI.h"
#include "Rendering/Renderer.h"

namespace NXTN {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Update();

		void Run();

	protected:
		std::shared_ptr<Window> m_Window;

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}
