#pragma once

#include "Core.h"

#include "Log.h"
#include "Mesh.h"

namespace NXTN {
	class Renderer
	{
	public:
		virtual ~Renderer() {}

		virtual void DrawMesh(const Mesh& mesh) = 0;

		virtual void SetClearColor(float r, float g, float b) = 0;
		virtual void ClearFrameBuffer() = 0;

		static Renderer* Create(GraphicsAPI api);
	};
}