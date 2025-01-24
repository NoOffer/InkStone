#pragma once

#include "src/Rendering/FrameBuffer.h"

namespace NXTN {
	class OpenGLFrameBuffer : FrameBuffer
	{
	public:
		OpenGLFrameBuffer(unsigned int width, unsigned int height);
		~OpenGLFrameBuffer();

		virtual inline unsigned int GetWidth() const override { return m_Width; }
		virtual inline unsigned int GetHeight() const override { return m_Height; }

		virtual inline unsigned int GetHandle() const override { return m_ColorAttachment; }

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int m_RendererID;
		unsigned int m_Width, m_Height;
		unsigned int m_ColorAttachment;
		unsigned int m_DepthStencilAttachment;
	};
}