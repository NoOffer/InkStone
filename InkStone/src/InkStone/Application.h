#pragma once

#include "Core.h"

namespace InkStone
{
	class INKSTONE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

