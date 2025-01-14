#pragma once

#include "src/Core.h"

#include "src/Log.h"
#include "src/Component/Mesh.h"
#include "src/System.h"

namespace NXTN {
	class Renderer
	{
	public:
		virtual ~Renderer() {}

		// Static
		static void DrawMesh(const Mesh& mesh);

		static void SetClearColor(float r, float g, float b);
		static void ClearFrameBuffer();

		static void Init();

	protected:
		// Virtual
		virtual void DrawMeshImpl(const Mesh& mesh) = 0;

		virtual void SetClearColorImpl(float r, float g, float b) = 0;
		virtual void ClearFrameBufferImpl() = 0;
		//static inline bool Initialized() { return s_Renderer != nullptr; }
		//static Renderer* Create(GraphicsAPI api);

	private:
		static std::unique_ptr<Renderer> s_Renderer;
	};
}