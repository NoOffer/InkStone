#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		if (s_Instance) Log::Warning("Duplicated Application: Application should be unique");

		s_Instance = this;

		Renderer::Init();

		m_Window = std::unique_ptr<Window>(Window::Create());

		Time::InitTime();

		Input::Init(m_Window->GetNativeWindow());
	}

	Application::~Application()
	{

	}

	void Application::Update()
	{
		Time::UpdateTime();

		m_Window->Update();

		m_LayerStack.Update();
	}

	void Application::Run()
	{
		while (true)
		{
			Update();
		}
	}
}