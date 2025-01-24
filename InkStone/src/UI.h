#pragma once

#include "Time.h"
#include "Window.h"

namespace NXTN {
	class UI
	{
	public:
		virtual ~UI() {}

		static void Init(const std::shared_ptr<Window>& window);
		
		// Public static interface/wrapper
		static void NewFrame();
		static void EndFrame();

		static void ViewWindow(unsigned int handle);  // Temp
		
		static void OnEvent(Event& event);

	protected:
		UI() {}

		// Protected virtual implementation
		virtual void NewFrameImpl() = 0;
		virtual void EndFrameImpl() = 0;

		virtual void ViewWindowImpl(unsigned int handle) = 0;

		virtual void OnEventImpl(Event& event) = 0;

	private:
		static std::unique_ptr<UI> s_UI;
	};
}

