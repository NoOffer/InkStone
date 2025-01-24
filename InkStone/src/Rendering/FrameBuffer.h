#pragma once

#include "src/Log.h"

namespace NXTN {
	class FrameBuffer
	{
	public:
		virtual ~FrameBuffer() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual unsigned int GetHandle() const = 0;  // Temp

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		static FrameBuffer* Create(unsigned int width, unsigned int height);
	};
}

