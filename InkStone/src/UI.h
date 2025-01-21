#pragma once

#include "Time.h"
#include "Window.h"

namespace NXTN {
	class UI
	{
	public:
		virtual ~UI() {}

		static void Init(const std::shared_ptr<Window>& window);
		
		// Static
		static void NewFrame();
		static void EndFrame();
		static void OnEvent(Event& event);

	protected:
		UI() {}

		// Virtual
		virtual void NewFrameImpl() = 0;
		virtual void EndFrameImpl() = 0;
		virtual void OnEventImpl(Event& event) = 0;

	private:
		static std::unique_ptr<UI> s_UI;
	};
}

