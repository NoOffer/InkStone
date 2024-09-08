#pragma once

#include "src/Core.h"

#include "src/Log.h"
#include "src/System.h"
#include "src/Math/Math.h"

namespace NXTN {

	enum class UniformType
	{
		None = 0, Int, Float, Float2, Float3, Float4, Mat4, Bool, Tex2D, TexCube
	};

	struct Uniform
	{
		UniformType type;
		std::string name;
	};

	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetUniformInt(const char* name, const int& i) = 0;
		virtual void SetUniformUInt(const char* name, const unsigned int& i) = 0;
		virtual void SetUniformFloat(const char* name, const float& f) = 0;
		virtual void SetUniformFloat3(const char* name, const vec3& v) = 0;
		virtual void SetUniformFloat4(const char* name, const vec4& v) = 0;
		virtual void SetUniformMat4(const char* name, const mat4& m) = 0;

		virtual const std::vector<Uniform>& GetUniformList() = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}

