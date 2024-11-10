#pragma once

#include "Layer.h"
#include "Time.h"
#include "Window.h"
#include "Rendering/Shader.h"

namespace NXTN {
	class UI : public Layer
	{
	public:
		virtual ~UI() {}

		static UI* Create(const std::shared_ptr<Window>& window, const std::string& name);

	protected:
		UI(const std::string& name = "UI") : Layer(name) {}
	};

	class Inspector : public Layer
	{
	public:
		static void Init() {}
		static void InspectShader(const Shader& shader) {}

	private:
		Inspector() : Layer("UI") {}
		~Inspector() {}
	};
}

