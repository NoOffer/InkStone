#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application::Application()
	{
		Renderer::Init();

		m_Window = std::unique_ptr<Window>(Window::Create());

		Time::InitTime();

		Input::Init(m_Window->GetNativeWindow());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

	}
}