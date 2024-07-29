#pragma once

#include "Rendering/VertexArray.h"
#include "Rendering/RenderingDataBuffer.h"

namespace NXTN {
	class Mesh
	{
	public:
		Mesh(VertexArray* va, IndexBuffer* ib);
		~Mesh() {}

		void Bind() const;
		void Unbind() const;

		const VertexArray& GetVertexArray() const;
		const IndexBuffer& GetIndexBuffer() const;

	private:
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	};
}

