#pragma once

#ifdef INKS_PLATFORM_WINDOWS

extern InkStone::Application* InkStone::CreateApplication();

int main(int argc, char** argv)
{
	InkStone::Log::Init();
	INKS_WARNING("Test Warning");

	InkStone::EventDispatcher();

	auto app = InkStone::CreateApplication();
	app->Run();
	delete app;
}

#endif // INKS_PLATFORM_WINDOWS
