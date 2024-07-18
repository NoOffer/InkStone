#pragma once

#include "Rendering/Shader.h"

#include <GLAD/glad.h>

namespace NXTN {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int m_RendererID;
	};
}

