#pragma once

#include "InkStone\Core.h"

namespace InkStone
{
	enum class EventType
	{
		None = 0,
		WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
		KeyPressed, KeyRepeated, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseWheelScrolled
	};

	enum EventFlag
	{
		None = 0,
		ApplicationEvent = BIT(0),
		InputEvent       = BIT(1),
		WindowEvent      = BIT(2),
		KeyboardEvent    = BIT(3),
		MouseEvent       = BIT(4)
	};

#define EVENT_TYPE(type) static inline EventType GetTypeStatic() { return EventType::##type; }\
						 virtual inline EventType GetType() const override { return EventType::##type; }\
						 virtual inline const char* GetName() const override { return #type; }

#define EVENT_FLAG(flag) virtual inline int GetFlag() const override { return flag; }

	class INKS_API Event
	{
	public:
		virtual inline EventType GetType() const = 0;
		virtual inline const char* GetName() const = 0;
		virtual inline int GetFlag() const = 0;

		inline bool hasFlag(EventFlag filter) { return GetFlag() & filter; }

	protected:
		bool m_hendled = false;
	};

	class EventDispatcher
	{

	};
}