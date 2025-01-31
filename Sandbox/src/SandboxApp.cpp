#include "SandboxApp.h"

// Sandbox Layer
SandboxLayer::SandboxLayer(unsigned int windowWidth, unsigned int windowHeight)
{

}

void SandboxLayer::Update()
{
	// Rendering
	NXTN::Renderer::SetClearColor(1.0f, 0.0f, 1.0f);

	NXTN::Renderer::ClearFrameBuffer();
}

void SandboxLayer::UIUpdate()
{

}

bool SandboxLayer::OnEvent(NXTN::Event& event)
{

}

// Sandbox Application
Sandbox::Sandbox()
	: Application()
{
	m_LayerStack.PushLayer(new SandboxLayer(m_Window->GetWidth(), m_Window->GetHeight()));
}

void Sandbox::Update()
{
	Application::Update();
}

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}