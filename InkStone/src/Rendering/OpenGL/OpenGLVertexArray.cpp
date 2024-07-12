#include "pch.h"

#include "OpenGLVertexArray.h"

namespace NXTN {

	OpenGLVertexArray::OpenGLVertexArray(const std::shared_ptr<VertexBuffer> vertexBuffer, const VertexArrayLayout& layout)
		: m_VertexBuffer(vertexBuffer), m_Layout(layout)
	{
		glCreateVertexArrays(1, &m_ObjectID);
		glBindVertexArray(m_ObjectID);

		m_VertexBuffer->Bind();

		unsigned int index = 0;
		unsigned int stride = m_Layout.GetStride();
		unsigned int offset = 0;
		for (const VertexArrayAtrribute& attribute : m_Layout.GetAttributes())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				attribute.count,
				ShaderDataTypeToOpenGLType(attribute.type),
				GL_FALSE,
				stride,
				(const void*)offset
			);

			index++;
			offset += ShaderDataTypeSize(attribute.type);
		}

		glBindVertexArray(0);
	}

	OpenGLVertexArray::OpenGLVertexArray(
		const std::shared_ptr<VertexBuffer> vertexBuffer,
		const std::initializer_list<VertexArrayAtrribute>& il
	)
		: m_VertexBuffer(vertexBuffer), m_Layout(il)
	{
		glCreateVertexArrays(1, &m_ObjectID);
		glBindVertexArray(m_ObjectID);

		m_VertexBuffer->Bind();

		unsigned int index = 0;
		unsigned int stride = m_Layout.GetStride();
		unsigned int offset = 0;
		for (const VertexArrayAtrribute& attribute : m_Layout.GetAttributes())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				attribute.count,
				ShaderDataTypeToOpenGLType(attribute.type),
				GL_FALSE,
				stride,
				(const void*)offset
			);
			offset += ShaderDataTypeSize(attribute.type);
		}

		glBindVertexArray(0);
		m_VertexBuffer->Unbind();
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_ObjectID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_ObjectID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}