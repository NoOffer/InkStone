#pragma once

namespace InkStone
{
	enum class EventType
	{
		None = 0,
		WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseWheelScrolled
	};


}