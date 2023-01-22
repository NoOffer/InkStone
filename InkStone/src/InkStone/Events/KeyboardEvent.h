#pragma once

#include "Event.h"

namespace InkStone
{
	struct INKS_API KeyboardEvent : public Event
	{
		//EVENT_FLAG(EventFlag::InputEvent | EventFlag::KeyboardEvent);
		KeyboardEvent(int keyCode) : m_KeyCode(keyCode) {}
		inline int GetKeyCode() { return m_KeyCode; }

		int m_KeyCode;
	};

	struct INKS_API KeyPressedEvent : public KeyboardEvent
	{
		KeyPressedEvent(int KeyCode) : KeyboardEvent(KeyCode) {}

		EVENT_TYPE(KeyPressed);
	};

	struct INKS_API KeyRepeatedEvent : public KeyboardEvent
	{
		KeyRepeatedEvent(int KeyCode) : KeyboardEvent(KeyCode) {}

		EVENT_TYPE(KeyRepeated);
	};

	struct INKS_API KeyReleasedEvent : public KeyboardEvent
	{
		KeyReleasedEvent(int KeyCode) : KeyboardEvent(KeyCode) {}

		EVENT_TYPE(KeyReleased);
	};
}