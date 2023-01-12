#pragma once

#ifdef INKSTONE_PLATFORM_WINDOWS

extern InkStone::Application* InkStone::CreateApplication();

int main(int argc, char** argv)
{
	auto app = InkStone::CreateApplication();
	app->Run();
	delete app;
}

#endif // INKSTONE_PLATFORM_WINDOWS
