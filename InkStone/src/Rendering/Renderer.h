#pragma once

#include "Core.h"

#include "Log.h"

namespace NXTN {
	class Renderer
	{
	public:
		virtual ~Renderer() {}

		virtual void SetClearColor(float r, float g, float b) = 0;
		virtual void ClearFrameBuffer() = 0;

		virtual inline GraphicsAPI GetGraphicsAPI() = 0;

		static Renderer* Create(GraphicsAPI api);
	};
}