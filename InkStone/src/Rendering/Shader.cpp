#include "pch.h"

#include "Shader.h"

namespace NXTN {
	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
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
			Log::Error("Vertex shader failed to compile: %s", msg);
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
			Log::Error("Fragment shader failed to compile: %s", msg);
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
			Log::Error("Shader program failed to link: %s", msg);
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
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}
}
