#include "pch.h"

#include "OpenGLShader.h"

namespace NXTN {
	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		// Fallback
		m_RendererID = 0;

		// Create an empty vertex shader handle
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string.c_str is NULL character terminated
		const char* source = vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		// Check compilation status
		int status = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
		if (!status)
		{
			// Get log information string length
			int msgLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &msgLength);

			// The maxLength includes the NULL character
			char* msg = (char*)malloc(msgLength * sizeof(char));
			glGetShaderInfoLog(vertexShader, msgLength, &msgLength, &msg[0]);

			// Log information
			Log::Error("Vertex shader failed to compile:\n%s", msg);
			free(msg);

			// Discard the shader
			glDeleteShader(vertexShader);

			return;
		}

		// Create an empty fragment shader handle
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		// Note that std::string.c_str is NULL character terminated.
		source = (const GLchar*)fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		// Check compilation status
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
		if (!status)
		{
			// Get log information string length
			int msgLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &msgLength);

			// The maxLength includes the NULL character
			char* msg = (char*)malloc(msgLength * sizeof(char));
			glGetShaderInfoLog(fragmentShader, msgLength, &msgLength, &msg[0]);

			// Log information
			Log::Error("Fragment shader failed to compile:\n%s", msg);
			free(msg);

			// Discard the shader
			glDeleteShader(fragmentShader);

			return;
		}

		// Create a program object.
		m_RendererID = glCreateProgram();

		// Attach the shaders to the program
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		// Link the program
		glLinkProgram(m_RendererID);

		// Check linking status
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, &status);
		if (!status)
		{
			// Get log information string length
			int msgLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &msgLength);

			// The maxLength includes the NULL character
			char* msg = (char*)malloc(msgLength * sizeof(char));
			glGetProgramInfoLog(m_RendererID, msgLength, &msgLength, &msg[0]);

			// Log information
			Log::Error("Shader program failed to link:\n%s", msg);
			free(msg);

			// Delete the program
			glDeleteProgram(m_RendererID);

			// Delete the shaders
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return;
		}

		// Detach shaders
		glDetachShader(m_RendererID, vertexShader);
		glDetachShader(m_RendererID, fragmentShader);

		// List shader uniforms
		int count;
		glGetProgramiv(m_RendererID, GL_ACTIVE_UNIFORMS, (GLint*)&count);

		GLsizei length;  // Length of uniform name
		GLint size;      // Size of uniform
		GLenum type;     // Type of uniform
		char name[32];   // Name of uniform (NOTE: The name should not be longer than 32 char)
		for (GLuint i = 0; i < count; i++)
		{
			glGetActiveUniform(m_RendererID, i, 32, &length, &size, &type, name);

			switch (type)
			{
			case GL_INT:
				m_Uniforms.push_back({ UniformType::Int, std::string(name) });
				break;
			case GL_FLOAT:
				m_Uniforms.push_back({ UniformType::Float, std::string(name) });
				break;
			case GL_FLOAT_VEC2:
				m_Uniforms.push_back({ UniformType::Float2, std::string(name) });
				break;
			case GL_FLOAT_VEC3:
				m_Uniforms.push_back({ UniformType::Float3, std::string(name) });
				break;
			case GL_FLOAT_VEC4:
				m_Uniforms.push_back({ UniformType::Float4, std::string(name) });
				break;
			case GL_FLOAT_MAT4:
				m_Uniforms.push_back({ UniformType::Mat4, std::string(name) });
				break;
			case GL_BOOL:
				m_Uniforms.push_back({ UniformType::Bool, std::string(name) });
				break;
			case GL_SAMPLER_2D:
				m_Uniforms.push_back({ UniformType::Tex2D, std::string(name) });
				break;
			case GL_SAMPLER_CUBE:
				m_Uniforms.push_back({ UniformType::TexCube, std::string(name) });
				break;
			default:
				break;
			}
		}
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetUniformInt(const char* name, const int& i)
	{
		glUniform1i(GetUniformPosition(name), i);
	}

	void OpenGLShader::SetUniformUInt(const char* name, const unsigned int& i)
	{
		glUniform1ui(GetUniformPosition(name), i);
	}

	void OpenGLShader::SetUniformFloat(const char* name, const float& f)
	{
		glUniform1f(GetUniformPosition(name), f);
	}

	void OpenGLShader::SetUniformFloat3(const char* name, const float& f0, const float& f1, const float& f2)
	{
		glUniform3f(GetUniformPosition(name), f0, f1, f2);
	}

	void OpenGLShader::SetUniformFloat4(const char* name, const float& f0, const float& f1, const float& f2, const float& f3)
	{
		glUniform4f(GetUniformPosition(name), f0, f1, f2, f3);
	}

	void OpenGLShader::SetUniformMat4(const char* name, const mat4& m)
	{
		glUniformMatrix4fv(GetUniformPosition(name), 1, GL_TRUE, &(m[0][0]));
	}

	int OpenGLShader::GetUniformPosition(const char* name)
	{
		if (m_UniformLocations.find(name) != m_UniformLocations.end())
		{
			return m_UniformLocations[name];
		}

		int location = glGetUniformLocation(m_RendererID, name);
		if (location == -1)
		{
			Log::Warning("Uniform %s does not exist.", name);
		}
		m_UniformLocations[name] = location;
		return location;
	}
}
