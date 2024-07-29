#pragma once

#include "LayerStack.h"
#include "Component/Mesh.h"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Window.h"

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
