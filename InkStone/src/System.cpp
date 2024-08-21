#include "pch.h"

#include "System.h"

namespace NXTN {
	GraphicsAPI System::s_GraphicsAPI = GraphicsAPI::OpenGL;
	WindowAPI   System::s_WindowAPI   = WindowAPI::GLFW;
}
