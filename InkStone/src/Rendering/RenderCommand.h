#pragma once

#include "Renderer.h"
#include "System.h"

namespace NXTN {
	class RenderCommand
	{
	public:
		static void Init();
		static inline bool IsInitialized() { return s_Renderer != NULL; }


		static void SetClearColor(float r, float g, float b);
		static void ClearFrameBuffer();

	private:
		static std::unique_ptr<Renderer> s_Renderer;
	};
}

