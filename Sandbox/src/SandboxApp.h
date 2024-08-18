#pragma once

#include "InkStone.h"

class Sandbox : public NXTN::Application
{
public:
	Sandbox();
	~Sandbox() {}

	virtual void Run() override;
};

NXTN::Application* NXTN::CreateApplication()
{
	return new Sandbox();
}