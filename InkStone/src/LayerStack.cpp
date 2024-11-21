#include "pch.h"

#include "LayerStack.h"

namespace NXTN {

	LayerStack::LayerStack() {}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_LayerStack)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerStack.emplace_back(layer);
	}

	void LayerStack::OnEvent(Event& event)
	{
		for (Layer* layer : m_LayerStack)
		{
			if (layer->OnEvent(event))
			{
				break;
			}
		}
	}

	void LayerStack::Update()
	{
		for (Layer* layer : m_LayerStack)
			layer->Update();
	}
}
