#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

namespace NXTN {
	Application* Application::s_Instance = nullptr;

	Application::Application() : m_Alive(true)
	{
		if (s_Instance) Log::Warning("Duplicated Application: Application should be unique");

		s_Instance = this;

		Renderer::Init();

		m_Window.reset(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnWindowEvent, this, std::placeholders::_1));

		Time::InitTime();

		//Input::Init(m_Window->GetNativeWindow());
	}

	Application::~Application()
	{

	}

	void Application::Update()
	{
		Time::UpdateTime();

		m_LayerStack.Update();

		m_Window->Update();
	}

	void Application::Run()
	{
		while (m_Alive)
		{
			Update();
		}
	}

	void Application::OnWindowEvent(Event& event)
	{
		switch (event.GetEventType())
		{
		case EventType::WindowClosed:
			m_Alive = false;
			break;
		default:
			m_LayerStack.OnEvent(event);
			break;
		}
	}
}