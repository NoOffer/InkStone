#pragma once

#include "Window.h"

namespace NXTN {

	class LayerStack
	{
	public:
		LayerStack();
		virtual ~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void OnEvent(Event& event);
		void Update();

	private:
		std::vector<Layer*> m_LayerStack;
		std::vector<Layer*> m_OverlayStack;
	};
}