#pragma once

#include "src/Input.h"

#include <GLFW/glfw3.h>

namespace NXTN {
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
	};
}
