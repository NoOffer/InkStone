#pragma once

#include "Event.h"

namespace InkStone
{
	struct INKS_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_TYPE(WindowClosed);
		EVENT_FLAG(EventFlag::WindowEvent);
	};

	struct INKS_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int newWidth, int newHeight)
			: m_Width(newWidth), m_Height(newHeight)
		{
		}

		EVENT_TYPE(WindowResized);
		EVENT_FLAG(EventFlag::WindowEvent);

	private:
		int m_Width;
		int m_Height;
	};

	struct INKS_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_TYPE(WindowLostFocus);
		EVENT_FLAG(EventFlag::WindowEvent);
	};

	struct INKS_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int dx, int dy)
			: m_XOffset(dx), m_YOffset(dy)
		{
		}

		EVENT_TYPE(WindowMoved);
		EVENT_FLAG(EventFlag::WindowEvent);

	private:
		int m_XOffset;
		int m_YOffset;
	};
}