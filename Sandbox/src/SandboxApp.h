#pragma once

#include "InkStone.h"

class Sandbox : public NXTN::Application
{
public:
	Sandbox();
	~Sandbox() {}

	virtual void Init() override;
	virtual void Update() override;

private:
	std::shared_ptr<NXTN::Camera> m_Camera;
	std::shared_ptr<NXTN::Mesh> m_Mesh;
	std::shared_ptr<NXTN::Shader> m_Shader;
};