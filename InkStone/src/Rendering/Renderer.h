#pragma once

#include "src/Core.h"

#include "src/Log.h"
#include "src/System.h"

#include "Mesh.h"

namespace NXTN {
	class Renderer
	{
	public:
		virtual ~Renderer() {}

		// Static
		static void DrawMesh(const std::shared_ptr<const Mesh>& mesh);

		static void ResizeViewport(int width, int height);
		
		static void SetClearColor(float r, float g, float b);
		static void ClearFrameBuffer();

		static void Init();

	protected:
		// Virtual
		virtual void DrawMeshImpl(const std::shared_ptr<const Mesh>& mesh) = 0;

		virtual void ResizeViewportImpl(int width, int height) = 0;

		virtual void SetClearColorImpl(float r, float g, float b) = 0;
		virtual void ClearFrameBufferImpl() = 0;

		//static inline bool Initialized() { return s_Renderer != nullptr; }

	private:
		static std::unique_ptr<Renderer> s_Renderer;
	};
}