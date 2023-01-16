#pragma once

#include "Event.h"

namespace InkStone
{
	class INKS_API KeyboardEvent : public Event
	{
	public:
		EVENT_FLAG(EventFlag::InputEvent | EventFlag::KeyboardEvent);

		inline int GetKeyCode() { return m_KeyCode; }
	protected:
		KeyboardEvent(int keyCode)
			: m_KeyCode(keyCode)
		{
		}
		int m_KeyCode;
	};

	class INKS_API KeyPressedEvent : public KeyboardEvent
	{
	public:
		KeyPressedEvent(int KeyCode)
			: KeyboardEvent(KeyCode)
		{
		}

		EVENT_TYPE(KeyPressed);
	};

	class INKS_API KeyRepeatedEvent : public KeyboardEvent
	{
	public:
		KeyRepeatedEvent(int KeyCode)
			: KeyboardEvent(KeyCode)
		{
		}

		EVENT_TYPE(KeyRepeated);
	};

	class INKS_API KeyReleasedEvent : public KeyboardEvent
	{
	public:
		KeyReleasedEvent(int KeyCode)
			: KeyboardEvent(KeyCode)
		{
		}

		EVENT_TYPE(KeyReleased);
	};
}