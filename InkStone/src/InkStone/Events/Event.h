#pragma once

#include "inks_pch.h"

#include "InkStone\Core.h"

namespace InkStone
{
	enum EventType
	{
		None,
		WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
		KeyPressed, KeyRepeated, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseWheelScrolled
	};

	//enum EventFlag
	//{
	//	//None = 0,
	//	ApplicationEvent = BIT(0),
	//	InputEvent       = BIT(1),
	//	WindowEvent      = BIT(2),
	//	KeyboardEvent    = BIT(3),
	//	MouseEvent       = BIT(4)
	//};

#define EVENT_TYPE(type) inline virtual EventType GetType() override { return EventType::##type; }/*\
						 virtual inline int GetType() const override { return EventType::##type; }\
						 virtual inline const char* GetName() const override { return #type; }*/

//#define EVENT_FLAG(flag) virtual inline int GetFlag() const override { return flag; }

	struct INKS_API Event
	{
		inline virtual EventType GetType() { return EventType::None; }

		bool m_dispatched = false;
	};
}