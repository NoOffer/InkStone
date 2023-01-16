#pragma once

#include "Event.h"

namespace InkStone
{
	class INKS_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_TYPE(WindowClosed);
		EVENT_FLAG(EventFlag::WindowEvent);
	};

	class INKS_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int newHeight, int newWidth)
			: m_Height(newHeight), m_Width(newWidth) {
		}

		EVENT_TYPE(WindowResized);
		EVENT_FLAG(EventFlag::WindowEvent);

	private:
		int m_Height;
		int m_Width;
	};

	class INKS_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_TYPE(WindowLostFocus);
		EVENT_FLAG(EventFlag::WindowEvent);
	};

	class INKS_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int dx, int dy)
			: m_XOffset(dx), m_YOffset(dy) {
		}

		EVENT_TYPE(WindowMoved);
		EVENT_FLAG(EventFlag::WindowEvent);

	private:
		int m_XOffset;
		int m_YOffset;
	};
}