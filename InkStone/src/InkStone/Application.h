#pragma once

#include "Core.h"

namespace InkStone
{
	class INKS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

