#pragma once

#include "Core.h"
#include "RenderingDataBuffer.h"

namespace NXTN {

	enum class ShaderDataType
	{
		None = 0, Int, Float
	};

	static unsigned int ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Int:   return sizeof(int);
		case ShaderDataType::Float: return sizeof(float);
		default:                    return -1;
		}
	}

	struct VertexArrayAtrribute
	{
		ShaderDataType type;
		unsigned int count;
		std::string name;
	};

	class NXTN_API VertexArrayLayout
	{
	public:
		VertexArrayLayout();
		VertexArrayLayout(const std::initializer_list<VertexArrayAtrribute>& il);
		~VertexArrayLayout();

		void AddAttribute(ShaderDataType type, unsigned int count, const std::string& name);
		inline const std::vector<VertexArrayAtrribute>& GetAttributes() const { return m_Layout; }
		inline unsigned int GetStride() const { return m_Stride; }

	private:
		std::vector<VertexArrayAtrribute> m_Layout;
		unsigned int m_Stride;  // The sum of the sizes of all attributes (The size of each vertex)
	};

	class NXTN_API VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static VertexArray* Create(const std::shared_ptr<VertexBuffer> vertexBuffer, const VertexArrayLayout& layout);
		static VertexArray* Create(
			const std::shared_ptr<VertexBuffer> vertexBuffer,
			const std::initializer_list<VertexArrayAtrribute>& il
		);
	};
}
