#include "pch.h"

#include "Application.h"

#include "GLAD/glad.h"

#include "Platform/OpenGL/ImGuiBackend/imgui_impl_opengl3.h"  // Temporary

namespace NXTN {
	Application* Application::s_Instance = nullptr;

	Application::Application() : m_Alive(true), m_Minimized(false)
	{
		NXTN_PROFILE_NEXT(60);
		NXTN_PROFILE_FUNCTION()

		if (s_Instance) Log::Warning("Duplicated Application: Application should be unique");

		s_Instance = this;

		m_Window.reset(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnWindowEvent, this, std::placeholders::_1));

		Renderer::Init();

		Time::InitTime();

		//Input::Init(m_Window->GetNativeWindow());

		UI::Init(m_Window);
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Alive)
		{
			Update();
		}
	}

	void Application::Update()
	{
		NXTN_PROFILE_FUNCTION()

		Time::UpdateTime();

		m_LayerStack.Update();

		UI::NewFrame();
		{
			m_LayerStack.UIUpdate();
		}
		UI::EndFrame();

		m_Window->Update();
	}

	void Application::OnWindowEvent(Event& event)
	{
		switch (event.GetEventType())
		{
		case EventType::WindowClosed:
		{
			m_Alive = false;
			return;
		}
		case EventType::WindowResized:
		{
			WindowResizeEvent e = *(WindowResizeEvent*)(&event);
			m_Minimized = e.GetNewWidth() < 1 || e.GetNewHeight() < 1;
			break;
		}
		}
		m_LayerStack.OnEvent(event);

		UI::OnEvent(event);
	}
}