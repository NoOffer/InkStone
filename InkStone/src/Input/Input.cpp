#include "pch.h"

#include "src/System.h"

#include "GLFW/GLFWInput.h"

namespace NXTN {
	Input* Input::s_Instance;

	void Input::Init(void* windowPtr)
	{
		switch (System::GetWindowAPI())
		{
		case WindowAPI::None:
			Log::Error("No window API specified");
			break;
		case WindowAPI::GLFW:
			s_Instance = new GLFWInput(windowPtr);
			break;
		default:
			Log::Error("Unsupported rendering API");
			break;
		}
	}
}