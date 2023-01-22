#pragma once

#include "Event.h"

namespace InkStone
{
	struct INKS_API MouseButtonPressedEvent : public Event
	{
		MouseButtonPressedEvent(int button) : m_button(button) {}

		EVENT_TYPE(KeyPressed);

		int m_button;
	};

	struct INKS_API MouseButtonReleasedEvent : public Event
	{
		MouseButtonReleasedEvent(int button) : m_button(button) {}

		EVENT_TYPE(KeyPressed);

		int m_button;
	};

	struct INKS_API MouseMovedEvent : public Event
	{
		MouseMovedEvent(int dx, int dy) : m_X(dx), m_Y(dy) {}

		EVENT_TYPE(KeyPressed);

		int m_X;
		int m_Y;
	};

	struct INKS_API MouseScrolledEvent : public Event
	{
		MouseScrolledEvent(int dx, int dy) : m_X(dx), m_Y(dy) {}

		EVENT_TYPE(KeyPressed);

		int m_X;
		int m_Y;
	};
}