#pragma once

#include "Layer.h"
#include "Time.h"
#include "Window.h"

namespace NXTN {
	class UI : public Layer
	{
	public:
		virtual ~UI() {}

		static Layer* Create(const std::shared_ptr<Window>& window, const char* name);

	protected:
		UI(const char* name = "UI") : Layer(name) {}
	};
}

