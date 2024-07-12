#pragma once

#include "Core.h"

namespace NXTN {
	enum class RenderingAPI
	{
		None = 0, OpenGL
	};

	class Renderer
	{
	public:
		static inline RenderingAPI GetRenderingAPI() { return s_RenderingAPI; }
	private:
		static RenderingAPI s_RenderingAPI;
	};
}