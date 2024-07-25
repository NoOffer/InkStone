#include "pch.h"

#include "OpenGL/OpenGLVertexArray.h"

namespace NXTN {
	// Vertex Array Layout
	VertexArrayLayout::VertexArrayLayout() : m_Layout(0), m_Stride(0) {}

	VertexArrayLayout::VertexArrayLayout(const std::initializer_list<VertexArrayAtrribute>& il)
	{
		m_Stride = 0;

		for (const VertexArrayAtrribute& attribute : il)
		{
			m_Stride += ShaderDataTypeSize(attribute.type) * attribute.count;
		}

		m_Layout = il;
	}

	VertexArrayLayout::~VertexArrayLayout() {}

	void VertexArrayLayout::AddAttribute(ShaderDataType type, unsigned int count, const std::string& name)
	{
		m_Layout.push_back({ type, count, name });

		m_Stride += ShaderDataTypeSize(type) * count;
	}

	// Vertex Array
	VertexArray* VertexArray::Create(const std::shared_ptr<VertexBuffer> vertexBuffer, const VertexArrayLayout& layout)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return (VertexArray*) new OpenGLVertexArray(vertexBuffer, layout);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}

	// Vertex Array
	VertexArray* VertexArray::Create(
		const std::shared_ptr<VertexBuffer> vertexBuffer,
		const std::initializer_list<VertexArrayAtrribute>& il)
	{
		switch (System::GetGraphicsAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return (VertexArray*) new OpenGLVertexArray(vertexBuffer, il);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}
