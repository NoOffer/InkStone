#pragma once

#include "Event.h"

namespace NXTN {
	class NXTN_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};

		virtual EventFlag GetEventFlag() const override { return EventFlag::Application; }

		virtual EventType GetEventType() const override { return EventType::WindowClosed; }
	};

	class NXTN_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :m_NewWidth(width), m_NewHeight(height) {};

		virtual EventFlag GetEventFlag() const override { return EventFlag::Application; }

		virtual EventType GetEventType() const override { return EventType::WindowClosed; }

		inline int GetNewWidth() const { return m_NewWidth; }

		inline int GetNewHeight() const { return m_NewHeight; }

	private:
		unsigned int m_NewWidth, m_NewHeight;
	};

	class NXTN_API ApplicationUpdateEvent : public Event
	{
	public:
		ApplicationUpdateEvent() {};

		virtual EventFlag GetEventFlag() const override { return EventFlag::Application; }

		virtual EventType GetEventType() const override { return EventType::AppUpdate; }
	};

	class NXTN_API ApplicationRenderEvent : public Event
	{
	public:
		ApplicationRenderEvent() {};

		virtual EventFlag GetEventFlag() const override { return EventFlag::Application; }

		virtual EventType GetEventType() const override { return EventType::AppRender; }
	};
}
