#pragma once

#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

#include "src/Log.h"

#define NXTN_EVENTBUFFER_MAX 500

namespace NXTN {
	class EventBuffer
	{
	public:
		static void PushEvent(Event* event);
		static void Clear();
		static inline std::deque<Event*>& GetEventBuffer() { return m_EventBuffer; }
	
	private:
		// Clearly C++ is not happy about Event being abstract
		// So pointer type is required here
		// For this std::deque object, use emplace_back and pop_front
		static std::deque<Event*> m_EventBuffer;
	};
}

