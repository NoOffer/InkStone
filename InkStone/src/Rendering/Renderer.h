#pragma once

#include "Core.h"

namespace NXTN {
	enum class GraphicsAPI
	{
		None = 0, OpenGL
	};

	class Renderer
	{
	public:
		static inline GraphicsAPI GetRenderingAPI() { return s_GraphicsAPI; }
	private:
		static GraphicsAPI s_GraphicsAPI;
	};
}