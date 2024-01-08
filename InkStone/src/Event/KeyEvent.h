#pragma once

#include "Event.h"

namespace NXTN {
	class NXTN_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		virtual EventFlag GetEventFlag() const override { return EventFlag::Keyboard; }

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class NXTN_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {};

		virtual EventType GetEventType() const override { return EventType::KeyPressed; }

		inline int GetRepeatCount() const { return m_RepeatCount; }

	private:
		int m_RepeatCount;
	};

	class NXTN_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {};

		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
	};
}
