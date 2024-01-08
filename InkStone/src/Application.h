#pragma once

#include "Core.h"

namespace NXTN {
	class NXTN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
