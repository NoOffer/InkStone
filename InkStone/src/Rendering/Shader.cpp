#include "pch.h"

#include "OpenGL/OpenGLShader.h"

namespace NXTN {
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetRenderingAPI())
		{
		case GraphicsAPI::None:
			Log::Error("No rendering API specified");
			break;
		case GraphicsAPI::OpenGL:
			return (Shader*) new OpenGLShader(vertexSrc, fragmentSrc);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}

		return nullptr;
	}
}
