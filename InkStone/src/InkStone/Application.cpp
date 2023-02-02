#include "inks_pch.h"
#include "Application.h"

#include "Log.h"
#include "Events/Event.h"

namespace InkStone
{
	//void TestFn(Event*)
	//{
	//	INKS_INFO("1");
	//}

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		//m_Window->SetEventCallback(MouseMoved, TestFn);
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}
