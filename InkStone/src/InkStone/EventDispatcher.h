#pragma once

#include "inks_pch.h"
#include "Events/Event.h"

#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

namespace InkStone
{
	class INKS_API EventDispatcher
	{
	public:
		EventDispatcher();
		~EventDispatcher();

		void PushCallback(EventType eventType, std::function<void(Event*)> dispatcherFn);
		void Distpatch(Event* event);

	private:
		std::unordered_map<EventType, std::vector<std::function<void(Event*)>>> m_Dispatchers;
	};
}