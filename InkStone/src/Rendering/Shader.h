#pragma once

#include "Core.h"

#include "Log.h"
#include "System.h"

namespace NXTN {
	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}

