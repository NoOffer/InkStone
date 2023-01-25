#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace InkStone
{
	class INKS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void SetEventCallback(EventType eventType, std::function<void(Event*)> callback) = 0;

		static Window* Create();
	};
}
