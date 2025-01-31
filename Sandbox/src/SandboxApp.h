#pragma once

#include "InkStone.h"

class SandboxLayer : public NXTN::Layer
{
public:
	SandboxLayer(unsigned int windowWidth, unsigned int windowHeight);

	virtual void Update() override;
	virtual void UIUpdate() override;
	virtual bool OnEvent(NXTN::Event& event) override;

private:

};

class Sandbox : public NXTN::Application
{
public:
	Sandbox();
	~Sandbox() {}

	virtual void Update() override;
};