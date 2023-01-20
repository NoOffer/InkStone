#include "EventManager.h"

#include "ApplicationEvent.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"
#include "WindowEvent.h"

namespace InkStone
{
	EventManager::EventManager()
	{
		EventManager::m_Dispatchers = {};

		m_Dispatchers.push_back(EventDispatcherLL<WindowClosedEvent>());
	}

	void EventManager::PushCallback(EventType e, std::function<EventType(void)> callback)
	{

	}

	void EventManager::Handle(EventType e) {}
}