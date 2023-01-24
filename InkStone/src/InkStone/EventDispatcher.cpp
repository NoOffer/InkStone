#include "inks_pch.h"
#include "EventDispatcher.h"

namespace InkStone
{
	EventDispatcher::EventDispatcher()
	{
		m_Dispatchers = {};
	}

	EventDispatcher::~EventDispatcher() {}

	void EventDispatcher::PushCallback(EventType eventType, std::function<void(Event*)> dispatcherFn)
	{
		m_Dispatchers[eventType].push_back(dispatcherFn);
	}

	void EventDispatcher::Distpatch(EventType eventType, Event* event)
	{
		std::vector<std::function<void(Event*)>> dispatchers = m_Dispatchers[eventType];
		for (int i = 0; i < dispatchers.size(); i++) {
			dispatchers[i](event);
			event->m_dispatched = true;
		}
	}
}