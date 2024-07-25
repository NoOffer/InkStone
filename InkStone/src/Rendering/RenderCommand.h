#pragma once

#include "Renderer.h"

namespace NXTN {
	class RenderCommand
	{
	public:
		static void InitRenderer(GraphicsAPI api);

		static GraphicsAPI GetGraphicsAPI();
		static inline bool IsRendererInit() { return s_Renderer != NULL; }

		static void SetClearColor(float r, float g, float b);
		static void ClearFrameBuffer();

	private:
		static std::unique_ptr<Renderer> s_Renderer;
	};
}

