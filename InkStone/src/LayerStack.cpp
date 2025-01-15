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

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_OverlayStack.emplace_back(layer);
	}

	void LayerStack::Update()
	{
		NXTN_PROFILE_FUNCTION()

		for (Layer* layer : m_LayerStack)
			layer->Update();
		for (Layer* layer : m_OverlayStack)
			layer->Update();
	}

	void LayerStack::UIUpdate()
	{
		NXTN_PROFILE_FUNCTION()

		for (Layer* layer : m_LayerStack)
			layer->UIUpdate();
	}

	void LayerStack::OnEvent(Event& event)
	{
		for (Layer* layer : m_LayerStack)
		{
			if (layer->OnEvent(event))
			{
				return;
			}
		}
		for (Layer* layer : m_OverlayStack)
		{
			if (layer->OnEvent(event))
			{
				return;
			}
		}
	}
}
