#pragma once

#include "Event.h"

namespace NXTN {
	class NXTN_API MouseButtonEvent : public Event
	{
	public:
		virtual EventFlag GetEventFlag() const override { return EventFlag::Mouse; }

		inline int GetButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int btn) : m_Button(btn) {}

		int m_Button;
	};

	class NXTN_API MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int btn) : MouseButtonEvent(btn) {};

		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
	};

	class NXTN_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int btn) : MouseButtonEvent(btn) {};

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
	};

	class NXTN_API MouseScrollEvent : public Event
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

	class NXTN_API MouseMovementEvent : public Event
	{
	public:
		MouseMovementEvent(float x, float y) : m_MovementX(x), m_MovementY(y) {}

		virtual EventFlag GetEventFlag() const override { return EventFlag::Mouse; }

		virtual EventType GetEventType() const override { return EventType::MouseMovement; }

		inline float GetX() const { return m_MovementX; }

		inline float GetY() const { return m_MovementY; }

	private:
		float m_MovementX, m_MovementY;
	};
}
