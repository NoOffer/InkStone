#pragma once

#include "Core.h"

#include "Log.h"

#include <GLAD/glad.h>

namespace NXTN {
	class NXTN_API Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind();
		void Unbind();

	private:
		unsigned int m_RendererID;
	};
}

