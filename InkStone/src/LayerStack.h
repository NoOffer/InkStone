#pragma once

#include "Layer.h"

namespace NXTN {

	class NXTN_API LayerStack
	{
	public:
		LayerStack();
		virtual ~LayerStack();

		void PushLayer(Layer* layer);
		void Update();
	private:
		std::vector<Layer*> m_LayerStack;
	};
}