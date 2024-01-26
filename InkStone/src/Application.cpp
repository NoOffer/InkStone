#include "pch.h"

#include "Application.h"

namespace NXTN {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		Log::Info("InkStone Engine successfully initialized.");
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (!m_Paused)
		{
			m_Window->Update();
		}
	}
}