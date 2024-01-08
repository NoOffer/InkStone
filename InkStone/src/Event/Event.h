#pragma once

#include "InkStone/Core.h"

#include <string>

namespace NXTN {
	enum class EventType
	{
		None = 0,
		AppUpdate, AppRender,
		WindowClosed, WindowResized,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseScroll, MouseMovement
	};

	enum EventFlag
	{
		None = 0,
		Application    = BITMASK(0),
		Keyboard       = BITMASK(1),
		Mouse          = BITMASK(2),
		Input          = BITMASK(1) | BITMASK(2),
		Window         = BITMASK(3)
	};

	class NXTN_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual EventFlag GetEventFlag() const = 0;
		virtual std::string ToString() const = 0;

	protected:
		bool m_Handled = false;
	};
}