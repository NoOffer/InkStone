#pragma once

#include "LayerStack.h"
#include "Rendering/RenderingDataBuffer.h"
#include "Rendering/VertexArray.h"
#include "Rendering/Window.h"

namespace NXTN {
	class Application
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
