#pragma once

#include "Event.h"

namespace InkStone
{
	class INKS_API MouseEvent : public Event
	{
	public:
		EVENT_FLAG(EventFlag::InputEvent | EventFlag::MouseEvent);
	};

	class INKS_API MouseButtonPressedEvent : public MouseEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: m_button(button)
		{
		}

		inline int GetButton() { return m_button; }

		EVENT_TYPE(KeyPressed);

	private:
		int m_button;
	};

	class INKS_API MouseButtonReleasedEvent : public MouseEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: m_button(button)
		{
		}

		inline int GetButton() { return m_button; }

		EVENT_TYPE(KeyPressed);

	private:
		int m_button;
	};

	class INKS_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(int dx, int dy)
			: m_X(dx), m_Y(dy)
		{
		}

		inline int GetX() { return m_X; }
		inline int GetY() { return m_Y; }

		EVENT_TYPE(KeyPressed);

	private:
		int m_X;
		int m_Y;
	};

	class INKS_API MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(int dx, int dy)
			: m_X(dx), m_Y(dy)
		{
		}

		inline int GetX() { return m_X; }
		inline int GetY() { return m_Y; }

		EVENT_TYPE(KeyPressed);

	private:
		int m_X;
		int m_Y;
	};
}