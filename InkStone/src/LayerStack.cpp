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
		m_LayerStack.emplace(m_LayerStack.end(), layer);
	}

	void LayerStack::OnEvent(Event& event)
	{
		switch (event.GetEventType())
		{
		case EventType::WindowClosed:

			break;
		default:
			break;
		}
	}

	void LayerStack::Update()
	{
		for (Layer* layer : m_LayerStack)
			layer->Update();
	}
}
