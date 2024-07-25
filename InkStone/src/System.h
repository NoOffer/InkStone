#pragma once

#include "Core.h"

namespace NXTN {
	class System
	{
	public:
		static inline GraphicsAPI GetGraphicsAPI() { return s_API; }
	private:
		static GraphicsAPI s_API;
	};
}

