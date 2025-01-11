#pragma once

#include "InkStone.h"

class SandboxLayer : public NXTN::Layer
{
public:
	SandboxLayer();

	virtual void Update() override;
	virtual bool OnEvent(NXTN::Event& event) override;

private:
	std::shared_ptr<NXTN::Camera> m_Camera;
	std::shared_ptr<NXTN::Mesh> m_Mesh;
	std::shared_ptr<NXTN::Texture2D> m_Texture;
	std::shared_ptr<NXTN::Shader> m_Shader;
};

class Sandbox : public NXTN::Application
{
public:
	Sandbox();
	~Sandbox() {}

	virtual void Update() override;
};