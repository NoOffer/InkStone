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

		static inline const Application& Get() { return *s_Instance; }

		virtual void Update();

		void Run();

	protected:
		std::shared_ptr<Window> m_Window;

		LayerStack m_LayerStack;

		bool m_Alive;
		bool m_Minimized;

	private:
		void OnWindowEvent(Event& event);

		static Application* s_Instance;
	};

	Application* CreateApplication();
}
