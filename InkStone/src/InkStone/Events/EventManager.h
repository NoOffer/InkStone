#pragma once

#include "Event.h"
#include "WindowEvent.h"

namespace InkStone
{
	// Event dispatchers
	class EventDispatcher
	{
	public:
		EventDispatcher()
		{
			m_Dispatchers = {};

			m_Dispatchers[EventType::WindowClosed].push_back(std::function<void(Event*)>(TestFn));
		}


		void TestFn(Event*);

		//void Distpatch(T event)
		//{

		//}

		//void Push(std::function<T(void)> dispatcherFn)
		//{

		//}

	private:
		std::unordered_map<EventType, std::vector<std::function<void(Event*)>>> m_Dispatchers;
	};
}