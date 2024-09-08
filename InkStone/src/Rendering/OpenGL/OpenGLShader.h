#pragma once

#include "src/Rendering/Shader.h"

#include <GLAD/glad.h>

namespace NXTN {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetUniformInt(const char* name, const int& i) override;
		virtual void SetUniformUInt(const char* name, const unsigned int& i) override;
		virtual void SetUniformFloat(const char* name, const float& f) override;
		virtual void SetUniformFloat3(const char* name, const vec3& v) override;
		virtual void SetUniformFloat4(const char* name, const vec4& v) override;
		virtual void SetUniformMat4(const char* name, const mat4& m) override;

		virtual inline const std::vector<Uniform>& GetUniformList() override { return m_Uniforms; };

	private:
		int GetUniformPosition(const char* name);

		unsigned int m_RendererID;

		std::vector<Uniform> m_Uniforms;
		std::unordered_map<std::string, int> m_UniformLocations;
	};
}

