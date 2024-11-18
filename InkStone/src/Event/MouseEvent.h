#pragma once

#include "Event.h"

namespace NXTN {
	class MouseButtonEvent : public Event
	{
	public:
		virtual EventFlag GetEventFlag() const override { return EventFlag::Mouse; }

		inline int GetButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int btn) : m_Button(btn) {}

		int m_Button;
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int btn) : MouseButtonEvent(btn) {};

		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int btn) : MouseButtonEvent(btn) {};

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float x, float y) : m_XOffset(x), m_YOffset(y) {}

		virtual EventFlag GetEventFlag() const override { return EventFlag::Mouse; }

		virtual EventType GetEventType() const override { return EventType::MouseScroll; }

		inline float GetX() const { return m_XOffset; }

		inline float GetY() const { return m_YOffset; }

	private:
		float m_XOffset, m_YOffset;
	};

	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y) : m_MovementX(x), m_MovementY(y) {}

		virtual EventFlag GetEventFlag() const override { return EventFlag::Mouse; }

		virtual EventType GetEventType() const override { return EventType::MouseMove; }

		inline float GetX() const { return m_MovementX; }

		inline float GetY() const { return m_MovementY; }

	private:
		float m_MovementX, m_MovementY;
	};
}
