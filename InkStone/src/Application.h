#pragma once

#include "LayerStack.h"
#include "Component/Camera.h"
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

		virtual void Run();

	protected:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}
