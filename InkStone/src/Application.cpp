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

		m_LayerStack.PushLayer(UI::Create(m_Window, "Test Window"));
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
		if (event.GetEventType() == EventType::WindowClosed)
		{
			m_Alive = false;
		}
		else
		{
			m_LayerStack.OnEvent(event);
		}
	}
}