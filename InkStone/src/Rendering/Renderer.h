#pragma once

#include "Core.h"

#include "Log.h"
#include "Mesh.h"
#include "System.h"

namespace NXTN {
	class Renderer
	{
	public:
		virtual ~Renderer() {}

		// Virtual
		virtual void DrawMeshImpl(const Mesh& mesh) = 0;

		virtual void SetClearColorImpl(float r, float g, float b) = 0;
		virtual void ClearFrameBufferImpl() = 0;

		// Static
		static void DrawMesh(const Mesh& mesh);

		static void SetClearColor(float r, float g, float b);
		static void ClearFrameBuffer();

		static void Init();
		//static Renderer* Create(GraphicsAPI api);

	private:
		static std::unique_ptr<Renderer> s_Renderer;
	};
}