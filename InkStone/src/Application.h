#pragma once

#include "Input/Input.h"
#include "LayerStack.h"
#include "UI/UI.h"
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

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
