#pragma once

#include "InkStone/Application.h"

#ifdef NXTN_PLATFORM_WINDOWS
extern NXTN::Application* NXTN::CreateApplication();

int main(int argc, char** argv)
{
	NXTN::Application* app = NXTN::CreateApplication();
	app->Run();
	delete app;
}
#endif // NXTN_PLATFORM_WINDOWS