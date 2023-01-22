#include "inks_pch.h"
#include "EventDispatcher.h"

namespace InkStone
{
	EventDispatcher::EventDispatcher()
	{
		m_Dispatchers = {};
	}

	EventDispatcher::~EventDispatcher() {}

	EventDispatcher& EventDispatcher::GetInstance()
	{
		static EventDispatcher instance;
		return instance;
	}

	void EventDispatcher::PushCallback(EventType eventType, std::function<void(Event*)> dispatcherFn)
	{
		m_Dispatchers[eventType].push_back(dispatcherFn);
	}

	void EventDispatcher::Distpatch(Event* event)
	{
		std::vector<std::function<void(Event*)>> dispatchers = m_Dispatchers[(*event).GetType()];
		for (int i = 0; i < dispatchers.size(); i++) {
			dispatchers[i](event);
			event->m_dispatched = true;
		}
	}
}