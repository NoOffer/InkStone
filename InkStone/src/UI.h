#pragma once

#include "Layer.h"
#include "Time.h"
#include "Window.h"

namespace NXTN {
	class UI : public Layer
	{
	public:
		virtual ~UI() {}

		static Layer* Create(const std::shared_ptr<Window>& window, const std::string& name);

	protected:
		UI(const std::string& name = "UI Layer") : Layer(name) {}
	};
}

